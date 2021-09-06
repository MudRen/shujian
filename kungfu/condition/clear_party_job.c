#include <ansi.h>
#include <condition.h>
 
inherit F_CLEAN_UP;
 
int update_condition(object me, int duration)
{
 
       me->apply_condition("clear_party_job", duration - 1);

        if( duration < 1 ) 
         {
             me->delete_temp("party_job_target");
            return 0;
         }
        return CND_CONTINUE;
 } 
 
 string query_type(object me)
 {
     return "job";
 }
