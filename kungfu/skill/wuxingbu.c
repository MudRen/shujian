//Cracked by Roath
// wuxingbu.c 
//kane

inherit SKILL;

mapping *action = ({
([	"action" : "$nһ�������ذδС������ϴ������ߣ��ܹ�$N������\n",
	"dodge"  : 10
]),
([	"action" : "$nһ�������ӷ��������һ���෭��������$N���������ơ�\n",
	"dodge"  : 20
]),
([	"action" : "$n���Ʋ��������ʹ�С���¿�������������һ�������$N�Ĺ�����\n",
	"dodge"  : 30
]),
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("wuxingbu");

	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
	return usage == "dodge";
}

string query_dodge_msg(string limb)
{
        return action[random(sizeof(action))]["action"];
}

int practice_skill(object me)
{
	if (me->query("jingli") < 30 )
		return notify_fail("�����ڵľ���̫���ˣ�������ϰ���в�����\n");
	me->receive_damage("jingli", 30);
	return 1;
}
