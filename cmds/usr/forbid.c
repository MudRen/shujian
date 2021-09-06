// Forbid.c ��ͣ�ʺ�
// ��ֹ��Ұ���Ҫ��ʱ���½��


#include <ansi.h>
#include <login.h>

#define FORBID_FILE       "/data/forbidlist"

inherit ITEM;
inherit F_SAVE;
mapping *notes;

int help(object me);
string query_save_file();
void list_forbid(object me, int num);

int is_forbid(string arg)
{
	foreach (mapping item in notes)
		if (arg == item["playerid"]) return 1;
	return 0;
}

string delete_forbid(string arg)
{
	foreach (mapping item in notes)
	{
		if (arg == item["playerid"])
		{
			object ob;
			if( file_size(DATA_DIR + "user/" + arg[0..0] 
				+ "/" + arg + SAVE_EXTENSION)<0 )
			{
				return 0;
			}
			
			ob = new(USER_OB);
			
			ob->set_name("", ({ arg }));
			
			seteuid(arg);
			export_uid(ob);
			seteuid(getuid());
			
			if (!ob->restore())
			{
				destruct(ob);
				return 0;
			}
			
			ob->set_name(ob->query("name"), ({ arg }));

			ob->delete("forbid_time");

			ob->set_temp("db_quit", 1);

			if (!ob->save())
			{
				destruct(ob);
				return 0;
			}

			destruct(ob);
			
			notes -= ({ item });
			save();
			
			return item["player"];
		}
	}
	
	return 0;
}

private int delete_forbid_name(object me, string arg)
{
	string name = delete_forbid(arg);

	if (name)
	{
		tell_object(me, "���" + name + "���ʺŽ�⡣\n");
	}
	else
	{
		tell_object(me, name + "���ʺ�û�з�ͣ��\n");
	}

	return 1;
}

void create()
{
	seteuid(getuid());
	restore();
}

int main(object me, string arg)
{
	mapping note,note2;
	string s,arg1,arg2;
	object ob;
	int day;
	
	if (!arg)
	{
		list_forbid(me, 10);
		return 1;
	}
	
	if (sscanf(arg, "%s", s) == 1 && s == "all" )
	{
		list_forbid(me, 0);
		return 1;
	}

	if (wiz_level(me)<4)
	{
		return notify_fail("ֻ����Ϸ����Ա�ſ��Է�ͣ�ʺš� \n");
	}
		
	if (sscanf(arg, "-d %s", s) == 1 )
	{
		delete_forbid_name(me, s);
		return 1;
	}

	if (sscanf(arg, "%s %d because %s", arg1, day, arg2) != 3)
	{
		return help(me);
	}

	if (day < 0)
	{
		return notify_fail("�ʺŽ���ʱ���������㣬��������㡣\n");
	}

	if (is_forbid(arg1))
	{
		return notify_fail("��ҵ��ʺ��Ѿ���ͣ������Ѿ���⣬����ɾ��������¼�����·�ͣ��\n");
	}
		
	if (strlen(arg2)< 8 || strlen(arg2)>44)
	{
		return notify_fail("�������Ҫ��˵��ԭ������������4-20֮�䡣 \n");
	}
	
	if (objectp(ob = LOGIN_D->find_body(arg1)))
	{
		"/cmds/wiz/kickout"->main(me, arg1);
	}

	if (!objectp(ob = LOGIN_D->find_body(arg1)))
	{
		if( file_size(DATA_DIR + "user/" + arg1[0..0] 
			+ "/" + arg1 + SAVE_EXTENSION)<0 )
		{
			return notify_fail("û����λʹ���ߡ�\n");
		}
		
		ob = new(USER_OB);
		
		ob->set_name("", ({ arg1 }));

		seteuid(arg1);
		export_uid(ob);
		seteuid(getuid());
		
		if (!ob->restore())
		{
			destruct(ob);
			return notify_fail("û�������ҡ�\n");
		}

		ob->set_name(ob->query("name"), ({ arg1 }));
	}

	//if (!(int)ob->query("forbid_time"))
	{			
		int forbid_time = time() + day * 24 * 60 * 60; 
		
		if (ob->set("forbid_time", forbid_time))
		{
			tell_object(me,"��ҷ���ʺ�ʱ�����óɹ���\n");
		}
		else
		{
			return notify_fail("��ҷ���ʺ�ʱ������ʧ�ܣ�����ʺ���Ч������߼���ʦ��ϵ��\n");
		}
		ob->set_temp("db_quit", 1);
		if (ob->save())
		{
			tell_object(me,"��ҷ���ʺ�ʱ�䱣��ɹ���\n");
		}
		else
		{
			return notify_fail("��ҷ���ʺ�ʱ�䱣��ʧ�ܣ�����ʺ���Ч������߼���ʦ��ϵ��\n");
		}
		
		note = allocate_mapping(7);
		note["time"] 	= time();
		note["block"] 	= me->query("id");
		note["player"] 	= ob->query("name") + "(" + capitalize(ob->query("id")) + ")";
		note["playerid"] = ob->query("id");
		note["reason"] 	= arg2;
		note["day"]	= day;
		note["utime"] 	= forbid_time;

		message("channel", HIC "\n�����ɡ�"+ob->query("name")
			+"("+capitalize(ob->query("id"))
			+")��Ϊ��" + arg2 + "�ݣ�Υ���齣��Ϸ���򣬾��������ͣ�ʺ�"
			+ CHINESE_D->chinese_number(day) + "��Ĵ�����\n\n" NOR, users()
			);
			//����������POSTר�����԰�
		
	        note2 = (["title":"ͣ�����"+ob->query("name")+"("+capitalize(ob->query("id"))+")�ʺŵĴ�����",
	        	"author":me->query("name") + "(" + getuid(me) + ")",
	        	"time":0,
	        	"msg":0,]);
		"/clone/board/wizto_b"->done_post(this_object(),note2,"�����ɡ�"+ob->query("name")
			+"("+capitalize(ob->query("id"))
			+")��Ϊ��" + arg2 + "�ݣ�Υ���齣��Ϸ���򣬾��������ͣ�ʺ�"
			+ CHINESE_D->chinese_number(day) + "��Ĵ�����\n");
		/*
		"/clone/board/wizto_b"->auto_post("ͣ�����"+ob->query("name")
		+"("+capitalize(ob->query("id"))
		+")�ʺŵĴ�����","�����ɡ�"+ob->query("name")
			+"("+capitalize(ob->query("id"))
			+")��Ϊ��" + arg2 + "�ݣ�Υ���齣��Ϸ���򣬾��������ͣ�ʺ�"
			+ CHINESE_D->chinese_number(day) + "��Ĵ�����\n");	
		*/
		//save ʧ�� ����log
		log_file( "static/FORBID", me->query("name")+"("+me->query("id")+") �� " +
			arg1 + day + " ���ͣ�ʺŵĳͷ�, ��Ϊ:" + arg2 + "\n" );
	}
	
	destruct(ob);

	if( !pointerp(notes) || !sizeof(notes) )
	{
		notes = ({ note });
	}
	else
	{
		notes += ({ note });
	}
	
	save();

	tell_object(me, "��ɹ��ذ�" + note["player"] + "�����ͣ�ʺ�������\n");
	return 1;
	
}


