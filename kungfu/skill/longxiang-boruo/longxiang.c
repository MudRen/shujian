// longxiang.c
// modefied by emnil@sj 2/2/00

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount, int count);

int exert(object me, object target)
{
        int skill;

	if ( !me->is_fighting())
		return notify_fail("��ֻ����ս���У��������������ӹ�������\n");

	if ( me->query_skill("longxiang-boruo", 1) < 140)
		return notify_fail("ֻ��������������������߲�֮�󣬲�����ǿ�Լ��Ĺ�������\n");

	if ( me->query("max_neili") < 2000)
		return notify_fail("���������Ϊ̫��������ɡ�\n");

	if ( me->query("neili") < 1000 ) 
		return notify_fail("�������������\n"); 

	if ( me->query_temp("xs/longxiang"))
		return notify_fail("���Ѿ������������ӹ�������\n"); 

	skill = me->query_skill("longxiang-boruo",1) /8;
/*
	if ( me->query_temp("xs/shield"))
		me->add("max_neili",-1);
*/
	if(wizardp(me)) tell_object(me,sprintf("add attack: %d\n",skill));

	message_vision(MAG"\n$NǱ����������������"+CHINESE_D->chinese_number(skill*2/5)+"��������ָ��糣������ɫ����Լ͸��һ�����ţ�\n" NOR, me);

	me->add_temp("apply/attack", skill);
	me->set_temp("xs/longxiang", skill);
	me->add("neili", -250);

	call_out("remove_effect", 1, me, skill, skill*7);

//	me->start_busy(random(2));
	me->start_exert(1, "����");
	return 1;
}

void remove_effect(object me, int amount, int count)
{
	if ( !me || !me->query_temp("xs/longxiang"))
		return;

	if ( count < 1 || !me->is_fighting()) {
		me->add_temp("apply/attack", -amount);
		me->delete_temp("xs/longxiang");
		message_vision(MAG"$N��������һ�����ָֻ��糣��\n" NOR, me);
		return;
	}
	call_out("remove_effect", 1, me, amount, count - 1);
}

string exert_name(){ return MAG"����"NOR; }

int help(object me)
{
        write(MAG"\n���������֮�����󡹣�"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1000 ���ϣ�
                ������� 2000 ���ϣ�
                ����������ȼ� 140 ���ϡ�

HELP
        );
        return 1;
}
