// sanmending.c 丧门钉
// cck 17/6/97

#include <weapon.h>
inherit THROWING;
inherit COMBINED_ITEM;
#include <ansi.h>
#include "/inherit/item/embed.h"

void create()
{
	set_name(GRN"丧门钉"NOR, ({ "sangmen ding", "ding" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把丧门钉，似乎喂的是“青陀罗花”的毒汁。\n");
		set("value", 50000);
		set("no_sell", 1);
		set("material", "steel");
		set("wield_msg", "$N抓出一把丧门钉扣在手心。\n");
		set("unwield_msg", "$N将手中的丧门钉放回装暗器的皮囊里。\n");
		set("base_unit", "枚");
		set("damage", 50);
		set("embed", 1);
		set("base_weight", 50);
		set("poison", "qtlh_poi");
		set("poison_number", 6);
	}
	set_amount(10);
	init_throwing(50);
	setup();
}
