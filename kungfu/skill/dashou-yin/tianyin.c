// tianyin.c 密宗大手印之天印
#include <ansi.h>

inherit F_SSERVER;

string perform_name(){ return HIY"阿修罗天印诀"NOR; }

int perform(object me, object target)
{
	int lvl;
	string msg;

	if( !target ) target = offensive_target(me);


         if( !target  
          || !me->is_fighting(target)
          || !objectp(target)
          || environment(target)!= environment(me))
           return notify_fail("阿修罗天印只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用「阿修罗天印」诀！\n");		
	if((int)me->query_skill("longxiang-boruo",1)<80)
                return notify_fail("你的龙象般若功修为不够。\n");	
        if( (int)me->query_skill("dashou-yin", 1) < 80 )
		return notify_fail("你的密宗大手印修为不够，不能使用「阿修罗天印」诀。\n");
        if((int)me->query("max_neili",1)<1000)
                return notify_fail("你的内力修为太差无法使用本势。\n");                        
        if( (int)me->query("neili", 1) < 500 )
		return notify_fail("你现在内力太弱，不能使用「阿修罗天印」诀。\n");
        if((int)me->query_skill("poison",1)<80)
            return notify_fail("你的毒技不够，无法配合送出掌毒。\n");			
	me->start_perform(5,"阿修罗天印");
	msg = HIY "$N默念愤怒咒，运起龙象般若神功，十指翻飞，双手陡然大了数倍，带着一股紫黑之气击向$n。\n"NOR;
	msg +=  "正是一招「"HIG"阿修罗无上梵天降魔宝印"NOR"」。\n\n"NOR;
           	message_vision(msg, me, target);

        if( !target->is_killing(me) ) target->kill_ob(me);

        if( target->query_temp("fanzhen")){
             msg+=HIY"$n 不闪不躲任由$N一掌击在胸口之上，只见金光一闪，$N的掌毒尽被反震击而回！\n"
                   +"$N失声惊叫：“金刚不坏体神功！”连忙收掌闪避。\n"NOR;     	
                me->add("neili", -300);
                me->apply_condition("dsy_poison", random(me->query_skill("poison")/10) + 1 );
           	message_vision(msg, me, target);
                return 1;
                    }	      



        lvl =( (int)me->query_skill("poison",1) +  (int)me->query_skill("dashou-yin", 1)+ (int)me->query_skill("longxiang-boruo",1) ) /2 ;

	me->add_temp("apply/hand", lvl);
	me->add_temp("apply/attack", lvl /3);
	me->add_temp("apply/strength", lvl /3);
	me->add_temp("apply/damage", lvl );

	if( present(target,environment(me)) && me->is_fighting(target) )
                COMBAT_D->do_attack(me, target, 0, 3);

	if( present(target,environment(me)) && me->is_fighting(target) )
                COMBAT_D->do_attack(me, target, 0, 3);

	me->add_temp("apply/hand",- lvl);
	me->add_temp("apply/attack",- lvl /3);
	me->add_temp("apply/strength",- lvl /3);
	me->add_temp("apply/damage", -lvl );

	me->start_perform(3, "阿修罗无上梵天降魔宝印");
	me->start_busy(random(2));

	return 1;



}


int help(object me)
{
        write(HIG"\n大手印「阿修罗无上梵天降魔宝印」："NOR"\n");
        write(@HELP
        阿修罗天印。以无上降魔手印及深厚龙象内力催动阿修罗血煞剧毒攻击敌人。
        要求：  最大内力  1000 以上；
                  当前内力  700 以上；
                  当前精力  500 以上；
                 大手印，龙象波若神功，毒技 均80lvl以上
HELP
        );
        return 1;
}
