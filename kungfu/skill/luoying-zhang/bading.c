// bading.c by Darken@Sj

inherit F_SSERVER;
#include <ansi.h>

string perform_name() { return HIG"���Ƕ�����"NOR; }

int perform(object me, object target)
{
        string msg;
        
        if(!objectp(target))
                return notify_fail("����û������ˡ�\n");
        if(!target->query("thd/fugu"))
                return notify_fail("�����û���и��Ƕ���\n");
        if( (int)me->query_skill("bihai-chaosheng", 1) < 250 )
                return notify_fail("��ı̺���������Ϊδ�����޷�ʹ�ø��Ƕ���\n");
        if( (int)me->query_skill("luoying-zhang",1) < 250 )
                return notify_fail("����Ʒ���Ϊ���㡣\n");
        if( (int)me->query("neili") < 2000 )
                return notify_fail("����������̫����\n");

        me->add("neili",-2000);
        me->add("max_neili",-30);
        msg = HIY"$N�ߵ�$n���ᣬ���������\n"NOR;
        msg+= HIW"$N����̺��������������Ľ�$n���и��Ƕ��γ���\n"NOR;
        if( target->query_con() > 30) {
                msg+= HIC"$n�ҽ�һ�����ڹ���Ϊ�������\n"NOR;
                target->add("max_neili",-5);
        } else {
                msg+= HIR"$n�ҽ�һ�������˹�ȥ��\n"NOR;
                target->unconcious();
                target->add("max_neili",-5);
        }
        target->add("thd/fugu",-1);
        message_vision(msg, me, target);
        return 1;
}

int help(object me)
{
        write(HIG"\n�����Ƕ����Ρ���"NOR"\n");
        write(@HELP

        ���˱̺��������������ܸ��Ƕ�֮����������Ƕ������Ǹ��ǲ�������ڹ�
        ������񣬶�����ʧ������������

        Ҫ��  �̺��������ȼ� 250 ���ϣ�
                ��Ӣ���Ƶȼ� 250 ���ϣ�
                ������� 2000 ���ϣ�
                ��ս������ʹ�á�
HELP
        );
        return 1;
}


