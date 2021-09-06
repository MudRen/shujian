// Room: /city/bingyin.c
// YZC 1995/12/04 
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "荒废兵营");
	set("long", @LONG
	这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

LONG
	);
	set("item_desc", ([
		"men" : "这是一扇极厚的铁门。\n",
	]));
	set("exits", ([
		"south" : __DIR__"bingqiku",
		"north" : __DIR__"bingyindamen",
	]));

	create_door("south", "铁门", "north", DOOR_CLOSED);
	setup();
}
//是镜像
int is_mirror() { return 1; }