// Room: /d/meizhuang/huilang23.c
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
		"east" : __DIR__"xiangfang3",
		"west" : __DIR__"huilang25",
		"south" : __DIR__"huilang21",
	]));
	setup();
}