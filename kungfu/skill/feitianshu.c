// feitianshu.c 飞天术
inherit SKILL;
string *dodge_msg = ({
"$n身形一晃，纤腰一扭，一招「倒挂悬檐」，弹地而起。\n",
"$n一招「神行鬼魅」，$N只觉眼前一花，不见了$n的身影。\n",
"$n一招「蝙蝠飞天」，身形微晃，有惊无险地避开了$N这一招。\n",
});

string query_dodge_msg(object me)
{	
	return dodge_msg[random(sizeof(dodge_msg))];

}

int valid_enable(string usage)
{ 
	return usage == "dodge"; 
}

int valid_learn(object me)
{ 
	return 1; 
}

int practice_skill(object me)
{
	if( (int)me->query("jingli") < 45 )
		return notify_fail("你的体力太差了，不能练飞天术。\n");	
	me->receive_damage("jingli", 35);	
	return 1;
}
