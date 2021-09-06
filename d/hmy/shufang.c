// shufang.c
// Created by Numa 19991022
// Modify By River@SJ 2003.1.9

#include <ansi.h>
inherit ROOM;

mapping *book = ({
	(["name":	"������ҩ",
	  "color":	HIR,
	  "show":	"��ͭɫ",]),
	(["name":	"�ܹ���������",
	  "color":	HIC,
	  "show":	"��ͭɫ",]),
	(["name":	"���ϻ�ͯ",
	  "color":	HIY,
	  "show":	"��ͭɫ",]),
	(["name":	"�����ɵ�",
	  "color":	HIG,
	  "show":	"��ͭɫ",]),
	(["name":	"�ⶾ",
	  "color":	HIM,
	  "show":	"��ͭɫ",]),
});

string do_have();
string do_see();

void create()
{
	set("short", "�鷿");
	set("long", @LONG
����������ͤ���鷿���鰸������ż����顣ǽ������һ����ܣ������
������İڷ���һ��һ�����顣
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"changlang3",
	]));
	set("item_desc",([
		"���":		(: do_have :),
		"shujia":	(: do_have :),
		"�鼮":		(: do_see  :),
		"shuji":	(: do_see  :),
	]));
	setup();
}

void init()
{
	add_action("do_get",({"na", "qu"}));
	add_action("do_fankan",({"fan", "fankan"}));
	add_action("do_open","open");
}
	
string do_have()
{
	object me = this_player();
	
	me->set_temp("shufang/have",1);
	return "һ��ʮ�ֿ�����ܣ�������Ų����鼮��\n";
}

string do_see()
{
	object me = this_player();
	
	if (!me->query_temp("shufang/have"))
		return "��˳�ַ����˼����飬û������ʲô������\n";
	me->delete_temp("shufang/have");
	me->set_temp("shufang/see",1);
	return "����ϸ���˿���Щ�鼮��������һ���屾�ż��ƺ������ۣ������ס��Ҫȡ����������\n";
}

int do_get(string arg)
{
	object me = this_player();
	string tar;
	int i;

	if ( me->query_temp("shufang/getkey"))
		return notify_fail("���Ѿ������Ȿ���в�ͬ�ˣ������о��°ɡ�\n");
	
	if (!me->query_temp("shufang/see"))
		return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if ( me->query_temp("shufang/shu"))
		return notify_fail("���Ѿ�ȡ��һ�����ˣ������ȷ����°ɡ�\n");

	if (!arg || sscanf(arg,"%s %d from %s",arg,i,tar)!=3)
		return notify_fail("��Ҫ������ȡ�ڼ����鰡��\n");

	if (arg != "shu" && arg != "��")
		return notify_fail("��Ҫȡʲô��\n");

	if (i > 5 || i < 1)
		return notify_fail("��Ҫȡ�ڼ����飿\n");

	if (tar != "jia" && arg != "���")
		return notify_fail("�������ȡ��\n");
	
	me->set_temp("shufang/shu",i);
	message_vision("$N�������������" + CHINESE_D->chinese_number(i) + "����������������\n",me);
	return 1;
}

int do_key(object me)
{
	tell_object(me,"��ͻȻ�����Ȿ�ż��ƺ������ͱ����Щ��ͬ��������ʲô���������Ȿ���С�\n");
	me->set_temp("shufang/getkey",1);
}

int do_fankan(string arg)
{
	object me = this_player();
	mapping book_info;
	int i;

	if ( me->query_temp("shufang/getkey"))
		return notify_fail("���Ѿ������Ȿ���в�ͬ�ˣ������о��°ɡ�\n");

	if (!me->query_temp("shufang/shu") && !wizardp(me)) return 0;

	if (!arg)
		return notify_fail("��Ҫ����ʲô��\n");

	if (arg != "shu" && arg != "��")
		return notify_fail("��Ҫ����ʲô��\n");

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	i = me->query_temp("shufang/shu");
	i = random(i) + 1;

        if (i > 5 || i < 1)
        i = 1;        

	book_info = book[i];
	tell_object(me,book_info["color"]+"����һ���������"+ book_info["name"] +"�Ĺż��������"+ book_info["show"] +"����ҳ�Ѿ������Ҳ�ȱ�˼�ҳ��\n"NOR);
	if ( random(5)) {
		me->delete_temp("shufang/shu");
		tell_object(me,"�㷭���˼�ҳ����û��ʲô�ر�֮���������ַ��˻�ȥ��\n");
	}
	else {
		me->delete_temp("shufang/shu");
		do_key(me);
		me->start_busy(1);
	}
	return 1;
}

int do_open(string arg)
{
	object me = this_player();
	object obj, ob;
	
	if (!me->query_temp("shufang/getkey")) return 0;

	if (!arg)
		return notify_fail("��Ҫ��ʲô��\n");

	if (arg != "shu" && arg != "��")
		return notify_fail("��Ҫ��ʲô��\n");
	
	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	tell_object(me,"�����ķ�ҳ������������һ���в㡣\n");
	ob = unew(__DIR__"obj/key");
	if ( !random(3) || !clonep(ob)) {
		if( clonep(ob)) 
			destruct(ob);
		message_vision("$N��Ҫ�����еĹż���ͻȻ��һλ������̳��ϳ��˽�����\n",me);
		me->delete_temp("shufang/getkey");
		obj = new(__DIR__"npc/zhanglao");
		obj->set_temp("target",me->query("id"));
		obj->move(environment(me));
		me->start_busy(random(2));
		return 1;
	}
	message_vision("$N���������йż��ļв㣬ȡ����Կ�ס�\n",me);
	me->delete_temp("shufang");
	ob->set_temp("owner",me->query("id"));
	ob->move(me);
	return 1;
}
