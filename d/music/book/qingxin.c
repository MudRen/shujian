// by lane

#include <ansi.h>

string book_name() { return GRN"����������"NOR; }

int query_level() { return 60; }

int query_jingli() { return 180; }

int query_neili() { return 80; }

mapping play_msg(object me)
{
	return ([
		"start_msg" : GRN"$N������һ�������������������������֮��������һ������̾Ϣ�������ǳ�¶���󻨰꣬����ͷ����ҡ�\n\n",
		"end_msg" : HIW"$Nֻ�������������Ѿ���ȫ��ԭ��\n"NOR,
	]);
}

int query_purpose() { return 1; }