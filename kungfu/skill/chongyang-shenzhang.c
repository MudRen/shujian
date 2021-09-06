// chongyang-zhang.c -重阳神掌
// Modified by action@SJ 2008/09/15

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "skill_name": "阳关三叠",
        "action": "$N双掌一错，一招「阳关三叠」幻出层层掌影奔向$n的$l",   
        "lvl"   : 0,
        "damage_type":  "瘀伤"
]),
([      "skill_name": "地久天长",
        "action": "$N暴喝一声，单掌猛然推出，一招「地久天长」强劲的掌风直扑$n的$l",
        "lvl"   : 15,
        "damage_type":  "瘀伤"
]),
([      "skill_name": "金龙戏水",
        "action": "$N双掌纷飞，一招「金龙戏水」直取$n的$l",
        "lvl"   : 30,
        "damage_type": "瘀伤"
]),
([      "skill_name": "万物复苏",
        "action": "$N按北斗方位急走，一招「万物复苏」，阵阵掌风无孔不入般地击向$n的$l",
        "lvl"   : 50,
        "damage_type": "瘀伤"
]),
([      "skill_name": "回光反照",
        "action": "$N回身错步，双掌平推，凝神聚气，一招「回光反照」拍向$n的$l",
        "lvl"   : 70,
        "damage_type": "瘀伤"
]),
([      "skill_name": "神光乍现",
        "action": "$N左掌立于胸前，右掌推出，一招「神光乍现」迅然击向$n$l",
        "lvl"   : 90,
        "damage_type": "瘀伤"
]),
([      "skill_name": "百里千长",
        "action": "$N使出「百里千长」，身形急进，快速向$n出掌攻击",
        "lvl"   : 110,
        "damage_type": "瘀伤"
]),
([      "skill_name": "星游九天",
        "action": "$N一招「星游九天」，双掌虚虚实实的击向$n的$l",
        "lvl"   : 130,
        "damage_type": "瘀伤"
]),
([      "skill_name": "北斗易位",
        "action": "$N左掌画了个圈圈，右掌推出，一招「北斗易位」击向$n$l",
        "lvl"   : 150,
        "damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) 
{
	object me;
	me = this_player(); 

	if ( me->query_int(1) > 50)
		return combo=="zhongnan-zhi"; 
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练重阳神掌必须空手。\n");
	if ((int)me->query_skill("xiantian-gong", 1) < 60)
		return notify_fail("你的先天功火候不够，无法学重阳神掌。\n");
	if ((int)me->query_int(1) > 30) {
		return 1;
	}
	else {
		if ( me->query_skill("zhongnan-zhi", 1))
			return notify_fail("你的功力不够，无法同时学习两种以上的上乘功夫。\n");
	}
	if ((int)me->query("max_neili") < 600)
		return notify_fail("你的内力太弱，无法练重阳神掌。\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, j, level;
	string msg;
	
	level = (int) me->query_skill("chongyang-shenzhang",1);	
	for(i = sizeof(action); i > 0; i--) 	{
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			if(me->query_temp("qixing")) {
				switch(me->query_temp("qixing")) {
					case 2: msg = HIY"$N出招稳凝如山，反手一下终南指法使出大理国绝技「一阳指」，当即剑气如虹，势不可挡。"NOR; break;
					case 1: msg = HIB"$N眼见对方已陷入重围，再也不能全身而退，当下掌指齐出回击。"NOR; break;
					default: msg = HIW"$N掌指齐出，掌风，指风即刻笼罩$n，$n处处显示出破绽。"NOR;break;
				}
				me->add_temp("qixing", -1);      
				return ([
					"action": msg, 
					"force" : 200 + random(300),
					"dodge": random(35),
					"parry": random(35),
					"damage": 40 + random(50),
					"damage_type" : "抓伤",
				]);
			}
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 150 + random(300),
				"dodge": random(30),
				"parry": random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("chongyang-shenzhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练重阳神掌。\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"chongyang-shenzhang/" + action;
}
