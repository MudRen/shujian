#include <ansi.h> // ����condition  �޸�by hongba

int update_condition(object me, int duration)
{
        if (duration < 1)
        {
                if (me->query_temp("hby_job/asked"))
                {
                        tell_object(me, HIR"�����Ĺ���䡱��һ��̮���ˣ���ֻ���㬵��뿪������δ����\n"NOR);
                        me->move("/d/xiangyang/damen");
                        me->delete_temp("hby_job");
                        me->apply_condition("job_busy", 10);
                }
                return 0;
        }
        if (me->query_temp("hby_job/asked"))
        {
                if (duration < 20)
                        tell_object(me, YEL"�����ĹͻȻ����һ���𶯣��������������ˣ�\n"NOR);
                else if (duration < 40)
                        tell_object(me, YEL"�����Ĺ����Խ��Խ���ң�����������ˣ�\n"NOR);
                else
                        tell_object(me, YEL"�����Ĺ��ʼ�Ӷ��ϵ���ɳʯ������ץ���ˣ�\n"NOR);
        }
        me->apply_condition("hby_job", duration - 1);
        return 1;
}

string query_type()
{
        return "job";
}

