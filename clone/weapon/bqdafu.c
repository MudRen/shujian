
#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create()
{
	set_name(YEL"宣花大斧"NOR, ({ "dafu","fu" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "此斧刃部弧曲宽阔，两角略微上翘，斧身饰有雷纹，花纹精美。但是刃口雪亮，闪着寒光，令人不寒而栗。\n");
		set("no_sell", 1);
                set("value", 45000);
              set("rigidity",3);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
 init_axe(75);
	setup();
}
