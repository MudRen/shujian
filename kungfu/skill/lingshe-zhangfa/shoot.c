// throw.c �����ȷ��綾
// By Yzuo 97.04

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;

        if( !target ) target = offensive_target(me);

        if( environment(me)->query("no_fight") )
                return notify_fail("���ﲻ�ܹ�������! \n");

        if( !target  
         || !objectp(target)
          || environment(target)!= environment(me))

                return notify_fail("��Ҫ��˭ʹ���綾��\n");

        if( (int)me->query_skill("hamagong", 1) < 40 )
                return notify_fail("��ĸ�󡹦������죬�����綾��\n");

        if( (int)me->query_skill("lingshe-zhangfa", 1) < 40 )
                return notify_fail("��������ȷ�������죬�����綾��\n");

        if( (int)me->query("neili", 1) < 400 )
                return notify_fail("������������������綾��\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
            return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (string)weapon->query("id") != "she zhang" )
                return notify_fail("������û�����ȣ������綾��\n");

        me->add("neili", -200);

        msg = MAG "$N��䷢���̶��ĸ�����죬����ǰͷ��С���͵���ͷ��һ��ۺ춾�������������$n��\n";

        me->start_busy(1);
        if( random( (int)me->query_skill("lingshe-zhangfa",1))
          > random(target->query_skill("dodge"))/4 )
        {
                msg += MAG "���$p��$P��ͷС��һ�����У�\n" NOR;
                if (target->query("neili") < me->query("neili")/2)
                {
        msg += MAG "$pֻ�ŵ�һ�����㣬��ǰ��ģ��������\n" NOR;
        target->receive_damage("qi",(int)me->query_skill("lingshe-zhangfa",1));
        target->receive_wound("qi",15 + random(10));
        target->receive_wound("jing", 10);
        target->apply_condition("snake_poison", random(me->query_skill("lingshe-zhangfa",1)/10) + 1 +
                target->query_condition("bt_poison")); 
        target->apply_condition("snake_poison", random(me->query_skill("lingshe-zhangfa",1)/10) + 1 +
                target->query_condition("bt_poison"));
        target->start_busy(5 + random(2));
                 message_vision(msg, me, target);
                COMBAT_D->report_status(target);
                }
                else
                {
        msg += CYN "$p����������һ���������߶���ȥ����ʱ�߶�����$PƮ�˻�ȥ��\n" NOR;
        msg += MAG "$Pֻ�ŵ�һ�����㣬��ǰ��ģ��������\n" NOR;
        me->receive_damage("qi",(int)me->query_skill("lingshe-zhangfa",1));
        me->receive_wound("qi",15 + random(10));
        me->receive_wound("jing", 10);
        me->apply_condition("snake_poison", random(me->query_skill("lingshe-zhangfa",1)/10) + 1 +
                me->query_condition("snake_poison"));
        me->start_busy(1 + random(2));
         message_vision(msg, me, target);
        COMBAT_D->report_status(me);
                }
        } else {
                msg += CYN"����$p��æ����һ�ԣ����˿�ȥ��\n" NOR;
                me->start_busy(3);
                 message_vision(msg, me, target);
        }
        if( !target->is_killing(me) ) target->kill_ob(me);
        return 1;
}

string perform_name(){ return MAG"�綾"NOR; }
