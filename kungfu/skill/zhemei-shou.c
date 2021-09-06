// zhemei-shou.c 天山折梅手
// Create by action@SJ 2009/1/10
// modified by zhuifeng@SJFY 2010/07/17

#include <ansi.h>
inherit SKILL;  

mapping *action = ({
([  "action" : MAG"$N一招「"+NOR+HIG+"吹梅笛怨"+NOR+MAG+"」，双手横挥，抓向$n"NOR,
    "lvl" : 0,
    "skill_name" : BLK "吹梅笛怨" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : MAG"$N一招「"+NOR+YEL+"黄昏独自愁"+NOR+MAG+"」，身子跃然而起，抓向$n的头部"NOR,
    "lvl" : 30,
    "skill_name" : RED "黄昏独自愁" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : MAG"$N一招「"+NOR+GRN+"寒山一带伤心碧"+NOR+MAG+"」，双手纷飞，$n只觉眼花缭乱"NOR,
    "lvl" : 60,
    "skill_name" : GRN "寒山一带伤心碧" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : MAG"$N一招「"+NOR+YEL+"梅花雪落覆白苹"+NOR+MAG+"」，双手合击，$n只觉无处可避"NOR,
    "lvl" : 90,
    "skill_name" : YEL "梅花雪落覆白苹" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : MAG"$N一招「"+NOR+HIC+"砌下落梅如雪乱"+NOR+MAG+"」，双手飘然抓向$n"NOR,
    "lvl" : 120,
    "skill_name" : HIC "砌下落梅如雪乱" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : MAG"$N双手平举，一招「"+NOR+HIW+"云破月来花弄影"+NOR+MAG+"」击向$n",
    "lvl" : 150,
    "skill_name" : HIW "云破月来花弄影" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : MAG"$N一招「"+NOR+WHT+"花开堪折直须折"+NOR+MAG+"」，拿向$n，似乎$n的全身都被笼罩"NOR,
    "lvl" : 180,
    "skill_name" : WHT "花开堪折直须折" NOR,
    "damage_type" : "内伤"
]),
([  "action" : MAG"$N左手虚晃，右手一记「"+MAG+"红颜未老恩先绝"+NOR+MAG+"」击向$n的头部"NOR,
    "lvl" : 210,
    "skill_name" : MAG "红颜未老恩先绝" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : MAG"$N施出「"+NOR+RED+"虚妄笑红"+NOR+MAG+"」，右手横扫$n的$l，左手攻向$n的胸口"NOR,
    "lvl" : 240,
    "skill_name" : RED "虚妄笑红" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : MAG"$N施出「"+NOR+YEL+"玉石俱焚"+NOR+MAG+"」，不顾一切扑向$n"NOR,
    "lvl" : 270,
    "skill_name" : YEL "玉石俱焚" NOR,
    "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { 

	  return usage=="parry"|| usage=="hand"; }
	
	
int valid_combine(string combo) 
   {
	    object me,victim;
	   me = this_player(); 

           if(me->query("marry/id") || me->query("/quest/xiaoyao/pass")) 
		return combo=="liuyang-zhang"; 
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练天山折梅手必须空手。\n");
	if ((int)me->query_skill("hand", 1) < 50)
		return notify_fail("你的基本手功火候不够，无法学习。\n");
	if ((int)me->query("max_neili") < 500)
		return notify_fail("你的内力太弱，无法练天山折梅手。\n");
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
		string msg;
level = (int) me->query_skill("zhemei-shou",1);

	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			if ( me->query_temp("zms/piaomiao")){
				return ([
					"action":HIR+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIR), NOR, HIR)+NOR,
					"damage": 100+random(100),
					"damage_type": "割伤",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}

if(me->query_temp("tanmei")){
		switch(me->query_temp("tanmei")){						
			case 2: msg = HIG "$n突然闻到一股若有若无的香味，心猿意马之中$N的双手已向$p胸口拍来！                        
"HIW"【落 雪】"NOR; break;
      case 1: msg = HIC "$N双手急挥，左右摇摆，幻出漫天"HIW"梅花"HIC"，飞雪似的向$n落来！                                    
"HIM"【散花香】"NOR; break;
default: msg = MAG "$N微微一笑，使出"HIG"【弹梅.落雪.散花香】"MAG"左手向$n轻轻弹出，好像是要弹去梅花上面的露珠！       
"HIW"【弹 梅】"NOR;break;
			
		}
		me->add_temp("tanmei", -1);
		return ([
			"action":msg,
					"damage": 100+random(80),
					"damage_type": "割伤",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}
			return ([
				"action" : action[j]["action"],
				"force" : 200 + random(350),
				"dodge" : random(25)-5,
				"parry": 200+random(100),
				"damage" : 80 + random(100),
				"damage_type" : action[j]["damage_type"],
				"lvl": action[j]["lvl"],
			]);
		}
	}
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 60)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的内力不够练天山折梅手。\n");
	me->receive_damage("jingli", 50);
	me->add("neili", -20 );
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"zhemei-shou/" + action;
}

mixed hit_ob(object me, object target, int damage_bonus)
{
	int i,j;

	i = me->query_skill("zhemei-shou", 1);

if(i>=150||(random(3)&&me->query_temp("xiaoyao_jianwu", 1))){
	                switch (random(4)) {
	    case 0:
           message_vision(HIR"这时$N内力生发，将「逍遥」二字发挥得淋漓尽致，姿势优雅美观，潇洒如意然而逍遥派武学的诸般狠辣招数\n"
                             "自然而然的也使了出来，所使招数渐趋阴险刻毒，$N招招凶险，皆攻向$n要害，直欲致$n死得惨酷无比！\n"NOR,me,target);
          j = i*(2+random(4));
          if( j>=target->query("qi") )  j=target->query("qi")/3;
            target->receive_damage("qi",j );
             target->receive_wound("qi",j/2 );
            break;
      case 1:
            message_vision(HIB"$N手腕转了个小圈，既快且准，三只手指搭上$n手腕，大拇指和小指跟着便即收拢，扣住$n脉门，$n顿时动弹不得！\n"NOR,me,target);
            target->add_busy(1);
  
       break;
       case 2:
            message_vision(HIC"$N右手一弯，掌上凝聚阴柔之力，无声无息劈向$n的「至阳穴」，跟着左拳猛击而出，击向$n胸口的「膻中穴」！\n"NOR,me,target);
            target->add_busy(1+random(2));
            
       
       break;
        case 3:
            message_vision(HIM"$N微微一笑，使出天山派絕招「天山折梅手」，左手向敌人手中的武器轻轻弹出，好像是要弹去梅花上面的露珠！\n"NOR,me,target);
       if( i>=target->query("qi") )  i=target->query("qi")/5;
            target->receive_damage("qi",i);
       break;
   }  
}
   
}
