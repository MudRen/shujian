//  huima.c 白首太玄 
//Created by Redhat@Sjmud 2009/4/7

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

string perform_name() {return WHT"白首太玄"NOR;}

int perform(object me,object target)
{
    object weapon;
    int i;
    i = me->query_skill("taixuan-gong", 1) /3;
    if( !target ) target = offensive_target(me);
     
    if(!objectp(target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("「白首太玄」只能对战斗中的对手使用。\n");

    if((int)me->query_skill("force", 1) < 250 )
                return notify_fail("你的基本内功不够娴熟，无法支持「白首太玄」。\n");

    if( (int)me->query_skill("taixuan-gong", 1) < 250 ) 
 return notify_fail("你的功夫还未练成，不能使用「白首太玄」！\n");

   
    if((int)me->query_skill("dodge", 1) < 250 )
                return notify_fail("你的基本轻功不够娴熟，不能使用「白首太玄」。\n");

                    
    if((int)me->query("max_neili") < 8000 )
                return notify_fail("你的内力修为不够，不能使用「白首太玄」！\n");

    if((int)me->query("neili") < 3000 )
                return notify_fail("你现在真气不足，不能使用「白首太玄」！\n");

    if((int)me->query("jingli") < 1000 )
                return notify_fail("你现在太累了，不能使用「白首太玄」！\n");
      
message_vision(HIW"\n霎时间$N思绪狂涌，不再理会$n如何招架，只管使出侠客岛石壁上的千百种招式尽数向$n袭去！\n"NOR, me,target);

    me->start_perform(3,"「白首太玄」");
    me->add("neili", -800);
    me->add("jingli",-500);
me->set_temp("txg_tx",5);

    me->add_temp("apply/attack", i);
    me->add_temp("apply/damage",i);
target->start_busy(random(4));
        target->set_temp("must_be_hit",1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
   target->delete_temp("must_be_hit");
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
   
   me->add_temp("apply/damage", -i);
   me->add_temp("apply/attack", -i);
me->delete_temp("txg_tx");
    me->start_busy(1);
    target->start_busy(1);
    return 1;
}

int help(object me)
{
   write(HIR"\n太玄功「"HIW"白首太玄"HIR"」："NOR"\n");
   write(@HELP
   指令：perform xuan

   要求：太玄功250级，
         最大内力 8000 以上，
         当前内力 3000 以上，
         当前精力 1000 以上，
         谁能书阁下，
         白首太玄经。
HELP
   );
   return 1;
}

