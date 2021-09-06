// seek.c Looklove@sj 2002.7.19 ������ң���ʾ������ʦ��Ŀ����ҵ�¼��
// Ӧ����/cmds/wiz/���棬Ȼ����logind.c �������һ����ʾ����ҵ�¼����Ϣ��

#include <ansi.h>
#include <login.h>

#define SEEK_FILE       "/data/seek"
#define NULL 0

inherit ITEM;
inherit F_SAVE;

nosave object ob = 0;
nosave string rcpt,msg,subject;

mapping *notes;

string query_save_file();

void list_seeklist(object me, int num);

int is_seek(string target, string arg)
{
	foreach (mapping item in notes)
		if (target == item["player"]
		&& arg == item["block"]
		&& LOGIN_D->find_body(arg) )
			return 1;
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
	string s, arg1, arg2;
	int num;
	object ob;

	if (!arg) {
		list_seeklist(me, 10);
		return 1;
	}

	if (sscanf(arg, "%s", s) == 1) {
		if ( s == "all" ) {
			list_seeklist(me,0);
			return 1;
		}
	}

	if (sscanf(arg, "%s because %s", arg1, arg2) == 2) {
		if (strlen(arg2)< 8 || strlen(arg2)>44)
			return notify_fail("�������Ҫ��˵��ԭ������������4-20֮�䡣 \n");
		ob = LOGIN_D->find_body(arg1);
		if(ob)
			return notify_fail("�����Ѿ����ߣ����صȴ�������������\n");

                ob = new(LOADUSER_OB, arg1);
                if (!ob->restore()) {
                        destruct(ob);
                        return notify_fail("û�������ҡ�\n");
                }
		else {
			log_file("static/seeklist",
				sprintf("%s(%s)����%s(%s)��\n",
					me->query("name"), me->query("id"),
					ob->query("name"), ob->query("id")
				), me, ({ ob->query("id") })
			);
			destruct(ob);
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
		write("��ɹ���"+arg1+"���봫����������������ϵͳ�������㡣\n");
		return 1;
	}

	if (sscanf(arg, "-d %d", num)== 1) {
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
				log_file( "static/seeklist",
					sprintf("%s(%s)��%s(%s)�Ӵ���������ɾ����\n",
						me->query("name"), me->query("id"),
						ob->query("name"), ob->query("id")
					), me, ({ ob->query("id") })
				);
				destruct(ob);
				write("�û�"+arg1+"���������������\n");
			}
        	}
		notes = notes[0..num-1] + notes[num+1..<1];
		save();
		write("��"+ (num+1) + "�������Ѿ�ɾ����\n");
		return 1;
	}

	if (sscanf(arg, "-r %d %s", num, arg2)== 2) {
		if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
			return notify_fail("û�������ŵ����ݡ�\n");
		if( notes[num-1]["result"] && notes[num-1]["unblock"] )
			return notify_fail("�������Ѿ����˴������ˡ�\n");
		arg1=notes[num-1]["player"];
        ob = LOGIN_D->find_body(arg1);
        if(!ob){
			ob = new(LOGIN_OB);
			ob->set("id",arg1);
			if( !ob->restore() ) {
				destruct(ob);
			}
			else {
				log_file("static/seeklist",
					sprintf("%s(%s)���봫�������Ϲ���%s(%s)�Ĵ�������\n",
						me->query("name"), me->query("id"),
						ob->query("name"), ob->query("id")
					), me, ({ ob->query("id") })
				);
				ob->save();
				destruct(ob);
			}
        }
		notes[num-1]["unblock"]=me->query("id");
		notes[num-1]["result"]=arg2;
		save();
		write("��"+ (num) + "�������޸���ϡ�\n");
		return 1;
	}

	if (sscanf(arg, "-dr %d", num)== 1) {
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
				log_file("static/seeklist",
					sprintf("%s(%s)ɾ�����������Ϲ���%s(%s)�Ĵ�������\n",
						me->query("name"), me->query("id"),
						ob->query("name"), ob->query("id")
					), me, ({ ob->query("id") })
				);
				ob->save();
				destruct(ob);
			}
        }
		notes[num-1]["unblock"]=NULL;
		notes[num-1]["result"]=NULL;
		save();
		write("��"+ (num) + "�������޸���ϡ�\n");
		return 1;
	}

	write("�﷨������help seek��\n");
	return 1;
}

string query_save_file()
{
	return SEEK_FILE ;
}

void list_seeklist(object me, int num)
{
	int i;
	string str;

	i = sizeof(notes);
	if( i < 1 ) write("��������Ŀǰû���κ����ݡ�\n");
	else {
		str="����������\n";
		str += repeat_string("-", 80) + "\n";
		while (i-- && (i>=sizeof(notes)-num || num==0)) {
			str += sprintf("%3d %s %-9s %-=22s %s %s \n",
				i+1,
				ctime(notes[i]["time"])[4..15],
				notes[i]["player"],
				notes[i]["reason"],
				notes[i]["result"] && notes[i]["unblock"]?
					("�����"+notes[i]["result"]+
						(wizardp(me)?
							("��"+notes[i]["unblock"]+"����")
							:"")
						)
					:"����",
				wizardp(me)?notes[i]["block"]:"",
			);
			str += repeat_string("-", 80) + "\n";
		}
	}
	me->start_more( str );
}

int help(object me)
{
        write(@HELP
ָ���ʽ :
seek [all]                 �鿴�������������ݺʹ�����
seek <id> because <ԭ��>   ��������봫���������Ⱥ�֪ͨ
seek -d <����>             ɾ��ָ����ŵĴ�������
seek -r <����> <����>      �ǼǴ���������ָ����ŵ��¼��Ĵ�����
seek -dr <����>            ɾ��ָ����ŵĴ��������Ĵ�����

��ʦ����Ҫ������������漰����ҵǼ��봫��������
������ҵ�¼��ʱ��ϵͳ�ͻ�������ʦ���д���

HELP);
        return 1;
}
