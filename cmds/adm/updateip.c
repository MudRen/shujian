// updateip.c 

int help(object me);

int main(object me, string arg)
{
	int start;
	int count;
	if (!arg)
	{
		return help(me);
	}

	if (sscanf(arg, "%s %d %d", arg, start, count) == 3)
	{
//                return IP_D->update_ip(me, arg, start, count);
                return "/adm/daemons/ipd2.c"->update_ip(me, arg, start, count);
	}

//        return IP_D->update_ip(me, arg);
        return "/adm/daemons/ipd2.c"->update_ip(me, arg);
}

int help(object me)
{
	write(@HELP
ָ���ʽ��updateip [<�ļ���>|<Ŀ¼��> <��ʼ�ļ�> <�ļ���>]

ָ��˵������IP�ļ�����ϵͳIP�⡣

HELP);

	return 1;
}

