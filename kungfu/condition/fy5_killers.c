// fy5_killers.c
// Create By lsxk@hsbbs 2007/8/31

#include <login.h>

int update_condition(object me, int duration)
{
       if (duration < 1){
//           me->delete_temp("no_fight");
           return 0;
       }
       me->apply_condition("fy5_killers", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "busy";
}
