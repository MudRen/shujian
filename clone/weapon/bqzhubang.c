// zhubang.c ���

#include <weapon.h>
#include <ansi.h>

inherit STICK;

void create()
{
        set_name(HIG"���������"NOR, ({ "zhu bang", "zhubang", "bang" }));
        set_weight(1500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������ؤ������������������ֳ����ģ��൱��ʵ��\n");
                set("value", 60000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", "$N���һ��$n�������е��˵ࡣ\n");
                set("unwield_msg", "$N�����е�$n���������䡣\n");
        }
        init_stick(120);
        setup();
}

