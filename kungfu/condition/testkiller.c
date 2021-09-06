// killer.c

#include <ansi.h>
#define JAIL_ROOM  "/d/wizard/wizard_jail"

int update_condition(object me, int duration)
{
        object where;
        where = environment(me);
        if ((duration > 220) && (file_name(where) != JAIL_ROOM))
        {
                message_vision(HIW"\n$Nɱ��������Ѫծ�ѳ����ٸ�ͨ����ܳ�ʱ���ˣ������\n�����ˣ�����ʵʵ�����߰ɡ�\n\n"NOR, me);
                me->move(JAIL_ROOM);
                me->set("jail_timeout_room",(string)file_name(where));
                me->set("startroom", JAIL_ROOM);
                message("channel:chat", HIC "\n���ٸ���Ϣ����"+(string)me->query("name")+"��Ϊɱ�����顢���񼫣�������ץ��������Ѻ��\n\n" NOR, users());
                return 1;
        }
        if (duration < 1) {
                tell_object(me, "�ٸ�����ͨ�����ˣ�\n");
                return 0;
        }
        if ((duration < 100) && (file_name(where) == JAIL_ROOM))
        {
                message_vision(HIW"\n������$N���лڹ�֮�⣬��׼$N��ȥ���мǲ�����Ϊ�����������򶨲����ģ�\n\n"NOR, me);
                me->move((string)me->query("jail_timeout_room"));
                return 1;
        }
        me->apply_condition("killer", duration - 1);
        return 1;
}

string query_type(object me)
{
        return "killer";
}
