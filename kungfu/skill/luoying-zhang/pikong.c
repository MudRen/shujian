// By Darken@SJ
// Modified by Numa@Sj 99-11-12 2:46
// Modified by Darken@SJ

inherit F_SSERVER;
#include <ansi.h>
#include <combat_msg.h>

string perform_name() { return HIG"落英劈空掌"NOR; }

int perform(object me, object target)
{
        int damage, p;
        string msg;
        
        if (!target) target = offensive_target(me);
        if (!objectp(target)) return notify_fail("你想劈谁？\n");
        if (wiz_level(me) < wiz_level(target))
                return notify_fail("你不能攻击巫师等级比你高的对手。\n");
        if (target == me)
                return notify_fail("用 suicide -f 指令会比较快些。\n");
         if( target->is_corpse() ) 
                return notify_fail("有个性，玩尸体。\n");
        if (!target || !target->is_character())
                return notify_fail("你想攻击谁？\n");
        if (me->query_temp("weapon"))
                return notify_fail("你拿着武器怎么能使用劈空掌！\n");   
        if (environment(me)->query("no_fight") )
                return notify_fail("这里不能战斗。\n");
        if ((int)me->query_dex() < 50)
                return notify_fail("你的身法不够，无法配合劈空掌。\n");
        if ((int)me->query_skill("bihai-chaosheng", 1) < 200 )
                return notify_fail("你的碧海潮生功修为未到，无法打出劈空掌。\n");
        if ((int)me->query_skill("luoying-zhang",1) < 200 )
                return notify_fail("你的掌法修为不足，使不出劈空掌。\n");
        if ((int)me->query("max_neili") < 5000)
                return notify_fail("你现在内力太弱，不能打出劈空掌。\n");
        if ((int)me->query("jiali") < 100)
                return notify_fail("你现在加力太弱，不能打出劈空掌。\n");
        if (me->query_skill_prepared("strike") != "luoying-zhang" || me->query_skill_mapped("strike") != "luoying-zhang")
                return notify_fail("你准备的技巧不对！\n");
        if (me->query_skill_mapped("force") != "bihai-chaosheng")
                return notify_fail("你激发的内功不对！\n");
     if( me->query("no_pk") && userp(target) && (!me->query_temp("xyjob") || !target->query_temp("xyjob")))
     return notify_fail("你已经退出江湖，还是老老实实的吧。\n");

     if( target->query("no_pk") && userp(me) && (!me->query_temp("xyjob") || !target->query_temp("xyjob")))
     return notify_fail( target->name()+"已经退出江湖了，得饶人处且饶人吧！\n");
if (userp(target) && userp(me) && me->query("combat_exp")<  target->query("combat_exp") * 2 /3 &&  !target->query_condition("killer") && !target->is_killing(me->query("id")) ) 
                 return notify_fail("人家比你强这么多，你就不怕人家报复？\n");

if (userp(target) && userp(me) && me->query("combat_exp") > target->query("combat_exp") * 3 / 2 &&  !target->query_condition("killer") && !target->is_killing(me->query("id"))) 
                 return notify_fail("你比人家强这么多，这种小虾米也值得你动手？\n");

        me->start_perform(3,"劈空掌");
        msg = HIB "\n$N长啸一声，一式劈空掌向$n击到，落英神剑掌风挟带著澎湃汹涌的碧海潮生功蜂拥而至，其势殊不可挡！\n"NOR;
        if (random(me->query_dex()) > target->query_dex()/2)
        {
                me->start_busy(1);
                target->start_busy(1+random(3));
                damage = (int)me->query_skill("force") + (int)me->query_skill("strike") + me->query("jiali")*5;
                if (damage > 1500 + me->query("thd/is_fast")*3) damage = 1500 + me->query("thd/is_fast")*3;
                if (target->query("neili") < me->query("neili")) damage *= 2;
                if (me->is_fighting()) damage *= 3/4;
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/2, me);
                me->add("neili", -damage/2);
                if (me->query("neili") < 0) me->set("neili",0);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += HIG"$n的胸口如同受到一记重锤，口中登时鲜血狂喷。\n"NOR;
                msg += "( $n"+eff_status_msg(p)+" )\n"; 
                me->kill_ob(target);
        }
        else {
                msg += CYN"$n见掌势猛烈，急忙向旁一让，$N这一掌便即落空。\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

int help(object me)
{
        write(HIG"\n「落英劈空掌」："NOR"\n");
        write(@HELP

        劈空掌乃是桃花各特殊技巧中，唯一重于强力内劲的直接打击。由於此举全
        靠浑厚内功支持来达到远距离攻击的效果，因此内力消耗极大，同时攻击时
        的加力多寡也成为效果的关键。

        要求：  碧海潮生功等级 200 以上；
                落英神剑掌等级 200 以上；
                后天身法 50 以上；
                最大内力 5000 以上；
                在战斗中使用时威力下降；
                内力超过对手时威力提升；
                配合奇门五转使用时命中提升。
HELP
        );
        return 1;
}

