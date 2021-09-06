// huxin-dan.c

#include <ansi.h>

inherit ITEM;

void init()
{
             add_action("do_eat", "eat");
             add_action("do_eat", "fu");
}

void create()
{
        set_name("�������ĵ�", ({"huxin dan","dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
                "�䵱�ɵ�ҩ�������ˡ�\n");
                set("value", 10);
                set_weight(25);
                set("unit", "��");
                set("no_get", 1);
                set("no_drop", 1);
                set("no_give", 1);
        }
}

int do_eat(string arg)
{
        object me;
        mapping fam;
        me = this_player();
        if (!id(arg)) return 0;
        if( (int)me->query_condition("medicine") > 0 )
                return notify_fail("���ϴε�ҩ������û���أ��Ȼ��ٳ԰ɡ�\n");
        if( (int)me->query("eff_qi") > (int)me->query("max_qi")/2 )
                return notify_fail("��û�����ˣ���������鵤��ҩ�񲻿�ϧ��\n");
        if( (int)me->query("eff_qi") < (int)me->query("max_qi")/10 )
                return notify_fail("������ƹ��أ������������취�ɡ�\n");
        if (!(fam = this_player()->query("family")) || fam["family_name"] !="�䵱��")
               {
                tell_object(me, "�������ͻȻ������������һ���������ĵ�������\n");
                destruct(this_object());
                return 1;
               }

        if((int)me->query("combat_exp") < 100000 )
                return notify_fail("���ʵս����̫�͡�\n");
        if((int)me->query_skill("yinyun-ziqi", 1) < 80 )
                return notify_fail("��������������������\n");
        if((int)me->query_skill("medicine", 1) < 60 )
                return notify_fail("���ҩ��֪ʶ�����㡣\n");

        message_vision(GRN"\n$N����һ���������ĵ����о����ƴ�ת��\n\n"NOR , me);
        me->apply_condition("medicine", 60);
        me->set("eff_qi",(int)me->query("max_qi"));
        me->set("qi",(int)me->query("max_qi"));
        destruct(this_object()); 
        return 1;
}