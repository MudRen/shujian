// gmove.c  ת�ư���
// by augx@sj 4/15/2002

#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me)
{
	write(@HELP
ָ���ʽ :
gmove [վ��Ӣ��id]
�Ѱ��ɿ���Ȩת�Ƶ�ָ��վ�㣬ת�Ʋ���ÿ���糿ϵͳ���а��ɼ����ͬ��ʱִ�С�
ֻ�а����͸�������Ȩ��ִ�д˲�����վ��Ӣ��id���á�mudlist������鿴����ע
���Сд��

HELP
	);
	return 1;
}


int main(object me, string arg)
{
	string gid;

	if( !arg ) return help(me);
	if( !(gid=me->query("group/id")) )
		return notify_fail("�㻹û�д����Լ��İ����ء�\n");
	if( me->query("group/class") > 2 )
		return notify_fail("��ĵȼ�������\n");
	if( !GROUP_D->site_now( gid ) )
		return notify_fail( GROUP_D->get_last_error() );

	if( !GROUP_D->set_site_next(gid,arg) )
		return notify_fail( GROUP_D->get_last_error() );

	write("�������"+GROUP_D->get_group_name(gid)+"�Ŀ���Ȩת�Ƶ�"+arg+"��\n");
	return 1;
}
