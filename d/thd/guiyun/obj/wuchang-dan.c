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
        set_name(HIR"�޳���"NOR, ({"wuchang dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIR"����һ��Ѫ��ĵ�ҩ�����һ���������ʥҩ�޳�����\n"NOR);
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
         me->receive_curing("qi", 10000);
         message_vision(HIR"$N����һ���޳�������ɫ�����ö��ˡ�\n"NOR, this_player());
        destruct(this_object());
                return 1;
}

