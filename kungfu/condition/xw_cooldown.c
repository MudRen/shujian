// xw_cooldown.c
// Create By lsxk@hsbbs 2007/11/03

#include <login.h>

int update_condition(object me, int duration)
{
       if (duration < 1){
           return 0;
       }
       me->apply_condition("xw_cooldown", duration - 1);
	return 1;
}

string query_type(object me)
{
       return "cooldown";
}
