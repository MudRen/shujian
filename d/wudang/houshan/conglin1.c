// Room : /d/wudang/conglin1.c ����
// By lius 99/8

#include <ansi.h>
#include "conglin.h"
inherit ROOM;

void create()
{
        set("short",HIR"�һ����"NOR);
        set("long", @LONG
������һƬ��ɫ�ĺ������ڵش����ֵ���Χ�����صĵ�������ʹ����
����ɽ��㣬�㾪̾��Ȼ֮���棬��֪��������ʧ�˷���
LONG                           
        );

	set("exits", ([               
		"east" : __DIR__"conglin"+(random(4)+1),
		"west" : __DIR__"conglin2",
		"south" : __DIR__"conglin"+(random(4)+1),
		"north" : __DIR__"conglin"+(random(4)+1),
		"northeast" : __DIR__"conglin"+(random(8)+1),
		"northwest" : __DIR__"conglin"+(random(8)+1),
		"southeast" : __DIR__"conglin4",
		"southwest" : __DIR__"conglin"+(random(8)+1),
	]));

	set("outdoors", "�䵱");
	set("objects", ([
		__DIR__"../npc/yetu" : 1, 
		__DIR__"../npc/shanji" : 1, 
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
