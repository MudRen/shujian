// shout.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str;
	if (!userp(me)) return 0;
	if (!arg) return notify_fail("����Ҫ���ʲô��\n");
	if (present(arg, environment(me))) return 0;
	if (!wizardp(me) && me->query("max_neili") < 4000 ) {
		write("����Ŀǰ������״�����޷�ʹ��ǧ�ﴫ����\n");
		return 1;
	}
	if (!wizardp(me) && me->query("neili") < 4000) {
		write("����Ŀǰ������״�����޷�ʹ��ǧ�ﴫ����\n");   
		return 1;
	}
	if (me->query_condition("shout_condition")) {
		write("��ո�������Х��������Ϣһ����˵�ɡ�\n");
		return 1;
	}
	if (!wizardp(me)){
		if (strlen(arg) > 100)
			arg = arg[0..99];
		str = me->name(1) + "(" + capitalize(me->query("id")) + ")";
		me->add("neili", -2000);
		me->apply_condition("shout_condition", 6);
	} else str = me->name();
	message("channel", "\r" + HIW + str + "������Х����" + arg + "��\n" NOR, users(), me);
	write(HIW "��������Х����" + arg + "��\n" NOR);
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : shout <ѶϢ>
 
���ָ�����㽫 <ѶϢ> ���ͳ�ȥ, ����������Ϸ�е��˶���������Ļ���
���Ҫ�󣺿���������� 4000���������� 4000
 
see also : tune
HELP
    );
    return 1;
}
