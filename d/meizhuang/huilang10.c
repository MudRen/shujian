// Room: /d/meizhuang/huilang10.c
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
		"east" : __DIR__"huilang8",
		"south" : __DIR__"huilang12",
	]));
	setup();
}