// /d/fuzhou/kezhan.c ��ջ
// By Lklv 2001.9.10

inherit ROOM;

void create()
{
        set("short", "�����ջ");
        set("long", @LONG
�����Ǹ��ݳ������ļ����ջ�����ڵ����⿴�����ܺ�𡣺ܶ��ϱ���
���Ŀ���������Ͷ�ޡ���ջ�ſ��Աߵ�˩��׮��˩�ż�ƥ��һ����Ͳ����
��С�������к����ˡ��������˹�������С����æӭ���������к�����ջ����
��ǽ�Ϲ���һ������(paizi)��
LONG
        );

        set("no_sleep_room",1);
	set("no_fight",1);
        set("item_desc", ([
                "paizi" : "¥����Ϣ������������\n",
        ]));

        set("objects", ([
         	__DIR__"npc/xiaoer" : 1,
        ]));

	set("exits", ([
		"north" : __DIR__"xixiang4",
		"up" : __DIR__"kezhan2",
	]));
        set("incity",1);
        setup();
}

int valid_leave(object me, string dir)
{
        if ((string)me->query_temp("rent_paid")!="�����ջ" && dir == "up" )
                return notify_fail("¥��һ���������������͹٣�����û��Ǯ����\n");
        if ((string)me->query_temp("rent_paid")=="�����ջ" && dir == "north" )
                return notify_fail("С���������͹��Ѿ��������ӣ���ô��ס��������أ����˻���ΪС���ź����أ���\n");
        return ::valid_leave(me, dir);
}
