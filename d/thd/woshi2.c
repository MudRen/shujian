// Room: /u/jpei/thd/woshi2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�䲼�õú���������ҡ�
LONG
	);
	set("no_clean_up", 0);

	set("exits", ([
		"west" : __DIR__"neishi2.c",
	]));

	setup();
}


