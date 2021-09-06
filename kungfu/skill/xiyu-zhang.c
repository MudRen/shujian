// xiyu-zhang ������
//written by cool

inherit SKILL;

mapping *action = ({
([
	"action" : "$N��������ǰ�����ߣ���������б��ǰ��һʽ������˫���ơ�������$n��$l",
	"damage_type" : "����",
	"lvl" : 0,
	"skill_name" : "����˫����"
]),
([
	"action" : "$N���Ȱ�׳ɹ���������ǰ�㣬һʽ���������ơ�������ֱ����ǰ�ῳ",
	"damage_type" : "����",
	"lvl" : 20,
	"skill_name" : "��������"
]),
([
	"action" : "$Nһʽ�����ơ����������ǰ���䲽�����ֱ�ȭΪ�ƣ������ƻ���������",
	"damage_type" : "����",
	"lvl" : 40,
	"skill_name" : "����"
]),
([
	"action" : "$N���Ʒ��ϳż���ǰ�Ϸ�������б���ϣ�һʽ�������ơ���������ǰ�Ϸ��Ƴ�",
	"damage_type" : "����",
	"lvl" : 60,
	"skill_name" : "������"
]),
([
	"action" : "$Nʹһʽ�������ܰ��ơ��������󹭲�����������������б���£���$n��ǰ�·��Ͱ�",
	"damage_type" : "����",
	"lvl" : 80,
	"skill_name" : "�����ܰ���"
]),
([
	"action" : "$N���Ӳ�����һʽ������˫���������ֻ���Ϊȭ����ǰ������������ƽ�������$n��ȥ",
	"damage_type" : "����",
	"lvl" : 90,
	"skill_name" : "����˫��"
]),
([
	"action" : "$N�ҽ��ƹ�����򶫷��䲽��һʽ���Ʋ��ϲ��ơ������־�����$n����",
	"damage_type" : "����",
	"lvl" : 100,
	"skill_name" : "�Ʋ��ϲ���"
]),
([
	"action" : "$Nʹһʽ�������ơ�����������̧�����ִ�����������������$n����",
	"damage_type" : "����",
	"lvl" : 140,
	"skill_name" : "������"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������Ʊ�����֡�\n");
	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("����ڹ���򲻹����޷�ѧ�����ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷��������ơ�\n");
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
	level = (int)me->query_skill("xiyu-zhang", 1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action":	action[j]["action"],
				"lvl":		action[j]["lvl"],
				"damage_type":	action[j]["damage_type"],
				"force":	150 + random(300),
				"dodge":	random(30),
				"parry":	random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("xiyu-zhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("������������������ơ�\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}
