// Room: /tiezhang/zoulang-1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�������ϡ���������ڴ������������������
LONG
	);
	set("exits", ([
		"north" : __DIR__"bqshi",
		"west" : __DIR__"wztang",
		"east" : __DIR__"zoulang-4",
	]));
	setup();
}
