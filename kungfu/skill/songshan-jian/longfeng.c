// longxiang.c 龙吟凤翔
// by xiaoyao 4/19/2k

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int lvl, j, focus;
        object weapon;

	lvl = me->query_skill("songshan-jian", 1) + me->query_skill("hanbing-zhenqi", 1) + me->query_skill("sword", 1) ;
	focus = me->query_temp("ss/focus") + 1;
	weapon = me->query_temp("weapon");

	if (!target ) target = offensive_target(me);


     if( !target  
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
           return notify_fail("「龙吟凤翔」只能在战斗中对对手使用。\n"); 


	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你必须使用剑才能使用「龙吟凤翔」。\n");

	if (me->query_skill("songshan-jian", 1) < 300 )
		return notify_fail("你的嵩山剑法还不够娴熟，使不出「龙吟凤翔」绝技。\n");



	if ( me->query_skill("force") < 400 )
		return notify_fail("你的内功等级不够，使不出「龙吟凤翔」绝技。\n");

	if ( me->query_str(1) < 35)
		return notify_fail("你的膂力还不够强劲，使不出「龙吟凤翔」绝技。\n");
	if ( me->query_skill_mapped("sword") != "songshan-jian"
	|| me->query_skill_mapped("parry") != "songshan-jian")
		return notify_fail("你现在的状态使不出「龙吟凤翔」绝技。\n");

	if ( me->query_temp("ss_lf"))
		return notify_fail("你正在使用「龙吟凤翔」呢！\n");

	if ( me->query("max_neili") < 2500 )
		return notify_fail("你现在内力太弱，使不出「龙吟凤翔」。\n");

	if ( me->query("neili") < 1500 )
		return notify_fail("你现在真气太弱，使不出「龙吟凤翔」。\n");

	if ( me->query("jingli") < 1000 )
		return notify_fail("你现在精力太弱，使不出「龙吟凤翔」。\n");

	msg = HIR"\n$N伸出左手拇指、食指、中指三根手指，握住了剑尖，右手一松，"+weapon->name()+HIR"突然弹起，剑柄在前，不住地晃动。\n突然$N绕着$n快速攻击，人剑合一，幻作一条金龙腾空而起，自半空中横过，剑身似曲似直，倏的罩向$n！\n\n"NOR;
	message_vision(msg, me, target);
	if(me->query_temp("ss/hb"))
			message_vision(HIB"\n$N更将「寒冰诀」发挥得淋漓尽致，身周寒光大盛！\n" NOR,me,target);

	me->set_temp("ss_lf", 1);

	if ( focus > 15) focus = 15;

	j = lvl / 15;                          //等级的1/5  

	if ( lvl > 350 )
		j = to_int( lvl/12.0 * lvl/ 350.0);  //等级的1/4加飞跃补偿
		j += focus * 3;                      //寒冰真气的效果补偿稍微削弱 
	
	if(target->is_busy()) j += j / 4;      //反PK的不二法宝 
		
  if(!userp(me)) j = j *2/ 3;          //死在这招之下的玩家不少哦。只要npc能抗住1pfm,直接反刷回来了，所以cut

		
	
	me->add_temp("apply/attack", j );
	me->add_temp("apply/sword",  j );
	me->add_temp("apply/strength",   j/5 );
		me->add_temp("apply/damage", j *2/3);


    if(me->query_temp("ss/hb"))
	me->add_temp("apply/damage", j / 4 );  //随时保持警惕,这样算下来 j = ((等级*5/16 )*(飞跃系数) +random(45)) * 5/4  ,约1/3强 

	me->add_temp("apply/damage", j /4);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	me->add_temp("apply/damage", -j/4);
	message_vision(HIR"                                                                   ※※  "HIC"龙"NOR  HIR"  ※※\n"NOR,me);

	weapon->unequip();
   COMBAT_D->do_attack(me, target, 0, 3);
	message_vision(HIR"                                                                   ※※  "HIC"吟"NOR  HIR"  ※※\n"NOR,me);

	weapon->wield();
	me->add_temp("apply/damage", j /4);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), (lvl<350)?1:3);
	me->add_temp("apply/damage", -j/4);
	message_vision(HIR"                                                                   ※※  "HIC"凤"NOR  HIR"  ※※\n"NOR,me);

	weapon->unequip();
   COMBAT_D->do_attack(me, target, 0, 3);
	message_vision(HIR"                                                                   ※※  "HIC"翔"NOR  HIR"  ※※\n"NOR,me);

	weapon->wield();

	//飞跃增加1hit
	if ( lvl > 350 ){
		me->add_temp("apply/damage", j/4);
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), (lvl<450)?1:3);
		me->add_temp("apply/damage", -j/4);
	}
	
	if(me->query_temp("ss/hb"))
	   me->add_temp("apply/damage", -j /4);
	
	      me->add_temp("apply/attack", -j );
      	me->add_temp("apply/sword",  -j );
        me->add_temp("apply/strength",   -j /5);
     		me->add_temp("apply/damage", -j *2/3);


	me->delete_temp("ss_lf");
	me->add("neili", -500);
	me->add("jingli", -200);
	me->start_busy(random(2));
   me->start_perform(4+random(2),HIR"「龙吟凤翔」"NOR);
	return 1;
}

string perform_name(){ return HIR"龙吟凤翔"NOR; }

int help(object me)
{
        write(HIR"\n嵩山剑法之「龙吟凤翔」："NOR"\n\n");
        write(@HELP
        要求：  当前内力 1500 以上；
                最大内力 2500 以上；
                当前精力 1000 以上；
                嵩山剑法等级 300 以上；
                寒冰真气等级 300 以上；
                有效内功等级 400 以上；
                激发剑法为嵩山剑法；
                激发招架为嵩山剑法；
           空手武功不限
                且手持兵器。

HELP
        );
        return 1;
}
