// Room: /d/meizhuang/huilang13.c
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
		"north" : __DIR__"huilang11",
		"west" : __DIR__"huilang15",
		"south" : __DIR__"houtang3",
		]));
	setup();
}