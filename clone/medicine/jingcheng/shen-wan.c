#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "fu");
}

void create()
{
        set_name("����", ({"shen wan", "shen", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("value", 3000);
                set("unit", "��");
                set("long", "����һ����Ч���裬���Բ�����Ѫ��\n");
        }
}

int do_eat(string arg)
{
        object me = this_player();
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        if (me->is_busy())
                return notify_fail("����æ���ء�\n");
        if (me->query("eff_jing") >= me->query("max_jing"))
                return notify_fail("�����ڲ���Ҫ�ò��衣\n");
        me->receive_curing("jing", me->query("max_jing"));
        me->receive_heal("jing", me->query("max_jing"));
        message_vision(HIY"$N����һ�Ų��裬����������Ȼ�ް���\n"NOR, me);
        me->start_busy(1);
        destruct(this_object());
        return 1;
}