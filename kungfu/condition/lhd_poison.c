#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if(!living(me)) {
      		message("vision", me->name() + "ȫ���ڣ�ɢ����һ�󽹺�ζ��\n", environment(me), me);
   	}
	else {
      	tell_object(me, HIR "��Ȼ��ը�˵ĵط�����һ���ʹ��\n" NOR );
      	tell_room(environment(me), HIR "һ�󽹺���ζ����"+ me->name()+"���ϴ��˳�����"+ me->name()+"����������ֹ��\n" NOR,
                ({ me })); 
	}	
      	me->receive_damage("qi", 2000);
      	me->set_temp("last_damage_from", "�������׻�ը");
      	if(userp(me))
        	me->receive_wound("jing", 2000);
      	else me->receive_wound("jing", 3000);
	me->add_busy(2);
      		me->apply_condition("lhd_poison", duration - 1);
   	if( duration < 1 ) return 0;
   	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
