// tiezhang-zhangfa 铁掌掌法
// BY BOBO@SJ 
// Update By lsxk@hsbbs 2007/5/15

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([
	"action": "$N右掌一拂而起，一招「推窗望月」，左掌自侧面连消带打，登时将$n的力道带斜，右掌一挥，拍向$p$l",
	"lvl": 0,
	"damage_type": "瘀伤",
	"skill_name": "推窗望月"
]),
([
	"action": "$N使一招「分水擒龙」，右臂突伸抓向$n，左掌陡然沿着伸长的右臂，飞快的一削而出，斩向$n的$l",
	"lvl": 20,
	"damage_type": "瘀伤",
	"skill_name": "分水擒龙"
]),
([
	"action": "$N突然使一式「白云幻舞」，双臂如旋风一般一阵狂舞，刮起一阵旋转的气浪，掌势一推，压向$n",
	"lvl": 40,
	"damage_type": "瘀伤",
	"skill_name": "白云幻舞"
]),
([
	"action": "$N一招「掌中乾坤」，一掌拍出以后，猛地侧过身来，右臂自左肋下疾翻而出，拇，中两指扣圈猛弹$n的$l",
	"lvl": 60,
	"damage_type": "内伤",
	"skill_name": "掌中乾坤"
]),
([
	"action": "$N一招「落日赶月」，伸掌一拍一收，一拍无丝毫力道，一收之间，一股阴柔无比的力道才陡然发出",
	"lvl": 80,
	"damage_type": "瘀伤",
	"skill_name": "落日赶月"
]),
([
	"action": "$N身行暴起，一式「蛰雷为动」，双掌横横切出，掌缘才递出，呜呜呼啸之声狂作，铁掌之名，由此而出",
	"lvl": 100,
	"damage_type": "内伤",
	"skill_name": "蛰雷为动"
]),
([
	"action": "$N一招「天罗地网」，左掌大圈而出，右掌小圈而出，两股奇异的力道一会之下，巨大的内劲压向$n的$l",
	"lvl": 120,
	"damage_type": "瘀伤",
	"skill_name": "天罗地网"
]),
([
	"action": "$N一招「五指幻山」，猛一吐气，单掌有如推门，另一掌却是迅疾无比的一推即收，双劲合一，去势如虎",
	"lvl": 140,
	"damage_type": "内伤",
	"skill_name": "五指幻山"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me,object weapon)
{
	int i, level, j;
	string msg;

	level = me->query_skill("tiezhang-zhangfa",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level >= action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);      
			if ( me->query_temp("tz/heyi")) {
				switch(me->query_temp("tz/heyi")){
					case 3: msg = HIB"$N突然脚下一晃，欺进$n，右掌一翻，运起铁掌罡气，单掌向$p顶门直拍而下"NOR; break;
					case 2: msg = HIR"紧接着$N身体一转，到了$n身旁，左掌顺力拍出，这一招看似平和，实是内涵罡气，威力无比"NOR; break;
					case 1: msg = HIW"最后$N猛一吐气，单掌有如推门，另一掌却是迅疾无比的一推即收，双劲合一，去势如虎"NOR; break;
					default : msg = HIB"$N突然脚下一晃，欺进$n，右掌一翻，运起铁掌罡气，单掌向$p顶门直拍而下"NOR; break;
				}
				me->add_temp("tz/heyi", -1);
				return ([
					"action": msg,
					"force": 250 + random(350),
					"parry": random(20)+10,
					"dodge": random(20)+10,
					"damage": 50 + random(100),
					"damage_type": "瘀伤"
				]);
			}
                   if (me->query_temp("tzzf")){
                     if (me->query_temp("tiezhang")){
                       me->add("neili", -500);
                           return ([
                                   "action" : BLU+action[j]["action"]+NOR,
                                   "force" : 400 + random(400),
                                   "damage": random(100)+80,
                                   "dodge": action[j]["dodge"]+random(20),
                                   "parry": random(20)+10,
                                   "lvl" : action[j]["lvl"],
                                   "damage_type" : action[j]["damage_type"],
                           ]);
                           }
                          else {
 				return ([
					"action" : WHT+action[j]["action"]+NOR,
 					"force" : 350 + random(350),
 					"damage": random(100)+50,
 					"dodge": action[j]["dodge"]+random(20),
 					"parry": random(20)+10,
					"lvl" : action[j]["lvl"],
 					"weapon" : "铁掌",
					"damage_type" : "割伤",
				]);
                         }
                     }
			if( random(me->query_skill("strike", 1)) > 100 
			 && random(me->query_skill("tiezhang-zhangfa", 1)) > 100 
			 &&( me->query_skill("yingou-bifa") > 100 || me->query("max_pot",1) >450 )
			 && !random(3)
			 && me->query("neili") > 30 
       && me->query("quest/tzauto/over") == 1   
			 && !me->query_temp("tz/heyi")) {
				me->add("neili", -20);
				return ([
					"action": HIW"$N右掌轻灵如刀，左掌凝重如斧，$n正招架不暇，忽的$N招式一换，骈指如钩，却是银钩笔法中的一招！"NOR,
					"force": 400 + random(300),
					"parry": 30,
					"dodge": 30,
           "damage": 160 +random(140),
					"damage_type": "刺伤"
				]);
			}

                        if (random(me->query_skill("strike", 1)) > 100 
			 && random(me->query_skill("tiezhang-zhangfa", 1)) > 100 
			 && (me->query_skill("liuye-daofa") > 100 || me->query("max_pot",1) >450 )
			 && !random(3)
			 && me->query("neili") > 30 
       && me->query("quest/tzauto/over") == 1
			 && !me->query_temp("tz/heyi")) {
				me->add("neili", -20);
				return ([
					"action": HIR"$N忽然立掌如刀，招式一变，用的却是柳叶刀法中的两刀一掌的功夫！"NOR,
					"force": 400 + random(300),
					"parry": 30,
					"dodge": 30,
                                        "damage": 120 +random(100),
					"damage_type": "割伤"
				]);
			}
                        if (random(me->query_skill("strike", 1)) > 100 
			 && random(me->query_skill("tiezhang-zhangfa", 1)) > 100 
                         && (me->query_skill("lietian-fu") > 100 || me->query("max_pot",1) >320)
			 && !random(3)
       && me->query("quest/tzauto/pass") == 1
			 && me->query("neili") > 30 
			 && !me->query_temp("tz/heyi")) {
				me->add("neili", -20);
				return ([
					"action": HIY"$N忽然左掌虚晃，右掌却悄悄运力，宛如提着一把大斧，呼的一声当头朝$n劈下，却是一招“离魂斩”！"NOR,
					"force": 400 + random(300),
					"parry": 30,
					"dodge": 30,
                                        "damage": 140 +random(100),
					"damage_type": "劈伤"
				]);
			}

                   if (me->query_temp("tiezhang")) {
                           me->add("neili", -300);
                          return ([
                                   "action": CYN + action[j]["action"] + NOR,
                                   "lvl": action[j]["lvl"],
                                   "damage_type" : action[j]["damage_type"],
                                   "force":300+random(350),
                                   "dodge":random(30)-10,
                                   "parry":random(20),
                                   ]);
                               }
			return ([  
				"action": action[j]["action"],
				"lvl": action[j]["lvl"],
				"damage_type" : action[j]["damage_type"],
				"force":200+random(350),
				"dodge":random(30)-10,
				"parry":random(20),
			]);
		}
	}
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练铁掌掌法必须空手。\n");
	if ((int)me->query_skill("force", 1) < 35)
		return notify_fail("你的内功火候不够，无法练铁掌掌法。\n");
	if ((int)me->query("max_neili") < 40)
		return notify_fail("你的内力太弱，无法练铁掌掌法");
	return 1;
}

