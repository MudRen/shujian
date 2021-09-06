#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIY"½ð¼×"NOR, ({ "jin jia", "armor", "jia" }) );
        set_weight(16000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "steel");
                set("value", 20000);
                set("armor_prop/armor", 100);
        }
        setup();
}

