inherit ROOM;

#include <ansi.h>
#include <net/dns.h>
#include <net/telnet.h>
#include <net/socket.h>
#include <net/socket_errors.h>
#include <socket_err.h>
#include <mudlib.h>

string smtp_ip="202.97.175.44 25";
string smtp_domain="mymud.com";
string sender_name="password";
string sender="password@mymud.com";

varargs void write_message(object, string, int);

void create()
{
	set("short", CHINESE_MUD_NAME+"Íæ¼ÒµÇ¼ÇÊÒ");
	set("long", @LONG
============================================================
    ÕâÀïÊÇÍæ¼ÒµÇ¼ÇµÄµØ·½£¬Íæ¼ÒµÇ¼Çºó²ÅÄÜÕıÊ½¿ªÊ¼ÓÎÏ·£¬ÏêÏ¸²½ÖèÈç
ÏÂ£º
    ÊäÈë [1;37mregister xxx@yyy.zzz[0;37;0m
    ÆäÖĞ xxx@yyy.zzz ÊÇÄúµÄµç×ÓÓÊ¼şµØÖ·¡£
    ÊäÈëÍê±ÏºóÏµÍ³»á½«Ò»·âº¬ĞÂÃÜÂëµÄÓÊ¼ş·¢ËÍ¸øÄú¡£
    ¹Ø±ÕÓÎÏ·Èí¼şµÄ×Ô¶¯µÇÂ¼¹¦ÄÜ¡£
    ÓÃĞÂÃÜÂëµÇÂ¼¼´Íê³ÉÁËµÇ¼Ç¹ı³Ì¡£
    ÏµÍ³»áÔÚÄú³É¹¦µÇ¼ÇÖ®ºó»Ö¸´ÄúÔ­À´µÄÃÜÂë¡£
    Èç¹û³¬¹ıÊ®·ÖÖÓ»¹Î´ÊÕµ½ÃÜÂëĞÅ¼ş£¬ÄúÒ²¿ÉÒÔÊ¹ÓÃ¾ÉµÄÃÜÂëÔÙ´Î»Øµ½
    ÕâÀïÀ´ÖØĞÂµÇ¼Ç¡£
    ÎªÁË¸üºÃµØ¹ÜÀíÊé½££¬¶Ô¸ø´ó¼Ò´øÀ´µÄ²»±ã¾´ÇëÔ­ÁÂ¡£
================================================================
LONG);
	set("no_death", 1);
	set("no_summon_out", 1);
	set("no_save", 1);
	set("no_fight", 1);
	set("no_update", 1);
	set("sleep_room", 1);
	set("no_sleep_room", 1);
	set("indoors", "Êé½£");
	setup();
}

void init()
{
	object me = this_player();
	string id = me->query("id");

	if (id != "guest") add_action("do_register", "register");
	else
	{
		add_action("do_change", "change");
		call_out("show", 1, me);
	}
	add_action("do_nothing", ({ "drop", "exert", "get", "kill", "save", "chat", "chat*", "tell" }));
	add_action("do_quit", "quit");
}

void show(object me)
{
	if (me) tell_object(me, "Äã¿ÉÒÔÓÃ change ÃüÁîÀ´×ª»» ID¡£\n");
}

int do_nothing()
{
	return 1;
}

int do_change(string arg)
{
	object me = this_player();
	string id, nid;

	if (me->is_busy())
	{
		write("ÇëÄÍĞÄµÈºò¡£\n");
		return 1;
	}
	if (!arg)
	{
		write("¸ñÊ½£ºchange ID\n");
		return 1;
	}

	if (sscanf(arg, "%s %s", id, nid) != 2) nid = id = arg;
	if (file_size("/log/data/login/"+ id[0..0] +"/"+ id + SAVE_EXTENSION) <0) {
		write(capitalize(id) +" µÇÂ¼µµ°¸²»´æÔÚ£¬ÎŞ·¨¸ü»» ID¡£\n");
		return 1;
	}
	if (file_size("/log/data/user/"+ id[0..0] +"/"+ id + SAVE_EXTENSION) <0) {
		write(capitalize(id) +" Êı¾İµµ°¸²»´æÔÚ£¬ÎŞ·¨¸ü»» ID¡£\n");
		return 1;
	}
	if (file_size("/data/login/"+ nid[0..0] +"/"+ nid + SAVE_EXTENSION) >0
	&& file_size("/data/user/"+ nid[0..0] +"/"+ nid + SAVE_EXTENSION) > 0)
	{
		write(capitalize(nid) +" ÒÑ¾­´æÔÚ£¬ÇëÊäÈë( change ¾ÉID ĞÂID )ÖØĞÂ×ª»»¡£\n");
		return 1;
	}
	me->add_busy(10);
	write("ÇëÊäÈë¸Ã ID µÄ¿ÚÁî£º");
	input_to("get_pass", 1, id, nid);
	return 1;
}

void get_pass(string passwd, string id, string nid)
{
	write("\n");
	__DIR__"idroom"->do_change(id, nid, passwd);
}

int do_quit()
{
	object ob = this_player();
	object lb = ob->query_temp("link_ob");

	message_vision("$NÀë¿ªÓÎÏ·¡£\n", ob);
	if (lb) destruct(lb);
	destruct(ob);
	return 1;
}

void tell_me(object me, string msg)
{
	if (me) {
		if (msg[0..1] != "<<" && msg[0..1] != ">>") tell_object(me, msg);
		message("wizard:yuj", me->query("id") + " : " + HIG + msg + NOR, this_object());
	}
}

int do_telnet(object me)
{
	int err, sock;

	sock = socket_create( STREAM, "in_read_callback","in_close_callback" );
	if ( sock < 0 ) {
		tell_me(me, "´´½¨Ì×½Ó×ÖÊ§°Ü¡£\n" );
		return 0;
	}
	tell_me(me, "ÕıÔÚÁ¬½ÓÓÊ¼ş·şÎñÆ÷...");
	err = socket_connect( sock, smtp_ip , "read_callback","write_callback" );
	if( err==EESUCCESS ) {
		me->set_temp("mail/sock", sock);
		set(""+sock, me);
		tell_me(me, "³É¹¦\nÏÖÔÚ·¢ËÍĞÅ¼ş...\n");
		return 1;
	}
	tell_me(me, "Ê§°Ü\nÓÊ¼ş·şÎñÆ÷ÎŞ·¨Á¬½Ó£¬ÇëÉÔºòÔÙÊÔ¡£\n");
	return 0;
}

void close_socket(object me)
{
	int sock;

	if (me && sock = me->query_temp("mail/sock")) {
		socket_close(sock);
		delete(""+sock);
		delete("OK"+sock);
		me->delete("disable_type");
		me->delete_temp("mail");
	}
}

void read_callback(int fd, mixed message)
{
	object me = query(""+fd);

	if (!me) {
		delete(""+fd);
		return;
	}
	tell_me(me, ">> "+message);
	switch(me->query_temp("mail/status")) {
		case 0:
			if (sscanf(message,"220%*s")) {
				me->add_temp("mail/status", 1);
				write_message(me, "HELO " + smtp_domain);
				return;
			}
			break;
		case 1:
			if (sscanf(message,"250%*s") || sscanf(message,"503%*s")) {
				me->add_temp("mail/status", 1);
				write_message(me, "MAIL FROM: "+sender_name);
				return;
			}
			break;
		case 2:
			if (sscanf(message,"250%*s")) {
				me->add_temp("mail/status", 1);
				write_message(me, "RCPT TO: <" + me->query_temp("mail/rcpt") + "> NOTIFY=NEVER");
				return;
			}
			break;
		case 3:
			if (sscanf(message,"250%*s")) {
				me->add_temp("mail/status", 1);
				write_message(me, "DATA");
				return;
			}
			tell_me(me, "ÓÊ¼şµØÖ·´íÎó£¬Çë¼ì²é£¡\n");
			break;
		case 4:
			if (sscanf(message,"354%*s")) {
				me->add_temp("mail/status", 1);
				write_message(me, me->query_temp("mail/msg")+"\n.");
				return;
			}
			break;
		case 5:
			if (sscanf(message,"451%*s")) tell_me(me, "·¢ĞÅ³ö´í£¡ÇëÉÔºòÔÙÊÔ¡£\n");
			else {
				object linkob = me->query_temp("link_ob");

				tell_me(me, "×¢²áĞÅ¼şÒÑ¾­ÕıÈ··¢ËÍÁË£¬Çë´ò¿ªÄãµÄĞÅÏä²éÊÕ¡£\nYu Jue@ShuJian\n");
				message_vision("$N¼±¼±Ã¦Ã¦µØÍË³öÓÎÏ·ÊÕĞÅÈ¥ÁË¡£\n", me);
				if (linkob) {
					linkob->set("reg_time", time());
					linkob->save();
					destruct(linkob);
				}
				write_message(me, "QUIT");
				close_socket(me);
				destruct(me);
				return;
			}
	}
	if (me->query_temp("mail/status") != 5 || !sscanf(message,"250%*s")) tell_me(me, "·¢ĞÅ³ö´í£¡\n");
	write_message(me, "QUIT");
	close_socket(me);
}

void write_callback(int fd, mixed msg)
{
	object me = query(""+fd);

	if (!me) {
		delete(""+fd);
		return;
	}
	set("OK"+fd, 1);
}

varargs void write_message(object me, string arg, int i)
{
	int fd;

	if (!me) return;
	fd = me->query_temp("mail/sock");
	if (!query("OK"+fd) && i < 3) {
		call_out("write_message", 1, me, "HELO " + smtp_domain, i++);
		return;
	}
	if( !arg ) arg="";
	arg += "\n";
	if (me) {
		tell_me(me, "<< " + arg);
		socket_write(fd, arg);
	}
}

string seed = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

string make_password()
{
	int i = 8, j;
	string id = "";

	while (i--) {
		j = random(52);
		id += seed[j..j];
	}
	return id;
}

int do_register(string dest)
{
	object me, linkob;
	string pass;

	if (!dest || sscanf(dest, "%*s@%*s.%*s") != 3)
		return notify_fail("µç×ÓÓÊ¼şµØÖ·¸ñÊ½´íÎó¡£\n");
	me = this_player();
	linkob = me->query_temp("link_ob");
	if (!linkob) return notify_fail("Äã²»ÊÇÕı³£µÇÂ¼µÄÈËÎï£¬²»ÄÜ½øĞĞµÇ¼Ç¡£\n");
	linkob->restore();
	if (linkob->query("registered") > 1) return notify_fail("Äã²»ÊÇÒÑ¾­µÇ¼Ç³É¹¦ÁËÃ´£¿¿ìÍË³ö°É¡£\n");
	if (time() < linkob->query("reg_time") + 600) return notify_fail("ÇëµÈºòĞÅ¼ş£¬ÄÍĞÄµã¡£\n");
	me->set_temp("mail/rcpt", dest);
	pass = make_password();
	me->set_temp("mail/msg",
		"SUBJECT: "+CHINESE_MUD_NAME+"×¢²áĞÅ¼ş£¡\n"+
		"FROM: \""+"ÃÜÂë¹ÜÀíÔ±@"+CHINESE_MUD_NAME+"\" <password@mymud.com>\n"+
		"TO: \""+me->name(1)+"\" <"+dest+">\n"+
		"MIME-Version: 1.0\n"+
		"DATE: "+ctime(time())+"\n"+
		"X-MAILER: LPC SMTP Client v1.0\n\n"+
		me->query("id") + " ÄúºÃ£¡»¶Ó­¹âÁÙ"+CHINESE_MUD_NAME+"£¡\n"+
		"Çë¹Ø±Õ×Ô¶¯µÇÂ¼¹¦ÄÜ£¬Ê¹ÓÃÏÂÃæÌá¹©µÄÃÜÂëµÇÂ¼¡£\n\n"+
		"ÄãµÄ×¢²áÃÜÂëÊÇ£º"+ pass +"\n\n"+
		"ÓÃ×¢²áÃÜÂëµÇÂ¼³É¹¦ºó£¬ÏµÍ³»á»Ö¸´ÄúÔ­À´µÄÃÜÂë¡£\n"+
		"Óöµ½ÎÊÌâ£¬ÇëÓÃÔ­À´µÄÃÜÂëµÇÂ¼¡£\n"+
		"×ÜÕ¾Ö÷Ò³£ºhttp://www.mymud.com/\n"+
		ctime(time())
	);
	if (!do_telnet(me)) {
		me->delete_temp("mail");
		return 1;
	}
	message_vision("$N³åÉÏÇ°È¥¿ªÊ¼°ìÀíµÇ¼ÇÊÖĞø¡£\n", me);
	//ÉèÖÃÍæ¼ÒµÄ×¢²áĞÅÏ¢
	linkob->set("newpassword", crypt(pass, "SJ"));
	linkob->set("email", dest);
	linkob->save();
	me->set("disable_type", " <°ìÀíµÇ¼ÇÖĞ>");
	return 1;
}
