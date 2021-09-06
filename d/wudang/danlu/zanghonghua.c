#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"²Øºì»¨"NOR, ({"zang honghua"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "¿Å");
                set("value", 9000);
                set("medicine", "drug");
                set("make/drug", 1);
        }
        setup();
}