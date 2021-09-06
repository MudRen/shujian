// fumo-jian.c -��ħ��

inherit SKILL;

mapping *action = ({
([
	"action" : "$Nһʽ�������ơ�������ƽָ��������磬һ���ǳɺ�ɨ$n������",
	"lvl" : 0,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([
	"action" : "$N��ǰԾ��һ�������ֽ���������$wʹ��һʽ�������ơ�ֱ��$n��$l",
	"lvl" : 10,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([
	"action" : "$N�β�ͦ����һʽ����ɽ�ơ�������$w�����ޱȣ������ӽ�ײ��$n��$l",
	"lvl" : 20,
	"skill_name" : "��ɽ��",
	"damage_type" : "����"
]),
([
	"action" : "$Nһʽ�������ơ���$w������һ���һ���󻡣�ƽƽ����$n��$l��ȥ",
	"lvl" : 30,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([
	"action" : "$N����š���������鱧��Բ��һʽ�������ơ���$w�й�ֱ��������$n���ؿ�",
	"lvl" : 40,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([
	"action" : "$Nһʽ�������ơ���$w������������������ֱ����Ю����֮����Ȼն��$n��$l",
	"lvl" : 49,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([
	"action" : "$N����ʩ���������ơ���$w����Ƴ�һ����â��������ƿ�����$n��$l",
	"lvl" : 57,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([
	"action" : "$N˫�Ȱ�����ף�һʽ�������ơ������⻮������ԲȦ����������������",
	"lvl" : 64,
	"skill_name" : "������",
	"damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("yijin-jing", 1) < 20)
		return notify_fail("����׽���̫ǳ��\n");
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
	level   = (int) me->query_skill("fumo-jian",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 100 + random(250),
				"dodge": random(20)-10,
				"damage": 40 + random(60),
				"parry": random(10),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("fumo-jian", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30 || me->query("neili") < 10)
		return notify_fail("���������������ħ����\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
