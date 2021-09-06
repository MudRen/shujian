// 李广弓

#include <weapon.h>
#include <ansi.h>

//inherit ARROW;
//inherit F_UNIQUE;

void create()
{
        set_name(HIY "李广弓" NOR, ({ "liguang gong","arrow" }));
        set_weight(20000);
       /* if (clonep())
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "把");
                set("long", HIC "这就是当年飞将军李广当年梦虎射石使用的弓，入手十分沉重。\n" NOR);
                set("value", 20000);
                set("material", "steel");
                set("rigidity", 3);
                set("sharpness", 3);
                set("unique", 1);
                set("weapon_prop/dodge", 30);
                set("wield_neili", 500);
                set("wield_maxneili", 3000);
                set("wield_str", 28);
                set("wield_msg", HIY "$N从伸手从背后拿出李广之弓，不由得显的$N气势非常。\n" NOR);
                set("unwield_msg", HIY "$N将李广之弓放入挂入背上，顿时豪情气势顿消。\n" NOR);
        }
        init_arrow(180);
        setup();*/
}
