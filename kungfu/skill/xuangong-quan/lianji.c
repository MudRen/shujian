#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon = me->query_temp("weapon");
        int i = me->query_skill("xuangong-quan", 1)/2;
        int j = me->query("jiali")/2 + 100;
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        || !living(target))
                return notify_fail("���޵���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("xuangong-quan", 1) < 250 )
                return notify_fail("����޼�����ȭ����̫ǳ��������˵�ɣ�\n");

        if( (int)me->query_skill("cuff", 1) < 250 )
                return notify_fail("��Ļ���ȭ������̫ǳ���Ͻ�ȥ����ɣ�\n");
        if( (int)me->query_skill("yinyun-ziqi", 1) < 250 )
                return notify_fail("����ڹ�����̫ǳ�����������С�\n");
                
        if( (int)me->query("max_neili") < 1500 )
                return notify_fail("�������̫�٣�����ȥ��\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("��������������޷�ʹ���޵���������\n");
        if (me->query_skill_mapped("force") != "yinyun-ziqi")
                return notify_fail("�������ڹ��ǡ����������𣡣�\n");
        if(weapon)
                return notify_fail("���������Ž������ʹ�á��޵�����������\n");
                 
        message_vision(YEL"
ֻ��$N��ɫ΢΢һ����ȭ�Ʒ��ɣ�������ʽ��Ȼ��죡\n"NOR,me);

        me->add("neili", -200);
        me->add("jingli", -30);
        me->add_temp("apply/attack", i*5);
        me->add_temp("apply/damage", j);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
//        if(me->is_fighting(target))
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
//        if(me->is_fighting(target))
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);        
        me->add_temp("apply/attack", -(i*5));
        me->add_temp("apply/damage", -j);   
        me->start_busy(2);
        target->start_busy(1+random(2));
        return 1;
}