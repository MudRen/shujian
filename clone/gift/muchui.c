// muchui.c

#include <weapon.h>
inherit HAMMER;

void create()
{
  set_name("ľ�", ({ "mu chui", "muchui" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ľͷ������ӣ���˵������ӽ�����ҽ𵰡�\n");
    set("value", 100);
		set("material", "wood");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���ڱ��ϡ�\n");
	}
	init_hammer(5);
	setup();
}
