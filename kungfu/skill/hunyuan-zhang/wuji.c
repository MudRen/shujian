// wuji.c 无级
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int damage, hehe;
	object weapon = me->query("weapon");
        hehe = ((int)me->query_skill("hunyuan-zhang",1)+(int)me->query_skill("zixia-gong",1)) / 15 ;
        if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("混元无极只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用混元无极！\n");  
		
        if( (int)me->query_skill("hunyuan-zhang", 1) < 100 )
                return notify_fail("你的混元掌不够娴熟，不会使用混元无极！\n");
	                        
        if( (int)me->query_skill("zixia-gong", 1) < 80 )
                return notify_fail("你的紫霞神功不够高，不能用出混元无极伤敌。\n");

        if( (int)me->query("neili") < 200 )
                return notify_fail("你现在内力太弱，无法使出混元无极。\n");

    msg = HIR "$N暗运紫霞神功，脸上返着暗暗的紫色，一股混元掌柔和的掌力直逼$n奇经八脉。\n"NOR;

  if (random(me->query_skill("zixia-gong")) > target->query_skill("force")/4 )
	{
                me->start_busy(2);
                target->start_busy(random(4));
		
                damage = (int)me->query_skill("hunyuan-zhang", 1) * 3 ;
		
		damage = damage/2 + random(damage);
		
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage * 2/3);
                me->add("neili", -damage/8);
                target->add("neili", -damage*3);
                msg += RED"结果$N一击命中，$n只感到浑身一股暖流向全身散去，突然感到一种难以忍受的灼热。\n"NOR;
	        target->apply_condition("hunyuan_hurt", hehe);
	} else 
        {
                me->start_busy(random(3));
                me->add("neili", damage/10);
                msg += CYN"可是$p看破了$P的招数，向旁跳开数步，躲开了$P的凌厉一击！\n"NOR;
	}
	message_vision(msg, me, target);
	return 1;
}
