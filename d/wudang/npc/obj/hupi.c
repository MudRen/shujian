// hupi.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("ª¢∆§", ({ "hupi","pi" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "’≈");
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        setup();
}
