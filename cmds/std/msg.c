// msg.c
// Created by mxzhao 2003/11/21

// ����Ϣ������ݽṹ
/******************************************************
sets
([
	"send_max":5,   // ����ͬʱ���͵�����û���
	"cmd_level":0,  // ����ʹ�����ָ����û��ȼ�
	"set_level": 4, // ���Ը������õ��û��ȼ�
	"wiz_count":20, // wiz����������
	"vip_count":15, // vip�û�����������
	"std_count":10, // ��ͨ�û�����������
])

users 
([ 
	"mxzhao": 
	([ 
		"cur_id":"",
		"msg_id":
		([ 
			"978594457mxzhao":
			([
				"isread":1,	
				"islock":1, 
			]),
			...
		]), 
	]),
	...
])

messages 
([
	"978594457mxzhao":
	([
		"title":"TEST",
		"text":"TEST TEXT",
		"time":978594457,
		"sender":(["id":"mxzhao","name":"����"]),
		"addressee": 
		([
			"mxzhao", ...
		]),
	]),
	...
])
*********************************************************/
// ���� mxzhao Ϊ�û�ID��978594457mxzhao��ϢID




#define MESSAGE_FILE	DATA_DIR + "msg"
#define MESSAGE_HEAD	HIC +"��"+ CHINESE_MUD_NAME + "����Ϣϵͳ����"NOR
#define MESSAGE_LINE	HIY+"�ԡ���������������������������������������������������������������������������������������\n"+NOR 
#define MAX_VALUE		20
#define MIN_VALUE		0

inherit F_SAVE;
inherit F_CLEAN_UP;

#include <ansi.h>
#include <mudlib.h>

string query_save_file();

private string make_result(string str);
private void write_result(string str);
private int load_message();
private string show_sets(object me);
private void start_send(string title, object me, mapping msg);
private void end_send(object me, mapping msg, string text);
private int save_message(object me, mapping msg);
private string make_title(mapping msg_id, mapping msg, int row);
private int do_clear_msg(string msg_id);
private int do_clear_user(string name);
private varargs int delete_user_all(object me, string name, int flag); 
private string make_statistic(object me);

int do_statistic(object me);			// ������LOGIN_D�е���
int do_send(object me, string arg);
varargs int do_read(object me, string arg, int flag);
int do_discard(object me, string arg);
int do_lock(object me, string arg, int lock);
int do_show(object me, string arg);
int do_clear(object me, string arg);	// ����û������ж���Ϣ��������purge��suicide�Ⱥ����е���
int do_set(object me, string arg);
int help(object me);

mapping sets;		// һЩ����Ϣ������
mapping users;		// ����Ϣ�û���Ϣ
mapping messages;	// ����Ϣ

// override query_save_file() 
// �� F_SAVE ��ʹ��
string query_save_file()
{
	return MESSAGE_FILE;
}

// ���ַ������� MESSAGE_HEAD
private string make_result(string str)
{
	return MESSAGE_HEAD + HIC + str + NOR;
}

// ��ʾ��Ϣ
private void write_result(string str)
{
	write(make_result(str) + "\n");
}

// �������Ϣ��Ϣ�����û�������Ϣ���趨��ʼֵ
private int load_message()
{
	if ( !mapp(messages) || !mapp(users) || !mapp(sets) )
	{
		restore();

		write_result("����ɹ���");
	}
	
	if( !mapp(sets) || sizeof(sets) == 0 )
	{
		sets = ([ "send_max":5, 
			"cmd_level":0,	
			"set_level": 4, 
			"wiz_count":20,	
			"vip_count":15, 
			"std_count":10 ]);
	}

	if( !mapp(users) || sizeof(users) == 0 )
	{
		users = ([]);
	}

	if( !mapp(messages) || sizeof(messages) == 0 )
	{
		messages = ([]);
	}

	return 0;
}

// ��������sets������
private string show_sets(object me)
{
	string str = "";
	string *keys = sort_array(keys(sets), 1);

	foreach (string key in keys)
	{
		str += sprintf("	%-15s:%5d\n", key, sets[key]);
	}

	return str;
}

