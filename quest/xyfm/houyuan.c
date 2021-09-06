// houyuan.c 财主后院
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "后院");
	set("long", @LONG
	这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

LONG
	);
	set("item_desc", ([
		"men" : "这扇门似乎通向一间密室。\n",
	]));
	set("exits", ([
		"south" : __DIR__"dayuan",
		"west" : __DIR__"xixiang",
	]));

	setup();
}
//是镜像
int is_mirror() { return 1; }