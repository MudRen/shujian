// chuanxin.c 一剑穿心

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me,object target)
{
     string msg;
        object weapon;
        int ap, dp, damage, exp;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

            if (! target || ! me->is_fighting(target))
                return notify_fail("「一剑穿心」只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        ap = me->query_skill("tianmo-jian",1);

        if (ap < 250)
                return notify_fail("你的天魔剑法等级不够, 不能使用「一剑穿心」！\n");

        if (me->query("neili") < 300)
                return notify_fail("你的真气不够，无法运用「一剑穿心」！\n");

        msg = HIC "$N" HIC "一声长啸，双足一点已纵身而起，身子急转数圈，与手中的"
              + weapon->name() + HIC + "合为一体，化作一道白光，如箭离弦一般笔直向$n" HIC
              "射来。\n" NOR;
   message_vision(msg, me, target);
        dp = target->query_skill("force", 1);
        exp = (int)me->query("combat_exp") / (int)target->query("combat_exp");
        if (dp < 1)  dp = 1;
        if (ap / 2 + random(ap) > dp || !living(target))
        {
                me->add("neili", -220);
                damage = ap + (int)me->query_skill("xixing-dafa", 1);
                damage = damage * 2 + random(damage * 2);


 msg = HIR"但听$N一声清喝：「着！」，"+weapon->name()+HIR"已经在$n胸口对穿而过，一股血箭疾射而出！\n"NOR;
   
            target->receive_damage("qi", damage);
            target->receive_wound("qi", damage*2/3);

                me->start_busy(2 + random(2));
                if (exp > 3)
                {
    message_vision(msg, me, target);
                      target->die(me);
                      return 1;
                }
        } else
        {
                me->add("neili", -60);
                msg += HIG "可是$n" HIG "早有防备，身形一转，已避开了$N"
                       HIG "的全力一击。\n"NOR;
                me->start_busy(3);
        }
   message_vision(msg, me, target);
 me->start_perform(3, "「神剑穿心」");

     return 1;
}

