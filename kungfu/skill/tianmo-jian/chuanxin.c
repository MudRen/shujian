// chuanxin.c һ������

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
                return notify_fail("��һ�����ġ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        ap = me->query_skill("tianmo-jian",1);

        if (ap < 250)
                return notify_fail("�����ħ�����ȼ�����, ����ʹ�á�һ�����ġ���\n");

        if (me->query("neili") < 300)
                return notify_fail("��������������޷����á�һ�����ġ���\n");

        msg = HIC "$N" HIC "һ����Х��˫��һ��������������Ӽ�ת��Ȧ�������е�"
              + weapon->name() + HIC + "��Ϊһ�壬����һ���׹⣬�������һ���ֱ��$n" HIC
              "������\n" NOR;
   message_vision(msg, me, target);
        dp = target->query_skill("force", 1);
        exp = (int)me->query("combat_exp") / (int)target->query("combat_exp");
        if (dp < 1)  dp = 1;
        if (ap / 2 + random(ap) > dp || !living(target))
        {
                me->add("neili", -220);
                damage = ap + (int)me->query_skill("xixing-dafa", 1);
                damage = damage * 2 + random(damage * 2);


 msg = HIR"����$Nһ����ȣ����ţ�����"+weapon->name()+HIR"�Ѿ���$n�ؿڶԴ�������һ��Ѫ�����������\n"NOR;
   
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
                msg += HIG "����$n" HIG "���з���������һת���ѱܿ���$N"
                       HIG "��ȫ��һ����\n"NOR;
                me->start_busy(3);
        }
   message_vision(msg, me, target);
 me->start_perform(3, "���񽣴��ġ�");

     return 1;
}

