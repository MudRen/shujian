#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "fu");
}

void create()
{
        set_name("�ⶾ��", ({"jiedu wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("value", 3000);
                set("unit", "��");
                set("long", "����һ�Žⶾ�裬������Ч�Ŀ��Ƹ��ֶ��ء�\n");
        }
}

int do_eat(string arg)                             
{
        object me = this_player();
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        if (me->is_busy())
                return notify_fail("����æ���ء�\n");
        me->clear_conditions_by_type("poison");
        message_vision(HIY"$N����һ�Žⶾ�裬��������֮���õ��˻��⡣\n"NOR, me);
        me->start_busy(1);
        destruct(this_object());
        return 1;
}