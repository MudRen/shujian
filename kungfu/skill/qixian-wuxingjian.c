// qixian-wuxingjian.c
// modified by action@SJ 2009/1/10
//updated by Zmud@Sjmud 10/3/2009

#include <ansi.h>
#include <skill.h>

inherit SKILL;

string *xue_name = ({ 
"劳宫穴", "膻中穴", "曲池穴", "关元穴", "曲骨穴", "中极穴", "承浆穴", "天突穴", "百会穴",
"幽门穴", "章门穴", "大横穴", "紫宫穴", "冷渊穴", "天井穴", "极泉穴", "清灵穴", "至阳穴", }); 

string  *msg = ({
"$N使一招「弦外有音」，手中$w弹出一股气流，如风一般卷向$n的$l",
"$N伸指在$w上一弹，一招「吴阳琴音」，整个剑身顿时发出一声龙吟，呼啸着斩向$n的$l",
"$N一招「天河紫气」，手中$w剑芒顿时暴长数尺，光华四射，直直削向$n的$l",
"$N手中$w一式「七盘绝刹」对准$n的$l一连刺出数剑，刹时剑气纵横，势不可挡",
"$N的$w凭空一指，一招「黄龙吐珠」直直刺出，剑尖陡然生出半寸吞吐不定的青芒刺向$n的$l",
"$N手中$w向外一分，使一招「清心普善」，单手在剑身轻轻弹拨，顿时一股剑气直涌$n$l而去",
"$N忽然眼中精光四射，一招「星河气旋」，一股淳厚无比的剑气从$w上激射而出，直逼$n",
});

string *feiyue_msg = ({
"$N左小指轻弹，一招宫韵悄然划向$n的后心，$w不住颤抖，向$n$l刺去",
"$N右手无名指若有若无的一划，将琴弦并做一处，商韵已将$n笼罩住在剑气之中",
"$N五指疾挥，一式角韵无形的刺向$n的左肋，忽然又$N一个转身，又向$n右肋刺去",
"$N将手中剑横扫，同时左右手如琵琶似的疾弹，正是一招支韵，感觉妩媚无比",
"$N使出羽韵，将剑提至唇边，如同清音出箫，剑掌齐出，划向$n的$l",
"$N的脸色变了，人剑一合，使出羽韵，$N手中又多了一柄剑，猛地向$n刺去",
"$N使一招宫韵，手中$w弹出一股气流，如风一般卷向$n的$l，招式极为飘逸",
"$N伸指在$w上一弹，一招商韵，整个剑身顿时发出一声龙吟，呼啸着斩向$n的$l",
"$N一招角韵，手中$w剑芒顿时暴长数尺，光华四射，直直削向$n的$l，$n已然无法躲避",
"$N手中$w一式角韵对准$n的$l一连刺出数剑，刹时剑气纵横，势不可挡，犹如狂风骤雨",
"$N的$w凭空一指，一招支韵直直刺出，剑尖陡然生出半寸吞吐不定的青芒刺向$n的$l",
"$N手中$w向外一分，使一招羽韵，单手在剑身轻轻弹拨，顿时一股剑气直涌$n$l而去",
"$N忽然眼中精光四射，一招宫韵，一股淳厚无比的剑气从$w上激射而出，直逼$n",
});

int valid_enable(string usage)
{
	if (this_player()->query("quest/xxdf/pass")) return usage == "sword" || usage == "parry";
}

