// Write By Yanyang@SJ 2001.9.28
// ROOM : /d/changan/bingying2.c

inherit ROOM;

void create()
{
        set("short", "��Ӫ");
        set("long", @LONG
������ǳ����ǵı�Ӫ�ˡ������������鵽�����ǹٱ����е����佫��ָ
���½��в������еĶ��������������е����š�����������Ϣ��
LONG
        );

        set("exits", ([
                "north" : __DIR__"bingying",
        ]));

        set("objects", ([
        __DIR__"npc/bing" : 4,
        __DIR__"npc/wujiang" : 2,
        ]));

        set("incity",1);
	setup();
}
