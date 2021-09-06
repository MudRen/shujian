// wuyue-jianfa.c 五岳剑法
// Update by action@SJ 2009/1/10

inherit SKILL;
#include <ansi.h>
#include <combat.h>

string *msg = ({
"$N将$w在空中虚劈一剑，这一剑自上而下，只不过移动了两尺光景，但斗室中竟然嗡嗡之声大作",
"$N赞道：“很好！”木剑斜刺$n左胸，守中带攻，攻中有守，乃是一招攻守兼备的凌厉剑法。",
"$N$w挥转，指向$n右肩，仍是守中带攻、攻中有守的妙着",
"$n从未遇到过如此强敌，$N剑法中也并非没有破绽，只是招数变幻无方，无法攻其瑕隙",
"$N内力之强，剑术之精，两者混而为一，实已无可分割",
"$N接连数次已将$n迫得处于绝境，除了弃剑认输之外更无他法",
"$N心中惧意尽去，也可说全心倾注于剑法之中，更无恐惧或是欢喜的余暇",
"$N接连变换八门上乘剑法，有的攻势凌厉，有的招数连绵，有的小巧迅捷，有的威猛沉稳。",
"$N连连呼喝，竟似发了疯一般。呼喝越急，出剑也是越快",
"$n觉得他这路剑法也无甚奇处，但每一声断喝却都令$n双耳嗡嗡作响，心烦意乱，只得强自镇定，拆解来招",
});

string *feiyue_msg = ({
"$N剑随身转，续而刺出十九剑，竟然是华山「玉女十九剑」，但奇的是这十九剑便如一招，手法之快，直是匪夷所思",
"$N奇诡地向$n挥出「泉鸣芙蓉」、「鹤翔紫盖」、「石廪书声」、「天柱云气」及「雁回祝融」衡山五神剑",
"$N突然使出青城派松风剑法的「鸿飞冥冥」，可是方位却有所偏差，$w对着$n一绞，企图突破$n的攻势",
"$N剑招突变，使出衡山的「一剑落九雁」，削向$n的$l，怎知剑到中途，突然转向，大出$n意料之外",
"$N抱剑旋身，转到$n身后，杂乱无章地向$n刺出一剑，不知使的是什么剑法",
"却见$N身随剑走，左边一拐，右边一弯，剑招也是越转越加狠辣，竟化「泰山十八盘」为一剑攻向$n",
"$N剑势忽缓而不疏，剑意有余而不尽，化恒山剑法为一剑，向$n慢慢推去",
"$N突然运剑如狂，一手关外的「乱披风剑法」，猛然向$n周身乱刺乱削",
"$N剑意突焕气象森严，便似千军万马奔驰而来，长枪大戟，黄沙千里，尽括嵩山剑势击向$n",
"$N手中$w越转越快，使的居然是衡山的「百变千幻云雾十三式」，剑式有如云卷雾涌，旁观者不由得目为之眩",
"只见$N吐气开声，一招似是「独劈华山」，手中$w向下斩落，直劈向$n的$l",
"但见$N挺身而上，$w一旋，一招仿佛泰山剑法的「来鹤清泉」直刺$n的$l",
"$N随手一剑指向$n，落点正是$n的破绽所在，端的是神妙无伦，不可思议",
"$n窥准$N一招华山剑法「有凤来仪」的趋势，准备进行反击，却见$N突然虚步提腰，使出酷似武当「蜻蜓点水」的一招",
"$n攻向$N的$l，$N不退反进，使出恒山剑招「绵里藏针」，森森剑气充溢四周",
});
int valid_enable(string usage)
{
   if ( this_player()->query("quest/xixing")=="pass" )
		return (usage == "sword") || (usage == "parry") ;
}

int valid_learn(object me)
{
	mapping my_fam  = me->query("family");
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if(!my_fam || my_fam["master_name"] != "任我行")
		return notify_fail("你不是任我行的弟子，不能学习「五岳剑法」。\n");

	if ( me->query("max_neili") < 1000)
		return notify_fail("你的内力不够。\n");
	return 1;
}


mapping query_action(object me, object weapon)
{
	int i, j, level, damage;

	level = me->query_skill("wuyue-jianfa", 1);
	i = random(me->query_skill("sword"))+50;
	if( i<100 ) i = 100;
	j = random(40)-5;
	damage = (random(6)+1)*35;
	if( damage < 50 ) damage =50;

		if( level > 350 ) {
			return ([
        "action": WHT+replace_string(replace_string(feiyue_msg[random(sizeof(feiyue_msg))], "$w", "$w"), "$w", "$w"WHT)+NOR,
				"damage": 150 + random(120),
				"damage_type": "刺伤",
				"dodge":  random(20),
				"parry":  random(20),
				"force":  300 + random(250),

			]);
		}

		else return ([
			"action": msg[random(sizeof(msg))],
			"damage": 130 + random(140),
			"damage_type": "刺伤",
			"dodge":  random(30),
			"force":  250 + random(300),
		]);
	}

int practice_skill(object me)
{
	if ( me->query("jingli") < 50)
		return notify_fail("你的体力不够练五岳剑法。\n");
	if ( me->query("neili") < 20)
		return notify_fail("你的内力不够练习五岳剑法。\n");
	me->receive_damage("jingli", 40);
	me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"wuyue-jianfa/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	object weapon, weapon1;
	int i;
	weapon = me->query_temp("weapon");
	weapon1= victim->query_temp("weapon");

	if( !objectp(weapon) ) return;

	i = me->query_skill("wuyue-jianfa", 1);

   if(i>=350){
       if(random(i)>(int)victim->query_skill("parry",1)*2/3
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HIG"$N剑劲连绵，护住全身，竟无半分空隙，竟能如此毫无破绽，$n暗暗惊异！\n"NOR,me,victim);
            victim->set_temp("must_be_hit",1);
            call_out("wyjf_must_be_hit",2,me,victim,random(i/50));
       }
   }

   if(i>=250){
       if(random(i)>(int)victim->query_skill("dodge",1)/2
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HIR"$n从未遇到过如此强敌，$N剑法中也并非没有破绽，只是招数变幻无方，无法攻其暇隙！\n"NOR,me,victim);
            victim->set_temp("no_fight",1);
            victim->apply_condition("no_fight",1);
       }
   }    
}

void wyjf_must_be_hit(object me,object target,int i)
{
    if(!target) return;
    if(!me) {
        target->delete_temp("must_be_hit");
        if(living(target))
            message_vision(HIY"$n终于松了口气，手脚恢复了正常！\n"NOR,target);
        return;
    }
    if(wizardp(me) && me->query("env/dgjj_test")) write("i is "+i+"\n"NOR);
    if(me->query_skill_mapped("sword")!="wuyue-jianfa"
     ||me->query_skill_mapped("parry")!="wuyue-jianfa"
     ||i<=0){
        if(living(target))
            message_vision(HIY"$n终于松了口气，手脚恢复了正常！\n"NOR,me,target);
        target->delete_temp("must_be_hit");
        return;
    }
    call_out("wyjf_must_be_hit",1,me,target,--i);
}
