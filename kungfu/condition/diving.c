#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int l_temp; 

	me->set_temp("last_damage_from", "��ˮ��");
	if(living(me)) {
		tell_object(me, HIY "���޷��������������٣�ͷ�ԡ����ˡ��졣\n" NOR );
		message("vision", me->name() + "���ѵغ���һ�����������ӿ첻���ˡ�\n", environment(me), me);
	}
	l_temp=120-(int)me->query_skill("force", 1)/5;
	me->add("qi",-l_temp);
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "drown";
}
