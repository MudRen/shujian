// /clone/drug/niuhuang.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"Å£»Æ"NOR, ({"niu huang"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "¿Å");
                set("value", 2000);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}
