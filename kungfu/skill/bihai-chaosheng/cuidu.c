// Modified by Darken@SJ
#include <ansi.h>

string exert_name() { return HIG"���Ƕ�����"NOR; }

int exert(object me, object target)
{
        int level = me->query_skill("bihai-chaosheng",1);
        int num;

        if( !objectp(target) )
                return notify_fail("��Ҫ�߶�˭�Ķ��ԣ�\n");
        if( environment(me)->query("no_fight") )
                return notify_fail("���ﲻ�ܴ߶���\n");
        if( me->is_fighting() || target->is_fighting())
                return notify_fail("ս���д߶�����������\n");
        if ((int)me->query_skill("bihai-chaosheng", 1) < 200)
                return notify_fail("��ı̺���������Ϊ��������\n");
        if( (int)me->query("max_neili") < 1000 )
                return notify_fail("���������Ϊ������\n");
        if( (int)me->query("neili") < 1000 )
                return notify_fail("�������������\n");
        if( me == target ) 
                return notify_fail("�������Ⱑ��\n");
        if(!target->query("thd/fugu"))
                return notify_fail("����û���и��Ƕ���\n");

        num = target->query("thd/fugu");        
        me->add("neili", -300);
        me->add("jing", -500);
        target->receive_wound("qi",random(level/5)*num);
        target->receive_wound("jing",random(level/5)*num);
        target->set_temp("last_damage_from", me);
        target->add("neili",-random(level));
        target->start_busy(2);
        message_vision(HIW"$N����̺����������߶�$n�ĸ��Ƕ�֮����"NOR,me,target);
        message_vision(HIW"$n��"HIR"���Ƕ�"HIW"֮�������ˣ�\n"NOR,me,target);
        if(!target->is_killing(me)) me->kill_ob(target);
        me->start_busy(5);
        return 1;
}

int help(object me)
{
        write(HIG"\n�����Ƕ����ߡ���"NOR"\n");
        write(@HELP

        ʹ�ñ̺��������߶����Ƕ��Ķ��ԣ���Ŀ��ľ������ܵ����ˣ�ͬʱ���ֵ�
        ���ɢ���־ۼ���������

        Ҫ��  �̺������ȼ� 200 ���ϣ�
                ������� 1000 ���ϣ�
                ��ս������ʹ�á�
HELP
        );
        return 1;
}

