// /d/mr/hffang.c
// update 1997.6.20 by beyond

#include <room.h>
inherit ROOM;
void create()
{
         set("short","���ʷ�");
         set ("long",@long
ʯ�ݺڶ�����, ֻ��һ���˱�����һ����������, ���������˶���, ����
������, ȴ˵�����������ٿ�����ʱ, ֻ��һ��������������������������һ
��ѩ���ĳ���, ����һ����ˮ, ���ֱð������
long);
	set("exits",([
		"east" : __DIR__"hhyuan",
		"west" : __DIR__"cl3-3",
	]));
	set("objects",([
		__DIR__"../npc/yan" : 1,
		__DIR__"../npc/tang" : 1,
	]));
	setup();
}
