#include <ansi.h>

inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIC"�����赨ɢ"NOR, ({"tianqi san", "san"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���һ����������赨ɢ���н�ٶ�����Ч��\n");
                set("value", 10);
		set("unique", 3);
		set("no_give",1);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
        if (!id(arg))
              return notify_fail("��Ҫ��ʲô��\n");
        me->clear_conditions_by_type("poison");
        message_vision(HIR"$N����һ�������赨ɢ��һ����������Ϣ�Ե���ӿ������\n"NOR, this_player());
        destruct(this_object());
        return 1;
}
