#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	message("vision", me->name() + "�����鸡���ƺ�����ȫʧ�ˡ�\n", environment(me), me);
	if (living(me)) {
		tell_object(me, HIR "������鸡���޷�ƽ�⡣\n" NOR );
	}
	me->set("neili",0);
	me->add_busy(2);
        me->apply_condition("ruanjin_poison", duration - random(2));
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "wound";
}
