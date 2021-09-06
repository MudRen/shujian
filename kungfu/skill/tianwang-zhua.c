// tianwang-zhua.c �������צ
//  by iceland
inherit SKILL;

mapping *action = ({
([
	"action" : "$N����̽��һʽ�����ơ�����������ǰ��צ�黤����צֱ̽$n������",
	"lvl" : 0,
	"skills_name" : "����",
	"damage_type" : "ץ��"
]),
([
	"action" : "$Nһʽ����ơ���������������׷�����б������$n��࣬���ֿ���$n����",
	"lvl" : 10,
	"skills_name" : "���",
	"damage_type" : "ץ��"
]),
([
	"action" : "$N�੹�Х���������ǣ�һʽ�����������ڽ�$n���У�˫צ���ۣ�����$n",
	"lvl" : 20,
	"skills_name" : "����",
	"damage_type" : "����"
]),
([
	"action" : "$N�ڿ�Ծ��ʹһʽ�����֡���˫צǰ�󽻴������һץ����һץ���Ƶ�$n��������",
	"lvl" : 30,
	"skills_name" : "����",
	"damage_type" : "ץ��"
]),
([
	"action" : "$N˫Ŀ������գ����������дʣ�һʽ��ײ�ӡ������ִ�������֮�ϣ���צ��˫��֮��ֱ����$n��$l",
	"lvl" : 40,
	"skills_name" : "ײ��",
	"damage_type" : "����"
]),
([
	"action" : "$N����������һʽ�����㡹��˫צ����ǰ�鰴���ó�����צӰ��ָ�������ƿ�˿˿���죬ңң����$nȫ��",
	"lvl" : 50,
	"skills_name" : "����",
	"damage_type" : "ץ��"
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������צ������֡�\n");
	if ( me->query_skill("longxiang-boruo", 1) < 30)
		return notify_fail("��������������򲻹�������ѧ�������צ��\n");
	if ( me->query_skill("force", 1) < 30)
		return notify_fail("��Ļ����ڹ���򲻹�������ѧ�������צ��\n");
	if ( me->query("max_neili") < 150)
		return notify_fail("�������̫���������˽������צ��\n");
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
	level   = (int) me->query_skill("tianwang-zhua",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"weapon": action[j]["weapon"],
				"force":100+random(250),
				"dodge":random(20)-10,
				"parry":random(10),
			]);
		}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("tianwang-zhua", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;
	if ( me->query("jingli") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ( me->query("neili") < 10)
		return notify_fail("��������������������צ��\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
