// Room: /d/meizhuang/huilang20.c
// By Lklv

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ׯ�ڵ�һ�����ȣ����������������ϸ�����ʯ��ͷ���Ǿ����Ļ���
�����������ܵĿյ�������һ���������÷���ԡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"ceting2",
		"south" : __DIR__"huilang4",
		"north" : __DIR__"huilang22",
	]));
	setup();
}