int practice_skill(object me)
{
	if( (int)me->query("jingli") < 50 || me->query("neili") < 20 )
		return notify_fail("你的体力不够练七弦无形剑。\n");

	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

int valid_learn(object me)
{
	mapping fam  = me->query("family");
	object weapon = me->query_temp("weapon");

	if( !weapon || weapon->query("skill_type") != "sword" )
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query("max_neili") < 800 )
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_skill("xixing-dafa", 1) < 200 )
		return notify_fail("你的吸星大法火候太浅。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, j, level, damage;
	string str;

	level = me->query_skill("qixian-wuxingjian", 1);
	i = random(me->query_skill("sword"))+50;
	if( i<100 ) i = 100;
	j = random(40)-5;
	damage = (random(6)+1)*35;
	if( damage < 50 ) damage =50;
		
	if(me->query_temp("guangling")){
		switch(me->query_temp("guangling")){
			case 3: str = HIB"$N心头灵光一现，忽然明白了广陵散的精髓所在，「"HIM"广陵散曲"HIB"」旋即向$n使出，将「七弦无形剑」绝技发挥的淋漓尽致"NOR; break;
			case 2: str = MAG"$n欲退不能，立即被卷入$N的剑光之中，$n只感觉$N手中$w"MAG"不断发出震耳欲聋的颤音，$n不由全身寒意突发"NOR; break;
			case 1: str = HIR"$N这$w"HIR"上的招数却和琴音恰正相反，$N出招快速而琴音却加倍悠闲，$n势必无法招架，此招功夫非同小可，威力极强"NOR; break;
		 default: str = HIR"$N这$w"HIR"上的招数却和琴音恰正相反，$N出招快速而琴音却加倍悠闲，$n势必无法招架，此招功夫非同小可，威力极强"NOR; break;
		}
		me->add_temp("guangling", -1);
		return ([
			"action":str,
                        "damage": 220 + random(150),
			"damage_type": "刺伤",
			"dodge": random(30),
			"parry": random(30),
			"force": 350 + random(250),
		]);
	}

		if( level > 450 ) {
			return ([
        "action": WHT+replace_string(replace_string(feiyue_msg[random(sizeof(feiyue_msg))], "$w", "$w"), "$w", "$w"WHT)+NOR,
				"damage": 120 + random(120),
				"damage_type": "刺伤",
				"dodge":  random(20),
				"parry":  random(20),
				"force":  300 + random(250),

			]);
		}

		else return ([
			"action": msg[random(sizeof(msg))],
			"damage": 100 + random(100),
			"damage_type": "刺伤",
			"dodge":  random(30),
			"force":  250 + random(300),
		]);
	}
	
string perform_action_file(string action)
{
	return __DIR__"qixian-wuxingjian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	object weapon, weapon1;
	string name;
	int i;
	weapon = me->query_temp("weapon");
	weapon1= victim->query_temp("weapon");

	if( !objectp(weapon) ) return;

	i = me->query_skill("qixian-wuxingjian", 1);

   if(i>=350){
       if(random(i)>(int)victim->query_skill("parry",1)*2/3
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HIG"\n$N剑劲连绵，护住全身，竟无半分空隙，竟能如此毫无破绽，$n暗暗惊异！\n"NOR,me,victim);
            victim->set_temp("must_be_hit",1);
            call_out("qxwxj_must_be_hit",2,me,victim,random(i/50));
       }
   }

   if(i>=250){
       if(random(i)>(int)victim->query_skill("dodge",1)/2
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HBRED"\n$n从未遇到过如此强敌，$N剑法中也并非没有破绽，只是招数变幻无方，无法攻其暇隙！\n"NOR,me,victim);
            victim->set_temp("no_fight",1);
            victim->apply_condition("no_fight",1);
       }
   }  
   if(i>=300){
       if(random(i)>(int)victim->query_skill("dodge",1)/2
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HIW"\n$N手腕一震，将体内的无形剑气发动，配合一阵淡淡的琴音侵入$n的全身穴脉！\n"NOR,me,victim);
            victim->set_temp("no_fight",1);
            victim->apply_condition("no_fight",1);
            victim->start_busy(1+random(1));
       }
   }  
   
   name = xue_name[random(sizeof(xue_name))];
   if(i>=400){
   	if(random(i)>(int)victim->query_skill("dodge",1)/3
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HIB "\n只听一阵淳厚的弦音从" + weapon->name() +HIB "处传来，$n" HIY "『" + name + "』"
                       NOR + HIB "顿时受震，两耳轰鸣，全身真气乱窜不止！\n" NOR,me,victim);
            victim->set_temp("no_fight",1);
            victim->start_busy(1+random(2));
            victim->apply_condition("no_fight",1);
       }
   }  
   	 
}

void qxwxj_must_be_hit(object me,object target,int i)
{
    if(!target) return;
    if(!me) {
        target->delete_temp("must_be_hit");
        if(living(target))
            message_vision(HIY"$n终于松了口气，手脚恢复了正常！\n"NOR,target);
        return;
    }
    if(wizardp(me) && me->query("env/qxwxj_test")) write("i is "+i+"\n"NOR);
    if(me->query_skill_mapped("sword")!="qixian-wuxingjian"
     ||me->query_skill_mapped("parry")!="qixian-wuxingjian"
     ||i<=0){
        if(living(target))
            message_vision(HIY"$n终于松了口气，手脚恢复了正常！\n"NOR,me,target);
        target->delete_temp("must_be_hit");
        return;
    }
    call_out("qxwxj_must_be_hit",1,me,target,--i);
}
