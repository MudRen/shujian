// /u/beyond/mr/xiaojing6.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",GRN"С��"NOR);
	set("long",@long
һ�����������ö���ʯ�̳ɵ�С��, ·������������, һ����ɽʯ��ľ��
׺�����С�������ʯ���ϣ�ž�žવķ������������������濴ȥ��һƬ��
���֣�����Ͷ�����С�������졣
long);
	set("outdoors","��٢��ɽׯ");
	set("exits",([
             "east" : __DIR__"xiaojing7",
             "north" : __DIR__"liulin1",
             "west" : __DIR__"xiaojing5",
             "south" : __DIR__"xiaojing8",
	]));
	set("objects",([
		__DIR__"../npc/yahuan" : 2,
	]));
	setup();
}
