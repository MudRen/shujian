// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/westjie1.c

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ���������ͷ���졣������������ͨ����⡣��
�����ǳ����ĵ���¥���ϱ���һ�Ҹ����ûʵ��鱦�꣬������ȥ�Ķ�����ͷ��
���ĸ��̡����߸߸������Ľ������ǳ����ǵĹ�¥��
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"   : __DIR__"zhonglou",
                "south"  : __DIR__"zhubaohang",
                "west"   : __DIR__"westjie2",
                "north"  : __DIR__"gulou",
        ]));

        set("incity",1);
	setup();
}