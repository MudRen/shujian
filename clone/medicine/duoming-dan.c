// duoming-dan.c 

#include <ansi.h>

inherit ITEM;

void init()
{
        add_action("do_eat", "fu");
}

void create()
{
        set_name(HIW"�׻�������"NOR, ({"duoming dan","dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ž�Ө����ľ���ҩ�衣\n");
                set("value", 1000);
        }
	set_weight(100);

        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
        if ( (int)me->query_condition("medicine") > 0 )
      {
              me->add("max_neili", -10);
              message_vision(HIR "$N����һ�Ű׻���������ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
              me->unconcious();
              destruct(this_object());
              return 1;
      }
        message_vision(HIW "$N����һ�Ű׻�������������һ��ů���Ե��������漴�鲼��֫������˵�����ж������\n" NOR, me);
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi", me->query("eff_qi"));
        me->set("eff_jing", me->query("max_jing"));
        me->set("jing", me->query("eff_jing"));
        if(me->query("jingli") < me->query("eff_jingli"))//add by caiji
        me->add("jingli", 200);
        if(me->query("neili") < me->query("max_neili")*2)//add by caiji
        me->add("neili", 200);
        destruct(this_object());
        me->apply_condition("medicine", 90);

        return 1;
}

