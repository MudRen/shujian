#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( !living(me) ) {
      message("vision", me->name() + "ʹ��غ���һ����\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "��ֻ�����ظ������٣�����֫������\n" NOR );
      message("vision", HIB+me->name() + "���š���һ�������ŵ�ü������͸��һ����Ρ�\n"NOR,
            environment(me), me);
   }
      me->receive_damage("qi", 80);
      if(userp(me))
           me->receive_wound("jing", 40+random(20));
      else me->receive_wound("jing", 50+random(30));      
	me->add_busy(1+random(2));
      me->apply_condition("tz_poison", duration - 1);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
string query_type(object me)
{
        return "poison";
}

