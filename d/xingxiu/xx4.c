// Room: /d/xingxiu/xx4.c

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
������һ�������޺�������ʯ������᫵�С·�ϣ�·����һȺ���޵�����
�ڳ�Х����������������������������ƺư��﷽Բ�����޺�������������
��֮����ɽ�ڣ�������һ͹���ľ�ʯ(jushi) ��
LONG);
        set("exits", ([
            "west" : __DIR__"xxh1",
            "south" : __DIR__"xxh2",
            "northup" : __DIR__"xx5",
        ]));

        set("item_desc", ([
                "jushi" : "һ���׸ߵĺں�ɫ��ʯ��\n"
        ]));


        set("objects", ([
                __DIR__"npc/tianlang"  : 1,
                __DIR__"npc/xxdizi3" : 1,
        ]));

        set("outdoors", "xingxiuhai");

        setup();
}

void init()
{
        add_action("do_pa", "pa");
}

int do_pa(string arg)
{
        object me;
        mapping myfam;
        me = this_player();
        myfam = (mapping)me->query("family");

        if( !arg || arg=="" ) return 0;

        if( arg=="jushi" )
        {
           if ((!myfam || myfam["family_name"] != "������") && (present("tianlang zi", environment(me)))) 
               return notify_fail("������������������ǰ, �ȵ����������ľͿ������\n");
           if(me->query_skill("dodge") < 100)
               return notify_fail("�������Ͼ�ʯ�������������ϲ�ȥ��\n");       
           message_vision("$N�ܷѾ������Ͼ�ʯ��\n", me);
           message("vision", me->name() + "һת�۱���ʧ��ɽ���ϡ�\n", environment(me), ({me}) );
           me->move(__DIR__"jushi");
           message("vision", me->name() + "��ɽ��������������\n", environment(me), ({me}) );
           return 1;
         }
}
