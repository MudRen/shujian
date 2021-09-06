// /d/putian/liangt.c
// lklv 2001.7.21

inherit ROOM;
int do_sit(string arg);
int do_stand();
void delete_served(object me);

void create()
{
        set("short", "��ͤ");
        set("long", @LONG
���ǰ�ɽ����һ��С��ͤ���������һ�Ű�ɫ��ʯͷ��(table)����Χ��ɢ
���������ʯͷ��(chair)���м�����װ��������ˣ�������������Ϣ������
һ��С�����������Ų��վ��һ�ԡ�
LONG
        );

        set("exits", ([
                "out" : __DIR__"road07",
        ]));

        set("item_desc", ([
                "table" : "һ��ʯͷ����������ż�������롣\n",
                "chair" : "һ��ʯͷ�ʣ�������΢��Щ����\n",
        ]));
        set("objects", ([
                __DIR__"npc/shami" : 1,
        ]));
        set("outdoors", "����");
        set("no_fight", 1);
        setup();
}

void init()
{
        add_action("do_stand", "stand");
        add_action("do_stand", "zhan");
        add_action("do_sit", "sit");
        add_action("do_sit", "zuo");
}

int serve_tea(object me)
{
        object ob;

        if (!present(me, this_object())) return 0;
        if (objectp(ob = present("xiao shami", environment(me)))){
                message_vision("Сɳ���߹�������$N����һ���衣\n", me);
                new("/d/thd/obj/huacha.c")->move(environment(me));
                me->set_temp("marks/tea_served", 1);
                call_out("delete_served", 120, me);
        }
        return 1;
}

void delete_served(object me)
{
        if ( objectp(me) ) me->delete_temp("marks/tea_served");
}

int do_sit(string arg)
{
        object me = this_player();

        if (me->is_busy() || me->is_fighting()) return notify_fail("����æ���أ�\n");
        if (arg == "table" || arg == "zhuozi")
                return notify_fail("����Ҫ���������ϣ��Աߵļ������ӵ��۾�һ����˹������㼱æֱ��ֱ����\n");

        if ( !arg || (arg != "chair" && arg != "dengzi") )
                return notify_fail("����Ҫ���ڵ��ϣ�̧ͷ�����Ա�һλ���Ե�Ŀ��ɨ������Ϊ�˲�Ӱ����������ֱ��վ��������\n");

        if (me->query_temp("marks/sit"))
                return notify_fail("���Ѿ�������λ���ˡ�\n");

        message_vision("$N���˸���λ���£������ϲ衣\n", me);
        if( me->query_temp("marks/tea_served") ) {
                message_vision("Сɳ���߹�����$N˵��ʩ�����ȱ��˵ľͳ�ȥ�ɣ����ռ�ŵط���\n", me);
                message_vision("$N�������˵��۹ⶼ�ڶ����Լ���æվ���������ε�˵������ʵ���ڿ���ʯ���ϵ����ϡ�\n", me);
                return notify_fail("");
        }
        me->set_temp("marks/sit", 1);

        call_out("serve_tea", 1, me);
        return 1;
}

int do_stand()
{
        object me = this_player();

        if (!me->query_temp("marks/sit"))
                return notify_fail("���Ѿ�վ���ˣ��ǲ���վ�����е㷢�谡��\n");

        message_vision("$N����ƨ�ɣ�վ��������\n", me);
        me->delete_temp("marks/sit");
        return 1;
}

int valid_leave(object me, string dir)
{
        if (me->query_temp("marks/sit"))
                return notify_fail("�����������Ҳ���ȥ��\n");

        if (dir == "out" && present("moli huacha", me))
                return notify_fail("Сɳ���߹���˵����ʩ�����豭����������ģ������ߡ�\n");

        return ::valid_leave(me, dir);
}
