// /clone/drug/fangfeng.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"����"NOR, ({"fang feng"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 2500);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}
