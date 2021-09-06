// fengyun-shou.c -������

inherit SKILL;

mapping *action = ({
([
	"action" : "$Nһʽ���������ա������ƻ�צ����ָ�繳��ֱ��$n������ҪѨ",
	"lvl" : 0,
        "skill_name" : "��������",
	"damage_type" : "����"
]),
([
	"action" : "$N������Σ�һʽ���һ����ơ�����������ֱ��������$n�ļ羮��Ѩ",
	"lvl" : 8,
        "skill_name" : "�һ�����",
        "damage_type" : "����"
]),
([
	"action" : "$Nʹһʽ���������󡹣���ָ��������ò�ʩ������$n����·Ҫ��",
	"lvl" : 16,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([
	"action" : "$N����ӥץ�������߾٣�һʽ����Ŀ�ѻԡ�����$n���нڴ���",
	"lvl" : 24,
        "skill_name" : "��Ŀ�ѻ�",
        "damage_type" : "����"
]),
([
	"action" : "$Nʹһʽ�������ķ���������˷�����������Ӱ��һצͻ����ץ��$n���ؿ�",
	"lvl" : 40,
        "skill_name" : "�����ķ�",
        "damage_type" : "����"
]),
([
	"action" : "$N���ֻ��ۣ�ȫ��ؽ�žž���죬һʽ��ˮ�����ɡ�������$n��$l",
	"lvl" : 48,
        "skill_name" : "ˮ������",
        "damage_type" : "����"
]),
([
	"action" : "$Nһʽ��ɽ�����ܡ���ʮָ���죬������հ������$n��ȫ��ҪѨ",
	"lvl" : 54,
        "skill_name" : "ɽ������",
        "damage_type" : "����"
]),
([
	"action" : "$N�������ţ�һʽ��������ġ�����һ�������У�˫��ͬʱ����$n���ߵ���Ѩ",
	"lvl" : 100,
        "skill_name" : "�������",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="shaolin-tantui"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������ֱ�����֡�\n");
	if ((int)me->query_skill("yijin-jing", 1) < 10)
		return notify_fail("����׽�ڹ���򲻹����޷�ѧ�����֡�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷��������֡�\n");
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
	level   = (int) me->query_skill("fengyun-shou",1);
	for(i = sizeof(action); i > 0; i--){
		if(level > action[i-1]["lvl"]){
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
	int lvl = me->query_skill("fengyun-shou", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("������������������֡�\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
