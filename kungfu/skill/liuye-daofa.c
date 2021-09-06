// xiuluo-dao.c ���޵�

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([
	"action" : "$N�����ת��������������������$n��$l",
	"lvl" : 0,
	"damage_type" : "����"
]),
([
	"action" : "$N��һ������һ��������$n��������",
	"lvl" : 20,
	"damage_type" : "����"
]),
([
	"action" : "$NͻȻ�������֣�һ������$n��$l��$n����֮�£�ֻ�������",
	"lvl" : 50,
	"damage_type" : "����"
]),
([
	"action" : "$Nʩչ�������Ʒ����������ģ�$n����һ�ܣ���ײ�ϵ�����·",
	"lvl" : 80,
	"damage_type" : "����"
]),
([
	"action" : "$N������������������ʹ�ϱ��ѱ��У�ʮ����������$n��$l�к�",
	"lvl" : 120,
	"damage_type" : "����"
]),
([
	"action" : "$N��עһ������ȫ��֮���ڵ����ϣ���$nһ������",
	"lvl" : 160,
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("guiyuan-tunafa", 1) < 10)
		return notify_fail("��Ĺ�Ԫ���ɷ����̫ǳ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level, j;
	level   = (int) me->query_skill("liuye-daofa",1);

	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			if ( me->query_temp("daozhang")) {
				return ([  
					"action": CYN+action[j]["action"]+NOR,
					"lvl": action[j]["lvl"],
					"damage_type" : action[j]["damage_type"],
					"force": 200+random(300),
					"dodge": random(30),
					"damage": 100+random(80),
					"parry": random(30),
				]);
			}
			return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"force":150+random(300),
				"dodge":random(30),
				"damage":60+random(100),
				"parry":random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("liuye-daofa", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 40)
		return notify_fail("���������������Ҷ������\n");
	if ( me->query("neili") < 20)
		return notify_fail("���������������Ҷ������\n");
        me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"liuye-daofa/" + action;
}
