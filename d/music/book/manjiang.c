// by lane

#include <ansi.h>

string book_name() { return HIR"������"NOR; }

int query_level() { return 120; }

int query_jingli() { return 180; }

int query_neili() { return 80; }

mapping play_msg(object me)
{
	return ([
		"start_msg" : YEL"$N�����������һ����$n"YEL"�������ϣ�����Ӧ��֮�䣬�·���������ʦ֮��������"RED"׳־���ͺ�²�� Ц̸������ūѪ"YEL"����ֻ��������͸�죬Ⱥɽ��Ⱦ��\n\n",
		"end_msg" : YEL"$N���и��Ǻ���ǧ�ƣ�����������������Ρ�\n"NOR,
	]);
}

int query_purpose() { return 8; }