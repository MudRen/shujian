// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/zhubaohang.c

inherit ROOM;

void create()
{
        set("short", "�鱦��");
        set("long", @LONG
����һ��װ�κ������鱦�ꡣ��ⱦ�����䣬ѣ������Щ�������۾�����
�µĳ����г����Ÿ��������鱦������������ӳ�ý�̻Ի͡���������ģ����
�����ڵ�ͷ��ϸ�������ţ��ϰ��ڲ����䷳�������š�
LONG
        );

        set("exits", ([
                "north" : __DIR__"westjie1",
        ]));

        set("objects", ([
                __DIR__"npc/zhubaoshang" : 1,
        ]));

        set("incity",1);
	setup();
}