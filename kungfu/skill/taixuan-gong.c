#include <ansi.h>
//inherit FORCE;
inherit SKILL;

string *dodge_msg = ({
    "$n左手拍出，劲风到处，把$N震到一边。\n",
    "$n手臂回转，抓住$N手肘一推，将$N远远掷开。\n",
    "$n两腿轻蹬，激跃而出，竟已落在十数丈外。\n",
    "$N只觉眼前一花，只见到$n身形一幌，自己的招数居然莫名其妙就落空了。\n",
});

string *parry_msg = ({
    "$n默念太玄口诀，将$N的攻势尽数化解。\n",
    "$n一声轻笑，对$N的攻击毫不在意。\n",
    
    "$N只觉$n遍体坚硬，犹如击在铜墙铁壁上一般。\n",
});

mapping *actionw = ({
([      "action" : "$N一招[ 赵客缦胡缨，吴钩霜雪明 ]直击向$n。",
        "force" : 510,
        "attack": 180,
        "dodge" : 85,
        "parry" : 175,
        "damage": 325,
        "damage_type": "内伤"
]),
([      "action":"$N一招[ 赵客缦胡缨，吴钩霜雪明 ]直击向$n。",
        "force" : 510,
        "attack": 108,
        "dodge" : 72,
        "parry" : 115,
        "damage": 310,
        "damage_type": "刺伤"
]),
([      "action":"$N一招[ 赵客缦胡缨，吴钩霜雪明 ]直击向$n。",
        "force" : 532,
        "attack": 125,
        "dodge" : 60,
        "parry" : 102,
        "damage": 365,
        "damage_type": "刺伤"
]),
([      "action":"$N又一招[ 银鞍照白马，飒沓如流星 ]向$n撞去。",
        "force" : 565,
        "attack": 110,
        "dodge" : 75,
        "parry" : 105,
        "damage": 390,
        "damage_type": "内伤"
]),
([      "action":"$N高叫：[ 十步杀一人，千里不留行 ]冲向$n。",
        "force" : 550,
        "attack": 108,
        "dodge" : 70,
        "parry" : 120,
        "damage": 420,
        "damage_type": "刺伤"
]),
});

mapping *action = ({
([      "action":"$N招式一变，[ 事了拂衣去，深藏身与名 ]$n只得放弃抵挡。",
        "force" : 540,
        "attack": 50,
        "dodge" : 50,
        "parry" : 120,
        "damage": 355,
        "damage_type":  "瘀伤"
]),
([      "action":"$N仰天大笑[ 闲过信陵饮，脱剑膝前横 ]挥拳朝$n打去。",   
        "force" : 560,
        "attack": 60,
        "dodge" : 60,
        "parry" : 90,
        "damage": 330,
        "damage_type":  "瘀伤"
]),
([      "action":"$N又使出一招[ 将炙啖朱亥，持觞劝侯嬴 ]直击向$n。",
        "force" : 570,
        "attack": 75,
        "dodge" : 75,
        "parry" : 135,
        "damage": 360,
        "damage_type":  "瘀伤"
]),
([      "action":"$N变拳为掌，正是一招[ 三杯吐然诺，五岳倒为轻 ]。",
        "force" : 580,
        "attack": 80,
        "dodge" : 80,
        "parry" : 75,
        "damage": 395,
        "damage_type":  "瘀伤"
]),
([      "action":"$N拳法再变，[ 眼花耳热后，意气素霓生 ]$n好不狼狈。",
        "force" : 580,
        "attack": 95,
        "dodge" : 90,
        "parry" : 125,
        "damage": 360,
        "damage_type":  "瘀伤"
]),
([      "action":"$N长叹一声：[ 谁能书阁下，白首太玄经 ]$n连连败退。",
        "force" : 580,
        "attack": 100,
        "dodge" : 100,
        "parry" : 145,
        "damage": 480,
        "damage_type":  "瘀伤"
]),
});
int valid_enable(string usage)
{
return usage == "cuff" || usage == "dodge" ||usage == "parry" || usage == "force" || usage == "strike";
}



