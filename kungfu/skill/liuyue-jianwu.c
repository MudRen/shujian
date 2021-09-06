//liuyue-jianwu.c
// Write By Zhuifeng's System on 2010-7-20 17:22:49

#include <ansi.h>
inherit SKILL;

mapping *action = ({

([
     "action" : "$N向前斜跨一步，一招「剑气封喉」，手中$w直刺$n的喉部",
     "force"  : 100,
     "dodge"  : 10,
     "parry"  : 5,
     "lvl"    : 10,
     "damage"    : 20,
     "skill_name"  : "剑气封喉",
     "damage_type" : "刺伤"
]),
([
     "action" : "$N错步上前，一招「明月千里」，剑意若有若无，$w淡淡地向$n的$l挥去",
     "force"  : 125,
     "dodge"  : 20,
     "parry"  : 10,
     "lvl"    : 20,
     "damage"    : 50,
     "skill_name"  : "明月千里",
     "damage_type" : "刺伤"
]),
([
     "action" : "$N一式「怀中抱月」，纵身飘开数尺，运发剑气，手中$w遥摇指向$n的$l",
     "force"  : 150,
     "dodge"  : 15,
     "parry"  : 10,
     "lvl"    : 30,
     "damage"    : 60,
     "skill_name"  : "怀中抱月",
     "damage_type" : "瘀伤"
]),
([
     "action" : "$N纵身轻轻跃起，一式「大风起兮」，剑光如水，一泻千里，洒向$n全身",
     "force"  : 180,
     "dodge"  : 30,
     "parry"  : 25,
     "lvl"    : 40,
     "damage"    : 90,
     "skill_name"  : "大风起兮",
     "damage_type" : "刺伤"
]),
([
     "action" : "$N手中$w中宫直进，一式「定天一针」，无声无息地对准$n的$l刺出一剑",
     "force"  : 180,
     "dodge"  : 30,
     "parry"  : 25,
     "lvl"    : 40,
     "damage"    : 120,
     "skill_name"  : "定天一针",
     "damage_type" : "刺伤"
]),
([
     "action" : "$N手中$w一沉，一式「星归月向」，无声无息地滑向$n的$l",
     "force"  : 200,
     "dodge"  : 25,
     "parry"  : 25,
     "lvl"    : 50,
     "damage"    : 125,
     "skill_name"  : "星归月向",
     "damage_type" : "瘀伤"
]),
([
     "action" : "$N手中$w斜指苍天，剑芒吞吐，一式「映月无声」，对准$n的$l斜斜击出",
     "force"  : 245,
     "dodge"  : 10,
     "parry"  : 15,
     "lvl"    : 70,
     "damage"    : 130,
     "skill_name"  : "映月无声",
     "damage_type" : "瘀伤"
]),
([
     "action" : "$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，一式「情连航慈」刺向$n的咽喉",
     "force"  : 290,
     "dodge"  : 10,
     "parry"  : 15,
     "lvl"    : 80,
     "damage"    : 140,
     "skill_name"  : "情连航慈",
     "damage_type" : "瘀伤"
]),
([
     "action" : "$N合掌跌坐，一式「影玉徵辉」，$w自怀中跃出，如疾电般射向$n的胸口",
     "force"  : 331,
     "dodge"  : 20,
     "parry"  : 15,
     "lvl"    : 90,
     "damage"    : 145,
     "skill_name"  : "影玉徵辉",
     "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage == "parry" || usage == "sword"; }

int practice_skill(object me)
{
       if ((int)me->query("jingli") < 50)
           return notify_fail("你的体力太低了。\n");
       if ((int)me->query("neili") < 50)
           return notify_fail("你的内力不够练习该技能。\n");
       me->receive_damage("jingli", 10);
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
   level   = (int) me->query_skill("liuyue-jianwu",1);
   for(i = sizeof(action); i > 0; i--) {
       if(level > action[i-1]["lvl"]) {
           j = NewRandom(i, 20, level/4);
       if((int)me->query_skill("liuyue-jianwu",1) > 450 ){
       return ([
               "action" : HIW+replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIW)+NOR,
               "force" : 120,
               "dodge": 20,
               "parry" : 15,
               "damage" : 30,
               "damage_type" : "瘀伤",
                ]);
       }
       else return action[j];
       }
   }
}

string perform_action_file(string action)
{
   return __DIR__"liuyue-jianwu/" + action;
}

