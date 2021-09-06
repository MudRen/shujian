// modified by snowman@SJ 05/12/2000
// Modify By River@Sj
// Modify By jpei


#include <ansi.h>
inherit F_SSERVER;
#include <combat_msg.h>

int next1(object me, object target, int i);
int next2(object me, object target, int i);

int perform(object me,object target)
{
        object weapon;
        string msg;
        int ap,dp;
        int i = me->query_skill("haotian-zhang",1) / 2 + me->query_skill("quanzhen-jianfa",1) /2 ;

        if( !target ) target = offensive_target(me);

        if( !objectp(target)
         || !me->is_fighting(target) 
         || !living(target)
         || environment(target)!=environment(me))
                return notify_fail("三连环只能对战斗中的对手使用。\n");

        if(me->query_skill_mapped("force") != "xiantian-gong")
                return notify_fail("你的内功不是先天功，无法使用三连环！\n");

 if(me->query("quest/quanzhen/sword/lianhuan")!=1)
                return notify_fail("你虽然听说过三连环绝技，但是一直没有领悟其中诀窍，还不会运用！\n");

        if( me->query_skill("xiantian-gong", 1) < 120 )
                return notify_fail("你的内功还未练成，不能使用三连环！\n");

        if( me->query_skill("quanzhen-jianfa", 1) < 120 )
                return notify_fail("你的剑法还未练成，不能使用三连环！\n");

        if (!objectp(weapon = me->query_temp("weapon")) 
        || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "quanzhen-jianfa")
                return notify_fail("你手里没有剑，无法使用三连环！\n");
   
     if (me->query_skill_prepared("strike") != "haotian-zhang"
            || me->query_skill_mapped("strike") != "haotian-zhang")
                return notify_fail("你现在无法使用「三连环」进行攻击。\n");  

        if(me->query_skill_mapped("parry") != "quanzhen-jianfa"
        && me->query_skill_mapped("parry") != "haotian-zhang")
                return notify_fail("你的招架功夫不对，无法使用三连环！\n");

        if(me->query("max_neili") < 1200 )
                return notify_fail("你的内力修为不够，不能使用三连环！\n");
        if(me->query("neili") < 1000 )
                return notify_fail("你现在真气不足，不能使用三连环！\n");
        if(me->query("jingli") < 600 )
                return notify_fail("你现在精力不足，不能使用三连环！\n");
        if(me->query_temp("qzjf/lian"))
                return notify_fail("你正在使用三连环！\n");

        if(me->query_skill("sword", 1) < 120 )
                return notify_fail("你的基本剑法不够娴熟，不能在剑招中使用三连环。\n");


        msg = HBRED"\n$N使出「三连环」绝招，忽然剑交左手，举剑平刺，当真是星芒电闪，去势绝快！\n"NOR;
              message_vision(msg, me, target);

        me->start_perform(3, "「三连环」");
        me->add_temp("apply/attack", me->query_skill("quanzhen-jianfa",1) /3);
        me->add_temp("apply/damage", me->query_skill("quanzhen-jianfa",1) /3);
                me->set_temp("qzjf/lian", 1);
             

      COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);

        me->add_temp("apply/attack", -me->query_skill("quanzhen-jianfa",1) /3);
        me->add_temp("apply/damage", -me->query_skill("quanzhen-jianfa",1) /3);

                me->add("neili", -150);

        if ( me->query_skill("xiantian-gong", 1) > 120)
                next1(me, target, i);
        else 
                me->delete_temp("qzjf/lian");
        return 1;
}

int next1(object me, object target, int i)

