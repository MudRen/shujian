//heiyi.c ????
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("????", ({ "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "??");
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}
