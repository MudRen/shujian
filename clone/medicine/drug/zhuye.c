// /clone/drug/zhuye.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"����Ҷ"NOR, ({"zhu ye"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Ƭ");
                set("value", 1500);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}
