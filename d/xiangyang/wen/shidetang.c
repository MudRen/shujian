// Room: shidetang.c
// Lklv Modify 2001.9.21

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���߽�һ��������Ĵ���������һ����ң�д���������֣��������á���
���������������ư廨ƿ����������ǿ�����һ�ɺ����լ�����ɡ�
LONG
	);
	set("objects", ([
		__DIR__"npc/wennanyang": 1,
	]));

	set("exits", ([
                "north": __DIR__"damen",
		"south": __DIR__"tianjing",
		"west":__DIR__"wofang1",
		"east":__DIR__"wofang2",
	]) );

	set("incity",1);
	setup();
}
