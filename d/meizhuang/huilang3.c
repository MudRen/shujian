// Room: /d/meizhuang/huilang3.c
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
		"west" : __DIR__"huilang",
		"east" : __DIR__"huilang5",
	]));
	setup();
}