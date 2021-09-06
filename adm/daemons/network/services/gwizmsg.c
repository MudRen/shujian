/*
 * File    : gwizmsg.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is used to broadcast a channel to other muds.
 */

// Ported to ES2 mudlib by Annihilator (06/15/95)
// Improve by Ciwei@SJ 04,5,7

#undef DEBUG
//#define DEBUG 1

inherit F_CLEAN_UP;
inherit F_DBASE;

#include <net/macros.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/services.h>

void create() { seteuid(ROOT_UID); }

// This is the interface to the intermud channels
void send_msg(string channel, string id, string name, string msg, int emoted)
{
	string *names;
	int i;
	mapping muds;
	mapping svcs;
	mapping minfo;

	if(!id || !name ||!msg ) return;
	if((!this_player()	// Prevent from being called by ourself.
	||!ACCESS_CHECK(previous_object()))
	&& previous_object()!=find_object(CHANNEL_D)
	) return;
	//return;
#ifdef DEBUG
	set("channel_id", "������ʦƵ������");
	CHANNEL_D->do_channel(this_object(), "sys", "prepare to send gwizmsg");
#endif
	muds = (mapping)DNS_MASTER->query_muds();
	svcs = (mapping)DNS_MASTER->query_svc();
	msg = replace_string(msg, "\n", "");
	msg = replace_string(msg, "|", "");
	msg = replace_string(msg, "@@@", "");
	// use keys(svcs) because none of the muds not in svcs can possibley
	// receive the message
	names = keys(svcs);
	i = sizeof(names);
	while(i--)
		if (names[i] != mud_nname()) {
			minfo = muds[names[i]];
			if(!mapp(minfo) || !mapp(svcs[names[i]])
			|| !(svcs[names[i]]["gwizmsg"] & SVC_UDP))
				continue;
			DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
				"@@@" + DNS_GWIZMSG +
				"||NAME:" + Mud_name() +
				"||PORTUDP:" + udp_port() +
				"||WIZNAME:" + capitalize(id) +
				"||CNAME:" + name +
				"||GWIZ:" + msg +
				"||CHANNEL:" + channel +
				(emoted?"||EMOTE:1":"") + "@@@\n");
		}
}

static mapping user_info;

void incoming_request(mapping info)
{
	mapping minfo;
	string tmsg;
	
	user_info=copy(info);
	
#ifdef DEBUG
	set("channel_id", "������ʦƵ������");
	CHANNEL_D->do_channel(this_object(), "sys", "gwizmsg received from " + info["NAME"]);
#endif
	if(!ACCESS_CHECK(previous_object())) return;

	if (info["NAME"]) {
		if (info["NAME"] == Mud_name()) return ;

		minfo = DNS_MASTER->query_mud_info(info["NAME"]);
		if (!minfo || !strlen(info["WIZNAME"])
		|| !DNS_MASTER->dns_mudp(info["NAME"]))	{
			// We don't accept the message.  But ping them anyway.
			PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);

			return ;
		}
		if (info["HOSTADDRESS"] != minfo["HOSTADDRESS"]) {
			if (info["EMOTE"])
				tmsg = info["WIZNAME"]+"@"+info["NAME"]+" "+info["GWIZ"];
			else
				tmsg = info["WIZNAME"]+"@"+info["NAME"]+": "+info["GWIZ"];

			// Faked.  sheeze... 
			dns_log("dns_fake",sprintf( "Gwiz: %s %s\n%s", ctime(time()),
				info["HOSTADDRESS"],tmsg));
			DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
				"@@@"+DNS_WARNING+
				"||NAME:"+Mud_name()+
				"||MSG: Fake gwiz msg: "+tmsg+
				"||FAKEHOST:"+info["HOSTADDRESS"]+
				"@@@\n");
			return;
		}
		if( undefinedp(info["CNAME"]) )
			set("channel_id", sprintf("%s@%s", info["WIZNAME"], info["NAME"]));
		else
			set("channel_id", sprintf("%s(%s@%s)", info["CNAME"], info["WIZNAME"], info["NAME"]));

		CHANNEL_D->do_channel(this_object(), "sj", info["GWIZ"], info["EMOTE"]);

    } //if (info["NAME"])
}

string query_name()
{
	if(!undefinedp(user_info["CNAME"]) )
		return user_info["CNAME"];
	return 0;
}

string query_id()
{
	if(!undefinedp(user_info["WIZNAME"]) && !undefinedp(user_info["NAME"]) )
		return sprintf("%s@%s",user_info["WIZNAME"], user_info["NAME"] );
	return 0;
}

string name()
{
	return "";
}
