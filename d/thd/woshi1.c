// Room: /u/jpei/thd/woshi1.c

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
		"west" : __DIR__"neishi1.c",
	]));

	setup();
}


