#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   
      tell_object(me, HIB "ͻȻ��о���֫������ƺ�������㣡\n" NOR );
      tell_room(environment(me), HIB + me->name()+"ͻȻȫ��һ����������������ȫ�ɺ�ɫ��������˳���ֱ�����������\n" NOR,
                ({ me }));     
  
      me->receive_damage("qi", 30);
      if(userp(me))
          me->receive_wound("jing", 5);
      else me->receive_wound("jing", 5);
	me->add_busy(2);
      me->set_temp("last_damage_from", "�б������붾");
      if( duration < 2 ) return 0;
	me->apply_condition("bing_poison", duration - 1);
      return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
