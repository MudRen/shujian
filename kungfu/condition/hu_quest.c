#include <ansi.h>
int update_condition(object me, int duration)
{                                        
        object bing;
        if (duration < 5) {
            tell_object(me, HBRED"ͻȻһ��Ԫ�����������㹥����\n"NOR);
            tell_object(me, HBRED"��ط���������������Ϊ�����Ѿ��ˡ�\n"NOR);
            bing = new("/d/xiangyang/npc/bing");
            bing->move(environment(me));
            bing->kill_ob(me);
            bing->set_leader(me);
            return 0;        
        }
        me->apply_condition("hu_quest", duration - 1);
        return 1;
}

