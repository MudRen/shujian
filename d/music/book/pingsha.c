// by lane

#include <ansi.h>

string book_name() { return MAG"ƽɳ����"NOR; }

int query_level() { return 40; }

int query_jingli() { return 40; }

int query_neili() { return 20; }

mapping play_msg(object me)
{
	return ([
		"start_msg" : MAG"$N������ԣ�����������$n"MAG"����ͬ������������������֮�ϣ���������֮����ʱ�쳹���ܣ���"YEL"�������ƿ������λش�����Ӫ���˰���������ˣ���ʮ�ҷ���������ɳ��������"MAG"��\n\n",
		"end_msg" : GRN"$N�������к�����������֫������������\n"NOR,
	]);
}

int query_purpose() { return 4; }