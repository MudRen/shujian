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
#define BBS_OK(x) sprintf(WHT"%s������̳��ɡ�\n"NOR,x)
#define BBS_URL(x) sprintf(CYN"�����������%s/viewthread.php?tid=%d��\n"NOR,BBS_ADDR,x)

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
		return  "��Ⱦ���";
	return 0;
}

nosave int op;

void post_ok(mixed ret)
{
	//mapping *notes;	
	//if(environment()) tell_room(environment(),BBS_OK("����"));
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
	//if(environment()) tell_room(environment(),BBS_OK("�ظ�"));
	//if(ret && sizeof(ret)) if(environment()) tell_room(environment(),BBS_URL(ret[0][0]));
	message("wizard",sprintf("�ظ�OK\n"),users());
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
	
	message("wizard", HIY "����ȡ������ "+note["author"]+" ʹ��"BLINK" SOS "NOR HIY"������ȣ���������ʦʹ�� sos ����鿴��\n" NOR,users());
	
	ob = new(LOGIN_OB);
        ob->set("id", me->query("id"));
        ob->restore();
        mail = ob->query("email");
        destruct(ob);

      	msg = ""+note["title"]+"\n"+
      	note["msg"]+"\n"+
      	"�������:"+mail+"\n"+
      	ctime(time()) +"\n";
      	
	tell_object(me, WHT "\n�����ϣ������Ϣ�Ѿ����ӵ���ʦ֪ͨ��Ϣ������ʼ���������ʦ���\n");
	tell_object(me, WHT "���������̳�������������Ϣ����ʦ�п��ܻ�����̳���������⣬�����⣺"+BBS_ADDR+"/forumdisplay.php?fid="+BBS_TNUM+"��\n");
	tell_object(me, WHT "��ʦ���ڴ���������ң���ȴ�......\n");
	tell_object(me, WHT "�������ʱ��sos read�����߲鿴����ע���������ʼ��ж��Ƿ񱻽����\n" NOR);
	SMTP_D->send_mail(me, WIZ_MAIL,CHINESE_MUD_NAME+"���" + note["author"] + "����ź�", msg);
	/*BBS_D->bbs_post(
		BBS_TNUM,
		wizardp(me)?me->query("id"):me->query("id")+"@"+lower_case(INTERMUD_MUD_NAME),
		strip("�����������⡿��"+note["title"]),
		"\n\n" + text,0,0,0,0,0 );*/
	BBS_D->bbs_post(
	BBS_TNUM,wizardp(me)?"master":me->query("id")+"@"+lower_case(INTERMUD_MUD_NAME),
	strip("�����������⡿��"+note["title"]),
	"\n\n" + text,0,0,0,this_object(),"post_ok");
			
	save();
	return;
}

