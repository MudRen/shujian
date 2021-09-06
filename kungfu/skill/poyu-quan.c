// poyu-quan.c -��ʯ����ȭ

inherit SKILL;

mapping *action = ({
([
	"action" : "$Nһʽ������ʽ����������˦�����ⷴ�У�˫ȭ���ƶ���������$n��$l",
	"lvl" : 0,
	"skill_name" : "����ʽ",
	"damage_type" : "����"
]),
([
	"action" : "$Nһʽ��ʯ���쾪�����������ϣ��������£�ȭ����ž���죬һ�ɾ���ֱ��$n��$l",
	"lvl" : 10,
	"skill_name" : "ʯ�ƾ���",
	"damage_type" : "����"
]),
([
	"action" : "$Nȫ���������ڿշ���һʽ�����ź��š���˫ȭ˫��������������ڣ���$n�޿ɶ��",
	"lvl" : 20,
	"skill_name" : "���ź���",
	"damage_type" : "����"
]),
([
	"action" : "$N�������أ�˫���麬����Ե�³������һ����һʽ��ǧ��׹�ء���������$n�Ƴ�",
	"lvl" : 30,
	"skill_name" : "ǧ��׹��",
	"damage_type" : "����"
]),
([
	"action" : "$Nһ��ǰ�죬һ�ۺ�ָ��һʽ�����������������м���ֱ$n��ǰ������$n��$l",
	"lvl" : 40,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([
	"action" : "$Nһʽ�����ֿβ������ȭ�������ϣ���ȭ�����ң�Ѹ�ײ����ڶ�֮��˫˫����$n��$l",
	"lvl" : 50,
	"skill_name" : "���ֿβ",
	"damage_type" : "����"
]),
([
	"action" : "$N��Ŀ���ӣ�˫��������һʽ������֡���˫ȭ����$n��ֻ��$n������ȥ���ֻ���$n��$l",
	"lvl" : 60,
	"skill_name" : "�����",
	"damage_type" : "����"
]),
([
	"action" : "$N������Ϣ������˫ȭ��һʽ����ʯ���񡹣�ȫ������������������þ�ȫ����������$n��$l",
	"lvl" : 80,
	"skill_name" : "��ʯ����",
	"damage_type" : "����"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if ( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ʯ����ȭ����֡�\n");
   if ( me->query_skill("zixia-gong", 1) < 10 && me->query_skill("huashan-qigong", 1) < 10)
		return notify_fail("�����ϼ�񹦲������޷�ѧ��ʯ����ȭ��\n");
	if ( me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷�����ʯ����ȭ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level, j;
	level = me->query_skill("poyu-quan",1);
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
	int lvl = me->query_skill("poyu-quan", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ( me->query("neili") < 20)
		return notify_fail("���������������ʯ����ȭ��\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"poyu-quan/" + action;
}
