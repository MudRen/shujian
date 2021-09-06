// /clone/drug/baotai.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"±ªÌ¥"NOR, ({"bao tai"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
                set("value", 7000);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}
