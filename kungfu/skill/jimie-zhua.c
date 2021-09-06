// jimie-zhua.c ����צ

inherit SKILL;

mapping *action = ({
([
	"action" : "$Nȫ��εض���һʽ���������ҡ���˫צѸ�͵�ץ��$n��$l",
	"lvl" : 0,
	"skills_name" : "��������",
	"damage_type" : "����"
]),
([
	"action" : "$N���һ��������������ץ��һʽ��������Ե����˫צץ��$n��ͷ�����ز�",
	"lvl" : 10,
	"skills_name" : "������Ե",
	"damage_type" : "����"
]),
([
	"action" : "$Nһʽ���һ����ơ���˫�ƻ�ָ����ʱ�䣬һ�����ͱ��˵���������$n",
	"lvl" : 20,
	"skills_name" : "�һ�����",
	"damage_type" : "����"
]),
([
	"action" : "$N˫צ����һʽ���ն�����������������ֱ�Ϯ��$n����Ҹ����",
	"lvl" : 30,
	"skills_name" : "�ն�����",
	"damage_type" : "����"
]),
([
	"action" : "$Nһʽ�����Ǿۻ᡹����צͻ������צ������˫צ�����ץ��$n���ؿ�",
	"lvl" : 40,
	"skills_name" : "���Ǿۻ�",
	"damage_type" : "����"
]),
([
	"action" : "$Nԭ�ز�����һʽ�����ݴ��͡���ֻ��$nϮ����˫צϮ��$n���д�Ѩ���ɲ�",
	"lvl" : 50,
	"skills_name" : "���ݴ���",
	"damage_type" : "����"
]),
([
	"action" : "$N��˫צ�����������ƿն�������һʽ�������޷졹��Ѹ���ޱȵػ���$n",
	"lvl" : 60,
	"skills_name" : "�����޷�",
	"damage_type" : "����"
]),
([
	"action" : "$N�ڿո߷����ɣ�һʽ�������Ƶء���һʱ����г�������$N����Ӱ����$n",
	"lvl" : 60,
	"skills_name" : "�����Ƶ�",
	"damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

int valid_combine(string combo) { return combo=="mohe-zhi"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������צ������֡�\n");
	if ((int)me->query_skill("yijin-jing", 1) < 10)
		return notify_fail("����׽�ڹ���򲻹����޷�ѧ����צ��\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷���ϰ����צ��\n");
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
	level   = (int) me->query_skill("jimie-zhua",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 100 + random(250),
				"dodge": random(20)-10,
				"parry": random(10),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("jimie-zhua", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("�����������������צ��\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
