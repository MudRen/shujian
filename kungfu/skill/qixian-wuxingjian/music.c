// music.c
// modified by action@SJ 2009/1/10
// updated BY Zmud@Sjmud 10/3/2009
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg, dodge_skill;
	object weapon;
	int ap, dp,i;

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	|| !target->is_character()
	|| !me->is_fighting(target)
	|| !living(target) )
		return notify_fail("「无弦音律」只能对战斗中的对手使用。\n");

	if( (int)me->query_skill("qixian-wuxingjian", 1) < 300 )
		return notify_fail("你的七弦无形剑等级不足，无法使用「无弦音律」。\n");

	if( (int)me->query_skill("sword", 1) < 300 )
		return notify_fail("你的基本剑法等级不足，无法使用「无弦音律」。\n");

	if( (int)me->query_skill("xixing-dafa", 1) < 300 )
		return notify_fail("你的基本内功等级不足，无法使用「无弦音律」。\n");

	if( (int)me->query("max_neili") < 8000 )
		return notify_fail("你的内力不足，无法使用「无弦音律」。\n");

	if( (int)me->query("neili") < 5000 )
		return notify_fail("你的真气不够。\n");		

	if( me->query_skill_mapped("force") != "xixing-dafa" )
		return notify_fail("你现在使用的特殊内功不对，无法使用「无弦音律」？\n");

	if( !objectp(weapon = me->query_temp("weapon"))
	 || weapon->query("skill_type") != "sword"
	 || me->query_skill_mapped("sword") != "qixian-wuxingjian"
	 || me->query_skill_mapped("parry") != "qixian-wuxingjian" )
		return notify_fail("手中无剑，你如何使得了「无弦音律」？\n");
	
	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");
		
	ap = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK) + me->query("combat_exp")/2;
	dp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE) + target->query("combat_exp")/2;

	ap += me->query_int(1) * me->query_dex(1) * 1000;
	dp += target->query_int(1) * target->query_con(1) * 1000;

	if( me->query_skill("qixian-wuxingjian", 1) > 300 )
		ap += random(ap/2);
msg = "\n  "HIB"$N气定神闲，手指往" + weapon->name() +HIB"轻轻一弹，" + weapon->name() +HIB"旋即发出一阵震耳欲聋的高频音律，让四周之人感觉天旋地暗！\n"NOR;
message_vision(msg, me, target);  
                   
msg = HIR"\n在" + weapon->name() +HIR"上拨弦发声，并非故示闲暇，却是在琴音之中灌注上乘内力，用以扰乱"+
"\n敌人心神，$n内力和琴音一生共鸣，便不知不觉自己招式已为琴音所制。\n"NOR;


	if ( random( ap + dp ) > dp ) {
		msg += HIM "\n$n只觉得$N内力激荡，" + weapon->name() +HIM"发出的「"HIB"无弦音律"HIM"」犹如一柄利剑穿透$n的鼓膜。\n";
		i=random(2);
		target->add_busy(4+i+random(2));
		if( !userp(target) ) target->add_busy(random(2));
		if( target->query_temp("lost_attack") < 1 )
			target->add_temp("lost_attack", random(3));
		me->add("neili", -300);
		me->add("jingli", -100);
		me->start_perform(3 + i, "「无弦音律」");
	}
	else {
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
                msg += HIM "\n可是$n看出$N企图，急忙凝神聚气，努力使自己不受「"HIB"无弦音律"NOR+HIM"」的干扰，将$n招数化解在无形之中。\n" NOR;
		me->add("neili", -100);
		me->add("jingli", -50);
		me->start_perform(2+random(2), "「无弦音律」");
	}
	me->start_busy(1);
	message_vision(msg, me, target);
	return 1;
}

string perform_name(){ return HIB"无弦音律"NOR; }
