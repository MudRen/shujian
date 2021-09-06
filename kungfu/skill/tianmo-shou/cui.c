// cui.c 催魂

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me,object target)
{
        string msg;
        object weapon;
        int ap, dp, damage;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }



        if (! target || ! me->is_fighting(target))
                return notify_fail("「催魂」只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon"))
                return notify_fail("你只能空手使用「催魂」绝技。\n");

        ap = me->query_skill("tianmo-shou", 1);

        if (ap < 150)
                return notify_fail("你的天魔手等级不够, 无法使用「催魂」！\n");

        if (me->query("neili") < 150)
                return notify_fail("你的真气不够，无法运用「催魂」！\n");

        msg = HIR "$N" HIR "步法忽变，左右横跨数步，口中发出长短不一的啸声，配合着一种奇异的旋律，双手向$n" HIR
              "缓缓拍到。\n" NOR;

        dp = target->query_skill("parry", 1);
        if (dp < 1)  dp = 1;
        if (ap / 2 + random(ap) > dp || random(me->query_con(1)) > target->query_int(1)/2)
        {
                me->add("neili", -120);
                damage = ap + (int)me->query_skill("force", 1);
                damage = damage * 2 + random(damage * 2);
if(userp(target)) damage = damage /3;
                target->receive_damage("jing", damage, me);
                target->receive_wound("jing", damage/3, me);
                msg +=                     HIR "$n" HIR "正自惊疑，不及闪避，登时被"
                                           "拍个正着。顿觉啸声直刺入脑，精神不济，摇摇欲倒！\n" NOR;
                target->start_busy(2 + random(2));
                me->start_busy(1);
        } else
        {
                me->add("neili", -50);
                msg += CYN "$n" CYN "听得笑声有异，忽感眩晕，连忙一咬舌尖，精神一振，奋力化解了$N"
                       CYN "这一招。\n"NOR;
                 me->start_busy(3+random(2));
       
        }

   message_vision(msg, me, target);
 me->start_perform(3,"催魂魔音");

        return 1;
}

