// Room: /d/meizhuang/huilang7.c
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
		"east" : __DIR__"shufang",
		"north" : __DIR__"huilang5",
		"south" : __DIR__"huilang9",
	]));
	setup();
}