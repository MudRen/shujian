#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int i;

	tell_object(me, HIR"��Ȼһ˿������������𣬻����Ľ�������֫�ٺ���ԭ�����е���Ѫ��צ���˷����ˣ�\n" NOR );
	message("vision", HIR + me->name() + "��Ȼ�о�һ˿������������𣬻����Ľ�����֫�ٺ���\n"NOR, environment(me), me);

	i = me->query_skill("force");
	i = i/2 + random(i/2);
	me->add_busy(2+random(3));
if(i < me->query("qi") )
        me->receive_damage("qi", i, "��Ѫ��צ���˷���");
//     me->apply_condition("nxsz_hurt", duration - 1);
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}
