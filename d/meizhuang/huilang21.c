// Room: /d/meizhuang/huilang21.c
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
		"north" : __DIR__"huilang23",
		"west" : __DIR__"ceting3",
		"south" : __DIR__"huilang5",
	]));
	setup();
}