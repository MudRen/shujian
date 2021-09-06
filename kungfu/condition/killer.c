// killer
#include <ansi.h>
#include <login.h>
#define JAIL_ROOM "/d/city/laofang"

private int clear_at_room(object ob)
{
	if(!ob) return 0;
	if(!interactive(ob)) return 0;
		
	if(ob->query("no_pk")) return 0;
		
	return 1;
}

int update_condition(object me, int duration)
{
	mixed where;
	int pk;

	if (!userp(me))
		return 0;
	where = environment(me);
        pk = me->query_condition("pk");
        
        if(duration > 90 && base_name(where) != JAIL_ROOM && me->query("no_pk") ) {
        	message_vision(HIW"\nһȺ����Χס$N����ͷ��һ�����һ����"+HIR+"�����ˣ�"+HIW+"��$N���뷴����ͻȻһ�뵽�Լ��Ѿ�����ϴ�֣���̾һ���α���������ˡ�\n\n"NOR, me);
        	me->unconcious();
        	me->move(JAIL_ROOM);
		me->set("jail_timeout_room", base_name(where));
		me->set("startroom", JAIL_ROOM);
		message("channel:chat", HIC "\n���ٸ���Ϣ��"+(string)me->query("name")+"��Ϊ�����ˡ����񼫣�������ץ��������Ѻ��\n\n" NOR, users());
		me->apply_condition("killer", 270);
		return 1;
        }
/*
	if (duration > 270 && base_name(where) != JAIL_ROOM) {
		message_vision(HIW"\n$N�����ˣ�Ѫծ�ѳ����ٸ�ͨ����ܳ�ʱ���ˣ�����ܲ����ˣ�����ʵʵ�����߰ɡ�\n\n"NOR, me);
		me->move(JAIL_ROOM);
		me->set("jail_timeout_room", base_name(where));
		me->set("startroom", JAIL_ROOM);
		message("channel:chat", HIC "\n���ٸ���Ϣ��"+(string)me->query("name")+"��Ϊ�����ˡ����񼫣�������ץ��������Ѻ��\n\n" NOR, users());
		me->apply_condition("killer", 270);
		return 1;
	}
*/
	if (!me->query("no_pk") && duration <= 150 && base_name(where) == JAIL_ROOM) {
		message_vision(HIW"\n������$N���лڹ�֮�⣬��׼$N��ȥ���мǲ�����Ϊ�����������򶨲����ģ�\n\n"NOR, me);
		message("channel:chat", HIC "\n���ٸ���Ϣ��"+me->query("name")+"���лڸ�֮�⣬������׼����ȥ���Թۺ�Ч��\n\n" NOR, users(), me);
		where = me->query("jail_timout_room");
		if (where && (where = load_object(where)) && !where->is_character()) {
			me->move(where);
			me->delete("jail_timout_room");
		}
		else me->move(REVIVE_ROOM);
		return 1;
	}
			
	if(me->query_condition("relax"))//�ؽ��ղ����� tj time
		return 1;

	if ( pk && (!living(me) || sizeof(filter_array(all_inventory(environment(me)) - ({ me }), (: clear_at_room :)))))
		return 1;
	if (duration < 2) {
		if(base_name(where)==JAIL_ROOM && me->query("no_pk"))
		{
			message_vision(HIW"\n������$N���лڹ�֮�⣬��׼$N��ȥ���мǲ�����Ϊ�����������򶨲����ģ�\n\n"NOR, me);
			message("channel:chat", HIC "\n���ٸ���Ϣ��"+me->query("name")+"���лڸ�֮�⣬������׼����ȥ���Թۺ�Ч��\n\n" NOR, users(), me);
			where = me->query("jail_timout_room");
			if (where && (where = load_object(where)) && !where->is_character()) {
				me->move(where);
				me->delete("jail_timout_room");
			}
			else me->move(REVIVE_ROOM);
		}
		else tell_object(me, "�ٸ�����ͨ�����ˣ�\n");
		return 0;
	}
	if (pk && (duration < 10 || !(duration % 10) && base_name(where) != JAIL_ROOM))
		message("channel:rumor",
			HIM "��ҥ�ԡ�ĳ�ˣ����˿���"+me->query("name")+"��"+TASK_D->get_regions(base_name(where))
			+strip(where->query("short"))+"�������֣�\n" NOR, users(), me
		);
	if (!pk || duration % 10 || interactive(me) && query_idle(me) < 15)
		me->apply_condition("killer", duration - 1);
	else
		me->apply_condition("killer", duration - random(2));
	return 1;
}

string query_type(object me)
{
	return "killer";
}
