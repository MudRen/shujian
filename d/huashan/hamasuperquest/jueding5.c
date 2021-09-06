

inherit ROOM;
#include <ansi.h>
string *dir=({"up","left","right"});

int     do_next(string arg);
int     do_cry();
void create()
{

                                        
        set("short", HIW"��ɽ����"NOR);
        set("long", @LONG
����һ���˼�������ɽ�����������ﻬ��ɽ���վ�������һ��̤�գ��Ʊ�
������������е��÷������,�ഫ��ɽ�۽����ڴ˴���
LONG
        );

        set("objects", ([
//                "/d/huashan/hamasuperquest/hong2" : 1,
        ]));

        set("outdoors", "huashan");
        set("cost", 5);
        set("no_fight", 1);
        set("no_quit", 1);
        setup();
}
void init()
{
//         add_action("do_next","climb");
        object me = this_player();
        add_action("do_cry","cry");
        me->set("startroom", "/d/city/guangchang");
        add_action("do_quit", "quit");
}
int do_next(string arg)
{
        object me = this_player();
        int cost,dodge;
         object hong = this_object();
        dodge = me->query_skill("dodge",1)/20+1;
        cost = dodge / 2 ;
        cost = random(cost) + 100;
        
        if(me->is_busy())
                return notify_fail("�㻹��æ���ء�\n");

        me->start_busy(2+random(2));
        
        if (!arg)
        {
                tell_object(me,"�������ĸ�������?\n"NOR);

                return 1;

        }
        if (me->query("jingli")<500)
        {
                tell_object(me,HIY"�������͸֧�����˹�ȥ��\n"NOR);
                me->add("jingli",-500);
                return 1;
        }
        
        if (arg == "down")
        {
                message_vision("$NС�������������ȥ��\n"NOR,me);
                me->move("/d/huashan/sheshen");
                me->add("jingli",-cost);
                 destruct(hong);
        }
        else
        {
                tell_object(me,"�������������\n");
                
        }
        
        
        return 1;
}

int do_cry()
{

        command("cry");
        

}

int do_quit()
{
        write("���ﲻ׼�˳���\n");
        return 1;
}

