// wujian.c
// tiantian@sj
// modified by olives@SJ 4/31/2001
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name() {return HIB"无剑胜有剑"NOR;}

void remove_effect(object me, object weapon);
int perform(object me, object target)
{
	int skill;
	int i;
	object weapon;

	skill = (int)me->query_skill("xuantie-jianfa", 1);                

	if( !target ) target = offensive_target(me);

	if( !target || !me->is_fighting(target) )
		return notify_fail("「无剑胜有剑」只能在战斗中使用。\n");

	if(me->query_temp("wujian"))
		return notify_fail("你正在使用「无剑胜有剑」。\n");

	if(!objectp(weapon = me->query_temp("weapon")) 
	|| weapon->query("skill_type")!="sword")
		return notify_fail("你手中无剑，如何使的出玄铁剑法的绝技！\n");

 if(me->query_skill("sword",1) <=550) 
	if(weapon->query("unique")|| !userp(me) )
		return notify_fail("你如此依赖宝剑，如何能领会「无剑胜有剑」的意境?\n");

	if( (int)me->query_skill("xuantie-jianfa", 1) < 200 ) 
		return notify_fail("你的玄铁剑法不够娴熟，不会使用「无剑胜有剑」。\n");
		
	if( (int)me->query_skill("force", 1) < 200 )
		return notify_fail("你的基本内功等级不够，不能使用「无剑胜有剑」。\n");

if( me->query_skill("sword",1) <=550 )
    	if (me->query_skill_mapped("sword") != "xuantie-jianfa" )
		return notify_fail("你现在无法使用「无剑胜有剑」。\n");

        if( me->query_skill_mapped("force") != "yunu-xinjing" && userp(me))
                return notify_fail("你现在无法使用「无剑胜有剑」！\n");
	if( me->query("max_neili")<3000)
		return notify_fail("你的内力修为太差，不能使用「无剑胜有剑」。\n");
	if( (int)me->query("neili") < 3000 )
		return notify_fail("你现在内力太弱，不能使用「无剑胜有剑」。\n");

 if(me->query_skill("sword",1) <=550) 	me->start_perform(1,"「无剑胜有剑」");

	message_vision(HIB "\n$N将内力灌注剑上，纯以意气运剑，但觉天地间无一不可为剑，渐入「无剑胜有剑」的境界。\n" NOR, me, target);
        i=(me->query_skill("xuantie-jianfa",1)+me->query_skill("force",1))/6;
	i=i+random(i);
	if(i>160) i=160+(i-160)/10;
	me->add("neili",-i*2);
	me->add_temp("apply/damage",i);
	me->set_temp("wujian",i);
	call_out("check_fight",1,me,weapon);
	return 1;
}

void check_fight(object me, object weapon) 
{ 
	if(!me
	|| !living(me)
	||  me->is_ghost()
	|| !me->is_fighting()
	|| !me->query_temp("weapon")
	||  me->query_temp("weapon") != weapon) 
	{
		remove_effect(me,weapon);
		return;
	}
            call_out("check_fight", 1, me, weapon); 
} 

void remove_effect(object me, object weapon)
{
	int lvl;

	if (!me)
		return;
	lvl = me->query_temp("wujian");
	me->add_temp("apply/damage",-lvl);
	me->delete_temp("wujian");
	if (!weapon) {
		me->set_temp("last_damage_from", "作弊失败被惩罚");
    	me->unconcious();
		return;
	}

}

int help(object me)
{
        write(HIB"\n玄铁剑法「无剑胜有剑」："NOR"\n\n");
        write(@HELP
        要求：  当前内力 3000 以上；
                最大内力 3000 以上；
                玄铁剑法等级 200 以上；
                玉女心经等级 200 以上；
                有效内功等级 200 以上；
                激发剑法为玄铁剑法；
                激发招架为玄铁剑法。

                当等级低于550级时装备宝物兵器无法使用。

HELP
        );
        return 1;
}
