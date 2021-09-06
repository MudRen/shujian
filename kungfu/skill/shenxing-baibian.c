//shenxing-baibian.c
// By action@SJ 2009/2/15
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
"$n一式「行云流水」，身不倾，脚不移，身体如行云流水般直滑出丈余。\n",
"$n一式「潜音夜行」，忽然一弯腰，全身贴地而行，顿时闪过了$N的凌厉攻势。\n",
"$n一式「移步换形」，足不动，手不抬，一转眼间便绕到了$N的身后!\n",
"$n一式「分身化影」，一转身间，四面八方飘动着无数个$n的身影，令$N手足无措。\n",
"$n一式「临行秋波」，身行倏的从$N的眼前直绕到身后，$N瞪大了两眼，不明所以。\n",
"$n一式「更上层楼」，身在空中，左脚在右足上一点，从$N头顶腾空而过。\n",
"$n一式「仙子出水」，长袖一拂，全身化为一道白影，幽幽地从$N头顶飘落。\n",
"$n一式「峰回路转」，身体如陀螺般急转，登时一股气流涌出，令$N难以动弹。\n",
});

int valid_enable(string usage)
{
	return usage == "dodge";
}

int valid_learn(object me)
{
	if ( me->query_skill("dulong-dafa", 1) < 10)
		return notify_fail("你的毒龙大法等级太低了。\n");
	return 1; 
}

string query_dodge_msg()
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("jingli") < 30 )
		return notify_fail("你的体力太差了，不能练神行百变。\n");
	me->receive_damage("jingli", 25);
	return 1;
}

string perform_action_file(string action)
{       
	return __DIR__"shenxing-baibian/" + action;
}


