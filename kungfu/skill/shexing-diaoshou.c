// shexing-diaoshou 蛇形刁手
//  by action@SJ 2008/12/30
#include <ansi.h>
inherit SKILL;
mapping *action = ({
([  "action" : "$N一式「"+RED+"灵蛇出洞"+NOR+"」，右手虚晃，左手扬起，突然拍向$n的背后二穴",
    "lvl" : 0,
    "skill_name" : RED "灵蛇出洞" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N侧身一晃，一式「"+YEL+"虎头蛇尾"+NOR+"」，左手拿向$n的肩头，右拳打向$n的胸口",
    "lvl" : 24,
    "skill_name" : YEL "虎头蛇尾" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N一式「"+HIG+"画蛇添足"+NOR+"」，右手环拢成爪，一出手就向扣$n的咽喉要害",
    "lvl" : 46,
    "skill_name" : HIG "画蛇添足" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N左手虚招，右掌直立，一式「"+HIY+"杯弓蛇影"+NOR+"」，错步飘出，疾拍$n的面门",
    "lvl" : 68,
    "skill_name" : HIY "杯弓蛇影" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N使一式「"+HIB+"蛇行鼠窜"+NOR+"」，左拳上格，右手探底突出，抓向$n的裆部",
    "skill_name" : BLK "蛇行鼠窜" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N一式「"+GRN+"蛇磐青竹"+NOR+"」，十指伸缩，虚虚实实地袭向$n的全身要穴",
    "lvl" : 100,
    "skill_name" : GRN "蛇磐青竹" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N双手抱拳，一式「"+YEL+"万蛇汹涌"+NOR+"」，掌影翻飞，同时向$n施出九九八十一招",
    "force" : 380,
    "lvl" : 120,
    "skill_name" : YEL "万蛇汹涌" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N一式「"+WHT+"白蛇吐信"+NOR+"」，拳招若隐若现，若有若无，急急地拍向$n的丹田",
    "lvl" : 140,
    "skill_name" : WHT "白蛇吐信" NOR,
        "damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage == "hand" || usage == "parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练蛇形刁手必须空手。\n");
	if ( me->query("max_neili") < 100)
		return notify_fail("你的内力太弱了，练不了蛇形刁手。\n");
	if ( me->query_skill("hamagong", 1) < 20)
		return notify_fail("你的蛤蟆功火候太浅，不能学蛇形刁手。\n");
	if ( me->query_skill("force", 1) < 20)
		return notify_fail("你的基本内功火候太浅，不能学蛇形刁手。\n");
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
	level   = (int) me->query_skill("shexing-diaoshou",1);
if(me->query_temp("sxds/ds"))
		return ([
				"action": action[j]["action"],
				"damage_type": "刺伤",
				"force": 600 +random(350),
				"dodge": random(30)-10,
				"parry": random(20)-10,
				"damage": 120 + random(140),
				"attack":150+random(150),
			]);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"weapon": action[j]["weapon"],
				"force":100+random(250),
				"dodge":random(20)-10,
				"parry":random(10),
			]);
		}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("shexing-diaoshou", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 30)
		return notify_fail("你的体力不够，练不了蛇形刁手。\n");
	if ( me->query("neili") < 10)
		return notify_fail("你的内力不够，练不了蛇形刁手。\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"shexing-diaoshou/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl = me->query_skill("hand"),attack;
        attack=lvl/100;
        if(attack>4) attack=4;
				attack=random(attack);
				if(attack<=1) attack=1;
        
        if (random(7)>4|| random(me->query_str()/2)> victim->query_str()/2) {
                message_vision(WHT "$N招招连环，步步紧逼，向$n颈后部卡去，$n瞬间被$N卡住喉颈，不能动弹！\n" NOR,me,victim);
                victim->start_busy(random(1));
        }
        else if (random(5)>3|| random(me->query_dex()/2)> victim->query_dex()/2) {
        	message_vision(MAG "$N揉身而上，自左向右轻轻回旋一周，$n被$N的身行所迷惑，顿时放弃攻击，改为自守。\n" NOR, me,victim);
        	victim->start_busy(random(2));
        }
        else if (random(4)>2|| random(me->query_con()/2)> victim->query_con()/2) {
        	message_vision(HIY "紧接着，$N口中发出“嘶嘶”的声音，双手半曲，三指上竖成蛇状，陪合着潇遥步法，有如急风暴雨般攻出了"+
			   chinese_number(attack+1)+"招。\n" NOR, victim);
        	victim->start_busy(random(2));
        }
}