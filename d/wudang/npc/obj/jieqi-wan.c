// jieqi-wan.c ������

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
        set_name(HIR"��ת������"NOR, ({"jieqi wan","wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������������ľ�ת�����衣���䵱�ɶ����ɵ�,�й̱���Ԫ����Ч!\n");
                set("value", 10000);
                set("no_drop", "�������������뿪�㡣\n");
        }

        set("wudang",1);
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");

        if ( me->query_skill_mapped("force") != "yinyun-ziqi" )
        {
                me->add("max_neili", -10);
                message_vision(HIR "$N����һ�ž�ת�����裬ֻ���õ������絶�ԭ�������ڹ�����������������Ԫ��\n" NOR, me);
                me->unconcious();
                destruct(this_object());
                return 1;
        }

        if ( me->query("max_neili") < 400 )
        {
                me->add("max_neili", -1);
                message_vision(HIR "$N����һ�ž�ת�����裬ֻ�������������Ҵܣ��ѹ��쳣��ԭ������������ҩЧ�ʵ��䷴��\n" NOR, me);
        }
         else if ( (int)me->query_condition("medicine") > 0 )
        {
                        me->add("max_neili", -10);
                message_vision(HIR "$N����һ�ž�ת�����裬ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
        }
        else
        {
                me->add("max_neili", 1);
                message_vision(HIY "$N����һ�ž�ת�����裬ֻ������������ԴԴ���������ٻ㣬�뵤�������������ȫ������Ȼ��ߣ�\n" NOR, me);
                  me->apply_condition("medicine", 60);
        }

        destruct(this_object());
        return 1;
}

