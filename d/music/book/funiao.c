// by lane

#include <ansi.h>

string book_name() { return RED"����"NOR; }

int query_level() { return 80; }

int query_jingli() { return 180; }

int query_neili() { return 60; }

mapping play_msg(object me)
{
	return ([
		"start_msg" : YEL"$N������裬ָ���������ƶˣ������������ָ�$n"YEL"����������������ü����Ȼ����������"RED"�ҷ����Ϊ¯�⣬�컯Ϊ��������Ϊ̿�⣬����Ϊͭ����"YEL"����\n\n",
		"end_msg" : YEL"$N����֮��ɣ����ӿ����ͷ����Ȼ������������ʲô��ʹ���Դ���Լ���\n"NOR,
	]);
}

int query_purpose() { return 5; }
