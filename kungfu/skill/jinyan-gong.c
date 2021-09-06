// jinyan-gong.c 金雁功
// Modified by action@SJ 2008/09/15


inherit SKILL;
 
string *dodge_msg = ({
"$n微一侧身，轻轻向前一纵，一式「北雁南飞」，轻描淡写地躲过$N的一击。\n",
"$n一式「雁去无痕」，长身而起飘然后退，$N一击不中，$n已落在丈许之外。\n",
"$n虚步前跨，脚踩七星方位，由天玑至玉衡，一招「斗转星移」已然绕到$N身后。\n",
"$n微微一笑，足不动，身不摆，一式「神游太虚」如清烟般冉冉而起，滑向$N左侧。\n",
"$n身形突变，使出「群星灿烂」，围绕$N四处游走顿时幻化出无数人影，$N目瞪眼呆不知击向何处。\n",
"$n身子如陀螺般急速旋转起来，一招「横空出世」将$N的攻势统统化解。\n",
"$n一式「如影随行」，衣袂飘飘，随着$N的走势而动，在$N大惊之下$n已飘然滑开！\n",
"$n使出「上天梯」身体斗然拔起，越升越高，空中微一转折落在数丈之外，将$N的攻势尽数化于无形！\n"
});
int valid_enable(string usage) 
{ 
	return usage == "dodge";
}

int valid_learn(object me)
{
	if ( me->query_skill("xiantian-gong", 1) < 10)
		return notify_fail("你的先天功等级太低了。\n");
	return 1; 
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( me->query("jingli") < 30 )
		return notify_fail("你的体力太差了，不能练金雁功。\n");
	me->receive_damage("jingli", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jinyan-gong/" + action;
}