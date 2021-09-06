// This Program is for command "sos"
// Create by keepon at 1999.4.20
// Optimize by Looklove@SJ 2003.10.21
// Modify By LinuX@SJ 2004.3.22

#define SOS_DIR       "/data/sos/"
#define SOS_FILENAME  "sos"
#define WIZ_MAIL "garrison.h@gmail.com"
#define BBS_TNUM 40
#ifndef BBS_ADDR
#define BBS_ADDR "http://bbs.mymud.com"
#endif
#define BBS_OK(x) sprintf(WHT"%s·¢±íµ½ÂÛÌ³Íê³É¡£\n"NOR,x)
#define BBS_URL(x) sprintf(CYN"ÏêÇéÇëä¯ÀÀ£º%s/viewthread.php?tid=%d¡£\n"NOR,BBS_ADDR,x)

inherit F_SAVE;

#include <command.h>
#include <ansi.h>
#include <mudlib.h>
#include <database.h>

mapping *notes;
int confirm(string yn, object me);
int help(object me);

void create()
{
        seteuid(getuid());
}

string query_save_file()
{
	return SOS_DIR + SOS_FILENAME ;
}

mixed query(string arg)
{
	if (arg && arg=="channel_id")
		return  "Çó¾È¾«Áé";
	return 0;
}

nosave int op;

void post_ok(mixed ret)
{
	//mapping *notes;	
	//if(environment()) tell_room(environment(),BBS_OK("ÁôÑÔ"));
	//notes = query("notes");
	if(!notes || !sizeof(notes)) return;	
	if(op != sizeof(notes)-1) return;//have somebody change it
	if(!ret || !sizeof(ret)) return;
	notes[op]["tid"] = ret[0][0];
	//if(environment()) tell_room(environment(),BBS_URL(ret[0][0]));
	save();
}
/*
void re_ok(mixed ret)
{
	//if(environment()) tell_room(environment(),BBS_OK("»Ø¸´"));
	//if(ret && sizeof(ret)) if(environment()) tell_room(environment(),BBS_URL(ret[0][0]));
	message("wizard",sprintf("»Ø¸´OK\n"),users());
}
*/

void done_post(object me, mapping note, string text)
{
	int i;
	object where;
	string msg;
	object ob;
	string mail;
	note["msg"] = text;
	i = sizeof(notes);
	where = environment(me);

	for( ; i > 0; i-- )
	if( notes[i-1]["author"] == me->query("id") ) break;
	if( !pointerp(notes) || i > 0 )
		if(!sizeof(notes)) notes = ({ note });
		else
		{
			notes[i-1]["title"] = note["title"];
			notes[i-1]["author"] = note["author"];
			notes[i-1]["msg"] = note["msg"];
			notes[i-1]["time"] = note["time"];
			notes[i-1]["solve"] = "";
			notes[i-1]["solve_id"] = "";
		}
	else notes += ({ note });
	
	op = sizeof(notes)-1;
	
	message("wizard", HIY "¡¾Çó¾È¡¿£ºÍæ¼Ò "+note["author"]+" Ê¹ÓÃ"BLINK" SOS "NOR HIY"½ô¼±Çó¾È£¬ÇëÔÚÏßÎ×Ê¦Ê¹ÓÃ sos ÃüÁî²é¿´¡£\n" NOR,users());
	
	ob = new(LOGIN_OB);
        ob->set("id", me->query("id"));
        ob->restore();
        mail = ob->query("email");
        destruct(ob);

      	msg = ""+note["title"]+"\n"+
      	note["msg"]+"\n"+
      	"Íæ¼ÒĞÅÏä:"+mail+"\n"+
      	ctime(time()) +"\n";
      	
	tell_object(me, WHT "\nÇó¾ÈÍê±Ï£¬ÄãµÄĞÅÏ¢ÒÑ¾­±»¼Óµ½Î×Ê¦Í¨ÖªÏûÏ¢Àï£¬²¢·¢ÓÊ¼şµ½Ö÷¹ÜÎ×Ê¦ÄÇÀï¡£\n");
	tell_object(me, WHT "Äã¿ÉÒÔÔÚÂÛÌ³¿´µ½ÄãµÄÇóÖúĞÅÏ¢£¬Î×Ê¦ÓĞ¿ÉÄÜ»áÔÚÂÛÌ³°ïÄã½â¾öÎÊÌâ£¬ÇëÁôÒâ£º"+BBS_ADDR+"/forumdisplay.php?fid="+BBS_TNUM+"¡£\n");
	tell_object(me, WHT "Î×Ê¦ÕıÔÚ´¦ÀíÆäËûÍæ¼Ò£¬ÇëµÈ´ı......\n");
	tell_object(me, WHT "Äã¿ÉÒÔËæÊ±ÓÃsos read£¬»òÕß²é¿´ÄúµÄ×¢²áĞÅÏäĞÂÓÊ¼şÅĞ¶ÏÊÇ·ñ±»½â¾ö¡£\n" NOR);
	SMTP_D->send_mail(me, WIZ_MAIL,CHINESE_MUD_NAME+"Íæ¼Ò" + note["author"] + "Çó¾ÈĞÅºÅ", msg);
	/*BBS_D->bbs_post(
		BBS_TNUM,
		wizardp(me)?me->query("id"):me->query("id")+"@"+lower_case(INTERMUD_MUD_NAME),
		strip("¡¾Íæ¼ÒÎÊÌâÇó½â¡¿£º"+note["title"]),
		"\n\n" + text,0,0,0,0,0 );*/
	BBS_D->bbs_post(
	BBS_TNUM,wizardp(me)?"master":me->query("id")+"@"+lower_case(INTERMUD_MUD_NAME),
	strip("¡¾Íæ¼ÒÎÊÌâÇó½â¡¿£º"+note["title"]),
	"\n\n" + text,0,0,0,this_object(),"post_ok");
			
	save();
	return;
}

