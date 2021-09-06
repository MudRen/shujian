#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	int lvl, j, ap, dp;
	object weapon;
	lvl = me->query_skill("xuanyin-jian", 1);

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ��ն�־���\n");

	weapon = me->query_temp("weapon");

	if ( ! weapon 
	|| weapon->query("skill_type") != "sword"
	|| me->query_skill_mapped("sword") != "xuanyin-jian"
	|| me->query_skill_mapped("parry") != "xuanyin-jian" )
		return notify_fail("�������޷�ʩչ��ն�־���\n");

	if( (int)me->query_skill("xuanyin-jian", 1) < 200 )
		return notify_fail("�����������������죬�޷�ʩչ��ն�־���\n");

	if ((int)me->query_skill("jiuyin-zhengong", 1) < 200)
		return notify_fail("��ľ����湦��򲻹����޷�ʩչ��ն�־���\n");

	if ((int)me->query_skill("jiuyin-shenfa", 1) < 200)
		return notify_fail("��ľ�������򲻹����޷�ʩչ��ն�־���\n");

	if ( (int)me->query("max_neili") < 2000)
		return notify_fail("��������������޷�ʩչ��ն�־���\n");

	if ( (int)me->query("neili") < 1500)
		return notify_fail("��������������޷�ʩչ��ն�־���\n");

	if ((int)me->query("jingli") < 1500)
		return notify_fail("��ľ����������޷�ʩչ��ն�־���\n");

	message_vision(HIB"\n$Nʹ��������ն�־���������һ˲�乥��$n��\n"NOR,me, target);

	j = to_int(lvl/2.0 * lvl/200.0);

	me->add_temp("apply/attack", j/3);
	me->add_temp("apply/sword", j);
	me->add_temp("apply/damage", j/2);

	ap = me->query("combat_exp", 1) / 1000 * me->query_dex(1);
	dp = target->query("combat_exp", 1) / 1000 * target->query_dex(1);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	if( random(ap + dp ) > dp* 7 / 5 ) {
		message_vision(HIB"���$Nһ�е��֣�$n�������Ȼ��ն��������\n"NOR,me, target);
		target->set_temp("must_be_hit", 1);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
		target->delete_temp("must_be_hit");
   target->apply_condition("broken_arm",1); 
		me->add("neili", -100);
	}

        me->add_temp("apply/attack", -j/3);
	me->add_temp("apply/sword", -j);
	me->add_temp("apply/damage",-j/2);
	me->add("neili", -400);
	me->add("jingli", -150);
	me->start_perform(3,"��ն�־���");
	me->start_busy(random(2));
	return 1;
}

string perform_name(){ return HIB"ն�־�"NOR; }

int help(object me)
{
        write(HIB"\n��������֮��ն�־�����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1500 ���ϣ�
                ������� 2000 ���ϣ�
                ��ǰ���� 1500 ���ϣ�
                ���������ȼ� 200 ���ϣ�
                �����湦�ȼ� 200 ���ϣ�
                �������ȼ� 200 ���ϣ�
                ��������Ϊ����������
                �����м�Ϊ����������
                ���ֱֳ�����

HELP
        );
        return 1;
}
