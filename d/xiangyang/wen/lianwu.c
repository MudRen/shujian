// Room: lianwu.c
// Lklv Modify 2001.9.21

inherit ROOM;
void create()
{
	set("short", "���䳡");
	set("long", @LONG
���߽�һ��������Ĵ�������ͨ�˳�Ϊһ�����ӡ��������ߵı�������
�����˸��ֱ��С�
LONG
	);
	set("objects", ([
		__DIR__"npc/wenfangda": 1,
	]));

	set("exits", ([
		"east":__DIR__"tianjing",
	]) );

	set("incity",1);
	setup();
}
