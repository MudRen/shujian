// Room: /u/jpei/thd/road2.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
һ���������·�����Ϸ�����һ��СС�Ĵ��䡣
LONG
	);
	set("outdoors","ţ�Ҵ�");

	set("exits", ([
		"northwest": "/d/group/entry/thdroad1",
		"southeast": __DIR__"njwest.c",
	]) );

	setup();
}
