//baibu-chuanyang.c
// Write By Zhuifeng's System on 2010-8-8 13:45:51

#include <ansi.h>
inherit SKILL;

mapping *action = ({

([
     "action" : "$N气定神闲，大力开阔，将多只箭搭在$w上，使出「连珠箭」向全身急射而出",
     "force"  : 5,
     "dodge"  : 5,
     "parry"  : 20,
     "lvl"    : 10,
     "damage"    : 120,
     "skill_name"  : "连珠箭",
     "damage_type" : "刺伤"
]),
([
     "action" : "$N屏住内息，疯狂的弯弓搭箭，使出「流星箭」不断连续射向$n，顿时$n陷入慌乱",
     "force"  : 50,
     "dodge"  : 15,
     "parry"  : 5,
     "lvl"    : 20,
     "damage"    : 100,
     "skill_name"  : "流星箭",
     "damage_type" : "刺伤"
]),
([
     "action" : "$N将全身之力灌注于弓弦之上，奋力使出「满弦射」，一支箭犹如飞鹰急速飞向$n",
     "force"  : 20,
     "dodge"  : 5,
     "parry"  : 10,
     "lvl"    : 30,
     "damage"    : 130,
     "skill_name"  : "满弦射",
     "damage_type" : "刺伤"
]),
([
     "action" : "$N弯弓搭箭，使出当年吕布将军辕门射戟「辕门射」，箭犹如脱缰的野马飞射向$n心脏",
     "force"  : 20,
     "dodge"  : 20,
     "parry"  : 20,
     "lvl"    : 40,
     "damage"    : 90,
     "skill_name"  : "辕门射",
     "damage_type" : "刺伤"
]),
([
     "action" : "$N弯弓搭箭，将内力灌注于$w之中，使出「鸣镝箭」，箭矢突然射出，中途发出一连串的镝声，飞向$n",
     "force"  : 20,
     "dodge"  : 20,
     "parry"  : 20,
     "lvl"    : 50,
     "damage"    : 90,
     "skill_name"  : "鸣镝箭",
     "damage_type" : "刺伤"
]),
([
     "action" : "$N弯弓搭箭，使出黄汉升长沙战云长绝技「落缨射」，箭矢飞跃长空，急速飞向$n的面门",
     "force"  : 50,
     "dodge"  : 20,
     "parry"  : 20,
     "lvl"    : 60,
     "damage"    : 120,
     "skill_name"  : "落缨射",
     "damage_type" : "刺伤"
]),
([
     "action" : "$N弯弓搭箭，使出「五步射」绝技，边走边射，五步之内就向$n连发数箭，箭箭射向$n要害之处",
     "force"  : 50,
     "dodge"  : 20,
     "parry"  : 20,
     "lvl"    : 70,
     "damage"    : 110,
     "skill_name"  : "五步射",
     "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage == "arrow" ||  usage=="parry"; ; }

int practice_skill(object me)
{

       if ((int)me->query_skill("arrow") < 30)
           return notify_fail("你的几本弓术太低了，无法练习百步穿杨。\n");

       if ((int)me->query("jingli") < 50)
           return notify_fail("你的体力太低了。\n");
       if ((int)me->query("neili") < 50)
           return notify_fail("你的内力不够，无法练习百步穿杨。\。\n");
       me->receive_damage("jingli", 10);
       me->add("neili", -10);
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
   level   = (int) me->query_skill("baibu-chuanyang",1);
   for(i = sizeof(action); i > 0; i--) {
       if(level > action[i-1]["lvl"]) {
           j = NewRandom(i, 20, level/4);
       if((int)me->query_skill("baibu-chuanyang",1) > 350 ){
       return ([
               "action" : HIC+replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIC)+NOR,
               "force" : 500,
               "dodge": 30,
               "parry" : 50,
               "damage" : 140,
               "damage_type" : "刺伤",
                ]);
       }
       else return action[j];
       }
   }
}

string perform_action_file(string action)
{
   return __DIR__"baibu-chuanyang/" + action;
}

