// jiedu-dan.c

#include <ansi.h>

inherit ITEM;

void init()
{
             add_action("do_eat", "eat");
             add_action("do_eat", "fu");
}

void create()
{
        set_name("���Ľⶾ��", ({"jiedu dan","dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
                "�䵱�ɵ�ҩ���ⶾ�á�\n");
                set_weight(25);
                set("value", 10);
                set("unit", "��");
                set("no_get", 1);
                set("no_drop", 1);
                set("no_give", 1);
        }
}

int do_eat(string arg)
{
        object me;
        int i,plvl,cure;
        mixed a;
        mapping fam;
        string poison;
        a = ({"snake_poison","xx_poison","dsy_poison","fs_poison","huagu_poison","man_poison","qinghua_poison","qishang_poison","qzhu_poison","sl_poison","sy_poison","warm_poison","hot_poison","cold_poison","bing_poison","hb_poison","bt_poison"}); 
        me = this_player();
        cure = 10 + random(20);
        for( i=0; i < sizeof(a); i++ )
                        if( me->query_condition(a[i]) > 0 )
                        {
                                poison = a[i];
                                break;
                        }
        if (!id(arg)) return 0;
        if( (int)me->query_condition("medicine") > 0 )
                return notify_fail("���ϴε�ҩ������û���أ��Ȼ��ٳ԰ɡ�\n");

        plvl= me->query_condition(poison , 1);

        if (!(fam = this_player()->query("family")) || fam["family_name"] !="�䵱��")
               {
                tell_object(me, "�������ͻȻ������������һ�����Ľⶾ��������\n");
                destruct(this_object());
                return 1;
               }

        if( plvl == 0 )
                return notify_fail("�㲢û�ж���С�ĳԴ���ҩ��\n");
        if((int)me->query("combat_exp") < 100000 )
                return notify_fail("���ʵս����̫�͡�\n");
        if((int)me->query_skill("yinyun-ziqi", 1) < 80 )
                return notify_fail("��������������������\n");
        if((int)me->query_skill("medicine", 1) < 60 )
                return notify_fail("���ҩ��֪ʶ�����㡣\n");

        message_vision(MAG"\n$N����һ�����Ľⶾ�����е��������еĶ��������ᣡ\n\n"NOR , me);
        me->apply_condition("medicine", 3);
        if (plvl < cure) 
            me->apply_condition(poison, 0);
        else me->apply_condition(poison, plvl-cure);
        destruct(this_object()); 
        return 1;
}