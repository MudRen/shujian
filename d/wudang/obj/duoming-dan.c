// duoming-dan.c 

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
        set_name(HIW"�׻�������"NOR, ({"duoming dan","dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ž�Ө����ľ���ҩ�衣\n");
                set("value", 1000);
                set("no_drop", "�������������뿪�㡣\n");
                set("no_get", "�����������ò��ˡ�\n");
                set("no_give", "�����������������ˡ�\n");
                set("no_put", "�����������ܷ������ֶ������档\n");

        }

        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");

        message_vision(HIW "$N����һ�Ű׻�������������һ��ů���Ե�������,�漴�鲼��֫,����˵�����ж������\n" NOR, me);
        me->reincarnate();
        me->set("qi", me->query("max_qi"));
        me->set("jing", me->query("max_jing"));
        me->set("jingli", me->query("eff_jingli"));
        me->set("neili", me->query("max_neili"));
        me->set("food", me->max_food_capacity());
        me->set("water", me->max_water_capacity());
        me->add("max_neili",(random(5)+1));
        destruct(this_object());

        return 1;
}

