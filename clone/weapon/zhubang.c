// zhubang.c ���

#include <weapon.h>
inherit STICK;

void create()
{
        set_name("���", ({ "zhu bang", "zhubang", "bang" }));
        set_weight(1500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����Ƶ���������ֳ����ģ��ƺ��൱��ʵ��\n");
                set("value", 200);
                set("material", "steel");
                set("wield_msg", "$N���һ��$n�������е��˵ࡣ\n");
                set("unwield_msg", "$N�����е�$n���������䡣\n");
        }
        init_stick(20);
        setup();
}

