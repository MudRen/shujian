#include <ansi.h>

int exert(object me)
{
	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������\n");
	if ((int)me->query_skill("jiuyin-zhengong", 1) < 180)
		return notify_fail("��ľ����湦��Ϊ��������\n");
	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");
	if( (int)me->query("eff_jing") >= (int)me->query("max_jing"))
		return notify_fail("��ľ���״̬���á�\n");

	message_vision(HIW"$N��������˿���������������תһ���죬�������ö��ˡ�\n" NOR,me);

        me->receive_curing("jing", (int)me->query_skill("force")*2/3);
	me->add("neili", -100);
	me->start_exert(1);
	me->start_busy(2);
	return 1;
}

string exert_name(){ return HIW"�ƾ���"NOR; }

int help(object me)
{
        write(HIW"\n�����湦֮���ƾ�������"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 500 ���ϣ�
                �����湦�ȼ� 180 ���ϡ�

HELP
        );
        return 1;
}
