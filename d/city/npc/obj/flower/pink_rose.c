
#include <ansi.h>

inherit COMBINED_ITEM;

int value() { return query_amount() * (int)query("base_value"); }

void create()
{
	set_name(HIM "??õ??" NOR, ({"fen meigui", "fen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "????һ?京?????ŵķ?õ?壬????????Զ?İ???\n");
		set("unit", "??");
		set("value", 45000);
		set("base_unit", "??");
        set("base_weight", 100);
	set("flower_w",1);
			}
	set_amount(1);
}
#include "flower.h"