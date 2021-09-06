//tianmo-gun.c 日月天魔棍
//By xjqx@SJ 2009/1/1

inherit SKILL; 

mapping *action = ({
([      "action":"$N身形稍退，手中$w迎风一抖，一招「月黑风高」，朝着$n劈头盖脸地砸将下来。",
        "lvl"   :0,
        "skill_name" :"月黑风高",
        "damage_type":"砸伤"
]),
([      "action":"$N面带戚色，手中$w以一招「凄风长号」狂风骤雨般地向$n的$l连连扫去。",
        "lvl"   :20,
        "skill_name" :"凄风长号",
        "damage_type":"挫伤"
]),
([      "action":"$N身形一转，手中$w往后一拖，就在这将退未退之际，一招「峰回路转」，向$n当头砸下。",
        "lvl"   :50,
        "skill_name" :"峰回路转",
        "damage_type":"砸伤"
]),
([      "action":"$N身形一转，一招「寒风起兮」$w幻出满天棍影，虚虚实实地袭向$n的$l。",
        "lvl"   :80,
        "skill_name" :"寒风起兮",
        "damage_type":"瘀伤"
]),
([      "action":"$N袖舞时幻起花雨满天，$w落处化作断霞千缕，一式「生死相随」，着着抢攻，全然不顾$n进招。",
        "lvl"   :120,
        "skill_name" :"生死相随",
        "damage_type":"瘀伤"
]),
([      "action":"$n忽然不见$N，猛一抬头只见$N一式「策馬長川」，急风骤雨一般径直扫向$n$l。",
        "lvl"   :150,
        "skill_name" :"策馬長川",
        "damage_type":"挫伤"
]),
});

int valid_enable(string usage) { return usage == "club" || usage == "parry"; }

int valid_learn(object me)
{
   if(!me->query_skill("xixing-dafa", 1)||(int)me->query_skill("tianmo-gong",1)<100)
   if(me->query_skill("tianmo-gong", 1) < 100 )
           return notify_fail("你的特殊内功功力太浅，不能学天魔棍。\n");

     if ((int)me->query_skill("club", 1) < 100)
         return notify_fail("你的基本棍法火候不够。\n");

     if ((int)me->query("max_neili") < 350)
         return notify_fail("你的内力太低，无法学日月天魔棍。\n");

     if ((int)me->query_skill("club", 1) < (int)me->query_skill("tianmo-gun", 1))
         return notify_fail("你的基本棍法水平有限，无法领会更高深的日月天魔棍。\n");

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

	level = (int) me->query_skill("tianmo-gun",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action" : action[j]["action"],
				"force" : 200 + random(350),
				"dodge" : random(25)-5,
				"parry": 20-random(10),
				"damage" : 100 + random(120),
				"damage_type" : action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"damage" : 100 + random(120),
			]);
		}
	}
				if ( me->query_temp("tmg/luanwu")){
				return ([
					"action" : action[j]["action"],
					"damage": 150+random(180),
					"damage_type": "割伤",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}
							if ( me->query_temp("tmg/tian")){
				return ([
					"action" : action[j]["action"],
					"damage": 150+random(180),
					"damage_type": "割伤",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(500),
				]);
			}
}

int practice_skill(object me)
{
     object weapon;

     if (! objectp(weapon = me->query_temp("weapon")) ||
        (string)weapon->query("skill_type") != "club")
            return notify_fail("你使用的武器不对。\n");

     if ((int)me->query("jingli") < 70)
            return notify_fail("你的体力不够练日月天魔棍。\n");

     if ((int)me->query("neili") < 80)
            return notify_fail("你的内力不够练日月天魔棍。\n");

     me->receive_damage("jingli", 65);
     return 1;
}

string perform_action_file(string action)
{
     return __DIR__"tianmo-gun/" + action;
}

