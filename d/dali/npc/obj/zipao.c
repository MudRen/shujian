#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(MAG"????????"NOR, ({ "xianghuang zipao", "pao", "cloth" }));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "??");
                set("material", "cloth");
                set("armor_prop/armor", 30);
        }
        setup();
}
