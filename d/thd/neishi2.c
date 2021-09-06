// Room: /u/jpei/thd/neishi2.c

inherit ROOM;

void create()
{
	set("short", "内室");
	set("long", @LONG
这是一间小房间，连接着厨房和卧室。
LONG
	);
	set("no_clean_up", 0);

	set("exits", ([
		"east" : __DIR__"woshi2.c",
		"west" : __DIR__"chufang.c",
		"south" : __DIR__"neishi1.c",
	]));

	setup();
}


