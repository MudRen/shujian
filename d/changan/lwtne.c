// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/lwtne.c

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
                "south" : __DIR__"eastchq1",
                "west"  : __DIR__"northchq6",
        ]));

        set("objects", ([
        __DIR__"npc/zhqbing" : 2,
        ]));
        
        set("incity",1);
	setup();
}

