// yin.c �򹷰���--���־�
// Creat by looklove@SJ 3/16/2001

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return HBCYN"���־�"NOR; }
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
	 || me->query_skill_mapped("stick") != "dagou-bang"
	 || me->query_skill_mapped("parry") != "dagou-bang" )
		return notify_fail("�������޷�ʹ�á����־�����\n");

	mexp=me->query("combat_exp");
	texp=target->query("combat_exp");

	mlvl=me->query_skill("dagou-bang",1);
	tlvl=target->query_skill("dodge",1);

	i = me->query_int(1);
	j = target->query_int(1);
	b = me->query_skill("bangjue",1);

	tweapon = target->query_temp("weapon");

	if( mlvl < 200 )
		return notify_fail("��Ĵ򹷰�����������죬����ʹ�ã����־��ݡ�\n");

	if( b < 150 )
		return notify_fail("��Ĵ򹷰���������죬�޷�ʹ�������־��ݡ�\n");

	if( me->query_skill("huntian-qigong", 1) < 200 )
		return notify_fail("��Ļ��������������㣬�޷�ʹ�������־��ݡ�\n");

	if( me->query("neili") < 400 )
		return notify_fail("�������������\n");

	if( me->query("jingli") < 400 )
		return notify_fail("��ľ�������������ʹ���˾�����\n");

	if( me->query("max_neili") < 2000 )
		return notify_fail("��������Ϊ���ڲ���, �����á����־�����\n");

	if( target->query_condition("no_perform") )
		return notify_fail("�Է��Ѿ�����İ������Ի󣬴󵨽����ɣ�\n");

	n = b / 50 + random(b/50);
	if( mlvl > 350 ) n += random(n);
	if( n > 6 ) n = 6;
	if(wizardp(me)) write(sprintf(HIR"n=%d \n"NOR,n));

	i = mexp/10000 * (mlvl + i/2);
	j = texp/10000 * (tlvl + j);
	i += COMBAT_D->skill_power(me, "stick", SKILL_USAGE_ATTACK);
	j += COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);

	if( !tweapon ) msg = HBCYN"$N��������������"+weapon->name()+HBCYN"�Ữ��ʹ�������־���������Ҫ��$n��ס"+weapon->name()+HBCYN"��\n"NOR;
	else msg = HBCYN"$N�������־���������"+weapon->name()+HBCYN"�����������"+tweapon->name()+HBCYN"����֮����\n"NOR;
	me->start_perform(3 + random(2), "���־�");

	if( random(i + j ) > j*5/4 ) {
		if( tweapon ) msg += HBCYN"$n�������������Σ�ʼ�հ��Ѳ���"+weapon->name()+HBCYN"��ǣ��֮�ơ�\n"NOR;
		else msg += HBCYN"$nһ���л��ɳˣ�Ѹ�ٱ���Ϊצ����ץ������ȴ��������"+weapon->name()+HBCYN"�ֺ���\n"NOR;
		msg += HBCYN""+weapon->name()+HBCYN"���������ٳ����������л�����$nȴ�о��������ƣ����ּ�ɬ��\n"NOR;
		target->add_busy(2 + random(2));
		target->set_temp("dgb/yin", n);
		target->add_condition("no_perform",n);
        }
	else {
		msg += HBCYN "$n�о����˳��"+weapon->name()+HBCYN"�����ƣ����˿�ȥ��\n" NOR;
		me->start_perform(2 + random(2), "���־�");
	}
	message_vision(msg, me, target);
	me->start_busy(1+random(2));
	me->add("neili",-300);
	me->add("jingli",-150);
	return 1;
}

int help(object me)
{
	write(HBCYN"\n�򹷰������־�����"NOR"\n");
	write(@HELP
	�򹷰��ڱ����๦��������������һ��ģ�������ʮ�ֵ���
	�˾��е��⡸���־�����ר������ǣ������ס���ֵı��������
	���������Է����������������������Է������͵�������ǣ��ס
	�Ķ�����Ҳ����ʹ��ǿ����Ч�Ĺ�����

	Ҫ��	������� 2000 ���ϣ�
		��ǰ���� 400 ���ϣ�
		�򹷰��ȼ� 200 ���ϣ�
		���������ȼ� 200 ���ϣ�
		�򹷰����ȼ� 150 ���ϣ�
		�����м�Ϊ�򹷰���
HELP
	);
	return 1;
}
