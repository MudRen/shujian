// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/chm.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����������ʢ������������Ӽ���ƽ����������¡֮�ࡣ����ǰ��һ
���װ����֣���������ĳ��������һλ�ֳ��ʲ���ë�ʵ��й١�һλ��ף
��ǰ�ߺ󣬺ʹ�Ҵ����к���
LONG
        );

        set("exits", ([
                "north"  : __DIR__"westjie4",
        ]));

        set("objects", ([
                __DIR__"npc/miaozhu" : 1,
        ]));

        set("incity",1);
	setup();
}

void init()
{
        add_action("action", ({
                "dazuo",
                "du",
                "exercise",
                "lian",
                "practice",
                "respirate",
                "study",
                "tuna"
        }));
}

int action()
{
        write("���޷���������������\n");
        return 1;
}
