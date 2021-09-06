// chuo.c �򹷰���--���־�
// Creat by Looklove@SJ 2001.4.9
// Modified by Looklove@SJ 2001.5.19
// update for condition limit by Lklv 2002.1.16

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return HBWHT"���־�"NOR; }
int perform(object me, object target)
{
	string msg;
	object tweapon, weapon;
	int mexp, texp, mlvl, tlvl, i, j, b, n;

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target) )
		return notify_fail("�����־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	weapon = me->query_temp("weapon");

	if( !weapon
	 || weapon->query("skill_type") != "stick"
	 || me->query_skill_mapped("stick") != "dagou-bang" )
		return notify_fail("�������޷�ʹ�á����־�����\n");

	mexp = me->query("combat_exp");
	texp = target->query("combat_exp");

	mlvl = me->query_skill("dagou-bang",1);
	tlvl = target->query_skill("dodge",1);

	i = me->query_int(1);
	j = target->query_int(1);
	b = me->query_skill("bangjue",1);

	tweapon = target->query_temp("weapon");

	if( mlvl < 120 )
		return notify_fail("��Ĵ򹷰�����������죬����ʹ�á����־�����\n");

	if( b < 120 )
		return notify_fail("��Ĵ򹷰���������죬�޷�ʹ�������־�����\n");

	if( (int)me->query_skill("huntian-qigong", 1) < 120 )
		return notify_fail("��Ļ��������������㣬�޷�ʹ�������־�����\n");

	if( (int)me->query("neili") < 600 )
		return notify_fail("�������������\n");

	if( (int)me->query("max_neili") < 2000 )
		return notify_fail("��������Ϊ���ڲ���, �����á����־�����\n");

	if ( target->query_condition("no_exert") || target->query_condition("no_force"))
		return notify_fail("�Է��Ѿ�����Ĵ��־����У��󵨽����ɣ�\n");

	i = mexp/10000*(mlvl+i);
	j = texp/10000*(tlvl+j*2);
	i += COMBAT_D->skill_power(me, "stick", SKILL_USAGE_ATTACK);
	j += COMBAT_D->skill_power(target, "force", SKILL_USAGE_DEFENSE);

	n = b /100 + random(b/100) + mlvl/50;
	if( mlvl > 350 ) n += (mlvl-350)/50;
	if( n > 8 ) n = 8; // ����Ŀ�����busy ��condition��

	me->start_perform(3, "���־�");
	msg = HBWHT"$Nʹ���򹷰������־�����"+weapon->name()+HBWHT"�������ϣ��������ֱ��$n�����к���\n"NOR;

	if( random(i+j) > j*5/4 ) {
		msg += HBWHT"$n�������˼�����������һ�����ֲ�������"+weapon->name()+HBWHT"�͵Ĵ���ҪѨ��\n"NOR;
		msg += HBCYN"���$n��ʱ��ɫ�԰ף��о�������Ϣ���ң�ͷ�ؽ��ᡣ\n"NOR;
		target->add_busy(1+random(2));
		target->set_temp("dgb/chuo", n);
		target->apply_condition("no_force",n);
		message("wizard", HIG"���־���ʱЧ"+n*20+"�룬ʹ����EXP"+mexp+"������EXP"+texp+"��\n"NOR, environment(me), me);
	}
	else {
		if (tweapon) msg += HBWHT"$n���һ������æ������"+tweapon->name()+HBWHT"��"+weapon->name()+HBWHT"��һ����\n"NOR;
		else msg += HBWHT "$n���а��в��ã������������������������ܹ���"+weapon->name()+HBWHT"�����ơ�\n" NOR;
		if ( random(mexp) > texp/2 ){
			msg += WHT "����$N�����ϵ�$n�д�һ�У�����"+weapon->name()+WHT"һת���Ĵ�$n�Ľ��ס�\n" NOR;
			msg += WHT ""+weapon->name()+WHT"����������$n�Ѿ����޿ɱܣ���ͨһ��Ӧ��������\n" NOR;
			target->apply_condition("no_exert",n/2);
			target->add_busy(2+random(2));
			message("wizard", HIG"���־���ʱЧ"+n*20/3+"�룬ʹ����EXP"+mexp+"������EXP"+texp+"��\n"NOR, environment(me), me);
		}
	}
	message_vision(msg, me, target);
	me->start_busy(1+random(2));
	me->add("neili",-200);
	return 1;
}

int help(object me)
{
	write(HBWHT"\n�򹷰������־�����"NOR"\n");
	write(@HELP
	�򹷰���ʽ�쳣���ɺ�ɨ���򣬴ˡ����־�����������
	���������в��������Ϣ���֮ҪѨ��һ�����У�����ס��
        ��֮��Ϣ��·��һ��ʱ����ʹ������Ϣ���Ҷ��������е�����

	Ҫ��	������� 2000 ���ϣ�
		��ǰ���� 600 ���ϣ�
		�򹷰��ȼ� 120 ���ϣ�
		���������ȼ� 120 ���ϣ�
		�򹷰����ȼ� 120 ���ϣ�
		�����м�Ϊ�򹷰���
HELP
	);
	return 1;
}
