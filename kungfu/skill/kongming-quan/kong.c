// kong.c  
// by tiantian@sj 2000.6.19

#include <ansi.h>

inherit F_SSERVER;

string perform_name(){ return HIW"��"NOR; }

int perform(object me,object target)
{
	int lvl;

	if (!target) target = offensive_target(me);
	if (!target || !me->is_fighting(target))
		return notify_fail("���ա��־�ֻ����ս����ʹ�á�\n");                

	if (me->query_skill("kongming-quan", 1) < 100)
		return notify_fail("��Ŀ���ȭ�в����죬������ʹ�á��ա��־���\n");        
	if (me->query("neili") < 1000)
		return notify_fail("�������������㣬����ʹ�á��ա��־���\n");
    if (!me->query("quest/jiebai/pass"))
        return notify_fail("��û�к��ܲ�ͨ���壬����ʹ�á��ա��־���\n");
	if (me->query_temp("kongming/kong"))
		return notify_fail("������ʹ�á��ա��־���\n");      
//	if (me->query_temp("kongming/ming"))
//		return notify_fail("������ʹ�á������־���\n");      
	message_vision(HIW"\n$Nһȭ�������������˸յľ�����ѧ��$n�;��öԷ�ȭ���������ޣ��Լ�����"
		+"ʹʵ�˹�Ȼ���ԣ�ʹ����Ҳ�Ǽ���Σ�գ����������Ծ���\n"NOR, me,target);
lvl = me->query_skill("kongming-quan",1);

	me->add("neili", -300); 
	me->start_perform(4,"���ա��־�");
	me->set_temp("kongming/kong", 1);

me->add_temp("apply/strength",lvl/10);
me->add_temp("apply/attack",lvl/3);
me->add_temp("apply/parry",lvl/3);


	call_out("remove_effect", me->query_skill("kongming-quan",1)/10, me,lvl);
	return 1;
}

void remove_effect(object me,int lvl )
{
	if (objectp(me)) 
	{
     me->add_temp("apply/strength",-lvl/10);
     me->add_temp("apply/attack",-lvl/3);
     me->add_temp("apply/parry",-lvl/3);
		me->delete_temp("kongming/kong");
		tell_object(me, HIW"\n�㻺�����������������뵤�\n"NOR);
	}
}
