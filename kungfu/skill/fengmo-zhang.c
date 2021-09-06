// fengmo-zhang.c ��ħ�ȷ�
// by hunthu
// update by cool
// Lklv update 2001.10.05

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action": "$Nб��$w, һ�С�������ʯ����б���������$n��$l",
	"lvl" : 0,
	"skill_name" : "������ʯ",
	"damage_type": "����"
]),
([
	"action": "$Nһ����ȣ�ʹ��һ�С�³�������, ����$w���¶���ɨ��$n��$l",
	"lvl" : 20,
	"skill_name" : "³�����",
	"damage_type": "����"
]),
([
	"action": "$Nʹ��һ�С���������������$w�Ӽ�ͷ˦��������$n��$l",
	"lvl" : 40,
	"skill_name" : "��������",
	"damage_type": "����"
]),
([
	"action": "$N����һ�Σ�һ�С�������򡹣�����$w���籩�����$n���",
	"lvl" : 60,
	"skill_name" : "�������",
	"damage_type": "����"
]),
([
	"action": "$Nһ��������һ�С����羭�졹, $w����������������$n��$l",
	"lvl" : 80,
	"skill_name" : "���羭��",
	"damage_type": "����"
]),
});

string query_skill_name(int level)
{
	int i = sizeof(action);
	while (i--)
		if(level > action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level, j;

	if( me->query_skill("staff", 1) >= 120
	 && me->query_skill("fengmo-zhang", 1) >= 120
	 && me->query_skill("force",1) >= 100
	 && me->query("neili") >= 500
	 && random(me->query_str(1)) >= 25
	 && me->query("shen")+1000 < 0 && random(2) ) {
		return ([
			"action": RED"$N����ͻ��ɷ��������$w������$n���Ի��䡣��һ�ȳ����ֿ��ֺݣ����ǡ���ħ�ȷ����еĶ���"NOR,
			"damage": 50+random(60),
			"parry": random(15),
			"dodge": random(20) - 5,
			"force": 110+random(250),
			"damage_type": "����"
		]);
	}
	level = (int) me->query_skill("fengmo-zhang",1);
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

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("�����ϵ�����������������ħ�ȷ���\n");
	if(me->query_skill("huntian-qigong", 1) < 20)
		return notify_fail("��Ļ��������ȼ�������\n");
	if(me->query("max_neili") < 200)
		return notify_fail("�㻹���ȼ��о������������ɡ�\n");
	return 1;
}

int practice_skill(object me)
{
	int lvl = me->query_skill("fengmo-zhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if (me->query("jingli") < 30)
		return notify_fail("����Ъ���������ɡ�\n");
	if( me->query("neili") < 15)
		return notify_fail("���������������ħ�ȷ�����\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"fengmo-zhang/" + action;
}
