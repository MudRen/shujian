//tianyu-qijian.c
// Write By Zhuifeng's System on 2010-7-20 17:39:23
// 我也来凑个热闹。修改下飞跃描述 jpei 2010-7-30



#include <ansi.h>
inherit SKILL;
#include <combat.h>
#include <combat_msg.h>


string *feiyue_msg = ({
""HIC"$N使一式「"+HIC+"海天一线"+HIC+"」，手中$w"+HIC+"嗡嗡微振，幻成一条疾光刺向$n的$l。"NOR"",
""HIC"$N错步上前，使出「"+RED+"闪电惊虹"+HIC+"」，手中$w"+HIC+"划出一道剑光劈向$n的$l"NOR"",
""HIC"$N手中$w"+HIC+"一抖，一招「"+GRN+"日在九天"+HIC+"」，斜斜一剑反腕撩出，攻向$n的$l"NOR"",
""HIC"$N手中剑锵啷啷长吟一声，一式「"+BLU+"咫尺天涯"+HIC+"」，一道剑光飞向$n的$l"NOR"",
""HIC"$N一式「"+MAG+"怒剑狂花"+HIC+"」，手中$w"+HIC+"舞出无数剑花，使$n难断虚实，无可躲避"NOR"",
""HIC"$N手中$w"+HIC+"斜指苍天，剑芒吞吐，一式「"+BLU+"九弧震日"+NOR+"」，对准$n的$l斜斜击出"NOR"",
""HIC"$N一式「"+WHT+"漫天风雪"+HIC+"」，手腕急抖，挥洒出万点金光，刺向$n的$l"NOR"",
""HIC"$N一式「"+HIR+"天河倒泻"+HIC+"」，$w"+HIC+"飞斩盘旋，如疾电般射向$n的胸口"NOR"",
""HIC"$N一式「"+HIY+"天外飞仙"+HIC+"」，$w"+HIC+"突然从天而降，一片金光围掠$n全身"NOR"",
});





mapping *action = ({

([
     "action" : "$N使一式「"+HIC+"海天一线"+NOR+"」，手中$w嗡嗡微振，幻成一条疾光刺向$n的$l",
     "force": 200 + random(220),
     "dodge"  : 40,
     "parry"  : 30,
     "lvl"    : 1,
     "damage"    : 80 + random(140),
     "skill_name"  : "海天一线",
     "damage_type" : "割伤"
]),
([
     "action" : "$N错步上前，使出「"+RED+"闪电惊虹"+NOR+"」，手中$w划出一道剑光劈向$n的$l",
     "force": 200 + random(220),
     "dodge"  : 40,
     "parry"  : 30,
     "lvl"    : 20,
     "damage"    : 80 + random(140),
     "skill_name"  : "闪电惊虹",
     "damage_type" : "割伤"
]),
([
     "action" : "$N手中$w一抖，一招「"+GRN+"日在九天"+NOR+"」，斜斜一剑反腕撩出，攻向$n的$l",
     "force": 200 + random(220),
     "dodge"  : 40,
     "parry"  : 20,
     "lvl"    : 30,
     "damage"    : 80 + random(140),
     "skill_name"  : "日在九天",
     "damage_type" : "割伤"
]),
([
     "action" : "$N手中剑锵啷啷长吟一声，一式「"+BLU+"咫尺天涯"+NOR+"」，一道剑光飞向$n的$l",
     "force": 200 + random(220),
     "dodge"  : 40,
     "parry"  : 20,
     "lvl"    : 40,
     "damage"    : 80 + random(140),
     "skill_name"  : "咫尺天涯",
     "damage_type" : "刺伤"
]),
([
     "action" : "$N一式「"+MAG+"怒剑狂花"+NOR+"」，手中$w舞出无数剑花，使$n难断虚实，无可躲避",
     "force": 200 + random(220),
     "dodge"  : 40,
     "parry"  : 30,
     "lvl"    : 60,
     "damage"    : 120 +random(140),
     "skill_name"  : "怒剑狂花",
     "damage_type" : "刺伤"
]),
([
     "action" : "$N手中$w斜指苍天，剑芒吞吐，一式「"+BLU+"九弧震日"+NOR+"」，对准$n的$l斜斜击出",
     "force": 200 + random(220),
     "dodge"  : 40,
     "parry"  : 30,
     "lvl"    : 70,
     "damage"    : 125 +random(140),
     "skill_name"  : "九弧震日",
     "damage_type" : "割伤"
]),
([
     "action" : "$N一式「"+WHT+"漫天风雪"+NOR+"」，手腕急抖，挥洒出万点金光，刺向$n的$l",
     "force": 200 + random(220),
     "dodge"  : 40,
     "parry"  : 30,
     "lvl"    : 80,
     "damage"    : 150+random(140),
     "skill_name"  : "漫天风雪",
     "damage_type" : "擦伤"
]),
([
     "action" : "$N一式「"+HIR+"天河倒泻"+NOR+"」，$w飞斩盘旋，如疾电般射向$n的胸口",
     "force": 200 + random(220),
     "dodge"  : 40,
     "parry"  : 30,
     "lvl"    : 90,
     "damage"    : 130+random(140),
     "skill_name"  : "天河倒泻",
     "damage_type" : "割伤"
]),
([
     "action" : "$N一式「"+HIY+"天外飞仙"+NOR+"」，$w突然从天而降，一片金光围掠$n全身",
     "force": 200 + random(220),
     "dodge"  : 40,
     "parry"  : 30,
     "lvl"    : 100,
     "damage"    : 125+random(140),
     "skill_name"  : "天外飞仙",
     "damage_type" : "割伤"
]),
});

