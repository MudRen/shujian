// Room: /d/meizhuang/huilang2.c
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
		"west" : __DIR__"huilang4",
		"east" : __DIR__"huilang",
	]));
	setup();
}