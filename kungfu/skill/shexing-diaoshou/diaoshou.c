// 蛇形刁手  

#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;

void remove_effect(object me, int improve);

int perform(object me, object target)
{
	int skill, j;

	skill = (int)me->query_skill("shexing-diaoshou", 1);

	if( !target ) target = offensive_target(me);

	if( !objectp(target) || !me->is_fighting(target) )
		return notify_fail("「蛇形刁手」只能在战斗中使用。\n");

	if( me->query_temp("weapon"))
		return notify_fail("你拿着武器怎么能使用「蛇形刁手」！\n");   

	if( skill < 160 )
		return notify_fail("你的蛇形刁手不够娴熟，使不出蛇形刁手。\n");

	if(me->query_skill("hamagong",1) < 200 )
		return notify_fail("你的蛤蟆功不够娴熟，使不出蛇形刁手。\n");

	if(me->query_skill("shexing-diaoshou",1) < 200 )
		return notify_fail("你的蛇形蛇形刁手不够娴熟，使不出蛇形刁手。\n");

	if (me->query_skill_mapped("parry") != "shexing-diaoshou" 
	|| me->query_skill_mapped("hand") != "shexing-diaoshou" 
	|| me->query_skill_prepared("hand") != "shexing-diaoshou" )
		return notify_fail("你现在无法使用「蛇形刁手」！\n");

	if( (int)me->query("max_neili") < 3000)
		return notify_fail("你现在内力太弱，使不出「蛇形刁手」。\n");      

	if( (int)me->query("neili") < 1500 )
		return notify_fail("你现在真气太弱，使不出「蛇形刁手」。\n");
		
		if( (int)me->query("jingli") < 1500 )
		return notify_fail("你现在精力太少，使不出「蛇形刁手」。\n");
		
		if( me->is_busy() )
		return notify_fail(me->name() +"你正忙呢！\n");

	message_vision(HIB"\n$N将周身关节节节贯通，手臂从一个不能弯折的角度击向$n！\n"NOR,me,target);

	j = skill/3;
	if ( skill > 200)
		j = to_int(skill/200.0 * skill/3.0);
  me->set_temp("sxds/ds",1);
	me->add_temp("apply/attack", j);
	me->add_temp("apply/hand", j);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	
	if(me->is_fighting(target)) 
	
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
				
	if(me->is_fighting(target)) 
		
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
		
	me->add_temp("apply/attack", -j);
	me->add_temp("apply/hand", -j);

	me->add("neili", -400);
	me->add("jingli", -150);
	me->start_perform(4, "蛇形刁手");
	me->delete_temp("sxds/ds");
	me->start_busy(random(2));
	target->start_busy(random(2));
	
	return 1;
}

string perform_name(){ return HIG"蛇形刁手"NOR; }

int help(object me)
{
	write(RED"\n蛇形蛇形刁手之「蛇形刁手」："NOR"\n");
	write(@HELP

	要求：当前内力 2500 以上；
		最大内力 2000 以上：
		当前精力 1500以上；
		蛇形蛇形刁手等级 200 以上；
		蛤蟆功等级 200 以上；
		内功有效等级 200 以上：
HELP
	);
	return 1;
}
