// Skill: youlong-shengfa.c ������
// 19990811001

inherit SKILL;
#include <ansi.h>
string *dodge_msg = ({
"ֻ��$nһ�С��������졹�����κ������ϸ߸����𣬶����$N��һ�С�\n",
"$n��������һ����һ�С������볲������ಡ���һ����$N�Ŀ��������\n",
"$nͻ����������һ����ʹ��һ�С�����������������������һ�Աܹ���\n",
"����$nһ�С��������֡��������������һ�ݣ��ܿ���$N��һ�С�\n",
"$nһ�С�����ǧ�ơ��������������£�Ӳ�Ǳܹ���$N��һ�С�\n",
"$n���Ų�æ��ʹ��һ�С������پ塹�����Ա�һ���Ӵܳ����ߣ������ù���$N��һ�С�\n",
"ֻ��$n����һ����ʹ��һ�С�����һ�֡������ؾ�ת����$N���\n",
});

int valid_enable(string usage) 
{
	return usage == "dodge"; 
}

int valid_learn(object me)
{
	if ( me->query_skill("dulong-dafa", 1) < 10)
		return notify_fail("��Ķ����󷨵ȼ�̫���ˡ�\n");
	return 1; 
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("jingli") < 30 )
		return notify_fail("��ľ���̫���ˣ�������ϰ��������\n");
	me->receive_damage("jingli", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"youlong-shenfa/" + action;
}
