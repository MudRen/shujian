// /u/beyond/mr/liulin1.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",GRN"������"NOR);
         set("long",@long
����һƬ���̵������֣�һƬ���̵���ɫ����������ȥ֦Ҷïʢ�����ϼ�
ֻС�����������Ľи���ͣ����������΢������ڶ���
long);
	set("outdoors","��٢��ɽׯ");

	set("exits",([
		"west" : __DIR__"liulin",
		"east" : __DIR__"liulin2",
		"north" : __DIR__"liulin3",
		"south" : __DIR__"xiaojing6",
	]));
	setup();
}
