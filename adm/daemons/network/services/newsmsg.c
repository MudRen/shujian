
//newsmsg.c

inherit F_CLEAN_UP;
inherit F_DBASE;

#undef DEBUG

#include <net/macros.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/services.h>

#define THIS_NAME "newsmsg"
#define NEWS_CMD "/cmds/usr/news"

void create() { seteuid(ROOT_UID); }

string* allow_name = ({"TEST","SJ"});
		
void send_msg(string title, string author, string poster, string text)
{
	string *names;
	int i;
	mapping muds;
	mapping svcs;
	mapping minfo;

	if( !this_player()		// Prevent from being called by ourself.
	||	!ACCESS_CHECK(previous_object())) return;
#ifdef DEBUG
	set("channel_id", "ͬ�����ž���");
	CHANNEL_D->do_channel(this_object(), "sys", "prepare to send newsmsg");
#endif
	muds = (mapping)DNS_MASTER->query_muds();
	svcs = (mapping)DNS_MASTER->query_svc();
	text = replace_string(text, "|", "");
	text = replace_string(text, "@@@", "");//��Ĳ������Щ�ַ��İɣ�
	// use keys(svcs) because none of the muds not in svcs can possibley
	// receive the message
	names = keys(svcs);
	i = sizeof(names);
	while(i--)
		if (names[i] != mud_nname()) {
			minfo = muds[names[i]];			
			if(!mapp(minfo) || !mapp(svcs[names[i]]))
				continue;
			DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
				"@@@" + THIS_NAME +
				"||NAME:" + Mud_name() +
				"||PORTUDP:" + udp_port() +
				"||TITLE:"+title+
				"||AUTHOR:"+author+
				"||POSTER:"+poster+
				"||TEXT:"+text+
				"@@@\n");
		}
}

void incoming_request(mapping info)
{
	mapping minfo;
	mapping note;
	string text;	
#ifdef DEBUG
	set("channel_id", "ͬ�����ž���");
	CHANNEL_D->do_channel(this_object(), "sys", "newsmsg received from " + info["NAME"]);
#endif	
	if(!ACCESS_CHECK(previous_object())) return;
	
	if (info["NAME"]) {
		if (info["NAME"] == Mud_name())
			return ;
		if( member_array(info["NAME"],allow_name)==-1)
			return;
															
		minfo = DNS_MASTER->query_mud_info(info["NAME"]);
		if (!minfo||!DNS_MASTER->dns_mudp(info["NAME"]))
		{
			// We don't accept the message.  But ping them anyway.
			PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
			return ;
		}
		
		if(undefinedp(info["TITLE"])
		|| undefinedp(info["AUTHOR"])
		||undefinedp(info["POSTER"])
		||undefinedp(info["TEXT"]) )
		{
			message("wizard:ciwei","�Ƿ��ַ��� dorped\n",users());
			return;
		}
		
		note = ([]);
		note["title"] = copy(info["TITLE"]);
		note["author"] = copy(info["AUTHOR"]);
		note["poster"] = copy(info["POSTER"]);
		text = copy(info["TEXT"]);
		NEWS_CMD->done_post(this_object(),note,text);
    }
    else message("wizard:ciwei","have no name dorped\n",users());
}

