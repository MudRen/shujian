// File     : /adm/daemons/network/dns_master.c
// Created  : 93-08-09
// By       : Grendel@tmi-2
// History  : Huthar@Portals wrote the original name server
//	  : Pinkfish@Discworld wrote a port of the CD udp server.  The
//	      udp comms and the database code are based on that port.
//
// This is the daemon that runs the DNS
//
// What does it do?
// -> maintains the database of known muds
// -> handles udp communication
// -> maintains a list of which services are avaible at which muds
// -> maintains an indexed list of outstanding requests to network services

// Ported to ES2 mudlib by Annihilator@ES2

// 由Yu Jue@SJ彻底改造，把UDP改为TCP，结果速度巨慢，只好换回 UDP

#include <ansi.h>
#include <mudlib.h>
#include <socket_err.h>
#include <net/config.h>
#include <net/daemons.h>
#include <net/dns.h>
#include <net/socket.h>
#include <net/services.h>
#include <net/macros.h>

#undef DEBUG

// services we always query if we don't know about
#define STD_SERVICE ({ "mail", "finger", "rwho_q", "tell", "gwizmsg" })

// used by the log() function
#define MY_LOG_FILE "dns_master"

inherit F_DBASE;

/* global vars */
// the udp port number of the mud, and the socket id of the udp socket
private int my_port, socket_id;

// The mapping containing the general mud info.
private mapping muds;

// This mapping has an entry for every mud in the dns, and holds
// information about the protocols supported for the services
private mapping mud_svc;

// Info about ourselves
private mapping this_host;

// the server where we get our mudlist from, and the number of tries
// we have had to contact it.
private mixed * bootsrv;
private int bootsrv_retry;

// used for sequencing the requests to the network services
private int seq_ctr;
private mapping seq_entries;

// Used for debugging
#ifdef DEBUG
#define debug(x) if(monitor) message("diagnostic", (x), monitor)
nosave object monitor = 0;
#else
#define debug(x)
#endif

/* prototypes */
// udp communication functions
int startup_udp();
void send_udp(string host, int port, string msg);
string start_message();

// mud database functions
void init_database();
void refresh_database();
void do_pings();
void set_mud_info(string name, mapping junk);
void zap_mud_info(string name, mapping junk);
void support_q_callback(mapping info);
private void query_services(string mud, string address, string port, string tcp);

// name serving functions
int query_service_method(string mud, string service);
mapping query_mud_info(string name);
string get_host_name(string alias);
int get_mudresource(string mud, string resource);
int dns_mudp(string name);
mapping query_muds();
mapping query_svc();

// sequencing functions
varargs int idx_request(function f);
void sequence_callback(int idx, mixed param);
void sequence_clean_up();

#ifdef DEBUG
// debugging functions
mixed * query_bootsrv();
void dump_sequencer();
void set_monitor(object ob);
object query_monitor();
#endif

// misc functions
private void restore_euid();
void aux_log(string file, string entry);
void aux_warning(string warning);
private void log(string entry);
void resolve_callback(string address, string my_ip, int key);

//      ----------------------------------------------------------------------------
//      The UDP(User Datagram Protocol) network functions
//      ----------------------------------------------------------------------------

// this function binds our listening socket, and requests a mudlist
int startup_udp()
{
	int err_no;

	if (socket_id) return 0;

	socket_id = socket_create(DATAGRAM, "read_callback");
	if (socket_id < 0) {
		log("Failed to acquire socket.\n");
		return 0;
	}

	err_no = socket_bind(socket_id, my_port);
	if( err_no <= 0 ) {
		log( sprintf("Failed to bind socket of TCP services, error = %d.\n", err_no));
		socket_close(socket_id);
		return 0;
	}
	return 1;
}

// this is called when we receive a udp packet.  We determine which
// service the packet is for, and send it to the auxiliary daemon of
// that name
void read_callback(int sock, string msg, string addr)
{
	string func, rest, *bits, name, arg, *list;
	mapping args;
	int i;

	if(previous_object()) return;

	debug("DNS: Got " + msg);

	// get the function from the packet
	if( !sscanf(msg, "@@@%s||%s@@@%*s", func, rest)) {
		if (!sscanf(msg, "@@@%s@@@%*s", func)) return;
		rest = "";
	}
	// get the address(remove port number)
	sscanf(addr, "%s %*s", addr);

	// get the arguments to the function
	// these are in the form "<arg>:<value>" and are put into a mapping
	// like that
	bits = explode(rest?rest:"", "||");
	args = allocate_mapping(sizeof(bits));
	i = sizeof(bits);
	while (i--)
		if (bits[i] && sscanf(bits[i], "%s:%s", name, arg) == 2)
			args[name] = arg;
	args["HOSTADDRESS"] = addr;
	// some muds don 't send their name out in a network friendly form
	if (args["NAME"])
		args["ALIAS"] = htonn(args["NAME"]);

	// we have received a message from someone, so we clear their
	// no contact count
	if (mapp(muds[args["NAME"]]))
		muds[args["NAME"]][DNS_NO_CONTACT] = 0;

	// we now execute the function we have received
	if (file_size(AUX_PATH + func + ".c") > 0) {
		list = values( LISTNODES );
		i = sizeof( list );
		while( i-- ) {
			sscanf( list[i], "%s %s", bootsrv[0], bootsrv[1] );
			if( bootsrv[0] == addr && bootsrv[1] == args["PORTUDP"] ) {
				(AUX_PATH + func + ".c" )->incoming_request(args);
				break;
			}
		}
	}
#ifdef DEBUG
	CHANNEL_D->do_channel(this_object(),"debug", sprintf("receive %s host:%s port:%s function: %s info:%O",(flag>0)?"valid":RED"invalid"WHT,addr,args["PORTUDP"], func, args));
#endif
}

