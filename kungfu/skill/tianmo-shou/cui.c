// cui.c �߻�

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
                return notify_fail("���߻꡹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon"))
                return notify_fail("��ֻ�ܿ���ʹ�á��߻꡹������\n");

        ap = me->query_skill("tianmo-shou", 1);

        if (ap < 150)
                return notify_fail("�����ħ�ֵȼ�����, �޷�ʹ�á��߻꡹��\n");

        if (me->query("neili") < 150)
                return notify_fail("��������������޷����á��߻꡹��\n");

        msg = HIR "$N" HIR "�������䣬���Һ�����������з������̲�һ��Х���������һ����������ɣ�˫����$n" HIR
              "�����ĵ���\n" NOR;

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
                msg +=                     HIR "$n" HIR "���Ծ��ɣ��������ܣ���ʱ��"
                                           "�ĸ����š��پ�Х��ֱ�����ԣ����񲻼ã�ҡҡ������\n" NOR;
                target->start_busy(2 + random(2));
                me->start_busy(1);
        } else
        {
                me->add("neili", -50);
                msg += CYN "$n" CYN "����Ц�����죬����ѣ�Σ���æһҧ��⣬����һ�񣬷���������$N"
                       CYN "��һ�С�\n"NOR;
                 me->start_busy(3+random(2));
       
        }

   message_vision(msg, me, target);
 me->start_perform(3,"�߻�ħ��");

        return 1;
}

