// Room: peitian-fang.c
// Created by Numa 1999-11-21

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"��������"NOR);
	set("long", @LONG
�����б���λ����ɽ֮�۵ķ���̨������ȥ��ң���ɸ����ţ���
������һ�ߣ��������������������ڣ����������������ص�����ɽ�塣
LONG);
	set("exits", ([
		"southdown" : __DIR__"shidao3",
		"northup" : __DIR__"fengchantai",
	]));
	set("outdoors", "��ɽ");
	setup();
}

void init()
{
	object me = this_player();

	if ( me->query("family/family_name") == "��ɽ��"
	&& me->query("title") == "��ɽ�ɵ��Ĵ�����")
		me->set("title", HIC"���������״�����"NOR);
}
