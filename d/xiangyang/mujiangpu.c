// Room: /d/xiangyang/mujiangpu.c

inherit ROOM;

void create()
{
	set("short", "木匠铺");
	set("long", @LONG
这是一家简陋的木匠铺，一个中年木匠正蹲在地上钉东西。
LONG
	);
        set("xyjob", 1);
	set("exits", ([
		"west" : __DIR__"ncx4",
	]));

	set("objects", ([
                __DIR__"npc/mujiang" : 1,
	]));
	set("no_clean_up", 0);

	set("incity",1);
	setup();
}
