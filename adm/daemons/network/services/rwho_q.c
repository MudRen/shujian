/*
 * File    : rhow_q.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is used to ask a mud for a list of users logged on.
 */

// Ported to ES2 mudlib by Annihilator@ES2.

inherit F_CLEAN_UP;
inherit F_DBASE;

#include <command.h>
#include <net/dns.h>
#include <net/macros.h>
#include <net/daemons.h>

/*
* Someone has asked us for a remote who...
* Lets oblige them.
*/
void create() {
	set("channel_id", "RWHO_Q");
	seteuid(ROOT_UID);
}

void incoming_request(mapping info)
{
	string str;

	if(!ACCESS_CHECK(previous_object())) return;

	if (stringp(info["NAME"]) && stringp(info["PORTUDP"])) {
		if (info["NAME"] == Mud_name())	return ;
		if (!DNS_MASTER->dns_mudp(info["NAME"])) {
			PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
			CHANNEL_D->do_channel( this_object(), "sys",
				sprintf("rwho request from %s rejected, ping_q sent.", info["NAME"] ) );
		}

		str = "-i";
		if (info["VERBOSE"]) str = "-l";
		if (info["WIZARD"]) str = "-w";
		if (info["PARTY"]) str += " -" + info["PARTY"];

		str = WHO_CMD->main(0, str, 1);

		DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
			"@@@" + DNS_RWHO_A +
			"||NAME:" + Mud_name() +
			"||PORTUDP:" + udp_port() +
			"||RWHO:" + str +
			"||ASKWIZ:" + info["ASKWIZ"] +
			"@@@\n");
    } //if (stringp(info["NAME"]) && stringp(info["PORTUDP"]))
}

int send_rwho_q(string mud, object them, int verbose, int wiz, string party)
{
	mapping info;
	string askwiz;

	if (htonn(mud) == mud_nname()) return notify_fail(mud + " ���������������վ����\n");
	if(!ACCESS_CHECK(previous_object())
	&&	base_name(previous_object()) != WHO_CMD) return 0;

	if (!them) them = this_player();
	askwiz = geteuid(them);
	info = DNS_MASTER->query_mud_info(mud);
	if (!info) return notify_fail("û�� " + mud + " ���վ�㡣\n");
	DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
		"@@@"+DNS_RWHO_Q+
		"||NAME:"+ Mud_name() +
		"||PORTUDP:"+ udp_port() +
		"||ASKWIZ:"+ askwiz +
		(verbose ? "||VERBOSE:1" : "") +
		(wiz ? "||WIZARD:1" : "") +
		(party != "(null)" ? "||PARTY:"+party : "") +
		"||@@@\n");
	return 1;
}

int visiblep(object obj) { return 1; }

string get_name(object obj) { return capitalize(geteuid(obj)); }

int support_rwho_q_VERBOSE() { return 1; }
