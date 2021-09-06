// wenjia-daofa.c �¼ҵ�����NPC����

inherit SKILL;

mapping *action = ({
([
	"action" : "$Nһʽ������ӭ�͡�������΢�࣬����ƽ����б��$n��$l",
	"lvl" : 0,
	"skill_name" : "����ӭ��",
	"damage_type" : "����"
]),
([
	"action" : "$N��ǰԾ��һ�������ּ����趯���е�$w��һ�С����ż�ɽ��ֱ��$n��$l",
	"lvl" : 10,
	"skill_name" : "���ż�ɽ",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ��б�ಽ��һ�С��ż����衹������$wƽƽ������$n��$l",
	"lvl" : 20,
	"skill_name" : "�ż�����",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С��Ʋ��������������$w����һ���󻡣����ٿ���$n��$l",
	"lvl" : 30,
	"skill_name" : "�Ʋ�����",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level, j;
	level   = (int) me->query_skill("wenjia-daofa",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action":	action[j]["action"],
				"lvl":		action[j]["lvl"],
				"damage_type":	action[j]["damage_type"],
				"force":	150+random(300),
				"dodge":	random(30),
				"parry":	random(30),
				"damage":	60 + random(100),
			]);
		}
	}
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 40)
		return notify_fail("��������������¼ҵ�����\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("��������������¼ҵ�����\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}
string perform_action_file(string action)
{
        return __DIR__"wenjia-daofa/" + action;
}
