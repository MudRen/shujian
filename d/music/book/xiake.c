// by lane

#include <ansi.h>

string book_name() { return HIW"������"NOR; }

int query_level() { return 150; }

int query_jingli() { return 200; }

int query_neili() { return 100; }

mapping play_msg(object me)
{
	return ([
		"start_msg" : HIW"$N��ȻһЦ����Ƿ���ɱ�⣬����ת��$n"HIW"ͷ��������һ��һ�٣����ֲط棬�·����������У�ֱ���ķΣ���"HIR"ʮ��ɱһ�ˣ�ǧ�ﲻ���С����˷���ȥ�����������"HIW"����\n\n",
		"end_msg" : HIW"$N�������꣬��һ���ŷ簻Ȼ�ġ�"RED"������"HIW"����\n"NOR,
	]);
}

int query_purpose() { return 7; }