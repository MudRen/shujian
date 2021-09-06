// kickout.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string name,q_name,q_id,q_ip;
	object obj, link_ob;

	if( !arg ) return notify_fail("ָ���ʽ : kickout <�����>\n" );

	seteuid(ROOT_UID);

	obj = LOGIN_D->find_body(arg);
	if( !obj || !userp(obj) || !me->visible(obj)) return notify_fail("û��������....��\n");
	name = obj->short(1);
	q_name = obj->name(1);
	q_id = obj->query("id");
	q_ip = query_ip_name(obj);

	if( me == obj )
		return notify_fail("�� quit ����ָ���Щ :) \n");

	if (wiz_level(me) <= wiz_level(obj))
		return notify_fail("���"+q_name+"���֣����ź��������㲻����ô����\n");

	message_vision("һ����ӰͻȻ������$N��ǰ��˵������"+q_name +
			"�������" + RANK_D->query_rude(obj) + "����ΪΥ����Ϸ�������˳���Ϸ�ɣ���\n", obj);
	obj->dismiss_team();
	//add by LinuX for DB_SAVE
	if (!obj->query_temp("db_quit"))
		obj->set_temp("db_quit", 1);
	obj->save();
	link_ob = obj->query_temp("link_ob");
	if (link_ob) {
		link_ob->save();
		destruct(link_ob);
	}
	catch(destruct(obj));
	
	if( obj ) return notify_fail("���޷������������ߡ�\n");
	else {
		//set("channel_id", me->name() );
		CHANNEL_D->do_channel(this_object(), "rumor", q_name + "��ΪΥ����Ϸ���򣬱�ϵͳ�߳���"+MUD_NAME+"��");
		CHANNEL_D->do_channel(me, "wiz", "�ҽ�"NOR + name + HIR"�߳���ϵͳ��");
		log_file("static/kickout",
			sprintf("%s(%s) kickout %s(%s) at %s\n",
				me->name(1), me->query("id"), q_name, q_id, q_ip
			), me, ({ q_id })
		);
		write("������������... ��ˬ!\n");
	}
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : kickout <�����>

���������ǿ�ȶ����������ߡ�

HELP );
	return 1;
}
