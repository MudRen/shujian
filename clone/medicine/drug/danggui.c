// /clone/drug/danggui.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(CYN"µ±¹é"NOR, ({"dang gui"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
                set("value", 3500);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}
