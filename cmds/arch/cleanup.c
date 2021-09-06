// cleanup.c

inherit F_CLEAN_UP;

int main(object me, string str)
{
       object *ob_list;
	int old_size, i;
	int flag = 0;

	if (!str) return notify_fail("ָ���ʽ��cleanup <����>\n"); 

	seteuid(getuid());
	if (sscanf(str, "-a %s", str)) flag = 1;
	str = resolve_path(me->query("cwd"), str);
	ob_list = children(str);
	old_size = sizeof(ob_list);
	ob_list->clean_up();
	ob_list -= ({ 0 });
	for(i=0; i<sizeof(ob_list); i++) {
		if (i % 20 == 0) reset_eval_cost();
		if( flag || (ob_list[i] && clonep(ob_list[i]) && !environment(ob_list[i])))
			destruct(ob_list[i]);
	}
	ob_list -= ({ 0 });
	printf("��� %d �������\n", old_size - sizeof(ob_list));
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��cleanup <����>

������ָ��������������� clean_up������������б����Ƴ����ģ�������û��
��������һ������е�ɢʧ�����
HELP
	);
	return 1;
}

