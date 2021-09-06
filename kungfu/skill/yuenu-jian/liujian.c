// 沙场破阵剑法 越女亲传
// by Jpei@NT 2009/05

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

string perform_name() {return HIY"临阵六剑"NOR;}

int perform(object me,object target)
{
    object weapon;
    
    if( !target ) target = offensive_target(me);
     
    if(!objectp(target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("临阵六剑只能对战斗中的对手使用。\n");
    if( (int)me->query_skill("yuenu-jian", 1) < 220 )
                return notify_fail("你的剑法还未练成，不能使用临阵六剑攻击！\n");
    if((int)me->query_skill("sword", 1) < 160 )
                return notify_fail("你的基本剑法不够娴熟，不能使用临阵六剑。\n");
    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "yuenu-jian")
                return notify_fail("你手里无剑，如何使用临阵六剑？\n");
                
    if((int)me->query("max_neili") < 1500 )
                return notify_fail("你的内力修为不够，不能使用临阵六剑！\n");
    if((int)me->query("neili") < 1000 )
                return notify_fail("你现在真气不足，不能使用临阵六剑！\n");
        message_vision(HIY"\n$N剑招忽生惨烈悲壮之意，刺挑削、旋引撩，招招皆是剑法入门，威力却是极大，剑剑不离$n致命之处，正是越女亲授之“临阵六剑”"HIY"！\n"NOR, me,target);
    me->start_perform(3,"「临阵六剑」");
    me->set_temp("ynj/6j",1);
     me->add("neili", -500);
 me->add_temp("apply/strength",  me->query_skill("yuenu-jian", 1)*2/5);
 me->add_temp("apply/attack",  me->query_skill("yuenu-jian", 1)*1/5);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
 //   if (me->is_fighting(target))
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
//    if (me->is_fighting(target))
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
//    if (me->is_fighting(target))
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
//    if (me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
//    if (me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    me->delete_temp("ynj/6j");
 me->add_temp("apply/strength", - me->query_skill("yuenu-jian", 1)*2/5);
 me->add_temp("apply/attack", - me->query_skill("yuenu-jian", 1)*1/5);
    target->start_busy(1);
    return 1;
}

int help(object me)
{
   write(WHT"\n越女剑「"HIY"临阵六剑"WHT"」："NOR"\n");
   write(@HELP
    越女亲授临阵六剑，刺挑削、旋引撩，招招皆是剑法入门，却招招指向致命之处，当者披靡。
HELP
   );
   return 1;
}
