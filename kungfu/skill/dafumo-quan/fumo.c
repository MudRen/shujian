#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int ap, dp;

	if( !target ) target = offensive_target(me);

	if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��ħֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_skill("dafumo-quan", 1) < 200 )
		return notify_fail("��Ĵ��ħȭ������죬�޷�ʹ�÷�ħ��\n");

	if( me->query_skill("jiuyin-zhengong", 1) < 200 )
		return notify_fail("��ľ����湦������죬�޷�ʹ�÷�ħ��\n");

	if( me->query_temp("weapon"))
		return notify_fail("������������\n");

	if (me->query_skill_prepared("cuff") != "dafumo-quan"
	|| me->query_skill_mapped("parry") != "dafumo-quan")
		return notify_fail("�������޷�ʹ�÷�ħ��\n");

	if (me->query("max_neili") < 6000)
		return notify_fail("��������������޷�ʹ�÷�ħ��\n");

	if (me->query("neili") < 10000)
		return notify_fail("��������������޷�ʹ�÷�ħ��\n");

	msg = HIY"\n$NͻȻ�۾�һ��������һ������ʹ��ȫ���������ȭ��$n��ȥ��\n";

	ap = me->query("combat_exp") /1000 * me->query_dex(1);
	dp = target->query("combat_exp") /1000 * target->query_dex(1);

	if( random( ap + dp)  > dp ) {
		msg += HIR"$n��������������С����$nֻ����һ��ǿ���ľ������������Լ���������\n";
		msg += HIR"$nֻ���õ������絶���Ϣֱ����������\n"NOR;
		target->add("max_neili",-(random(me->query_skill("dafumo-quan",1)/15)+5));
		target->set("neili",0);
		target->set("jiali",0);
		me->set("neili", 0);
		me->set("jiali", 0);
	}
	else
		msg += CYN"$n���������ң���æ����һ�ԡ�\n" NOR;

	me->start_perform(5, "��ħ");
	message_vision(msg, me, target);
	me->start_busy(random(3));
	return 1;
}

string perform_name(){ return HIY"��ħ"NOR; }

int help(object me)
{
        write(HIY"\n���ħȭ֮����ħ����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 10000 ���ϣ�
                ������� 6000 ���ϣ�
                ��ǰ���� 1500 ���ϣ�
                ���ħȭ�ȼ� 200 ���ϣ�
                �����湦�ȼ� 200 ���ϣ�
                ����ȭ��Ϊ���ħȭ��
                �����м�Ϊ���ħȭ��
                ��ȭ��Ϊ���ħȭ��
                �����ޱ�����

HELP
        );
        return 1;
}
