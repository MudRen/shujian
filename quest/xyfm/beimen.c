// Room: /city/beimen.c
// YZC 1995/12/04 
#include <room.h>
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "荒野北门");
	set("long", @LONG
	这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

LONG
	);
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"south" : __DIR__"beidajie2",
                "west" : __DIR__"postoffice",
          "east" : __DIR__"work2",
	]));
	set("outdoors", "city");
	setup();
}

//是镜像
int is_mirror() { return 1; }