string query(string arg)
{
        if(arg=="id") return "Wizard";
        return ::query(arg);
}

string query_save_file()
{
	return FORBID_FILE ;
}

void list_forbid(object me, int num)
{
	int i;
	string str;
	
	i = sizeof(notes);

	if( i < 1 )
	{
		write("�齣��ͣ�ʺ�����Ŀǰû���κ����ݡ�\n");
		return;
	}
	
	str="�齣��ͣ�ʺ�������\n";
	str += repeat_string("��", 24) + "\n";

	while (i-- && (i>=sizeof(notes)-num || num==0))
	{
		str += sprintf("��ţ�%d\n��ң�%s\nԭ��"HIG"%s"NOR
			"\nʱ�䣺�� %s �졣%s��\n״̬��%s\nʱ�䣺%s\n",
			i+1,
			notes[i]["player"],
			notes[i]["reason"],
			CHINESE_D->chinese_number(notes[i]["day"]),
			wizardp(me)?("������ʦ:"+notes[i]["block"]):"",				
			( notes[i]["utime"]-time() > 0 )?("��ʣ" + 
			CHINESE_D->chinese_time(notes[i]["utime"]-time())):"�ѵ���",
			CHINESE_D->chinese_date(notes[i]["time"],1)
			);

		str += repeat_string("��", 24) + "\n";
	}
	
	me->start_more( str );
}

int help(object me)
{
	if (!wiz_level(me) )
        write(@HELP
ָ���ʽ :
forbid [all]                 �鿴��ͣ�ʺ����������ݺʹ�����

��ʦ��������Υ���������ҵǼ����ͣ�ʺţ��ڷ�ͣ�ʺ��ڼ䣬�������
�Ž�����ʱ��գ�����������Ϸ��

HELP);
    else 
        write(@HELP
ָ���ʽ :
forbid [all]                       �鿴�����������ݺʹ�����
forbid <id> <day> because <ԭ��>   �����������������Ⱥ���鴦��
forbid -d <id>                     ɾ��ָ����ŵĺ�����

��ʦ��������Υ���������ҵǼ����ͣ�ʺţ��ڷ�ͣ�ʺ��ڼ䣬�������
�Ž�����ʱ��գ�����������Ϸ��
HELP);
        return 1;
}
