#include <ansi.h>

int update_condition(object me, int duration)
{
        if (duration < 1)
        {
                
                        tell_object(me, HIR"����Ԯ���Ѿ��ϵ���һ���Ҽ���������������������������ض���������\n"NOR);
                        me->move("/d/city/kedian/pianting");
                        me->delete_temp("was_job");
                        me->unconcious();
                        me->apply_condition("ruanjin_poison", 100);
                
                return 0;
        }
    
                if (duration < 5)
                        tell_object(me, HIR"���˵�Ԯ�����Ͼ�Ҫ�ϵ��ˣ���ץ��ʱ�䣡\n"NOR);
                else if (duration < 10)
                        tell_object(me, HIR"Զ��Ԫ����Ӫ�Ѿ��ƻ�ͨ�����ƺ���һ����������ڼ��ᣡ\n"NOR);
                else
                        tell_object(me, HIR"Զ��Ԫ����Ӫ����һ��ɧ�ң��ƺ�����ע�⵽����ߵ��������ץ��ʱ�䣡\n"NOR);
    
        me->apply_condition("was_check", duration - 1);
        return 1;
}

string query_type()
{
        return "job";
}
