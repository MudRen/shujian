// lingshe.c ���߷���
// Last Modified by sir on 4/26/2001

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "���߷���"
int perform(object me, object target)
{
	int skill;

	skill = (int)me->query_skill("shexing-diaoshou", 1);

	if( !target ) target = offensive_target(me);

	if( !objectp(target) || !me->is_fighting(target) )
		return notify_fail("�����߷��衹ֻ����ս����ʹ�á�\n");

	if( me->query_temp("weapon"))
		return notify_fail("������������ô��ʹ�á����߷��衹��\n");   

	if( skill < 160 )
		return notify_fail("����������߷��費����죬ʹ�������߷��衣\n");

	if(me->query_skill("hamagong",1) < 200 )
		return notify_fail("��ĸ�󡹦������죬ʹ�������߷��衣\n");

	if(me->query_skill("shexing-diaoshou",1) < 200 )
		return notify_fail("����������߷��費����죬ʹ�������߷��衣\n");

	if (me->query_skill_mapped("parry") != "shexing-diaoshou" 
	|| me->query_skill_mapped("hand") != "shexing-diaoshou" 
	|| me->query_skill_prepared("hand") != "shexing-diaoshou" )
		return notify_fail("�������޷�ʹ�á����߷��衹��\n");

	if( (int)me->query("max_neili") < 3000)
		return notify_fail("����������̫����ʹ���������߷��衹��\n");      

	if( (int)me->query("neili") < 1500 )
		return notify_fail("����������̫����ʹ���������߷��衹��\n");
		
		if( (int)me->query("jingli") < 1500 )
		return notify_fail("�����ھ���̫�٣�ʹ���������߷��衹��\n");

	if( target->is_busy() )
		return notify_fail(target->name() +"Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	message_vision(HIC"$N����һ����ֻ��ʳָһ����ָһ��βָһɨ����������Ѱ϶���ֵ���$n������Ѩ��\n"NOR,me,target);
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			message_vision(HIY"\n$Pһ�µ���$p�Ĵ�Ѩ��$pֻ��΢΢һ�飬Ѹ���ж��糣��\n"NOR,me,target);
			me->start_busy(1+random(3));
			me->add("neili", -100);
		} else {
			message_vision(HIY "\n���$p��$P���м���Ѩ��!\n"NOR,me,target);
			target->start_busy(2+random(3));
			me->start_busy(random(2));
			me->add("neili", -100);
		}
	}
	else
	{
		message_vision(HIM "\n$p�鼱����������һԾ���˳���Զ��\n"NOR,me,target);
		me->start_busy(3);
	        if(!target->is_fighting(me) && target->query("owner") && 
		        me->query("id") == target->query("owner"))
	        target->fight_ob(me);
        }
	return 1;
}
string perform_name(){ return HIC"���߷���"NOR; }
