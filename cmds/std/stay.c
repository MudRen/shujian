// stay.c
// by augx@sj  6/27/2002

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object target;

	if( me->is_busy() )
		return notify_fail("����æ���ء�\n");

	if( !arg || !(target=present(arg,environment(me))) )
		return notify_fail("��Ҫ��ʲô����ͣ������\n");

	if( !living(target) )
		return notify_fail("�ǲ��ǻ��\n");

	if( target->query("master") != me->query("id") )
		return notify_fail("�㻹û�н������ء�\n");

	if( target->query_leader() != me )
		return notify_fail("����û�и����㰡��\n");

	message_vision(CYN"$N������$n��ͷ����ָָ$n......\n" NOR, me,target);

	target->set_leader(0);
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : stay <����id>

�����������ʹ������Ķ���ͣ��ԭ�ء�
HELP
);
	return 1;
}
