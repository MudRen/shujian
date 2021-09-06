// Filename : /cmds/std/ride.c
// Modify By Mope@SJ /17/04/2002

#include <ansi.h>

inherit F_CLEAN_UP;

int do_ride(object me, object ob);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, env;

	if (!arg) return notify_fail("��Ҫ��ʲô������\n");

	if (me->query_temp("is_riding"))
		return notify_fail("���Ѿ��������ˣ�\n");

	if (me->is_busy())
		return notify_fail("����һ��������û����ɣ�\n");

	if (me->is_fighting())	return notify_fail("�㻹��ս���У�û������ȥ��\n");

	// Check if a container is specified.
	env = environment(me);        

	if (!objectp(obj = present(arg, env)) || !living(obj))
			return notify_fail("����û�������������\n");

        if (env->query("no_ride")) return notify_fail("�����ֹ����\n");

	if (!obj->query("ridable") && !obj->query("horse"))
		return notify_fail("���������ҲҪ��������ƨ�ɣ�\n");

	return do_ride(me, obj);
	write("����ȥ�ˡ�\n");
}
	
int do_ride(object me, object obj)
{
	object *guard;

	if (!obj) return 0;

	if (guard = obj->query_temp("guarded")) {
		guard = filter_array(guard, (: objectp($1) && present($1, environment($2)) && living($1) && ($1!=$2) :), me);
		if( sizeof(guard) )
			return notify_fail( guard[0]->name() 
				+ "������" + obj->name() + "һ�ԣ���ֹ�κ������ߡ�\n");
	}
	
	if (!obj->query("master"))
		return notify_fail(obj->name() + "��ֻ����Ұ�ޣ������ѱ��(train)������\n");
		
	if (obj->query("owner") && (obj->query("owner") != getuid(me))) {
			return notify_fail("�㲻��"+obj->name() + "�����ˣ�\n");
	}
	
	message_vision( "$Nһ�����������ݵ�����$n��\n", me, obj );
	obj->set_temp("is_rided_by", me);
	obj->set_leader(me);
	me->set_temp("is_riding", obj->query("name"));
	me->set_temp("riding_beast", obj);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : ride | qi <������>
 
���ָ������������ϴ�������ѱ���Ķ��
 
HELP
    );
    return 1;
}
 
