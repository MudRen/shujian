// Room: /d/jiaxing/yanyu.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"����¥"NOR);
	set("long", @LONG
����¥���ڼ��˵ķ羰ʥ���Ϻ������һ��С���ϣ��������겻�ϵ�ˮ��
�������ֵ��������ɵġ�����������ī�͵��������棬ƾ��Զ�������ͼ��˵�
����ɽɫ��
LONG
	);
	set("group", 1);
	set("exits", ([
		"north" :  "/d/jiaxing/nanhu1",
	]));
	set("objects", ([ 
                "d/jiaxing/npc/yangkang" : 1,
	 ]) );

	set("outdoors", "���˳�");
	setup();
}
