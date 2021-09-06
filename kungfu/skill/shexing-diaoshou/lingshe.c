// lingshe.c 灵蛇飞舞
// Last Modified by sir on 4/26/2001

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "灵蛇飞舞"
int perform(object me, object target)
{
	int skill;

	skill = (int)me->query_skill("shexing-diaoshou", 1);

	if( !target ) target = offensive_target(me);

	if( !objectp(target) || !me->is_fighting(target) )
		return notify_fail("「灵蛇飞舞」只能在战斗中使用。\n");

	if( me->query_temp("weapon"))
		return notify_fail("你拿着武器怎么能使用「灵蛇飞舞」！\n");   

	if( skill < 160 )
		return notify_fail("你的蛇形灵蛇飞舞不够娴熟，使不出灵蛇飞舞。\n");

	if(me->query_skill("hamagong",1) < 200 )
		return notify_fail("你的蛤蟆功不够娴熟，使不出灵蛇飞舞。\n");

	if(me->query_skill("shexing-diaoshou",1) < 200 )
		return notify_fail("你的蛇形灵蛇飞舞不够娴熟，使不出灵蛇飞舞。\n");

	if (me->query_skill_mapped("parry") != "shexing-diaoshou" 
	|| me->query_skill_mapped("hand") != "shexing-diaoshou" 
	|| me->query_skill_prepared("hand") != "shexing-diaoshou" )
		return notify_fail("你现在无法使用「灵蛇飞舞」！\n");

	if( (int)me->query("max_neili") < 3000)
		return notify_fail("你现在内力太弱，使不出「灵蛇飞舞」。\n");      

	if( (int)me->query("neili") < 1500 )
		return notify_fail("你现在真气太弱，使不出「灵蛇飞舞」。\n");
		
		if( (int)me->query("jingli") < 1500 )
		return notify_fail("你现在精力太少，使不出「灵蛇飞舞」。\n");

	if( target->is_busy() )
		return notify_fail(target->name() +"目前正自顾不暇，放胆攻击吧！\n");

	message_vision(HIC"$N手腕一抖，只见食指一挑中指一并尾指一扫，犹如灵蛇寻隙钻侵点向$n身上诸穴。\n"NOR,me,target);
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			message_vision(HIY"\n$P一下点中$p的大穴，$p只觉微微一麻，迅即行动如常。\n"NOR,me,target);
			me->start_busy(1+random(3));
			me->add("neili", -100);
		} else {
			message_vision(HIY "\n结果$p被$P点中几处穴道!\n"NOR,me,target);
			target->start_busy(2+random(3));
			me->start_busy(random(2));
			me->add("neili", -100);
		}
	}
	else
	{
		message_vision(HIM "\n$p情急智生，狠力一跃，退出老远。\n"NOR,me,target);
		me->start_busy(3);
	        if(!target->is_fighting(me) && target->query("owner") && 
		        me->query("id") == target->query("owner"))
	        target->fight_ob(me);
        }
	return 1;
}
string perform_name(){ return HIC"灵蛇飞舞"NOR; }
