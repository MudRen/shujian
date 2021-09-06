// zui-gun.c -�������

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action":"�����ɺͣ�����Ȱ�������ʡ���$N����$w���ᣬ�������ǣ���������$n��$l",
	"lvl" : 0,
	"skill_name" : "���ɺͣ�����Ȱ��������",
	"damage_type":"����"
]),
([
	"action":"�����ɹã������������ɲ�����$N����Ť�����ұ�Ю$w˳���͵�ɨ��$n��$l",
	"lvl" : 10,
	"skill_name" : "���ɹã������������ɲ�",
	"damage_type":"����"
]),
([
	"action":"���ܹ��ˣ�ǧ���������ѡ���$N��ǰһ�Σ�����$w��ָ���أ���$n��$l��ȥ",
	"lvl" : 20,
	"skill_name" : "�ܹ��ˣ�ǧ����������",
	"damage_type":"����"
]),
([
	"action":"�������ӣ������������������$Nҡͷ���ԣ�����$w�����˻��˸���Ȧ������$n��$l",
	"lvl" : 40,
	"skill_name" : "�����ӣ��������������",
	"damage_type":"����"
]),
([
	"action":"�������룬������������������$N���й������ţ��Ų�Ҳҡҡ�ڰڣ�ɨ�𼲷�������$n",
	"lvl" : 60,
	"skill_name" : "�����룬��������������",
	"damage_type":"����"
]),
([
	"action":"��������ߵ���ɽ����ء���$N����֧�أ���һ������$w��������˦��$n��$l",
	"lvl" : 90,
	"skill_name" : "������ߵ���ɽ�����",
	"damage_type":"����"
]),
([
	"action":"���Ź��ϣ�����ױ�����¿����$NŤ������ҡҡ��׹��$w�ӿ�����������$n���ؿ�",
	"lvl" : 120,
	"skill_name" : "�Ź��ϣ�����ױ�����¿",
	"damage_type":"����"
]),
([
	"action":"�������������������ǧ������$N�������ʣ���ȴ�������ᣬ����$wЮǧ��֮��ѹ��$n",
	"lvl" : 150,
	"skill_name" : "�����������������ǧ��",
	"damage_type":"����"
]),
});

string  *msg = ({
HIG"�����ɺͣ�����Ȱ�������ʡ���$N����$w"HIG"���ᣬ�������ǣ���������$n��$l"NOR,
HIY"$P˳�ƽ��š����ɹã������������ɲ���������Ť�����ұ�Ю$w"HIY"˳���͵�ɨ��$n��$l"NOR,
HIM"Ȼ��һʽ���ܹ��ˣ�ǧ���������ѡ�����ǰһ�Σ�����$w"HIM"��ָ���أ���$n��$l��ȥ"NOR,
HIC"������һ�С������ӣ������������������$Pҡͷ���ԣ�����$w"HIC"�����˻��˸���Ȧ������$n��$l"NOR,
HIW"����һ�С������룬������������������$P���й������ţ��Ų�Ҳҡҡ�ڰڣ�ɨ�𼲷�������$n"NOR,
HIB"˳��һ�ԡ�������ߵ���ɽ����ء���$P����֧�أ���һ������$w"HIB"��������˦��$n��$l"NOR,
HIR"Ȼ���Ź��ϣ�����ױ�����¿����$PŤ������ҡҡ��׹��$w"HIR"�ӿ�����������$n���ؿ�"NOR,
HIC"���һʽ�������������������ǧ������$P�������ʣ���ȴ�������ᣬ����$w"HIC"Юǧ��֮��ѹ��$n"NOR,
});

int valid_enable(string usage) { return (usage == "club") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "club")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query("max_neili") < 800)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("yijin-jing", 1) < 70)
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
	level   = (int) me->query_skill("zui-gun",1);
	
	if ((int)me->query_temp("zuijiu")) {
		return([
			"action": msg[(int)me->query_temp("zuijiu")-1],
			"force" : 200 + random(300),
			"dodge" : random(35),
			"damage": 120 + random(100),
			"parry": random(35),
			"damage_type" : "����",
		]);
	}
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 150 + random(300),
				"dodge": random(30),
				"damage": 60 + random(100),
				"parry": random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("zui-gun", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 40 || me->query("neili") < 20)
		return notify_fail("����������������������\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"zui-gun/" + action;
}
