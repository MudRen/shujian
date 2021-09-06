// chuanliu.c
//xjqx@sj 2008/12/30
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int skill;
	weapon = me->query_temp("weapon");

	if( !target ) target = offensive_target(me);
	
	if( !objectp(target)
	 || !me->is_fighting(target) )
		return notify_fail("你只能在战斗中使用化身万千。\n");

	if (!objectp(weapon) || (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

        if (me->query_skill_mapped("force") != "tianmo-gong" )
          if(me->query_skill_mapped("force") != "xixing-dafa")
                return notify_fail("你所使用的特殊内功不对。\n"); 

        if(!me->query_skill("xixing-dafa", 1))
          if(me->query_skill("tianmo-gong", 1) < 150)
                return notify_fail("以你现在的内功修为还使不出「化身万千」。\n");  

	if ((int)me->query_skill("blade", 1) < 150 )
		return notify_fail("你的基本刀法极不够娴熟，不能使用化身万千！\n");

	if ( me->query_skill_mapped("blade") != "tianmo-dao"
	 || me->query_skill_mapped("parry") != "tianmo-dao" )
		return notify_fail("你现在无法使用化身万千！\n");

	if ((int)me->query("neili") < 1000 )
		return notify_fail("你现在真气太弱，不能使用化身万千！\n");

	if ((int)me->query("max_neili") < 2000 )
		return notify_fail("你现在内力太弱，不能使用化身万千！\n");

	if (me->query_temp("tmd/huashen") ) 
		return notify_fail("你已经在使用化身万千了！\n");

	message_vision(HIG"\n$N暗运起吸星大法，将手中" + weapon->name() +HIG"划出多层光影，即刻威力大增，势不可挡。\n"NOR, me);
        skill = me->query_skill("tianmo-dao",1);
	skill += random(skill);
	if ( skill > 100) skill = 100 + random(skill-100)/10;
	me->add_temp("apply/damage", skill/2);
	me->set_temp("tmd/huashen", skill);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	if ( me->query_skill("tianmo-dao", 1) > 200)
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);

	me->start_perform(3, "化身万千");
	me->add("neili", -300);
	me->start_busy(random(2));
	call_out("remove_effect", 1, me, target, weapon, skill);
	return 1;
}

void remove_effect(object me, object target,object weapon, int skill)
{
	if( !me) return;
	if(!me->is_fighting(target)
	|| ! weapon
	|| me->query_temp("weapon") != weapon
	|| me->query_skill_mapped("blade") != "tianmo-dao"
	|| me->query_skill_mapped("parry") != "tianmo-dao"){
		if( weapon)
			message_vision(HIG"$N渐渐收回刀影，威力顿时散尽！\n"NOR, me);
		me->add_temp("apply/damage", -skill/2);
		me->delete_temp("tmd/huashen");
		return;
	}
	call_out("remove_effect", 1, me, target, weapon, skill);
}

string perform_name(){ return HIG"化身万千"NOR; }

int help(object me)
{
        write(HIY"\n天魔刀之「化身万千」："NOR"\n\n");
        write(@HELP
        要求：  当前内力 1000 以上；
                天魔刀等级 150 以上；
                吸星大法等级 150 以上；
                基本刀法等级 150 以上；
                激发刀法为天魔刀；
                激发招架为天魔刀；
                激发内功为吸星大法；
                且手持兵器。

HELP
        );
        return 1;
}
