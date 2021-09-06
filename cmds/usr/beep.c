// beep.c
// by snowman 11/03/2000

inherit F_CLEAN_UP;

#include <ansi.h>

int help(object me);

void remove_busy(object me)
{
	if ( me) me->delete_temp("command_busy");
}

int main(object me, string arg)
{
	string *friend_user;
	object obj;

	if( me->query_temp("command_busy"))
		return notify_fail("��������æ���ء�\n");

	if( !arg ) return help(me);

	if( arg == me->query("id") )
		return notify_fail("Beep�Լ���������Ү��\n");

	friend_user = me->query("friend_user");
	if( !friend_user || !sizeof(friend_user))
		return notify_fail("��Ŀǰ��û���趨���ѣ��������� beep��\n");

	if( !wizardp(me) && member_array(arg, friend_user) == -1)
		return notify_fail("����������û�д��ˣ��������� beep��\n");

	if (!obj = LOGIN_D->find_body(arg))
		return notify_fail(arg+"��������ڲ������ϡ�\n");

	if (!me->visible(obj))
		return notify_fail(arg+"��������ڲ������ϡ�\n");

	if (!interactive(obj))
		return notify_fail("����˶����ˡ�\n");
	if (!living(obj))
		return notify_fail("����������޷�������Ļ���\n");

	if( !wizardp(me) ){
		friend_user = obj->query("friend_user");
		if( !friend_user || !sizeof(friend_user) )
			return notify_fail("�Է�Ŀǰ��û���趨���ѣ��������� beep��\n");

		if( member_array(me->query("id"), friend_user) == -1)
			return notify_fail("�Է��ĺ���������û���㣬�������� beep��\n");
	}

	tell_object(me, HIG "�����С�"+obj->query("name")+"���� Beep !\n"NOR);
	tell_object(obj, HIG "\n�����С����� Beep ���� �������"+me->query("name")+"("+me->query("id")+")�������أ����"
	+gender_pronoun(me->query("gender"))+"��ϵ��\n" NOR);

	me->set_temp("command_busy", 1);
	call_out("remove_busy", 3, me);
	return 1;

}

int help(object me)
{
write(@HELP

ָ���ʽ��beep <ĳ��>

����������ָ���������Լ�������(��robot�ر�����)��
������˫�����ڶԷ��ĺ��������ڡ�����Է�����(PC)��
����С���ȵ�(��������)����������Beep����

���ָ�finger ( ���ڼ������ )
HELP);
return 1;
}
