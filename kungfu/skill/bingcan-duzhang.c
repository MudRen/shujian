// bingcan-duzhang.c  冰蚕毒掌

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N脸上露出诡异的笑容，双掌携满寒霜，横扫$n",
        "dodge" : 21,
        "attack": 79,
        "parry" : 37,
        "dmage" : 52,
        "force" : 430,
        "damage_type": "瘀伤"
]),
([      "action": "$N突然身形旋转起来扑向$n，双掌飞舞着拍向$n的$l",
        "dodge" : 22,
        "attack": 96,
        "parry" : 34,
        "dmage" : 67,
        "force" : 490,
        "damage_type": "瘀伤"
]),
([      "action": "$N将冰蚕寒毒运至右手，阴毒无比地拍向$n的$l",
        "dodge" : 24,
        "attack": 113,
        "parry" : 10,
        "dmage" : 82,
        "force" : 530,
        "damage_type": "瘀伤"
]),
([      "action": "$N诡异的一笑，双掌带着凌厉的寒气拍向$n的$l",
        "dodge" : 28,
        "attack": 139,
        "parry" : 36,
        "dmage" : 95,
        "force" : 580,
        "damage_type": "瘀伤"
]),
([      "action": "$N仰天一声长啸，聚集全身的力量击向$n",
        "dodge" : 27,
        "attack": 161,
        "parry" : 21,
        "dmage" : 105,
        "force" : 640,
        "damage_type": "瘀伤"
]),
});

int valid_enable(string usage) 
{ 
if ( this_player()->query("quest/bingcan/pass") )

 return usage=="strike" || usage=="parry"; 
}   

int valid_learn(object me)
{
        if ((int)me->query_skill("yijinjing", 1) < 0)
                return notify_fail("你所修的内功无法练冰蚕毒掌。\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("你的内功火候不够，无法练冰蚕毒掌。\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("你的内力太弱，无法练冰蚕毒掌。");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("bingcan-duzhang", 1))
                return notify_fail("你的基本掌法水平有限，无法领会更高深的冰蚕毒掌。\n");

        if ((int)me->query_skill("yijinjing", 1) < (int)me->query_skill("bingcan-duzhang", 1))
return notify_fail("你的神足经神功水平有限，无法领会更高深的冰蚕毒掌。\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me)
{
	int i, j, level;
	level = me->query_skill("bingcan-duzhang",1);

	for(i = sizeof(action); i > 0; i--){
		if(level > action[i-1]["lvl"]){
			j = NewRandom(i, 20, level/5);


			if( me->query_temp("bcdz_pfm")) {
				return ([
                             	"action" :	WHT+action[j]["action"]+NOR,
					"poison":	action[j]["poison"],
					"damage_type":	action[j]["damage_type"],
					"dodge":	random(55),
					"parry":	random(55),
					"force":	350 + random(350),
					"damage":	50 + random(50),
				]);
			}
			return ([
				"action":	action[j]["action"],
				"damage_type":	action[j]["damage_type"],
				"poison":	action[j]["poison"],
				"lvl":		action[j]["lvl"],
				"force":	300 + random(350),
				"dodge":	random(30),
				"parry":	random(30),
			]);
		}
	}
}


int practice_skill(object me)
{
        if ((int)me->query("qi") < 40)
                return notify_fail("你的体力太低了。\n");

        if ((int)me->query("neili") < 30)
                return notify_fail("你的内力不够练冰蚕毒掌。\n");

        if (me->query_skill("bingcan-duzhang", 1) < 50){
                me->receive_damage("jingli", 40);
	me->add("neili", -15);
}
        else
{ 
              me->receive_damage("jingli", 50);
	me->add("neili", -55);
}
        return 1;
}

mixed hit_ob(object me, object victim, int damage)  // 增加auto
{
  

        int lvl = me->query_skill("bingcan-duzhang"),attack,lb;
        attack=lvl/100;
        if(attack>=4) attack=4;
                attack=random(attack);
        if(attack<=1) attack=1;
        lb = random(10);
       
 if( !me->query_temp("bcdzauto")  && lb> 5  )
        
        {  
              
                        if ( random(lvl) > 50 && random(me->query_dex()) > victim->query_dex()/4) 
          {
                message_vision(BLU+BWHT "眼见$n越战越勇，$N却丝毫不放在心上，抽空之间平平挥出一招，\n"
                                   "$n见来势怪异，掌风中竟夹杂着扑鼻的腥气，不禁打了个冷战。 \n"NOR,me,victim);
                if(userp(victim))
{
victim->start_busy(random(3));
                 victim->add_condition("cold_poison", 10);
}
else 
{
victim->start_busy(random(4));
victim->add_condition("cold_poison", 15);
}
                         me->set_temp("bcdzauto", 1);
                         me->add_temp("apply/attack",  me->query_skill("bingcan-duzhang", 1)/6);
                         me->add_temp("apply/attack", -me->query_skill("bingcan-duzhang", 1)/6);
                       me->delete_temp("bcdzauto");               
                       
}
else if (random(lvl) > 150 && random(me->query_str()) > victim->query_str())
{
                        message_vision(HIW "$N趁机踏步上前，向$n面门前虚晃一招，$n还未抵挡，不料后招又至，正中$n小腹。\n" NOR,me,victim);
                        message_vision(WHT "$n只觉丹田中真气似被冻结一般，无法凝聚，顿时出了一身冷汗。\n" NOR,me,victim);
 me->set_temp("bcdzauto", 1);
if(userp(victim))
{
                        victim->add("jing",- lvl); 
                        victim->add("neili",- lvl); 
                        victim->add("jingli",- lvl); 
                      victim->apply_condition("no_perform", 2+ random(2));
                      victim->apply_condition("no_exert", 2+ random(2));
                      victim->add_condition("cold_poison", 20);
}
else
{
                        victim->add("jing",- lvl*3/2); 
                        victim->add("neili",- lvl*3/2); 
                        victim->add("jingli",- lvl*3/2); 
                      victim->apply_condition("no_perform", 2+ random(4));
                      victim->apply_condition("no_exert", 2+ random(4));
                      victim->add_condition("cold_poison", 30);
}


me->delete_temp("bcdzauto");   
// COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(4)?1:3);

                }

                      

         }
 
 

}



string perform_action_file(string action)
{
    return __DIR__"bingcan-duzhang/" + action;
}

