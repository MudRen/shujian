// cloth.c
// login cloth
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(YEL"°ÙñÄ½áÒÂ"NOR, ({ "baina jieyi", "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "cloth");
                 set("armor_prop/armor", 20);
        }
        setup();
}
