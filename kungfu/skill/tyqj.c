// tianyu-qijian.c 天羽奇剑
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([  "action":"$N使一式「"+BLK+"海天一线"+NOR+"」，手中$w嗡嗡微振，幻成一条疾光刺向$n的$l",
    "lvl" : 0,
    "skill_name" : BLK "海天一线" NOR,
    "damage_type":  "割伤"
]),
([  "action":"$N错步上前，使出「"+RED+"闪电惊虹"+NOR+"」，手中$w划出一道剑光劈向$n的$l",
    "lvl" : 10,
    "skill_name" : RED "闪电惊虹" NOR,
    "damage_type":  "割伤"
]),
([  "action":"$N手中$w一抖，一招「"+GRN+"日在九天"+NOR+"」，斜斜一剑反腕撩出，攻向$n的$l",
    "lvl" : 15,
    "skill_name" : GRN "日在九天" NOR,
    "damage_type":  "割伤"
]),
([  "action":"$N手中剑锵啷啷长吟一声，一式「"+BLU+"咫尺天涯"+NOR+"」，一道剑光飞向$n的$l",
    "lvl" : 20,
    "skill_name" : BLU "咫尺天涯" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N一式「"+MAG+"怒剑狂花"+NOR+"」，手中$w舞出无数剑花，使$n难断虚实，无可躲避",
    "lvl" : 35,
    "skill_name" : MAG "怒剑狂花" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N手中$w斜指苍天，剑芒吞吐，一式「"+BLU+"九弧震日"+NOR+"」，对准$n的$l斜斜击出",
    "lvl" : 45,
    "skill_name" : BLU "九弧震日" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N一式「"+WHT+"漫天风雪"+NOR+"」，手腕急抖，挥洒出万点金光，刺向$n的$l",
    "lvl" : 50,
    "skill_name" : WHT "漫天风雪" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N一式「"+HIR+"天河倒泻"+NOR+"」，$w飞斩盘旋，如疾电般射向$n的胸口",
    "lvl" : 60,
    "skill_name" : HIR "天河倒泻" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N一式「"+HIY+"天外飞仙"+NOR+"」，$w突然从天而降，一片金光围掠$n全身",
    "lvl" : 65,
    "skill_name" : HIY "天外飞仙" NOR,
    "damage_type":  "刺伤"
])
});
mapping *action_shandian = ({
([	"action":HIY"$N前招将落，后招已至，前后两招形如一式，此起彼伏，连绵不绝"NOR,
	"lvl" : 15,
	"damage_type":	"割伤"
]),
([	"action":HIC"对方正惊愕间，却见$N的剑光已闪至眼前，剑光闪处寒气四射，咄咄逼人"NOR,
	"lvl" : 30,
	"damage_type":	"割伤"
]),
([	"action":HIR"只见$N人影一闪，身形已然欺近对方，手中剑光闪烁，嗡嗡做响"NOR,
	"lvl" : 45,
	"damage_type":	"割伤"
]),
([	"action":HIY"却见$N一剑未定二剑已至，随有前后之分却同时到达，速度之快晃如两剑同时发出"NOR,
	"lvl" : 60,
	"damage_type":	"刺伤"
]),
([	"action":HIG"不见$N手臂动作，只听一声龙吟之生，这第二剑已破空而至，刺至身前"NOR,
	"lvl" : 75,
	"damage_type":	"刺伤"
]),
([	"action":HIB"紧跟着，$N又是一剑刺至，剑招虽分前后，但剑锋几乎同时到达，速度之快难以言表"NOR,
	"lvl" : 90,
	"damage_type":	"刺伤"
]),
([	"action":HIR"一眨眼间$N的身形已欺至身前，若有若无，这第二剑已于电光火石间刺至身前"NOR,
	"lvl" : 105,
	"damage_type":	"刺伤"
])
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	 || (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if (me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ( ! me->query_skill("bahuang-gong", 1))
	if (me->query_skill("beiming-shengong", 1) < 20)
		return notify_fail("你的八荒六合唯我独尊火候太浅。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level,j;
	level   = (int) me->query_skill("tianyu-qijian",1);
	if( me->query_temp("tyqj/shandian")) {
		for(i = sizeof(action_shandian); i > 0; i--) { 
			if(level >= action_shandian[i-1]["lvl"]) {
				j = NewRandom(i, 20, level/5);
				return ([
					"action": action_shandian[j]["action"],
					"lvl": action_shandian[j]["lvl"],
					"damage_type": action_shandian[j]["damage_type"],
					"force": 150 + random(200),
					"dodge": random(30),
					"parry": random(30),
					"damage": 160+ random(200),
				]);
			}
		}
	}
		if( me->query_temp("tyqj/kuangwu")) {
	
				return ([
					"action": action_shandian[j]["action"],
					"lvl": action_shandian[j]["lvl"],
					"damage_type": action_shandian[j]["damage_type"],
					"force": 100 + random(200),
					"dodge": random(30),
					"parry": random(30),
					"damage": 100+ random(140),
				]);
			}
		if( me->query_temp("tyqj/piaomiao")) {
	
				return ([
					"action": action[j]["action"],
					"lvl": action[j]["lvl"],
					"damage_type": action[j]["damage_type"],
					"force": 100 + random(200),
					"dodge": random(30),
					"parry": random(30),
					"damage": 80+ random(100),
				]);
			}
return ([
				"action" : action[j]["action"],
				"force" : 100 + random(350),
				"dodge" : random(25)-5,
				"parry": 20-random(10),
				"damage" : 100 + random(100),
				"damage_type" : action[j]["damage_type"],
				"lvl": action[j]["lvl"],
			]);
}

int practice_skill(object me)
{
	int lvl = me->query_skill("tianyu-qijian", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 50)
		return notify_fail("你的体力不够练天羽奇剑。\n");
	if((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练天羽奇剑。\n");
		me->receive_damage("jingli", 40);
		me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tianyu-qijian/" + action;
}

