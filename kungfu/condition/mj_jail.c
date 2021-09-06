// mj_jail.c
#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	object where;
	if (duration < 2) {
		me->move("/d/mingjiao/shaqiu2");
		message("vision",HIY "������һ������������´α������ټ����㡱��ԭ����һ��ȫ����͸�˵ļһ���ӵ���ɳĮ��\n"NOR, environment(me), me);
		tell_object(me, HIY "ֻ��������̧���ϣ���������ر��ӵ���ɳĮ֮�У�\n" NOR);
		me->set("startroom", START_ROOM);
		return 0;
        }

	where = environment(me);
	if ( !wizardp(me) && base_name(where)!="/d/mingjiao/jianyu") {
		message_vision(HIR "ͻȻ����������̸��֣���$N�Ұ�����......\n" NOR, me);
		me->unconcious();
		message_vision("���̸��ֿ���������ȥ��$N���ﳤ��ȥ��\n", me);
		me->move("/d/mingjiao/jianyu");
		me->set("eff_qi", 1);
		me->set("qi", 1);
		duration = 120;
	}
	me->apply_condition("mj_jail", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "jail";
}
