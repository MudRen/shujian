// sanhua-zhang.c -ɢ����
inherit SKILL;
#include <ansi.h>
mapping *action = ({
([
	"action" : "$N���Ʊ���һʽ��"HIG"����ݾ�"NOR"����˫�Ʊ�����£���������$n��$l",
	"lvl" : 0,
	"skill_name" : "����ݾ�",
        "damage_type" : "����"
]),
([
	"action" : "$N��ָ������һʽ��"GRN"���ж���ܰ"NOR"���������ƴ��巭�ɣ�����$n��$l��ȥ",
	"lvl" : 30,
	"skill_name" : "���ж���ܰ",
        "damage_type" : "����"
]),
([
	"action" : "$Nʹһʽ��"HIY"�ﺨ��˪��"NOR"�����������У�����է��է�ϣ��͵ز���$n��$l",
	"lvl" : 60,
	"skill_name" : "�ﺨ��˪��",
        "damage_type" : "����"
]),
([
	"action" : "$N˫��Ѫ�죬һʽ��"HIW"������÷��"NOR"�����ó�����÷����䣬������$n��ȥ",
	"lvl" : 90,
	"skill_name" : "������÷��",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) 
{
	object me;
	me = this_player(); 

	if ((int)me->query_int(1) > 40)
		return combo=="nianhua-zhi"; 
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ɢ���Ʊ�����֡�\n");
	if ((int)me->query_skill("yijin-jing", 1) < 60)
		return notify_fail("����׽�ڹ���򲻹����޷�ѧɢ���ơ�\n");
	if ((int)me->query_int(1) > 30) {
		return 1;
	}
	else {
		if ( me->query_skill("banruo-zhang", 1)
		 && me->query_skill("yizhi-chan", 1)
		 && me->query_skill("jingang-quan", 1)
		 && me->query_skill("nianhua-zhi", 1)
		 && me->query_skill("qianye-shou", 1)
		 && me->query_skill("ruying-suixingtui", 1)
		 && me->query_skill("longzhua-gong", 1))
			return notify_fail("��Ĺ����������޷�ͬʱѧϰ�������ϵ��ϳ˹���\n");
	}
	if ((int)me->query("max_neili") < 600)
		return notify_fail("�������̫�����޷���ɢ���ơ�\n");
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
	level   = (int) me->query_skill("sanhua-zhang",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 150 + random(300),
				"dodge": random(30),
				"parry": random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("sanhua-zhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ( me->query("neili") < 20)
		return notify_fail("�������������ɢ���ơ�\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"sanhua-zhang/" + action;
}
