// longsword.c 长鞭

#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
	set_name( MAG"游龙长鞭"NOR, ({ "youlong bian", "bian" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根由千年巨蟒皮混合乌金丝绞制而成的沉甸甸的长鞭，透出隐隐的紫色宝光，坚韧无比。\n");
		set("value", 80000);
		set("no_sell", 1);
		set("material", "leather");
		set("wield_msg", "$N「唰」的一声抖出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n卷回腰间。\n");
	}
	init_whip(100);
	setup();
}