{
        string msg;
        int damage, ap,dp;
        object weapon;

        if (!me) return 0;

        weapon = me->query_temp("weapon");
        if (!weapon || !target || !living(me) || !me->is_fighting(target)) {
                me->delete_temp("qzjf/lian");
                return 0;
        }
        msg = HIR"\n紧跟着$N欺身近前，一掌印在$n胸前，昊天掌掌力急吐。"NOR;
        ap = me->query("combat_exp", 1) * me->query_con(1)/10000;
        dp = target->query("combat_exp", 1) * target->query_con(1)/10000;
        if((userp(target)&& random(ap + dp) > dp/2 )|| !userp(target)){
                msg += HIR"$n只觉腾的一阵大力撞来，直撞的自己眼冒金星。\n"NOR;
                damage = me->query_skill("quanzhen-jianfa",1)*3;
                damage += me->query_skill("sword")*3;
                damage += random(damage);
                if ( damage > 3000 )
                        damage = 3000 + (damage - 1000)/10;
  
                target->add("neili",-(300+random(150)));
                target->receive_damage("qi", damage, me);

                target->receive_wound("qi", damage/3, me);
                msg += damage_msg(damage, "内伤");
                message_vision(msg, me, target);
                COMBAT_D->report_status(target, random(2));
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"你对"+ target->query("name") +"造成了"HIR+ damage+ WHT"点攻击伤害。\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"的攻击对你造成了"HIR+ damage+ WHT"点伤害。\n"NOR); 

        me->add_temp("apply/attack", me->query_skill("haotian-zhang",1) /3);
        me->add_temp("apply/damage", me->query_skill("haotian-zhang",1) /3);

        if(random(3))            target->add_condition("no_perform", 1);
        if(random(3))            target->add_condition("no_exert", 1);
           if(!userp(target))    target->add_busy(2);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);

        me->add_temp("apply/attack", -me->query_skill("haotian-zhang",1) /3);
        me->add_temp("apply/damage", -me->query_skill("haotian-zhang",1) /3);

                me->add("neili",-200);
                me->add("jingli",-80);
                me->start_perform(3, "「三连环」");
        }
        else {
                msg  += CYN"\n$n一个懒驴打滚，危急之中躲过致命一击。\n"NOR;
                message_vision(msg, me, target);
                me->add("neili", -80);
                me->add_busy(random(2));
        }
        if (me->query_skill("quanzhen-jianfa", 1) > 160)
                next2(me, target, i);
        else
                me->delete_temp("qzjf/lian");
        return 1;
}

int next2(object me, object target, int i)
{
        string msg;
        int damage, ap, dp;
        object weapon;
        if( !me ) return 0;
        weapon = me->query_temp("weapon");
        if (!weapon || !target || !living(me) || !me->is_fighting(target)) {
                me->delete_temp("qzjf/lian");
                return 0;
        }

        msg = HIC"\n就在$n疲于防守之际，$N手中长剑做势欲刺，当下却是一腿扫出！\n"NOR;
        ap = me->query("combat_exp", 1) * me->query_str(1);
        dp = target->query("combat_exp", 1) * target->query_str(1);
      if((userp(target)&& random(ap + dp) > dp)|| !userp(target)){

                damage = me->query_skill("quanzhen-jianfa",1)*5;
                damage += me->query_skill("sword",1)*2;
                damage += random(damage);
                if ( damage > 5000 )
                        damage = 5000 + (damage - 1000)/10;
   

                target->add_temp("apply/attack", -80);
                target->add_temp("apply/dodge", -80);
                target->add_temp("apply/armor", -100);
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/3, me);
                msg += damage_msg(damage, "瘀伤");

                message_vision(msg, me, target);

                COMBAT_D->report_status(target, random(2));
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"你对"+ target->query("name") +"造成了"HIR+ damage+ WHT"点攻击伤害。\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"的攻击对你造成了"HIR+ damage+ WHT"点伤害。\n"NOR); 

        me->add_temp("apply/attack", me->query_skill("xiantian-gong",1) /2);
        me->add_temp("apply/damage", me->query_skill("xiantian-gong",1) /2);

      COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);

        me->add_temp("apply/attack", -me->query_skill("xiantian-gong",1) /2);
        me->add_temp("apply/damage", -me->query_skill("xiantian-gong",1) /2);
                me->add("neili",- 150);
                me->add("jingli",-80);
                me->start_perform(3 + random(2),"「三连环」");
                call_out("back", 5 + random(me->query("jiali") / 20), target);
        } 
        else {
                msg = msg + HIW "$n一个旱地拔葱，跃起数丈，堪堪避过。\n" NOR;
                message_vision(msg, me, target);
                me->add("neili", -70);
                me->add_busy(random(2));
        }
        me->delete_temp("qzjf/lian");
        return 1;
}

void back(object target)
{
        if (!target) return;
        target->add_temp("apply/attack", 80);
        target->add_temp("apply/dodge", 80);
        target->add_temp("apply/armor", 100);
}

string perform_name(){ return HIG"三连环"NOR; }
int help(object me)
{
        write(HIG"\n全真剑法之「三连环」："NOR"\n\n");
        write(@HELP
        要求：  当前内力 1000 以上；
                最大内力 1200 以上；
                当前精力 600 以上；
                全真剑法等级 120 以上；
                先天功等级 120 以上；
                基本剑法等级 120 以上；
                激发剑法为全真剑法；
                激发招架为全真剑法或昊天掌；
                激发内功为先天功。
HELP
        );
        return 1;
}