string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}


int valid_learn(object me)
{


if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
return notify_fail("练太玄功必须空手。\n");
if ((int)me->query("max_neili") < 100)
return notify_fail("你的内力太弱，无法练功。\n");
return 1;
}

string exert_function_file(string func)
{
        return __DIR__"taixuan-gong/" + func;
}
string perform_action_file(string action)
{
        return __DIR__"taixuan-gong/" + action;
}

string query_parry_msg(object weapon, object me)
{
        if (me->query_skill_mapped("parry") == "taixuan-gong")
                return parry_msg[random(sizeof(parry_msg))];
}
        

mapping query_action(object me, object weapon)
{
        int i, j, level;
                string msg;
level = me->query_skill("taixuan-gong",1);
        for(i = sizeof(action); i > 0; i--) {
                if(level > action[i-1]["lvl"]) {
                        j = NewRandom(i, 20, level/5);
                                                if ( me->query_temp("txg/xuan")){
                                return ([
                                        "action":HIW+replace_string(replace_string(replace_string(action[j]["actionw"], "$w", "$W"), "$W", "$w"MAG), NOR, MAG)+NOR,
                                        "damage": 60+random(120),
                                        "damage_type": "割伤",
                                        "dodge": random(35),
                                        "parry": random(35),
                                        "force": 200+random(300),
                                ]);
                        }
                        if(me->query_temp("txg/xuan")){
                switch(me->query_temp("taixuan")){                                              
 case 5: msg = HIW"\n$N招式一变「"HIR"银鞍照白马，飒沓如流星 "NOR+HIC"」$n只得放弃抵挡"NOR;break;
 case 4: msg = HIG"\n$N一招「"HIR"赵客缦胡缨，吴钩霜雪明"NOR+HIC"」直击向$n"NOR;break;
 case 3: msg = HIC"\n$N变拳为掌，正是一招「"HIR"三杯吐然诺，五岳倒为轻 "NOR+HIC"」"NOR;break;
 case 2: msg = HIM"\n$N拳法再变，「"HIR" 眼花耳热后，意气素霓生 "NOR+HIC"」$n好不狼狈"NOR; break;
 case 1: msg = HIC"\n$N高叫：「"HIR" 十步杀一人，千里不留行 "NOR+HIC"」冲向$n"NOR; break;
default: msg = HIY"\n$N长叹一声「"HIR"谁能书阁下，白首太玄经 "NOR+HIC"」$n连连败退"NOR;break;
                }
                me->add_temp("taixuan", -1);
                return ([
                        "action":msg,
                                        "damage": 80+random(80),
                                        "damage_type": "割伤",
                                        "dodge": random(35),
                                        "parry": random(60),
                                        "force": 200+random(300),
                                ]);
                        }
                        return ([
                                "action" : action[j]["action"],
                                "force" : 200 + random(350),
                                "dodge" : random(25)-5,
                                "parry": 50+random(60),
                                "damage" : 80 + random(80),
                                "damage_type" : action[j]["damage_type"],
                                "lvl": action[j]["lvl"],
                        ]);
                }
        }
if (random(me->query_skill("taixuan-gong",1)) > 300 && me->query("neili") > 100)
        {
                me->add("neili", -50);
                return ([
        "action": HIR "$N的心中突然一片茫然，只觉得经脉中象有无数的蝌蚪在串来串去，难过非常，
当下不及多想，顺着蝌蚪的走向一阵拳打脚踢！四周顿时劲风乱飑，好不热闹！"NOR,
        "damage": 1000,
        "dodge" : 100,
        "force" : 400,
        "damage_type": "瘀伤"]);
        }
        return action[random(sizeof(action))];


        
}
int practice_skill(object me)
{
       if ((int)me->query("jingli") < 30)
               return notify_fail("你的体力太低了。\n");
       if ((int)me->query("neili") < 20)
               return notify_fail("你的内力不够练太玄功。\n");
       me->receive_damage("jingli", 30);
       me->add("neili", -10);
       return 1;
}


