#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

#include "/kungfu/skill/force.h"

int valid_learn(object me)
{
	if ( me->query("gender") == "无性")
		return notify_fail("你无根无性，阴阳不调，难以领会高深的天魔功。\n");

        if ((int)me->query_skill("tianmo-gong", 1) > me->query_skill("force", 1) + 10
          && me->query_skill("tianmo-gong", 1) >= 200 )
               return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");

        return valid_public(me);
}

int practice_skill(object me)
{
       if((int)me->query_skill("tianmo-gong", 1) >= 200 )
       {
           if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200)
           {
                   me->improve_skill("tianmo-gong", (int)me->query_int());
                   me->add("neili", -100); 
                   me->add("potential", -1*(1+random(3)));
                   return 1;
           }
           else return notify_fail("你现在的修为不足以提高天魔功了。\n");       }
        else return notify_fail("你现在的天魔功修为只能用学(learn)的来增加熟练度。\n");

}
void skill_improved(object me)
{
        int skill, lit;
        skill = me->query_skill("tianmo-gong", 1);
        lit = me->query_skill("literate", 1);
        if(skill >= 300 && !me->query("tmg/300") && me->query("age")>55){
                tell_object(me, HIR"\n无意中你感觉一股热浪，从丹田涌出，你多年修炼的内力有了提高！\n"NOR);
                me->add("max_neili", random(lit + skill));
                me->set("tmg/300", 1);
        }
}


string exert_function_file(string func)
{
        return SKILL_D("tianmo-gong/") + func;
}
mapping exercise_msg(object me)
{
	return ([
                "status_msg" : HIR + me->name()+"脸上充满了红色光芒，气定神闲" NOR,
                "start_my_msg" : HIR"你盘膝坐下，默运天魔大法，顿时脸上红光时隐时现，内息顺经脉缓缓流动。\n"NOR,
                "start_other_msg" : HIM + me->name() +"盘膝而坐，默运天魔大法，顿时脸上红光时隐时现。\n"NOR,
                "halt_msg" : "$N长出一口气，将内息急速退了回去，站了起来。\n",
                "end_my_msg" : HIR"你将内息走了个一个周天，将满脸红光退去，收功站了起来。\n"NOR,
                "end_other_msg" : HIR"不一会儿"+me->name()+"便神采弈弈地站了起来。\n"NOR
	]);
}
