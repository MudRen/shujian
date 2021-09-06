// 观日剑

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIR "观日剑" NOR, ({ "guanri jian", "guanri", "jian" }));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "把");
                set("long", HIR "观日剑据说在观日峰十年铸成，光芒犹如初升之红日，能破魔消灾。\n" NOR);
                set("value", 10000);
                set("material", "steel");
                set("rigidity", 3);
                set("sharpness", 3);
                set("unique", 1);
                set("weapon_prop/parry", 2);
                set("wield_neili", 500);
                set("wield_maxneili", 900);
                set("wield_str", 23);
                set("wield_msg", HIR "$N出手拔剑一转，一轮红日若从剑鞘中升起，剑光闪烁耀眼。\n" NOR);
                set("unwield_msg", HIR "只见$N手指微动，红日没于剑鞘之中。\n" NOR);
        }
        init_sword(45);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

if(me->query("family/family_name")!="嵩山派" ) return 0;              
if( victim->query_condition("no_fight") &&  victim->query_condition("no_perform")) return 0;
if(random(10)>5) return 0;

        switch (random(3))
        {
        case 0:
                victim->start_busy(me->query_skill("sword",1) / 200 + 1);
                 n = me->query_skill("sword");
                 victim->add_condition("no_fight", 1);

                return HBYEL HIY"$N" HBYEL HIY"跨前一步，手中的" NOR + HIR"观日剑" NOR
                       + HBYEL HIY"发出一道道剑气，向$n" HBYEL HIY"逼去，剑气凌厉之极，如同万丈红日，不可逼视。\n"
                       "$n" HBYEL HIY"大吃一惊，不知如何抵挡，只有连连后退！\n" NOR;

        case 1:
                n = me->query_skill("sword",1);
                victim->receive_damage("qi", n*2, me);
                victim->receive_wound("qi", n, me);
                victim->receive_damage("neili", n, me);
                victim->add_busy(1+random(2));
                victim->add_condition("no_perform", 1+random(2));

                
                return random(2) ? HBYEL HIY"$N" HIY "一声长吟，手中"HIR"观日剑"HBYEL HIY"迸射出一"
                                   "道犀利无比的剑气，急如星火，朝$n" HBYEL HIY"激射而去！\n" NOR:
                                   HBYEL HIY"$N" HBYEL HIY"突然大声喝道：“看招！”剑招忽变"
                                   "手中"HIR"观日剑"HBYEL HIY"幻化出无数道剑光，如初升之朝阳，\n" HIY "霞光万道，$n"
                                   HBYEL HIY"登时觉得头昏目眩眼花缭乱！\n" NOR;
        case 2:
                n = me->query_skill("sword",1);
                victim->receive_damage("qi", n*2, me);
                victim->receive_wound("qi", n, me);
                victim->receive_damage("neili", n, me);
                victim->add_busy(1+random(2));
                victim->add_condition("no_perform", 1+random(2));

                
                return random(2) ? HBYEL HIY"$N" HIY "一声长吟，手中"HIR"观日剑"HBYEL HIY"迸射出一"
                                   "道犀利无比的剑气，急如星火，朝$n" HBYEL HIY"激射而去！\n" NOR:
                                   HBYEL HIY"$N" HBYEL HIY"突然大声喝道：“看招！”剑招忽变"
                                   "手中"HIR"观日剑"HBYEL HIY"幻化出无数道剑光，如初升之朝阳，" HIY "霞光万道，$n"
                                   HBYEL HIY"登时觉得眼花缭乱！\n" NOR;


        }

       
}


 
