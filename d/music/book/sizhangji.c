// by lane

#include <ansi.h>

string book_name() { return HIC"���Ż�"NOR; }

int query_level() { return 140; }

int query_jingli() { return 280; }

int query_neili() { return 180; }

mapping play_msg(object me)
{
	return ([
		"start_msg" : GRN"$N��������������������$n"GRN"�����ϵ��𣬲�����ת���������ߣ�Ӧ�͵Ĳ�֪�������ϣ�������������"HIC"���Ż���ԧ��֯����˫�ɡ�����δ��ͷ�Ȱף������̲ݣ�����������ԡ���¡���"GRN"����\n\n",
		"end_msg" : GRN"$Nһ�����ˣ����ѻ������ѳգ�����ȴ��һϴ�ٶ������޺ۼ�����\n"NOR,
	]);
}

int query_purpose() { return 3; }