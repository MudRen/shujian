// /kungfu/condition/xu_ruo.c
// by akuma 1:42 PM 1/22/2002

#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
	message_vision("$Nֻ��˫ϥ��������ͷ�麹����������������\n", me);	
	me->receive_damage("jingli", 50);
	me->apply_condition("xu_ruo", duration - 1);
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}
