#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_eat", "fu");
        add_action("do_eat", "eat");
        add_action("do_eat", "chi");
}
void create()
{
        set_name(HIG"�˲ι�"NOR, ({"renshen guo", "guo"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("long",
                "��˽������Թ��Ķ�������������һ���װ����ֵ�С�к���\n"
                "�лָ����������ӹ���������Ч����\n");
                set("value", 1000);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
        message_vision(HIB"
$N����һö�˲ι������ˡ����ٵģ�\n\n"NOR,me);
        destruct(this_object());
        return 1;
}
