// Room: /d/meizhuang/huilang.c
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
		"west" : __DIR__"huilang2",
		"east" : __DIR__"huilang3",
		"north" : __DIR__"hall",
	]));
	setup();
}