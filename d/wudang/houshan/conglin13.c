// Room : /d/wudang/conglin13.c ����
// By lius 99/8

#include <ansi.h>
#include "conglin.h"
inherit ROOM;

void create()
{
	set("short",HIG"��Ҷ����"NOR);
	set("long", @LONG
��ͻ����ǰһ�����߽���һƬ���������Ĵ��֣���˵����Ҷ�������ղ�
�࣬ȴ�������������ȸ������Զ��ɽȪ�Ķ��������㾫��Ϊ֮һ��
LONG                           
        );

	set("exits", ([               
		"east" : __DIR__"conglin12",
		"west" : __DIR__"conglin"+(random(12)+5),
		"south" : __DIR__"conglin"+(random(12)+5),
		"north" : __DIR__"conglin"+(random(8)+9),
		"northeast" : __DIR__"conglin14",
		"northwest" : __DIR__"conglin"+(random(8)+9),
		"southeast" : __DIR__"conglin"+(random(8)+9),
		"southwest" : __DIR__"conglin"+(random(8)+9),
	]));

	set("outdoors", "�䵱");

	set("objects", ([
		__DIR__"../npc/bird" : 1, 
		__DIR__"../npc/monkey" : 1,
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
