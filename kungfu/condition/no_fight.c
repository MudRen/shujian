// no_fight.c
// Create By lsxk@hsbbs 2007/6/3

#include <login.h>

int update_condition(object me, int duration)
{
       if (duration < 1){
           me->delete_temp("no_fight");
           return 0;
       }
       me->apply_condition("no_fight", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "busy";
}
