

inherit ROOM;
#include <ansi.h>
string *dir=({"up","left","right"});

int     do_next(string arg);
void create()
{

                                        
        set("short", HIW"��ɽ֮��"NOR);
        set("long", @LONG
��������ɽ֮�ۣ�����躮��Ǧ�Ƶ�ѹ�����罥����������վ�Ʈ
��һƬƬ��ѩ��,������ѩ�µ�һ�����ˣ�����ﻬ����·�������ڱ��ϣ�
����̤һ���գ��Ʊص�����������е��÷�����ǡ���ֻ��С���������
��(climb)���ˡ�
LONG
        );
        set("outdoors", "huashan");
        set("cost", 5);
       setup();
}
void init()
{
        add_action("do_next","climb");
}
int do_next(string arg)
{
        object me = this_player();
        int cost,dodge;

        dodge = me->query_skill("dodge",1)/20+1;
        cost = dodge / 2 ;
        cost = random(cost) + 100;
        
        if(me->is_busy())
                return notify_fail("�㻹��æ���ء�\n");

        me->start_busy(2+random(2));
        
        if (!arg)
        {
                tell_object(me,"�������ĸ�����������(left),��(right)����(up)��\n"NOR);

                return 1;

        }
        if (me->query("jingli")<500)
        {
                tell_object(me,HIY"�������͸֧�����˹�ȥ��\n"NOR);
                me->add("jingli",-500);
                return 1;
        }
        if (arg == dir[random(3)] )
        {
                message_vision(HIG"$N�ҵ���һ���ܷ�֮����׼��Ъ����������\n"NOR,me);
                me->move("/d/huashan/hamasuperquest/jueding3");
                me->add("jingli",-cost);
                

        }
        else if (arg == "down")
        {
                message_vision("$NС�������������ȥ��\n"NOR,me);
                me->move("/d/huashan/sheshen");
                me->add("jingli",-cost);
        
        }
        else if (arg=="left" || arg=="right" || arg=="up" )
        {
                tell_object(me,HIR"����˺ܴ��������˹�ȥ��ȴ���������˷���ֻ���˻���ԭ�ء�\n"NOR,me);
                me->add("jingli",-cost);
                me->move("/d/huashan/hamasuperquest/jueding1");

        }
        else
        {
                tell_object(me,"�������������\n");
                
        }
        
        
        return 1;
}