// ���Ͷ���Ϣ
int do_send(object me, string arg)
{
	string file;
	object ob;
	mapping msg = ([ ]);
	
	string *names = explode(arg, ":");

	msg["addressee"] = ({ });
	
	if (!wizardp(me) && sizeof(names) >  sets["send_max"] )
	{
		write_result("�������ͬʱ��" + chinese_number(sets["send_max"]) + "λ�û����Ͷ���Ϣ��");
		return 1;
	}

	foreach (string name in names )
	{
		if ( me->query("id") == name )
		{
			write_result("�㲻�ܸ��Լ����Ͷ���Ϣ��");
			return 1;
		}
		
		file = DATA_DIR + "login/"+ name[0..0] +"/"+ name;
		
		ob = LOGIN_D->find_body(name);
		
		if( ob && me->visible(ob) ) 
		{
			write_result(ob->name() + "(" + capitalize(name) + ")���������У��㻹��ʹ�� Tell ָ�������Щ��");
			return 1;
		} 
		else if( file_size(file + ".ppp") > 0 )
		{
			write_result(capitalize(name) + "�Ѿ���ɾ���ˡ�");
			return 1;
		}
		else if( file_size(file +__SAVE_EXTENSION__) < 0 )
		{
			write_result("û��" + capitalize(name) + "��λ�û���");
			return 1;
		}

		{
			int msg_count = 0;
			
			if(getuid(me)==ROOT_UID)			
				msg_count = 9999;//hehe by ciwei				
			else if (wiz_level(name) > 0)
			{
				msg_count = sets["wiz_count"];
			}
			else if (me->query("registered")==3)
			{
				msg_count = sets["vip_count"];
			}
			else
			{
				msg_count = sets["std_count"];
			}
			
			if ( mapp(users[name]) && sizeof(users[name]["msg_id"]) >= msg_count )
			{
				write_result( capitalize(name) + "������������" );
				return 1;
			}
		}

		msg["addressee"] += ({ name });
	}
	
	msg["sender"] = ([ "id":me->query("id"), "name":me->query("name") ]);
		
	write(HIG +"��������Ҫ���Ͷ���Ϣ�ı���(40���ַ�����)��"+NOR);
	input_to("start_send", me, msg);
	
	return 0;
}

//ϵͳ��player ����msg
public void system_send(object me,string* geters,string title,string text)
{
	mapping msg =([]);
	if(!me || getuid(me)!=ROOT_UID) return;
	if(!arrayp(geters) || !stringp(title) || !stringp(text)) return;
	msg["addressee"] = geters;
	msg["sender"] = ([ "id":"System", "name":"ϵͳ" ]);
	msg["title"] = title;
	msg["text"] = text;
	save_message(me, msg);		
}

// ��������ı���(40�ַ�����)����ʼ���뱾�ġ�
private void start_send(string title, object me, mapping msg)
{
	if ( strlen(title) > 40 )
	{
		title = title[0..39];
	}
	write(HIG+"��������Ҫ���͵Ķ���Ϣ�����ݣ����ܴ��� 500 �֣���\n" + NOR);
	msg["title"] = title;

	me->edit( (: end_send, me, msg :) );
}

// �������룬����
private void end_send(object me, mapping msg, string text)
{
	msg["text"] = text;
	
	if ( sizeof(text) > 500 ){
		write_result("�Բ��������͵Ķ���Ϣ���ݴ����� 500 �֣�\n") ;
		return;
	}
	if (!save_message(me, msg))
	{
		write_result("����Ϣ���ͳɹ���");
	}
}

nosave int seed=0;
private int get_seeds()
{
	seed++;
	return seed;
}
// �洢�¶���Ϣ
private int save_message(object me, mapping msg)
{
	string msg_id;

	if ( load_message() )
	{
		return 1;
	}

	msg["time"] = time();

	msg_id = sprintf("%s%d%s%d",msg["addressee"][0], msg["time"], msg["sender"]["id"],get_seeds() );
	//����ϵͳ����msg ���� ��ϵͳ�п���ͬʱ���id��msg���������һ��msg_id
	//��ǿΨһ��
	messages[msg_id] = msg;

	foreach ( string name in msg["addressee"] )
	{
		mapping user = users[name];

		if ( !mapp(user) || sizeof(user) == 0)
		{
			user = ([ ]);

			user["cur_id"] = 0;
			user["msg_id"] = ([ ]);
		}
		
		user["msg_id"] += ([ msg_id:(["islock":0, "isread":0]) ]);

		users[name] = user;
	}
	
	save();

	return 0;
}

// ���ص� row �ж���Ϣ������ַ���
private string make_title(mapping msg_id, mapping msg, int row)
{
	//		no.) lock title name(id) (time)
	return sprintf("%-2s%s%3d) %-40s %18s (%s)" NOR "\n", msg_id["islock"]?HIR"��"NOR:"", 
		msg_id["isread"]?"":(HIG BRED), row, msg["title"], msg["sender"]["name"] + "(" + 
		capitalize(msg["sender"]["id"]) + ")", ctime(msg["time"])[4..] );
}

