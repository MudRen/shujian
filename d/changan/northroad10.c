// Write By Yanyang@SJ 2001.10.13
// Room: /d/changan/northroad10.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ������ʯ�̳ɵĴ��������һ���³�������ãã��Ұ֮�ϣ��Ǳ���
�ɺ�ľ�̿��Ƶ�ƽ���ݣ�������ǰ�����Ǳ�����ɽ�ˡ�
LONG
	);
	set("outdoors", "ƽ����");

	set("exits", ([
		"northup"  : "/d/hengshan/jinlongxia",
		"east" : "/d/hmy/pingding/road1",
		"south"  : __DIR__"northroad9",
	]));

	setup();
}
