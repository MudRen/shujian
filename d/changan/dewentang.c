// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/dewentang.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����������һ����֡����������һ���ŵ�����������������ط���
һЩ���ᣬ���ڻ������ż��軨���ݲݣ�������䣬�������£�����������Ŀ��
���ﲻ���з�ɧ����ϲ����ʫ�ʣ�����Щ��ǳ�Ĺ����飬�����о�������ǿ��
���塣
LONG
        );
        set("exits", ([
                "east" : __DIR__"southjie2",
        ]));

        set("objects", ([
                __DIR__"npc/tangwende" : 1,
        ]));

        set("incity",1);
	setup();
}
