// ql_cooldown.c
// Create By lsxk@hsbbs 2007/11/03

#include <login.h>
#include <ansi.h>

int update_condition(object me, int duration)
{
       if (duration < 1){
           me->delete("ql_spec_attack");
           me->set("quest/bwdh/ql_cooldown",time());
           message_vision(HIC"�������ã�$N�����������������������\n"NOR,me);
           return 0;
       }
       me->apply_condition("ql_spec", duration - 1);
	return 1;
}

string query_type(object me)
{
       return "cooldown";
}
