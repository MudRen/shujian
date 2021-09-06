// last modify at 17th, JUNE 1999 -Yu Jue.

#include <ansi.h>

inherit F_CLEAN_UP;

int help(object);

int main(object me, string arg)
{
	string cmds;
	object ob;

	if (!arg || !sscanf(arg, "%s do %s", arg, cmds)) return help(me);

	if (!(ob = present(arg, environment(me))) && !(ob = find_player(arg)) && !(ob = find_living(arg)))
		return 0;

	if (ob == me)
		return notify_fail("ֱ�Ӵ�����ȽϿ�Щ��\n");

	if (geteuid(ob) == "yuj" || wiz_level(me) < wiz_level(ob) - 1)
		return notify_fail("��û������Ȩ����\n");

	return ob->force_me(cmds);
}

int help(object me)
{
	write(@HELP
ָ���ʽ�� force ����<id> do <����>
HELP );
	return 1;
}
