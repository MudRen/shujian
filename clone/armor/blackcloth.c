// blackcloth.c บฺาย

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("บฺาย", ({ "hei yi", "black cloth", "cloth" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ผþ");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
