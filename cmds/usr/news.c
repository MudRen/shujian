//BBB 09/25/1999
//����Ҳ���©���κ���Ҫ���ţ�Ҳ��Ҫ��;����ȥ����ʦ����档
// Modify by snowman@SJ for new_list when login.
// Modified By Numa@SJ 2000.3.31 For write all to player
// Modified By bbb@SJ 2000.11.03 For Mysql
// Modified by snowman@SJ 19/12/2000 for faster speed.

// Modified by mxzhao 2004/02/18

inherit F_SAVE;

#include <ansi.h>
#include <net/dns.h>
#include <mudlib.h>
#include <database.h>

#define Data_Base_Online

#define NEWS_DIR       "/data/"
#define NEWS_FILENAME  "news"
#define NEWS_TITLE  "\n���������������������������� "HIY"�齣������Ϸ�����б�"NOR" ����������������������������\n"
#define NEWS_END  "������������������������������������������������������������������������������\n"
#define NEWS_P HIY"����ϵͳ��ʾ��"NOR
#define BBS_URL(x) sprintf(CYN"���ڱ����ŵ������������%s/viewthread.php?tid=%d��\n"NOR,BBS_ADDR,x)

nosave object ob = 0;
nosave int status=0;
nosave string msg,subject;

mapping *notes;

public string query_version(object ob)
{
	if(ob==find_object(BBS_D)) return "1.0";
}

string query_save_file()
{
	return NEWS_DIR + NEWS_FILENAME ;
}

void tell_me(string msg)
{
	if (objectp(ob)) tell_object(ob, msg);
}
//����������ں�����ϵͳ��������о�����
string Ctime(int t)
{
        string ts = ctime(t);
        string str = ts[8..9];
	if (str == " 1" || str == " 2" || str == " 3" || str == " 4" 
	|| str == " 5" || str == " 6" || str == " 7" || str == " 8" || str == " 9")
	
	str = "0" + ts[8..9];	
        ts = ts[0..2]+ts[19..23]+ts[4..6]+str+ts[10..18];
        
        ts = replace_string(ts, ":", "");
        ts = replace_string(ts, " ", "");
        ts = replace_string(ts, "Sun", "");
        ts = replace_string(ts, "Mon", "");
        ts = replace_string(ts, "Tue", "");
        ts = replace_string(ts, "Wed", "");
        ts = replace_string(ts, "Thu", "");
        ts = replace_string(ts, "Fri", "");
        ts = replace_string(ts, "Sat", "");
        ts = replace_string(ts, "Jan", "01");
        ts = replace_string(ts, "Feb", "02");
        ts = replace_string(ts, "Mar", "03");
        ts = replace_string(ts, "Apr", "04");
        ts = replace_string(ts, "May", "05");
        ts = replace_string(ts, "Jun", "06");
        ts = replace_string(ts, "Jul", "07");
        ts = replace_string(ts, "Aug", "08");
        ts = replace_string(ts, "Sep", "09");
        ts = replace_string(ts, "Oct", "10");
        ts = replace_string(ts, "Nov", "11");
        ts = replace_string(ts, "Dec", "12");
        return ts;
}

nosave int op;

void post_ok(mixed ret)
{	
	if(!ret || !sizeof(ret)) return;
	if(!notes || !sizeof(notes)) return;
	if(op != sizeof(notes)-1) return;//have somebody change it
	notes[op]["tid"] = ret[0][0];
	save();
}

void done_post(object me,mapping note, string text)
{
	int i;
	note["msg"] = text;
	i = sizeof(notes);
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });
	note["time"] = time();
	if(userp(me)) tell_object(me, NEWS_P + HIM "���ŷ�����ϡ����б�Ҫ���뷢������ҳ��ʹ�÷����� help news\n"NOR);
        message("system",HIW"\n\n�����š�������Ϸ���ţ����� news ָ��鿴���������ҳ www.SJzitan.com ��\n\n"NOR, users());
	save();
	if(me&&userp(me))
