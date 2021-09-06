// taishan-jianfa.c
// Modified by XiaoYao

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"skill_name" :"��������",
	"action":  "$N����$wһ�Σ����һ���������һ��"HIB"���������ơ�"NOR"��ת������������΢����$w��$nбб��ȥ",
        "lvl" : 0
]),
([	"skill_name" :"������",
	"action":  "$N����$wȦת��һ��"HIC"�������ա�"NOR"ȥ���漲�������������$n��$l",
	"lvl" : 15
]),
([	"skill_name" :"������Ȫ",
	"action": "$NͻȻ��һ�䣬ͦ$w��$n��ȥ����һ����������������һ��"HIC"��������Ȫ��"NOR"",
	"lvl" : 30
]),
([	"name":    "ʯ�ػ���",
	"action":  "$N����$wˢ��һ�������ֿ���$n������Բ�����⣺"HIY"��ʯ�ػ���"NOR"��",
	"lvl" : 45
]),
([	"skill_name" : "̩ɽʮ����",
	"action":  "$Nչ�����ƣ����潣�ߣ����һ�գ��ұ�һ�䣬ԽתԽ�����͵�$w���Ⱪ����һ��"HIM"��̩ɽʮ���̡�"NOR"��$n$l��ȥ",
	"lvl" : 60
]),
([	"skill_name" :"�������",
	"action": "$N�ֱ۱���������$w���չ����ˢˢ������ָ��$n������"GRN"��������"NOR"",
	"lvl" : 75
]),
([	"skill_name" :  "�����䳤��",
	"action":  "$Nһ��"HIR"�������䳤�ա�"NOR"ͦ$w��$n���ش�ȥ��������˸��$w��������֮������ס��$n�ؿڡ����С�������ء��������桱������⡱�������ȡ��������š�����ͨ�ȡ��ߴ���Ѩ",
	"lvl" : 90
]),
([	"skill_name" :"����",
	"action":  "$N����$wٿ�ش̳���һ���彣��ÿһ���Ľ��нԲ�Ȼ�й��⡣�������ӣ��ڲ���䣬����"HIW"�����򽣡�"NOR"",
	"lvl" : 105
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	 || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if (me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("panshi-shengong", 1) < 50)
		return notify_fail("�����ʯ�񹦻��̫ǳ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level,j;
	level   = (int) me->query_skill("taishan-jianfa",1);
	if( me->query_temp("tsjf/daizong")) {
		for(i = sizeof(action); i > 0; i--) { 
			if(level >= action[i-1]["lvl"]) {
				j = NewRandom(i, 20, level/5);
				return ([
					"action": action[j]["action"],
					"lvl": action[j]["lvl"],
					"damage_type": action[j]["damage_type"],
					"force": 150 + random(300),
					"dodge": random(30),
					"parry": random(30),
					"damage": 250+ random(300),
				]);
			}
		}
	}
	for(i = sizeof(action); i > 0; i--) { 
			if(level >= action[i-1]["lvl"]) {
				j = NewRandom(i, 20, level/5);
		if( me->query_temp("tsjf/shibapan")) {
	
				return ([
			"action" : action[j]["action"],
				"force" : 100 + random(350),
				"dodge" : random(25)-5,
				"parry": 20-random(10),
				"damage" : 200 + random(300),
				"damage_type" : action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				]);
			}
		}
	}
	for(i = sizeof(action); i > 0; i--) { 
			if(level >= action[i-1]["lvl"]) {
				j = NewRandom(i, 20, level/5);
return ([
				"action" : action[j]["action"],
				"force" : 100 + random(350),
				"dodge" : random(25)-5,
				"parry": 20-random(10),
				"damage" : 100 + random(80),
				"damage_type" : action[j]["damage_type"],
				"lvl": action[j]["lvl"],
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("taishan-jianfa", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 50)
		return notify_fail("�������������̩ɽ������\n");
	if((int)me->query("neili") < 20)
		return notify_fail("�������������̩ɽ������\n");
		me->receive_damage("jingli", 40);
		me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taishan-jianfa/" + action;
}
