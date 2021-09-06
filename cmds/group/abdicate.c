// abdicate.c
// by augx@sj 4/10/2002

#include <ansi.h>
inherit F_CLEAN_UP;
#include <group.h>

int help(object me)
{
	write(@HELP
ָ���ʽ : abdicate/chanrang to [���id]
���Լ��İ���λ�����ø��Լ��������������ҡ�
���õĶ��������ϰ����ľ���Ҫ��
���ú�ԭ����û�о�����ʧ��
HELP
	);
	return 1;
}

int main(object me, string arg)
{
	string gid,str;
	object ob;

	if( !arg || sscanf(arg,"to %s",arg) < 1 ) return help(me);
	if( !(gid=me->query("group/id")) )
		return notify_fail("�㻹û�м�������ء�\n");
	str = GROUP_D->get_member_class(gid,1);
	if( me->query("group/class") != 1 )
		return notify_fail("���ֲ���"+str+"�������λ��\n");
	if( me->query("id") == arg )
		return notify_fail("�Լ���λ���Լ���\n");
	if( !arg || !(ob=find_player(arg)) )
		return notify_fail("�Ҳ���Ҫ���õ��˰���\n");
	if( ob->query("group/id") != gid )
		return notify_fail(ob->name()+"����������"+GROUP_D->query_group_name(gid)+"�ĳ�Ա����\n");
	if( ob->query("combat_exp") < EXP_REQUIRE )
		return notify_fail(ob->name()+"��������������λ�����������Է��ڡ�\n");

	if( !GROUP_D->set_group_master(gid,arg,0) )
		return notify_fail( GROUP_D->get_last_error() );
	if( !GROUP_D->set_group_master(gid,me->query("id"),0) )
		return notify_fail( GROUP_D->get_last_error() );
	if( !GROUP_D->set_group_master(gid,arg,1) )
		return notify_fail( GROUP_D->get_last_error() );
	ob->set("group/class",1);
	me->set("group/class",4);
	me->save();
	ob->save();
	GROUP_D->check_user_group(me);
	GROUP_D->check_user_group(ob);

	tell_object(me,"�������"+str+"֮λ���ø�"+ob->name()+"��\n");
	tell_object(ob,me->name()+"������"+str+"֮λ���ø��㡣\n");
	CHANNEL_D->do_channel(this_object(),"rumor",HIM"��˵"+me->name()+HIM+"�Ѿ���"+GROUP_D->get_group_name(gid)+HIM"��"+str+HIM"֮λ���ø�"+ob->name()+HIM"�ˡ�"NOR);
	log_file("group/manage",sprintf("abdicate:%s:%s(%s):%s(%s)",gid,me->name(),me->query("id"),ob->name(),ob->query("id")),me);

	return 1;
}
