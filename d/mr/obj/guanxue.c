// /clone/armor/guanxue.c   ��ѥ -3

#include <armor.h>
#include <ansi.h>

inherit BOOTS;
void create()
{
        set_name(HIW"��ѥ"NOR, ({ "guan xue", "xue","shoes" }));
        set_weight(150);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long","����һ˫��͢��Ա���õĹ�ѥ��\n");
                set("unit", "˫");
                set("no_transfer",1);
                set("material", "cloth");
                set("armor_type", "feet");
                set("armor_prop/dodge", 2);
        }
        setup(); 
}
