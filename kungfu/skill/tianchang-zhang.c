//    /kungfu/skill/tianchang-zhang.c 天长掌法
// by action@SJ 2008/12/30

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N使一招"GRN"「青山隐隐」"NOR"，双手划了个半圈，按向$n的$l",
	  "skill_name" : "青山隐隐",
  	"lvl" : 5,
		"damage_type" : "瘀伤"
]),
([	"action" : "$N使一招"MAG"「云霞出海」"NOR"，左手轻轻一挥，劈向$n的$l",
  	"skill_name" : "云霞出海",
  	"lvl" : 15,
		"damage_type" : "瘀伤"
]),
([	"action" : "$N右手掌心向外，由右向左，使一招"CYN"「星河鹭起」"NOR"，向$n的$l打去",
  	"skill_name" : "星河鹭起",
  	"lvl" : 10,
		"damage_type" : "瘀伤"
]),
([	"action" : "$N使一招"HIM"「彩舟云淡」"NOR"，分击$n的胸口和$l",
  	"skill_name" : "彩舟云淡",
	  "lvl" : 20,
		"damage_type" : "瘀伤"
]),
([	"action" : "$N使一招"HIB"「月照幽林」"NOR"，左右掌同时击出，在空中突然左右掌方向互变",
	  "skill_name" : "月照幽林",
  	"lvl" : 30,
		"damage_type" : "瘀伤"
]),
([	"action" : "$N左手不住晃动，右掌一招"HIW"「白日参辰」"NOR"，向$n的$l打去",
	  "skill_name" : "白日参辰",
  	"lvl" : 50,
		"damage_type" : "瘀伤"
]),
([	"action" : "$N左手变掌为啄，右掌立掌如刀，一招"HIY"「鹤舞白沙」"NOR"，劈向$n的$l",
	  "skill_name" : "鹤舞白沙",
	  "lvl" : 70,
		"damage_type" : "瘀伤"
]),
([	"action" : "$N左脚退后半步，右掌使一招"HIC"「水天一色」"NOR"，横挥向$n",
	  "skill_name" : "水天一色",
  	"lvl" : 80,
		"damage_type" : "瘀伤"
]),
([	"action" : "$N一招"CYN"「月华流照」"NOR"，左掌先发而后至，右掌后发而先至",
	  "skill_name" : "月华流照",
	  "lvl" : 90,
		"damage_type" : "瘀伤"
]),
([	"action" : "$N双掌缩入袖中，双袖飞起扫向$n的$l，却是一招"HIR"「嫦娥奔月」"NOR"，仪态潇洒",
	  "skill_name" : "嫦娥奔月",
  	"lvl" : 100,
		"damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练天长掌法法必须空手。\n");
	if ( me->query_skill("baiyun-xinfa", 1) < 15)
		return notify_fail("你的白云心法火候不够，无法学斗转天长掌法。\n");
	if ( me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练斗转天长掌法。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int)me->query_skill("tianchang-zhang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	int lvl = me->query_skill("tianchang-zhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 40)
		return notify_fail("你的体力太低了。\n");
	if ( me->query("neili") < 20)
		return notify_fail("你的内力不够练天长掌法。\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tianchang-zhang/" + action;
}
