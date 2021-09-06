// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        me->receive_wound("jing", 1);
        me->receive_damage("jing", 1);
	me->set_temp("last_damage_from", "�߶�����");
	me->apply_condition("snake_poison", duration - 1);
	if (living(me))
		message_vision(BLU "$N���۷�ֱ������ɪɪ����������\n" NOR, me);
	else
		message_vision(BLU "$Nʹ���������һ����\n" NOR, me);
	me->add_busy(2); 
	if( duration < 1 ) return 0;
	return 1;
}

string query_type(object me)
{
	return "poison";
}
