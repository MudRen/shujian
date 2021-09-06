//神鬼乱舞
//xjqx 2008/12/30

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

string perform_name(){ return HIW"神鬼乱舞"NOR; }

int perform(object me,object target)
{
    object weapon;
    int i;
    
    if( !target ) target = offensive_target(me);
     
    if( !objectp (target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("神鬼乱舞只能对战斗中的对手使用。\n");

        if (me->query_skill_mapped("force") != "tianmo-gong" )
          if(me->query_skill_mapped("force") != "xixing-dafa")
                return notify_fail("你所使用的特殊内功不对。\n");  
        if(!me->query_skill("xixing-dafa", 1))
          if(me->query_skill("tianmo-gong", 1) < 100)
                return notify_fail("以你现在的内功修为还使不出「神鬼乱舞」。\n");   
    if( (int)me->query_skill("tianmo-gun", 1) < 100 ) 
                return notify_fail("你的日月天魔棍还未练成，不能使用神鬼乱舞！\n");
    if((int)me->query_skill("club", 1) < 100 )
                return notify_fail("你的基本棍法不够娴熟，不能在使用神鬼乱舞。\n");
    if((int)me->query_dex(1) < 35 )
                return notify_fail("你的身法还不够，还不能使用神鬼乱舞。\n");
    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "club"
        || me->query_skill_mapped("club") != "tianmo-gun"
        || me->query_skill_mapped("parry") != "tianmo-gun")
                return notify_fail("你现在使得了神鬼乱舞么？\n");
                
    if((int)me->query("max_neili") < 1200 )
                return notify_fail("你的内力修为不够，不能使用神鬼乱舞！\n");
    if((int)me->query("neili") < 800 )
                return notify_fail("你现在真气不足，不能使用神鬼乱舞！\n");

        message_vision(HIW"\n$N将手中"+weapon->name()+HIW+"一阵乱舞，将$n罩在$N的乱棍之中，不能动弹。\n"NOR, me, target);

    me->start_perform(3+random(2),"「神鬼乱舞」");
    i = (int)me->query_skill("tianmo-gun",1);
        me->add("neili", -200);
        me->add_temp("apply/attack",  i/2);
        me->add_temp("apply/damage",  i/2);
        me->set_temp("tmg/lw",1);
if(i>450 ) target->add_busy(2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),(i<450)?1:3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),(i<450)?1:3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        me->add_temp("apply/attack",  -i/2);
        me->add_temp("apply/damage",  -i/2);
        me->delete_temp("tmg/lw");

    return 1;
}

int help(object me)
{
   write(WHT"\n日月天魔棍「"HIW"群魔乱舞"WHT"」："NOR"\n");
   write(@HELP

   要求：  最大内力 1200 以上；
           当前内力 800 以上；
           日月天魔棍等级 100 以上；
           吸星大法等级 100 以上；
           后天身法 35 以上；
           激发招架为日月天魔棍。

HELP
   );
   return 1;
}
