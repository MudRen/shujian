// delate.c
// by augx@sj 4/4/2002

#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me)
{
	write(@HELP
ָ���ʽ : delate/tanhe
�����Լ����ɵİ���������������ʱҲ�ܵ������������������˳������ɣ�
��û�о�����ʧ��������ǵİ������������죬�����õ�����ͬ�⣻�����
�ǵİ������Ļ��������죬�����õ�����ͬ�⣻������ǵİ���ֻ��������
�죬��ֻ��Ҫһ�˵�ͬ�⡣
HELP
	);
	return 1;
}

int main(object me, string arg)
{
	if( !me->query("group/id") )
		return notify_fail("�㻹û�м�������ء�\n");
	if( me->query("group/class") > 3 )
		return notify_fail("��ĵȼ�������\n");
	if( me->query("group/class") == 1 )
		return notify_fail("�Լ������Լ���\n");

	GROUP_D->start_vote(me,me->query("group/id"),me->name()+"���Ҫ��������Ŀǰ��"+GROUP_D->get_member_class(me->query("group/id"),1)+"�������Ƿ�ͬ�⣿(y/n) ","delate",60);
	tell_object(me,"���Ѿ������˵�����������飬������Ҫ�ȴ�����������쵼�˵Ļ�Ӧ��\n");

	return 1;
}
