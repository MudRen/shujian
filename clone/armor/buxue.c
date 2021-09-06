// buxue.c ²¼Ñ¥
// build by Lklv@SJ 2001.9.28

#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("²¼Ñ¥", ({ "bu xue", "buxue", "xue", "shoes" }) );
        set_weight(120);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "boots");
                set("unit", "Ë«");
                set("value", 0);
                set("armor_prop/dodge", 1);
        }
        setup();
}
