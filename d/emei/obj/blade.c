// blade.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(GRN"��Ҷ��"NOR, ({ "liuye dao", "blade" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����Ҷ����\n");
		set("value", 1500);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	init_blade(25);
	setup();
}
