#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( !living(me) ) {
      message("vision", me->name() + "��ʹ���̣��������С�\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "ͻȻ����һ���ʹ���絶����е��̲���¶�涾�����ˣ�\n" NOR );
      message("vision", me->name() + "�鴤��һ�ţ���ɫ���Ϻ��࣬���ڵ��ϰ��š�\n",
            environment(me), me);
   }
      me->receive_damage("qi", random(20)+50);
      if(userp(me))
           me->receive_wound("jing", 30+random(30));
      else me->receive_wound("jing", 50+random(30));      
	me->add_busy(2); 
      me->apply_condition("lvbo_poison", duration - 1);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
