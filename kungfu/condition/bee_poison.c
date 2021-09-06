//bee_poison.c ��䶾
#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	object where=environment(me);
	tell_object(me, MAG"ͻȻ��ֻ�������ѵ����ƺ���������Ҳ�ڷ�����\n" NOR );
	tell_room(environment(me), HIR+me->name()+"��Ȼ���㲻��������"+where->query("short")+HIR"�ĵ��Ϲ�����ȥ���������У�\n" NOR,({ me }));
	me->receive_damage("qi", 50+random(30));
	me->receive_wound("jing", 30+random(30));
	me->add_busy(2);
	me->set_temp("last_damage_from", "����䶾����");
	me->apply_condition("bee_poison", duration - 1);
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
