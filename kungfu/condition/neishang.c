// Created by snowman@SJ 08/12/2000

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

#include <combat_msg.h>

int update_condition(object me, int duration)
{
      	int damage, j;
      	
        damage = me->query_condition("neishang") + 10;
        damage *= me->query_con() + random(20);
      	if( me->is_fighting() ) damage *= 2;
      	if( !userp(me) ) damage += random(damage);
      
      	if( living(me) ){
      		tell_object(me, "ͻȻ��о��ؿ���ʹ�쳣���ղű����е��߹Ǵ�����Ҫ�ѿ����Ƶģ���ѪҲ�ӿ������˳�����\n");
      		tell_room(environment(me), "\n"+HIR + me->name()+"ͻȻһ�Բ�����˫�����أ��ŵ��㵹���������������۵�һ���³�����Ѫ����\n" NOR,({ me }));
	}
	else tell_room(environment(me), "\n"+HIR + me->name()+"ͻȻȫ��һ��һ�����Ѫ���˳�����\n" NOR,({ me }));
	me->add_busy(2);
	
	me->receive_damage("qi", damage);
	if( damage/3 < me->query("qi") )
		me->receive_wound("qi", damage/3);

	else {
		me->receive_wound("qi", me->query("qi")-1);
		message_vision("( $N"RED"���˹��أ��Ѿ�������в�����ʱ�����ܶ����� )\n"NOR, me);
		return 0;
	}
      	j = (int)me->query("qi")*100/(int)me->query("max_qi");
      	if(living(me)) 
             	message_vision("( $N"+(random(2)?status_msg(j):eff_status_msg(j))+" )\n", me);
      	me->apply_condition("neishang", duration - 1);
   	if( duration < 1 )
   		return 0;
   	return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}
