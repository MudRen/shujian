// alarm.c creat by Look@SJ 19990909
// Modified by bbb 19991214
// Modified by snowman 14/12/1999
// Modified by Looklove 2000/8/25
// push in board & bbs  by Ciwei@SJ

#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);
void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg;
	object obj;

	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 )
		return help(me);
	if( strlen(msg) > 40 ) return notify_fail("û��Ҫ����ô���ɣ�\n");
	obj = find_player(target);
	if (!obj) return notify_fail("��Ҫ����˭��������û("+target+")����˰���\n");
	if (geteuid(me) != "yuj") message("wizard", getuid(this_player(1))+"��������\n", users());
	if (obj->query("id") == "yuj" || obj->query("id") == "linux")
		message("system", HIR "�����桿" + me->name(1) + "("+ me->query("id")
		+ ")�����Ҿ�����ʦ������Ϊ����˲���Ӱ�죬����ٷ��������뵽�һ�Դ���͡�\n" NOR,users());
	else{
		mapping note;
		message("system", HIR "�����桿" + obj->name(1) + "("+ capitalize(obj->query("id"))
		+ ")��"+msg+"������Ϊ����˲���Ӱ�죬����ٷ��������뵽�һ�Դ���͡�\n" NOR,users());
		//����������POSTר�����԰�
		//done_post(object me, mapping note, string text)
		//title author
		note = (["title":"�������"+obj->name(1) + "("+ capitalize(obj->query("id"))+")����",
			"author":me->query("name") + "(" + getuid(me) + ")",
			"time":0,
			"msg":0,
			]);					
		"/clone/board/wizto_b"->done_post(this_object(),note,"�����桿" + obj->name(1) + "(" + capitalize(obj->query("id"))
		+ ")��"+msg+"������Ϊ����˲���Ӱ�죬����ٷ��������뵽�һ�Դ���͡�\n");
		/*
		"/clone/board/wizto_b"->auto_post(
		"�������"+obj->name(1) + "("+ capitalize(obj->query("id"))+")����",
		"�����桿" + obj->name(1) + "(" + capitalize(obj->query("id"))
		+ ")��"+msg+"������Ϊ����˲���Ӱ�죬����ٷ��������뵽�һ�Դ���͡�\n");
		*/
	}
        log_file("static/ALARM", sprintf("%s alarm %s because %s.\n",
                        geteuid(this_player(1)), obj->query("id"), msg),
                        this_player(1));

	return 1;
}

string query(string arg)
{
	if(arg=="id") //return now_id;
	return "Wizard";
}

int help(object me)
{
	write(@HELP
ָ���ʽ��alarm <ĳ��> <ѶϢ>
����������ָ���һЩΥ����Ϸ�������ҡ�
HELP
	);
	return 1;
}
