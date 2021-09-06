// taishan-jianfa.c
// Modified by XiaoYao

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"skill_name" :"朗月无云",
	"action":  "$N手中$w一晃，向右滑出三步，一招"HIB"「朗月无云」"NOR"，转过身来，身子微矮，$w向$n斜斜刺去",
        "lvl" : 0
]),
([	"skill_name" :"峻岭横空",
	"action":  "$N手中$w圈转，一招"HIC"「峻岭横空」"NOR"去势奇疾，无数剑光刺向$n的$l",
	"lvl" : 15
]),
([	"skill_name" :"来鹤清泉",
	"action": "$N突然腰一弯，挺$w向$n刺去，这一剑力劲剑疾，正是一招"HIC"「来鹤清泉」"NOR"",
	"lvl" : 30
]),
([	"name":    "石关回马",
	"action":  "$N手中$w刷的一声，反手砍向$n，剑势圆润如意："HIY"「石关回马」"NOR"！",
	"lvl" : 45
]),
([	"skill_name" : "泰山十八盘",
	"action":  "$N展开剑势，身随剑走，左边一拐，右边一弯，越转越急。猛地$w剑光暴长，一招"HIM"「泰山十八盘」"NOR"往$n$l刺去",
	"lvl" : 60
]),
([	"skill_name" :"快活三里",
	"action": "$N手臂暴长，手中$w豁豁展开，刷刷两剑，指向$n，正是"GRN"「快活三里」"NOR"",
	"lvl" : 75
]),
([	"skill_name" :  "七星落长空",
	"action":  "$N一招"HIR"「七星落长空」"NOR"挺$w向$n当胸刺去，剑光闪烁，$w发出嗡嗡之声，罩住了$n胸口“膻中”、“神藏”、“灵墟”、“神封”、“步廊”、“幽门”、“通谷”七处大穴",
	"lvl" : 90
]),
([	"skill_name" :"五大夫剑",
	"action":  "$N手中$w倏地刺出，一连五剑，每一剑的剑招皆苍然有古意。招数古朴，内藏奇变，正是"HIW"「五大夫剑」"NOR"",
	"lvl" : 105
]),
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
	if ((int)me->query_skill("panshi-shengong", 1) < 50)
		return notify_fail("你的磐石神功火候太浅。\n");
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
		return notify_fail("你的体力不够练泰山剑法。\n");
	if((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练泰山剑法。\n");
		me->receive_damage("jingli", 40);
		me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taishan-jianfa/" + action;
}
