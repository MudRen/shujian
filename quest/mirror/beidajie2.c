// Room: /d/city/beidajie2.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "城池");
	set("long", @LONG
	山海关的城池，周长约4公里，是一座小城，整个城池与长城相连，以
城为关。城高14米，厚7米。全城有四座主要城门，并有多种古代的防御建筑，是
一座防御体系比较完整的城关。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"beimen",
  "west" : __DIR__"wumiao",
  "south" : __DIR__"beidajie1",
  "east" : __DIR__"zuixianlou",
]));
	set("outdoors", "city");

	setup();
}
//是镜像
int is_mirror() { return 1; }