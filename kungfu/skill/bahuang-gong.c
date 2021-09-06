// bahuang-gong.c 八荒六合唯我独尊功
// bahuang-gong.c
#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { 
	  if (this_player()->query("family/family_name")=="灵鹫宫" || this_player()->query("cw_mp/灵鹫宫") )
return usage == "force"; }

#include "force.h"

int valid_learn(object me)
{
		mapping fam  = me->query("family");
	if ((!fam || fam["family_name"] != "灵鹫宫" )&& !me->query("cw_mp/灵鹫宫") )
			 	return notify_fail("你并非天山灵鹫宫弟子，如何习得了八荒六合唯我独尊功。\n");
		
	if ( me->query("gender") == "无性")
		return notify_fail("你无根无性，阴阳不调，难以领会高深的八荒六合唯我独尊功。\n");

	if ((int)me->query_skill("bahuang-gong", 1) > me->query_skill("force", 1) + 10
	 && me->query_skill("bahuang-gong", 1) >= 200 )
		return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	if((int)me->query_skill("bahuang-gong", 1) >= 200 ){
		if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200){
			me->improve_skill("bahuang-gong", (int)me->query_int());
			me->add("neili", -100); 
			me->add("potential", -1*(1+random(3)));
			return 1;
		}
		else return notify_fail("你现在的修为不足以提高八荒六合唯我独尊功了。\n");
	}
	else return notify_fail("你现在的八荒六合唯我独尊功修为只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return SKILL_D("bahuang-gong/") + func;
}

mapping exercise_msg(object me)
{
	return ([
		"status_msg" : me->name() +"盘膝而坐，鼻孔中两道红色气团缭绕，面色红白变幻。" ,
                "start_my_msg" : "你盘膝而坐，运起八荒六合唯我独尊功，丹田真气升腾而起，开始打坐。\n",
		"start_other_msg" : "只见"+ me->name() +"鼻孔中两道白气循环缭绕，头顶汗气蒸腾。\n",
		"end_my_msg" : "你只觉真力运转顺畅，周身气力充沛，气沉丹田，站起身来。\n",
		"end_other_msg" : me->name() +"收起鼻孔间的白气，精神抖擞，站起身来。\n",
	]);
}
