//tianmo-dao.c ��ħ����
//By haiyan
#include <ansi.h>
inherit SKILL; 

mapping *action = ({
([      "action":"$N�߸�Ծ��һʽ������Ǭ��������$n$lһ����",
        "lvl"   :0,
        "skill_name" :"����Ǭ��",
        "damage_type":"����"
]),
([      "action":"ֻ��$N����$w�����μ��壬������$n����֮�ʣ�ͻȻʹ����꼻�һ�֡���$n����б�����¡�",
        "lvl"   :30,
        "skill_name" :"꼻�һ��",
        "damage_type":"����"
]),
([      "action":"$Nһʽ���Ǻ������졹������$w����һ������, �����ӵ�к�����$n$l��",
        "lvl"   :60,
        "skill_name" :"�Ǻ�������",
        "damage_type":"����"
]),
([      "action":"$N�����㱣�����$wƮҡ������һ�С��߷�Ʈҡ��бб�Ŀ���$n��$l��",
	      "lvl"   :90,
        "skill_name" :"�߷�Ʈҡ",
        "damage_type":"����"
]),
([      "action":"$N���һ����ʹ��һ�С������ã����˫�ֽ���$w���ű��˵�ɱ��������$n��$l��",
        "lvl"   :120,
        "skill_name" :"�����ã",
        "damage_type":"����"
]),
([      "action":"$Nб�����һ�С��˷����ˡ�������һƬ�������$n��$l��",
        "lvl"   :150,
        "skill_name" :"�˷�����",
        "damage_type":"����"
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
   if(!me->query_skill("xixing-dafa", 1)||(int)me->query_skill("tianmo-gong",1)<100)
   if(me->query_skill("tianmo-gong", 1) < 100 )
           return notify_fail("��������ڹ�����̫ǳ������ѧ��ħ����\n");
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

	level = (int) me->query_skill("tianmo-dao",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
						if ( me->query_temp("tmd/pfm1")){
				return ([
					"action":MAG+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"MAG), NOR, MAG)+NOR,
					"damage": 150+random(150),
					"damage_type": "����",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}
			if ( me->query_temp("tmd/huashen")){
				return ([
					"action":HIB+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIB), NOR, HIB)+NOR,
					"damage": 130+random(180),
					"damage_type": "����",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}
			if ( me->query_temp("tmd/jingshen")){
				return ([
					"action":HIR+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIR), NOR, HIR)+NOR,
					"damage": 200+random(300),
					"damage_type": "����",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}
			return ([
				"action" : action[j]["action"],
				"force" : 200 + random(350),
				"dodge" : random(25)-5,
				"parry": 20-random(10),
				"damage" : 100 + random(120),
				"damage_type" : action[j]["damage_type"],
				"lvl": action[j]["lvl"],
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("tianmo-dao", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 50 || me->query("neili") < 10 )
                return notify_fail("���������������ħ������\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tianmo-dao/" + action;
}
