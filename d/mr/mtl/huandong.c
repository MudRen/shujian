// /d/mr/huandong.c
// this is made by beyond
// update 1997.6.20
// Lklv Modify at 2001.9.21

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",MAG"������"NOR);
	set ("long",@long
������٢��ɽׯ����书�ؼ��ĵط���һ�������������İڷ��Ÿ�����
����һλ�����Ĺ����������ű��飬��������ǰ����ͷ�ж��š�
long);
	set("exits",([
		"combat" : __DIR__"getexp",
		"gift" : __DIR__"getgift",
                "misc" : __DIR__"getmisc",
                "weapon" : __DIR__"getweapon",
//               "armor" : __DIR__"getarmor",
		"north" : __DIR__"ytyuan",

	]));
	set("objects",([
		__DIR__"../npc/wyy" : 1,
	]));
	set("no_fight", 1);
	set("lingwu", 1);

	setup();
}
