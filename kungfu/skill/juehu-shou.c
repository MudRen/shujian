// juehu-shou.c -��צ������

inherit SKILL;

mapping *action = ({
([
	"action" : "$Nһʽ����ţ�����������ƻ�צ����ָ�繳�����۵ɵ�ͨ�죬ֱ��$n���ɲ�",
	"lvl" : 0,
	"skill_name" : "��ţ����",
	"damage_type" : "ץ��"
]),
([
	"action" : "$N��֫���أ�ͷ���״�������������������ͻȻ��֫����һ���Ѵܵ�$n���£������͵��ϴ�����һʽ����ƣ������",
	"lvl" : 30,
	"skill_name" : "��ƣ����",
	"damage_type" : "����"
]),
([
	"action" : "$N���ָ߸߾���������磬һʽ��׳ʿ���󡹣����۾ͳ�$n�����忳ȥ",
	"lvl" : 50,
	"skill_name" : "׳ʿ����",
	"damage_type" : "����"
]),
([
	"action" : "$NһԾ����ֱ��$n��˫�����£�˫����ס$n�ľ�����һŤ����˫�ֳɹ���֮�ƣ���$n���ɲ��ݺ���ȥ������һʽ����Ҷ�����",
	"lvl" : 80,
	"skill_name" : "��Ҷ���",
	"damage_type" : "����"
]),
([
	"action" : "$Nʹһʽ����ǰ���󡹣�����һ��Ϊ������ֻ�����������ư㳯$n�ĺ������ɲ���ȥ",
	"lvl" : 120,
	"skill_name" : "��ǰ����",
	"damage_type" : "����"
]),
([
	"action" : "$Nȫ��ؽ�žž���죬�����ֽ��һʽ�����Ӿ��������ӥצץ��$nȫ��Ҫ����˲������ӥצ�ֺ�Ϊһצֱ��$n���ɲ�ץ��",
	"lvl" : 150,
	"skill_name" : "���Ӿ���",
	"damage_type" : "ץ��"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����צ�����ֱ�����֡�\n");
	if ((int)me->query_skill("yinyun-ziqi", 1) < 40)
		return notify_fail("�����������򲻹����޷�ѧ��צ�����֡�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�����צ�����֡�\n");
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
	level   = (int) me->query_skill("juehu-shou",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"force":150+random(300),
				"dodge":random(30),
				"parry":random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("���������������צ�����֡�\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	me->add("shen", -100);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"juehu-shou/" + action;
}
