// zhouyu.c 暴风骤雨

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg, *limbs;
	int p,count, damage = 0, damage1;
	int arg,ap,dp, i=0;

	if( !target )
		target = offensive_target(me);

	if( !objectp(target) || !me->is_fighting(target) )
		return notify_fail("「暴风骤雨」只能在战斗中对对手使用。\n");

	if( objectp( me->query_temp("weapon")) )
		return notify_fail("只有空手才能施展「暴风骤雨」。\n");

	if( me->query_skill("strike") < 150 )
		return notify_fail("你的掌法不够娴熟，不会使用「暴风骤雨」。\n");

	if( me->query_skill("panshi-shengong", 1) < 150 )
		return notify_fail("你的磐石神功等级不够，不能使用「暴风骤雨」。\n");

	if( me->query("max_neili") < 3000 )
		return notify_fail("你内力修为不够，不能使用「暴风骤雨」。\n");

	if( me->query("neili") < 1000 )
		return notify_fail("你现在内力太弱，不能使用「暴风骤雨」。\n");

	if( me->query("jingli") < 1000 )
		return notify_fail("你现在精力不够，自己小心啊！\n");

	if (me->query_skill_prepared("strike") != "kuaihuo-zhang"
	 || me->query_skill_mapped("force") != "panshi-shengong" 
	 || me->query_skill_mapped("strike") != "kuaihuo-zhang" 
	 || me->query_skill_mapped("parry") != "kuaihuo-zhang" )
		return notify_fail("你现在无法使用「暴风骤雨」进行攻击。\n");

        if( me->query("env/暴风骤雨") == "暴风" ) {
		message_vision(HIG"\n$N大吼一声，双掌激烈的翻动着，宛如「暴风骤雨」，使人无法抵挡。"NOR, me, target);

		i = me->query_skill("kuaihuo-zhang", 1)/100;
		if( i < 1 ) i = 1;
		if( i > 2 ) i = 2 + random(2);

		me->add_temp("apply/attack", me->query_skill("panshi-shengong", 1)/2);
		me->add_temp("apply/strike", me->query_skill("kuaihuo-zhang", 1)/3);
		me->add_temp("apply/dodge", me->query_skill("kuaihuo-zhang", 1)/3);
		me->add("jiali", i*50);

		me->set_temp("zhouyu1", 1);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SUPER);
		me->delete_temp("zhouyu1");

		me->set_temp("zhouyu2", i+1);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);
		me->delete_temp("zhouyu2");
		
		me->set_temp("zhouyu3", i+1);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);
		me->delete_temp("zhouyu3");
		
		me->set_temp("zhouyu4", i+1);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);
		me->delete_temp("zhouyu4");

		me->add_temp("apply/attack", -me->query_skill("panshi-shengong", 1)/2);
		me->add_temp("apply/strike", -me->query_skill("kuaihuo-zhang", 1)/3);
		me->add_temp("apply/dodge", -me->query_skill("kuaihuo-zhang", 1)/3);
		me->add("jiali", -i*50);

		me->receive_damage("neili", 400);
		me->receive_damage("jingli", 50);

		me->start_perform(3, "「暴风」");
		me->add_busy(1+random(2));
		return 1;
	}

	arg = (me->query_skill("kuaihuo-zhang", 1)-1) / 50;

	if( me->query("neili") < 50*arg + me->query("jiali")*arg/4 )
		return notify_fail("你现在的内力施展不了那么多招。\n");

message_vision(HIY"$N一反平常快活逍逸的神情，口中大喝了一声，施展出「暴风骤雨」！\n"NOR, me, target);
message_vision(HIY"$N双掌上下翻飞，$n只觉得四周都是$N"HIY"双掌的影子，根本不知如何招架，更不用说躲闪了！\n\n"NOR, me, target);
	ap = COMBAT_D->skill_power(me, "strike", SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

	if (target->is_busy())
		dp -= dp / 2;

	if (!userp(target)) {
		i = me->query_temp("ts/zyfail/"+target->query("id"));
		if (dp / 2 > ap)
			i = 0;
	}

	if (!living(target))
		i = 2;

	if (random(ap+dp) > dp || i >= 2) {
		limbs = target->query("limbs");
		damage = 0;
		for (count=0; count<arg; count++) {
			message_vision(
				replace_string(SKILL_D("kuaihuo-zhang")->query_action(me, 0)["action"],
					"$l", limbs[random(sizeof(limbs))]
				) + "！\n", me, target);
			damage1 = 200 + random(100);
			if (count > 6 && arg >= 8)
				damage1 += random(480);
			damage1 += me->query("jiali")/2 + random(me->query("jiali")/4);
			if ( count > 5 && random(2)) damage1 /= 2;
			damage -= target->query_temp("apply/armor_vs_force");
			damage += damage1;
		}

		damage = damage * me->query_str(1) / 32;

		if(wizardp(me) && me->query("env/test"))
			tell_object(me,sprintf("damage:%d \n",damage));

		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/2 + random(damage/2), me);
		msg = "\n";
		msg += COMBAT_D->damage_msg(damage, random(2)?"瘀伤":"内伤");
		if (random(2) && target->query("qi") >=0 || target->query("eff_qi")+target->query_temp("apply/qi") < 0) {
			p = (target->query("eff_qi")+target->query_temp("apply/qi"))*100
				/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		}
		else {
			p = target->query("qi")*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg += "( $n"+COMBAT_D->status_msg(p)+" )\n";
		}
		me->add("neili", -450);
		me->delete_temp("ts/zyfail");
	}
	else {
		me->add("neili", -200);
		if (!userp(target))
			me->add_temp("ts/zyfail/"+target->query("id"), 1);
		msg = HIR"$n"HIR"身形急速后退，顺着掌风就势一跳，躲开了这攻击。\n" NOR;
	}
	me->add("jingli", -100);
	me->start_perform(3, "「骤雨」");
	me->add_busy(random(2));
	message_vision(msg, me, target);

	return 1;
}

string perform_name(){ return HIG"暴风骤雨"NOR; }
int help(object me)
{
	write(HIG"\n快活十三掌之「暴风骤雨」："NOR"\n\n");
	write(@HELP
	要求：150级磐石神功，
	      150级快活十三掌，
	      150级别基本掌法
	      2000当前内力，
	      3000最大内力，
	      1000当前精力，
	      后天30点膂力

		set 暴风骤雨 暴风
		set 暴风骤雨 骤雨

HELP
	);
	return 1;
}
