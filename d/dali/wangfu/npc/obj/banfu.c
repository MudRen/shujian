// banfu.c

#include <weapon.h>
inherit AXE;

void create()
{
        set_name("�����師", ({ "bingtie banfu","fu","axe" }));
        set_weight(12000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����������ƶ��ɳ����ĸ�ͷ��\n");
                set("value", 1500);
                set("material", "steel");
                set("wield_msg", "$N���ѡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_axe(25);
        setup();
}
