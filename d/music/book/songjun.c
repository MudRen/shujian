// by lane

#include <ansi.h>

string book_name() { return HIY"�;���"NOR; }

int query_level() { return 80; }

int query_jingli() { return 180; }

int query_neili() { return 80; }

mapping play_msg(object me)
{
	return ([
		"start_msg" : YEL"$NĿ��Զ����������Ȼ��$n"YEL"������������ƽ�ͣ����Ƴ����أ������������"GRN"������ˮ����磬�δ���������ա��׺�ãã�ҷ�ȥ�����ĴӴ˸�����"YEL"����\n\n",
		"end_msg" : HIY"$N���ý��������ֵ������������������ి���ڿա�\n"NOR,
	]);
}

int query_purpose() { return 6; }