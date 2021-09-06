// feed.c
// by augx@sj  6/27/2002

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object target,obj,env;
	string s1,s2;

	if( me->is_busy() )
		return notify_fail("����æ���ء�\n");

	if( !arg || sscanf(arg,"%s to %s",s1,s2)<2 )
		return notify_fail("��Ҫ��ʲô����ιʳ��\n");

	if( !(target=present(s2,environment(me))) )
		return notify_fail("��Ҫ��ʲô����ιʳ��\n");

	if( !(obj=present(s1,me)) && !(obj=present(s1,environment(me))) )
		return notify_fail("��Ҫ��ʲô��ιʳ��\n");

	if( !living(target) )
		return notify_fail("�ǲ��ǻ��\n");

	if( target->query("master") != me->query("id") )
		return notify_fail("�㻹û�н������ء�\n");

	if( obj->query("food_supply") ) {
		if( !obj->query("food_remaining") )
	     		return notify_fail( obj->name() + "�Ѿ�ûʲô�óԵ��ˡ�\n");
	     	if( target->query("food") >= target->max_food_capacity() )
	     		return notify_fail("���Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");

		message_vision(CYN"$N��һ"+obj->query("unit")+obj->query("name")+CYN"ι��$n��\n"NOR, me, target);
		env = environment(obj);
		obj->move(target);
		"/cmds/std/eat.c"->main(target,obj->query("id"));
		if(obj) obj->move(env);
	}
	else if( obj->query("liquid") ) {
		if( !obj->query("liquid/remaining") )
			return notify_fail( obj->name() + (obj->query("liquid/name") ? "�Ѿ����ȵ�һ��Ҳ��ʣ�ˡ�\n":"�ǿյġ�\n"));
		if( target->query("water") >= target->max_water_capacity() )
			return notify_fail("���Ѿ��ȵ�̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

		message_vision(CYN"$N��һ"+obj->query("unit")+obj->query("name")+CYN"ι��$n��\n"NOR, me, target);
		env = environment(obj);
		obj->move(target);
		"/cmds/std/drink.c"->main(target,obj->query("id"));
		if(obj) obj->move(env);
	}
	else
		return notify_fail("���������Ȳ��ܳ�Ҳ���ܺ�ѽ��\n");

	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : feed <ʳ���ˮ> to <����>

���������������ĳ���ιʳ��
HELP
);
	return 1;
}
