#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "fu");
}

void create()
{
        set_name("С����", ({"xiaohuan dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("value", 3000);
                set("unit", "��");
                set("long", "����һ��С���������Բ���������\n");
        }
}

int do_eat(string arg)                             
{
        object me = this_player();
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        if (me->is_busy())
                return notify_fail("����æ���ء�\n");
        if (me->query("neili") >= me->query("max_neili"))
                return notify_fail("�����ڲ���Ҫ��С������\n");
        me->set("neili", me->query("max_neili"));
        message_vision(HIY"$N����һ��С��������ʱ�о�����ԴԴ������\n"NOR, me);
        me->start_busy(1);
        destruct(this_object());
        return 1;
}