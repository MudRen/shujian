// grant.c
// by augx@sj 4/4/2002

#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me)
{
	write(@HELP
ָ���ʽ :
grant [���id] [�ȼ�]
��������ڰ����еĵȼ���
��һ�ȼ�Ϊ��������һ�ˣ��ڶ��ȼ�Ϊ����������һ�ˣ�
�����ȼ�Ϊ�����������ˣ����ĵȼ�Ϊ���ڣ������ɰ���ʵ�������������ơ�
���ϡ������������������������������������ڡ��ĳ�ν����������������á�

�ȼ��У�0��4��0��ʾ������
grant [���Լ���id] 0 ��ʾ���Լ�����������ɣ�û���κ���ʧ��
�������Կ���������������ˣ��������������˽��ܵ�3%�ľ���ͷ���

����һ����Ҽ�����ɣ�����ұ������á�gjoin�����������

HELP
	);
	return 1;
}

int main(object me, string arg)
{
	string uid;
	int gclass;
	object ob;

	if( !arg || sscanf(arg,"%s %d",uid,gclass)<2 || gclass<0 || gclass>4 )
		return help(me);
	if( !me->query("group/id") )
		return notify_fail("�㲢û�м������ء�\n");
	if( !GROUP_D->site_now(me->query("group/id")) )
		return notify_fail( GROUP_D->get_last_error() );

	if( uid==me->query("id") && gclass==0 ) {
		if( me->query("group/class") == 1 )
			return notify_fail("��ɢ������� gdismiss ���\n");
		if( !GROUP_D->set_group_master(me->query("group/id"),uid,gclass) )
			return notify_fail( GROUP_D->get_last_error() );
		if( !GROUP_D->set_group_member(me->query("group/id"),uid,0) )
			return notify_fail( GROUP_D->get_last_error() );
		GROUP_D->add_group_members(me->query("group/id"),-1);
		message_vision("$N�˳���"+GROUP_D->get_group_name(me->query("group/id"))+"��\n",me);
		log_file("group/manage",sprintf("rebel   :%s:%s(%s)",me->query("group/id"),me->name(),me->query("id")),me);
		me->delete("group");
		me->delete_temp("title");
		return 1;
	}

	if( me->query("group/class") > 3 )
		return notify_fail("��ĵȼ�������\n");

	ob = find_player(uid);
	if (ob && !me->visible(ob)) ob = 0;

	if( gclass == 0 ) {
		if( !ob ) return notify_fail("û������ˡ�\n");
		if( ob->query("group/id") != me->query("group/id") )
			return notify_fail("����˲��������ǰ��ĳ�Ա��\n");
		if( me->query("group/class") > 2 )
			return notify_fail("��ĵȼ�������\n");
		if( me->query("group/class") >= ob->query("group/class") )
			return notify_fail("��ĵȼ��������޷�����"+ob->name()+"��\n");

		if( !GROUP_D->set_group_master(me->query("group/id"),uid,gclass) )
			return notify_fail( GROUP_D->get_last_error() );
		if( !GROUP_D->set_group_member(me->query("group/id"),uid,0) )
			return notify_fail( GROUP_D->get_last_error() );
		GROUP_D->add_group_members(me->query("group/id"),-1);
		ob->add("combat_exp",-ob->query("combat_exp")*3/100);
		ob->delete("group");

		tell_room(environment(me),me->name()+"��"+ob->name()+"������"+GROUP_D->get_group_name(me->query("group/id"))+"��\n",({me,ob}));
		tell_object(me,"���"+ob->name()+"������"+GROUP_D->get_group_name(me->query("group/id"))+"��\n");
		tell_object(ob,"�㱻"+me->name()+"������"+GROUP_D->get_group_name(me->query("group/id"))+"��\n");
		log_file("group/manage",sprintf("fire    :%s:%s(%s):%s(%s)",me->query("group/id"),me->name(),me->query("id"),ob->name(),ob->query("id")),me);
		ob->delete_temp("title");
	}
	else {
		if( !ob || !present(ob,environment(me)) ) return notify_fail("û������ˡ�\n");
		if( ob->query("group") && ob->query("group/id")!=me->query("group/id") )
			return notify_fail("����˲��������ǰ��ĳ�Ա��\n");
		if( me->query("group/class")>=gclass || (ob->query("group/class") && me->query("group/class")>=ob->query("group/class")) )
			return notify_fail("��ĵȼ��������޷��ı�"+ob->name()+"�ڰ���еĵȼ���\n");
		if( !ob->query("group") && GROUP_D->get_group_members(me->query("group/id"))>=GROUP_D->get_max_group_members(me->query("group/id")) )
			return notify_fail("���ǰ��ɵ������Ѿ��ﵽ���ޣ�"+CHINESE_D->chinese_number(GROUP_D->get_max_group_members(me->query("group/id")))+"�ˡ�\n");
		if( !ob->query("group") && ob->query_temp("group/join")!=me->query("group/id") )
			return notify_fail(ob->name()+"��û��Ҫ��������ǵİ�ᰡ��\n");

		if( !ob->query("group") && !GROUP_D->set_group_member(me->query("group/id"),uid,1,ob->name()) )
			return notify_fail( GROUP_D->get_last_error() );
		if( !GROUP_D->set_group_master(me->query("group/id"),uid,0) )
			return notify_fail( GROUP_D->get_last_error() );
		if( !GROUP_D->set_group_master(me->query("group/id"),uid,gclass) )
			return notify_fail( GROUP_D->get_last_error() );
		if( !ob->query("group") ) {
			GROUP_D->add_group_members(me->query("group/id"),1);
			log_file("group/manage",sprintf("join    :%s:%s(%s):%s(%s)",me->query("group/id"),me->name(),me->query("id"),ob->name(),ob->query("id")),me);
		}
		ob->delete_temp("group/join");
		ob->set("group/id",me->query("group/id"));
		ob->set("group/name",GROUP_D->get_group_name(me->query("group/id")));
		ob->set("group/class",gclass);

		tell_room(environment(me),me->name()+"��"+ob->name()+"�ڰ����еĵȼ���Ϊ"+GROUP_D->get_member_class(me->query("group/id"),gclass)+"��\n",({me,ob}));
		tell_object(me,"���"+ob->name()+"�ڰ���е�Ȩ�޸�Ϊ"+GROUP_D->get_member_class(me->query("group/id"),gclass)+"��\n");
		tell_object(ob,me->name()+"�����ڰ����е�Ȩ�޸�Ϊ"+GROUP_D->get_member_class(me->query("group/id"),gclass)+"��\n");
		if(ob) GROUP_D->check_user_group(ob);
	}

	return 1;
}
