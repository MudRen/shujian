// blacklist.c by tiantian@sj 2000.8.8

#include <ansi.h>
#include <login.h>

#define BL_FILE       "/data/blacklist"
#define NULL 0

inherit ITEM;
inherit F_SAVE;

nosave object ob = 0;
nosave string rcpt,msg,subject;

mapping *notes;

string seed = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

string query_save_file();
string make_password();
void list_bllist(object me, int num);

int is_black(string arg)
{
	foreach (mapping item in notes)
		if (arg == item["player"]) return 1;
	return 0;
}

void create()
{
	seteuid(getuid());
	restore();
}

int main(object me, string arg)
{
	mapping note;
	string s,arg1,arg2;
	int num;
	object ob;
	string password;
	
	if (!arg) {
		list_bllist(me, 10);
		return 1;
	}

    if (sscanf(arg, "%s", s) == 1) {
		if ( s == "all" ) {
			list_bllist(me,0);
			return 1;
		}
	}

	if (sscanf(arg, "%s because %s", arg1, arg2) == 2) {
		if (wiz_level(me)<4)
			return notify_fail("ֻ��arch�ſ��Խ��������������� \n");
		if (strlen(arg2)< 8 || strlen(arg2)>44)
			return notify_fail("�������Ҫ��˵��ԭ������������4-20֮�䡣 \n");
        ob = LOGIN_D->find_body(arg1);
		if(ob)
			"/cmds/wiz/kickout"->main(me, arg1);
        ob = LOGIN_D->find_body(arg1);
		if(!ob) {
			if( file_size(DATA_DIR + "login/" + arg1[0..0] + "/" + arg1 + SAVE_EXTENSION)<0 )
                return notify_fail("û����λʹ���ߡ�\n");
			ob = new(LOGIN_OB);
			ob->set("id",arg1);
			if( !ob->restore() ) {
				destruct(ob);
				return notify_fail("û�������ҡ�\n");
			}
			else {
				password = make_password();
				ob->set("password",crypt(password, "$1$ShuJian"));
				log_file("static/bllist",
					sprintf("%s(%s)��%s(%s)�����������\n", 
						me->query("name"), me->query("id"),
						ob->query("name"), ob->query("id")
					), me, ({ ob->query("id") })
				);
				ob->save();
				destruct(ob);
			}
		}
		note = allocate_mapping(6);
		note["time"] = time();
		note["block"] = me->query("id");
		note["player"] = arg1;
		note["reason"] = arg2;
		note["unblock"] = NULL;
		note["result"] = NULL;
        if( !pointerp(notes) || !sizeof(notes) )
                notes = ({ note });
        else
                notes += ({ note });
		save();
		write("���"+arg1+"�ɹ��������������\n");
		return 1;
	}

	if (sscanf(arg, "-d %d", num)== 1) {
		if ( wiz_level(me)<4 )
			return notify_fail("ֻ��arch�ſ���ɾ���������ϵ����ݡ� \n");
		if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
			return notify_fail("û�������ŵ����ݡ�\n");
		num--;
		arg1=notes[num]["player"];
        ob = LOGIN_D->find_body(arg1);
        if(!ob){
			ob = new(LOGIN_OB);
			ob->set("id",arg1);
			if( !ob->restore() ) {
				destruct(ob);
			}
			else {
//				password = make_password();
//				ob->set("password",crypt(password, "$1$ShuJian"));
				log_file( "static/bllist",
					sprintf("%s(%s)�Ѻ������Ϲ���%s(%s)������ɾ����\n", 
						me->query("name"), me->query("id"),
						ob->query("name"), ob->query("id")
					), me, ({ ob->query("id") })
				);
//				ob->save();
				destruct(ob);
//				write("�û�"+arg1+"�����뱻�޸�Ϊ"+password+"����ͨ��mail֪ͨ���û���\n");
			}
        }
		else
			return notify_fail("��û�и���������ϵ�����ô�����ˣ����Ȱ����߳�ȥ��˵�ɡ�\n");
		notes = notes[0..num-1] + notes[num+1..<1];
		save();
		write("��"+ (num+1) + "�������Ѿ�ɾ����\n");
		return 1;
	}

	if (sscanf(arg, "-r %d %s", num, arg2)== 2) {
		if ( wiz_level(me)<4 )
			return notify_fail("ֻ��arch�ſ����޸ĺ������ϵ����ݡ� \n");
		if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
			return notify_fail("û�������ŵ����ݡ�\n");
		if( notes[num-1]["result"] && notes[num-1]["unblock"] )
			return notify_fail("�������Ѿ����˵������ˡ�\n");
		arg1=notes[num-1]["player"];
        ob = LOGIN_D->find_body(arg1);
        if(!ob){
			ob = new(LOGIN_OB);
			ob->set("id",arg1);
			if( !ob->restore() ) {
				destruct(ob);
			}
			else {
				password = make_password();
				ob->set("password",crypt(password, "$1$ShuJian"));
				log_file("static/bllist",
					sprintf("%s(%s)����������Ϲ���%s(%s)�ĵ�������\n", 
						me->query("name"), me->query("id"),
						ob->query("name"), ob->query("id")
					), me, ({ ob->query("id") })
				);
				ob->save();
				destruct(ob);
				write("�û�"+arg1+"�����뱻�޸�Ϊ"+password+"����ͨ��mail֪ͨ���û���\n");
			}
        }
		else
			return notify_fail("��û�и���������ϵ�����ô�����ˣ����Ȱ����߳�ȥ��˵�ɡ�\n");
		notes[num-1]["unblock"]=me->query("id");
		notes[num-1]["result"]=arg2;
		save();
		write("��"+ (num) + "�������޸���ϡ�\n");
		return 1;
	}

	if (sscanf(arg, "-dr %d", num)== 1) {
		if ( wiz_level(me)<4 )
			return notify_fail("ֻ��arch�ſ����޸ĺ������ϵ����ݡ� \n");
		if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
			return notify_fail("û�������ŵ����ݡ�\n");
		arg1=notes[num-1]["player"];
        ob = LOGIN_D->find_body(arg1);
        if(!ob){
			ob = new(LOGIN_OB);
			ob->set("id",arg1);
			if( !ob->restore() ) {
				destruct(ob);
			}
			else {
				password = make_password();
				ob->set("password",crypt(password, "$1$ShuJian"));
				log_file("static/bllist",
					sprintf("%s(%s)ɾ���������Ϲ���%s(%s)�ĵ�������\n", 
						me->query("name"), me->query("id"),
						ob->query("name"), ob->query("id")
					), me, ({ ob->query("id") })
				);
				ob->save();
				destruct(ob);
			}
        }
		else
			return notify_fail("��û�и���������ϵ�����ô�����ˣ����Ȱ����߳�ȥ��˵�ɡ�\n");
		notes[num-1]["unblock"]=NULL;
		notes[num-1]["result"]=NULL;
		save();
		write("��"+ (num) + "�������޸���ϡ�\n");
		return 1;
	}

	write("�﷨������help blacklist��\n");
	return 1;
}

