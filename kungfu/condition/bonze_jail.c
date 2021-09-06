// bonze_jail.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
      object where;
	if (duration < 1) {
		me->move("/d/shaolin/guangchang");
		message("vision",
			HIY "ֻ��ƹ��һ����������һ��������һ����\n"
			"ԭ����һ���������ļһ�Ӵ����ﱻ���˳�����\n" NOR, environment(me), me);
		tell_object(me, HIY "ֻ��һ�����Ƽ���㣬��������ر��ӳ��������£�\n" NOR);
		me->set("startroom", START_ROOM);
		return 0;
	}
	if (!duration) return 0;
        where = environment(me);
        if (duration >= 1 && base_name(where)!="/d/shaolin/jianyu") {		
		message_vision(HIR "\nͻȻ�����һ��Ⱥɮ����ָ��$N���������������ӷ������ӵ��Ķ�ȥ����
���ű����Ұ����£���ʱ��$N��û�����ȥ......\n" NOR, me);
                me->unconcious();
                message_vision("ɮ���ǿ���������ȥ��$N�������������ȥ�ˡ�\n", me);
                me->set("eff_qi", 1);
                me->set("qi", 1);
                me->apply_condition("bonze_jail", 120);
                me->move("/d/shaolin/jianyu");
                message("vision",
			HIY "ֻ��ƹ��һ����������һ��������һ����\n"
			"ԭ����һ���������ļһﱻ���˽�����\n" NOR, environment(me), me);
	}
	me->apply_condition("bonze_jail", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "jail";
}
