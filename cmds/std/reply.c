// reply.c
// modified by snowman@SJ 25/11/2000

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	object obj;
	string target, mud;

	if( !arg || arg=="" )
		return notify_fail("��Ҫ�ش�ʲô��\n");

	if (stringp(target = me->query_temp("reply"))) {
		if( sscanf(target, "%s@%s", target, mud)==2 ) {
			if (me->query("combat_exp") < 500000)
				return notify_fail("�������������������ʹ��ǧ�ﴫ����\n");
			GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
			write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
			return 1;
		}
	}

	if (!objectp(obj = me->query_temp("reply")))
		return notify_fail("�ղ�û���˺���˵������\n");

	if (!interactive(obj))
		return notify_fail("�ղź���˵�����˶����ˡ�\n");

	if (!wizardp(me) && me->query("id") == obj->query("env/block"))
		return notify_fail(obj->query("name")+"��������Ϲ����\n");
		
	write(GRN "��ش�" + (me->visible(obj)?obj->query("name"):obj->name()) + "��" + arg + "\n" NOR);
	message("channel", sprintf(GRN"%s�ش��㣺%s\n"NOR,
		obj->visible(me)?(me->query("name")+"("+capitalize(me->query("id"))+")"):me->name(), arg), obj);

	obj->set_temp("reply", me);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��reply <ѶϢ>

����������ָ��͸ղ��� tell ����˵����ʹ����˵����

see also : tell
HELP
	);
	return 1;
}