void list_bug(object me, string arg)
{
	int i;
	string str,s;

	if (sizeof(notes)<1) {
		write("Ã»ÈË·¢³ö sos Çó¾ÈĞÅºÅ¡£\n");
		return;
	}
	arg == "all"?s="È«²¿":s="Î´½â¾ö";
	s = sprintf("µ±Ç°¹²ÓĞ("+sizeof(notes)+")ÌõSOS£¬"+s+"ĞÅÏ¢ÁĞ±íÈçÏÂ:\n"
	"©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥\n");
	for( i = 0; i<sizeof(notes); i++){
		if( arg=="all" ){
			str = sprintf("[%2d] %-40s%10s [%s] \n",
			i+1, notes[i]["title"], notes[i]["solve_id"]==""?"ÉĞÎ´»Ø¸´":"By "+notes[i]["solve_id"],
			ctime(notes[i]["time"])[0..15] );
			s = s + str;
		}
		else{
			if(notes[i]["solve_id"]=="") {
				str = sprintf("[%2d] %-40s%10s [%s] \n",
				i+1, notes[i]["title"], "ÉĞÎ´»Ø¸´",
				ctime(notes[i]["time"])[0..15] );
				s = s + str;
			}
		}
	}
	me->start_more(s);
}

void do_read(object me, int i)
{
	string s;
	if( i > sizeof(notes) || i < 1) {
		wizardp(me)?write("ÎŞ´Ë±àºÅ£¡\n"):write("Ä¿Ç°Ã»ÓĞÄã·¢³öµÄSOSĞÅÏ¢¡£\n");
		return;
	}

	s = sprintf("(%d) %-46s "HIW"Ê±¼ä£º"NOR"%s\n"
	"©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥\n"
	"%s\n"
	"Î×Ê¦´¦Àí»Ø¸´:£¨%s£©\n"NOR
	HIG"%s\n"NOR,
	i, notes[i-1]["title"], ctime(notes[i-1]["time"])[0..15],
	notes[i-1]["msg"], notes[i-1]["solve_id"]==""?"ÉĞÎ´»Ø¸´":"By "+notes[i-1]["solve_id"],
	notes[i-1]["solve"] );
	
	if(notes[i-1]["tid"]) s+= sprintf("ÂÛÌ³¿ÉÄÜ»áÓĞ¸ü¶àµÄ½â´ğ£¬%s",BBS_URL(notes[i-1]["tid"]) );
		
	me->start_more(s);
}

int search_id(string id)
{
	int i;
	if( !(i = sizeof(notes)) ) return 0;
	for( ; i > 0; i-- )
	if( notes[i-1]["author"] == id ) break;
	return i;
}

