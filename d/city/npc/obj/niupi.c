// /d/emei/npc/obj/niupi.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("ţƤ", ({ "niu pi", "pi", "cow skin" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "fur");
                set("value", 300);
                set("armor_prop/armor", 2);
        }
        setup();
}

