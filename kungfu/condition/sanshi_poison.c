#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
void extra(object me);
int update_condition(object me, int duration)
{
	if (!me|| me->is_ghost()) return 0;
	message("vision", HIB +me->name() + "全身抽搐，全身发麻，无法动弹。\n"NOR,
		environment(me), me);
	tell_object(me, HIB "你感觉全身一阵阵抽搐，全身发麻，无法动弹。\n" NOR );
	me->receive_wound("qi", random(20)+50);
	me->receive_wound("jing", random(20)+50);
	me->receive_damage("jingli", random(20)+50);
	me->add("neili", -random(20)-60);
	me->set_temp("last_damage_from", "三尸脑神毒发作");
	call_out("extra",5,me);
	call_out("extra",10,me);
	call_out("extra",15,me);
	me->apply_condition("sanshi_poison", duration-1);
	if( duration < 2 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}

void extra(object me)
{
	if (!me || me->is_ghost()) return 0;
	message("vision", HIB +me->name() + "全身抽搐，全身发麻，无法动弹。\n"NOR,
		environment(me), me);
	tell_object(me, HIB "你感觉全身一阵阵抽搐，全身发麻，无法动弹。\n" NOR );
	me->receive_wound("qi", random(20)+50);
	me->receive_wound("jing", random(20)+50);
	me->receive_damage("jingli", random(20)+50);
	me->set_temp("last_damage_from", "三尸脑神毒发作");
	me->add("neili", -random(20)-60);
}
