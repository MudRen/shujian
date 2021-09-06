// Room: /u/swl/songshan/dtlxia.c

inherit ROOM;

void create()
{
        set("short", "������Ͽ");
        set("long", @LONG
����ĵ�·ʮ�����գ����·֮����ȥ������Ͽ֮�Ҿ��ǹ�ʯ����
·���ȴ���������֣��첻���ס��������˵����ľ���
LONG);
        set("exits", ([
            "southdown" : __DIR__"qgping",
            "northup" : __DIR__"xtlxia",
        ]));
        set("objects", ([ 
            CLASS_D("songshan") + "/le" : 1,
            __DIR__"npc/ssdizi" : 1,
        ]));
        set("jingli_cost/northup", 10);
        set("outdoors", "��ɽ");
        set("coor/x",50);
  set("coor/y",200);
   set("coor/z",90);
   setup();
}

void init()
{
        object me = this_player();
        
        if (me->query_temp("ss/zsb_4")
         || me->query_temp("ss/hb_1"))
        {
                add_action("do_tie",({"ji","tie"}));
                add_action("do_down","pa");
                add_action("do_down","climb");
        }
}

int do_tie(string arg)
{
        object me = this_player();
        object ob;
        
        if (!arg || arg != "sheng")
                return notify_fail("��Ҫϵʲô��\n");
        if (!(ob = present("song sheng",me)))
                return notify_fail("�����Ӷ�û����ôϵѽ����\n");

        if (me->query_temp("tie_sheng"))
        {
                message_vision("$N�ֽ�������ʯͷ����ϵ��һ���ᡣ\n",me);
                if (random(3)>1)
                {
                        message_vision("���һ��С�ģ�ûϵ�ã����������ˣ�������Ͽ�ȡ�\n",me);
                        destruct(ob);
                }
                return 1;
        }
        message_vision("$N�������������ʵʵ��ϵ����ʯͷһ���ϡ�\n",me);
        me->set_temp("tie_sheng",1);
        return 1;
}
int do_down(string arg)
{
        object me = this_player();
        
        if (!arg || arg != "down")
                return notify_fail("��Ҫ����������\n");
        if (!present("song sheng",me))
                return notify_fail("������ѽ?��ô��,��ô������ȥ��ȥ�Ҹ���������ȥ�ɣ���\n");
        if (!me->query_temp("tie_sheng"))
                return notify_fail("��������ӣ���������ѽ��\n");

        message_vision("$N���������������һ�̣�˳������������ȥ��\n",me);
        me->delete_temp("tie_sheng");
        me->move(__DIR__"yanbi");
        return 1;
}