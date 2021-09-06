// /d/mr/huandong.c
// this is made by beyond
// update 1997.6.20
// Lklv Modify at 2001.9.21

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",MAG"娘缳玉洞"NOR);
	set ("long",@long
这是曼佗罗山庄存放武功秘籍的地方，一排排书架上整齐的摆放着各种书
籍。一位美丽的姑娘手里拿着本书，坐在书桌前，低头研读着。
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