void done_re(object me, int i, string text)
{
	object obj, ob;
	string mail;
	string msg;
	notes[i-1]["solve"] = text;
	notes[i-1]["solve_id"] = me->query("id");
	save();
	if ( obj = LOGIN_D->find_body(notes[i-1]["author"])){
		tell_object(obj, HIG "ÔÚÏßÎ×Ê¦ÒÑ¾­»Ø¸´ÄãµÄsos£¬ÇëÊ¹ÓÃsos read²é¿´£¡\n");
	}
	ob = new(LOGIN_OB);
        ob->set("id", notes[i-1]["author"]);
        ob->restore();
        mail = ob->query("email");
        destruct(ob);
	
	msg = ""+notes[i-1]["title"]+"\n"+
      	notes[i-1]["msg"]+"\n"+
      	"Î×Ê¦»Ø¸´£º\n"+
      	text+
      	ctime(time()) +"\n";
      	
        SMTP_D->send_mail(me, mail,CHINESE_MUD_NAME+"¹ÜÀíÔ±¶ÔÄúSOSµÄ»Ø¸´", msg);
	write("¸Ã sos ĞÅÏ¢ÒÑ±êÖ¾Îª½â¾ö¡£\n");
	
	if(notes[i-1]["tid"])
	{
		BBS_D->bbs_post(BBS_TNUM,"master","¹ÜÀíÔ±ÔÚÓÎÏ·ÖĞµÄµÄ»Ø¸´",text,notes[i-1]["tid"],0,0,0,0);
		BBS_D->add_Bbs_Up_Map(WEB_DB_NAME,sprintf("UPDATE %s SET solve='1' WHERE tid='%d' AND fid='%d'",BBS_THREADS,notes[i-1]["tid"],BBS_TNUM),0,0);		
	}		
	return;
}

int do_re(object me, int i)
{
	if( i > sizeof(notes) || i < 1) {
		write("ÎŞ´Ë±àºÅ¡£\n");
		return 0;
	}

	if ( notes[i-1]["solve_id"]!="" ) {
		write(notes[i-1]["solve_id"]+"ÒÑ¾­±êÖ¾½â¾öÁË¡£\n");
		return 1;
	}
	write("ÇëÊäÈëÄãµÄ´¦Àí»Ø¸´£º\n");
	me->edit( (: done_re, me, i :) );
	return 1;
}

