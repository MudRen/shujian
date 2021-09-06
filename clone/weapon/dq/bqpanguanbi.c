#include <ansi.h>
#include <weapon.h>
inherit BRUSH;

void create()
{
	set_name(HIM"判官笔"NOR, ({ "Panguan bi", "bi" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("long", "这对判官笔看起来极其普通，但是只要微微按动机关，便能瞬间暴长气寸，威胁极大，不是武艺惊人之士难以躲避。（\n");
		set("value", 60000);
		set("material", "steel");
		set("no_sell", 1);
		set("wield_msg", "$N从袖里抽出一只$n，轻松写意的在空中临摹了几笔。\n");
		set("unwield_msg", "$N将手中的$n插回笔鞘，笼回袖中。\n");
	}
	init_brush(100);
	setup();
}
