// Room: /u/jpei/thd/neishi2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��С���䣬�����ų��������ҡ�
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


