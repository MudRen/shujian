// yunu-shengfa.c ��Ů��
#include <ansi.h>;
inherit SKILL;

string *dodge_msg = ({
HIW"$nһ�С������貨���������趯����ס����ȥ������ƮƮ�������⣬�����$N��һ�С�\n"NOR,
HIR"$n��ȻһЦ�����˾�����$n�ѽ��⡸һЦ�����֮�ƣ��ܿ���$N���������ơ�\n"NOR,
HIM"$nʹ����������ơ���������Σ��Ų�������������$N�����\n"NOR,
HIC"$n�����أ��ۿ�$Nɱ�п���Ϯ����һ�С����ҹ�����������ѽ���ƽ�ƣ�����һ�ԡ�\n"NOR,
MAG"$nһʽ������׹¥�����������ػ��У�����˷�����˼����$N�Ĺ�����Ȼ�˿ա�\n"NOR,
});

int valid_enable(string usage) { return (usage == "dodge"); }

int valid_learn(object me)
{
	if ( me->query_skill("yunu-xinjing", 1) < 10)
		return notify_fail("�����Ů�ľ��ȼ��������޷�������Ů����Ҫ����\n");
	return 1;
}

string query_dodge_msg(object me)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if((int)me->query("jingli") < 30 )
		return notify_fail("�����Ϣһ���ˣ��Ȼ�������Ů���ɡ�\n");
        me->receive_damage("jingli", 10);
	return 1;
}

mapping query_action(object me, object weapon)
{
	int level,out;
	level   = (int) me->query_skill("yunu-shenfa",1);
	out = (stringp(environment(me)->query("outdoors"))?1:0);
	if(me->query("family/family_name")!="��Ĺ��")
		return ([
			"action":dodge_msg[random(sizeof(dodge_msg))], 
			"dodge": -level/3,
		]);
	if(me->query("gender") == "����")
		return ([
			"action":dodge_msg[random(sizeof(dodge_msg))],
			"dodge": level/3 + me->query_con() - out*level/5,
		]);
	else
		return ([
			"action":dodge_msg[random(sizeof(dodge_msg))],
			"dodge": level/2 + me->query_per()*4 - out*level/5,
		]);
}
