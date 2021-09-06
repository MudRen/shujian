//By action@SJ
//狂风扫落叶

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

string perform_name(){ return HBYEL"狂风扫落叶"NOR; }

int perform(object me,object target)
{
    object weapon;
    int i;
    
    if( !target ) target = offensive_target(me);
     
    if( !objectp (target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("狂风扫落叶只能对战斗中的对手使用。\n");

    if(me->query_skill_mapped("force") != "hamagong")
                return notify_fail("你的内功不是蛤蟆功，无法使用狂风扫落叶！\n");
    if( (int)me->query_skill("hamagong", 1) < 150 )
                return notify_fail("你的内功还未练成，不能使用狂风扫落叶！\n");
    if( (int)me->query_skill("lingshe-zhangfa", 1) < 150 ) 
                return notify_fail("你的灵蛇杖法还未练成，不能使用狂风扫落叶！\n");
    if((int)me->query_skill("staff", 1) < 150 )
                return notify_fail("你的基本杖法不够娴熟，不能在使用狂风扫落叶。\n");
    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "staff"
        || me->query_skill_mapped("staff") != "lingshe-zhangfa"
        || me->query_skill_mapped("parry") != "lingshe-zhangfa")
                return notify_fail("你现在使得了狂风扫落叶么？\n");
                
    if((int)me->query("max_neili") < 3000 )
                return notify_fail("你的内力修为不够，不能使用狂风扫落叶！\n");
    if((int)me->query("neili") < 1000 )
                return notify_fail("你现在真气不足，不能使用狂风扫落叶！\n");

        message_vision(HIC"\n$N跳出数丈外，突然一声暴喝：“------"HIR" 狂 "HIC"-----"HIG" 风 "HIC"-----"HIY" 扫 "HIC"-----"HIM" 落 "HIC"-----"YEL" 叶 "HIC"----- ！！！”\n" NOR,me,target);

    me->start_perform(3+random(2),"「狂风扫落叶」");
    i = (int)me->query_skill("lingshe-zhangfa",1);
        me->add("neili", -300);
        me->add_temp("apply/attack",  i*4/5);
        me->add_temp("apply/damage",  i*6/5);
        me->set_temp("lszf/luoye",1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        me->add_temp("apply/attack",  -i*4/5);
        me->add_temp("apply/damage",  -i*6/5);
        me->delete_temp("lszf/luoye");

    me->start_busy(1);
    target->start_busy(1);
    return 1;
}

int help(object me)
{
   write(WHT"\n灵蛇杖法「"HBYEL"狂风扫落叶"WHT"」："NOR"\n");
   write(@HELP

   要求：  最大内力 3000 以上；
           内力 1000 以上；
           灵蛇杖法等级 150 以上；
           蛤蟆功等级 150 以上；
           激发招架为灵蛇杖法。

HELP
   );
   return 1;
}
