#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	me->apply_condition("yzc_qiankun", duration - 1);
	if( duration < 1 ) return 0;
      
	tell_object(me, HIC "ͻȻ������ĵ����е�ָ���Ҵܣ��������亹ֱð��\n" NOR );
	tell_room(environment(me), HIC + me->name()+"ͻȻһ��������˲��ð������亹��\n" NOR, ({ me }));  
	switch(duration) {
		case 1:	me->add_condition("no_exert", 5); 	break;
		case 3:	me->add_condition("no_perform", 5);	break;
		case 5:	me->add_condition("no_force", 5);	break;
		case 7:	me->add_busy(5); 			break;
		default:
			me->set_temp("last_damage_from", "һָ���ھ�����");
			me->receive_damage("qi", 50);
			me->receive_wound("qi", 50);
			me->add_busy(2);
			break;
	}
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}
