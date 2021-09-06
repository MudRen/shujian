#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me,int duration)
{
	if(!environment(me)) return CND_CONTINUE; 
	me->receive_wound("qi",600);
	me->receive_wound("jing",400);
	me->add_busy(2);
	me->set_temp("last_damage_from","���ĺ��Ķ�����");
	if( !living(me) ) message("vision",HIR+ me->name() + HIR"������������ý�Ӳ��\n"NOR, environment(me), me);
	else 
		message_vision(HIR"$N˫ϥ������������������������������Ц��Ц�����鼫�ǹ��졣\n"NOR,me);
	if(duration < 1) return 0;
	me->apply_condition("haitang_poison",duration - 1);
	return CND_CONTINUE;
}

string query_type(object me)
{
        return "poison";
}