// Write By Yanyang@SJ 2001.10.13
// Room: /d/changan/northroad9.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ������ʯ�̳ɵĴ�����Ϸ���ͨ�������ĳ������ˣ��򱱷��߱��
��������ɽ�ˡ�
LONG
	);
	set("outdoors", "ƽ����");

	set("exits", ([
		"north"  : __DIR__"northroad10",
		"south"  : __DIR__"road3",
	]));

	setup();
}
