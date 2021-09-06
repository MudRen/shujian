// xingyi-jianzhen.c

#include <ansi.h>

inherit SKILL;

string *action_msg = 
({
	MAG"\n$N������Ц����ৡ���һ���������ʣ���â���£������Ƿɣ�ңָ$nǰ��Ҫ����\n\n"NOR,
	MAG"\n$Nһ����Х������ʩչǬ����ת�����е��߽�ʽ�����ߵ�·���ݺύ��ع���$n��\n\n"NOR,
	MAG"\n�������б������ֶ������������Ƿ�׹��һͬ����$n����Ҫ����\n\n"NOR,
	MAG"\n���˽Ų���Ȼ�ӿ죬�ǹ���ת��Χ��$n��ת��ͬʱ����$n���ϸ�����Ѩ��\n\n"NOR,
	MAG"\n$n��ǰһ����ֻ���Է����˻���Ϊ����������ʩ��һ������\n\n"NOR,
	MAG"\nֻ��һ����Х��$N�Ʒ���ŷ�ɳ��ʯ������$n���������ƻ谵��\n\n"NOR,
	MAG"\n$Nʩչ��$n�ĳ���������$n��Ŀ�ɿڴ�֮�ʣ����������Ѵ����Ϯ����\n\n"NOR,
	MAG"\n$N˫���յ�����ǰ��󻮻���һƬ�������$n������!\n\n"NOR,
	MAG"\n$N����ǰ�죬����$nǰ��ʮ������Ѩ��ֱ�����ǵ�㡣\n\n"NOR,
});


string query_action()
{
	return action_msg[random(sizeof(action_msg))];
}

int query_limit()
{
	return 4;
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
	if( me->query_skill("shenyuan-gong",1) < 150)
		return notify_fail("�����Ԫ�����𲻹����޷�ѧϰ���ƽ���\n");
	if( me->query_int() < 36 )
		return notify_fail("�������̫�ͣ��޷��������ƽ���\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("���ƽ���ֻ��ͨ��ѧϰ(learn)����ߡ�\n");
}
