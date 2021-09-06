//tianmo-shou.c 天魔手法
//By xjqx@SJ 2009/1/1

inherit SKILL; 

mapping *action = ({
([      "action":"$N一招「覆雨翻云」，左手抓向$n的丹田，就在$n回身自防的一瞬间，右手却已掐上了$n的$l。",
        "lvl"   :0,
        "skill_name" :"覆雨翻云",
        "damage_type":"瘀伤"
]),
([      "action":"$N双手一错，右手向外横推而出，一招「风起云涌」带着一股劲风拍向$n的$l。",
        "lvl"   :50,
        "skill_name" :"风起云涌",
        "damage_type":"瘀伤"
]),
([      "action":"忽听$N一声怒吼，右手高高举起，一式「高山流水」，砍向$n的$l。",
        "lvl"   :80,
        "skill_name" :"高山流水",
        "damage_type":"砍伤"
]),
([      "action":"$N身子微斜，随即跨出一步，左手忽掌忽爪使出「两处茫茫」，拍向$n的$l。",
        "lvl"   :130,
        "skill_name" :"两处茫茫",
        "damage_type":"瘀伤"
]),
([      "action":"$N使出「出没风波里」，双手滑溜异常对准$n的$l抓去。",
        "lvl"   :160,
        "skill_name" :"出没风波里",
        "damage_type":"抓伤"
]),
([      "action":"$N右手在$n$l划过，随后一招「捕风捉影」左手又向同一方位抓去。",
        "lvl"   :200,
        "skill_name" :"捕风捉影",
        "damage_type":"抓伤"
]),
});

int valid_enable(string usage) { return usage == "hand" || usage == "parry"; }
int valid_combine(string combo) {
	if(this_player()->query_skill("tianmo-jue", 1) >= 120
	&& this_player()->query_skill("xixing-dafa",1) >= 200
	&& this_player()->query_con(1) > 45
	&& this_player()->query_int(1) > 45)
		return combo=="huanmo-longtianwu";
}

int valid_learn(object me)
{
     if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
         return notify_fail("练天魔手法必须空手。\n");

   if(!me->query_skill("xixing-dafa", 1)||(int)me->query_skill("tianmo-gong",1)<100)
   if(me->query_skill("tianmo-gong", 1) < 100 )
           return notify_fail("你的特殊内功功力太浅，不能学天魔手法。\n");

     if ((int)me->query_skill("hand", 1) < 100)
         return notify_fail("你的基本手法火候不够。\n");

     if ((int)me->query("max_neili") < 350)
         return notify_fail("你的内力太低，无法学天魔手法。\n");

     if ((int)me->query_skill("hand", 1) < (int)me->query_skill("tianmo-shou", 1))
         return notify_fail("你的基本手法水平有限，无法领会更高深的天魔手法。\n");

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
	level   = (int) me->query_skill("tianmo-shou",1);
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
				"damage" : 100 + random(100),
			]);
		}
	}
}

int practice_skill(object me)
{
     if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
         return notify_fail("练天魔手法必须空手。\n");

     if ((int)me->query("jingli") < 100)
            return notify_fail("你的体力不够练天魔手法。\n");

     if ((int)me->query("neili") < 90)
            return notify_fail("你的内力不够练天魔手法。\n");

     me->receive_damage("jingli", 85);
     return 1;
}

string perform_action_file(string action)
{
     return __DIR__"tianmo-shou/" + action;
}

