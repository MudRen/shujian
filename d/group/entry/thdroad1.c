// Room: /u/jpei/thd/road1.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
һ���������·��Զ���ƺ��������䡣
LONG
	);
	set("outdoors","ţ�Ҵ�");

	set("group", 1);
	set("exits", ([
		"north": "/d/thd/niujia/road",
		"southeast": "/d/thd/niujia/road2",
	]) );

	setup();
}
