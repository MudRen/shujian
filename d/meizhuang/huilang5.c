// Room: /d/meizhuang/huilang5.c
// By Lklv

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ׯ�ڵ�һ�����ȣ����������������ϸ�����ʯ��ͷ���Ǿ����Ļ���
�����������ܵĿյ�������һ���������÷����
LONG
	);

	set("exits", ([
		"west" : __DIR__"huilang3",
		"east" : __DIR__"qishi",
		"south" : __DIR__"huilang7",
		"north" : __DIR__"huilang21",
	]));
	setup();
}