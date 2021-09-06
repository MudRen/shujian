//wd_job.c

#include <login.h>
#include <ansi.h>
int update_condition(object me, int duration)
{
        if (duration < 1) {               
me->clear_condition("jn_job");
                }
        if (!duration) return 0;
 me->apply_condition("jn_job", duration - 1);
        return 1;
}

string query_type(object me)
{
        return "job";
}
