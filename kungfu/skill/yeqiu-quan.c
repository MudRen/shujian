// 野球拳
// 新手 专用

inherit SKILL;
#include <ansi.h>
#include <combat.h>

mapping *action = ({
([     "action" : HIW"$N挺身而出，双手握拳，一前一后，一招「"HIY"勾摆连击"HIW"」攻向$n的上中下三路!"NOR,
       "force" : 150,
        "dodge" : 5,
       "damage_type" : "瘀伤",
       "lvl" : 0,
]),
([     "action" : HIW"$N微微跨了个马步，左脚蹬地，急速右转，左拳猛的击出，直奔$n的胸前，正是一招 「"HIR"左勾拳"HIW"」!"NOR,
       "force" : 160,
        "dodge" : 5,
        "damage_type" : "瘀伤",
       "lvl" : 12,
]),
([     "action" : HIW"$N微微跨了个马步，右脚蹬地，急速左转，右拳猛的击出，直奔$n的胸前，正是一招 「"HIC"右勾拳"HIW"」!"NOR,
       "force" : 170,
        "dodge" : 5,
        "damage_type" : "瘀伤",
       "lvl" : 18,
]),
([     "action" : HIW"$N左脚朝左侧一摆，左肘下收，左拳朝$n的$l猛的击出，正是一招「"MAG"斜上勾拳"HIW" 」! "NOR,
       "force" : 185,
        "dodge" : 15,
        "damage_type" : "瘀伤",
       "lvl" : 24,
]),
([     "action" : HIW"$N右拳随意击出，左肘横过，忽的变拳为爪，右手便去抓$n的肩头,正是一招「"YEL"近身小擒拿"HIW" 」!  "NOR,
       "force" : 185,
        "dodge" : 15,
        "damage_type" : "瘀伤",
       "lvl" : 30,
]),
([     "action" : HIW"$N右手绕个半圈，左拳虚晃，猛的欺身上去，抓住$n的手腕用力一扭,「"HIB"分筋错骨"HIW" 」! "NOR,
       "force" : 185,
        "dodge" : 15,
        "damage_type" : "瘀伤",
       "lvl" : 50,
])
});

int valid_enable(string usage) { return usage=="cuff" ||  usage=="parry"; }

int valid_learn(object me)
{
       if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
               return notify_fail("练野球拳必须空手。\n");
       if ((int)me->query_skill("force", 1) < 30)
               return notify_fail("你的基本内功等级不够，不能练习野球拳。\n");
       if ((int)me->query("max_neili") < 100)
               return notify_fail("你的内力太弱，无法练野球拳。\n");

if ( me->query_skill("yeqiu-quan",1) > 251 )
		return notify_fail("武林中各种神功绝学多入牛毛，野球拳这种新手技能就不用再费时了吧。\n");

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
       int i, level;
       level = (int)me->query_skill("yeqiu-quan", 1);
       for(i = sizeof(action); i > 0; i--)
               if(level > action[i-1]["lvl"])
                       return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
       if ((int)me->query("jingli") < 30)
               return notify_fail("你的精力太低了。\n");
       if ((int)me->query("neili") < 20)
               return notify_fail("你的内力不够练野球拳。\n");
       me->receive_damage("jingli", 25);
       me->add("neili", -25);
       return 1;
}



mixed hit_ob(object me, object victim, int damage_bonus)
{

	int i;

	i = me->query("max_pot", 1);

   if(i<=320){
       if(random(i)>(int)victim->query_skill("parry",1)/2 
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HIB"$n被$N的气势所震慑，身法一滞，顿时连连中招！\n"NOR,me,victim);
            victim->set_temp("must_be_hit",1);
            call_out("yqq_must_be_hit",2,me,victim,random(i/50));
       }
   }

   if(i<=220){
       if(random(i)>(int)victim->query_skill("dodge",1)/2
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HIB"$n只觉$N拳意凌厉，不由得心下生畏，只得撤招防守，丝毫没有进攻机会！\n"NOR,me,victim);
            victim->set_temp("no_fight",1);
            victim->apply_condition("no_fight",1);
       }
   }

	
     
}

void yqq_must_be_hit(object me,object target,int i)
{
    if(!target) return;
    if(!me) {
        target->delete_temp("must_be_hit");
        if(living(target))
            message_vision(HIY"$n渐渐摸通了套路，松了一口气！\n"NOR,target);
        return;
    }

    if(me->query_skill_mapped("cuff")!="yeqiu-quan"
     ||me->query_skill_mapped("parry")!="yeqiu-quan"
     ||i<=0){
        if(living(target))
            message_vision(HIY"$n终于松了口气，开始反击！\n"NOR,me,target);
        target->delete_temp("must_be_hit");
        return;
    }
    call_out("yqq_must_be_hit",1,me,target,--i);
}



string perform_action_file(string action)
{
	return __DIR__"yeqiu-quan/" + action;
}
