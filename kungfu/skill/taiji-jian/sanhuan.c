// sanhuan.c for tjj
// Created and Modified by snowman@SJ 23/02/2001

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int i, j, lvl = me->query_skill("taiji-jian", 1);

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target)
	 || !living(target) )
		return notify_fail("「三环套月」只能对战斗中的对手使用。\n");

	if( me->query_temp("tjj/lian") )
		return notify_fail("你正在使用连。\n");
 
        if( (int)me->query_skill("taiji-jian", 1) < 150 )
		return notify_fail("你的太极剑法功力太浅，别做梦了。\n");
 
        if( (int)me->query_skill("sword", 1) < 150 )
		return notify_fail("你的基本剑法功力太浅，别做梦了。\n");

	if( (int)me->query_temp("tjj/chan") )
		return notify_fail("你现在正在使用「缠」字诀。\n");

        if( (int)me->query_skill("yinyun-ziqi", 1) < 150 )
		return notify_fail("你的内功功力太浅，别做梦了。\n");

        if( (int)me->query("max_neili") < 2500 )
		return notify_fail("你的内力太浅，别做梦了。\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("你的真气不够，别做梦了。\n");
/*
	if( me->query_skill_mapped("force") != "yinyun-ziqi" )
		return notify_fail("你用什么为内功基础来使「三环套月」?\n");
*/
	if( !objectp(weapon = me->query_temp("weapon"))
	 || weapon->query("skill_type") != "sword"
	 || me->query_skill_mapped("sword") != "taiji-jian" )
		return notify_fail("你使得了「三环套月」么?\n");

  	j = lvl /2; //原1/3
	if ( lvl > 449 )
		j = to_int(lvl * lvl/825);

if(!userp(me)) j = j/3;
	me->set_temp("tjj/sanhuan", 3);
	me->add_temp("apply/sword", j/3);
        me->add_temp("apply/attack", j*2/3);
        me->add_temp("apply/damage", j*2/3);
	if( wizardp(me) )
           tell_object(me, "你的「"HIW"三环套月"NOR"」增加：有效剑法 "+j+"；命中率 "+j+"；伤害 "+j/4+"。\n"NOR);

	if( ( weapon->query("material") == "wood"
	   || weapon->query("material") == "bamboo"
          ||weapon->query("id") == "songwen jian"
           || weapon->query("material") == "paper" )
           || weapon->query("weapon_prop/damage") < 20 
           || weapon->query("weapon_prop/damage") > 220 ) {
                   i =  me->query_skill("taiji-jian", 1)/3;
			me->add_temp("apply/damage", i);
                        me->add_temp("apply/attack", i);
			me->set_temp("tjj/sanhuan_damage", i);
	if( wizardp(me) ) 
                tell_object(me, "你「"HIW"三环套月"NOR"」威力加成： "+i+"。\n"NOR);
if(!userp(target)) target->add_busy(2);
            }

   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	if( me->is_fighting(target) )
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	if( me->is_fighting(target) )
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	me->add_temp("apply/sword", -j/3);
        me->add_temp("apply/attack", -j*2/3);
	me->add_temp("apply/damage", -j*2/3);

	if( me->query_temp("tjj/sanhuan_damage") )
		me->add_temp("apply/damage", -me->query_temp("tjj/sanhuan_damage") );
		me->add_temp("apply/attack", -me->query_temp("tjj/sanhuan_damage") );

	me->delete_temp("tjj/sanhuan");
	me->delete_temp("tjj/sanhuan_damage");

	me->start_busy(random(2));
	me->add("neili", -300);
	me->add("jingli", -150);
	me->start_perform(3, "「三环套月」");
	return 1;
}

string perform_name(){ return HIG"三环套月"NOR; }

int help(object me)
{
        write(HIG"\n太极剑法之「三环套月」："NOR"\n\n");
        write(@HELP
        武当绝技，连续攻击三招，是武当功夫中最具攻击性的，如果使用
        武器得法，威力更甚。

        要求：  当前内力 1000 以上;
                最大内力 2500 以上；
                太极剑法等级 150 以上；
                氤氲紫气等级 150 以上；
                基本剑法等级 150 以上；
                激发剑法为太极剑法；
                激发招架为太极剑法；
                激发内功为氤氲紫气。

HELP
        );
        return 1;
}
