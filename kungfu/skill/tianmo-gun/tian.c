// tian.c 天地旋转
// Modify by action

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return HIR"天地旋转"NOR; }
int perform(object me,object target)
{
    object weapon;
    int i,j,lev,jiali;
    
    if( !target ) target = offensive_target(me);
     
    if( !userp(me) && userp(target) )
                return notify_fail("「天地旋转」只能由玩家使用。\n");

    if( !objectp (target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("「天地旋转」只能对战斗中的对手使用。\n");

        if (me->query_skill_mapped("force") != "tianmo-gong" )
          if(me->query_skill_mapped("force") != "xixing-dafa")
                return notify_fail("你所使用的特殊内功不对。\n"); 

        if(!me->query_skill("xixing-dafa", 1))
          if(me->query_skill("tianmo-gong", 1) < 350)
                return notify_fail("以你现在的内功修为还使不出「天地旋转」。\n");  

    if( (int)me->query_skill("tianmo-gun", 1) < 350 ) 
                return notify_fail("你的日月天魔棍还未练成，无法使用「天地旋转」！\n");

    if((int)me->query_skill("club", 1) < 400 )
                return notify_fail("你的基本棍法不够娴熟，不能使用「天地旋转」！\n");

    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "club"
        || me->query_skill_mapped("club") != "tianmo-gun")
                return notify_fail("你必须使用棍法，才能使出「天地旋转」!\n");
                
   if((int)me->query_str() < 40)
           return notify_fail("你的膂力还不够强劲，使不出「天地旋转」绝技。\n");

   if(me->query_skill_mapped("parry") != "tianmo-gun")
           return notify_fail("「天地旋转」需要使用天魔棍招架。\n"); 

   if((int)me->query("max_neili") < 10000 )
           return notify_fail("你内力修为尚浅，使不出「天地旋转」。\n");  

   if( (int)me->query("neili") < 6000 )
           return notify_fail("你现在真气太弱，使不出「天地旋转」。\n");

	 message_vision(HIR"\n$N将手中"+weapon->name()+HIR+"尽力挥舞着向$n步步紧逼而来，只觉"+weapon->name()+HIR+"散发着无数日月光环。\n"NOR, me, target);

    lev = (int)me->query_skill("tianmo-gun",1)/2;
if(lev>225 ) target->add_busy(2);
    if( me->query_temp("xxdf/powerup") ) {           
           lev *= 2;
       }

    me->start_perform(3,"「天地旋转」");
   
    me->set_temp("tmg/tian", 1);
        jiali = ((int)me->query("str",1)/2 + (int)me->query("con",1))/2 + random((int)me->query("jiali")/20 );
        me->add_temp("apply/damage",  lev/2);
        me->add_temp("apply/attack",  lev);
        me->add_temp("apply/strength", jiali);
        target->add_busy(1+random(2));
        for (i=0;i<5;i++){
          j = i;
          if (i<1) j = 1;
          if (i>1) j = 3;
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"),j);
          me->add("neili", -100);  
        }
   
        me->add("neili", -200);
        me->add_temp("apply/damage",  -lev/2);
        me->add_temp("apply/attack",  -lev);
        me->add_temp("apply/strength", -jiali);

    me->delete_temp("tmg/tian");
    target->add_busy(1);
    return 1;
}

int help(object me)
{
	write(WHT"\n「天地旋转」："NOR"\n");
	write(@HELP

	要求：
		最大内力 10000 以上；
		当前内力 6000 以上；
		日月天魔棍等级 400 以上；
		吸星大法等级 400 以上；
		激发招架为日月天魔棍；
HELP
	);
	return 1;
}
