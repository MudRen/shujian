// zhenwu-qijiezhen.c

#include <ansi.h>

inherit SKILL;

string *action_msg = 
({
	HIW"\n$N������������̫�����������ޣ����¿����ʸ��ᡣ��\n\n"NOR,
	HIW"\n$nֻ����ǰͻ�Ľ�����䣬����������ɽ�������鶯���𣬲�������һ�������ⰵ����\n\n"NOR,
	HIW"\n$N���б����󿪴��أ��Ƶ��ۻ룬����̩ɽѹ��֮�ƹ���$nǰ��Ҫ����\n\n"NOR,
	HIW"\n$N�������ˣ������ϻó���㺮�ǣ�ÿ���ǹⶼ����$n����֮����\n\n"NOR,
	HIW"\n$N������ͥɢ����ʵ���̤���ǣ��պ�ռס��$n�Ĳ����ƶ�֮����\n\n"NOR,
	HIW"\n$nֻ����ȫ�����¶������������ƣ��·���׹���У����еı��о�ʩչ������\n\n"NOR,
	HIW"\n$N�ȼ��˺�����ң�������ȥ����������֯��һ��������ȴ����Է����С�\n\n"NOR,
	HIW"\n��������ʹ������Ⱥɽ֮�������磬���಻��������ƺƴ�ӣ�������Ϣ��\n\n"NOR,
	HIW"\n$nһ�й���$N��ֻ��$N��Ȼ��˿������ͻȻ�������ɽ���Ϯ����ȴ��������ֻ����\n"
		+"һ��һ����Ȼ������\n\n"NOR,
});


string query_action()
{
	return action_msg[random(sizeof(action_msg))];
}

int query_limit()
{
	return 7;
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
	if( me->query_skill("yinyun-ziqi",1) < 120)
		return notify_fail("������������𲻹����޷�ѧϰ�����߽���\n");
	if( me->query_skill("taiji-jian",1) < 120)
		return notify_fail("���̫���������𲻹����޷����������߽���\n");
    if( me->query_skill("taoism",1) < 120)
        return notify_fail("��ĵ�ѧ�ķ����𲻹����޷����������߽���\n");
	if( me->query_int() < 32 )
		return notify_fail("������ԣ��޷����������߽���\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("�����߽���ֻ��ͨ��ѧϰ(learn)����ߡ�\n");
}
