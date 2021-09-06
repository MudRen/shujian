// murong-daofa.c Ľ�ݵ���

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action" : "$NͻȻ���һ�������С���һ�С�"HIY"����ǵ���׳־"NOR"�����������϶�����$n��$lնȥ",
	"lvl" : 0,
	"skill_name" : "����ǵ���׳־",
	"damage_type" : "����"
]),
([
	"action" : "$N���λ���һ�С�"HIR"�䵶��ת��Ǭ��"NOR"��������$w�ڿ��м��ٻγ������⻷������$n��$l",
	"lvl" : 30,
	"skill_name" : "�䵶��ת��Ǭ��",
	"damage_type" : "����"
]),
([
	"action" : "$N��һ����һ�С�"HIG"ң����ǧ��ѩ"NOR"��, $w�Ӳ���˼��ķ����$n�ľ���նȥ",
	"lvl" : 70,
	"skill_name" : "ң����ǧ��ѩ",
	"damage_type" : "����",
]),
([
	"action" : "$N����ӯ�ޱȣ�һ�С�"HIM"׳־����������"NOR"�����������⻯����㷱�ǣ���$n��$l��ȥ",
	"lvl" : 100,
	"skill_name" : "׳־����������",
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
	if ((int)me->query_skill("shenyuan-gong", 1) < 10)
		return notify_fail("�����Ԫ�����̫ǳ��\n");
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
	int i, j, level;
	level = (int) me->query_skill("murong-daofa",1);

	for(i = sizeof(action); i > 0; i--) {
		if(level >= action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			if( random(level) >= 150 && !random(4) && !me->query_temp("mr_daoying")){
				return ([
					"action":GRN+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"GRN), NOR, GRN)+NOR,
					"damage": 130+random(60),
					"damage_type": "����",
					"dodge": random(35),
					"parry": random(35),
					"force": 350+random(150),
				]);
			}
			if ( me->query_temp("mr_daoying")){
				return ([
					"action":CYN+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"CYN), NOR, CYN)+NOR,
					"damage": 130+random(60),
					"damage_type": "����",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}
			return ([
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"force": 150 +random(300),
				"dodge": random(30),
				"parry": random(30),
				"damage": 60 +random(100),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("murong-daofa", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 40)
		return notify_fail("�������������Ľ�ݵ�����\n");
	if ( me->query("neili") < 20)
		return notify_fail("�������������Ľ�ݵ�����\n");
	me->receive_damage("jingli", 30);
	me->add("neili",-10);
	return 1;
}
	   
string perform_action_file(string action)
{
	return __DIR__"murong-daofa/" + action;
}
