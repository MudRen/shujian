// by lane

#include <ansi.h>

string book_name() { return YEL"ɽ����"NOR; }

int query_level() { return 120; }

int query_jingli() { return 180; }

int query_neili() { return 80; }

mapping play_msg(object me)
{
	return ([
		"start_msg" : GRN"$Nָ�Ʒ�����$n"YEL"�ϣ����������϶������ϳ壬��������������"HIY"��ɽ����������మ���β��������۹��ƽ����һéի��Ұ����������˭���˷�˭�ɰܣ�ª�ﵥư�����ա�ƶ�������ģ��־���ģ�"GRN"����\n\n",
		"end_msg" : GRN"$N����֮�󣬶پ��ھ����಻�����ƴ�����\n"NOR,
	]);
}

int query_purpose() { return 14; }