int practice_skill(object me)
{
	int lvl = me->query_skill("tiezhang-zhangfa", 1);
	int i = sizeof(action);
	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练铁掌掌法。\n");

	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tiezhang-zhangfa/" + action;
}



mixed hit_ob(object me, object victim, int damage)
{
  

        int lvl,attack,lb;
        lvl= me->query_skill("tiezhang-zhangfa",1) +  me->query_skill("lietian-fu",1) +  me->query_skill("liuye-daofa",1) + me->query_skill("yingou-bifa",1);
        lvl = lvl/4;
        lb = random(10);
       
 if( !me->query_temp("tzrh/auto") && userp(me)&& me->query("quest/tzauto/over") )
   	
   	{  

 		 if(  lb> 7 &&  me->query_temp("tiezhang") ) 
          {
                message_vision(HBBLU "$N武技早已臻登峰造极之境，铁掌武技烂熟于心，一双肉掌或劈或砍或点，使的居然全是长兵刃的招式!" NOR,me,victim);
                victim->start_busy(random(2));
                         me->set_temp("tzrh/auto", 1);
                         me->add_temp("apply/attack",  me->query_skill("lietian-fu", 1)/6);
                         COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(4)?1:3);
                        me->add_temp("apply/attack", -me->query_skill("lietian-fu", 1)/6);
                        me->delete_temp("tzrh/auto");
                        victim->apply_condition("no_perform", 2+ random(2));

         }
 
   else if(  lb> 5 &&  me->query_temp("tiezhang") ) 
 {
        	message_vision(HBRED "这铁掌连环绝技乃是$N看家本领，招招穷追猛打，不死不休！" NOR, me,victim);
        	victim->start_busy(random(2));
                   me->set_temp("tzrh/auto", 1);
                         me->add_temp("apply/attack",  me->query_skill("liuye-daofa", 1)/6);
                         COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(4)?1:3);
                        me->add_temp("apply/attack", -me->query_skill("liuye-daofa", 1)/6);
                        me->delete_temp("tzrh/auto");

        }

   else if( lb>3 || me->query_temp("tiezhang") )
{
                message_vision(HBMAG "$N灵光一闪，平生所学刹那间融会贯通，紧跟着又拍出一掌。" NOR,me, victim);
                    	victim->start_busy(random(attack+1));
                      me->set_temp("tzrh/auto", 1);
                         me->add_temp("apply/attack",  me->query_skill("yingou-bifa", 1)/6);
                         COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(4)?1:3);
                        me->add_temp("apply/attack", -me->query_skill("yingou-bifa", 1)/6);
                        me->delete_temp("tzrh/auto");
 
}

}

}
