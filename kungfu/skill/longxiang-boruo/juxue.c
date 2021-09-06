// By River@SJ

#include <ansi.h>
void heal_done(object me, int count);

int exert(object me)
{
	int i;
	if (me->is_fighting())
		return notify_fail("ս�����˹����ˣ�������\n");

	if ((int)me->query_skill("longxiang-boruo", 1) < 100)
		return notify_fail("����ڹ���Ϊ��������\n");

	if ((int)me->query_skill("medicine", 1) < 80)
		return notify_fail("��ı���������Ϊ��������\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("�������������\n");

	if( (int)me->query("eff_qi") >= (int)me->query("max_qi"))
		return notify_fail("û������ʲô�ˣ�\n");

	if (me->query("eff_qi")+me->query_temp("apply/qi") < ((me->query("max_qi") + me->query_temp("apply/qi"))/4))
		return notify_fail("���Ѿ����˹��أ����ܲ��������𵴣�\n");

	message_vision(HIW"$N����������Ϣ������������ʼ�˹����ˡ�\n"NOR,me);

	i = me->query("max_qi");
	i -= me->query("eff_qi");
	i /= 500;

	me->receive_curing("qi", 500);
	me->set("qi", me->query("eff_qi"));
	me->add("neili", -100);

	if ( i  > 0 ) {
		call_out("heal_done", 1, me, i);
		me->start_busy(i);
		return 1;
	}
	message_vision(HIW"$N����һ�����������ӵ�վ��������\n"NOR, me);
	me->start_exert(1, "��Ѫ");
	me->start_busy(random(2));
	return 1;
}

void heal_done(object me, int count)
{
	if(!me) return;
	if( me->is_fighting() 
	|| count < 0
	|| me->query("neili") < 200) {
		message_vision(HIW"$N����һ�����������ӵ�վ��������\n"NOR, me);
		me->start_exert(1, "��Ѫ");
		me->start_busy(-1);
		me->start_busy(random(2));
		return;
	}
	me->receive_curing("qi", 500);
	me->set("qi", me->query("eff_qi"));
	me->add("neili", -100 );
	call_out("heal_done", 1, me, count -1);
}

string exert_name(){ return HIW"��Ѫ"NOR; }

int help(object me)
{
        write(HIW"\n���������֮����Ѫ����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1000 ���ϣ�
                ��������ȼ� 80 ���ϣ�
                ����������ȼ� 100 ���ϣ�
                ���˺�������޲�С��ԭ�����޵� 25%��

HELP
        );
        return 1;
}
