#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(MAG"Ïâ»Æ×ÏÅÛ"NOR, ({ "xianghuang zipao", "pao", "cloth" }));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "cloth");
                set("armor_prop/armor", 30);
        }
        setup();
}
