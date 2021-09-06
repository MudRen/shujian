// piaomiao-shenfa.c 缥缈身法
// written by action
//modified by zhuifeng@SJFY

inherit SKILL;

string *dodge_msg = ({
"$n足下一个踉跄，乘势向左斜出半步，恰符合了凌波微步中「忽焉纵体」的步子，闪了开来。\n",
"$n使出「流风回雪」歪歪斜斜退了几步，似乎不成章法，却在间不容缓的空隙中躲过了$N的攻势。\n",
"$N的招式明明可以把$n围住，不知怎的，$n一式「轻云蔽月」，又如鬼魅般的跨出了圈外。\n",
"$n一式「以遨以嬉」，瞻之在前，忽焉在后，$N招式的落点和$n身子间总有厘毫之差。\n",
"$n大喝一声，使出「乍阴还阳」，左足向右踏出，不料踏实之时，身子已在西北角上。\n",
"$n身形闪处，突然转向，使出了「神光离合」，$N加紧攻势，竟无法碰到$n一片衣角。\n",
"$n一式「飘忽若神」，侧身斜进，抢步“既济”，立闪“未济”，闪得几闪，已欺到$N的身后。\n",
"$n一式「体迅飞枭」，似乎自管自地踏步，毫不理会，每一步都踏在别人意想不到的所在。\n",
});

int valid_enable(string usage)
{
	return usage == "dodge";
}

int valid_learn(object me)
{
        if ( me->query_skill("beiming-shengong", 1) < 10 && me->query_skill("xixing-dafa", 1)<10 )
		return notify_fail("你的北冥神功等级太低了。\n");
	return 1; 
}

string query_dodge_msg()
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("jingli") < 30 )
		return notify_fail("你的体力太差了，不能练缥缈身法。\n");
	me->receive_damage("jingli", 25);
	return 1;
}

string perform_action_file(string action)
{       
	return __DIR__"piaomiao-shenfa/" + action;
}