// �������Ϣ���ռ���("addressee")Ϊ�գ���ɾ���������Ϣ
private int do_clear_msg(string msg_id)
{
	if ( !mapp(messages[msg_id]) )
	{
		return 0;
	}

	{
		string *addressee = messages[msg_id]["addressee"];
		if ( !arrayp(addressee) || sizeof(addressee) == 0)
		{
			map_delete(messages, msg_id);
			return 1;
		}
	}
	
	return 0;
}

// ����û�������û�ж���Ϣ����ɾ���û�����
private int do_clear_user(string name)
{
	if ( !mapp(users[name]) )
	{
		return 0;
	}

	{
		string *msg_id = users[name]["msg_id"];

		if ( !mapp(msg_id) || sizeof(msg_id) == 0)
		{
			map_delete(users, name);

			return 1;
		}
	}
	
	return 0;
}

// ����û��Ķ���Ϣ
// flag		0��	��ɾ���������Ķ���Ϣ��
//			1��	��ɾ�����ж���Ϣ
private varargs int delete_user_all(object me, string name, int flag)
{
	int count = 0;
	string *msg_ids = sort_array(keys(users[name]["msg_id"]), 1);

	foreach ( string msg_id in msg_ids )
	{
		if ( flag || !users[name]["msg_id"][msg_id]["islock"] )
		{
			map_delete(	users[name]["msg_id"], msg_id );
			messages[msg_id]["addressee"] -= ({ name });
			
			do_clear_msg(msg_id);
			
			count++;
		}
	}
	
	do_clear_user(name);
	
	return count;
}

// �����û�����Ϣ��ͳ����Ϣ��
private string make_statistic(object me)
{
	int total = 0;
	int read = 0;
	int lock = 0;

	string name = me->query("id");

	if (!mapp(users[name]) || sizeof(users[name]) == 0 
		|| !mapp(users[name]["msg_id"]) || sizeof(users[name]["msg_id"]) == 0 )
	{
		return "��Ŀǰû���κζ���Ϣ��";
	}

	total = sizeof(users[name]["msg_id"]);
	
	foreach ( mapping msg_id in keys(users[name]["msg_id"]) )
	{
		if ( users[name]["msg_id"][msg_id]["isread"] )
		{
			read++;
		}
		
		if ( users[name]["msg_id"][msg_id]["islock"] )
		{
			lock++;
		}
	}

	return "��Ŀǰ����" + chinese_number(total) + "������Ϣ������" + 
		chinese_number(total-read) + "��δ����" + chinese_number(lock) + "��������";
}

// ��ʾ�û�����Ϣ��ͳ����Ϣ��
int do_statistic(object me)
{
	if (load_message())
	{
		return 1;
	}

	if ( (string)SECURITY_D->get_status(me) != "(admin)" 
		&& wiz_level(me) < sets["cmd_level"] )
	{
		return 1;
	}

	write_result(HIY + make_statistic(me) + "���� help msg ����鿴����ʹ�÷�����"+NOR);

	return 0;
}

// ��ȡ����Ϣ
varargs int do_read(object me, string arg, int flag)
{
	mapping user;
	mapping msg_id;
	string *msg_ids;
	string str = "";
	string name = me->query("id");

	if (load_message())
	{
		return 1;
	}
	
	user = users[name];

	if (!mapp(user) || sizeof(user) == 0 )
	{
		write_result("��Ŀǰû���κζ���Ϣ��");
		return 1;
	}
	
	msg_id = user["msg_id"];

	if ( !mapp(msg_id) || sizeof(msg_id) == 0 )
	{
		return help(me);
	}
	
	msg_ids = sort_array(keys(msg_id), 1);

	str += make_result("");

	if ( arg == "all" )
	{
		int new_count = 0;

		str += "	" + make_statistic(me) + "\n" + MESSAGE_LINE;

		for ( int i=sizeof(msg_ids); i>0; i-- )
		{
			if ( !flag || !msg_id[msg_ids[i-1]]["isread"] )
			{
				str += make_title(msg_id[msg_ids[i-1]], messages[msg_ids[i-1]], i);

				new_count++;
			}
		}

		if ( flag && new_count == 0 )
		{
			return help(me);
			//write_result("��Ŀǰû���µĶ���Ϣ��");
			//return 1;
		}
	}
	else if ( arg == "new" )
	{
		for ( int i=0; i<sizeof(msg_ids); i++ )
		{
			if ( !users[name]["msg_id"][msg_ids[i]]["isread"] )
			{
				return do_read(me, "" + (i+1));
			}
		}

		write_result("��Ŀǰû���µĶ���Ϣ��");
		return 1;
	}
	else if ( arg == "next" )
	{
		string cur_id = users[name]["cur_id"];
		int i = member_array(cur_id, msg_ids);

		if ( i < 0 )
		{
			i = 0;
		}
		else
		{
			i++;

			if ( i >= sizeof(msg_ids) )
			{
				write_result("û����һ������Ϣ��");
				return 1;
			}
		}

		i++;
		
		return do_read(me, "" + i);
	}
	else
	{
		int num = atoi(arg);
		if ( num <= 0 || num > sizeof(msg_id))
		{
			write_result("û�������ŵĶ���Ϣ��");
			return 1;
		}
		
		{
			mapping msg = messages[msg_ids[num-1]];
			str += "\n" + make_title(msg_id[msg_ids[num-1]], msg, num) 
				+ MESSAGE_LINE + msg["text"];
		}

		users[name]["msg_id"][msg_ids[num-1]]["isread"] = 1;
		users[name]["cur_id"] = msg_ids[num-1];

		save();
	}

	str += MESSAGE_LINE;

	me->start_more(str);
	
	return 0;
}

