// tiejia.c ����
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIC"����"NOR, ({ "armor" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "steel");
		set("value", 2000);
                set("armor_prop/armor", 50);
        }
        setup();
}

