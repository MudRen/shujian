// Room: /d/thd/neishi1.c

inherit ROOM;
void create()
{
	set("short", "内室");
	set("long", @LONG
这是一间小房间，连接着饭厅和卧室。
LONG
	);
	set("no_clean_up", 0);

	set("exits", ([
		"east" : __DIR__"woshi1.c",
		"west" : __DIR__"fanting.c",
		"south" : __DIR__"zoulang2.c",
		"north" : __DIR__"neishi2.c",
	]));

	set("objects", ([
		__DIR__"npc/huangrong.c":1,
	]));

	setup();
	"/clone/board/guiyun_b.c"->foo();
}