int main(object me, string arg)
{
	string s, str,arg1;
	int i,arg2;
	restore();

	if (!arg) {
		if(wizardp(me) && !me->query("env/test")) {
			list_bug(me,"test");
		} else {
			write(HIG"\nÔÄ¶Á×Ô¼ºµÄsosÇëÊ¹ÓÃsos read£¬Ã¿¸öÈËÖ»ÄÜÌîĞ´Ò»·İSOSĞÅÏ¢\n"NOR);
			write(HIG"\nÈç¹ûÒÑ¾­ÌîĞ´¹ıĞÅÏ¢£¬Ñ¡Ôñ "HIR"Y"HIG" ½«¸²¸ÇÄãÒÔÇ°Ğ´¹ıµÄSOSĞÅÏ¢\n"NOR);
			write(HIR "Õâ·İÇóÖúĞÅÏ¢½«±»ÈÏÎªÊÇ¹«¿ªµÄ£¬ÔÚÂÛÌ³ÉÏ¿É¼ûµÄ£¬Çë´ó¼Ò±£»¤×Ô¼ºµÄÒşË½¡£\n¶ÔÓÚÒ»Ğ©¸üÒşË½µÄÎÊÌâ£¬¿ÉÒÔ·¢ËÍµ½Î×Ê¦ĞÅÏä¡£\n"NOR);
			write(HIG"\nÄãÈ·¶¨ÒªĞ´Ò»·İSOSĞÅÏ¢Âğ£¿£¨Y/N£©\n"NOR);
			input_to((: confirm :), me);
		}
		return 1;
	}
	if(wizardp(me)){
		if( sscanf(arg, "re %s", arg1) == 1 ) {
			i = search_id(arg1);
			if( i > 0 ){
				do_re( me, i );
				return 1;
			}
		}
		if( sscanf(arg, "re %d", arg2) == 1 ) {
			do_re( me, arg2 );
			return 1;
		}
		if( sscanf(arg, "del %s", arg1) == 1 ) {
			i = search_id(arg1);
			if( !(i = sizeof(notes)) ) return notify_fail("Ã»ÈË·¢³ö sos Çó¾ÈĞÅºÅ¡£\n");
			printf("%sµÄ sos ÇóÖúÒÑ±»É¾³ı£¡£¡£¡\n", notes[i-1]["author"]);
			if( sizeof(notes) == 1 ) notes = ({});
			else if(i==1) notes = notes[1..sizeof(notes)-1];
			else if( i == sizeof(notes) ) notes = notes[0..sizeof(notes)-2];
			else notes = notes = notes[0..i-2] + notes[i..sizeof(notes)-1];
			save();
			return 1;
		}
	}

	if ( sscanf(arg, "%s", s) == 1 ){
	if (!wizardp(me) && arg !="read")
		return help(me);
	switch(arg){
	case "read":
		if( !(i = sizeof(notes)) )
			return notify_fail("»¹Ã»ÓĞÈË×ö¹ı sos ºô½Ğ£¡\n");
		else {
			i = search_id( me->query("id") );
			do_read(me,i);
		}
		break;

	case "all":
	case "list":
		list_bug(me,"all");
		break;
	case "bug":
		list_bug(me,"test");
		break;
	case "clear":
		if( !(i = sizeof(notes)) ) return notify_fail("Ã»ÈË·¢³ö sos Çó¾ÈĞÅºÅ¡£\n");
		for( ; i > 0; i-- )
		if( "" != notes[i-1]["solve_id"] ) {
			printf("%sµÄ sos ÇóÖúÒÑ±»É¾³ı£¡£¡£¡\n", notes[i-1]["author"]);
			if( sizeof(notes) == 1 ) notes = ({});
			else if(i==1) notes = notes[1..sizeof(notes)-1];
			else if( i == sizeof(notes) ) notes = notes[0..sizeof(notes)-2];
			else notes = notes = notes[0..i-2] + notes[i..sizeof(notes)-1];
		}
		save();
		break;
	case "re":
		return notify_fail("¸ñÊ½: sos re <±àºÅ»òÍæ¼Òid>\n");
		break;

	default:
		if( sscanf(arg, "%d", i) == 1 )
			do_read( me, i );
		else if( sscanf( arg, "%s", str ) == 1 ) {
			i = search_id(str);
			if( i == 0 ) return notify_fail("ÎŞ´ËÍæ¼Ò·¢³öµÄ sos ÇóÖúĞÅÏ¢£¡\n");
			do_read( me, i );
		}
	}
	}
	else return notify_fail("¸ñÊ½²»¶Ô£¬¾ßÌåÊ¹ÓÃ·½·¨Çë²ÎÔÄ help sos \n");
	return 1;
}

int confirm(string yn, object me)
{
	mapping note;
	object where;
	string s, mid;
	restore();
	mid = me->query("id");
	wizardp(me)? mid= sprintf("%s%d",mid,random(10)):mid=mid;
	if( upper_case(yn) == "Y" ) {
		tell_object(me, HIM "ÄãÕıÔÚ" HIW MUD_NAME NOR HIM "ÀïĞÁ¿àµØÍÚ×ÅÄà°Í£¬Í»È»·¢ÏÖÒ»Ö»´ó¸öµÄ³ô³æÏòÄãÅÀÀ´¡£\n" NOR);
		tell_object(me, HIM "Äã¸Ï½ôÏòÎ×Ê¦ÃÇ·¢³ö½ô¼±ÇóÖúĞÅºÅ£º£Ó£Ï£Ó£¡£¡£¡\n" NOR);
		tell_object(me, HIM "Çë½«³öÏÖµÄÇé¿öºÍÏµÍ³µÄÌáÊ¾¾¡Á¿ÏêÏ¸µØ½øĞĞËµÃ÷£¬ÒÔ±ãÎ×Ê¦ĞŞ¸Ä¡£\n"NOR);
		tell_object(me, HIR "Õâ·İÇóÖúĞÅÏ¢½«±»ÈÏÎªÊÇ¹«¿ªµÄ£¬ÔÚÂÛÌ³ÉÏ¿É¼ûµÄ£¬Çë´ó¼Ò±£»¤×Ô¼ºµÄÒşË½¡£\n¶ÔÓÚÒ»Ğ©¸üÒşË½µÄÎÊÌâ£¬¿ÉÒÔ·¢ËÍµ½Î×Ê¦ĞÅÏä¡£\n"NOR);
		tell_object(me, HIW "ÇëÊäÈë´Ë·İSOSµÄ±êÌâ£¬Çë¾¡¿ÉÄÜ¼ò¶óµÄËµÃ÷(³¤¶ÈÇë±£³ÖÔÚÎå¸öºº×Ö»òÕßÊ®¸ö×ÖÄ¸ÒÔÉÏ)£º"NOR);
		where = environment(me);
		if (!where )
			s=sprintf("%s(%s)ÇóÖú",me->query("name"), mid);
		else
			s=sprintf("%s(%s)ÔÚ %s ÇóÖú", me->query("name"), mid, (string)where->query("short"));

		note = allocate_mapping(6);
		note["title"] = s;
		note["author"] = mid;
		note["time"] = time();
		note["solve"] = "";
		note["solve_id"] = "";
		input_to("this_title", me,note);
		//me->edit( (: done_post, me, note :) );
	} else {
		write(HIW"Äú·ÅÆúÁËÌîĞ´SOSĞÅÏ¢¡£¡£¡£¡£\n"NOR);
		return 1;
	}
}