void list_bug(object me, string arg)
{
	int i;
	string str,s;

	if (sizeof(notes)<1) {
		write("û�˷��� sos ����źš�\n");
		return;
	}
	arg == "all"?s="ȫ��":s="δ���";
	s = sprintf("��ǰ����("+sizeof(notes)+")��SOS��"+s+"��Ϣ�б�����:\n"
	"��������������������������������������������������������������������������\n");
	for( i = 0; i<sizeof(notes); i++){
		if( arg=="all" ){
			str = sprintf("[%2d] %-40s%10s [%s] \n",
			i+1, notes[i]["title"], notes[i]["solve_id"]==""?"��δ�ظ�":"By "+notes[i]["solve_id"],
			ctime(notes[i]["time"])[0..15] );
			s = s + str;
		}
		else{
			if(notes[i]["solve_id"]=="") {
				str = sprintf("[%2d] %-40s%10s [%s] \n",
				i+1, notes[i]["title"], "��δ�ظ�",
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
		wizardp(me)?write("�޴˱�ţ�\n"):write("Ŀǰû���㷢����SOS��Ϣ��\n");
		return;
	}

	s = sprintf("(%d) %-46s "HIW"ʱ�䣺"NOR"%s\n"
	"��������������������������������������������������������������������������\n"
	"%s\n"
	"��ʦ����ظ�:��%s��\n"NOR
	HIG"%s\n"NOR,
	i, notes[i-1]["title"], ctime(notes[i-1]["time"])[0..15],
	notes[i-1]["msg"], notes[i-1]["solve_id"]==""?"��δ�ظ�":"By "+notes[i-1]["solve_id"],
	notes[i-1]["solve"] );
	
	if(notes[i-1]["tid"]) s+= sprintf("��̳���ܻ��и���Ľ��%s",BBS_URL(notes[i-1]["tid"]) );
		
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
		tell_object(obj, HIG "������ʦ�Ѿ��ظ����sos����ʹ��sos read�鿴��\n");
	}
	ob = new(LOGIN_OB);
        ob->set("id", notes[i-1]["author"]);
        ob->restore();
        mail = ob->query("email");
        destruct(ob);
	
	msg = ""+notes[i-1]["title"]+"\n"+
      	notes[i-1]["msg"]+"\n"+
      	"��ʦ�ظ���\n"+
      	text+
      	ctime(time()) +"\n";
      	
        SMTP_D->send_mail(me, mail,CHINESE_MUD_NAME+"����Ա����SOS�Ļظ�", msg);
	write("�� sos ��Ϣ�ѱ�־Ϊ�����\n");
	
	if(notes[i-1]["tid"])
	{
		BBS_D->bbs_post(BBS_TNUM,"master","����Ա����Ϸ�еĵĻظ�",text,notes[i-1]["tid"],0,0,0,0);
		BBS_D->add_Bbs_Up_Map(WEB_DB_NAME,sprintf("UPDATE %s SET solve='1' WHERE tid='%d' AND fid='%d'",BBS_THREADS,notes[i-1]["tid"],BBS_TNUM),0,0);		
	}		
	return;
}

int do_re(object me, int i)
{
	if( i > sizeof(notes) || i < 1) {
		write("�޴˱�š�\n");
		return 0;
	}

	if ( notes[i-1]["solve_id"]!="" ) {
		write(notes[i-1]["solve_id"]+"�Ѿ���־����ˡ�\n");
		return 1;
	}
	write("��������Ĵ���ظ���\n");
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
			write(HIG"\n�Ķ��Լ���sos��ʹ��sos read��ÿ����ֻ����дһ��SOS��Ϣ\n"NOR);
			write(HIG"\n����Ѿ���д����Ϣ��ѡ�� "HIR"Y"HIG" ����������ǰд����SOS��Ϣ\n"NOR);
			write(HIR "���������Ϣ������Ϊ�ǹ����ģ�����̳�Ͽɼ��ģ����ұ����Լ�����˽��\n����һЩ����˽�����⣬���Է��͵���ʦ���䡣\n"NOR);
			write(HIG"\n��ȷ��Ҫдһ��SOS��Ϣ�𣿣�Y/N��\n"NOR);
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
			if( !(i = sizeof(notes)) ) return notify_fail("û�˷��� sos ����źš�\n");
			printf("%s�� sos �����ѱ�ɾ��������\n", notes[i-1]["author"]);
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
			return notify_fail("��û�������� sos ���У�\n");
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
		if( !(i = sizeof(notes)) ) return notify_fail("û�˷��� sos ����źš�\n");
		for( ; i > 0; i-- )
		if( "" != notes[i-1]["solve_id"] ) {
			printf("%s�� sos �����ѱ�ɾ��������\n", notes[i-1]["author"]);
			if( sizeof(notes) == 1 ) notes = ({});
			else if(i==1) notes = notes[1..sizeof(notes)-1];
			else if( i == sizeof(notes) ) notes = notes[0..sizeof(notes)-2];
			else notes = notes = notes[0..i-2] + notes[i..sizeof(notes)-1];
		}
		save();
		break;
	case "re":
		return notify_fail("��ʽ: sos re <��Ż����id>\n");
		break;

	default:
		if( sscanf(arg, "%d", i) == 1 )
			do_read( me, i );
		else if( sscanf( arg, "%s", str ) == 1 ) {
			i = search_id(str);
			if( i == 0 ) return notify_fail("�޴���ҷ����� sos ������Ϣ��\n");
			do_read( me, i );
		}
	}
	}
	else return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help sos \n");
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
		tell_object(me, HIM "������" HIW MUD_NAME NOR HIM "�������������ͣ�ͻȻ����һֻ����ĳ�������������\n" NOR);
		tell_object(me, HIM "��Ͻ�����ʦ�Ƿ������������źţ��ӣϣӣ�����\n" NOR);
		tell_object(me, HIM "�뽫���ֵ������ϵͳ����ʾ������ϸ�ؽ���˵�����Ա���ʦ�޸ġ�\n"NOR);
		tell_object(me, HIR "���������Ϣ������Ϊ�ǹ����ģ�����̳�Ͽɼ��ģ����ұ����Լ�����˽��\n����һЩ����˽�����⣬���Է��͵���ʦ���䡣\n"NOR);
		tell_object(me, HIW "������˷�SOS�ı��⣬�뾡���ܼ���˵��(�����뱣����������ֻ���ʮ����ĸ����)��"NOR);
		where = environment(me);
		if (!where )
			s=sprintf("%s(%s)����",me->query("name"), mid);
		else
			s=sprintf("%s(%s)�� %s ����", me->query("name"), mid, (string)where->query("short"));

		note = allocate_mapping(6);
		note["title"] = s;
		note["author"] = mid;
		note["time"] = time();
		note["solve"] = "";
		note["solve_id"] = "";
		input_to("this_title", me,note);
		//me->edit( (: done_post, me, note :) );
	} else {
		write(HIW"����������дSOS��Ϣ��������\n"NOR);
		return 1;
	}
}

void this_title(string title,object me,mapping note)
{
	if(!title || !strlen(title) )
	{
		write(HIW"����������дSOS��Ϣ��������\n"NOR);
		return;
	}
	if(strlen(title)<10)
	{
		write(HIW"���Ȳ����Ϲ淶��������������⣺"NOR);
		input_to("this_title", me,note);		
		return;
	}
	note["title"]=title;
	tell_object(me, HIW "�������������SOS��������ϸ���ݣ�\n"NOR);
	me->edit( (: done_post, me, note :) );
}

int help(object me)
{
	if (!wiz_level(me) )
	write(@HELP

ָ���ʽ :
           sos
           sos read
���ָ�������ϵͳ����bugʱ������ʦ������
����������ϵͳ����ʾ������� bug �����������������Ӧ�ý� bug
���ֵ������ϵͳ����ʾ������ϸ�ؽ���˵�����Ա���ʦ�޸ĸ� bug��
ÿ�����ֻ����һ�� sos���µ� sos ��������ǰ�����롣
������ sos read �Ķ��Լ������� sos��
HELP
 );
	else
	write(@HELP
ָ���ʽ :
           sos
           sos bug             ��ʾ����δ�����sos��
	   sos all/list        �����е� sos ��Ϣ�����б�
           sos <���ֻ�ID>      ����ʾ��Ӧ������Ӧ��ҵ� sos ����ϸ��Ϣ�
           sos clear           ɾ�����б�־Ϊ�ѽ���� sos ��Ϣ��
           sos del <���ֻ�ID>  ɾ��ָ���� sos ��Ϣ��
           sos re <���ֻ�ID>   �� sos ��Ϣ���лظ���

���ָ����Ը�����ʦ������������ sos �б�
HELP
 );
    return 1;
}