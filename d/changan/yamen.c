// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/yamen.c

inherit ROOM;

void create()
{
        set("short", "���Ŵ���");
        set("long", @LONG
�����ǳ����ǵ����Ŵ��ţ�������ľ���Ž����ر��š��ſڷ���������ͭ
ʨ�����ྲ�����رܡ������ӷַ������ԡ�ǰ����һ����ģ���Ȼ�ǹ�С����
ԩ�õġ�������������ǰѲ�ߡ�
LONG
        );

        set("exits", ([
                "south" : __DIR__"westjie2",
                "north" : __DIR__"yamen2",
        ]));

        set("objects", ([
                __DIR__"npc/yayi" : 2,
        ]));

        set("incity",1);
        setup();
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("ya yi", environment(me))) && dir == "north"){
                if( me->query_condition("killer"))
                        return notify_fail("���ۺȵ���������˭������뿪�����\n");
                else
                        return notify_fail("���ۺȵ������������䡭������\n");
        }
        return ::valid_leave(me, dir);
}