void this_title(string title,object me,mapping note)
{
	if(!title || !strlen(title) )
	{
		write(HIW"Äú·ÅÆúÁËÌîĞ´SOSĞÅÏ¢¡£¡£¡£¡£\n"NOR);
		return;
	}
	if(strlen(title)<10)
	{
		write(HIW"³¤¶È²»·ûºÏ¹æ·¶£¬ÇëÖØĞÂÊäÈë±êÌâ£º"NOR);
		input_to("this_title", me,note);		
		return;
	}
	note["title"]=title;
	tell_object(me, HIW "ÏÖÔÚÇëÄúÊäÈë´ËSOSÇóÖúµÄÏêÏ¸ÄÚÈİ£º\n"NOR);
	me->edit( (: done_post, me, note :) );
}

int help(object me)
{
	if (!wiz_level(me) )
	write(@HELP

Ö¸Áî¸ñÊ½ :
           sos
           sos read
Õâ¸öÖ¸Áî¿ÉÒÔÔÚÏµÍ³³öÏÖbugÊ±À´ÏòÎ×Ê¦ÇóÖú¡£
ÊäÈë¸ÃÃüÁîºó£¬ÏµÍ³½«ÌáÊ¾ÄãÊäÈë¶Ô bug µÄÃèÊö¡£Íæ¼ÒÔÚÕâÀïÓ¦¸Ã½« bug
³öÏÖµÄÇé¿öºÍÏµÍ³µÄÌáÊ¾¾¡Á¿ÏêÏ¸µØ½øĞĞËµÃ÷£¬ÒÔ±ãÎ×Ê¦ĞŞ¸Ä¸Ã bug¡£
Ã¿¸öÍæ¼ÒÖ»ÄÜÌùÒ»Ìõ sos£¬ĞÂµÄ sos ½«¸²¸ÇÒÔÇ°µÄÊäÈë¡£
¿ÉÒÔÓÃ sos read ÔÄ¶Á×Ô¼ºÌù³öµÄ sos¡£
HELP
 );
	else
	write(@HELP
Ö¸Áî¸ñÊ½ :
           sos
           sos bug             ÏÔÊ¾ËùÓĞÎ´½â¾öµÄsos¡£
	   sos all/list        ½«ËùÓĞµÄ sos ĞÅÏ¢½øĞĞÁĞ±í¡£
           sos <Êı×Ö»òID>      ½«ÏÔÊ¾¶ÔÓ¦ºÅÂë»ò¶ÔÓ¦Íæ¼ÒµÄ sos µÄÏêÏ¸ĞÅÏ¢¡
           sos clear           É¾³ıËùÓĞ±êÖ¾ÎªÒÑ½â¾öµÄ sos ĞÅÏ¢¡£
           sos del <Êı×Ö»òID>  É¾³ıÖ¸¶¨µÄ sos ĞÅÏ¢¡£
           sos re <Êı×Ö»òID>   ¶Ô sos ĞÅÏ¢½øĞĞ»Ø¸´¡£

Õâ¸öÖ¸Áî¿ÉÒÔ¸¨ÖúÎ×Ê¦´¦ÀíÍæ¼ÒÌá³öµÄ sos ÁĞ±í¡£
HELP
 );
    return 1;
}