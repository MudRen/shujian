// attack.c
// by augx@sj  4/2/2002

#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me)
{
	write(@HELP
ָ���ʽ :
attack here
�������ڵķ��䡣

attack [��Ʒid]
�������������Ʒ��

�����߱����ֳִ��������

HELP
	);
	return 1;
}

int main(object me, string arg)
{
	object env = environment(me), obj, ob, weapon;
	int t;

	if( !arg ) return help(me);
	if( arg == "here" ) obj = env; else obj = present(arg,env);
	if( !obj ) return notify_fail("��Ҫ����ʲô��\n");
	if( living(obj) ) return notify_fail("��killָ����ܱȽϿ졣\n");
	if( obj->query("hp") <= 0 ) return notify_fail("�㲻�ܴݻ�����������\n");
	if( env->query("attack") ) return notify_fail("�Ѿ�����������ݻٵ��˵�װ���ˡ�\n");
	if( !me->query("group/id") ) return notify_fail("�㻹û�м�����ɣ������ﵷʲô�Ұ���\n");
	if( !(weapon=me->query_temp("weapon")) || weapon->query("skill_type")!="hammer" )
		return notify_fail("��û�д��ӣ���δݻٷ������Ʒ����\n");
	if( !GROUP_D->site_now(me->query("group/id")) )
		return notify_fail( GROUP_D->get_last_error() );
	if( GROUP_D->is_group_fight(me) != 1 )
		return notify_fail("�㲢û�д���ս��״��ѽ��\n");
	if( GROUP_D->query_league(me->query("group/id")) == env->query("group1") )
		return notify_fail("�ݻ��Լ��˵�װ����\n");

	message_vision("$N����"+weapon->name()+"����"+(clonep(obj)?obj->name():obj->query("short"))+"......\n",me);
	t = 15 + random(30);
	me->start_busy(t/2+1);
	env->set("attack",time()+t);

	switch( obj->query("id") ) {
		case "shi men":	 env->set("attack_type","door"); break;
		case "pai bian": env->set("attack_type","flag"); break;
		case "qian gui": env->set("attack_type","cash_box"); break;
		default: env->set("attack_type","room"); break;
	}

	foreach ( ob in all_inventory(env) ) {
		if( !ob || !living(ob) || !userp(ob) ) continue;
		env->set_attack(ob);
	}

	call_out("attack_finish",t,obj,env,me);
	return 1;
}

void attack_finish(object obj,object env,object me)
{
	if( !env ) return;
	env->set("attack",0);
	env->set("attack_type","");

	if( !me ) return;
	tell_room(env,me->name()+"�Ĺ��������ˣ�",({me}));
	tell_object(me,"�㹥�������ˣ�");

	if( environment(me) != env ) return;
	GROUP_D->attack_room(obj,me);
}
