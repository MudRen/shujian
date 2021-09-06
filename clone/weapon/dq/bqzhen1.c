// 针

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name(HIB "蓝玉毒针" NOR, ({ "lanyu duzhen", "zhen", "needle", "duzhen" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "一枚蓝莹莹的细针，通体晶莹，偶尔有一丝蓝亮游动，似乎喂有剧毒。\n");
                set("value", 120000);
                set("unique", 2);
                set("needle", 1);
		  set("no_sell", 1);
		  set("material", "steel");
                set("weapon_prop/dodge", 2);
		  set("wield_msg", "$N打开沙纸，轻轻捻起一枚$n。\n");
		  set("unwield_msg", "$N将$n用砂纸包起来，藏回怀中。\n");
                set("poisoned", "xx_poison");
                set("poison_number", 300);
 //               set("treasure", 1);
	}
        init_sword(100);
	setup();
}
