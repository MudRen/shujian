// Room: /d/meizhuang/huilang4.c
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
		"west" : __DIR__"jiushi",
		"east" : __DIR__"huilang2",
		"south" : __DIR__"huilang6",
		"north" : __DIR__"huilang20",
	]));
	setup();
}