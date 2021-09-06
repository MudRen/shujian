// chufang.c ����
// Lklv 2001.9.10

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ɮ������ի�ĵط����������Ǻܴ󣬵���Ҳ�����ɸ�����ʮ��ͬʱ
�ò͡����������ʮ�������Ӻ���ʮ�������ʣ�����Сɳ����һ���ڸ����ź�
����÷������ϰڼ������裬�����ӵ�һ������Сͭ��(luo) û�Ա��Ŀ�����
һ���ࡣ
LONG
        );

        set("exits", ([
                "south" : __DIR__"celang5",
        ]));

        set("item_desc", ([
                "luo" : "����һ��ͭ�Ƶ�С�࣬��ɮ�����ٻ���ի��Сɳ���õġ�\n",
        ]));

        set("objects",([
                "/d/shaolin/npc/xiao-nan1" : 1
        ]));

        setup();
}

void init()
{

        add_action("do_tap", "qiao");
        add_action("do_tap", "knock");
        add_action("do_zuo", "zuo");
        add_action("do_zuo", "sit");
}

int do_tap(string arg)
{

        object me;
        object shami;
        me = this_player();

        if (!arg || (arg != "luo"))
                return notify_fail("��Ҫ��ʲô��\n");

        if( !objectp(shami = present("xiao shami", environment(me))) )
                return notify_fail("������һ��С�࣬ȴ����û�����㡣\n");

        if( !me->query_temp("marks/sit") )
                return notify_fail("������һ��С�࣬�����ڷ����ڻص�����ͻȻ�о��Լ����޴���\n");

        if( me->query_temp("marks/served")){
                message_vision("Сɳ�ֶ�$N˵��������������������ᣬ��Ҳ��������������ѽ������\n", me);
                return notify_fail("");
        }

        message_vision("$N��������ǰ����������һ�����ϵ�С�࣬Сɳ�ֹ������˸�Ҿ�������к���\n", me);

        shami->serve_food(me) ;
        me->set_temp("marks/served", 1);
        call_out("delete_served", 20, me);
        return 1;
}

void delete_served(object me)
{
        if ( objectp(me) ) me->delete_temp("marks/served");
}

int do_zuo(string arg)
{

        if ( !arg || (arg != "changdeng" && arg != "chair") )
                return notify_fail("��Ҫ��ʲô���棿\n");

        if (this_player()->query_temp("marks/sit"))
                return notify_fail("���Ѿ����˸���λ�ˡ�\n");

        this_player()->set_temp("marks/sit", 1);
                return notify_fail("�����˸���λ���¡�\n");
}

int valid_leave(object me, string dir)
{
        me->delete_temp("marks/sit");
        me->delete_temp("tea_cup");
        return ::valid_leave(me, dir);
}
