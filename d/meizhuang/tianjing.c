// Room: /d/meizhuang/tianjing.c
// By Lklv

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�쾮");
	set("long", @LONG
����ׯ�ڵ�һ�����쾮���쾮�����Ҹ�ֲ��һ����÷����֦����������
�ǲԾ���������һ�����ã����쾮���淽�����ׯ�š�
LONG
	);
	set("outdoors","÷ׯ");

	set("exits", ([
		"east" : __DIR__"huilang25",
		"west" : __DIR__"huilang24",
		"south" : __DIR__"hall",
		"north" : __DIR__"door",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir != "south" && me->query_temp("mz_quest/flag")==3
	&& (objectp(present("ding jian", environment(me)))
	|| objectp(present("shi lingwei", environment(me))) )){
		return notify_fail(CYN"�����������������ǰ������" + RANK_D->query_respect(me) + "�����������Ҷ��˽�ׯ�ա���\n"NOR);
	}
	if (dir == "south" && me->query_temp("mz_quest/go")==1)
		me->set_temp("mz_quest/go",2);

        return ::valid_leave(me, dir);
}