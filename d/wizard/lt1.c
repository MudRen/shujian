#include <ansi.h>

inherit ROOM;
string look_leitai();

void create()
{
	set("short", HIY"������"NOR);
    set("long", "�������齣������ķ����ű�����̨��̨�¼��������Ը��Ÿ��ɵĹ��ڡ�
Χ������̨��(leitai)����̨(info)���������֣��˴��������У������ޱȣ�
����ͨ�����������������俴̨��\n");

	set("no_fight", 1);
	set("no_sleep_room", 1);
	set("sleep_room", 1);
	set("leitai", "/cmds/leitai/leitai1");

	set("exits", ([
		"out" : "/d/xiangyang/guangc",
		"east" : __DIR__"lt1a",
		"west" : __DIR__"lt1b",
		"south" : __DIR__"lt1c",
		"north" : __DIR__"lt1d",
	]));

	set("item_desc",([
		"leitai" : (: look_leitai :),
		"info" : "\n����Ҫ���ޣ������룺dalei\n",
	]));

	set("outdoors", "������̨");
	setup();
}

void init()
{
	object me = this_player();

	if (userp(me) && !wizardp(me))
		add_temp("num", 1);
      add_action("do_biwu", "dalei");
	add_action("do_action", ({"dazuo", "tuna", "lian", "learn", "du", "steal", "hit",
		"kill", "fight", "study", "practice","exercise", "exert"}));
}

#include "leitai_fun.h"
