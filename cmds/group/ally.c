// ally.c
// by augx@sj 4/3/2002

#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me)
{
	write(@HELP
ָ���ʽ :
ally request [����id]
�����ĳ�����ɽ��ˣ�ֻ�д���ս����ս��׼��״̬�µİ��ɣ�����������ˡ�

ally answer [����id]
ͬ���ĳ�����ɽ��ˣ���Ҫ���б�İ��ɷ����������󣬲���ʹ�ô����

ally renege [����id]
ȡ����ĳ�����ɵĽ��˹�ϵ����ȡ����ĳ�����ɷ����Ľ�������
HELP
	);
	return 1;
}

int main(object me, string arg)
{
	string type,gid1,gid2;

	if( !arg || sscanf(arg,"%s %s",type,gid2)<2 || (type!="request" && type!="answer" && type!="renege") )
		return help(me);
	if( !(gid1=me->query("group/id")) )
		return notify_fail("�㲢û�м����ᣬ���˸�ʲôѽ��\n");
	if( me->query("group/class") > 3 )
		return notify_fail("��ĵȼ����������ܺͱ�İ��ɽ��ˡ�\n");

	if( !GROUP_D->do_friend(gid1,gid2,type) )
		return notify_fail( GROUP_D->get_last_error() );

	switch( type ) {
		case "request":
			GROUP_D->tell_group_master(gid1,"���������"+GROUP_D->get_group_name(gid2)+"���ˡ�\n",5);
			GROUP_D->tell_group_master(gid2,GROUP_D->get_group_name(gid1)+"��������ǵİ��ɽ��˵�����\n",5);
			break;
		case "answer":
			GROUP_D->tell_group_master(gid1,"�����Ѿ���Ӧ��"+GROUP_D->get_group_name(gid2)+"���ˡ�\n",5);
			GROUP_D->tell_group_master(gid2,GROUP_D->get_group_name(gid1)+"�Ѿ���Ӧ�����ǽ��ˡ�\n",5);
			break;
		case "renege":
			GROUP_D->tell_group_master(gid1,"�����Ѿ��������"+GROUP_D->get_group_name(gid2)+"����Լ��\n",5);
			GROUP_D->tell_group_master(gid2,GROUP_D->get_group_name(gid1)+"�Ѿ�����������ǵ���Լ��\n",5);
			break;
	}

	return 1;
}
