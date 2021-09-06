// Room: /u/swl/songshan/qgfeng.c

inherit ROOM;

void create()
{
        set("short", "��ڷ�");
        set("long", @LONG
�ٲ����ѽ�����ʧ����ȴ��ɫ��ؿ�������࣬��·���ԣ�������
�֣������ߴ����ͦ��·Ҳƽ̹�˺ܶࡣ
LONG);
        set("exits", ([ 
            "southdown" : __DIR__"shanlu3",
            "northup" : __DIR__"qgping",
        ]));
        set("item_desc",([
                "����" : "һ�ÿøߴ��ͦ��������֦��Ҷï����Щ��֦�͵ļ������ֿɴ���\n",
                "����" : "һ�ÿøߴ��ͦ��������֦��Ҷï����Щ��֦�͵ļ������ֿɴ���\n",
                "tree" : "һ�ÿøߴ��ͦ��������֦��Ҷï����Щ��֦�͵ļ������ֿɴ���\n",
        ]));
        set("objects", ([ 
            CLASS_D("songshan") + "/di" : 1,
            __DIR__"npc/ssdizi" : 1,
        ]));
        set("outdoors", "��ɽ");
        set("shuzhi",4);
        set("coor/x",50);
  set("coor/y",180);
   set("coor/z",70);
   setup();
}

void init()
{
        object me = this_player();
        
    if (me->query_temp("ss/zsb_3")
     || me->query_temp("ss/zsb_4")
     || me->query_temp("ss/hb_1"))
        add_action("do_zhe","zhe");
}


void reset_shuzhi()
{
        set("shuzhi", 4);
        delete("shuzhi_call_out");
}


int do_zhe(string arg)
{
        object me = this_player();
        
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���أ�\n");
/*
        if (me->query_temp("shuzhi")==1)
                return notify_fail("���Ѿ��۹��ˣ������ۣ�\n");
*/
        if (arg == "shuzhi")
        {
            if (query("shuzhi")) 
                {
                        message_vision("$N�Ż����ŵ�������������������һ����֦��\n", me);
                        add("shuzhi", -1);
                        if (query("shuzhi") <0)
                                set("shuzhi",0);
                        new(__DIR__"obj/shuzhi")->move(me);
                        me->start_busy(1);
                        me->set_temp("shuzhi",1);
                        return 1;
                }
                else
                {
                        if (!query("shuzhi_call_out"))
                        {
                                remove_call_out("reset_shuzhi");
                                set("shuzhi_call_out", 1);
                                call_out("reset_shuzhi", 500);
                        }
                        return notify_fail("�����Ѿ���ͺͺ���ˣ��㻹����ʲô��\n");
                }
        }
        return 0;
}
