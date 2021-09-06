// Skill: chongling-jian.c ���齣��
// Date: Look 99/03/25

inherit SKILL;

mapping *action = ({
([
	"action" : "$Nһ�С���÷�綹��������$w���������$n��$l",
	"lvl": 0,
	"damage_type" : "����"
]),
([
	"action" : "$Nʹ������Ҷ��ü��������$wƮ������������$n��$l",
	"lvl": 10,
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С����г�������$w����ǧ�ٽ�Ӱ����$n������ȥ",
	"lvl": 20,
	"damage_type" : "����"
]),
([
	"action" : "$N��ǰ����һ��������$wʹ�������է�꡹ֱ��$n��$l",
	"lvl": 30,
	"damage_type" : "����"
]),
([
	"action" : "$N���е�$wһ�Σ��ų�������������ʹ����ͬ��������ֱ��$n�������Ѩ",
	"lvl": 40,
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
	if ( me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ( me->query_skill("zixia-gong", 1) < 20)
		return notify_fail("��Ļ�ɽ�ڹ����̫ǳ��\n");
	return 1;
}


mapping query_action(object me, object weapon)
{
	int i, level, j;
	level = me->query_skill("chongling-jian",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
				"force": 100 +random(250),
				"dodge": random(20)-10,
				"parry": random(10),
				"damage": 40 +random(60),
			]);
		}
	}
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30 || me->query("neili") < 10 )
		return notify_fail("����������������齣����\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"chongling-jian/" + action;
}
