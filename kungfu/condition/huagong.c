#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   
      tell_object(me, HIR "��ֻ�������类���ˣ������������յ����������ӷ��̣�\n" NOR );
      tell_room(environment(me), HIR + me->name()+"ͻȻ���һ�������۷��ף�ˤ���ڵز�ס�ذ��ţ�\n" NOR,
                ({ me }));     
      if( me->query("max_neili", 1) < 1 ) {
                me->set_temp("last_damage_from", "�������󷨻�����Ԫ");
                me->die();
                return 0;
        }
      me->receive_damage("qi", 25);
      me->receive_wound("jing", 5);
      me->add("max_neili", - (2 + random(3)));    
	me->add_busy(2); 
	if( duration < 2 ) return 0;
      me->apply_condition("huagong", duration - 1);
   return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}
