// Room: /u/jpei/thd/fanting.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ǻ�ҩʦһ���˳Է��ĵط���
LONG
	);
	set("no_clean_up", 0);
	set("resource/water", 1);

	set("exits", ([
		"east" : __DIR__"neishi1.c",
		"north" : __DIR__"chufang.c",
	]));

	setup();
}
