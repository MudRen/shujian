// Room: /d/shaolin/shanlu1.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��������ɽ������µ�һ��С·��·�Գ�������ݡ������̾͵�С·��
�������������ƺ����˾�����ɨ����Զ����������壬ɽ��ͦ�Σ����㾳��
����������������������΢��������������������������������£������
�������֡�
LONG
	);
	
	set("exits", ([
		"north" : __DIR__"shanlu2",
		"south" : __DIR__"qfdian",
	]));

//	create_door("south","ľ��","north",DOOR_CLOSED);

	set("outdoors", "shaolin");
	set("coor/x",50);
  set("coor/y",440);
   set("coor/z",130);
	setup();
}
/*
void init()
{
	object me = this_player()...
}

*/