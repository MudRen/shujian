
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( !living(me))
		message("vision", me->name() + "���ȫ��鴤�������һ�š�\n", environment(me), me);
	else {
		tell_object(me, WHT "�������ѵ���ֱ��ǧǧ����ֻ����ͬʱ��ҧ��һ�㣡\n" NOR );
		message("vision", me->name() + "����һ��죬һ��ף�˫�����裬��״�ɲ��Ѽ���\n", environment(me), me);
	}
	me->receive_damage("qi", 300+random(300));

	if(userp(me))
		me->receive_wound("jing", 300+random(300));
	else
		me->receive_wound("qi", 500+random(400));

	me->add_busy(10+random(10));
	me->set_temp("last_damage_from", "����������");
	me->apply_condition("shengsi_poison", duration - 1);
	if( duration < 2 ) return 0;
	return CND_CONTINUE & CND_NO_HEAL_UP;
}

string query_type(object me)
{
	return "poison";
}
