// ci.c canhe-zhi perform ���־�
// by leontt 1/5/2000
// modified by darken to reduce busy time

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int improve);

int perform(object me, object target)
{
	string msg;
	int improve, ap, dp, skill, i;

	if( !target ) target = offensive_target(me);

         if( !objectp(target) || !target->is_character() || !me->is_fighting(target) || !living(target))
		return notify_fail("�����־���ֻ����ս���жԶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("��������ʹ�á����־�����\n");

	if( (int)me->query_skill("canhe-zhi",1) < 100 )
		return notify_fail("��Ĳκ�ָ������죬����ʹ�á����־�����\n");

	if( (int)me->query_skill("shenyuan-gong",1) < 100 )
		return notify_fail("�����Ԫ���ȼ�����������ʹ�á����־�����\n");

	if( (int)me->query_str(1) < 30 )
		return notify_fail("��ı�������ǿ������ʹ�á����־�����\n");

	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("�������̫��������ʹ�á����־�����\n");

	if( (int)me->query("neili") < 600 )
		return notify_fail("�������̫���ˣ��޷�ʹ�ó������־�����\n");

	if (me->query_skill_prepared("finger") != "canhe-zhi"
	|| me->query_skill_mapped("finger") != "canhe-zhi")
		return notify_fail("�������޷�ʹ�á����־������й�����\n");

        if ( me->query_skill_mapped("force") != "shenyuan-gong")
           return notify_fail("û����Ԫ��֧�����ʹ�á����־�����\n");
	if ( me->query_skill_mapped("parry") != "canhe-zhi"
	&& me->query_skill_mapped("parry") != "douzhuan-xingyi")
		return notify_fail("�������޷�ʹ�á����־������й�����\n");

//	if( target->query_temp("ci"))
//		return notify_fail("������ʹ�òκ�ָ�����⹥�������־�����\n");

	msg = HIC"\n$NͻȻһ�������Լ��ĵ����ϼ���ȫ��������γ�һ�ɡ�"HIR"����"HIC"����������Ĵָ�������������$n�ļ粿��\n" NOR;
	message_vision(msg, me, target);

//	pfm ci �в��� aut pfm �ı�� by lane
	me->set_temp("mr_ci", 1);


	ap = COMBAT_D->skill_power(me, "finger", SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

	if ( target->is_busy())
		 dp -= dp/3;
	

	skill = me->query_skill("canhe-zhi", 1);

	if(skill>451 && !userp(target) ) 
		 dp = dp/3;	


	  i = skill/3;
	
	if ( skill > 250 )
		i = to_int( skill/2.8 * skill/250.0);

	me->add_temp("apply/attack", i);
	me->add_temp("apply/finger", i);
	me->add_temp("apply/damage", i);
	
	if( random(ap + dp) > dp && !target->query_temp("ci")) {
		msg = HIR"$n�ļ�ؽ�һ�ᣬ˫����ʱʧȥ֪�����������á�\n"NOR;
target->add_busy(2);
                message_vision(msg, me, target);
		if (present(target,environment(me)) && me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
		
		if (present(target,environment(me)) && me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), (skill>=451)?3:1);

		if ( skill > 150)
			if (present(target,environment(me)) && me->is_fighting(target))
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

		improve = me->query("str");
		target->add_temp("apply/strength", -improve);
		target->set_temp("ci", improve);
		target->add_condition("no_perform", 2);
		target->add_busy(random(2)+1);
		me->add("neili", -100);
		me->add("jingli", -50);
		call_out("check_fight", 1, me, target ,improve, me->query_skill("finger")/30+5);
	}
	else {
		msg = CYN"$n����һԾ�����ݵض����$N����һ�У�$P��$p����֮�ʣ�˳���ٹ����У�\n"NOR;
target->add_busy(2);
                message_vision(msg, me, target);
		if (present(target,environment(me)) && me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
		if ( skill > 150)
			if (present(target,environment(me)) && me->is_fighting(target))
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	}
	me->add_temp("apply/attack", -i);
	me->add_temp("apply/finger", -i);
  me->add_temp("apply/damage", -i);
	me->start_busy(random(2));
	me->add("neili", -250);
	me->add("jingli", -80);

	me->delete_temp("mr_ci");

	me->start_perform(2, "�����־���");
	return 1;
}

void remove_effect(object target, int improve)
{
	if(!target) return;
	target->add_temp("apply/strength", improve);
	target->delete_temp("ci");
	tell_object(target, HIR"\n������һ����ɫ������ֻ࣬����˫���Ѿ��ָ���ԭ״��\n"NOR);
}

void check_fight(object me, object target, int improve, int count)
{
	if(! target) return;
	if(! me
	|| ! me->is_fighting(target)
	|| me->query_skill_mapped("finger") != "canhe-zhi"
	|| me->query_skill_prepared("finger") != "canhe-zhi"
	|| me->query_temp("weapon")
	|| count < 0 ){
		remove_effect(target , improve);
		return;
	}
	call_out("check_fight", 1, me, target, improve, count -1);
}

string perform_name(){ return HIC"���־�"NOR; }

int help(object me)
{
        write(HIC"\n�κ�ָ֮�����־�����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 600 ���ϣ�
                ������� 1000 ���ϣ�
                �κ�ָ�ȼ� 100 ���ϣ�
                ��Ԫ���ȼ� 100 ���ϣ�
                ����ָ��Ϊ�κ�ָ��
                ��ָ��Ϊ�κ�ָ��
                �����ޱ�����

HELP
        );
        return 1;
}
                                
