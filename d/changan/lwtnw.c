// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/lwtnw.c

inherit ROOM;

void create()
{
        set("short", "����̨");
        set("long", @LONG
�سǵ���Ҫ�ڸڡ��м���һ���޴����¯������װ�����Ƿ࣬һ�����һ
��ͭ�ӣ�ÿ���н���������س������ͷ����̡�����Ϊ���������ٱ����Ա���
������������ֵ�ڵĸ�����ϸ�Ĺ۲��ų���Ķ�����
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"  : __DIR__"northchq1",
                "south" : __DIR__"westchq1",
        ]));

        set("objects", ([
        __DIR__"npc/zhqbing" : 2,
        ]));
        
        set("incity",1);
	setup();
}

