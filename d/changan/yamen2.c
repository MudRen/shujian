// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/yamen2.c

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
���������ŵ����ã����϶����������ס������һ������������������ϸ
��������ǽ������һ�����ң����顰����������ĸ���������Ĵ��֡�������
�����ְֳ��Ӳ������ԣ������ǵ�֪�������������İ����������顣
LONG
        );

        set("exits", ([
                "south" : __DIR__"yamen",
        ]));
        set("objects", ([
                __DIR__"npc/yayi" : 4,
                __DIR__"npc/zhifu" : 1,
        ]));

        set("incity",1);
	setup();
}
