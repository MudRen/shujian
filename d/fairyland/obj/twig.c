// twig.c
// By jpei
// Modify By River@SJ
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIG"֦��"NOR, ({ "zhi tiao", "twig", "zhi" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "֦");
		set("long", "�������ϵ�֦����\n");
		set("value", 1);
		set("material", "wood");
                set("wield_msg", "$N�ó�һ֦$n���������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
	}
	init_sword(1);
}
