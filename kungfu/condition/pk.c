// pk

void killer(object me)
{
	if (!me) return;
	if (me->query_condition("killer")) return;
	me->clear_condition("pk");
}

int update_condition(object me, int duration)
{
	if (!userp(me))
		return 0;
	call_out("killer", 1, me);
	return 1;
}

string query_type(object me)
{
	return "killer";
}
