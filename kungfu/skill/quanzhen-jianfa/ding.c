// ding. 定阳针
// Modified by action@SJ
#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;

string perform_name() {return HIB"定阳针"NOR;}

int perform(object me, object target)
{        
        object weapon;
        int damage,p,force;
        string msg, *limbs;
        weapon = me->query_temp("weapon");

        if( !target) target = offensive_target(me);

        if( !objectp(target)
         || !me->is_fighting(target) 
         || !living(target)
         || environment(target)!=environment(me))
                return notify_fail("「定阳针」只能在战斗中对对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");    

        if( (int)me->query_skill("xiantian-gong",1) < 100 )
                return notify_fail("你的先天功等级不够，不能施展「定阳针」！\n");

        if( (int)me->query_skill("force", 1) < 100 )
                return notify_fail("你的基本内功等级不够，不能施展「定阳针」！\n");
                
        if ((int)me->query_skill("quanzhen-jianfa", 1) < 100)
                return notify_fail("你的全真剑法不够娴熟，不能使用「定阳针」。\n");
                
        if (me->query_skill_mapped("sword") != "quanzhen-jianfa")
                return notify_fail("你没有激发全真剑法，不能使用「定阳针」。\n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("你的真气不足，不能施展「定阳针」！\n");

        if( (int)me->query("max_neili") < 1000 )
                return notify_fail("你的内力不足，不能施展「定阳针」！\n");

        if( (int)me->query("jingli") < 300 )
                return notify_fail("你的精力不足，不能施展「定阳针」！\n");

        if( target->is_busy()) 
                 return notify_fail("对方正自顾不暇呢，你不忙施展「定阳针」！\n");

        me->start_perform(2, "「定阳针」");

        force = me->query_skill("force") + me->query_skill("xiantian-gong", 1)/10;
        tell_object(me,HIW"你左手捏着剑诀，右足踏开一招「"HIR"定阳针"HIW"」向上斜刺，"+weapon->name()+""HIW"锵然跃出，倏的化作几点星光，射向"+target->name()+"！\n"NOR);
        if(random(force) > target->query_skill("force")/3){
           damage = force;
           damage += random(damage);
           if(target->query_skill("force") - 50 > force)
             damage = damage/2;
           if(target->query_skill("force") > (force)*2)
              damage = random(10);
           if((force) > target->query_skill("force")*2)
              damage = damage+random(damage);
             if (damage > 1500) damage = 1500;
           if(damage > 300)
              tell_object(target, HIB"\n突然之间，你胸口一痛，似乎被一枚极细的尖针刺了一下。这一下刺痛\n"+
                                     "突如其来，似有形，实无质，一股剑气突破你的护体神功，直钻入心肺！\n"NOR);            
           target->receive_damage("qi", damage, me);
           target->receive_wound("qi", damage/3, me);
           me->receive_damage("neili", damage/3);
           limbs = target->query("limbs");
           p = (int)target->query("qi")*100/(int)target->query("max_qi");
           tell_room(environment(target), HIR + target->name()+"忽感全身像被针刺了一样，一阵一阵的麻！\n" NOR, ({ target }));  
           msg = damage_msg(damage, "内伤");
           msg += "( $n"+eff_status_msg(p)+" )\n";
           message_vision(msg, me, target);
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"你对"+ target->query("name") +"造成了"RED+ damage+ WHT"点攻击伤害。\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"的攻击对你造成了"RED+ damage+ WHT"点伤害。\n"NOR); ;
           me->start_busy(1);
           me->add("jingli", -20);
           target->start_busy(2+random(4));
           return 1;
        }        
        else {
           me->add("neili", -50);
           me->add("jingli", -5);
           tell_object(me, HIY"可是"+target->name()+"看破了你的企图，斜跃避开了攻击。\n"NOR);
           me->start_busy(2);         
        }
        return 1;
}

