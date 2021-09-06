// cuogu-shou.c �ֽ�����

inherit SKILL;

mapping *action = ({
([
	"action" : "$Nһʽ��������ߡ�������̧�����ְ��أ�ͻȻ����$n��$l",
	"lvl" : 0,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([
	"action" : "$N����һ�Σ�һʽ��˫����֡�����������$n�ļ�ͷ����ȭ����$n���ؿ�",
	"lvl" : 10,
	"skill_name" : "˫�����",
	"damage_type" : "����"
]),
([
	"action" : "$Nһʽ����ӥ��צ����˫�ֻ�£��צ�����ֻ��壬���ֿ���$n��$l",
	"lvl" : 20,
	"skill_name" : "��ӥ��צ",
	"damage_type" : "ץ��"
]),
([
	"action" : "$N����ס��һ����һ��б����ʽ��һʽ������չ�᡹��������$nɨ��",
	"lvl" : 30,
	"skill_name" : "����չ��",
	"damage_type" : "ץ��"
]),
([
	"action" : "$Nʹһʽ����ȸ���᡹��һ��������ŷ�����$n���ɲ���ȥ",
	"lvl" : 40,
	"skill_name" : "��ȸ����",
	"damage_type" : "����"
]),
([
	"action" : "$N����һ�죬һʽ��Գ����֡����ֱ�ͻȻ������������$n��$lһ��",
	"lvl" : 50,
	"skill_name" : "Գ�����",
	"damage_type" : "ץ��"
]),
([
	"action" : "$N˫�ֱ�ȭ��һʽ�����ڷɻ����������������ĳ���Ʈ�ݾ��ڵ�����$n��$l",
	"lvl" : 60,
	"skill_name" : "���ڷɻ�",
	"damage_type" : "����"
]),
([
	"action" : "$Nһʽ�����ɻ�����������������бб������бб������$n��$l",
	"lvl" : 70,
	"skill_name" : "���ɻ�",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���ֽ����ֱ�����֡�\n");

	if ( me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷����ֽ����֡�\n");
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
	level   = (int) me->query_skill("cuogu-shou",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
				"force": 150 +random(300),
				"dodge": random(30),
				"parry": random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("cuogu-shou", 1);
	int i = sizeof(action);
	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("��������������ֽ����֡�\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
