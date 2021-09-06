
// 新yinlong-bian.c 银龙鞭法
// By fengyue
#include <ansi.h>
inherit SKILL;

string  *msg = ({
"$N将$w抖动成圆，绕成一个个大大小小的圈子，登时将$n裹在其间,正是一招「圆转如意」！",
"$N的$w连连进击，忽然间鞭头倒卷而回，一招「银龙回首」鞭头对准$n$l砸了下来",
"$N运起内力一送，$w陡然变成笔直，锐利如枪，一式「银龙出洞」，向$n直刺过去",
"$N的$w犹似一条柔丝，竟如没半分重量，身子忽东忽西，忽进忽退，在$n身周飘荡不定，连连刺击",
"$N的$w便如灵蛇颤动，直奔$n胸口。$n奔身闪避，那$w却从半路弯将过来，将$n圈在其内",
"$N身形一闪一晃，疾退数丈，$w从右肩急甩向后，陡地鞭头击向$n面门,正如天外游龙，矢矫而至",
"蓦地里青影闪动，$w迎面击来，迅速无伦，$n身形急退，却不料$N招式奇幻，一不留神便被圈住",
});

int valid_enable(string usage)
{ 
	return usage == "whip" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
        if((int)me->query_skill("yinlong-bian",1)>=450)
        return ([
                "action":HIC +replace_string(replace_string(msg[random(sizeof(msg))], "$w", "$w"), "$w", "$w"HIC)+NOR,
                "damage":       150 + random(150),
                "damage_type":  "拉伤",
                "dodge":        10+random(30),
                "force":        random(300) + 200,
                "parry":        random(30),
            ]);
        else

        if((int)me->query_skill("yinlong-bian",1)>=350)
        return ([
                "action":HIC +replace_string(replace_string(msg[random(sizeof(msg))], "$w", "$w"), "$w", "$w"HIC)+NOR,
                "damage":       120 + random(100),
                "damage_type":  "拉伤",
                "dodge":        10+random(30),
                "force":        random(300) + 200,
                "parry":        random(30),
            ]);
        else
	return ([
		"action":	msg[random(sizeof(msg))],
		"damage":	100 + random(120),
		"damage_type":	"拉伤",
		"dodge":	random(30),
		"force":	random(300) + 150,
		"parry":	random(30),
       ]);
}

int valid_learn(object me)
{
	object weapon;
	if( (int)me->query("max_neili") < 1500 )
		return notify_fail("你的内力不足，没有办法练银龙鞭，多练些内力再来吧。\n");
	if ((int)me->query_skill("whip", 1) < 100)
		return notify_fail("你的先打好基础再练吧。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	 || ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("你使用的武器不对。\n");
	return 1;
}
 
int practice_skill(object me)
{
	if ((int)me->query("jingli") < 60)
		return notify_fail("你的体力不够练九阴银龙鞭。\n");
	if ((int)me->query("neili") < 30 )
		return notify_fail("你的内力不够练九阴银龙鞭。\n");
	me->receive_damage("jingli", 50);
	me->add("neili",-20);
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	object weap,weap1;
	int ap, dp;
	weap = victim->query_temp("weapon");
	weap1 = me->query_temp("weapon");

	if( !me->query("env/no_chan")
	 && me->query_skill("yinlong-bian", 1) > 120
	 && me->query("neili") > 700
	 && victim->query_temp("weapon")
	 && random(me->query_skill("yinlong-bian",1)) > victim->query_skill("dodge", 1)/2 
	 && random(10) > 3) {
		message_vision(HIC"只见$N"+ weap1->name() + HIC"急速抖动，绕成转出无数个大小圈子，登时将" + weap->name() +HIC"卷在其间！\n" NOR, me );
		victim->add_busy(1);
		ap = me->query("combat_exp", 1) /1000 * me->query_str(1);
		dp = victim->query("combat_exp", 1) /1000 * victim->query_str(1);
		if (random(ap + dp ) > dp ) {
			message_vision(HIY"$N劲力被这么一带，登时身不由主，连转了几个七八个圈子，"+ weap->name()+ HIY"脱手而出。\n" NOR, victim );
			weap->move(environment(me));
			victim->reset_action();
		}
		else {
			message_vision(HIY"$N暗运巧劲，"+ weap->name()+ HIY"顺着方向快速旋转数下，解开了"+weap1->name()+HIY"的缠绕。\n" NOR, victim );
			victim->add("neili", -50);
		}
		me->add("neili", -(20+random(30)));
	}
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yinlong-bian/" + action;
}

