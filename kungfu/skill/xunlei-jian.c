//xunlei-jian.c by jpei

inherit SKILL;
#include <ansi.h>
#include <combat.h>


string *msg = ({
"$N忽然团身一缩，手中$w乍然一现，一式「泽上有雷」，漫天劲气如水银泄地般点向$n",
"$N飞步上前，一招「天雷不交」，$w颤动不停，剑尖离$n要害不到半寸，随后剑气迸发",
"$N斜出一剑，一招「雷风恒」，精妙难言，於凌厉剑势之中，暗伏无穷无尽的後著变化",
"$N$w斜走，向上虚点，跟著使一招「雷水解」，$w如电光只闪了一闪，便已刺到了$n的$l",
"$N身形微侧，已从$n身旁绕过，在这一瞬之间，向$p的$l斩了一剑，手法奇快，正是一招「天雷闪」",
"$N当下一招「雷泽归妹」身随剑走，如电光般游到了$n身後，脚步未定，剑招先到，$w抖动，往$p$l刺去",
"但见寒芒吞吐，$N一招「雷天大壮」，剑招大开大合，气象威严，凌厉之极，青霜到处，所向披靡",
"$N一招「天雷无妄」，手中$w疾如骇电奔雷，逼出一道丈许的剑光，凌空斩下",
"$N一招「雷风相与」，$w如银蛇狂舞，剑招神光离合，虚实变幻，刚柔并济",
"$N身形一晃，抢上数丈，一招「泽雷随」， 剑随身动，$w已刺向$n的$l，快如流星闪电",
"但见$N身形穿插来去，一招「雷电合章」，剑光纵横反复，如雷声隆隆，绵绵不绝",
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 30)
		return notify_fail("你的玄天无极功火候太浅。\n");

	if ( me->query("family/master_name") != "何足道" )
		return notify_fail("你只有在拜了何足道后才能学习迅雷剑法。\n");

	if ((int)me->query_skill("sword", 1) < 20)
		return notify_fail("你的基本剑法火候太浅。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, j, level, damage;

	level = me->query_skill("xunlei-jian", 1);
	i = random(me->query_skill("sword"))+50;
	if( i<100 ) i = 100;
	j = random(40)-5;
	damage = (random(2)+4)*35;
	if( damage < 50 ) damage =50;

		if( level > 350 ) {
			return ([
                           "action": HIB+replace_string(replace_string(msg[random(sizeof(msg))], "$w", "$w"), "$w", "$w"HIB)+NOR,
                                          "damage": 160 + random(150),
		              "damage_type": "刺伤",
			"dodge":  random(20),
			"parry":  random(20),
			"force":  300 + random(250),

			]);
		}

		else return ([
			"action": msg[random(sizeof(msg))],
                                          "damage": 120 + random(80),
			"damage_type": "刺伤",
			"dodge":  random(30),
			"force":  250 + random(300),
		]);
	}
int practice_skill(object me)
{
	if ( me->query_skill("xunlei-jian", 1 ) < 120)
		return notify_fail("迅雷十九剑只能通过跟师傅学习来提高。\n");

	if ( me->query("jingli") < 50)
		return notify_fail("你的体力不够练迅雷剑。\n");
	if ( me->query("neili") < 20)
		return notify_fail("你的内力不够练习迅雷剑。\n");
	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"xunlei-jian/" + action;
}



