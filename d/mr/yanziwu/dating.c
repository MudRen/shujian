// Room: /d/mr/dating.c
// this is made by beyond
// update 1997.6.20
// Update by Lklv 2001.9.21

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIW"����"NOR);
	set ("long",@long
�����Ǵ��������г���򵥣���ʲ���裬�����Ϲ�����������ֻ�������
����Ľ����������¼�������Ľ���϶����˺��𾴡������Ķ������鷿������
��һ�����ң������������Ǻ����ˡ�
long);
	set("exits",([
		"north" : __DIR__"xiaojing2",
		"west" : __DIR__"jushi",
		"south" : __DIR__"houting",
		"east" : __DIR__"shufang",
	]));
	set("objects",([
		__DIR__"../npc/gongye" : 1,
		FOOD_D("cha") : 2,
	]));
	setup();
}
