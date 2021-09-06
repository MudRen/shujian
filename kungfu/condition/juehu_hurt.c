#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{  
	if( !living(me))
		message("vision", me->name() + "����һ����£�������ݡ��������졣\n", environment(me), me);
	else {
		tell_object(me, HIB "���Ȼ�е����ھ�Ԫ��й��ͷ������ġ�\n" NOR );
		message("vision", HIB+ me->name(1) + "ͻȻ���ȷ������ֱ���һ�ţ����ֱ������\n"NOR, environment(me), me);
	}
	me->receive_wound("jing", 50 , "��Ԫ�ݽ߶�");
	me->add_busy(2);
	me->apply_condition("juehu_hurt", duration - 1);
	if( duration < 2 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}
