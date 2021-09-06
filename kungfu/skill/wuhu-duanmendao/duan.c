#include <ansi.h>
inherit F_SSERVER;

string perform_name() {return HIY"断字诀"NOR;}

int perform(object me, object target)
{
    int lvl;
    object weapon; 
    lvl = me->query_skill("wuhu-duanmendao", 1);
    
    if( !target ) target = offensive_target(me);
        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
        return notify_fail("你只能对战斗中的对手使用断字诀。\n");

    if( (int)me->query_skill("wuhu-duanmendao", 1) < 220 )
        return notify_fail("你的五虎断门刀不够娴熟，无法施展出断字诀。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "blade") 
                return notify_fail("你手上无刀如何能使出「断字诀」？\n");

    if (me->query_skill_mapped("blade") != "wuhu-duanmendao"
         || me->query_skill_mapped("parry") != "wuhu-duanmendao")
         return notify_fail("你现在无法使用「断字诀」！\n");  

    if ( (int)me->query("max_neili") < 3000)
        return notify_fail("你的内力不够，无法施展出断字诀。\n");

    if ( (int)me->query("neili") < 1000)
        return notify_fail("你的真气不够，无法施展出断字诀。\n");

    if ((int)me->query("jingli") < 1000)
        return notify_fail("你的精气不够，无法施展出断字诀。\n");

    message_vision(HIY"$N猛然伏地，使出五虎断门刀"NOR+HIR"「断」"NOR+HIY"字诀，顿时一片白光直向$n滚去！\n"NOR,me, target);
    me->start_perform(2,"「断字诀」");

if(!userp(target)&& me->query("max_pot",1)<=550) target->start_busy(lvl/50); 

    else if(!random(3))  target->add_busy(lvl/100); 
 
 me->add("neili", -(300 +random(100)) );
 me->add("jingli", -150);

   me->add_temp("apply/attack",lvl/3);
   me->add_temp("apply/damage",lvl/4);

    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

    me->start_busy(random(2) + 1);
    me->add_temp("apply/attack", -lvl/3);
    me->add_temp("apply/damage", -lvl/4);
   
    return 1;
}


int help(object me)
{
        write(HIG"\n五虎断门刀之「断字诀」："NOR"\n\n");
        write(@HELP
        五虎断门刀绝技，连续攻击三招，出刀迅捷，
        在新手阶段容易造成敌人手忙脚乱，极具攻击性。
        451级（最大潜能551点）以后威力衰减。

        要求：  当前内力 1000 以上;
                最大内力 3000 以上；
                五虎断门刀等级 220 以上；
                激发刀法为五虎断门刀；
                激发招架为五虎断门刀；
 
HELP
        );
        return 1;
}

