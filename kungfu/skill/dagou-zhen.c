// dagou-zhen.c

#include <ansi.h>

inherit SKILL;

string *action_msg = 
({
	HIG"\n$N��������������ү̫̫���кã��ʹ����һ��Ǯ����\n\n"NOR,
	HIG"\n$N��������������ү̫̫��ʩ����䷹����\n\n"NOR,
	HIG"\n$N������������������·�㲻���ģ���\n\n"NOR,
	HIG"\n$N���������������������㴳��������\n\n"NOR,
	HIG"\n$Nʹ��һ�С��⡱�־��������е��������ܲ�͸�磬��ס��$n�Ĺ��ơ�\n\n"NOR,
	HIG"\n$Nʹ��һ�С��衱�־�,һ�費���ٰ裬����֮�ؾ�,$n���ò���������,�����Ա���\n\n"NOR,
	HIG"\n$Nʹ��һ�С������־�������İ�ӰȦ����$n,$n��һ��,��Ȧ�˽�ȥ��\n\n"NOR,
	HIG"\n$Nʹ��һ�С������־�,�趯�����������Ӱ��ʹ�������$n����һ�£����ⰵ��!\n\n"NOR,
	HIG"\nȺؤ���е����������䣬���ѵ���ɱ��ɱ�ˣ�����ͣ�֡�\n\n"NOR,
	HIG"\n$n�������Ⱥؤ���и߳������䣬���з��꣬���и����·���\n\n"NOR,
});


string query_action()
{
	return action_msg[random(sizeof(action_msg))];
}

int query_limit()
{
	return 10;
}

void create()
{ 
	seteuid(getuid()); 
}

string type() 
{ 
        return "array"; 
}

int valid_learn(object me) 
{
	if( me->query_skill("huntian-qigong",1) < 100)
		return notify_fail("��Ļ����������𲻹����޷�ѧϰ����\n");
	if( me->query_skill("dagou-bang",1) < 100)
		return notify_fail("��Ĵ򹷰������𲻹����޷��������\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("���ֻ��ͨ��ѧϰ(learn)����ߡ�\n");
}
