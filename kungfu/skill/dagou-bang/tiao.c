// tiao.c �򹷰���--���־�
// Creat by looklove@SJ 3/17/2001

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return HBMAG"���־�"NOR; }
int perform(object me, object target)
{
	string msg;
	object tweapon, weapon;
	int busy, mexp, texp, mlvl, tlvl, i, j, b, ap, dp;

	me->clean_up_enemy();
	target = me->select_opponent();

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target) )
		return notify_fail("�����־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	weapon = me->query_temp("weapon");
	tweapon = target->query_temp("weapon");

	if( !weapon
	 || weapon->query("skill_type") != "stick"
	 || me->query_skill_mapped("stick") != "dagou-bang" )
		return notify_fail("�������޷�ʹ�����־���\n");

	if( !tweapon )
		return notify_fail("�Է�û��ʹ���κα��������޷�ʹ�á����־�����\n");

	mexp=me->query("combat_exp");
	texp=target->query("combat_exp");
	if( texp < 100 ) texp = 100;

	mlvl=me->query_skill("dagou-bang",1);
	tlvl=target->query_skill("dodge",1);

	i = me->query_int(1);
	j = target->query_int(1);
	b = me->query_skill("bangjue",1);

	if( mlvl < 160 )
		return notify_fail("��Ĵ򹷰�����������죬����ʹ�á����־�����\n");

	if( b < 160 )
		return notify_fail("��Ĵ򹷰���������죬�޷�ʹ�������־�����\n");

	if( (int)me->query_skill("huntian-qigong", 1) < 160 )
		return notify_fail("��Ļ��������������㣬�޷�ʹ�������־�����\n");

	if( (int) me->query("neili") < 800 )
		return notify_fail("��������������޷�ʹ�������־�����\n");

	busy = random( b/50 ) +1;

	if(wizardp(me)) write(sprintf(HIR"busy=%d \n"NOR,busy));

	msg = HBMAG"$N���������"+weapon->name()+HBMAG"һת�����һ�����𣡡���ʹ�������־�������ס"+tweapon->name()+HBMAG"����������\n"NOR;

	me->start_perform(3, "���־�");

	ap = mexp/10000*(mlvl+i);
	dp = texp/10000*(tlvl+j*2);
	ap += COMBAT_D->skill_power(me, "stick", SKILL_USAGE_ATTACK);
	dp += COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

	if( random(ap + dp) > dp ) {
		int move_flag = 0;
		if(tweapon->is_owner(target)) move_flag=1;
		msg += HBMAG"$nֻ��"+tweapon->name()+HBMAG"�������ַɳ���һ�����ղ�ס�����б����������˳�ȥ��\n"NOR;
		target->add_busy(busy);
		me->add("neili",-300);

		if (move_flag==0 && random(2)!=1 && tweapon->query("imbued") < 3 && tweapon->move(me)){
			msg += HIY"$N��������Ծ�����࣬������е�"+tweapon->name()+HIY"�������С�\n"NOR;
		}
		else {
			msg += HBMAG"$n���������"+tweapon->name()+HBMAG"�������ӣ���$N"+weapon->name()+HBMAG"��һ��������ֻ����"+tweapon->name()+HBMAG"����һ�ߡ�\n"NOR;
			tweapon->move(environment(me));
		}
	}
	else {
		me->add("neili",-200);
		msg += HIG"$n��������б����һ������"+weapon->name()+HIG"���Լ���"+tweapon->name()+HIG"�ϵ��˿�ȥ��\n"NOR;
	}
	me->start_busy(random(2));
	message_vision(msg, me, target);
	return 1;
}

int help(object me)
{
	write(HBMAG"\n�򹷰������־�����"NOR"\n");
	write(@HELP
	�򹷰���������������һ���ٵ�֮���ݲ����˵У�����Ա���
	�������ֱֳ�������ʹ�ôˡ����־������ɽ����ֱ�����ɻ�
	�������Լ����С�

	Ҫ��	��ǰ���� 800 ���ϣ�
		�򹷰��ȼ� 160 ���ϣ�
		���������ȼ� 160 ���ϣ�
		�򹷰����ȼ� 160 ���ϣ�
		�����м�Ϊ�򹷰���
		���������ޱ���������Ч����
HELP
	);
	return 1;
}