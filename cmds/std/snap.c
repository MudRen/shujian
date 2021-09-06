// snap.c
// by augx@sj  6/27/2002

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object target,obj;
	string s1,s2;

	if( me->is_busy() )
		return notify_fail("����æ���ء�\n");

	if( !arg || sscanf(arg,"%s to %s",s1,s2)<2 )
		return notify_fail("��Ҫ��ĳ��﹥��˭��\n");

	if( !(target=present(s1,environment(me))) )
		return notify_fail("��Ҫָ��ʲô���ﰡ��\n");

	if( !(obj=present(s2,environment(me))) )
		return notify_fail("��Ҫ��ĳ��﹥��˭��\n");

	if( !living(target) || !living(obj) )
		return notify_fail("�ǲ��ǻ��\n");

	if( target->query("master") != me->query("id") )
		return notify_fail("�㻹û�н������ء�\n");

	if( userp(obj) )
		return notify_fail("�����ڼ䣬��ֹ������ҡ�\n");

	if( target->is_busy() || target->is_fighting() )
		return notify_fail("��ĳ�����æ���ء�\n");

	message_vision(CYN"$N������"+target->name()+CYN"��ͷ��ָָ$n......\n"NOR,me,obj);

	target->kill_ob(obj);
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : snap <����> to <��������>

�����������ָ����ĳ��﹥�����ˡ�
HELP
);
	return 1;
}
