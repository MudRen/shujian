//By action@SJ
//���ɨ��Ҷ

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

string perform_name(){ return HBYEL"���ɨ��Ҷ"NOR; }

int perform(object me,object target)
{
    object weapon;
    int i;
    
    if( !target ) target = offensive_target(me);
     
    if( !objectp (target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("���ɨ��Ҷֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if(me->query_skill_mapped("force") != "hamagong")
                return notify_fail("����ڹ����Ǹ�󡹦���޷�ʹ�ÿ��ɨ��Ҷ��\n");
    if( (int)me->query_skill("hamagong", 1) < 150 )
                return notify_fail("����ڹ���δ���ɣ�����ʹ�ÿ��ɨ��Ҷ��\n");
    if( (int)me->query_skill("lingshe-zhangfa", 1) < 150 ) 
                return notify_fail("��������ȷ���δ���ɣ�����ʹ�ÿ��ɨ��Ҷ��\n");
    if((int)me->query_skill("staff", 1) < 150 )
                return notify_fail("��Ļ����ȷ�������죬������ʹ�ÿ��ɨ��Ҷ��\n");
    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "staff"
        || me->query_skill_mapped("staff") != "lingshe-zhangfa"
        || me->query_skill_mapped("parry") != "lingshe-zhangfa")
                return notify_fail("������ʹ���˿��ɨ��Ҷô��\n");
                
    if((int)me->query("max_neili") < 3000 )
                return notify_fail("���������Ϊ����������ʹ�ÿ��ɨ��Ҷ��\n");
    if((int)me->query("neili") < 1000 )
                return notify_fail("�������������㣬����ʹ�ÿ��ɨ��Ҷ��\n");

        message_vision(HIC"\n$N���������⣬ͻȻһ�����ȣ���------"HIR" �� "HIC"-----"HIG" �� "HIC"-----"HIY" ɨ "HIC"-----"HIM" �� "HIC"-----"YEL" Ҷ "HIC"----- ��������\n" NOR,me,target);

    me->start_perform(3+random(2),"�����ɨ��Ҷ��");
    i = (int)me->query_skill("lingshe-zhangfa",1);
        me->add("neili", -300);
        me->add_temp("apply/attack",  i*4/5);
        me->add_temp("apply/damage",  i*6/5);
        me->set_temp("lszf/luoye",1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        me->add_temp("apply/attack",  -i*4/5);
        me->add_temp("apply/damage",  -i*6/5);
        me->delete_temp("lszf/luoye");

    me->start_busy(1);
    target->start_busy(1);
    return 1;
}

int help(object me)
{
   write(WHT"\n�����ȷ���"HBYEL"���ɨ��Ҷ"WHT"����"NOR"\n");
   write(@HELP

   Ҫ��  ������� 3000 ���ϣ�
           ���� 1000 ���ϣ�
           �����ȷ��ȼ� 150 ���ϣ�
           ��󡹦�ȼ� 150 ���ϣ�
           �����м�Ϊ�����ȷ���

HELP
   );
   return 1;
}
