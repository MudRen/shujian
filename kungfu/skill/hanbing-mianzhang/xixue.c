// xixue.c ��Ѫ����
// By River
#include <ansi.h>

inherit F_SSERVER;
int perform(object me,object target)
{
	string msg;
	int skill, damage, p, ap, dp;
	skill = me->query_skill("hanbing-mianzhang",1);

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !me->is_fighting(target))
		return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á���Ѫ���𡹡�\n");

	if( me->query_temp("weapon"))
		return notify_fail("������������ô��ʹ�á���Ѫ���𡹣�\n");

	if( skill < 120 )
		return notify_fail("��ġ��������ơ��ȼ�����, ������ʹ�á���Ѫ���𡹣�\n");

	if( me->query_skill_mapped("strike") != "hanbing-mianzhang")
		return notify_fail("�������޷�ʹ�á���Ѫ���𡹣�\n");

	if (me->query_skill_prepared("strike") != "hanbing-mianzhang")
		return notify_fail("�������޷�ʹ�á���Ѫ���𡹣�\n");

	if ( me->query_skill_mapped("parry") != "qiankun-danuoyi"
	&& me->query_skill_mapped("parry") != "hanbing-mianzhang")
		return notify_fail("�������޷�ʹ�á���Ѫ���𡹣�\n");

	if( me->query_skill("dodge", 1) < 120 )
		return notify_fail("����Ṧ�������޷��������á���Ѫ���𡹣�\n");

	if( !me->query_skill("jiuyang-shengong", 1))
	if( me->query_skill("shenghuo-shengong", 1) < 120)
		return notify_fail("���ʥ���񹦵ȼ��������޷�ʹ�á���Ѫ���𡹣�\n");

	if((int)me->query("neili") < 400)
		return notify_fail("�����������ʹ�á���Ѫ���𡹡�\n");

	if( me->query_temp("qkdny/yin") )
		return notify_fail("������ʩչǬ����Ų�ơ������־��أ�\n");

	if((int)me->query("jingli") < 200)
		return notify_fail("��ľ�������ʹ�á���Ѫ���𡹡�\n");

	msg = HIC"\n$NͻȻ��ͬһֻ��Ѫ�����۽�$n����ǰ���������$n���ʺ�ҧȥ��\n"NOR;

	ap = me->query("combat_exp") * me->query_dex(1);
	dp = target->query("combat_exp") * target->query_dex(1);

	if( random(ap + dp) > dp || !living(target)) {
		msg += HIR"$nֻ�����ʺ�һ���ʹ��$N���ڿ���$n����Ѫ��\n"NOR;
		damage = skill*2;
		damage += me->query_skill("strike");
		damage += me->query_skill("force");
		damage += random(damage/2);

		me->add("neili",-250);
		me->add("jingli", -80);

		if(target->query("neili") >= skill*2)
			target->add("neili", - random(skill*2));
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/2, me);
		target->add_condition("hb_poison", skill / 15);
		target->add_busy(random(3));
		if (random(2)) {
			p = (target->query("eff_qi")+target->query_temp("apply/qi"))*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg += COMBAT_D->damage_msg(damage, "����");
			msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		}
		else {
			p = target->query("qi")*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg += COMBAT_D->damage_msg(damage, "����");
			msg += "( $n"+COMBAT_D->status_msg(p)+" )\n";
		}
	}
	else {
		msg += CYN"ֻ��$n���Ų�æ������һ���������$N�����ݣ�\n"NOR;
		me->add("neili",-100);
		me->add("jingli",-50);
	}
	me->start_perform(3, "��Ѫ����");
	me->start_busy(random(2));
	message_vision(msg, me, target);
	return 1;
}

string perform_name(){ return HIC"��Ѫ����"NOR; }

int help(object me)
{
        write(HIC"\n��������֮����Ѫ���𡹣�"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 400 ���ϣ�
                ��ǰ���� 200 ���ϣ�
                �������Ƶȼ� 120 ���ϣ�
                ���޾�������ʥ���񹦵ȼ� 120 ���ϣ�
                �����Ṧ�ȼ� 120 ���ϣ�
                �����Ʒ�Ϊ�������ƣ�
                �����м�Ϊ�������ƻ�Ǭ����Ų�ơ�

HELP
        );
        return 1;
}
