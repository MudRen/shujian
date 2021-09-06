//chaodu.c  �����Ƴ���������

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int skill;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("lianhuan") )
                return notify_fail("������ʹ�ó����������ˣ�\n");

        weapon = me->query_temp("weapon");
        if( objectp(weapon) )
                return notify_fail("���������żһ����ܹ�ʩչ��������\n");

        if( me->query_skill_mapped("force") != "yijin-jing" )
                return notify_fail("�����õĲ����׽�񹦣��޷�����Ʒ�ʩչ��������\n");

        if( me->query_skill("force") < 120 )
                return notify_fail("����׽�������δ�����޷����ʩչ��������\n");

/*
        if( me->query_skill("banruo-zhang") < 120 )
                return notify_fail("���Ʒ���Ϊ���㣬������ʹ�ó��Ⱦ���\n");
*/

        if( me->query_skill("strike") < 120 )
                return notify_fail("���Ʒ���Ϊ���㣬������ʹ����������\n");

        if( me->query("neili") <= 300 )
                return notify_fail("�����������ʩչ��������\n");
        if( me->query("jingli") <= 200 )
                return notify_fail("��ľ�������ʩչ��������\n");

        skill = me->query_skill("strike");
        
        message_vision(HIR "\n$N���һ�����������,�Ʒ������������������ʽ���ŷ�ħ�����Ⱦ���\n\n" NOR, me, target);

        me->set_temp("lianhuan", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/5);
        me->add("neili", -300);
        me->add("jingli", -100);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->delete_temp("lianhuan");

        if ( me->is_fighting() ) {
                message_vision(HIR "\n$N���׽��������ϣ��������ջص����������Ҳ������������\n\n" NOR, me);
        }
        else {
                tell_object(me, HIR "\n����׽��������ϣ������������ջص��\n\n" NOR);
        }
}

string perform_name(){ return HIR"����������"NOR; }