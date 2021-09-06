// huashan-neigong.c 华山内功

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{

		mapping fam  = me->query("family");
	int i = (int)me->query_skill("huashan-qigong", 1);


	if (!fam || fam["family_name"] != "华山派" )
			 	return notify_fail("你并非华山派弟子，如何习得了华山气功。\n");


	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");
	if ((int)me->query("shen") < (int)pow(i/10, 2) * 100)
		return notify_fail("你的神太低了。\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("太极气功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return SKILL_D(__DIR__"taiji-qigong/") + func;
}

