// ctime.c

int main(object me, string arg)
{
	int t;

	seteuid(geteuid(me));
	if (!arg || sscanf(arg,"%d",t)<1) return notify_fail("ָ���ʽ : ctime <ʱ��>\n");
	tell_object( me , sprintf("%s = %s\n",arg,ctime(t)) );
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : ctime <ʱ��>
 
ת��ʱ���ʽ��
HELP
    );
    return 1;
}
