// condition relax.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	mixed where;

	if (duration < 2) {
		message_vision(MAG"\nͻȻƮ��һλ��ɫ��Ů����$N�����뿪�ˡ�\n\n"NOR, me);
		if (!stringp(where = me->query("relax_timeout_room")))
			if (me->query("enter_wuguan"))
				where = START_ROOM;
			else
				where = REVIVE_ROOM;
		me->delete("relax_timeout_room");
		me->move(where);
		me->set("startroom", where);
		me->save();
		message_vision(HIY "һλ��ɫ��Ů����$N���˹�����\n" NOR, me);
		tell_object(me, HIY "�����ڶ��߶���˵������ξͷ����㣬�´ζ������ģ�\n" NOR);
		return 0;
	}

	if(!objectp(where = environment(me)))
		me->move(RELAX_ROOM);

	if (duration > 1 && base_name(where) != RELAX_ROOM) {
		message_vision(HIR "\nһλ�������������´�����$N��˵�������ף��һ�Դ����ʲôʱ�����������ˣ�����һ�ȥ�ɣ���\n" NOR, me);
		message_vision("���˴���$N���������뿪�ˡ�\n", me);
//		me->set("eff_qi", 1);
//		me->set("qi", 1);
//		duration = me->query("rules")*90;
		me->move(RELAX_ROOM);
		message_vision(HIY "һλ���˴���$N���˹�����\n" NOR, me);
	}
        if (duration % 6 == 0) message_vision("һ������˵����$N���д�Լ"+chinese_number(duration/6)+"���ӵĽ���ʱ�䡣\n", me);
	me->apply_condition("relax", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "relax";
}
