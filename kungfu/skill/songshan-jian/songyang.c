// songyangjue.c by darken@SJ
// Lklv@SJ modified 2001.10.22

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon = me->query_temp("weapon");

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target) )
		return notify_fail("嵩阳诀只能对战斗中的对手使用。\n");

	if( me->query_skill("hanbing-zhenqi", 1) < 90 )
		return notify_fail("你的寒冰真气不够，无法施展嵩阳诀！\n");

	if( me->query_skill("songshan-jian", 1) < 90 )
		return notify_fail("你的剑法程度还不能使用嵩阳诀！\n");

	if( me->query_skill("songyang-shou", 1) < 90 )
		return notify_fail("你对大嵩阳手认识还不够！\n");

	if( me->query("neili") < 500 )
		return notify_fail("你的内力不够使用嵩阳诀！\n");

	if( me->query("jingli") < 300 )
		return notify_fail("你的精力不够使用嵩阳诀！\n");

	if (!weapon
	 || weapon->query("skill_type") != "sword"
	 || me->query_skill_mapped("sword") != "songshan-jian"
	 || me->query_skill_mapped("parry") != "songshan-jian" )
		return notify_fail("你必须使用嵩山剑法！\n");

	message_vision(HIW"\n$N长啸一声，剑法突变，手中剑向后一背，电石火光间猛然施展出大嵩阳手的招数！\n" NOR, me);
	me->set_temp("ssj_songyang", 2);
 if( me->query_skill("songyang-shou", 1) < 160 ) target->start_busy(1+random(1));
        me->add_temp("apply/attack", 50);
        me->add_temp("apply/damage", 150);
        me->add_temp("apply/sword", 150);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(3)?1:3);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);
	me->add_temp("apply/attack", -50);
        me->add_temp("apply/damage", -150);
        me->add_temp("apply/sword", -150); 
	me->add("neili", -200);
	me->add("jingli", -100);
	me->delete_temp("ssj_songyang");
	me->start_perform(2+random(2), "嵩阳诀");
	me->start_busy(random(2));
	return 1;
}

string perform_name(){ return HIW"嵩阳诀"NOR; }

int help(object me)
{
        write(HIW"\n嵩山剑法之「嵩阳诀」："NOR"\n\n");
        write(@HELP
        要求：  当前内力 500 以上；
                当前精力 300 以上；
                嵩山剑法等级 90 以上；
                寒冰真气等级 90 以上；
                大嵩阳手等级 90 以上；
                激发剑法为嵩山剑法；
                激发招架为嵩山剑法；
                且手持兵器。

HELP
        );
        return 1;
}
