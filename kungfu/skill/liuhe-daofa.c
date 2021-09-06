//�������ϵ���

inherit SKILL;

mapping *action = ({
([
	"action" : "$Nһ����Х������$wһ�һʽ�����ǽ�$n���ڵ���֮��",
	"lvl" : 0,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С�Ǭ����ת��������$w�ڿ����������£�ͻȻ�»�����$n��$l",
	"lvl" : 20,
	"skill_name" : "Ǭ����ת",
	"damage_type" : "����"
]),
([
	"action" : "$N���¼�����̤���ķ����棬����$w����һ����â�����·��衣��һ����������",
	"lvl" : 40,
	"skill_name" : "��������",
	"damage_type" : "����",
]),
([
	"action" : "$N��ɫ��ɱ��һ���������е�����˸������һƬ�̹ǵĵ��罫$n����Χס�����������ϡ�!",
	"lvl" : 60,
	"skill_name" : "��������",
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
	if ( me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ( me->query_skill("huntian-qigong", 1) < 30)
		return notify_fail("��Ļ����������̫ǳ��\n");
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
	level   = (int) me->query_skill("liuhe-daofa",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"force":100+random(250),
				"dodge":random(20)-10,
				"damage":40+random(60),
				"parry":random(10),
			]);
		}

}

int practice_skill(object me)
{
	int lvl = me->query_skill("liuhe-daofa", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 30 || me->query("neili") < 10)
		return notify_fail("��������������������ϵ�����\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"liuhe-daofa/" + action;
}
