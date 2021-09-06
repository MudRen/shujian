// xixing-dafa.c 吸星大法
// modified by action@SJ
//updated by Zmud@Sjmud 10/3/2009
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { if (this_player()->query("quest/xxdf/pass")) return usage == "force"; }

#include "/kungfu/skill/force.h"

int valid_learn(object me)
{
	if ( me->query("gender") == "无性")
		return notify_fail("你无根无性，阴阳不调，难以领会高深的吸星大法。\n");

        if ((int)me->query_skill("xixing-dafa", 1) > me->query_skill("force", 1) + 10
          && me->query_skill("xixing-dafa", 1) >= 200 )
               return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");

        return valid_public(me);
}

int practice_skill(object me)
{
       if((int)me->query_skill("xixing-dafa", 1) >= 200 )
       {
           if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200)
           {
                   me->improve_skill("xixing-dafa", (int)me->query_int());
                   me->add("neili", -100); 
                   me->add("potential", -1*(1+random(3)));
                   return 1;
           }
           else return notify_fail("你现在的修为不足以提高吸星大法了。\n");       }
        else return notify_fail("你现在的吸星大法修为只能用学(learn)的来增加熟练度。\n");

}
void skill_improved(object me)
{
        int skill, lit;
        skill = me->query_skill("xixing-dafa", 1);
        lit = me->query_skill("literate", 1);
        if(skill >= 300 && !me->query("xxdf/300") && me->query("age")>55){
                tell_object(me, HIR"\n无意中你感觉一股热浪，从丹田涌出，你多年修炼的内力有了提高！\n"NOR);
                me->add("max_neili", random(lit + skill));
                me->set("xxdf/300", 1);
        }
}

string exert_function_file(string func)
{
        return SKILL_D("xixing-dafa/") + func;
}
mapping exercise_msg(object me)
{
	return ([
		"status_msg" : HIB + me->name()+"端坐太虚，满面蓝光" NOR,
		"start_my_msg" : "你随意坐下，双手平放在双膝，默念口诀，开始运起吸星大法。\n",
		"start_other_msg" : me->name()+"随意在那里坐下，双手平放在双膝，全身蓝色气息浮现。\n",
		"halt_msg" : "$N面色一沉，迅速收气，站了起来。\n",
		"end_my_msg" : "你将真气逼入体内，将全身聚集的蓝色气息散去，站了起来。\n",
		"end_other_msg" : "只见"+me->name()+"双手抬起，站了起来，蓝色气息渐渐散去。\n"
	]);
}

int ob_hit(object ob, object me, int damage)
{
mapping myfam;
    int m_xxdf,t_force,i,j;
myfam= me->query("family");
    t_force = (int)ob->query_skill("force",1);
if(!myfam || myfam["family_name"] != "日月神教")
j=0;
else j = 1;
    if((int)me->query_skill("xixing-dafa",1)>=300)
    if(me->query_temp("xxdf/xixing")){
        if(m_xxdf > t_force ){
            i = - damage;
            message_vision(WHT"$n的招式威力太过于渺小，被吸星大法瞬间化解，结果没有对$N造成任何伤害。\n"NOR,me,ob);
            me->add("neili",300);
            ob->add("neili",-300);           
            return i;
        }
        else if(m_xxdf > t_force*2/5){
            i = - damage/2 - random(damage/2);
            message_vision(HIB"$N突然发动吸星大法，$n突然觉得精力源源不绝的在损失，感觉筋疲力尽,只得撤招！\n"NOR, me,ob);
            me->add("jingli",50);
            ob->add("jingli",-300);   
if(j>0)  {ob->start_busy(1);
ob->apply_condition("no_exert",1);
}
            return i;
        }
        else if(m_xxdf > t_force/2){
            i = - damage/2;
            message_vision(HIC"$N突然发动吸星大法，$n突然觉得内力源源不绝的流了出去,$n大叫一声,立即撤招！\n"NOR, me,ob);
            me->add("neili",-200);
            ob->add("neili",-300);   
if(j>0) {ob->start_busy(1);
 ob->apply_condition("no_fight",1);
}
            return i;
        }
        else if(m_xxdf > t_force/3){
            i = - damage/3;
            message_vision(HIR"$N突然发动吸星大法，$n突然觉得气血源源不绝地在损失，立即脱离了$N的控制！\n"NOR, me,ob);
            me->add("neili",-100);
            ob->add("qi",-500);               
if(j>0) ob->start_busy(1);
            return i;
        }
        else{
            i = - damage/4 - random(damage/5);
            message_vision(HIM"$N突然发动吸星大法，$n突然觉得精血源源不绝地在损失，立即脱离了$N的控制！\n"NOR, me,ob);
            me->add("neili",-50);
            ob->add("jing",-300);   
if(j>0) ob->start_busy(1);
            return i;
        }
    }
    return 0;
}
