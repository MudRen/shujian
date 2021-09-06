// lingshe-quanfa.c  灵蛇拳法

inherit SKILL;

#include <ansi.h>

mapping *action = ({
([      "action" : "$N一式「"+RED+"灵蛇出洞"+NOR+"」，右手虚晃，左手扬起，突然拍向$n的背后二穴",
        "force" : 170,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 0,
        "skill_name" :"灵蛇出洞",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N侧身一晃，一式「"+YEL+"虎头蛇尾"+NOR+"」，左手拿向$n的肩头，右拳打向$n的胸口",
        "force" : 230,
        "dodge" : 5,
        "parry" : 10,
        "lvl" : 10,
        "skill_name" :"虎头蛇尾",
        "damage_type" : "瘀伤"
]),
([     "action" : "$N一式「"+HIG+"画蛇添足"+NOR+"」，右手环拢成爪，一出手就向扣$n的咽喉要害",
        "force" : 300,
        "dodge" : 15,
        "parry" : 20,
        "lvl" : 20,
      "skill_name" :"画蛇添足",
        "damage_type" : "瘀伤",
]),
([      "action" : "$N左手虚招，右掌直立，一式「"+HIY+"杯弓蛇影"+NOR+"」，错步飘出，疾拍$n的面门",
        "force" : 280,
        "dodge" : 20,
        "parry" : 25,
        "lvl" : 30,
          "skill_name" :"杯弓蛇影",
        "damage_type" : "瘀伤"
]),
([     "action" : "$N使一式「"+HIB+"蛇行鼠窜"+NOR+"」，左拳上格，右手探底突出，抓向$n的裆部",
        "force" : 290,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 40,
       "skill_name" :"蛇行鼠窜",
        "damage_type" : "瘀伤"
]),
([       "action" : "$N一式「"+GRN+"蛇磐青竹"+NOR+"」，十指伸缩，虚虚实实地袭向$n的全身要穴",
        "force" : 310,
        "dodge" : 5,
        "parry" : 3,
        "lvl" : 50,
       "skill_name" :"蛇磐青竹",
        "damage_type" : "瘀伤"
]),
([     "action" : "$N双手抱拳，一式「"+YEL+"万蛇汹涌"+NOR+"」，掌影翻飞，同时向$n施出九九八十一招",
        "force" : 340,
        "dodge" : 10,
        "parry" : 3,
        "lvl" : 65,
         "skill_name" :"万蛇汹涌",
        "damage_type" : "瘀伤"
]),
([    "action" : "$N一式「"+WHT+"白蛇吐信"+NOR+"」，拳招若隐若现，若有若无，急急地拍向$n的丹田",
        "force" : 400,
        "dodge" : 5,
        "parry" : 0,
        "lvl" : 80,
        "skill_name" :"白蛇吐信",
        "damage_type" : "瘀伤"
]),
});
int valid_enable(string usage) { 
if( this_player()->query("oyf/hamagong",1 ) > 1 )
return usage == "cuff" || usage == "parry";}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练灵蛇拳法必须空手。\n");
	if ( me->query("max_neili") < 100)
		return notify_fail("你的内力太弱了，练不了灵蛇拳法。\n");
	if ( me->query_skill("hamagong", 1) < 20)
		return notify_fail("你的蛤蟆功火候太浅，不能学灵蛇拳法。\n");
	if ( me->query_skill("force", 1) < 20)
		return notify_fail("你的基本内功火候太浅，不能学灵蛇拳法。\n");
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
        int i,level,f_force,s;
        s = random(5);
        f_force=me->query_skill("force");
 
        if( (me->query_temp("lsqf/ls") || me->query_temp("lszf/bb")) && s > 3 ) {
          	
                return ([
                "action": CYN "$N手臂青筋根根炸起，两臂如毒蛇般乱钻，带出一股巨大的崩劲，，正是一招"+HIR+"毒蛇出洞"+NOR+"。"NOR,
                                        "force": 400 + random(300),
					"parry": 30,
					"dodge": 30,
					"damage": 250 +random(140),
                "damage_type": "割伤"]);
        }
         
    else if( (me->query_temp("lsqf/ls") || me->query_temp("lszf/bb")) && s > 2 ) { 
                return ([
                "action": WHT "$N横臂扫去，$n伸左臂挡格，岂料$N手臂忽弯，腾的一拳，正打在$n面颊之上。"NOR,
                                        "force": 400 + random(300),
					"parry": 30,
					"dodge": 30,
					"damage": 240 +random(140),
                "damage_type": "内伤"]);
        }

     else if( me->query_temp("lsqf/ls") || me->query_temp("lszf/bb")) {
                return ([
                 "action": WHT "$N手臂宛然灵动如蛇,出拳的方位匪夷所思，怪招猝发！"NOR,
                                        "force": 400 + random(300),
					"parry": 30,
					"dodge": 30,
					"damage": 230 +random(140),
                "damage_type": "内伤"]);
        }
        
       
        level   = (int) me->query_skill("lingshe-quanfa",1);
        for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
        return action[NewRandom(i, 20, level/5)];

}


int practice_skill(object me)
{
        if ((int)me->query("jingli") < 50)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练灵蛇拳法。\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"lingshe-quanfa/" + action;
}


mixed hit_ob(object me, object victim)
{
  

        int lvl = me->query_skill("hand"),attack,lb;
        attack=lvl/100;
        if(attack>4) attack=4;
		attack=random(attack);
        	if(attack<=1) attack=1;
        lb = random(12);

   if( lb > 7 && !me->query_temp("lsqf/auto") )
          {
                message_vision(WHT "$N忽地欺进，左手快如闪电，两指一并点在$n胸口，正是一招"+HIW+"白蛇吐信"+WHT+"！\n$N紧跟又轰出一拳！" NOR,me,victim);
                victim->start_busy(random(4));
                         me->set_temp("lsqf/auto", 1);
                         me->add_temp("apply/attack",  me->query_skill("lingshe-quanfa", 1)/8);
                         COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(4)?1:3);
                        me->add_temp("apply/attack", -me->query_skill("lingshe-quanfa", 1)/8);
                        me->delete_temp("lsqf/auto");
                        victim->apply_condition("no_perform", 2+ random(2));

         }
     
   else if( lb > 6 && !me->query_temp("lsqf/auto") )
 {
        	message_vision(MAG "$N揉身而上，自左向右轻轻回旋一周，$n被$N的身行所迷惑，眼神恍惚，顿时又挨了一下。" NOR, me,victim);
        	victim->start_busy(random(2));
                   me->set_temp("lsqf/auto", 1);
                         me->add_temp("apply/attack",  me->query_skill("lingshe-quanfa", 1)/9);
                         COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(4)?1:3);
                        me->add_temp("apply/attack", -me->query_skill("lingshe-quanfa", 1)/9);
                        me->delete_temp("lsqf/auto");

        }

   else if( lb > 5 && !me->query_temp("lsqf/auto") )
{
        	message_vision(HIY "紧接着，$N口中发出“嘶嘶”的声音，双手半曲，三指上竖成蛇状，有如急风暴雨般攻出了"+
			   chinese_number(attack+1)+"招。" NOR,me, victim);
                    	victim->start_busy(random(attack+1)+1 );
                      me->set_temp("lsqf/auto", 1);
                         me->add_temp("apply/attack",  me->query_skill("lingshe-quanfa", 1)/9);
                         COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(4)?1:3);
                        me->add_temp("apply/attack", -me->query_skill("lingshe-quanfa", 1)/9);
                        me->delete_temp("lsqf/auto");
 
}
}
