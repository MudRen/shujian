// by lane

#include <ansi.h>

string book_name() { return HIG"�����"NOR; }

int query_level() { return 150; }

int query_jingli() { return 250; }

int query_neili() { return 150; }

mapping play_msg(object me)
{
	return ([
		"start_msg" : HIG"$N��üתĿ��ʮָ���ߣ�һ�������������$n"HIG"�ϵ�����������"CYN"�����䡢���Ǻ��ֱ�������������ϵر�˫�ɿͣ��ϳἸ�غ��������"HIG"���������˸п�������˿˿���⣬��������͸����\n\n",
		"end_msg" : CYN"��������֮�ʣ��̿�һϴ��$NҲ��֪�Ǳ���ϲ���Ǹ�����������ȴ�ǿ���������͸��\n"NOR,
	]);
}

int query_purpose() { return 12; }