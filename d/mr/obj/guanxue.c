// /clone/armor/guanxue.c   ¹ÙÑ¥ -3

#include <armor.h>
#include <ansi.h>

inherit BOOTS;
void create()
{
        set_name(HIW"¹ÙÑ¥"NOR, ({ "guan xue", "xue","shoes" }));
        set_weight(150);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long","ÕâÊÇÒ»Ë«³¯Í¢¹ÙÔ±¹ßÓÃµÄ¹ÙÑ¥¡£\n");
                set("unit", "Ë«");
                set("no_transfer",1);
                set("material", "cloth");
                set("armor_type", "feet");
                set("armor_prop/dodge", 2);
        }
        setup(); 
}
