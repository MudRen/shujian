// liuyang-zhang.c 天山六阳掌

// modified by action@SJ 2009/2/5
//modified by zhuifeng@SJFY 2010/0717

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : HIY"$N一招「"+YEL+"落日熔金"+HIY+"」，左掌叠于右掌之上，劈向$n小腹要害之处"NOR,
        "force" : 170,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 0,
        "skill_name" : "落日熔金",
        "damage_type" : "瘀伤"
]),
([  "action" : HIY"$N一招「"+RED+"安禅制毒龙"+HIY+"」， 面色凝重， 双掌轻飘飘地拍向$n面颊"NOR,
        "force" : 200,
        "dodge" : 15,
        "parry" : 20,
        "lvl" : 10,
        "skill_name" : "安禅制毒龙",
        "damage_type" : "瘀伤"
]),
([  "action" : HIY"$N一招「"+MAG+"日斜归路晚霞明"+HIY+"」，双掌幻化一片掌影，将$n笼罩于内"NOR,
        "force" : 240,
        "dodge" : 30,
        "parry" : 15,
        "lvl" : 20,
        "skill_name" : "日斜归路晚霞明",
        "damage_type" : "瘀伤"
]),
([  "action" : HIY"$N一招「"+HIC+"阳关三叠"+HIY+"」，急速地向$n的$l连击三掌，招式十分凌厉"NOR,
        "force" : 360,
        "dodge" : 10,
        "parry" : 30,
        "lvl" : 30,
        "skill_name" : "阳关三叠",
        "damage_type" : "瘀伤"
]),
([  "action" : HIY"$N一招「"+WHT+"阳春一曲和皆难"+HIY+"」， 只见掌力幻化作万千掌影攻向$n下盘"NOR,
        "force" : 350,
        "dodge" : 40,
        "parry" : 50,
        "lvl" : 40,
        "skill_name" : "阳春一曲和皆难",
        "damage_type" : "瘀伤"
]),
([  "action" : HIY"$N双掌平挥，一招「"+HIW+"云霞出海曙"+HIY+"」击向$n的胸口，只见$n急忙封住胸口"NOR,
        "force" : 400,
        "dodge" : 30,
        "parry" : 15,
        "lvl" : 50,
        "skill_name" : "云霞出海曙",
        "damage_type" : "瘀伤"
]),
([  "action" : HIY"$N一招「"+RED+"白日参辰现"+HIY+"」，只见一片掌影攻向$n前胸，顿时$n陷入困境"NOR,
        "force" : 420,
        "dodge" : -1,
        "parry" : 50,
        "lvl" : 60,
        "skill_name" : "白日参辰现",
        "damage_type" : "瘀伤"
]),
([  "action" : HIY"$N左掌虚晃，右掌一招「"+RED+"云霞出薛帷"+HIY+"」猛然击向$n的头部，犹如云霞般"NOR,
        "force" : 260,
        "dodge" : 15,
        "parry" : 35,
        "lvl" : 70,
        "skill_name" : "云霞出薛帷",
        "damage_type" : "瘀伤"
]),
([  "action" : HIY"$N施出「"+HIC+"青阳带岁除"+HIY+"」， 右手横扫$n的$l， 左手猛然攻向$n的胸口"NOR,
        "force" : 280,
        "dodge" : 50,
        "parry" : 25,
        "lvl" : 80,
        "skill_name" : "青阳带岁除",
        "damage_type" : "瘀伤"
]),
([  "action" : HIY"$N施出「"+YEL+"阳歌天钧"+HIY+"」，双掌同时击向$n的$l，霎那间，$n依然凸显无助"NOR,
        "force" : 300,
        "dodge" : 5,
        "parry" : 25,
        "lvl" : 90,
        "skill_name" : "阳歌天钧",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) 
{
	object me;
	me = this_player(); 
	
           if(me->query("marry/id") || me->query("/quest/xiaoyao/pass")) 
		return combo=="zhemei-shou"; 
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练天山六阳掌必须空掌。\n");
		
	if ((int)me->query_skill("strike", 1) < 30)		
		return notify_fail("你的基本掌功火候不够，无法学习。\n");
		
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力修为太弱，无法练习天山六阳掌。\n");
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
level = me->query_skill("liuyang-zhang",1);

	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
						if ( me->query_temp("ruyi/wanshi")){
				return ([
					"action":MAG+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"MAG), NOR, MAG)+NOR,
					"damage": 60+random(120),
					"damage_type": "割伤",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}
			if ( me->query_temp("ryd/xiaoyao")){
				return ([
					"action":HIR+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIR), NOR, HIR)+NOR,
					"damage": 100+random(100),
					"damage_type": "割伤",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}
if ( me->query_temp("lyz/jiutian")){
				return ([
					"action":HIB+replace_string(replace_string(replace_string(action[j]["action"], "$w", "$W"), "$W", "$w"HIB), NOR, HIB)+NOR,
					"damage": 90+random(50),
					"damage_type": "割伤",
					"dodge": random(35),
					"parry": random(35),
					"force": 200+random(300),
				]);
			}
if(me->query_temp("baihong")){
		switch(me->query_temp("baihong")){						
 case 5: msg = HIW"\n$N聚起全身的内力化劲成焰，一招「"HIR"烈阳普照"NOR+HIW"」全身上下发出巨大的光芒，使$n有如陷入焚炉之中痛苦万分"NOR;break;
 case 4: msg = HIG"\n$N左手运劲内走奇经八脉化气成焰，右手逆转内劲气走丹田化为霜，使出「"HIB"阳盛阴衰"NOR+HIG"」，以强劲内力猛然攻击"NOR;break;
 case 3: msg = HIC"\n$N身法如鹰府冲而下使出「"HIY"阳歌天钧"NOR+HIC"」以诡异的身法游走$n的四方，趁其不备双手运勾朝$n脑门扑击而去"NOR;break;
 case 2: msg = HIM"\n$N使出「"HIW"春阳白雪"NOR+HIM"」，$N身形飞舞全身散发寒劲成霜，当场雪花漫天飞舞，$N趁机发动攻势偷袭使其受创"NOR; break;
 case 1: msg = HIC"\n$N聚劲双臂运劲成焰，凝聚强大的热量使出「"HIR"骄阳似火"NOR+HIC"」，烈焰掌劲侵入$n全身阵阵如火酷劲有如遭烈焰焚身"NOR; break;
default: msg = HIY"\n$N使出一招「"HIR"阳关三叠"NOR+HIY"」，以强劲的掌力以连绵不绝生生不息之力，犹如排山倒海之势朝$n周身奋然击去"NOR;break;
			
		}
		me->add_temp("baihong", -1);
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
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 50)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练六阳掌。\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
	        return __DIR__"liuyang-zhang/" + action;
}

mixed hit_ob(object me, object target, int damage_bonus)
{
	    int i,j;
	    i= me->query_skill("liuyang-zhang", 1);
	    j=1+random(1);
	    
      if(i>=200)
      {      
      if(userp(me)
      	&&random(me->query_dex(1))>target->query_dex(1)/2
        &&random(6)
      	&&!target->query_condition("shengsi_poison")
      	&&!me->query_temp("lyz/baihong")
       || (random(3)&&me->query_temp("xiaoyao_jianwu", 1))) 
      	 {
            message_vision(WHT"$N化水為冰，凝于掌中，輕飄飄地拍向$n周身大穴！\n"NOR,me,target);
            message_vision(BLU"$n也是微微一凉，但觉七处穴道中同时麻痒难当，直如千千万万只蚂蚁同时在咬啮一般。\n"NOR,me,target);
            target->add_condition("shengsi_poison",1);
          }
      }
     if (random(me->query_con(1))>target->query_con(1)/2
      	       &&random(3)
      	       &&!target->query_temp("absorb")
      	       &&!me->query_temp("lyz/baihong") || (random(3)&&me->query_temp("xiaoyao_jianwu", 1)))
      	   {
      	   	message_vision(HIB"$n一惊之下，急运内力挣扎，突觉内力自膻中急泄而出，全身便似脱力一般，更是惶恐无己！\n"NOR,me,target);
      	   	target->add("neili",-j);
      	   	target->start_busy(1+random(2));
      	   	me->add("neili",j);
      	   	target->set_temp("absorb",8);
      	  }
if( me->query_temp("xiaoyao_jianwu")&& me->query_skill("liuyang-zhang",1)>=550 ){ 
             target->add_condition("shengsi_poison",1);
                   target->add_busy(1+random(2));
             target->apply_condition("no_fight",1);
             target->apply_condition("no_perform",1);
             target->apply_condition("no_exert",1);
}
   
}


