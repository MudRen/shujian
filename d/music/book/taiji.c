// by lane

#include <ansi.h>

string book_name() { return YEL"̫����"NOR; }

int query_level() { return 100; }

int query_jingli() { return 280; }

int query_neili() { return 180; }

mapping play_msg(object me)
{
	return ([
		"start_msg" : YEL"$N������һ�ڳ������ھ��᳹����͵�һ����ɫ����ʼ����һ�����ϡ�������̫����ת��������ƣ����Ὺ�ϣ���Ȼ�о������κ����������Ǿ�Ȼ���������ϣ����޻��У�������࣬��ɽ����֮�䣬��Ȼ��֪������ɫʲôʱ��Ż��ͣ��\n\n",
		"end_msg" : GRN"$N�����Լ��ľ���ԴԴ�����ޱȼ��У����粻���þ�һ�㡣\n"NOR,
	]);
}

int query_purpose() { return 9; }