// ����Ϊ����yihunӦ��100%�����Լ�����Ҫ�ж�pfm�Ƿ����С��� 
#include <ansi.h>
inherit F_SSERVER;

int exert(object me, object target)
{       
	int skill, ap, dp;

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	|| !target->is_character()
        || !me->is_fighting(target)
        || !necessary(target) )
		return notify_fail("�ƻ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if ((int)me->query_skill("jiuyin-zhengong", 1) <= 220)
		return notify_fail("��ľ����湦��Ϊ��������\n");

	if( (int)me->query_int(1) < 45 )
                return notify_fail("������Բ�����\n");

	if( (int)me->query("neili") < 2000 )
		return notify_fail("�������������\n");

	skill = me->query_skill("jiuyin-zhengong",1);

        ap = me->query_skill("force");
        dp = target->query_skill("force")/3;

	message_vision(HIW"$N����ͻȻ��ʼ����������ֵı��顣\n"NOR, me, target);

        if (     random(me->query_int()) > target->query("int")/2) 
              {
        	int qi2 = target->query("qi");
                message_vision(HIW"$n����׼��ȡЦ$N��ȴ��֪������ѧ��$N�ı��顣\n"NOR, me, target);
		message_vision(HIW"$N��Ȼ�������Լ������Ķ�����$n�������Լ������ƵĹ�������������Խ��Խ�أ�\n"NOR, me, target);
		target->add_temp("apply/attack",skill/3);
		target->add_temp("apply/damage",skill/3);
                target->set_temp("must_be_hit",1);
		target->add_temp("apply/dodge",-skill);
		target->add_temp("apply/parry",-skill);
		target->add_temp("apply/defence",-skill);
              //������Ϊ�������ʰɣ�������must_be_hit��������
                COMBAT_D->do_attack(target, target, target->query_temp("weapon"), 3);
                if( me->is_fighting(target)&& random(2)) COMBAT_D->do_attack(target, target, target->query_temp("weapon"),3);
                if( me->is_fighting(target)) COMBAT_D->do_attack(target, target, target->query_temp("weapon"),3);
                if( me->is_fighting(target)) COMBAT_D->do_attack(target, target, target->query_temp("weapon"),3);
                if(target)
                {
			target->add_temp("apply/attack",-skill/3);
			target->add_temp("apply/damage",-skill/3);
                        target->delete_temp("must_be_hit");
			target->add_temp("apply/dodge",skill);
			target->add_temp("apply/parry",skill);
			target->add_temp("apply/defence",skill);//ԭ����1

			if(qi2 > target->query("qi")) target->set_temp("last_damage_from", me);
                }
	        me->add("neili", - 350);
	        me->add("jingli", -100);
	}
	else {
		message_vision(HIW"����$N��ô�仯���飬$n����������޶����ԡ�\n"NOR, me, target); 
	        me->add("neili", - 150);
	        me->add("jingli", -50);
	}
        me->start_exert(3, "���ƻ�󷨡�");
	if ( !me->is_perform())
		me->start_perform(1, "���ƻ�󷨡�");
	return 1;
}

string exert_name(){ return HIW"�ƻ��"NOR; }

int help(object me)
{
        write(HIW"\n�����湦֮���ƻ�󷨡���"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 2000 ���ϣ�
        	�������� 45 ���ϣ�
                �����湦�ȼ� 220 ���ϡ�

HELP
        );
        return 1;
}
