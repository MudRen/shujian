#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me,int duration)
{
	if(!environment(me)) return CND_CONTINUE;
	me->receive_wound("qi",100);
	me->receive_wound("jing",100);
	me->receive_damage("jingli",me->query_skill("force")*2);
	me->add_busy(2);
	me->set_temp("last_damage_from","�䶾����");
	if( !living(me) ) message("vision", me->name() + "ʹ��غ���һ����\n", environment(me), me);
	else 
		message_vision(HIR"$Nֻ�������ѵ����ƺ���������Ҳ�ڷ��������㲻�������ڵ��Ϲ�����ȥ���������С�\n"NOR,me);
	if(duration < 1) return 0;
	me->apply_condition("yufeng_poison",duration - 1);
	return CND_CONTINUE;
}

string query_type(object me)
{
        return "poison";
}