/*
	{
#ifdef Data_Base_Online
		string msg = ( sprintf("[%d] %-=31s %18s (%s)\n" + NEWS_END,sizeof(notes),note["title"], " ",ctime(note["time"])[0..15]) + note["msg"] );
		string subject = ( sprintf("%s",note["title"]) );
		op = sizeof(notes)-1;
		if(BBS_D->bbs_post(10,"system","����������"+note["title"],text,0,0,0,this_object(),"post_ok" ) )
			tell_object(me,NEWS_P +"news  ���͵���̳������ϡ�\n");
		else tell_object(me,NEWS_P +"news  ���͵���̳����ʧ�ܡ�\n");
				
		if (BBS_D->add_Bbs_Up_Map(WEB_DB_NAME, "INSERT INTO announcements (author, subject, starttime, endtime, message) VALUES ('master', '"+subject+"', '"+time()+"', '0', '"+msg+"')"))
			tell_object(me,NEWS_P +"news  ���͵���̳������ϡ�\n");
		else
			tell_object(me,NEWS_P +"news  ���͵���̳����ʧ�ܡ�\n");
		if (BBS_D->add_Bbs_Up_Map(WEB_DB_NAME,"INSERT INTO izz_text_soft (soft_name, soft_keyword, soft_download_url, soft_is_commend,soft_grade, soft_type, soft_note, soft_author, soft_relation_url,soft_category_id, soft_class_id, soft_img, soft_byuser, soft_user_id,soft_size, soft_date, soft_hits_day, soft_display) VALUES ( '"+subject+"', '����', 'Wizard', '0', '3', 'ԭ��', '"+msg+"', '�齣�ٷ�վ', 'http://www.sjmud.com.cn', '10','51', 'N/A', 'Master', '17', 'N/A', '"+Ctime(note["time"])+"', '20040127', '1' )"))
			tell_object(me,NEWS_P +"news  ���͵���ҳ��ϡ�\n");
		else tell_object(me,NEWS_P +"news  ���͵���ҳʧ�ܡ�\n");		
#endif
		//send to others
		"/adm/daemons/network/services/newsmsg"->send_msg(note["title"],note["author"],note["poster"],text);
	}
	*/
	
	
		"/adm/daemons/network/services/newsmsg"->send_msg(note["title"],note["author"],note["poster"],text);	
	return;
}

void list_news(object me, int login)
{
	int i = 0, ulogin, j = 0;
	string str;

	if (sizeof(notes) < 1)
		write("û���κ����š�\n");
	else {
		ulogin = me->query("last_news");
		str = NEWS_END;
		foreach (mapping item in notes) {
			i++;
			if (ulogin < item["time"]) {
				if (j++ < 15)
					str = sprintf("%3d) %-=40s %18s (%s)\n%s",
						i, item["title"],
						wizardp(me)?item["poster"]+"("+capitalize(item["author"])+")":"",
						ctime(item["time"])[0..9], str
					);
			}
		}
		if (!j)
			write(NEWS_P+"Ŀǰû���·��������š�\n");
		else {
			if (login && j > 5)
				;
			else
				write(NEWS_TITLE + str);
			write(NEWS_P+"Ŀǰ���� "+ i +" �����š�"+ j +" ��δ����\n");
			write("���� news �Ķ����⣬���� news new|next|��� �Ķ���ϸ���ݡ�\n");
		}
	}
}

void list_allnews(object me)
{
	int i;
	string str;

	i = sizeof(notes);
	if ( i < 1) {
		write(NEWS_P +"û���κ����š�\n");
		return;
	}
	str = NEWS_TITLE;
	while( i-- )
		str += sprintf("%3d) %-=40s %18s (%s) \n",
			i+1, notes[i]["title"], wizardp(me)?notes[i]["poster"]+"("+capitalize(notes[i]["author"])+")":"",
			ctime(notes[i]["time"])[0..9] );
	str += NEWS_END;
	me->start_more(str);
}

void create()
{
	seteuid(getuid());
	restore();
	call_out("create", 900);
}
/*���ǹ�Ask���õ� LinuX@SJ*/
string read_last_news()
{
	int size = sizeof(notes);
	int num;
	string str;
	if (size < 10) return "���û��������ʲô���š�";
	num = size - 1 - random(10);
	if (strlen(notes[num]["msg"]) > 400) return "���û��������ʲô�����š�";
	str = "\n��������������������������������������������������������\n"
	+ HIY+notes[num]["title"] + NOR+"\n"+ notes[num]["msg"] + "��������������������������������������������������������\n";			
	return str;
	
}

