// cibei-dao.c �ȱ���

inherit SKILL;

mapping *action = ({
([
	"action" : "$N����$wбָ��һ�С�ͣ����·��������һ�٣�һ����$n��$l��ȥ",
	"lvl" : 0,
	"skill_name" : "ͣ����·",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С�ͯ�ӹһ�������������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
	"lvl" : 8,
	"skill_name" : "ͯ�ӹһ�",
	"damage_type" : "����"
]),
([
	"action" : "$Nչ���鲽������Ծ�䣬һ�С��ƴ����¡�������һ������ն��$n",
	"lvl" : 16,
	"skill_name" : "�ƴ�����",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С����ż�ɽ����$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
	"lvl" : 24,
	"skill_name" : "���ż�ɽ",
	"damage_type" : "����"
]),
([
	"action" : "$N����$wһ����һ�С���Ϫ���㡹��˫�ֳ����������У�����$n���ؿ�",
	"lvl" : 33,
	"skill_name" : "��Ϫ����",
	"damage_type" : "����"
]),
([
	"action" : "$N����$w��ʹ��һ�С��Ź����ġ����������ã����ҿ�����������$n",
	"lvl" : 42,
	"skill_name" : "�Ź�����",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С��������ۡ������Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
	"lvl" : 51,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([
	"action" : "$N����פ�أ�һ�С�������Ϣ�����ӳ�һƬ�����ĵ�Ӱ����$n��ȫ��ӿȥ",
	"lvl" : 60,
	"skill_name" : "ͣ����·",
	"damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("yijin-jing", 1) < 10)
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
	level   = (int) me->query_skill("cibei-dao",1);
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
	int lvl = me->query_skill("cibei-dao", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30 || me->query("neili") < 10)
		return notify_fail("��ľ����������ȱ�����\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
