// by lane

#include <ansi.h>

string book_name() { return HIB"������"NOR; }

int query_level() { return 150; }

int query_jingli() { return 250; }

int query_neili() { return 150; }

mapping play_msg(object me)
{
	return ([
		"start_msg" : HIB"$N�����ֽ������һ����$n"HIB"�������ϣ�ʮָһ������Ȼ��һ�����Ա��裬���֮�ڣ����֮�ϣ�һ�����·�Ҫ�������£��ַ·����˲��ĸս�������ֱǰ����ã���ˣ��и�Ӧ�ͣ���"HIC"����������ˮ����׳ʿһȥ�ⲻ����"HIB"����\n\n",
		"end_msg" : GRN"��һ����ֻ��$N���ù����ս��������Ծ��ط档\n"NOR,
	]);
}

int query_purpose() { return 13; }