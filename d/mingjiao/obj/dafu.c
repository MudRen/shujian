// dafu.c ��

#include <weapon.h>
inherit AXE;

void create()
{
	set_name("��", ({ "dafu","fu" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͷ��\n");
		set("value", 5000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
      init_axe(20);
	setup();
}
