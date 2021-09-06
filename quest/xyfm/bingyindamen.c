// Room: /city/bingyindamen.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "荒废大门");
	set("long", @LONG
	这里不知通向哪里，破败不堪，你走上前，犹豫是否要进去。

LONG
	);
	set("exits", ([
		"south" : __DIR__"bingyin",
		"north" : __DIR__"xidajie1",
	]));

	setup();
}

//是镜像
int is_mirror() { return 1; }