// chaidao.c
// Creat for hs job

#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("��", ({ "chai dao", "chaidao", "dao" }));
        set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                  set("long", "����һ�Ѳ񵶣�����ر���\n");
                set("value", 300);
		set("material", "steel");
                  set("wield_msg", "$N��ৡ��س��һ��$n�������С�\n");
                  set("unwield_msg", "$N�����е�$n�������䡣\n");
	}
        init_blade(4);
	setup();
}
