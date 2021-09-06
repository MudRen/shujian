// gdismiss.c  ��ɢ����
// by augx@sj 4/11/2002

#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me)
{
	write(@HELP
ָ���ʽ :
gdimiss
��ɢ���ɣ�ֻ�а��ɵ�����������ʹ��������

gdimiss [����id]
��ʦר�������ɢָ�����ɡ�
HELP
	);
	return 1;
}

int main(object me, string arg)
{
	string gid;
	mapping mp;

	if( !me->query("group") && !wizardp(me) )
		return notify_fail("�㻹û�д����Լ��İ����ء�\n");
	if( me->query("group/class")!=1 && !wizardp(me) )
		return notify_fail("ֻ�а��ɵ��������ʦ����Ȩ����ɢ���ɡ�\n");
	if( wizardp(me) && arg ) gid = arg; else gid = me->query("group/id");
	if( !GROUP_D->site_now(gid) )
		return notify_fail( GROUP_D->get_last_error() );
	if( !(mp=GROUP_D->get_group(gid,1)) )
		return notify_fail("û��������ɡ�\n");
	if( mp["war"] > 1 )
		return notify_fail("���ǵİ�������ս�����ء�\n");

	write("��ȷ��Ҫ��ɢ��İ�����[y/n] ");
	input_to("confirm_dismiss",me,gid);

	return 1;
}

protected void confirm_dismiss(string arg,object me,string gid)
{
	if( arg[0]!='y' && arg[0]!='Y' ) return;
	
	GROUP_D->set_res("����������ɢ");
	GROUP_D->delete_group(gid);
	tell_object(me,"���ɢ���Լ��İ��ɡ�\n");
	log_file("group/group",sprintf("dismiss:dismiss  :%-8s:%s(%s)",gid,me->name(),me->query("id")),me);
}
