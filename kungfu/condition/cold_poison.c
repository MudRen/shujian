#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( !living(me) ) {
		message("vision",HIW + me->name() + "ɪɪ������ȫ�����һ�㱡���İ�˪����\n"NOR, environment(me), me);
	}
	else {
		tell_object(me, HIW "��Ȼһ�ɺ������Ʊ�����ѭ���ֱۣ�Ѹ�����׵��������ţ����еĺ��������ˣ�\n" NOR );
		message("vision", HIW + me->name() + "ȫ���������ظ��ֱ�죬����Ƭ�̣��촽Ҳ���ˣ���ɫ����������ס�\n"NOR,
				environment(me), me);
		me->receive_damage("qi", 50+random(50),"��������" );
		if(userp(me))
			me->receive_wound("jing", 50+random(30),"��������");
		else me->receive_wound("jing", 40+random(50),"��������");
	}
	
//	me->add_busy(2);
	if( duration < 2 ) return 0;
	me->apply_condition("cold_poison", duration - 1);
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