string query_save_file()
{
	return BL_FILE ;
}

string make_password()
{
        int i = 8, j;
        string id = "";

        while (i--) {
                j = random(52);
                id += seed[j..j];
        }
//	return id;
	return "";
}

void list_bllist(object me, int num)
{
	int i;
	string str;

	i = sizeof(notes);
	if( i < 1 ) write("�齣������Ŀǰû���κ����ݡ�\n");
	else {
		str="�齣��������\n";
		str += repeat_string("-", 80) + "\n";
		while (i-- && (i>=sizeof(notes)-num || num==0)) {
			str += sprintf("%3d %s %-9s��Ϊ %-=22s ��%s�����������%s\n",
				i+1,
				ctime(notes[i]["time"])[4..15],
				notes[i]["player"],
				notes[i]["reason"],
				wizardp(me)?notes[i]["block"]:"",
				notes[i]["result"] && notes[i]["unblock"]?
					("��������"+notes[i]["result"]+
						(wizardp(me)?
							("��������"+notes[i]["unblock"])
							:"")
						)
					:"���ܵ���"
			);
			str += repeat_string("-", 80) + "\n";
		}
	}
	me->start_more( str );
}

int help(object me)
{
	if (!wiz_level(me) )
        write(@HELP
ָ���ʽ :
blacklist [all]                 �鿴�����������ݺʹ�����

��ʦ��������Υ���������ҵǼ�����������ܵ��飬�ڽ��ܵ����ڼ䣬
�����id������ʱ��գ�����������Ϸ��
�������֮����ʦ�Ὣ�����id�������뷢�͵���ҵ�ע�����䡣
�����ҷ����Լ���������޷���¼������ʹ������id�鿴����������
�Լ��Ƿ����ڽ������顣

HELP);
    else 
        write(@HELP
ָ���ʽ :
blacklist [all]                 �鿴�����������ݺʹ�����
blacklist <id> because <ԭ��>   �����������������Ⱥ���鴦��
blacklist -d <����>             ɾ��ָ����ŵĺ�����
blacklist -r <����> <����>      �ǼǺ�������ָ����ŵ��¼��ĵ�����
blacklist -dr <����>            ɾ��ָ����ŵĺ������ĵ�����

��ʦ��������Υ���������ҵǼ�����������ܵ��飬�ڽ��ܵ����ڼ䣬
�����id������ʱ��գ�����������Ϸ��
�������֮����ʦ�Ὣ�����id�������뷢�͵���ҵ�ע�����䡣
�����ҷ����Լ���������޷���¼������ʹ������id�鿴����������
�Լ��Ƿ����ڽ������顣

HELP);
        return 1;
}
