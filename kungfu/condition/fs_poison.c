#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
	if( !living(me))
		message("vision", HIB+ me->name() + "ʹ��غ���һ����\n", environment(me), me);
	else {
		tell_object(me, HIB "��ͻȻ����һ�ɶ���Ӹ������𣬲�����Ż������\n" NOR );
		tell_room(environment(me), HIB + me->name()+"���ϸ���һ��������Ų����ǣ�ͻȻ�³�һ�ѻ��\n" NOR, ({ me }));
	}
	me->receive_wound("qi", 200, "��ʬ������");
	me->receive_wound("jing", 150, "��ʬ������");
	me->add_busy(2);
	if( duration < 1 ) return 0;
	me->apply_condition("fs_poison", duration - 1); 
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
 