// /clone/drug/xuelianzi.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"я╘а╚вс"NOR, ({"xuelian zi"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "©е");
                set("value", 6000);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}
