// by darken@SJ

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        
        if( !target ) target = offensive_target(me);

        if( !objectp(target)
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        || !living(target))
                return notify_fail("һ����˫��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("liuye-daofa", 1) < 100 )
                return notify_fail("�����Ҷ��������̫ǳ���޷�ʹ��һ����˫�ƹ�����\n");

        if( (int)me->query_skill("tiezhang-zhangfa", 1) < 100 )
                return notify_fail("��������Ʒ�����̫ǳ���޷�ʹ��һ����˫�ƹ�����\n");

        if( (int)me->query("max_neili") < 1000 )
                return notify_fail("�������̫ǳ���޷�ʹ��һ����˫�ƹ�����\n");

        if( (int)me->query("neili") < 400 )
                return notify_fail("����������㣬�޷�ʹ��һ����˫�ƹ�����\n");

        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "blade"
            || me->query_skill_mapped("blade") != "liuye-daofa" || 
               me->query_skill_prepared("strike") != "tiezhang-zhangfa")
                return notify_fail("���׼�����򲻶ԡ�\n");

        me->add("neili", -200);
        me->add("jingli", -40);
        message_vision(BLU"$N�������������У������м������������Ʒ���Ѹ����$n��ȥ��\n" NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        weapon->unequip();
        if(me->is_fighting(target)) COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        if(me->is_fighting(target)) COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        weapon->wield();
        me->start_perform(4,"һ��Ю˫��");
        me->start_busy(1);
        return 1;
}

string perform_name(){ return BLU"�Ƶ�"NOR; }