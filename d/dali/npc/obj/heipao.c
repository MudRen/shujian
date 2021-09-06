// heipao.c ╨зеш

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("╨зеш", ({ "hei pao", "pao" ,"cloth" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "╪Ч");
                set("material", "steel");
                set("armor_prop/armor", 50);
        }
        setup();
}

