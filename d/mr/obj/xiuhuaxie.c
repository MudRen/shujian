// /clone/armor/guanxue.c   �廨Ь

#include <armor.h>
#include <ansi.h>

inherit BOOTS;
void create()
{
        set_name(HIR"�廨Ь"NOR, ({ "xiuhua xie", "xie","shoes" }));
        set_weight(150);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long","����һ˫�廨Ь��\n");
                set("unit", "˫");
                set("no_transfer",1);
                set("material", "cloth");
                set("armor_type", "feet");
                set("armor_prop/dodge", 2);
        }
        setup(); 
}
