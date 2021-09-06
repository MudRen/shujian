
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( !living(me))
		message("vision", me->name() + "冷得全身抽搐，已冷成一团。\n", environment(me), me);
	else {
		tell_object(me, WHT "你麻痒难当，直如千千万万只蚂蚁同时在咬啮一般！\n" NOR );
		message("vision", me->name() + "脸上一阵红，一阵白，双手乱舞，情状可怖已极。\n", environment(me), me);
	}
	me->receive_damage("qi", 300+random(300));

	if(userp(me))
		me->receive_wound("jing", 300+random(300));
	else
		me->receive_wound("qi", 500+random(400));

	me->add_busy(10+random(10));
	me->set_temp("last_damage_from", "生死符发作");
	me->apply_condition("shengsi_poison", duration - 1);
	if( duration < 2 ) return 0;
	return CND_CONTINUE & CND_NO_HEAL_UP;
}

string query_type(object me)
{
	return "poison";
}
