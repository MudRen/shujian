//慈航鞭,
//取自普明禅师<牧牛图颂>
//cool@SJ,990420

#include <ansi.h>

inherit SKILL;

string *body_name = ({ 
"左手腕","左胳膊","脖子","头部","腰部","左腿","小腿","左脚脚腕","右手腕","右胳膊","右腿","右脚脚腕",}); 

mapping *action = ({
([
	"action": "$N双手合什，内力灌注, 一式「未牧」，腰间$w似有灵性，忽地一转，卷向$n的$l",
	"skill_name" : "未牧",
	"lvl": 0,
	"damage_type":  "拉伤",
]),
([
	"action": "$N沉肩滑步，手中$w一抖，一式「初调」，迅捷无比地分打左右两侧，$n顿时左右支绌，慌了手脚",
	"skill_name" : "初调",
	"lvl": 20,
	"damage_type":  "拉伤"
]),
([
	"action": "$N将内力注入$w，蓦地使出一式「受制」，$w矫夭飞舞，直如神龙破空一般抽向$n",
	"skill_name" : "受制",
	"lvl": 40,
	"damage_type":  "拉伤"
]),
([
	"action": "$N一声清啸，手中$w一招「回首」，划出漫天鞭影铺天盖地地向$n卷来，势道猛烈之极",
	"skill_name" : "回首",
	"lvl": 60,
	"damage_type":  "拉伤"
]),
([
	"action": "$N急速旋绕手中$w，一式「驯服」，挥出无数旋转气流向$n逼去 ",
	"skill_name" : "驯服",
	"lvl": 80,
	"damage_type":  "拉伤"
]),
([
	"action": "$N身体凌空飞起，右手大力挥出$w，一式「无碍」，一股排山倒海的鞭风直击向$n",
	"skill_name" : "无碍",
	"lvl": 100,
	"damage_type":  "拉伤"
]),
([
	"action": "$N面露微笑跨前一步，右手$w轻扬，使出一式「任运」，鞭势平和中正，不带丝毫霸气",
	"skill_name" : "任运",
	"lvl": 120,
	"damage_type":  "拉伤"
]),
([
	"action": "$N向前急进，双手握住$w，缓缓使出一式「相望」，鞭势沉稳, 一股劲风破空而起",
	"skill_name" : "相望",
	"lvl": 140,
	"damage_type":  "拉伤"
]),
([
	"action": "$N狂舞手中$w，一式「独照」，鞭若蛟龙, 盘旋飞舞",
	"skill_name" : "独照",
	"lvl": 160,
	"damage_type":  "拉伤"
]),
([
	"action": "$N身体螺旋飞舞，手中$w突然挥出，使出一式「双泯」，鞭势犹如雨中闪电,气势惊人",
	"skill_name" : "双泯",
	"lvl": 180,
	"damage_type":  "拉伤"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 800 )
		return notify_fail("你的内力不足，没有办法练习鞭法, 多练些内力再来吧。\n");

	if ((int)me->query_skill("kurong-changong", 1) < 100)
		return notify_fail("你的枯荣禅功修为不够。\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	 ||( string)weapon->query("skill_type") != "whip" )
		return notify_fail("你必须先找一条鞭子才能练鞭法。\n");
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
	string msg;
	level = (int) me->query_skill("cihang-bian",1);

	if(me->query_temp("chb")){
		switch(me->query_temp("chb")){
			case 3: 
				         msg =HIY"$N高宣“阿弥陀佛！”，使出「慈悲」字诀，手中长索一扬，向$n的咽喉点去，\n";
                       msg +="索头未到，索上所挟劲风犹如红日当空，令对方一阵气窒，只听见「啪啪」几声巨响，\n";
                       msg +="索头昂起，便如一条假死的毒蛇忽地反噬挥动，带动无数风沙，呼啸而出。"NOR;
				break;
		  case 2:         msg =HIW"$N又宣“我佛慈悲！”，又使出「慈悲」字诀，内力返照空明，功力精纯，不露棱角，\n";
                             msg +="手中长索舞动时瞧不见半点影子无声无息，似缓实急，却又大开大阔，如天神，说不尽的莫测高深。"NOR;

				break;
			
			
			case 1: msg = HIW"$N高宣“我佛慈悲！渡世渡人！”，使出「慈悲」诀，内力返照空明，功力精纯。手中长索一扬，带动无数风沙，呼啸而出。"NOR; break;
			
			
			default: msg = HIW"$N高宣“我佛慈悲！渡世渡人！”，使出「慈悲」诀，内力返照空明，功力精纯。手中长索一扬，带动无数风沙，呼啸而出。"NOR; break;
		}
		me->add_temp("chb", -1);
		return ([
			"action":	msg,
			"damage_type": 	"拉伤",
			"damage": 	130 +random(140),
			"dodge": 	random(30), 
			"parry": 	random(30),
			"force": 	250 + random(350),
		]);
	}
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action":	action[j]["action"],
				"damage_type": 	action[j]["damage_type"],
				"skill_name" : 	action[j]["skill_name"],
				"lvl":		action[j]["lvl"],
				"damage": 	80 + random(140),
				"dodge": 	random(30)-10,
				"force": 	200 + random(350),
				"parry":	random(20),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("cihang-bian", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 50)
		return notify_fail("你的体力不够练慈航鞭法。\n");
	if ( me->query("neili") < 20)
		return notify_fail("你的内力不够练慈航鞭法。\n");
	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	object weap,weap1;
        
	weap = victim->query_temp("weapon");
	weap1 = me->query_temp("weapon");

	if( random(me->query_skill("cihang-bian", 1)) > 150
	 && me->query("neili") > 100
	 && random(10) > 7 
	 && !me->query_temp("chb")){
		if ( weap ){
			message_vision(HIY "只见$N急速挥舞" + weap1->name() + HIY"，转出无数个大小圈子，以阴柔之劲缠住对方的" + weap->name() +HIY"！\n" NOR, me );
			if (random(me->query_skill("parry", 1)) > victim->query_skill("parry", 1)/2 ) {
				message_vision(HIY "$N气运手臂用力一拽，" + weap->name() + HIY"却无法从"+weap1->name()+HIY"的缠绕中脱开，情急之下只好放弃了手中的兵刃。\n" NOR, victim );
				weap->unequip();
				weap->move(environment(me));
				victim->reset_action();
			}
			else {
				message_vision(HIY "$N暗运巧劲，" + weap->name()+ HIY"顺着方向快速旋转数下，解开了"+weap1->name()+HIY"的缠绕。\n" NOR, victim );
				victim->add("neili",-20);
			}
			me->add("neili", -30);
		}
		else {
			if ( random(me->query_skill("parry", 1)) > victim->query_skill("parry", 1)/2 
			&& !random(5) 
			&& !victim->is_busy() ) {
				victim->start_busy(random(3)+ 1);
				me->add("neili",-80);
				victim->receive_damage("qi", damage_bonus/2, me);
				victim->receive_wound("qi", damage_bonus/4, me);     
				message_vision(HIY"只见$N的鞭式灵动异常，"+ weap1->name() + HIY"转出无数个大小圈子，以阴柔之劲缠住了对方的"
					+ body_name[random(sizeof(body_name))] +"！\n" NOR, me);
	               		message_vision(HIR"$N身形一缓,似乎受了点伤。\n" NOR, victim );    
	           	}
	        }
	}
	return 0;
}

string perform_action_file(string action)
{
	return __DIR__"cihang-bian/" + action;
}
