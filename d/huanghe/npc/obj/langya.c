#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name("����", ({ "lang ya", "ya" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "jade");
                set("value", 2000);
                set("armor_prop/armor", 10);
        }
        setup();
}

