// Room: /d/thd/neishi1.c

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
����һ��С���䣬�����ŷ��������ҡ�
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
