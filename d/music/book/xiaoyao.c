// by lane

#include <ansi.h>

string book_name() { return CYN"��ң��"NOR; }

int query_level() { return 150; }

int query_jingli() { return 250; }

int query_neili() { return 150; }

mapping play_msg(object me)
{
	return ([
		"start_msg" : CYN"$N����һЦ����������������ζ�����Ȼ��֪��������ȡ��$n"CYN"���������ɣ�Ʈ�����ѣ���������չ�ᣬ�����ھ���֮�ϣ����������뺣��Ϸˮ���ĺ����󣬺��Ϻ��£�������ң������ڣ���ȸԾ�������ݣ����ͷ�����ң���ڣ��޾�������\n\n",
		"end_msg" : RED"$N�������ν��ᣬ�������ɽ�����ң����������\n"NOR,
	]);
}

int query_purpose() { return 11; }