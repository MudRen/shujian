// /clone/drug/fuling.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"‹Ú‹ﬂ"NOR, ({"fu ling"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "÷Í");
                set("value", 2000);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}