int main(object me, string arg)
{
	mapping note;
	string s,arg1;
	int num = -1;

/*#ifdef Data_Base_Online
	//int mysql,rows;
	string forum;
#endif
*/
	if (!arg) {
		list_news(me, 0);
		return 1;
	}

	if (sscanf(arg, "%s", s) == 1) {
		if ( s == "all" ) {
			list_allnews(me);
			return 1;
		}
		if ( s == "post" ){
			if( wiz_level(me)<3 )
				return notify_fail(NEWS_P +"ֻ����ʦ�ſ��Է�����Ϣ�� \n");
			else 	return notify_fail("ʹ�÷����� news post <����> \n");
		}
		if ( s == "delete" ){
			if( wiz_level(me)<3 )
				return notify_fail(NEWS_P +"ֻ����ʦ�ſ���ɾ����Ϣ�� \n");
			else	return notify_fail("ʹ�÷����� news delete <���> \n");
		}
	}

	if (sscanf(arg, "post %s", arg1) == 1) {
		if ( wiz_level(me)<3 )
			return notify_fail(NEWS_P +"ֻ����ʦ�ſ��Է�����Ϣ�� \n");
		if ( strlen(arg1)< 8 || strlen(arg1)>40 )
			return notify_fail(NEWS_P +"�������Ҫ��˵�����⣬��������������4-20֮�䣬��ֹʹ�ÿ�ͷ���ԡ� \n");
		else note = allocate_mapping(5);
		note["title"] = arg1;
		note["author"] = getuid(me);
		note["poster"] = me->query("name");
		me->edit( (: done_post, me, note :) );
		return 1;
	}

	if (sscanf(arg, "delete %d", num)== 1) {
		if ( wiz_level(me)<3 )
			return notify_fail(NEWS_P +"ֻ����ʦ�ſ���ɾ����Ϣ�� \n");
		if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
			return notify_fail(NEWS_P +"û�������ŵ����š�\n");
		else num--;
		notes = notes[0..num-1] + notes[num+1..<1];
		save();
		write(NEWS_P +"ɾ���� " + (num+1) + " ������....Ok����������ű���������ҳ����ȥ��ҳɾ����\n");
		return 1;
	}

	if (arg == "new" || arg == "next") {
		int ulogin = me->query("last_news");

		num = sizeof(notes);
		while (num--)
			if (ulogin >= notes[num]["time"])
				break;
		num+=2;
	}

	if (num+1 || sscanf(arg, "%d", num) == 1) {
		int size = sizeof(notes);
		string bbs_msg = "";
		
		
				
		if (!size)
			return notify_fail(NEWS_P +"û���κ����š�\n");
		if (num < 1 || num > size)
			return notify_fail(NEWS_P +"û�������ŵ����š�\n");
		num--;
		
		if(notes[num]["tid"]) bbs_msg = BBS_URL(notes[num]["tid"]);

		me->start_more(sprintf("%d) %-=43s %8s(%s)(%s)\n"+NEWS_END,
			num + 1, notes[num]["title"],
			wizardp(me)?notes[num]["poster"]:"",
			wizardp(me)?notes[num]["author"]:"News",
			ctime(notes[num]["time"])[0..15]) + notes[num]["msg"] + bbs_msg +"������������������������������������������������������������������[ �� ƪ �� ]"
		);
		if (me->query("last_news") < notes[num]["time"])
			me->set("last_news", notes[num]["time"]);
		return 1;
	}

	if ( arg == "write all" ) {
		if (!wizardp(me))
			return notify_fail("������ʦ���\n");
		if( !pointerp(notes) || !sizeof(notes) )
			return notify_fail(NEWS_P +"û���κ����š�\n");
		msg = NEWS_TITLE;
		for (num=0;num<sizeof(notes);num++) {
			msg += sprintf(HIW"%d"NOR") %-=43s %8s(%s)(%s)\n"+NEWS_END,num + 1, notes[num]["title"],
				wizardp(me)?notes[num]["poster"]:"",wizardp(me)?notes[num]["author"]:"",
				ctime(notes[num]["time"])[0..15]) + notes[num]["msg"] + "\n\n";
		}
		me->start_more(msg);
		return 1;
	}
}

int help(object me)
{
	if (!wiz_level(me) )
	write(@HELP
ָ���ʽ :
news		�鿴���ʮ����δ���������б�
news all	�鿴ȫ�������б�
news new|next	�鿴���һ��δ�����ŵ���ϸ���ݡ�
news <���>	�鿴�˱�����ŵ���ϸ���ݡ�

����������ҪΪ��ϵͳ���桢����Ķ������ִ��¡�
HELP);

	else
	write(@HELP
ָ���ʽ :
news				�鿴���ʮ����δ���������б�
news all			�鿴ȫ�������б�
news new|next			�鿴���һ��δ�����ŵ���ϸ���ݡ�
news <���>			�鿴�˱�����ŵ���ϸ���ݡ�
news post <����>		�������ţ�wizard ����������ʦר��
news delete <���>		ɾ�����ţ�wizard ����������ʦר��
news write all			�г�ȫ�� news ����ϸ����
news send <���> <��̳ID>	�������ŵ���ҳ������ѡ��ͬ������������

��̳ID���£�ϵͳ����(info) ����(shaolin)  �䵱(wudang)
��ɽ(huashan) �һ�(taohua) ����(tiezhang) ����(shenlong)
����(xingxiu) ����(emei)   ��ɽ(songshan) ѩɽ(xueshan)
��Ĺ(gumu)    Ľ��(murong) ����(mingjiao) ؤ��(gaibang) ����(tianlong)
��վ��̳�ֱ�Ϊ��ln sh qhd zj hb sd yt dd gz cdedu

���;�����news send 122 info

ע�⣺  1������������ҪΪ��ϵͳ���桢����Ķ������ִ��¡�
	2��δ��ȷʵ����Ϣ�Ͻ������������������ɾ����
	3���ش����䶯��������漰��ң������ô˷���ͨ�棬���Դ�Ϊ׼��
	4�����ŷ����漰ȫ�ֵģ����뷢����info��������ɵķ����ε�info��������,��Է�վ�ķ����ε�info�ͷ�վ��
	5��ע�ⷢ��ʱ������ȷ����Ҫ�������壬��Ҫʹ�ÿ�ͷ���ԡ�
HELP);
	return 1;
}
