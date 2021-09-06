// gunding-dao.c

#include <weapon.h>
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"古锭刀"NOR, ({"guding dao", "dao", "blade", }) );	
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", HIY"一把锈迹斑驳的长刀，传说这就是孙坚当年所用的战刀，份量相当的沉重。\n"NOR);
                set("value", 1);
                set("unique", 1);
                set("rigidity", 5);
                set("sharpness", 10);
                set("weapon_prop/parry", 1);
                set("wield_maxneili", 2000);
                set("treasure",1);
                set("wield_str", 35);
                set("material", "steel");
                set("wield_msg", HIY"$N缓缓将到抽出刀鞘，霎时间狂风暴雨电闪雷鸣，转眼手中已多了一柄英气逼人的尖刀。\n"NOR);
                set("unwield_msg",HIY"$N将古锭刀小心插回刀鞘，顿时英气渐渐消逝。\n"NOR);
        }
        init_blade(180);
        setup();
}
