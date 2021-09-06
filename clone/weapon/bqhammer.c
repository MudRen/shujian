// copy to hammer.c
//modified by campsun 2003/09/20
//轮子，最终威力最大的基本武器。
#include <ansi.h>
#include <weapon.h>
inherit F_HAMMER;
inherit F_EQUIP;
inherit COMBINED_ITEM;

void create()
{
        set_name( BLU"秘传法轮"NOR,({ "falun" ,"lun" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "只");
                set("long","这只法轮由玄铁所制，约有尺半大小。轮上铸有密宗伏魔真言，内藏九个小球，轮子边缘磨得极薄，寒光闪烁，锐利无比。\n");
                set("value", 80000);
                set("rigidity", 3);
                set("weapon_prop/dodge", -5);
		set("no_sell", 1);
                set("weapon_prop/parry", 20);    
                set("material", "iron");
                set("base_unit", "只");
                set("base_weight", 18000);
                set("wield_msg", "$N从怀中掏出$n掂了掂分量，握在手中，当啷啷响声良久。\n");
                set("unwield_msg","$N将手中的$n揣回怀中。\n");
        }    
        set_amount(5);           
        init_hammer(60);
        setup();
}


