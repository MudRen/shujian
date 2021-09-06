#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me,int duration)
{
	if(!environment(me)) return CND_CONTINUE; 
	me->receive_wound("qi",100);
	me->receive_wound("jing",100);
	me->add_busy(2);
	me->set_temp("last_damage_from","���϶�����");
	if( !living(me) ) message("vision", HIW+me->name() + HIW"��ͷ�ϡ��·��ϡ��ֽ��ϣ�����һ�㱡���İ�˪��\n"NOR, environment(me), me);
	else {
		tell_object(me,HIB"��ͻȻ����ʳָ����΢΢һ����һ�ɺ������Ʊ�����ѭ���ֱۣ�Ѹ�����׵��������š�\n"NOR);
		tell_room(environment(me),HIW+me->name() + HIW"��ͷ�ϡ��·��ϡ��ֽ��ϣ�����һ�㱡���İ�˪,����ȫ��ͣ�Ķ��£�\n"NOR,({me}));
		//message("vision", me->name() + "��ͷ�ϡ��·��ϡ��ֽ��ϣ�����һ�㱡���İ�˪,����ȫ��ͣ�Ķ��£�\n", environment(me), me);
	}
	if(duration < 1) return 0;
	me->apply_condition("bingcan_poison",duration - 1);
	return CND_CONTINUE;
}

string query_type(object me)
{
        return "poison";
}
