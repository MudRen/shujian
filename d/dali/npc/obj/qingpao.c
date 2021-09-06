// Modify By River 98/12
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIC"À¶±ßÇàÅÛ"NOR, ({ "lanbian qingpao", "pao", "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "cloth");
                set("armor_prop/armor", 15);
        }
        setup();
}
