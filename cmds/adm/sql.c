
int main(object me,string sql)
{
	mixed ret;
        if(!sql) return notify_fail("failed\n");
        if(strsrch(sql,"*")!=-1) return notify_fail("���С�ĵ㣬��㵱���ˡ�\n");
	ret = dbquery(sql);
	if(!ret) return notify_fail("exec failed\n");
	me->start_more(sprintf("���ؽ����%O\n",ret));
	return 1;
}
