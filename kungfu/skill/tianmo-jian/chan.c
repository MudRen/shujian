// chan.c ��ħ����

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int level, b;
        string msg;

        if (! target) target = offensive_target(me);

           if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
                return notify_fail("����ħ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

        if (!living(target))
                return notify_fail("�Է��Ѿ�����ս���ˣ�\n");

        if ((level = me->query_skill("tianmo-jian", 1)) < 160)
                return notify_fail("�����ħ����������죬����ʹ�á���ħ������\n");

        if (me->query("neili") < 80)
                return notify_fail("�����������������޷�ʹ�á���ħ������\n");

        msg = HIM "$N" HIM "ʹ����ħ��������ħ������Ĭ�˿ھ���������"
              + weapon->name() + HIM "һ������ʱ����һ�������Ļ��������\n" NOR;

        me->add("neili", -60);
        if (random(level) > (int)target->query_skill("parry", 1) /3)
        {
                msg += HIR "���$p" HIR "�پ����ǲ������������ң�"
                       "ȫȻ��֪���ںδ�������������\n" NOR;
                b = level / 20;
                if (b > 6)   b = 6;
                target->start_busy(b);
                me->start_busy(1);
        } else
        {
                msg += CYN "����$p" CYN "������$P" CYN "����ͼ����æ"
                       "�˹���"+ weapon->name() + CYN "���˿�ȥ�������������С�\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
 me->start_perform(3, "����ħ����");

        return 1;
}

