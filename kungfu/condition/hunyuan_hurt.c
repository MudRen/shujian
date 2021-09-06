#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{    
      tell_object(me, HIR "���Ȼ�е����ھ�����к��ͷ������ġ�\n" NOR );
      message_vision(HIR"$NͻȻ���ȷ����ȵ�ȫ��������������һ�㡣\n"NOR, me);

      me->receive_damage("qi", 100+random(50));
      me->receive_wound("qi", 50+random(70));

      me->set_temp("last_damage_from", "���˷���");
      me->apply_condition("hunyuan_hurt", duration - 1);
     if( duration < 1 ) return 0;
     return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}
