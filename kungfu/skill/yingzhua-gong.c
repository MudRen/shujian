// yingzhua-gong.c -ӥצ��

inherit SKILL;

mapping *action = ({
([
	"action" : "$Nȫ��εض��𣬰����һ�����һʽ����ӥϮ�á���Ѹ�͵�ץ��$n��$l",
	"lvl" : 0,
	"skills_name" : "��ӥϮ��",
	"damage_type" : "����"
]),
([
	"action" : "$N����ֱ����˫��ƽ�죬һʽ����ӥչ�᡹��˫צһǰһ��£��$n��$l",
	"lvl" : 10,
	"skills_name" : "��ӥչ��",
        "damage_type" : "����"
]),
([
	"action" : "$Nһʽ���γ��ɡ���ȫ����б��ƽ�ɣ�����һ����˫צ����$n�ļ�ͷ",
	"lvl" : 20,
	"skills_name" : "�γ���",
        "damage_type" : "����"
]),
([
	"action" : "$N˫צ�����Ͼ٣�ʹһʽ��ӭ��������һ�����ֱ�Ϯ��$n����Ҹ����",
	"lvl" : 30,
	"skills_name" : "ӭ������",
        "damage_type" : "����"
]),
([
	"action" : "$Nȫ�������ǰ��һʽ��������צ������צͻ�������Ȱ�ץ��$n���ؿ�",
	"lvl" : 40,
	"skills_name" : "������צ",
        "damage_type" : "����"
]),
([
	"action" : "$N���ػ��У�һʽ������հ�ա�������Ϯ�����д�Ѩ�����ַ�ץ$n���ɲ�",
	"lvl" : 50,
	"skills_name" : "����հ��",
        "damage_type" : "����"
]),
([
	"action" : "$N��������צ���棬һʽ���������ա��������������ƿն�����Ѹ���ޱȵػ���$n",
	"lvl" : 55,
	"skills_name" : "��ӥϮ��",
        "damage_type" : "����"
]),
([
	"action" : "$N�ڿո߷����ɣ�һʽ��ӥ�����������ж�ʱ�Գ�һ������צӰ����������$n",
	"lvl" : 60,
	"skills_name" : "��ӥϮ��",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

int valid_combine(string combo) { return combo=="weituo-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ӥצ��������֡�\n");
	if ((int)me->query_skill("yijin-jing", 1) < 20)
		return notify_fail("����׽�ڹ���򲻹����޷�ѧӥצ����\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷���ӥצ����\n");
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
	level   = (int) me->query_skill("yingzhua-gong",1);
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
	int lvl = me->query_skill("yingzhua-gong", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("�������������ӥצ����\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

