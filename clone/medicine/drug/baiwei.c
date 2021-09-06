// /clone/drug/baiwei.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"°×Þ±"NOR, ({"bai wei"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "¶ä");
                set("value", 1000);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}
