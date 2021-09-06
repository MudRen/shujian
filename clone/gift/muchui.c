// muchui.c

#include <weapon.h>
inherit HAMMER;

void create()
{
  set_name("木槌", ({ "mu chui", "muchui" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把木头做的槌子，听说曾被李咏拿来砸金蛋。\n");
    set("value", 100);
		set("material", "wood");
		set("wield_msg", "$N「唰」的一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n背在背上。\n");
	}
	init_hammer(5);
	setup();
}
