// Room: /d/city/xidajie1.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "小路");
	set("long", @LONG
	这里是一处古战场的遗迹，如今荒乱不堪野草丛生，传言有僵尸出没，害人性命。

LONG
	);
	set("outdoors", "city");

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"xidajie2",
  "north" : __DIR__"yamen",
  "south" : __DIR__"bingyindamen",
  "east" : __DIR__"guangchang",
]));

	setup();
}
//是镜像
int is_mirror() { return 1; }