// gjoin.c
// by augx@sj 4/4/2002

#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me)
{
	write(@HELP
ָ���ʽ :
gjoin [����id]
�������ĳ�����ɡ�
HELP
	);
	return 1;
}

int main(object me, string arg)
{
	if( !arg ) return help(me);
	if( me->query("group/id") )
		return notify_fail("���Ѿ�����һ�������ˡ�\n");
	if( me->query("combat_exp") < 100000 )
		return notify_fail("����������������ǵ�һ����ȥ����ɰɡ�\n");
	if( !GROUP_D->site_now(arg) )
		return notify_fail( GROUP_D->get_last_error() );

	me->set_temp("group/join",arg);
	message_vision("$NҪ�����"+GROUP_D->get_group_name(arg)+"��\n",me);
	return 1;
}
