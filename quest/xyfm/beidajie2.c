// Room: /d/city/beidajie2.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "荒丘");
	set("long", @LONG
	这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

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