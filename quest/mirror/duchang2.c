// Room: /city/duchang.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "赌场");
	set("long", @LONG
	这里有四条走廊通向不同的房间。
LONG
	);
	set("exits", ([
		"down" : __DIR__"duchang",
	]));
	setup();
}
//是镜像
int is_mirror() { return 1; }