// pot_job.c

int update_condition(object me, int duration)
{
	if (duration < 2) return 0;
		me->apply_condition("pot_job", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "job";
}
