// declare war
// by augx@sj 3/28/2002

#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me)
{
	write(@HELP
ָ���ʽ��declare war to [����id]
��ĳ��������ս�������򸱰������Զ�����ս��������Ҫ���˻����ϲ�����ս��
����Է����ɵ����������ˣ���Է����ɱ����������������������ߣ����ܶ�֮
��ս������Է����������������ˣ���ֻҪ�Է�������һ���������ߣ��Ϳɶ�֮
��ս����ս�����뽨����̳�Ҵ�����һǧ���ƽ𣬰���������������15�ˡ�
HELP );
	return 1;
}

int main(object me, string arg)
{
	string gid;
	int i,j;
	mixed res;

	if( !arg || sscanf(arg,"%s to %s",arg,gid)<2 ) return help(me);
	if( arg != "war" ) return help(me);
	if( !me->query("group/id") )
		return notify_fail("�㻹û�м�����ɣ�Ϲ��ʲô����\n");
	if( me->query("group/class") > 3 )
		return notify_fail("�㻹�����ʸ���ս��\n");
	if( me->query("group/id") == gid )
		return notify_fail("���Լ��İ�����ս��\n");
	if( !GROUP_D->site_now(me->query("group/id")) )
		return notify_fail( GROUP_D->get_last_error() );
	if( !GROUP_D->site_now(gid) )
		return notify_fail( GROUP_D->get_last_error() );

	if ( GROUP_D->get_group(me->query("group/id"), 0)["money"] < 1000)
		return notify_fail("��û��������̳���޷���ս��\n");

	if ( GROUP_D->get_group_members(me->query("group/id")) < 15 )
		return notify_fail("���������������������޷���ս��\n");

	if( GROUP_D->get_group(gid,1)["target"] != me->query("group/id") ) {
		i = GROUP_D->query_master_count(gid);
		j = GROUP_D->query_master_count(gid,1);
		if ((i>=5 && j<2) || j<1)
			return notify_fail("�Է����쵼�˶����ڣ�����սҲû���ð���\n");
	}

	if( stringp(res=GROUP_D->declare_war(me,gid)) )
		return notify_fail(res);

	return 1;
}
