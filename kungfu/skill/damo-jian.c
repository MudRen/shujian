// damo-jian.c ��Ħ��

inherit SKILL;

mapping *action = ({
([
	"action":"$Nʹһʽ��������Ե����������$w����΢�񣬻ó�һ���������$n��$l",
	"lvl" : 0,
	"skill_name" : "������Ե��",
	"damage_type":  "����"
]),
([
	"action":"$N����ǰ��ʹ������ȥ�����С��������������ޣ�$w��������$n��$l��ȥ",
	"lvl" : 9,
	"skill_name" : "��ȥ������",
	"damage_type":  "����"
]),
([
	"action":"$Nһʽ��������ɣԶ��������Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",
	"lvl" : 18,
	"skill_name" : "������ɣԶ",
	"damage_type":  "����"
]),
([
	"action":"$N��������Ծ��һʽ���ֻط����᡹���������ּ�ת������ն��$n��$l",
	"lvl" : 27,
	"skill_name" : "�ֻط�����",
	"damage_type":  "����"
]),
([
	"action":"$N����$w�й�ֱ����һʽ��ˮ��ͨ���š���������Ϣ�ض�׼$n��$l�̳�һ��",
	"lvl" : 36,
	"skill_name" : "ˮ��ͨ����",
	"damage_type":  "����"
]),
([
	"action":"$N����$wбָ���죬��â���£�һʽ������������������׼$n��$lбб����",
	"lvl" : 44,
	"skill_name" : "����������",
	"damage_type":  "����"
]),
([
	"action":"$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ��ǧ��һέȥ������$n��$l",
	"lvl" : 52,
	"skill_name" : "ǧ��һέȥ",
	"damage_type":  "����"
]),
([
	"action":"$N���Ƶ�����һʽ�����Ķ���������$w�Ի���Ծ�����缲�������$n���ؿ�",
	"lvl" : 60,
	"skill_name" : "���Ķ�����",
	"damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("yijin-jing", 1) < 20)
		return notify_fail("����׽�ڹ������̫ǳ��\n");
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
	level   = (int) me->query_skill("damo-jian",1);
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
	int lvl = me->query_skill("damo-jian", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30 || me->query("neili") < 10)
		return notify_fail("��ľ�����������Ħ����\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"damo-jian/" + action;
}
