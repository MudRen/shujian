#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "fu");
}

void create()
{
        set_name("��ҩ", ({"jinchuang yao", "jinchuang", "yao"}));
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("value", 3000);
                set("unit", "��");
                set("long", "����һ����Ч��ҩ�����Բ�����Ѫ��\n");
        }
}

int do_eat(string arg)
{
        object me = this_player();
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        if (me->is_busy())
                return notify_fail("����æ���ء�\n");
        if (me->query("eff_qi") >= me->query("max_qi"))
                return notify_fail("�����ڲ���Ҫ�ý�ҩ��\n");
        me->receive_curing("qi", me->query("max_qi"));
        me->receive_heal("qi", me->query("max_qi"));
        message_vision(HIY"$N����һ����ҩ������������Ȼ�ް���\n"NOR, me);
        me->start_busy(1);
        destruct(this_object());
        return 1;
}