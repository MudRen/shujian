
int update_condition(object me, int duration)
{
	if (duration < 2) {
		tell_object(me, "��ɱ���������\n");
		return 0;
	}
	me->apply_condition("ansha_job", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "job";
}