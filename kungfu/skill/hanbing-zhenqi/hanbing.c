// by darken@SJ
// Lklv add help at 2001.10.06

#include <ansi.h>
inherit F_SSERVER;
string exert_name(){ return HIW"������"NOR; }

int exert(object me)
{
	string msg;
	int lv;
	lv = me->query_skill("force");

	if (!me->is_fighting())
		return notify_fail("��ֻ����ս����ʹ�á�����������\n");
	
	if (me->query_temp("ss/hb"))
		return notify_fail("������ʹ�á�����������\n");

	if ((int)me->query_skill("hanbing-zhenqi",1) < 100)
		return notify_fail("����Ŀǰ���ڹ���Ϊ���޷�ʹ�á�����������\n");

	if ((int)me->query("max_neili") < 1000)
		return notify_fail("����Ŀǰ��������Ϊ���޷�ʹ�á�����������\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("�������������\n");

	msg = HIW"$N����һ������һ�������㿪ʼ��ת�����ԡ�\n"NOR;
	me->set_temp("ss/hb", 1);
	me->add("neili", -250);
	message_vision(msg, me);
	
	if ((int)me->query_skill("hanbing-zhenqi",1) < 350)
	{
		me->start_busy(random(2));
		me->start_exert(1, "����������");
	}
	call_out("remove_effect", lv/5 + random(10), me);
	return 1;
}

void remove_effect(object me)
{
	if (!me || !me->query_temp("ss/hb")) return;
	message_vision(HIW"$N���ϵĺ���������ɢȥ�ˡ�\n"NOR,me);
	me->delete_temp("ss/hb");
}

int help(object me)
{
	write(HIW"\n��������֮������������"NOR"\n\n");
        write(@HELP
	Ҫ��  �������  1000 ���ϣ�
                ��ǰ����  500  ���ϣ�
                ��������  100  �����ϣ�
HELP
        );
        return 1;
}