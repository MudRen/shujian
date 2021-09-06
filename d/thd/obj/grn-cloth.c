// grn-cloth.c thd 二代弟子穿

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIC"青色长袍"NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这是一件青色的长袍。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 30);
        }
        setup();
}
