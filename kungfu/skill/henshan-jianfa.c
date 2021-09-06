// hengshan-jianfa.c
//  by hongba
#include <ansi.h>

inherit SKILL;



int tydamage = (this_player()->query("tydamage/unarmed")?this_player()->query("tydamage/unarmed"):this_player()->query_skill("hengshan-sword"))*5;

mapping *action = ({
([
        "action":  "$N右手$w慢慢指出，突然间在空中一颤，发出嗡嗡之声，跟着便是
嗡嗡两剑，手中$w剑光暴长，向$n的$l刺去",
        "dodge":    50,
        "damage":  tydamage,
        "damage_type":  "刺伤"
]),
([
        "action":  "$N手中$w如鬼如魅，竟然已绕到了$n背后，$n急忙转身，耳边只听
得嗡嗡两声",
        "dodge":   -70,
        "damage":  tydamage,
        "damage_type":  "刺伤"
]),
([      "name":    "百变千幻",
        "action":  "$N手中$w寒光陡闪，手中的$w，猛地反刺，直指$n胸口。这一下
出招快极，抑且如梦如幻，正是「"+HIW+"百变千幻衡山云雾十三式」"+NOR+"中的绝招",
        "dodge":   -40,
        "damage":   tydamage,
        "damage_type":  "刺伤"
]),
([      "name":    "泉鸣芙蓉",
        "action":  "$N不理会对方攻势来路，手中$w刷的一剑「"+HIC+"泉鸣芙蓉"+NOR+"」，向$n小
腹刺去",
        "dodge":   -40,
        "damage":  tydamage,
        "damage_type":  "刺伤"
]),
([      "name":    "鹤翔紫盖",
        "action":  "$N不理会对方攻势来路，手中$w刷的一剑「"+HIM+"鹤翔紫盖"+NOR+"」，向$n额
头刺去",
        "dodge":   -40,
        "damage":  tydamage,
        "damage_type":  "刺伤"
]),
([      "name":    "石廪书声",
        "action":  "$N手中$w倏地刺出，剑势穿插迂回，如梦如幻，正是一招「"+HIW+"石廪书声"+NOR+"」，
向$n$l刺去",
        "dodge":   60,
        "damage":  tydamage,
        "damage_type":  "刺伤"
]),
([      "name":    "天柱云气",
        "action":  "$N手中$w倏地刺出，极尽诡奇之能事，动向无定，不可捉摸。正是
一招「"+HIY+"天柱云气"+NOR+"」，指向$n$l",
        "dodge":   60,
        "damage":  tydamage,
        "damage_type":  "刺伤"
]),
([      "name":    "雁回祝融",
        "action" : "$N飞身跃起，「"+HIC+"雁回祝融"+NOR+"」！，$w发出一声龙吟从半空中洒向$n的
$l",
        "dodge":   60,
        "damage":  tydamage,
        "damage_type":  "刺伤"
]),
});

int valid_learn(object me)
{
    object ob;

    if( (int)me->query("max_neili") < 50 )
        return notify_fail("你的内力不够，没有办法练衡山剑法。\n");

    if( !(ob = me->query_temp("weapon"))
    ||      (string)ob->query("skill_type") != "sword" )
        return notify_fail("你必须先找一把剑才能练剑法。\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}


int practice_skill(object me)
{
    if( (int)me->query("qi") < 30
    ||      (int)me->query("neili") < 5 )
        return notify_fail("你的内力或气不够，没有办法练习衡山剑法。\n");
 me->receive_damage("qi", 30);        // 这里是不是有点流氓了？
    me->add("neili", -5);
    write("你按著所学练了一遍衡山剑法。\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
        int i, j, level;

        level = (int) me->query_skill("hengshan-jianfa",1);
        for(i = sizeof(action); i > 0; i--) {
                if(level > action[i-1]["lvl"]) {
                        j = NewRandom(i, 20, level/5);
                        return ([
                       "action" : YEL+action[j]["action"]+NOR,
                                "force" : 200 + random(350),
                                "dodge" : random(25)-5,
                                "parry": 20-random(10),
                                "damage" : 100 + random(120),
                                "damage_type" : action[j]["damage_type"],
                                "lvl": action[j]["lvl"],
                        ]);
                }
        }
}

string perform_action_file(string action)
{
        return __DIR__"hengshan-jianfa/" + action;
}

