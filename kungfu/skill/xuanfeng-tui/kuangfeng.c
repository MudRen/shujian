// kuangfeng.c  ������
// Modified by Darken@SJ

#include <ansi.h>
inherit F_SSERVER;

string perform_name() { return HIG"������"NOR; }

int perform(object me, object target)
{
        int lvl;

        if( !target ) target = offensive_target(me);
        if( !objectp(target)
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (!(me->query("thd/perform") & 4))
                return notify_fail("����Ȼ��˵���������������һ��������񼼣�����ȴδ��Ƶ������ڡ�\n");
        if( objectp(me->query_temp("weapon")) )
               return notify_fail("��������ʹ�á�����������\n");
        if( (int)me->query_skill("luoying-zhang", 1) < 100 )
                return notify_fail("�����Ӣ���Ʋ�����죬�޷�ʩչ����������\n");
        if( (int)me->query_skill("xuanfeng-tui", 1) < 100 )
                return notify_fail("�������ɨҶ�Ȳ�����죬�޷�ʩչ����������\n");
        if ((int)me->query_skill("bihai-chaosheng", 1) < 100)
                return notify_fail("��ı̺���������򲻹����޷�ʩչ����������\n");
        if ( (int)me->query("max_neili") < 1000)
                return notify_fail("��������������޷�ʩչ����������\n");
        if ( (int)me->query("neili") < 500)
                return notify_fail("��������������޷�ʩչ����������\n");
        if (me->query_skill_prepared("leg") != "xuanfeng-tui"
            || me->query_skill_mapped("leg") != "xuanfeng-tui"
            || me->query_skill_mapped("strike") != "luoying-zhang" )
                return notify_fail("�������޷�ʹ�ÿ��������й�����\n");
        if (me->query_skill_mapped("force") != "bihai-chaosheng")
                return notify_fail("��ı̺���������Ϊ�������޷�ʹ�ÿ��������й�����\n");

        if (me->query_temp("thd/is_fast")) lvl += 100;
            me->start_perform(6, "������");
        lvl = (me->query_skill("xuanfeng-tui",1) + me->query_skill("luoying-zhang",1) )/2;
        message_vision(HBGRN "$Nһ����Х��ȭ����ʩ��ʹ���һ�����������Ѹ�����׵ع���$n��\n"NOR,me, target);
        call_out("kuangfeng_attack", 1, me, target, "leg", lvl);
        return 1;
}

void kuangfeng_attack(object me, object target, string skill, int lvl)
{
        int i;
        if (!me)
return;
    if(me)
        me->receive_damage("neili", 100+random(100));
        if (!me || !target || !me->is_fighting(target) || lvl <= 0 || me->query("neili") <= 0) {
                message_vision(HIG"$N���ν�����ֹͣ�˿�������\n"NOR, me);
                me->prepare_skill("strike","luoying-zhang");
                me->prepare_skill("leg", "xuanfeng-tui");
                return;
        } else {
                if (skill == "strike") {
                        me->prepare_skill("leg");
                        me->prepare_skill("strike", "luoying-zhang");
                        message_vision(HIG"$N����Ϊ�ƣ�Ѹ���ޱȵ���$n��ȥ��\n"NOR, me, target);
                        call_out("kuangfeng_attack", 2, me, target, "leg", lvl-50);
                } else {
                        me->prepare_skill("strike");
                        me->prepare_skill("leg", "xuanfeng-tui");
                        message_vision(HIG"$N����Ϊ�ȣ�Ѹ���ޱȵ���$n��ȥ��\n"NOR, me, target);
                        call_out("kuangfeng_attack", 2, me, target, "strike", lvl-50);
                }
                me->add_temp("apply/attack",lvl/2);
                me->add_temp("apply/damage",lvl/2);
                for (i = 0; i < 5; i++) COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
                me->add_temp("apply/attack",- lvl/2);
                me->add_temp("apply/damage",- lvl/2);
       }
}

int help(object me)
{
        write(HIG"\n������������"NOR"\n");
        write(@HELP

        ����Ӣ�����������ɨҵ������ֿ��ٹ�����Ϊ��ҩʦ������Ķ��ž���
        ��������Ӣ���ƣ���������ɨҶ�ȣ�ѭ����ֹ��

        Ҫ��  �̺��������ȼ� 100 ���ϣ�
                ��Ӣ���Ƶȼ� 100 ���ϣ�
                ����ɨҶ�ȵȼ� 100 ���ϣ�
                ������� 1000 ���ϣ�
                ÿ�غ�����������������
                ��������������ÿ�غ����½���
                ���������ת����������ʱ�ޡ�
HELP
        );
        return 1;
}


