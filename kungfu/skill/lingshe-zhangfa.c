//lingshe_zhangfa.c 灵蛇杖法
//updated by redhat@sjmud 2009/5/9

#include "ansi.h"

inherit SKILL;
mapping *action = ({
([  "action": HIB"$N使出一招「灵蛇出洞」，手中$w"HIB"大开大阖扫向$n的$l"NOR,
    "lvl" : 0,
    "skill_name" : RED "灵蛇出洞" NOR,
    "damage_type": "挫伤"
]),
([  "action": HIY"$N手中$w"HIY"阵阵风响，一招「摇头摆尾」向$n的$l攻去"NOR,
    "lvl" : 20,
    "skill_name" : MAG "摇头摆尾" NOR,
    "damage_type": "挫伤"
]),
([  "action": HIG"$N举起$w"HIG"，居高临下使一招「灵蛇下涧」砸向$n的$l"NOR,
    "lvl" : 30,
    "skill_name" : HIW "灵蛇下涧" NOR,
    "damage_type": "挫伤"
]),
([  "action": HIM"$N一招「灵蛇挺身」，手中$w"HIM"猛烈扫向$n的$l"NOR,
    "lvl" : 40,
    "skill_name" : YEL "灵蛇挺身" NOR,
    "damage_type": "挫伤"
]),
([  "action": HIR"$N使出一招「蛇游蟒走」，$w"HIR"左右迂回向$n的$l扫去"NOR,
    "lvl" : 50,
    "skill_name" : YEL "蛇游蟒走" NOR,
    "damage_type": "挫伤"
]),
([  "action": HIY"$N手中$w"HIY"一挥，使出一招「蛇缠左右」，忽左忽右扫向$n的$l"NOR,
    "lvl" : 60,
    "skill_name" : BLU "蛇缠左右" NOR,
    "damage_type": "挫伤"
]),
([  "action": HIM"$N使出一招「巨蟒下山」，高举手中$w"HIM"，劈头砸向$n的$l"NOR,
    "lvl" : 80,
    "skill_name" : RED "巨蟒下山" NOR,
    "damage_type": "挫伤"
]),
([  "action": HIB"$N使出一招「灵蛇出洞」，手中$w"HIB"猛一探，直扫$n的$l"NOR,
    "lvl" : 100,
    "skill_name" : RED "灵蛇出洞" NOR,
    "damage_type": "挫伤"
]),
});

int valid_enable(string usage) { return usage=="staff" || usage=="parry"; }

string query_skill_name(int level)
{
	int i = sizeof(action);
	while (i--)
		if(level > action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, j, level;

	level = (int) me->query_skill("lingshe-zhangfa",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action" : action[j]["action"],
				"force" : 200 + random(350),
				"dodge" : random(25)-5,
				"parry": 20-random(10),
				"damage" : 200 + random(150),
				"damage_type" : action[j]["damage_type"],
				"lvl": action[j]["lvl"],
			]);
		}
	}

		   if( me->query_temp("lszf/saoluoye") > 1 )
			me->add_temp("lszf/luoye", -1);
		return ([
			"action" : action[j]["action"],
			"damage": 220 + random(100),
			"damage_type": "刺伤",
			"dodge": random(30)-20,
			"parry": random(30),
			"force": 350 + random(250),
		]);
		if( me->query_temp("lszf/wanshe"))
		return ([
			"action" : action[j]["action"],
			"damage": 350 + random(250),
			"damage_type": "刺伤",
			"dodge": random(30)-20,
			"parry": random(30),
			"force": 450 + random(250),
		]);
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 60)
		return notify_fail("你的体力不够了。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的体力不够了。\n");
	me->receive_damage("jingli", 50);
	me->add("neili", -20);
	return 1;
}

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("你的内力不足，没有办法练灵蛇杖法, 多练些内力再来吧。\n");

	if (!me->query_skill("hamagong", 1) || me->query_skill("hamagong", 1) < 50)
		return notify_fail("你的蛤蟆功火候太浅。\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "staff" )
		return notify_fail("你必须使用杖来练杖法。\n");
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon; 
        int i;
        weapon = me->query_temp("weapon");
        i = me->query_skill("lingshe-zhangfa", 1);

        if( !userp(me) && random(2) ) return 0;

        if( !weapon || weapon->query("skill_type") != "staff" ) return 0;
        if( i < 350 ) return 0;
        if( me->query_temp("lszf/wanshe")) return 0;
        if( !me->query_temp("hmg_nizhuan")) return 0;
        if( !living(victim) ) return 0;

        if( i >= 350 && random(3)
         && random(me->query_con()) > victim->query_con()/3
         && random(me->query_skill("staff")) > victim->query_skill("parry")/3 
         && !me->query_temp("lingshe")) {
                if( me->query_skill_prepared("cuff") == "lingshe-zhangfa"
                 && me->query_skill_mapped("cuff") == "lingshe-zhangfa"
                 && me->query_skill("lingshe-quanfa", 1) >= 200 && random(3) ) {
                 	message_vision(HIB"只见$N手中"+weapon->name()+HIB"上人头雕得更是诡奇可怖，只是两条怪蛇虽然毒性无异，突然喷射两行毒液，向$n激射而去！\n"NOR, me);
                        
                        me->add_temp("apply/attack",  me->query_skill("lingshe-quanfa", 1)/2);
                        me->set_temp("lingshe");
                        COMBAT_D->do_attack(me, victim, 0, 3);
                        victim->add_condition("snake_poison", 10);
                        me->delete_temp("lingshe");
                        me->add_temp("apply/attack", -me->query_skill("lingshe-quanfa", 1)/2);
                } else {
                  message_vision(HIM"$N全身经脉逆转，凭着武学渊深，内功浑厚，竟尔已有小成，当下"+weapon->name()+HIM"挥动，忽变怪招，招式极为凌厉！"NOR, me);     
                        me->set_temp("lingshe", 1);
                        me->add_temp("apply/attack",  me->query_skill("lingshe-zhangfa", 1));
                        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),  3);
                        me->add_temp("apply/attack", -me->query_skill("lingshe-zhangfa", 1));
                        me->delete_temp("lingshe");
                }
        }
        else if( i >= 400 && random(2)
         && random(me->query("combat_exp")) > victim->query("combat_exp")/3
         && random(me->query_skill("staff")) > victim->query_skill("parry")/3
         && random(me->query_con()) > victim->query_str()/3
         && !victim->query_temp("lost_attack")
         && !me->query_temp("wugou") ) {
                message_vision(HIY"$N右手握"+weapon->name()+HIY"直挺，凝聚功力于"+weapon->name()+HIY"上，身行随风飘摆，而杖尖任他狂风暴雨也不移动，\n"+
					                     HIY"单单直指$n心口，正是打狗棒第三十六路棒法「"HIG"天下无狗"NOR"」"HIY"的第六变的棒心所在！\n"NOR, me, victim);
					                     me->set_temp("wugou");
                victim->add_temp("lost_attack", 1+random(3));
                return random(me->query_skill("staff"))/3;
                me->delete_temp("wugou");
        }
        return 0;
}

string perform_action_file(string action)
{
	return __DIR__"lingshe-zhangfa/" + action;
}
