// Room: /u/jpei/thd/road.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
һ���������·��Զ���ƺ��������䡣
LONG
	);
	set("outdoors","ţ�Ҵ�");

	set("exits", ([
		"northwest": "/d/hz/qsddao3.c",
		"south": "/d/group/entry/thdroad1",
	]) );

	setup();
}
