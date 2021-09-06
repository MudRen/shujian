// alias.c

inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string arg)
{
	mapping alias;
	string verb, replace, *vrbs;

	if( !arg ) {
		alias = me->query_all_alias();
		if( !sizeof(alias) ) {
			write("��Ŀǰ��û���趨�κ� alias��\n");
			return 1;
		} else  {
			write("��Ŀǰ�趨�� alias �У�\n");
			vrbs = sort_array(keys(alias), 1);
			foreach (verb in vrbs)
				write(sprintf("%-15s = %s\n", verb, alias[verb]));
			return 1;
		}
	}
	if( sscanf(arg, "%s %s", verb, replace)!=2 ){
		write("��ȡ���� \""HIR+arg+NOR"\" ���������\n");
		me->set_alias(arg, 0);
	}
	else if(me->find_command(verb))
		return notify_fail("�㲻�ܽ� \""+verb+"\" ָ���趨������;��\n");
	else if( verb=="" )
		return notify_fail("��Ҫ��ʲô alias��\n");
	else   {
		write("��� \""HIR+verb+NOR"\" �趨Ϊ \""HIG+replace+NOR"\" �ɹ���ɡ�\n");
		return me->set_alias(verb, replace);
	}
	write("OK��\n");
	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ : alias <���趨ָ֮��> <ϵͳ�ṩָ֮��>
 
��ʱϵͳ���ṩָ֮����Ҫ����ܳ����ִ�, ��ʹ��ʱ(�����Ǿ����õ���)
�����о�������, ��ʱ�㼴���ô�һָ���趨�����ԭ��ָ֮�
 
����:
	'alias sc score' ���� sc ȡ�� score ָ�
	'alias' �󲻼Ӳ������г������е����ָ�
	'alias sc' ������ sc ������ָ� (���������Ļ�)
 
���п����� $1, $2, $3 .... ��ȡ����һ���ڶ������������������� $* ȡ��
���еĲ������磺
	'alias pb put $1 in $2'

��ÿ����(��)��
	pb bandage bag

�ͻ�ȡ���ɣ�
	put bandage in bag
	
HELP
);
	return 1;
}

