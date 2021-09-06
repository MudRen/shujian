#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if( !living(me) ) {
                message("vision", me->name() + "���Ŵ�������ɫ��졣\n", environment(me), me);
        }
        else {
                tell_object(me, RED "��ֻ�������������ͣ��ƺ������ڻ�¯��һ������Ϊ���ܣ�\n" NOR );
                message("vision", me->name() + "ͻȻ��ɫһ�죬����һ������ͷ�����ֱ���Լ�ɼ��߰ߺ�㣬��Ϊ�ֲ���\n",
                        environment(me), me);
        }
        me->receive_damage("qi", 25);
        me->receive_wound("jing", 20);
        me->set_temp("last_damage_from", "�ȶ�����");
        me->apply_condition("warm_poison", duration - 1);
        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}

string query_type(object me)
{
        return "poison";
}
