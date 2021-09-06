inherit SKILL;

mapping *action = ({
([
	"action" : "$N����б��������Ծ������,һ�С�����չ�᡹�����е�$w��$n��$l������ȥ",
	"lvl" : 0,
	"skill_name" : "����չ��",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ�С����ɽ�ڡ�������$w��$n�����̻�ȥ����δʹ�ϣ�����ֱ��$n��$l",
	"lvl" : 20,
	"skill_name" : "���ɽ��",
	"damage_type" : "����"
]),
([
	"action" : "$Nб������������$n��࣬һ�С��鵶��ˮ��,$w��������ƽƽ��ɨ$n��ǰ��",
	"lvl" : 40,
	"skill_name" : "�鵶��ˮ",
	"damage_type" : "����",
]),
([
	"action" : "$Nһ�С����Ƽ��ա������е�$w��$n�鿳һ�������к���ת��$n��$l��ȥ",
	"lvl" : 60,
	"skill_name" : "���Ƽ���",
	"damage_type" : "����"
]),
([
	"action" : "$N���浶���������Ծ��һ�С���ӥ���¡���ֱ��$n�Ҽ磬��ͽ���涵�˸���Բ������ͻ��,б��$n��$l",
	"lvl" : 80,
	"skill_name" : "��ӥ����",
	"damage_type" : "����"
]),
([
	"action" : "$N��Ȼ���з���һ�С������ѩ�������е�$w���������⣬��$n��$l��ȥ",
	"lvl" : 100,
	"skill_name" : "�����ѩ",
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
		return notify_fail("�������������ϰ���鵶����\n");
	if ((int)me->query_skill("yinyun-ziqi", 1) < 10)
		return notify_fail("������������̫ǳ��\n");
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
	level   = (int) me->query_skill("xuanxu-daofa",1);
	for(i = sizeof(action); i > 0; i--) {
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
}

int practice_skill(object me)
{
	int lvl = me->query_skill("xuanxu-daofa", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30 || me->query("neili") < 10)
		return notify_fail("����������������鵶����\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"xuanxu-daofa/" + action;
}
