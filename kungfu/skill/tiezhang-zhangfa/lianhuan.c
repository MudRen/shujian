// lianhuan.c  夺命连环掌
// Create by lsxk@hsbbs 2007/5/15

#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;

string perform_name(){ return CYN"夺命连环掌"NOR; }

void remove_effect(object me, int improve);

int perform(object me, object target)
{
        int lev;
         lev = ((int)me->query_skill("tiezhang-zhangfa", 1) + (int)me->query_skill("strike", 1))/2;
       if(!userp(me)) lev = lev / 4;
        if( !target ) target = offensive_target(me);

        if( !target 
          || !me->is_fighting(target)
          || !objectp(target)
          || environment(target)!= environment(me))

                return notify_fail("「夺命连环掌」绝技只能在战斗中使用。\n");

        if( me->query_temp("weapon"))

                return notify_fail("你拿着武器怎么能使用「夺命连环掌」绝技?\n");   


        if( (int)me->query_skill("tiezhang-zhangfa", 1) < 100 )
                return notify_fail("你的铁掌掌法还不够娴熟，使不出「夺命连环掌」绝技。\n");

        if (me->query_skill_prepared("strike") != "tiezhang-zhangfa"
        || me->query_skill_mapped("parry") != "tiezhang-zhangfa"
        || me->query_skill_mapped("strike") != "tiezhang-zhangfa")
                return notify_fail("你现在无法使用「夺命连环掌」绝技进行攻击。\n");  

        if( (int)me->query_skill("force", 1) < 100)
                return notify_fail("你的基本内功等级还不够，使不出「夺命连环掌」绝技。\n");

        if( me->query("max_neili") < 1500)
                return notify_fail("你现在内力修为太差，使不出「夺命连环掌」。\n"); 

        if( (int)me->query("neili") < 800 )
                return notify_fail("你现在真气太弱，使不出「夺命连环掌」。\n"); 

        if( (int)me->query("max_jingli") < 1000)
                return notify_fail("你现在精力修为太差，使不出「夺命连环掌」。\n"); 

        if( (int)me->query("jingli") < 600 )
                return notify_fail("你现在精力太差，使不出「夺命连环掌」。\n"); 

        message_vision(HIM"\n$N突然大喝一声，运掌如风，双掌连环拍出，正是铁掌掌法之精髓「夺命连环掌」绝技！\n"NOR,me);

        me->add_temp("apply/strike", lev/10);
        me->add_temp("apply/attack", lev/4);
        me->add_temp("apply/strength",(int)me->query("str"));
        me->add_temp("apply/damage", lev/3);
        me->set_temp("tiezhang", 1);
if(!userp(target) ) 
             target->start_busy(1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), (lev>449)?3:1);
        if(me->is_fighting(target)) COMBAT_D->do_attack(me, target, me->query_temp("weapon"), (lev>449)?3:1);
        if(me->is_fighting(target)) COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        if(me->is_fighting(target)) COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        me->add_temp("apply/strike", -lev/10);
        me->add_temp("apply/attack", -lev/4);
        me->add_temp("apply/strength",-(int)me->query("str"));
        me->add_temp("apply/damage", -lev/3);

if(target) target->delete_temp("must_be_hit");
        me->start_busy(1+random(2));
        me->start_perform(2+random(2),"「夺命连环掌」");
        me->add("neili", -500);
        me->delete_temp("tiezhang");
        return 1;
}
