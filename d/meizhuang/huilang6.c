// Room: /d/meizhuang/huilang6.c
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
		"west" : __DIR__"huashi",
		"north" : __DIR__"huilang4",
		"south" : __DIR__"huilang8",
	]));
	setup();
}