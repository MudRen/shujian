
int main(object me,string sql)
{
	mixed ret;
	if(!sql) return notify_fail("failed\n");
	ret = dbquery(sql);
	if(!ret) return notify_fail("exec failed\n");
	me->start_more(sprintf("·µ»Ø½á¹û£º%O\n",ret));
	return 1;
}