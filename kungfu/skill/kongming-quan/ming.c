// ming.c  
// by tiantian@sj 2000.6.19

#include <ansi.h>

inherit F_SSERVER;

string perform_name(){ return HIC"��"NOR; }

int perform(object me,object target)
{
    
	
	if (!target) target = offensive_target(me);
	if (!target || !me->is_fighting(target))
		return notify_fail("�������־�ֻ����ս����ʹ�á�\n");                

	if (me->query_skill("kongming-quan", 1) < 150)
		return notify_fail("��Ŀ���ȭ�в����죬������ʹ�á������־���\n");        
	if (me->query("neili") < 1000)
		return notify_fail("�������������㣬����ʹ�á������־���\n");
//	if (me->query_temp("kongming/kong"))
//		return notify_fail("������ʹ�á��ա��־���\n");      
    if (!me->query("quest/jiebai/pass"))
        return notify_fail("��û�к��ܲ�ͨ���壬����ʹ�á������־���\n");
	if (me->query_temp("kongming/ming"))
		return notify_fail("������ʹ�á������־���\n");      
	message_vision(HIW"\n$N��Хһ����ȭ����Ȼ�ӿ죬˫��ȭ��ԴԴ������\n"NOR, me);
	me->add("neili", -300); 
	me->start_perform(4,"�������־�");
	me->set_temp("kongming/ming", 1);
	call_out("remove_effect", me->query_skill("kongming-quan",1)/10, me);
	return 1;
}

void remove_effect(object me)
{
	if (objectp(me)) 
	{
		me->delete_temp("kongming/ming");
		tell_object(me, HIW"\n��ȭ��һ�ϣ����ֲ��ɵ�����������\n"NOR);
	}
}