// ɾ������Ϣ
int do_discard(object me, string arg)
{
	string name = me->query("id");
	int del_count = 0;
	
	if (load_message())
	{
		return 1;
	}
	
	if (!mapp(users[name]) || sizeof(users[name]) == 0 
		|| !mapp(users[name]["msg_id"]) || sizeof(users[name]["msg_id"]) == 0 )
	{
		write_result("��Ŀǰû���κζ���Ϣ��");
		return 1;
	}
	
	if ( arg == "all" )
	{
		del_count = delete_user_all(me, name);
	}
	else
	{
		string *msg_ids = sort_array(keys(users[name]["msg_id"]), 1);

		int num = atoi(arg);
		if ( num <= 0 || num > sizeof(msg_ids))
		{
			write_result("��û�������ŵĶ���Ϣ��");
			return 1;
		}
		
		
		if (users[name]["msg_id"][msg_ids[num-1]]["islock"])
		{
			write_result("�˶���Ϣ�ѱ����������Ƚ��������");
			return 1;
		}

		map_delete(	users[name]["msg_id"], msg_ids[num-1] );
		messages[msg_ids[num-1]]["addressee"] -= ({ name });

		do_clear_msg(msg_ids[num-1]);
		do_clear_user(name);

		del_count++;
	}

	save();

	write_result("��ɾ����" + chinese_number(del_count) + "������Ϣ��");

	return 0;
}

// ����Ϣ����/�������
int do_lock(object me, string arg, int lock)
{
	string name = me->query("id");

	if (load_message())
	{
		return 1;
	}

	if (!mapp(users[name]) || sizeof(users[name]) == 0 
		|| !mapp(users[name]["msg_id"]) || sizeof(users[name]["msg_id"]) == 0 )
	{
		write_result("��Ŀǰû���κζ���Ϣ��");
		return 1;
	}

	{
		string *msg_ids = sort_array(keys(users[name]["msg_id"]), 1);
		int num = atoi(arg);
		if ( num <= 0 || num > sizeof(msg_ids))
		{
			write_result("��û�������ŵĶ���Ϣ��");
			return 1;
		}
	
		if (lock == 0)
		{
			if ( !users[name]["msg_id"][msg_ids[num-1]]["islock"] )
			{
				write_result("�˶���Ϣδ������");
				return 1;
			}

			users[name]["msg_id"][msg_ids[num-1]]["islock"] = 0;
			write_result("��"+chinese_number(num)+"������Ϣ���������");
		}
		else
		{
			if ( users[name]["msg_id"][msg_ids[num-1]]["islock"] )
			{
				write_result("�˶���Ϣ��������");
				return 1;
			}

			users[name]["msg_id"][msg_ids[num-1]]["islock"] = 1;
			write_result("������"+chinese_number(num)+"������Ϣ��");
		}
	}
	
	save();
	
	return 0;
}

