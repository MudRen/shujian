// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/minju2.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�������ӿ����������Ѿ��ܾ�û��ס�ˡ�����ʵ��Ŵ������ưܲ�����
��Ŀ��˿��࣬ǽ�ϵ��µ������ǻҳ�����ֻ����������ȥ��Ժ�����Ӳݴ�����
լ��ǽ������̦֩�����ԵüȻ�������ɭ��������һ��ĳ��š�
LONG
        );

        set("exits", ([
                "north" : __DIR__"shiji",
        ]));

        set("objects", ([
                __DIR__"npc/dalaoshu" : 2,
        ]));

        set("incity",1);
	setup();
}