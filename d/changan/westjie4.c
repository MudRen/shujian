// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/westjie4.c

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ���������ͷ���졣������������ͨ����⡣��
�����ǳ����ĵ���¥�������������£��ϱ����ǳ����������������ƣ�����
��Ů�ǽ�����������Ϊ���֡�
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"   : __DIR__"westjie3",
                "south"  : __DIR__"chm",
                "west"   : __DIR__"westmen",
                "north"  : __DIR__"qingzhensi",
        ]));

        set("incity",1);
	setup();
}