// Room: /d/meizhuang/huilang12.c
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
		"east" : __DIR__"huilang14",
		"north" : __DIR__"huilang10",
		"south" : __DIR__"houtang2",
	]));
	setup();
}