// this is the function used by the udp slave daemons to send packets
void send_udp(string host, int port, string msg)
{
	int sock;

	if (!ACCESS_CHECK(previous_object())
	&& file_name(previous_object())[0..strlen(AUX_PATH) - 1] != AUX_PATH)
		return;
#ifdef DEBUG
	CHANNEL_D->do_channel(this_object(), "debug", sprintf("sending to %s ",host));
#endif
	debug("DNS: Sending " + msg);

	sock = socket_create(DATAGRAM, "read_callback");
	if (sock <= 0) {
		log("Failed to open socket to " + host + " " + port + "\n");
		return;
	}
	socket_write(sock, msg, host+" "+port);
	socket_close(sock);
}

// used to inform the slave daemons of the udp port
int query_udp_port() {  return my_port; }

// return the name we'll use on the domain of intermud.
string query_mud_name() { return INTERMUD_MUD_NAME; }

// this is called when we want to shut the mud down
void send_shutdown()
{
	string *mud_names;
	int i;

	// check the permission
	// if(geteuid(previous_object())!= ROOT_UID) return;

	// run through the muds and send a shutdown message
	mud_names = keys(muds);
	i = sizeof(mud_names);
	while (i--)
		SHUTDOWN->send_shutdown(muds[mud_names[i]]["HOSTADDRESS"],
			muds[mud_names[i]]["PORTUDP"]);
	socket_close(socket_id);
	CHANNEL_D->do_channel(this_object(), "sys", "送出 shutdown 讯息。\n");
}

string start_message()
{
	return sprintf( "||MUDNAME:%s||NAME:%s||VERSION:%s||MUDLIB:%s||HOST:%s||PORT:%d"
		"||PORTUDP:%d||TIME:%d||USERS:%d||TCP:%s", CHINESE_MUD_NAME,Mud_name(),
		MUDLIB_VERSION, MUDLIB_NAME, query_host_name(),
		mud_port(), my_port, uptime(), sizeof(users()), TCP_SERVICE_LEVEL);
}

//      ----------------------------------------------------------------------------
//      Network database functions
//      ----------------------------------------------------------------------------

// Sends a startup message to our server mud, then requests a mudlist.
// It requests every 60 seconds for 5 minutes.  If it doesn 't get one
// by then it switches to the backup server.  It then keeps alternating
// until it gets a reply.  If it does switch to the backup server it
// doesn't bother checking for the main server, as this would chew cpu
// with no real advantage.
void init_database()
{
	int i;
	string message, *list;

	// if we have received any muds then we stop starting up.
	if( MUDLIST_A->query_db_flag() ) {
	// start call outs - note we do the sequence clean up
	// a bit early because of the number of muds we query
	// when we first start up.
	call_out("refresh_database", REFRESH_INTERVAL);
	call_out("sequence_clean_up", 4 * SERVICE_TIMEOUT);
	do_pings();

	CHANNEL_D->do_channel(this_object(), "sys", "sending。。。\n");

	return;
	}

	message = sprintf("@@@%s%s@@@\n", DNS_STARTUP, start_message());

	// send a startup and request a mudlist
	list = values( LISTNODES );
	i = sizeof( list );

	while( i-- ) {
		sscanf( list[i], "%s %d", bootsrv[0], bootsrv[1] );
		send_udp(bootsrv[0], bootsrv[1], message);
		MUDLIST_Q->send_mudlist_q(bootsrv[0], bootsrv[1]);
	}

	call_out("init_database", 60);
	return;
}

// This periodic function queries the boot server for its current list
// of muds
void refresh_database()
{
	int i;
	string *list;

	if (find_call_out("refresh_database") != -1) return;
	call_out("refresh_database", REFRESH_INTERVAL);

	list = values( LISTNODES );
	i = sizeof( list );

	while( i-- ) {
		sscanf( list[i], "%s %d", bootsrv[0], bootsrv[1] );
		MUDLIST_Q->send_mudlist_q(bootsrv[0], bootsrv[1]);
	}
}

