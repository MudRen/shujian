// changqiang.c ��ǹ

#include <weapon.h>
inherit SPEAR;

void create()
{
        set_name("��ǹ", ({ "chang qiang", "qiang", "spear" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ӧ����ǹ�������ɶ���ǹͷ����͸�����⡣\n");
                set("value", 1);
                set("material", "steel");
                set("wield_msg", "$N���һ�˸�$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�������\n");
        }
	init_spear(30);
        setup();
}
