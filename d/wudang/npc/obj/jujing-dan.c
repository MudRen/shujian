// jujing-dan.c ������

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
        set_name(HIY"����۾���"NOR, ({"jujing dan","dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ҩ�����˵�����۾�����\n");
                set("value", 10000);
//                set("no_drop", "�������������뿪�㡣\n");
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
                me->add("max_jingli", -5);
                me->add("eff_jingli", -5);
                message_vision(HIR "$N����һ������۾�����ֻ����ͷ�����ѣ�ԭ�������ڹ�����������������Ԫ��\n" NOR, me);
                me->unconcious();
                destruct(this_object());
                return 1;
        }

 if ( me->query("eff_jingli") < 200 )
        {
me->add("eff_jingli", -1);
me->add("max_jingli", -1);
                message_vision(HIR "$N����һ������۾�����ֻ����ͷ�ؽ��ᣬҡҡ������ԭ������������ҩЧ�ʵ��䷴��\n" NOR, me);
        }
        else if ( (int)me->query_condition("bonze_drug" ) > 0 )
        {
me->add("eff_jingli", -1);
me->add("max_jingli", -1);
                message_vision(HIR "$N����һ������۾�����ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
        }
        else
        {
me->add("eff_jingli", 1);
me->add("max_jingli", 1);
                message_vision(HIY "$N����һ������۾�����ֻ��������ƮƮ���ɣ��پ�����ڱ���\n" NOR, me);
        me->apply_condition("bonze_drug", 30);
        }
        
        destruct(this_object());
        return 1;
}
