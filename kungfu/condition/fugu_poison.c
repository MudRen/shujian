// ��Ѫ���Ƿ� fugu_poison.c
// created by olives@SJ 5/1/2001
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
      if(duration>30)
      	     duration = 30;
       if(me->query("eff_qi")<me->query("max_qi")*3/4)
      {
	     me->receive_damage("qi",me->query_condition("fugu_poison")*100);
	     me->receive_wound("qi",me->query_condition("fugu_poison")*50);
	     if(!objectp(me->query_temp("last_damage_from")))
	     	me->set_temp("last_damage_from","��Ѫ���Ƿ��ж�����");
	     message_vision(HIR"ֻ��$N�˿�����ð��һ����̣�$N���ɵ��沿һ��鴤������һ�󶶶���\n"NOR,me);
             me->apply_condition("fugu_poison",duration-random(2));
       	     me->add_busy(1);
      }
      if( duration < 1 ) return 0;
      return CND_CONTINUE;
}

string query_type(object me)
{
        return "wound";
}
