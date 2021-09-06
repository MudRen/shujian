// yinshesword 银蛇剑

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIW"银蛇剑"NOR,({ "yinshe sword", "sword","yinshe" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("no_sell", 1);
                set("value",  55000);
                set("rigidity", 6);
                set("sharpness", 6);
                set("material", "steel");
                set("weapon_prop/parry", 15);
                set("wield_neili", 1000);
                set("wield_maxneili", 1500);
                set("wield_str", 25);
                set("long", "这把剑犹如一条盘蛇，银光闪闪，极为轻巧精致 。\n剑身上一道血痕，发出碧油油的暗光，极是诡异。\n");                
                set("unwield_msg", WHT "$N随手一挥，手中银蛇剑已不见踪影。姿态潇洒无比。\n" NOR);
                set("wield_msg", WHT"$N微一舞动，一道耀眼的银光绕着$N全身上下游走，光芒顿住，$N手中\n"+
                                    "已多了柄弯弯曲曲的奇形宝剑。剑身的寒光映照出$N脸上浮现出诡异神情。\n"NOR);
        }
        init_sword(90);
        setup();
}
