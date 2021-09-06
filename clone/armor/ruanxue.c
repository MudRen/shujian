// ruanxue.c
// Lklv 2001.9.25

#include <ansi.h>
#include <armor.h>
inherit BOOTS;

void create()
{
        set_name(HIG"ÈíÑ¥"NOR, ({ "ruan xue", "ruanxue", "xuezi", "shoes" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
                set("material", "boots");
                set("armor_prop/dodge", 2);
        }
        setup();
}
