// Room : /d/wudang/conglin9.c ����
// By lius 99/8

#include <ansi.h>
#include "conglin.h"
inherit ROOM;

void create()
{
	set("short",HIW"��ѩ����"NOR);
	set("long", @LONG
����Խ��Խ�ߣ�����Խת���䣬·�ϡ����϶��������Ļ�ѩ���н�Խ��
Խ���ѣ���֮Ұ�޵�Ϯ������ֻ���������뿪��Ƭ���֡�
LONG                           
        );

	set("exits", ([               
		"east" : __DIR__"conglin"+(random(4)+5),
		"west" : __DIR__"conglin8",
		"south" : __DIR__"conglin"+(random(4)+5),
		"north" : __DIR__"conglin"+(random(12)+5),
		"northeast" : __DIR__"conglin"+(random(12)+5),
		"northwest" : __DIR__"conglin"+(random(12)+5),
		"southeast" : __DIR__"conglin10",
		"southwest" : __DIR__"conglin"+(random(12)+5),
	]));

	set("outdoors", "�䵱");

	set("objects", ([
		__DIR__"../npc/xiong" : 1, 
		__DIR__"../npc/bao" : 1,
	]));
	set("caiyao_room", 1);

	setup();
}

void reset()
{
	::reset();
	set("caiyao_room", 1);
}

void init()
{
	add_action("do_zhao", ({"zhao","find"}));
}

int valid_leave(object me, string dir)
{
	me->add_busy(2);
	me->add("jingli",-30);
	return ::valid_leave(me,dir);
}
