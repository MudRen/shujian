#include <ansi.h>
inherit SKILL;
mapping *action = ({
([
	"action" : HIW"$N势若疯虎，形若邪魔，双爪如钢抓铁钩，左手手腕翻处，右手疾伸，五根手指抓向$n$l"NOR,
	"lvl" : 0,
	"damage_type" : "抓伤"
]),
([
	"action" : HIW"突然人影闪动，$N迫到$n身后，袖中伸出手，五根手指向$n$l插了下去"NOR,
	"weapon" : "五指",
	"lvl" : 10,
	"damage_type" : "刺伤"
]),
([
	"action" : HIW"$N手臂关节喀喇一响，手臂斗然长了半尺，一掌按在$n$l，五指即要插进$n的$l"NOR,
	"weapon" : "手指",
	"lvl" : 20,
	"damage_type" : "刺伤"
]),
([
	"action" : HIW"$N双手微张，十根尖尖的指甲映出灰白光芒，突然翻腕出爪，五指猛地插落"NOR,
	"weapon" : "手爪",
	"lvl" : 30,
	"damage_type" : "刺伤"
]),
([
	"action" : HIW"$N左手突然在$n眼前上围下钩，左旋右转，连变了七八般，蓦地里右手一伸，五根手指直插$n$l"NOR,
	"weapon" : "五根手指",
	"lvl" : 40,
	"damage_type" : "刺伤"
]),
([
	"action" : HIW "$N左爪虚晃，右爪蓄力，一招" HIR "「勾魂夺魄」" HIW "直插向$n的$l" NOR,
	"lvl"   : 100,
	"skill_name" : "勾魂夺魄" ,
	"damage_type" : "抓伤"
]),
([
	"action" : HIW "$N双手连环成爪，爪爪钩向$n，" HIR "「九子连环」" HIW "已向$n的$l抓出" NOR,
	"lvl"   : 120,
	"skill_name" : "九子连环" ,
	"damage_type" : "抓伤"
]),
([
        "action" : HIW "$N身形围着$n一转，使出" HIR "「天罗地网」" HIW "，$n的$l已完全笼罩在爪影下" NOR,
	"lvl"   : 140,
	"skill_name" : "天罗地网" ,
	"damage_type" : "抓伤"
]),
([
	"action" : HIW "$N使一招" HIR "「风卷残云」" HIW "，双爪幻出满天爪影抓向$n全身" NOR,
	"lvl"   : 160,
	"skill_name" : "风卷残云" ,
	"damage_type" : "抓伤"
]),
([
	"action" : HIW "$N吐气扬声，一招" HIR "「唯我独尊」" HIW "双爪奋力向$n天灵戳下" NOR,
	"lvl"   : 180,
	"skill_name" : "唯我独尊" ,
	"damage_type" : "抓伤"
]),
});

int valid_enable(string usage)
{ 
	return usage=="claw" || usage=="parry" ;
}

int valid_learn(object me)
{
	if( (int)me->query_skill("jiuyin-shenzhua", 1 ) < 140 )
		return notify_fail("你现在不能学习九阴神爪。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练九阴神爪必须空手。\n");
	if ((int)me->query_skill("claw", 1) < 50)
		return notify_fail("你的基本爪功火候不够，无法学习。\n");
	if ((int)me->query_skill("jiuyin-zhengong", 1) < 50)
		return notify_fail("你的九阴真功火候不够，无法学习。\n");
	if ((int)me->query_skill("jiuyin-baiguzhua", 1) > 1)
		return notify_fail("你学了九阴白骨抓，无法学习九阴神爪。\n");
	if ((int)me->query_skill("daode-jing", 1) < 50)
		return notify_fail("你的道学心法火候不够，无法学习。\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力太弱，无法练九阴神爪。\n");
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
	int i, level, j;
	level   = (int) me->query_skill("jiuyin-shenzhua",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level >= action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action":	action[j]["action"],
				"weapon":	action[j]["weapon"],
				"lvl":		action[j]["lvl"],
				"damage_type":	action[j]["damage_type"],
				"force":	300 + random(350),
				"dodge":	random(30),
				"parry":	random(30),
			]);
		}
	}
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 60)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的内力不够练九阴神爪。\n");
	me->receive_damage("jingli", 50);
	me->add("neili", -20 );
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jiuyin-shenzhua/" + action;
}



mixed hit_ob(object me, object victim, int damage)
{
  

        int lvl = me->query_skill("claw"),attack,lb;
        attack=lvl/100;
        if(attack>=4) attack=4;
          	attack=random(attack);
        if(attack<=1) attack=1;
        lb = random(10);
       
 if( !me->query_temp("9ysz/auto")  )
   	
   	{  

 		 if(  lb> 7 ||  me->query_temp("sz3j")==1 ) 
          {
                message_vision(HBBLU "正当$n旧力已尽、新力未生之时，$N忽地乘隙而进，右手箕张，五指插向$n头顶！" NOR,me,victim);
                victim->start_busy(random(4));
                         me->set_temp("9ysz/auto", 1);
                         me->add_temp("apply/damage",  me->query_skill("jiuyin-shenzhua", 1)/6);
                         COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(2)?1:3);
                        me->add_temp("apply/damage", -me->query_skill("jiuyin-shenzhua", 1)/6);
                        me->delete_temp("9ysz/auto");
                        victim->apply_condition("no_perform", 2+ random(2));

         }
 
   else if(  lb> 5 ||  me->query_temp("sz3j")==2 ) 
 {
        	message_vision(HBRED "$N连转了几个身，忽的青光一闪，手臂暴涨，指爪如短剑般闪烁着凛冽的寒光，对准$n天灵盖猛的插了下去。" NOR, me,victim);
        	victim->start_busy(random(2));
                   me->set_temp("9ysz/auto", 1);
                         me->add_temp("apply/damage",  me->query_skill("jiuyin-shenzhua", 1)/6);
                         COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(2)?1:3);
                        me->add_temp("apply/damage", -me->query_skill("jiuyin-shenzhua", 1)/6);
                        me->delete_temp("9ysz/auto");

        }

   else if( lb>3 || me->query_temp("sz3j")==3 )
{
        	message_vision(HBMAG "$N长身便扑，双手指甲尖利，猛的向$n的喉咙抓去，眼看一个疏忽之下便要拧断$n的喉咙。" NOR,me, victim);
                    	victim->start_busy(random(attack+1));
                      me->set_temp("9ysz/auto", 1);
                         me->add_temp("apply/damage",  me->query_skill("jiuyin-shenzhua", 1)/6);
                         COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(2)?1:3);
                        me->add_temp("apply/damage", -me->query_skill("jiuyin-shenzhua", 1)/6);
                        me->delete_temp("9ysz/auto");
 
}

}

}
