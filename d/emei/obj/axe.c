// axe.c ��ͷ

#include <weapon.h>
inherit AXE;

void create()
{
        set_name("��ͷ", ({ "axe", "fu tou" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ѷ����ɵ�����ʧ�ĸ�ͷ���Ƕ����ɷ�ľ�õġ�\n");
                set("value", 1500);
                set("rigidity",2);
                set("material", "steel");
                set("wield_msg", "$N�ó�һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_axe(25);
        setup();
}