// ��ʾ����Ϣϵͳ��ͳ����Ϣ
int do_show(object me, string arg)
{
	if ( !wizardp(me) )
	{
		return help(me);
	}

	if (arg == "users")
	{
		string str = "";

		str += make_result("����" + sizeof(users) + "λ�û���" + sizeof(messages) + "������Ϣ��\n");

		str += sprintf("        %-10s %10s\n", "�û�", "��Ϣ��");
		str += MESSAGE_LINE;

		{
			int i = 1;
			foreach (string name in sort_array(keys(users), 1))
			{
				str += sprintf("%4d    %-10s %10d\n", i++, name, sizeof(users[name]["msg_id"]));
			}
		}
		
		str += MESSAGE_LINE;

		me->start_more(str);
	}
	else
	{
		return help(me);
	}

	return 0;
}

// ����û������ж���Ϣ
int do_clear(object me, string arg)
{
	if (!wizardp(me) )
	{
		return help(me);
	}

	if (wiz_level(me) < wiz_level(arg))
	{
		write_result("��û��ɾ������û�����Ϣ��Ȩ�ޡ�");
		return 1;
	}

	delete_user_all(me, arg, 1);

	save();

	write_result("������û�" + capitalize(arg) + "�����ж���Ϣ��");

	return 0;
}

// ���ö���Ϣϵͳ����
int do_set(object me, string arg)
{
	int value;

	if ( !wizardp(me) )
	{
		return help(me);
	}

	if ( arg == "all" )
	{
		write_result("����ֵ\n\n" + show_sets(me));

		return 1;
	}

	if ( !arg || sscanf(arg, "%s %d", arg, value) != 2 )
	{
		return help(me);
	}

	if ( (string)SECURITY_D->get_status(me) < "(arch)" 
		&& wiz_level(me) < sets["cmd_leve"] )
	{
		write_result("��û�ж���Ϣ�趨Ȩ�ޡ�");
		return 1;
	}

	if ( member_array(arg, keys(sets)) < 0 )
	{
		write_result("û�д������");
		return 1;
	}

	if (value < MIN_VALUE || value > MAX_VALUE)
	{
		write_result("��ֻ������Ϊ" + MIN_VALUE + "��" + MAX_VALUE + "�ڵ�������");
	}

	sets[arg] = value;

	save();

	write_result("����" + arg + "����Ϊ" + value + "��");

	return 0;
}

void create()
{
	seteuid(getuid());

	load_message();

	call_out("create", 900);
}

int main(object me, string arg)
{
	string type;

	if (load_message())
	{
		return 1;
	}

	if ( (string)SECURITY_D->get_status(me) != "(admin)" 
		&& wiz_level(me) < sets["cmd_level"] )
	{
		write_result("�Ѿ��رա�");
		return 1;
	}

	if( !arg )
	{
		do_read(me, "all", 0);
		return 1;
	}

	if ( sscanf(arg, "%s %s", type, arg) != 2 )
	{
		return help(me);
	}

	switch (type)
	{
	case "send":
		do_send(me, arg);
		break;
	case "read":
		do_read(me, arg);
		break;
	case "discard":
		do_discard(me, arg);
		break;
	case "lock":
		do_lock(me, arg, 1);
		break;
	case "unlock":
		do_lock(me, arg, 0);
		break;
	case "show":
		do_show(me, arg);
		break;
	case "clear":
		do_clear(me, arg);		// ������ʹ�á�
		break;
	case "set":
		do_set(me, arg);
		break;
	default:
		return help(me);
		break;
	}

	return 1;
}

int help(object me)
{
	string help = @HELP

ָ��˵�� : 
	���ָ����Է��ͻ������Ķ���Ϣ��
	���͵Ķ���Ϣ��ʹ�����������Ҳ�����յ���

ָ���ʽ : 
	msg <send [id1[:id2[...]]]>            ���Ͷ���Ϣ��һ��������ҡ�
	msg <read [all | new | next |���]>    ��ȡ����Ϣ��
	msg <discard [all | ���]>             ɾ��һ����������Ϣ��
	msg <lock/unlock> <���>               ������������ָ������Ϣ����Ҫɾ��
	                                       ��������Ϣ���Ƚ��������
		
	���� msg read all �и�����ʾ��Ϊ����Ϣ�����ǰ����ɫ����ŵ�Ϊ����������Ϣ��
HELP;

	if ( wizardp(me) )
	{
		help +=@HELP

	msg set <all | Settings <Value> >      �鿴����Ķ���Ϣ���á�

	Settings ����ʹ�� msg set all �鿴��
HELP;

		help += "\n" + show_sets(me);
		help += "\n	Value ����ȡֵ" + MIN_VALUE + "��" + MAX_VALUE + "��";
	}

	help += "\n
	Copyright 1997-2003 ShuJian MUD Wizard Group.
	All rights reserved.
	
	Visit our Homepage at - www.mymud.com \n";

	write(help);

	return 1;
}

