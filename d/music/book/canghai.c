// by lane

#include <ansi.h>

string book_name() { return BLU"�׺�Ц"NOR; }

int query_level() { return 150; }

int query_jingli() { return 250; }

int query_neili() { return 150; }

mapping play_msg(object me)
{
	return ([
		"start_msg" : BLU"$N����һ�ݣ�һ����Х��˫�۰������ߣ��������죬һ������һ���������$n"BLU"ͷ�������������̲���ֹ�������޺ۣ������㣬һ�˸���һ�ˣ���ͬ�׺�ŭ����\n\n",
		"end_msg" : YEL"������������ģ���$N���û���·����ò����������\n"NOR,
	]);
}

int query_purpose() { return 10; }