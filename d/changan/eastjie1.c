// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/eastjie1.c

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ���������ͷ���졣�����Ƕ�����ͨ����⡣��
�����ǳ����ĵ���¥���ϱ���һ�Ҷĳ�������������¥���з����µ��к�Ů
��ֻһ����������������������������ȥ���ò����֣�
LONG
        );
	set("outdoors", "����");
	set("exits", ([
                "east"   : __DIR__"eastjie2",
                "south"  : __DIR__"duchang",
                "west"   : __DIR__"zhonglou",
                "north"  : __DIR__"wanhonglou",
        ]));
	set("objects", ([
		CLASS_D("gaibang/qnqigai") : 1,
	]));
        set("incity",1);
	setup();
}