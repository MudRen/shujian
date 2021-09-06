// guangling.c
//updated by Zmud@Sjmud 10/3/2009

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int i, a;

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target)
	 || !living(target) )
		return notify_fail("「广陵散曲」只能对战斗中的对手使用。\n");

	if( me->query_temp("qxwxj/shan") )
		return notify_fail("你正在使用「七弦黄龙闪」。\n");
 
        if( (int)me->query_skill("qixian-wuxingjian", 1) < 120 )
		return notify_fail("你的七弦无形剑等级不足，无法使出「广陵散曲」。\n");
 
        if( (int)me->query_skill("sword", 1) < 120 )
		return notify_fail("你的基本剑法等级不足，无法使出「广陵散曲」。\n");


        if( (int)me->query_skill("xixing-dafa", 1) < 120 )
		return notify_fail("你的吸星大法等级不足，无法使出「广陵散曲」。\n");

        if( (int)me->query("max_neili") < 2500 )
		return notify_fail("你的内力修为太浅，无法使出「广陵散曲」。\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("你的真气不足，无法使出「广陵散曲」。\n");
		
		if( (int)me->query("jingli") < 1000 )
		return notify_fail("你的精力不足，无法使出「广陵散曲」。\n");

	if( me->query_skill_mapped("force") != "xixing-dafa" )
		return notify_fail("你没有使用吸星大法，无法使出「广陵散曲」?\n");

	if( !objectp(weapon = me->query_temp("weapon"))
	 || weapon->query("skill_type") != "sword"
	 || me->query_skill_mapped("sword") != "qixian-wuxingjian" )
		return notify_fail("你使得了「广陵散曲」么?\n");

        i = (int)me->query_skill("qixian-wuxingjian",1) /3 +(int)me->query_skill("xixing-dafa",1) /3;
        
        me->add("neili",-(150+random(50))); 
        me->add("jingli",-50); 
		me->set_temp("guangling",3);
        for(a=0;a<3;a++)
        {
		     if(random(2)) me->set_temp("gl_sword",1);

		     if (me->query_temp("gl_sword"))
		   {
		         me->add_temp("apply/attack", i);
                 me->add_temp("apply/sword", i);
		         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
                 me->add_temp("apply/sword", -i);
                 me->add_temp("apply/attack", -i);
                } else {
        		 me->add_temp("apply/attack", i);
		         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
                 me->add_temp("apply/attack", -i);
           }
     me->delete_temp("gl_sword");
        }
		me->delete_temp("guangling");
		me->delete_temp("gl_sword");
        me->start_perform( 3 + random(2), "「广陵散曲」");
        me->start_busy(2);
        return 1;
}

string perform_name(){ return HIM"广陵散曲"NOR; }
