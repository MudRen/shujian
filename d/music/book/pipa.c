// by lane

#include <ansi.h>

string book_name() { return HIM"������"NOR; }

int query_level() { return 100; }

int query_jingli() { return 280; }

int query_neili() { return 180; }

mapping play_msg(object me)
{
	return ([
		"start_msg" : HIM"$Nָ���ƿۣ�������$n"HIM"��ת��Խ��Խ�죬�������ǽ�����֮��������������һ������һ�󣬶�����ϣ�ƾ�����ڣ��·��Ǵ���С��������֮����\n\n",
		"end_msg" : YEL"$Nֻ�����������֣������ɵ�һˬ��\n"NOR,
	]);
}

int query_purpose() { return 2; }