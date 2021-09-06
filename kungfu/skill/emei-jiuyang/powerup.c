// Exert: PowerUp.c ���Ҿ���������
// Date : AHA 97/06/29

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if( target != me ) 
		return notify_fail("���Ҿ�����ֻ�����������Լ���ս������\n");

	if (!me->is_fighting())
		return notify_fail("��ֻ����ս�����ö��Ҿ�����������ս������\n");

	if( (int)me->query("neili") < 100  ) 
		return notify_fail("�������������\n");
	if( (int)me->query_temp("powerup") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = me->query_skill("force");
	me->add("neili", -100);

	message_vision(HIY "$N����һ������������Ҿ�������˫Ŀ�����һ��������������������"
        		"����������\n" NOR, me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("powerup", 1);

	me->start_call_out( (: call_other, this_object(), "remove_effect", 
                         me, skill/3 :), skill);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->delete_temp("powerup");
	tell_object(me, "��Ķ��Ҿ�����������ϣ��������ջص��\n");
}
