//Cracked by Roath
// wuxingbu.c 
//kane

inherit SKILL;

mapping *action = ({
([	"action" : "$n一个「旱地拔葱」，向上窜起数尺，避过$N攻击。\n",
	"dodge"  : 10
]),
([	"action" : "$n一个「鹞子翻身」，凌空一个侧翻，闪过了$N的凌厉攻势。\n",
	"dodge"  : 20
]),
([	"action" : "$n见势不妙，不得以使招「懒驴打滚」，往地上一滚，躲过$N的攻击。\n",
	"dodge"  : 30
]),
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("wuxingbu");

	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
	return usage == "dodge";
}

string query_dodge_msg(string limb)
{
        return action[random(sizeof(action))]["action"];
}

int practice_skill(object me)
{
	if (me->query("jingli") < 30 )
		return notify_fail("你现在的精力太差了，不能练习五行步法。\n");
	me->receive_damage("jingli", 30);
	return 1;
}
