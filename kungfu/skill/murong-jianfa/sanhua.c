// modified by snowman@SJ 05/12/2000
// Modify By River@Sj

#include <ansi.h>
inherit F_SSERVER;
#include <combat_msg.h>

int next1(object me, object target, int i);
int next2(object me, object target, int i);

int perform(object me,object target)
{
        object weapon;
        string msg;
        int i = me->query_skill("douzhuan-xingyi",1) / 4;
        int ap,dp;

        if( !target ) target = offensive_target(me);

        if( !objectp(target)
         || !me->is_fighting(target) 
         || !living(target)
         || environment(target)!=environment(me))
                return notify_fail("天女散花只能对战斗中的对手使用。\n");

        if(me->query_skill_mapped("force") != "shenyuan-gong")
                return notify_fail("你的内功不是神元功，无法使用天女散花！\n");

        if( me->query_skill("shenyuan-gong", 1) < 120 )
                return notify_fail("你的内功还未练成，不能使用天女散花！\n");

        if( me->query_skill("murong-jianfa", 1) < 120 )
                return notify_fail("你的剑法还未练成，不能使用天女散花！\n");

        if (!objectp(weapon = me->query_temp("weapon")) 
        || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "murong-jianfa")
                return notify_fail("你手里没有剑，无法使用天女散花！\n");

        if(me->query_skill_mapped("parry") != "murong-jianfa"
        && me->query_skill_mapped("parry") != "douzhuan-xingyi")
      
                return notify_fail("你的招架功夫不对，无法使用天女散花！\n");
        if(me->query("max_neili") < 1200 )
                return notify_fail("你的内力修为不够，不能使用天女散花！\n");
        if(me->query("neili") < 1000 )
                return notify_fail("你现在真气不足，不能使用天女散花！\n");
        if(me->query("jingli") < 600 )
                return notify_fail("你现在精力不足，不能使用天女散花！\n");
        if(me->query_temp("sanhua"))
                return notify_fail("你正在使用天女散花！\n");

        if(me->query_skill("sword", 1) < 120 )
                return notify_fail("你的基本剑法不够娴熟，不能在剑招中使用天女散花。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        msg = HIG"\n$N使出「天女散花」，点点剑光直飞$n全身各大要穴。\n"NOR;
        me->start_perform(3, "「天女散花」");
        ap = me->query("combat_exp", 1) * me->query_int(1);
        dp = target->query("combat_exp", 1) * target->query_int(1);
        i = random(i/8) + 3;
        if ( i > 5 ) i = 5;
        if( random(ap + dp ) > dp ||( me->query_skill("murong-jianfa",1)>= 451 && userp(me) && random(ap+dp)>dp/3 )  ) {
                msg += MAG "结果$n被$N攻了个措手不及。\n" NOR;
                target->add_busy(i);
                me->set_temp("sanhua", 1);
                me->add("neili", -150);
        }
        else {
                me->add("neili", -80);
                msg += MAG "可是$n看破了$N的企图，并没有上当。\n" NOR;
                me->start_busy(random(2));
        }
        message_vision(msg, me, target);
        if ( me->query_skill("murong-jianfa", 1) > 140)
                next1(me, target, i);
        else 
                me->delete_temp("sanhua");
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
                me->delete_temp("sanhua");
                return 0;
        }
        msg = HIR"\n紧跟着$N剑锋一转，欺身近前，从不可思议的角度刺向$n的" + HIY"「命门穴」"HIR + "。\n"NOR;
        ap = me->query("combat_exp", 1) * me->query_con(1);
        dp = target->query("combat_exp", 1) * target->query_con(1);
        if( random(ap + dp ) > dp ||( me->query_skill("murong-jianfa",1)>=451 && userp(me) && random(ap+dp)>dp/3 )  ) {
                msg += CYN"$n只觉全身真气由「命门穴」狂泻而出。\n"NOR;
                damage = me->query_skill("murong-jianfa",1);
                damage += me->query_skill("sword")* 3;
                damage += random(damage);
                if ( me->query_skill("murong-jianfa",1)<=250 && damage > 3500 )
                        damage = 3500 + (damage - 3500)/10;
                target->add("neili",-(300+random(150)));
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/3, me);
                msg += damage_msg(damage, "刺伤");
                msg = replace_string(msg, "$w", weapon->name());
                msg = replace_string(msg, "$l", "「命门穴」");
                message_vision(msg, me, target);
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"你对"+ target->query("name") +"造成了"HIR+damage+ WHT"点攻击伤害。\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"的攻击对你造成了"HIR+damage+ WHT"点伤害。\n"NOR);
                COMBAT_D->report_status(target, random(2));
                me->add("neili",-200);
                me->add("jingli",-80);
                me->start_perform(3, "「天女散花」");
        }
        else {
                msg  += CYN"$n一个懒驴打滚，危急之中躲过致命一击。\n"NOR;
                message_vision(msg, me, target);
                me->add("neili", -80);
                me->add_busy(random(2));
        }
        if (me->query_skill("murong-jianfa", 1) > 160)
                next2(me, target, i);
        else
                me->delete_temp("sanhua");
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
                me->delete_temp("sanhua");
                return 0;
        }
        msg = HIC"\n就在$n疲于防守之际，$N又风驰电掣地刺出第三剑。\n"NOR;
        ap = me->query("combat_exp", 1) * me->query_str(1);
        dp = target->query("combat_exp", 1) * target->query_str(1);
        if( random(ap + dp ) > dp ||( me->query_skill("murong-jianfa",1)>=451 && userp(me) && random(ap+dp)>dp/3 )  ) {
                msg += HIW "结果一剑正刺中$n的" + HIR"「檀中穴」"HIW + "。\n"NOR;
                damage = me->query_skill("murong-jianfa",1)*3;
                damage += me->query_skill("sword",1)*2;
                damage += random(damage);
                if ( damage > 5000 )
                        damage = 5000 + (damage - 5000)/10;
if(me->query_skill("murong-jianfa",1)>=450 ) damage *=3/2;
                target->add_temp("apply/attack", -80);
                target->add_temp("apply/dodge", -80);
                target->add_temp("apply/parry", -80);
                 if( damage > target->query("qi") ) 
 { damage= target->query("qi")-1;
    target->start_busy(5);
   }
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/3, me);
                msg += damage_msg(damage, "刺伤");
                msg = replace_string(msg, "$w", weapon->name());
                msg = replace_string(msg, "$l", "「檀中穴」");
                message_vision(msg, me, target);
                COMBAT_D->report_status(target, random(2));
                me->add("neili",- 150);
                me->add("jingli",-80);
                me->start_perform(3 + random(2),"「天女散花」");
                call_out("back", 5 + random(me->query("jiali") / 20), target);
        } 
        else {
                msg = msg + HIW "$n一个旱地拔葱，跃起数丈，堪堪避过。\n" NOR;
                message_vision(msg, me, target);
                me->add("neili", -70);
                me->add_busy(random(2));
        }
        me->delete_temp("sanhua");
        return 1;
}

void back(object target)
{
        if (!target) return;
        target->add_temp("apply/attack", 80);
        target->add_temp("apply/dodge", 80);
        target->add_temp("apply/parry", 80);
}

string perform_name(){ return HIG"天女散花"NOR; }
int help(object me)
{
        write(HIG"\n慕容剑法之「天女散花」："NOR"\n\n");
        write(@HELP
        要求：  当前内力 1000 以上；
                最大内力 1200 以上；
                当前精力 600 以上；
                慕容剑法等级 120 以上；
                神元功等级 120 以上；
                基本剑法等级 120 以上；
                激发剑法为慕容剑法；
                激发招架为慕容剑法、斗转星移或参合指；
                激发内功为神元功。
HELP
        );
        return 1;
}
