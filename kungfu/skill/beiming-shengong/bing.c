// bing.c 北冥真气 之 冰心诀
// modified by action@SJ 2009/2/5

#include <ansi.h>

inherit F_SSERVER;
string exert_name(){ return HIB"冰心诀"NOR; }

int exert(object me, object target)
{
        int attackp, defendp;

        if( !target ) target = offensive_target(me);

         if( !objectp(target) || !me->is_fighting(target) )
                return notify_fail("「冰心诀」只能在战斗中使用。\n");
        if( me->query_temp("weapon"))
                return notify_fail("你拿着武器怎么能使用「冰心诀」！\n");   
                
        if( (int)me->query_skill("liuyang-zhang", 1) < 250 )
                return notify_fail("你的天山六阳掌还不够娴熟，使不出「冰心诀」绝技。\n");
                
        if (me->query_skill_prepared("strike") != "liuyang-zhang"
            || me->query_skill_mapped("strike") != "liuyang-zhang")
                return notify_fail("你现在无法使用「冰心诀」进行攻击。\n");  

        if( (int)me->query_skill("beiming-shengong", 1) < 250 )
                return notify_fail("你的北冥神功等级还不够，使不出「冰心诀」绝技。\n");
                
        if (me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("你的内功有误，无法使用「冰心诀」。\n");  
                
        
        if( (int)me->query("neili") < 3000 )
                return notify_fail("你的真气不足，不能施展「冰心诀」！\n");

        if( (int)me->query("max_neili") < 2000 )
                return notify_fail("你的内力不足，不能施展「冰心诀」！\n");

        if( (int)me->query("jingli") < 1000 )
                return notify_fail("你的精力不足，不能施展「冰心诀」！\n");

        if( target->is_busy()) 
                 return notify_fail("对方正自顾不暇呢，你不忙施展「冰心诀」！\n");
                

        attackp = me->query_skill("liuyang-zhang", 1) + me->query_skill("beiming-shengong", 1) + me->query_skill("force",1) / 3;
        defendp = target->query_skill("force") + target->query_skill("dodge");

        message_vision( HIG"$N逆运["HIB"北溟"HIG"]真气，掌中凝出无数晶莹闪烁的"HIB"冰晶"NOR+HIG"，在寒光闪耀中，向$n袭来！\n"NOR, me, target );

        if( attackp > defendp / 2 + random(defendp) / 2 || (!userp(target)&& me->query_skill("beiming-shengong")>=451 )) {
                message_vision( HIW"无数闪耀的"HIB"冰晶"HIW"围绕着$n的全身，渐渐凝聚成"WHT"冰块"NOR+HIW"，将$n冻在其中！\n"NOR, me, target );

                target->start_busy(3+random(3));
                target->apply_condition("no_fight",1+random(2));

        }
        else {
                message_vision(HIC"$n看见眼前出现一线"HIB"冰晶"NOR+HIC"向自己袭来，向左一个闪避躲开了。\n"NOR, me, target);
        }

        me->set_temp("bingxin",15+random(15));   
        me->add("neili", -200);
        me->start_busy(2);
        return 1;
}

int help(object me)
{
	write(HIW"\n北冥神功之「冰心诀」："NOR"\n\n");
        write(@HELP
	要求：  最大内力  3000 以上；
          当前内力  2000  以上；
          当前精力  1000  以上；
          北冥神功  250  级以上；
          天山六阳掌  250  级以上；
          激发掌法为天山六阳掌；
          备掌法为天山六阳掌；
HELP
        );
        return 1;
}
