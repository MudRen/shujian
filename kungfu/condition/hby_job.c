#include <ansi.h> // 放在condition  修改by hongba

int update_condition(object me, int duration)
{
        if (duration < 1)
        {
                if (me->query_temp("hby_job/asked"))
                {
                        tell_object(me, HIR"秦陵古墓“轰”地一声坍塌了，你只好悻悻地离开，意犹未尽。\n"NOR);
                        me->move("/d/xiangyang/damen");
                        me->delete_temp("hby_job");
                        me->apply_condition("job_busy", 10);
                }
                return 0;
        }
        if (me->query_temp("hby_job/asked"))
        {
                if (duration < 20)
                        tell_object(me, YEL"秦陵古墓突然发起一阵震动，看来出了问题了！\n"NOR);
                else if (duration < 40)
                        tell_object(me, YEL"秦陵古墓的震动越来越猛烈，看来问题大了！\n"NOR);
                else
                        tell_object(me, YEL"秦陵古墓开始从顶上掉落沙石，必须抓紧了！\n"NOR);
        }
        me->apply_condition("hby_job", duration - 1);
        return 1;
}

string query_type()
{
        return "job";
}

