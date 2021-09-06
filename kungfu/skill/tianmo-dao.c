//tianmo-dao.c 天魔刀法
//By haiyan
#include <ansi.h>
inherit SKILL; 

mapping *action = ({
([      "action":"$N高高跃起，一式「刀劈乾坤」，向$n$l一劈！",
        "lvl"   :0,
        "skill_name" :"刀劈乾坤",
        "damage_type":"劈伤"
]),
([      "action":"只见$N倒提$w，身形急冲，就在与$n错身之际，突然使出「昙花一现」从$n后脑斜劈而下。",
        "lvl"   :30,
        "skill_name" :"昙花一现",
        "damage_type":"劈伤"
]),
([      "action":"$N一式「星河欲曙天」，手中$w化做一道刀光, 似银河倒泻般挥向$n$l。",
        "lvl"   :60,
        "skill_name" :"星河欲曙天",
        "damage_type":"砍伤"
]),
([      "action":"$N眼神恍惚，手中$w飘摇不定，一招「边风飘摇」斜斜的砍向$n的$l。",
	      "lvl"   :90,
        "skill_name" :"边风飘摇",
        "damage_type":"砍伤"
]),
([      "action":"$N狂喝一声，使出一招「绝域苍茫」，双手紧握$w带着逼人的杀气，刺向$n的$l。",
        "lvl"   :120,
        "skill_name" :"绝域苍茫",
        "damage_type":"刺伤"
]),
([      "action":"$N斜身飞起，一招「乘风破浪」，带出一片刀光卷向$n的$l。",
        "lvl"   :150,
        "skill_name" :"乘风破浪",
        "damage_type":"劈伤"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");
   if(!me->query_skill("xixing-dafa", 1)||(int)me->query_skill("tianmo-gong",1)<100)
   if(me->query_skill("tianmo-gong", 1) < 100 )
           return notify_fail("你的特殊内功功力太浅，不能学天魔刀。\n");
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
					"damage_type": "割伤",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}
			if ( me->query_temp("tmd/huashen")){
				return ([
					"action":HIB+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIB), NOR, HIB)+NOR,
					"damage": 130+random(180),
					"damage_type": "割伤",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}
			if ( me->query_temp("tmd/jingshen")){
				return ([
					"action":HIR+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIR), NOR, HIR)+NOR,
					"damage": 200+random(300),
					"damage_type": "割伤",
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
                return notify_fail("你的体力不够练天魔刀法。\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tianmo-dao/" + action;
}
