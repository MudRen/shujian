// /clone/drug/hua.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"½ðÒø»¨"NOR, ({"jinyin hua"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "¶ä");
                set("value", 3500);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}