// this periodic function pings all the muds on our list.  It keeps them
// alive in our database, and keeps us alive in theirs
void do_pings()
{
	int i;
	string *mud_names;

	if(find_call_out("do_pings") != -1) return;
	// do it again in 30 minutes
	call_out("do_pings", PING_INTERVAL);

	mud_names = keys(muds);
	i = sizeof(mud_names);
	while (i--) {
		// a static mud
		if(undefinedp(mud_svc[mud_names[i]])) continue;

		// increment the no contact count - this will be zerod if a reply
		// is received, if it reaches a threshold the mud is removed
		muds[mud_names[i]] [DNS_NO_CONTACT]++;

		// ping the mud
		PING_Q->send_ping_q(muds[mud_names[i]]["HOSTADDRESS"],
			muds[mud_names[i]]["PORTUDP"]);

		// delete it if is hasn 't answered recently enough
		if (muds[mud_names[i]][DNS_NO_CONTACT] >= MAX_RETRYS)
			zap_mud_info(mud_names[i], 0);
	}
}

// adds a mud to the 'muds' mapping.  if it is a new entry then it may
// also query the muds services
void set_mud_info(string name, mapping junk)
{
	string tcp;

	if( !(ACCESS_CHECK(previous_object()))
	&&	file_name(previous_object())[0..strlen(AUX_PATH) - 1] != AUX_PATH)
		return;

	name = htonn( name );
	while( name[<1] == '.' ) name = name[ 0..<2 ];

	// already know about ourselves
	if (name == htonn(Mud_name())) {
		this_host["HOSTADDRESS"] = junk["HOSTADDRESS"];
		return;
	}

	junk["ALIAS"] = nntoh( junk["NAME"] );

	// determines whether or not we send the service queries out
	// to the new mud
	if (!undefinedp(mud_svc[name])) {
		muds[name] = junk;
		return;
	}

	if (!undefinedp(muds[name]))
		this_object()->aux_log("dns_mud_conv", "Udp contact from: "+name+"\n");

	// is it a tcp - enabled mud ?
	if (!junk["TCP"]) junk["TCP"] = TCP_NONE;

	// set the entry in the main mud
	muds[name] = junk;

	tcp = junk["TCP"];
	switch (tcp) {
	case TCP_ALL:
		mud_svc[name] = ([
			"mail"     :  SVC_TCP,
			"finger"   :  SVC_TCP | SVC_UDP | SVC_KNOWN,
			"tell"     :  SVC_TCP | SVC_UDP | SVC_KNOWN,
			"rwho_q"   :  SVC_UDP,
			"gwizmsg"  :  SVC_UDP,
		]);
		break;
	case TCP_ONLY:
		mud_svc[name] = ([
			"mail"     :  SVC_TCP | SVC_NO_UDP | SVC_KNOWN,
			"finger"   :  SVC_TCP | SVC_NO_UDP | SVC_KNOWN,
			"tell"     :  SVC_TCP | SVC_NO_UDP | SVC_KNOWN,
			"rwho_q"   :  SVC_NO_UDP,
			"gwizmsg"  :  SVC_NO_UDP,
		]);
		break;
	case TCP_SOME:
		mud_svc[name] = ([
			"mail"     :  SVC_UNKNOWN,
			"finger"   :  SVC_UDP,
			"tell"     :  SVC_UDP,
			"rwho_q"   :  SVC_UDP,
			"gwizmsg"  :  SVC_UDP,
		]);
		break;
	default: // TCP_NONE
		mud_svc[name] = ([
			"mail"     :  SVC_NO_TCP,
			"finger"   :  SVC_NO_TCP | SVC_UDP | SVC_KNOWN,
			"tell"     :  SVC_NO_TCP | SVC_UDP | SVC_KNOWN,
			"rwho_q"   :  SVC_NO_TCP | SVC_UDP | SVC_KNOWN,
			"gwizmsg"  :  SVC_NO_TCP | SVC_UDP | SVC_KNOWN,
		]);
		break;
	} // switch (tcp)

	// handle service information
	if (tcp != TCP_ONLY)
		query_services(name, junk["HOSTADDRESS"], junk["PORTUDP"], tcp);
}

// deletes an entry for a mud
void zap_mud_info(string name, mapping junk)
{
	// check permissions
	if( !previous_object()
	||      !ACCESS_CHECK(previous_object())
	||      file_name(previous_object())[0..strlen(AUX_PATH) - 1] != AUX_PATH)
		return;

	// delete the entry
	map_delete(muds, name);

	// wipe the service information
	map_delete(mud_svc, name);
}

// This is called when we get a service response from the other end
void support_q_callback(mapping info)
{
	string cmd;
	string mud;

	// check permission
	if (!ACCESS_CHECK(previous_object())) return;

	// check the reply is valid - note that if info is 0 it is possible
	// this is the result of a tiemout, but as muds are only queried
	// once, and the default is unknown, we dont have a problem.
	if (!info || !info["CMD"] || !info["NAME"] || !strlen(info["CMD"])
	||      !strlen(info["NAME"]))
		return;

	mud = htonn( info["NAME"] );

	if (undefinedp(muds[mud])) return;

	if (undefinedp(mud_svc[mud])) mud_svc[mud] = ([]);

	if(!info["SUPPORTED"] && !info["NOTSUPPORTED"]) return; // mesed up packet

	if (info["CMD"] == "tcp") {
		cmd = in