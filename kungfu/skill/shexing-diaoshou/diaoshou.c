// ���ε���  

#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;

void remove_effect(object me, int improve);

int perform(object me, object target)
{
	int skill, j;

	skill = (int)me->query_skill("shexing-diaoshou", 1);

	if( !target ) target = offensive_target(me);

	if( !objectp(target) || !me->is_fighting(target) )
		return notify_fail("�����ε��֡�ֻ����ս����ʹ�á�\n");

	if( me->query_temp("weapon"))
		return notify_fail("������������ô��ʹ�á����ε��֡���\n");   

	if( skill < 160 )
		return notify_fail("������ε��ֲ�����죬ʹ�������ε��֡�\n");

	if(me->query_skill("hamagong",1) < 200 )
		return notify_fail("��ĸ�󡹦������죬ʹ�������ε��֡�\n");

	if(me->query_skill("shexing-diaoshou",1) < 200 )
		return notify_fail("����������ε��ֲ�����죬ʹ�������ε��֡�\n");

	if (me->query_skill_mapped("parry") != "shexing-diaoshou" 
	|| me->query_skill_mapped("hand") != "shexing-diaoshou" 
	|| me->query_skill_prepared("hand") != "shexing-diaoshou" )
		return notify_fail("�������޷�ʹ�á����ε��֡���\n");

	if( (int)me->query("max_neili") < 3000)
		return notify_fail("����������̫����ʹ���������ε��֡���\n");      

	if( (int)me->query("neili") < 1500 )
		return notify_fail("����������̫����ʹ���������ε��֡���\n");
		
		if( (int)me->query("jingli") < 1500 )
		return notify_fail("�����ھ���̫�٣�ʹ���������ε��֡���\n");
		
		if( me->is_busy() )
		return notify_fail(me->name() +"����æ�أ�\n");

	message_vision(HIB"\n$N������ؽڽڽڹ�ͨ���ֱ۴�һ���������۵ĽǶȻ���$n��\n"NOR,me,target);

	j = skill/3;
	if ( skill > 200)
		j = to_int(skill/200.0 * skill/3.0);
  me->set_temp("sxds/ds",1);
	me->add_temp("apply/attack", j);
	me->add_temp("apply/hand", j);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	
	if(me->is_fighting(target)) 
	
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
				
	if(me->is_fighting(target)) 
		
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
		
	me->add_temp("apply/attack", -j);
	me->add_temp("apply/hand", -j);

	me->add("neili", -400);
	me->add("jingli", -150);
	me->start_perform(4, "���ε���");
	me->delete_temp("sxds/ds");
	me->start_busy(random(2));
	target->start_busy(random(2));
	
	return 1;
}

string perform_name(){ return HIG"���ε���"NOR; }

int help(object me)
{
	write(RED"\n�������ε���֮�����ε��֡���"NOR"\n");
	write(@HELP

	Ҫ�󣺵�ǰ���� 2500 ���ϣ�
		������� 2000 ���ϣ�
		��ǰ���� 1500���ϣ�
		�������ε��ֵȼ� 200 ���ϣ�
		��󡹦�ȼ� 200 ���ϣ�
		�ڹ���Ч�ȼ� 200 ���ϣ�
HELP
	);
	return 1;
}
