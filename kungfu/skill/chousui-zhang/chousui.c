// chousui.c 三阴抽髓
// Created and Modified by spiderii

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        
        int j, i, lvl = me->query_skill("chousui-zhang", 1);

        if( !target ) target = offensive_target(me);

        if( !objectp(target)
         || !target->is_character()
         || !me->is_fighting(target)
         || !living(target) )
                return notify_fail("「三阴抽髓」只能对战斗中的对手使用。\n");

        
        if( (int)me->query_skill("chousui-zhang", 1) < 200 )
                return notify_fail("你的抽髓掌功力太浅，别做梦了。\n");

        if( (int)me->query_skill("strike", 1) < 200 )
                return notify_fail("你的基本掌法功力太浅，别做梦了。\n");

        
        if( (int)me->query_skill("force", 1) < 200 )
                return notify_fail("你的内功功力太浅，别做梦了。\n");

       if( (int)me->query_skill("huagong-dafa", 1) < 200 )
                return notify_fail("你的化功大法太浅，别做梦了。\n");

        if( (int)me->query("max_neili") < 2500 )
                return notify_fail("你的内力太浅，别做梦了。\n");

        if( (int)me->query("neili") < 1000 )
                return notify_fail("你的真气不够，别做梦了。\n");
        if (me->query_skill_prepared("strike") != "chousui-zhang"
        || me->query_skill_mapped("strike") != "chousui-zhang"
        || me->query_skill_mapped("parry") != "chousui-zhang")
                tell_object(me,"你必须用抽髓掌才能使用「三阴抽髓」进行攻击。\n"); 
                                                                                         
        if(me->query_skill_mapped("force") != "huagong-dafa")
                tell_object(me,"你发现自己所用的内功无法进行「三阴抽髓」攻击。\n");
                
        
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用「三阴抽髓」！\n");           
        j = lvl/3;

        if ( lvl > 300 )
                j = to_int(lvl/3.0 * lvl/275.0);
        message_vision(BLU"\n$N"BLU"绕着$n快速的转了几圈，暴喝一声，掌爪互逆，几道冷风从掌端射出，袭向$n！ "BLU"！\n"NOR, me,target);

        me->set_temp("xx_chousui", 3);

        me->add_temp("apply/strike", j);
        me->add_temp("apply/attack", j);
        me->add_temp("apply/damage", j);
if(target->query_condition("xx_poison") > 180 || me->query_skill("poison",1)>180) 
{ target->add_busy(2);
 me->add_temp("apply/damage", j);
i=1;
}

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(3)?1:3);

        if( me->is_fighting(target) )
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

        if( me->is_fighting(target) )
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

if(i==1 && me->is_fighting(target) ) 
                 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        me->add_temp("apply/strike", -j);
        me->add_temp("apply/attack", -j);
        me->add_temp("apply/damage", -j);

if(i==1) me->add_temp("apply/damage", -j);

        me->delete_temp("xx_chousui");

        me->start_busy(random(2));
        me->add("neili", -300);
        me->add("jingli", -150);
        me->start_perform(3, "「三阴抽髓」");
        return 1;
}

string perform_name(){ return HIW"三阴抽髓"NOR; }

int help(object me)
{
        write(HIW"\n抽髓掌之「三阴抽髓」："NOR"\n\n");
        write(@HELP
        星宿派的功夫主要是在<毒>字上下功夫，深的阴损毒辣其中三味
        抽髓掌乃是在战斗中，凭借深厚内功把体内存毒逼出借以伤敌的
        一门功夫。「三阴抽髓」一式讲究以快打慢，一出手就是连环三
        式。如对方不解其中奥妙，甚难防御！

        要求：  当前内力 1000 以上;
                最大内力 2500 以上；
                抽髓掌等级 220 以上；
                化功大法等级 220 以上；
                基本掌法等级 220 以上；
                基本内功等级 220 以上;
                且手中无兵器。

        
HELP
        );
        return 1;
}

