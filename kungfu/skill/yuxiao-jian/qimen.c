// By Darken@SJ

#include <ansi.h>
inherit F_SSERVER;

string perform_name() { return HIG"���š�����"NOR; }

int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, attack_time, lvl;
        if( !target ) target = offensive_target(me);
        if( !objectp(target)
        ||  !target->is_character()
        ||  !me->is_fighting(target) )
                 return notify_fail("���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
         || (string)weapon->query("skill_type") != "sword")
                 return notify_fail("��ʹ�õ��������ԡ�\n");
        if((int)me->query_skill("yuxiao-jian",1) < 100 )
                 return notify_fail("������｣�����������ʹ���������������\n");
        if((int)me->query_skill("qimen-bagua",1) < 100 )
                 return notify_fail("������Ű��Ի��������ʹ���������������\n");
        if((string)me->query_skill_mapped("sword") != "yuxiao-jian" && userp(me))
                   return notify_fail("�������޷�ʹ�á����������\n");
        if((string)me->query_skill_mapped("parry") != "yuxiao-jian" && (string)me->query_skill_mapped("parry") != "tanzhi-shentong"&&userp(me))
                   return notify_fail("�������޷�ʹ�á����������\n");
        if((int)me->query_temp("yuxiao_lian") )
                return notify_fail("�������Ѿ��������ʹ�á���������ˡ�\n");
        if((int)me->query("max_neili", 1) < 1000 )
                 return notify_fail("���������Ϊ����ʹ�á����������\n");
        if((int)me->query("max_jingli") < 500 )
                 return notify_fail("��ľ�����Ϊ����ʹ�á����������\n");
        if((int)me->query("neili")<500)
                 return notify_fail("�������������\n"); 
        
        attack_time = me->query_skill("yuxiao-jian",1) / 2;

        if (attack_time < 2)  attack_time = 2;
        if (attack_time > 4)  attack_time = 4;
        if (me->query_temp("thd/is_fast")) attack_time += 2;

        msg = HIG "$N����"+weapon->name()+HIG"���̣��������磬���ж��ǹ��ƣ�һ�в���$n���⿪ȥ�����������������\n"+
                 "$N����һ��������һ�У�����"+chinese_number(attack_time)+"�У�����ѧ������ȫ�෴��\n"+
                 "$n��������������Ҫ������ȫ��"+weapon->name()+HIG"����֮�£�\n"NOR;
        message_vision(msg, me, target);
        lvl = me->query_skill("yuxiao-jian", 1) /5 + me->query_skill("qimen-bagua", 1)/ 20;

if(!userp(target) && lvl>=60)  target->add_busy(1+ random(2));

        me->add_temp("apply/attack", lvl);
        me->add_temp("apply/damage", lvl);
        me->add_temp("apply/sword", lvl);
        me->add("neili", -300);
        me->add("jingli", -80);
        for(i = 0; i < attack_time; i++)
                if (me->is_fighting(target))
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        me->start_perform(attack_time/2,"���������");
        me->set_temp("yuxiao_lian", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, target, lvl :), random(attack_time)+4);
        return 1;
}

void remove_effect(object me, object target, int lvl)
{
        if (me) me->delete_temp("yuxiao_lian"); 
        if (me) me->add_temp("apply/attack", -lvl);
        if (me) me->add_temp("apply/damage", -lvl);
        if (me) me->add_temp("apply/sword", -lvl);
        if (target && me->is_fighting(target))
                message_vision(HIC"$n������͸��$N�Ĺ��ƣ����ٱ����｣�������Ž�·���Ի�\n"NOR,me,target);
}

int help(object me)
{
        write(HIG"\n�����š������"NOR"\n");
        write(@HELP

        ʹ�����Ű��Է�λ��ȡ���⹥�ƣ�����ֿ��ٹ���֮���Ի���֡�

        Ҫ��  �̺������ȼ� 100 ���ϣ�
                ���｣���ȼ� 100 ���ϣ�
                ���Ű��Եȼ� 100 ���ϣ�
                ���������תʱ�����������ӡ�
HELP
        );
        return 1;
}



