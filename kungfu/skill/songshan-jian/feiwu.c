// modified by darken@SJ

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int focus, i, j;
	string str;

	focus = me->query_temp("ss/focus");

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	|| !target->is_character()
	|| !me->is_fighting(target) 
	|| !living(target))
		return notify_fail("剑光飞舞只能对战斗中的对手使用。\n");

	if( me->query_skill("songshan-jian", 1) < 100 )
		return notify_fail("你的嵩山剑法功力太浅，无法使用飞舞攻击。\n");

	if( me->query_skill("sword", 1) < 100 )
		return notify_fail("你的基本剑法功力太浅，无法使用飞舞攻击。\n");

	if( me->query_skill("hanbing-zhenqi", 1) < 100 )
		return notify_fail("你的内功功力太浅，无法使用飞舞攻击。\n");
                
	if( me->query("max_neili") < 1200 )
		return notify_fail("你的内力太浅，无法使用飞舞攻击。\n");

	if( me->query("neili") < 800 )
		return notify_fail("你的真气不足，无法使用飞舞攻击。\n");

	if (me->query_skill_mapped("force") != "hanbing-zhenqi")
		return notify_fail("你用什么为基础来使嵩山剑绝技么?\n");

	if (!objectp(weapon = me->query_temp("weapon")) 
	|| weapon->query("skill_type") != "sword"
	|| me->query_skill_mapped("sword") != "songshan-jian"
	|| me->query_skill_mapped("parry") != "songshan-jian" )
		return notify_fail("你使得了嵩山剑绝技么?\n");

	i = me->query_skill("songshan-jian", 1);

	message_vision(HIB"\n$N长啸一声，举剑挺刺，在半空中划出道道剑光，空中气劲激荡，阵阵寒气向$n奔袭而去！\n" NOR,me,target);
  if(me->query_temp("ss/hb"))
	message_vision(HIB"\n$N更将「寒冰诀」发挥得淋漓尽致，身周寒光大盛！\n" NOR,me,target);

	j = i / 4;
        if ( i > 250 )  	j = to_int(i/ 4.0 * i/ 250.0);
        if ( focus > 15 ) focus = 15;
                                   	j += 5 * focus;

if(!userp(me)) j = j /4;
	me->add_temp("apply/attack", j /2);
	me->add_temp("apply/sword",  j );
  	me->add_temp("apply/damage", j );
	if(me->query_temp("ss/hb"))
        	me->add_temp("apply/damage", j);
me->set_temp("ss/fw",1);
if(!userp(target)) target->add_busy(2);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	if(me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

   if(me->is_fighting(target) && (int)me->query_skill("songshan-jian", 1) > 150 )
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	if(me->is_fighting(target)) {
			weapon->unequip(); 
                   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
			weapon->wield();
		}  
		
		
	if(me->query_temp("ss/hb"))
		    me->add_temp("apply/damage", -j);
	       me->add_temp("apply/attack",-j/2);
	       me->add_temp("apply/sword",  -j );
       	me->add_temp("apply/damage", -j );
me->delete_temp("ss/fw");
	      me->add("neili", -350);
	      me->add("jingli", -150);
       	me->start_busy(random(2));
	     me->start_perform(3+random(2), HIB"飞舞"NOR);
	return 1;
}

string perform_name(){ return HIB"飞舞"NOR; }

int help(object me)
{
        write(HIB"\n嵩山剑法之「飞舞」："NOR"\n\n");
        write(@HELP
        要求：  当前内力 800 以上；
                最大内力 1200 以上；
                当前精力 500 以上；
                嵩山剑法等级 100 以上；
                寒冰真气等级 100 以上；
                基本剑法等级 100 以上；
                激发剑法为嵩山剑法；
                激发招架为嵩山剑法；
                激发内功为寒冰真气；
                且手持兵器。

HELP
        );
        return 1;
}
