// hupi.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(YEL"��Ƥ"NOR, ({ "hu pi", "pi" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "fur");
               	set("value", 20000);
                set("warm_cloth", 1);
                set("armor_prop/armor", 10);
        }
        setup();
}

