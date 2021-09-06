// xiuluo-dao.c ���޵�

inherit SKILL;

mapping *action = ({
([
	"action" : "$N�ص����գ�һ�С�������ӥ�����������¶��ϻ��˸��뻡����$n��$l��ȥ",
	"lvl" : 0,
	"skill_name" : "������ӥ",
	"damage_type" : "����"
]),
([
	"action" : "$N�����������⣬һ�С�Ͷ�������������$w��ֱ����$n��$l",
	"lvl" : 12,
	"skill_name" : "Ͷ�����",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С��ͷл�졹��$w�ƾ�������ˢ��һ�����϶�����$n����",
	"lvl" : 18,
	"skill_name" : "�ͷл��",
	"damage_type" : "����"
]),
([
	"action" : "$N���ַ�ִ������һ�С��۹ǳ��衹����һ����$wֱ��$n�ľ���նȥ",
	"lvl" : 24,
	"skill_name" : "�۹ǳ���",
	"damage_type" : "����",
]),
([
	"action" : "$Nһ�С�����ǧ�ơ����������⻯����㷱�ǣ���$n��$l��ȥ",
	"lvl" : 30,
	"skill_name" : "����ǧ��",
	"damage_type" : "����"
]),
([
	"action" : "$N˫�ֺ�ִ$w��һ�С����۲�ʩ����š��ת������ֱ����$n��˫��",
	"lvl" : 36,
	"skill_name" : "���۲�ʩ",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С���Ƥ�龭��������$w����һ����ƽʮ�֣���$n�ݺ���ȥ",
	"lvl" : 42,
	"skill_name" : "��Ƥ�龭",
	"damage_type" : "����"
]),
([
	"action" : "$N��ת�����׼�Լ���һ�С����ľ�־����ȫ��һ��������$w��$n����նȥ",
	"lvl" : 48,
	"skill_name" : "���ľ�־",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С������𡹣�$w�ĵ���·𻯳�һ�ش����棬��$n����Χ��",
	"lvl" : 54,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([
	"action" : "$N����ƽָ��һ�С���Ѫ���ء���һƬƬ�йǵ�����쫷�����$n��ȫ��",
	"lvl" : 60,
	"skill_name" : "��Ѫ����",
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
		return notify_fail("����׽�ڹ����̫ǳ��\n");
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
	level   = (int) me->query_skill("xiuluo-dao",1);
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
	int lvl = me->query_skill("xiuluo-dao", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30 || me->query("neili") < 10)
		return notify_fail("����������������޵���\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
