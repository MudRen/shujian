// taizu-quan ̫�泤ȭ

inherit SKILL;

mapping *action = ({
([
	"action" : "$Nһʽ��ǧ����С���˫��ֱ��ֱ�£��͹���ǰ������$n��$l",
	"lvl" : 0,       
	"damage_type" : "����"
]),
([
	"action" : "$N����ǰ�㣬��ȭֱ������һ������$n������һ�С�����ն����",
	"lvl" : 10,
	"damage_type" : "����"
]),
([
	"action" : "$Nʹ�С���˷����������������һ�������ȭ����$n",
	"lvl" : 20,
	"damage_type" : "����"
]),
([
	"action" : "$N˫ȭ����������������飬���͡�������ͨ��֮��",
	"lvl" : 30,
	"damage_type" : "����"
]),
([
	"action" : "$N������������һת�������غ�˫ȭ���������$n��$l��������������",
	"lvl" : 40,
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��̫�泤ȭ������֡�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�������\n");
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
	level   = (int) me->query_skill("taizu-quan",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action":	action[j]["action"],
				"lvl":		action[j]["lvl"],
				"damage_type":	action[j]["damage_type"],
				"force":	100+random(250),
				"dodge":	random(20)-10,
				"parry":	random(10),
			]);
		}
	}
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("�������������̫�泤ȭ��\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taizu-quan/" + action;
}
