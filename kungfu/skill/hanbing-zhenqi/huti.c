// huti.c

#include <ansi.h>

int exert(object me, object target)
{
	int skill;
	string msg;

	if (me->query_temp("hbzq/huti"))
		return notify_fail("���Ѿ���ʹ�á����塹�ˡ�\n");

	if (me->query_skill("hanbing-zhenqi",1) < 100)
		return notify_fail("��ġ����������������������޷�ʩ�á����塹��\n");

	if (me->query("max_neili") < 1000)
		return notify_fail("��������������޷�ʹ�á����塹��\n");

	if (me->query("neili") < 500)
		return notify_fail("��������������޷�ʹ�á����塹��\n");

	me->add("neili", - 250);
	msg = HIB"$NĬ�������������Խ��ԽŨ���������Լ������˹���������\n"NOR;

    //����һ��huti Ч��
	skill = me->query_skill("hanbing-zhenqi",1)/3;
	me->add_temp("apply/dodge", skill);
	me->add_temp("apply/parry", skill);
	me->set_temp("hbzq/huti", skill);

	call_out("remove_effect", skill * 2, me);
	if (me->is_fighting())
		me->start_busy(1);
	me->start_exert(1, "���������");
	message_vision(msg, me);
	return 1;
}

void remove_effect(object me)
{
	int skill;
	if (!me || !me->query_temp("hbzq/huti"))
		return;
	skill = me->query_temp("hbzq/huti");
	me->add_temp("apply/dodge", -skill);
	me->add_temp("apply/parry", -skill);
	me->delete_temp("hbzq/huti");
	if (living(me) && ! me->is_ghost())
		message_vision(HIW"$N����ĺ���ɢ�����������𵽱����������ˡ�\n"NOR,me);
}

string exert_name()
{
	return HIB"�����"NOR;
}

int help(object me)
{
	write(HIB"\n��������֮�����������\n\n"NOR);
	write(@HELP
	Ҫ��	���������ȼ� 100 ���ϣ�
		������� 1000 ���ϣ�
		��ǰ���� 500 ���ϡ�

HELP
	);
	return 1;
}
