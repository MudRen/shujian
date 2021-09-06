#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
	int i;

	tell_object(me, HIR "��ֻ������Ѫ��ӿ����������ǧ��֧������ҧ�ͣ�ʹ�����̣�\n" NOR );
	tell_room(environment(me), HIR + me->name()+"���Ť������������ס�ͺߣ�����ͣ�Ĳ�����\n" NOR, ({ me }));

	i = 200 + random(150);
	if ( !userp(me)) i *= 2;
	i -= me->query_con();

	if ( me->query_temp("qianzhu")){
		me->receive_wound("qi", i , "��ǧ���򶾹�");
		me->receive_wound("jing", i , "��ǧ���򶾹�");
		me->add_busy(1 + random(3));
	}
	else {
		me->receive_damage("qi", 15, "��ǧ���򶾹�");
		me->receive_wound("jing", 15, "��ǧ���򶾹�");
	}

	if( duration < 2 ) {
		me->delete_temp("qianzhu");
		return 0;
	}
	me->apply_condition("qzhu_poison", duration - 1);
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
