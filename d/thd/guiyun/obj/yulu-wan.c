// yulu-wan.c �Ż���¶��
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
        set_name(HIG"�Ż���¶��"NOR, ({"yulu wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIG"����һ�ŷ��ŵ��������СԲ�򡣲������ۡ�\n"NOR);
                set("value", 100);
                set("no_drop", 1);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        if (me->query_skill_mapped("force") != "bihai-chaosheng")
        {
                me->add("max_neili", -10);
                message_vision(HIR "$N����һ�žŻ���¶�裬ֻ���õ������絶�ԭ�������ڹ�����������������Ԫ��\n" NOR, me);
                me->unconcious();
                destruct(this_object());
                return 1;
        }

        else {
                me->set("jingli", me->query("eff_jingli"));
                me->receive_curing("jing", 100);
                message_vision(HIG"$N����һ�žŻ���¶�裬�������ö��ˡ�\n"NOR, this_player());
        
        }
        destruct(this_object());
                return 1;
}

