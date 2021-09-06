// ruyi-dao.c 如意刀法
// modified by xjqx@SJ 2009/1/3
//modified by zhuifeng@SJFY 2010/07/20

inherit SKILL;
#include <combat.h>
#include <ansi.h>
mapping *action = ({
([ "action" : "$N一磕刀柄，一招「若往若返」，猛地一个转身，手中$w直向$n的胸口突然斩去",
   "lvl" : 0,
	"skill_name" : "若往若返",
	"parry":0,
	"damage_type" : "刺伤"
]),
([      "action" : "$N把手中的$w一扬，一招「峰回路转」，手中的刀一个急转，直砍向$n的$l",
        "lvl" : 10,
	"skill_name" : "峰回路转",
	"parry":10,
	"damage_type" : "刺伤" 
]),
([      "action" : "$N身形陡然滑出数尺，一招「御风而行」，刀势如风，手中$w斩向$n的$l",
        "lvl" : 30,
	"skill_name" : "御风而行",
	"parry":10,
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「云雾萦绕」，身子骤然拔高数尺，手中$w一个平推向$n的$l砍去",
       "lvl" : 50,
	"skill_name" : "云雾萦绕",
	"parry":0,
	"damage_type" : "刺伤"
]),
([      "action" : "$N纵身突然一跃，手中$w一招「金光泻地」轻飘飘地向$n的$l要害掠去",
       "lvl" : 80,
	"skill_name" : "金光泻地",
	"parry":30,
	"damage_type" : "刺伤"
]),
([      "action" : "$N手中$w向外一分，轻轻颤动， 一招「柳暗花明」反手向$n$l掠去",
       "lvl" : 110,
	"skill_name" : "柳暗花明",
	"parry":20,
	"damage_type" : "刺伤"
]),
([      "action" : "$N横刀上前，身形一转，手中$w使一招「空谷秋虹」画出一道光弧斩向$n的$l",
       "lvl" : 140,
	"skill_name" : "空谷秋虹",
	"parry":30,
	"damage_type" : "刺伤"
]),
([      "action" : "$n只觉眼前一花，$N一招「紫气东来」，$w挟呼呼风声迅猛砍向$n的$l",
        "lvl" : 180,
	"skill_name" : "紫气东来",
	"parry":40,
	"damage_type" : "刺伤"
]),
([      "action" : "$N把$w划了一圈，一招「神光离合」，$n只觉得全身被笼罩在一团刀气之中",
       "lvl" : 240,
	"skill_name" : "神光离合",
	"parry":40,
	"damage_type" : "刺伤"
]),
([      "action" : "$N身形一转，一招「逍遥自在」， $w刀光不定， 招招砍向$n的$l要害",
"lvl" : 300,
	"skill_name" : "逍遥自在",
	"parry":40,
	"damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ( me->query("max_neili", 1) < 100)
		return notify_fail("你的内力不够。\n"); 
		
		

	if (!me->query_skill("bahuang-gong", 1) )
    if ( me->query_skill("beiming-shengong", 1) < 30 )
		return notify_fail("你的北冥神功火候太浅。\n");
        if ( me->query_skill("blade", 1) < 30 )
		return notify_fail("你的基本刀法还不够娴熟，无法学习如意刀法。\n");
	if ( me->query_skill("liuyang-zhang", 1) < 30)
		return notify_fail("你的天山六阳掌太弱，无法学习到如意刀法的精髓。\n");
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

	level = (int) me->query_skill("ruyi-dao",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
					
			if ( me->query_temp("ryd/ruyi")){
				return ([
					"action":WHT+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"WHT), NOR, WHT)+NOR,
          "damage": 220+random(150),
					"damage_type": "割伤",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}
			if ( me->query_temp("ryd/xiaoyao")||me->query_temp("xiaoyao_jianwu")){
				return ([
					"action":HIR+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIR), NOR, HIR)+NOR,
          "damage": 230+random(190),
					"damage_type": "割伤",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}
			
			return ([
				"action" : action[j]["action"],
				"force" : 200 + random(350),
				"dodge" : random(25)+25,
				"parry": 20-random(10),
        "damage" : 120 + random(120),
				"damage_type" : action[j]["damage_type"],
				"lvl": action[j]["lvl"],
			]);
		}
	}
}

int practice_skill(object me)
{
	if ( me->query("jingli") < 50)
		return notify_fail("你的体力不够练如意刀法。\n");         
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够练如意刀法。\n");
	me->receive_damage("jingli", 40);
	me->receive_damage("neili", 15);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"ruyi-dao/" + action;
}




mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon, weapon1;
        int i;
        weapon = me->query_temp("weapon");
        weapon1= victim->query_temp("weapon");

        if( !objectp(weapon) ) return;

        i = me->query_skill("ruyi-dao", 1);



   if(i>=350){
       if(random(i)>(int)victim->query_skill("dodge",1)/2
        &&!victim->query_condition("no_fight")){
            message_vision(HIR"$N刀气纵横，迅疾逾电，$n连连招架,竟是毫无还手之力！\n"NOR,me,victim);
            victim->set_temp("no_fight",1);
            victim->apply_condition("no_fight",1);
       }
   }

        if( weapon1 && i > 200 && living(victim)
         && me->query_skill_mapped("force") == "beiming-shengong"
         && random(me->query("combat_exp")) > victim->query("combat_exp")/2 ) {
                message_vision(HIM"北冥神功何等神奇，$N更将真气运到"+weapon->name()+HIM"上，刀气锐利无匹，摧枯拉朽，无可匹敌！\n"NOR, 

me,victim);
                if( random(me->query("str")) > victim->query("dex")/3 ) {
                        me->add("neili", -50);
                   victim->add_busy(1+random(2));
                        message_vision(HIR"$N只觉一股大力袭来，臂膀剧痛，手中"+weapon1->name()+HIR"再也拿捏不住，脱手而出！\n"NOR, victim);
                        weapon1->unequip();
                        weapon1->move(environment(victim));
                }
        }
     
}

