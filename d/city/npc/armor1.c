// tiejia.c Ìú¼×
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("Ìú¼×", ({ "armor" }) );
        set_weight(16000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "steel");
                set("value", 1600);
                set("armor_prop/armor", 40);
        }
        setup();
}

