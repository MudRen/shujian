// Room: /d/meizhuang/huilang22.c
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
		"east" : __DIR__"huilang24",
		"south" : __DIR__"huilang20",
		"west" : __DIR__"xiangfang2",
	]));
	setup();
}