int valid_enable(string usage) { return usage == "parry" || usage == "sword"; }

int valid_learn(object me)
{
	object weapon;
	
	if (!objectp(weapon = me->query_temp("weapon"))
	 || (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if (me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ( ! me->query_skill("bahuang-gong", 1))
	if (me->query_skill("beiming-shengong", 1) < 50)
		return notify_fail("你的八荒六合唯我独尊火候太浅。\n");
	return 1;
}

int practice_skill(object me)
{
       if ((int)me->query("jingli") < 40)
           return notify_fail("你的体力太低了。\n");
       if ((int)me->query("neili") < 50)
           return notify_fail("你的内力不够练习该技能。\n");
       me->receive_damage("jingli", 20);
       me->add("neili", -0);
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
   level   = (int) me->query_skill("tianyu-qijian",1);
   for(i = sizeof(action); i > 0; i--) {
       if(level > action[i-1]["lvl"]) {
           j = NewRandom(i, 20, level/4);
       if((int)me->query_skill("tianyu-qijian",1) >  450){
       return ([
               "action": HIC+feiyue_msg[random(sizeof(feiyue_msg))],
               "force" : 300 + random(300),
               "dodge": 50,
               "parry" : 30,
               "damage" : 220+random(150),
               "damage_type" : "割伤",
                ]);
       }
       else return action[j];
       }
   }
}

string perform_action_file(string action)
{
   return __DIR__"tianyu-qijian/" + action;
}







mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon, weapon1;
        int i;
        weapon = me->query_temp("weapon");
        weapon1= victim->query_temp("weapon");

        if( !objectp(weapon) ) return;

        i = me->query_skill("tianyu-qijian", 1);



   if(i>=350){
       if(random(i)>(int)victim->query_skill("dodge",1)/2
        &&!victim->query_condition("no_fight")){
            message_vision(HIR"$N飘身而进，左手捏个剑诀，剑光如电，直指$N的破绽所在，$n只得连连招架,竟是毫无还手之力！\n"NOR,me,victim);
            victim->set_temp("no_fight",1);
            victim->apply_condition("no_fight",1);
            victim->add_busy(1);
       }
   }

        if( weapon1 && i > 200 && living(victim)
         && me->query_skill_mapped("force") == "bahuang-gong"
         && random(me->query("combat_exp")) > victim->query("combat_exp")/2 ) {
                message_vision(HIM"$N随意一剑，去势却是绝快，剑光迅疾逾电，一闪而收。将天羽奇剑的轻灵奇幻之精要，发挥的淋漓尽致！\n"NOR, 

me,victim);
                if( random(me->query("str")) > victim->query("dex")/3 ) {
                        me->add("neili", -50);
                   victim->add_busy(1+random(2));
                        message_vision(HIR"$N只觉得手腕剧痛，手中"+weapon1->name()+HIR"再也拿捏不住，脱手而出！\n"NOR, victim);
                        weapon1->unequip();
                        weapon1->move(environment(victim));
                }
        }
     
}

