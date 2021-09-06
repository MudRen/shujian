#include <ansi.h>

int update_condition(object me, int duration)
{
        if (duration < 1)
        {
                if (me->query_temp("was_job/asked"))
                {
                        tell_object(me, HIR"�����Ļ�����Ȼ�鼰������Ӫ���ж���Ȼʧ�ܣ���ֻ��Ѹ�ٳ��롣\n"NOR);
                        me->move("/d/nanyang/kedian1");
                        me->delete_temp("was_job");
                        me->apply_condition("job_busy", 10);
                }
                return 0;
        }
        if (me->query_temp("was_job/asked"))
        {
                if (duration < 5)
                        tell_object(me, HIR"�����Ļ����Ѿ������쳣��ץ��ʱ�䣡\n"NOR);
                else if (duration < 10)
                        tell_object(me, HIR"�����Ļ����Ѿ�Ѹ������ץ��ʱ�䣡\n"NOR);
                else
                        tell_object(me, HIR"�����Ļ����Ѿ�������ɢ��ץ��ʱ�䣡\n"NOR);
        }
        me->apply_condition("was_job", duration - 1);
        return 1;
}

string query_type()
{
        return "job";
}
