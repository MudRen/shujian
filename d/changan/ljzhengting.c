// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/ljzhengting.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��������Ա��ҵĵ���������������ֹ���������Ŀ��������ͭ�����ߵ���
�����ʡ�����Ӧ�о��У�ֻҪӵ��һ�����͹����һ�����ˡ����˵��ֻ�Ҳ��
����ǽ���ǣ���������һ��̫ʦ�Σ���Ա��ƽʱ���������
LONG
        );
        set("exits", ([
                "east"  : __DIR__"lijia",
                "west"  : __DIR__"ljwoshi",
                "north" : __DIR__"ljyanting",
        ]));

        set("objects", ([
                __DIR__"npc/liyuanwai" : 1,
        ]));

        set("incity",1);
	setup();
}
