// qingtuoluohua.c �����޻���
// cck 17/6/97

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( !living(me) )
	{
		message("vision", me->name() + "ʹ���������һ����\n", environment(me), me);
	}

	else
	{
		tell_object(me, HIB "ͻȻ����ǰ���ģ�����������е������޻��������ˣ�\n" NOR );
		message("vision", me->name() + "ͻȻ��Ƥ�´���ͫ�׷Ŵ󣬿ڴ����ϣ���·���ȣ�����Ҳ��ú�������������\n",
				environment(me), me);
	}

		me->receive_damage("qi", 35);
		me->receive_wound("jing", 20);
		me->set_temp("last_damage_from", "ҩ������");
		me->apply_condition("qtlh_poi", duration - 1);

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
