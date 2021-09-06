// ITEM: /d/huashan/obj/lingzhi.c
// Date: Look 99/03/25

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("��֥��", ({"lingzhi cao", "lingzhi", "cao"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY"����һ��������ɽ���ϵ���֥�ݣ���Ч�ޱȡ�\n");
                set("value", 10000);
              set("no_drop", 1);
              set("no_give", 1);
              set("no_get", 1);
        }

        set("huashan",1);
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");


        if ( me->query_skill_mapped("force") != "zixia-gong" )
        {
                me->add("max_neili", -10);
                message_vision(HIR "$N����һ����֥�ݣ�ֻ���øγ���ϣ�ԭ�����˲ݾ����ڻ�ɽ֮�ϣ������������������\n" NOR, me);
                me->unconcious();
                destruct(this_object());
                return 1;
        }

        if ( me->query("max_neili") < 400 )
        {
                me->add("max_neili", -1);
                message_vision(HIR "$N����һ����֥�ݣ�ֻ����ͷ�ؽ��ᣬҡҡ������ԭ��������������ʳ�ɲݣ�ҩЧ�ʵ��䷴��\n" NOR, me);
        }
            else if ( (int)me->query_condition("medicine") > 0 )
        {
                me->add("max_neili", -5);
                message_vision(HIR "$N����һ����֥�ݣ�ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
        }
         else if ((me->query_skill("force")*8 +  me->query("combat_exp",1)/1000 ) <= me->query("max_neili") )
        { 
                message_vision(HIR "$N����һ����֥�ݣ�ֻ������Ȼ�ɲ����飬Ҳ��������������Ϊ�ˣ�\n" NOR, me);
        }
        else
        {
                me->add("max_neili", 1);
                message_vision(HIG "$N����һ����֥�ݣ�ֻ������������ԴԴ������������Ȼ��� !\n" NOR, me);
        }
            me->apply_condition("medicine", 60);
        
        destruct(this_object());
        return 1;
}
