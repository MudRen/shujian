// gm_job.c 

#include <login.h>
#include <ansi.h>
int update_condition(object me, int duration)
{
	if (duration < 1) {
		tell_object(me, HIY "ɽ�µش����������˴��룬�����ȥѲ�߿�����\n" NOR);
		me->delete_temp("gm/job");
		me->delete_temp("meet_nuzi");
		return 0;
	}
	me->apply_condition("gm_job", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "job";
}
