// juehu.c ���������֡�������perform

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if ( me->is_fighting())
		return notify_fail("ս�������ˣ���������\n");

	if( !target ) target = me;

	if ( target != me && !present(target, environment(me)))
		return notify_fail("û������˰���\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ�á����ˡ���\n");  

	if( me->query_skill("juehu-shou", 1) < 200 )
		return notify_fail("��Ļ�צ�����ֲ�����죬����ʹ�á����ˡ���\n");

	if( me->query_skill("yinyun-ziqi", 1) < 200 )
		return notify_fail("��������������ߣ������á����ˡ���\n");

	if ( me->query_skill("medicine", 1) < 120 )
		return notify_fail("��ı�������ȼ�������\n");

	if ( target->is_fighting())
		return notify_fail("ս�������ˣ���������\n");

	if ( ! target->query_condition("juehu_hurt")){
		if ( target == me)
			return notify_fail("��û���ܡ�������֮�˰���\n");
		else
			return notify_fail( target->name(1)+"��û���ܡ�������֮�ˡ�\n");
	}

	if ( me->query_skill_prepared("hand") != "juehu-shou"
	|| me->query_skill_mapped("parry") != "juehu-shou" )
		return notify_fail("�����ڲ���ʹ�á����ˡ���\n");

	if( me->query("neili") < 1500  || me->query("max_neili") < 2000)
		return notify_fail("����������̫�����������������ˡ���\n");

	if ( target == me) {
		msg = HIC"\n$N����һ�����󻺻����£�����Ϊָ����ס�Լ��ļ���ҪѨ������$N��ʼͷð����������������Щ�ˡ�\n"NOR;
		message_vision(msg, me);
	}
	else {
		msg = HIC"\n$N����һ�����󻺻����£�����Ϊָ����ס$n�ļ���ҪѨ������$n��ʼͷð����������������Щ�ˡ�\n"NOR;
		message_vision(msg, me, target);
	}
	target->add_condition("juehu_hurt", - me->query_skill("juehu-shou", 1)/10);

	me->add("neili", -500);
	me->add("max_neili", -5);
	me->start_busy(random(2));
	me->start_perform(3, "����");
	return 1;
}

string perform_name(){ return HIC"����"NOR; }

int help(object me)
{
        write(HIC"\n��צ������֮�����ˡ���"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1500 ���ϣ�
                ��ǰ���� 2000 ���ϣ�
                ��צ�����ֵȼ� 200 ���ϣ�
                �������ȼ� 200 ���ϣ�
                ��������ȼ� 120 ���ϣ�
                �����м�Ϊ��צ�����֣�
                �����ҶԷ����Լ����˾����ˡ�

HELP
        );
        return 1;
}
                                                                                                                                           