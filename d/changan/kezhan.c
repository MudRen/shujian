// Write By Yanyang@SJ 2001.9.27
// Room: /d/changan/kezhan.c

inherit ROOM;

void create()
{
        set("short", "�ۺ���ջ");
        set("long", @LONG       
���ǳ�������ľۺ���ջ���ϰ��ǳ��е��׸���Ա�⣬�ֶ���ľ�¥Ҳ��
�����ġ�����οʹ��ѡ��������ţ�����������ǰ����ﵱ�ɾۻ���ͷ�ĳ�
������ʱ�н������ͽ�����������С����������æ������ת���Ӵ�����ǻ����
�Ŀ��ˡ���ջ�����ǽ�Ϲ���һ����Ŀ������(paizi)��
LONG
        );

        set("valid_startroom", 1);
        set("no_sleep_room",1);
        set("no_fight",1);
        set("item_desc", ([
                "paizi" : "¥���ŷ���ÿҹ����������\n",
        ]));

        set("objects", ([
             __DIR__"npc/xiaoer" : 1,
        ]));

        set("exits", ([
            "east" : __DIR__"northjie1",
              "up" : __DIR__"kezhan2",
        ]));

        set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{

        if ( !me->query_temp("rent_paid") && dir == "up" )
                return notify_fail("��ô�ţ����ס����\n");

        if ( me->query_temp("rent_paid") && dir == "east" )
                return notify_fail("�͹��Ѿ��������ӣ���ô��ס��������أ����˻���ΪС���ź����أ�\n");

        return ::valid_leave(me, dir);
}
