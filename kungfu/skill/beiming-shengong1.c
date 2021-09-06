// beiming-shengong.c 北溟神功
//updated by Zmud@Sjmud 12/3/2009

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { 
	 if (this_player()->query("quest/天龙八部/北冥神功/pass") 
	  || this_player()->query("family/family_name")=="逍遥派"
          || this_player()->query("cw_mp/逍遥派")
 )
	return usage == "force"; }

#include "force.h"

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("beiming-shengong", 1);
	int t = 1, j;

	for( j = 1; j < lvl / 10; j++) t *= 2;
	if( t > 5000 ) t = 5000;
	if( me->query("gender") == "无性" && lvl > 49 )
		return notify_fail("你无根无性，阴阳不调，难以领会高深的北冥神功。\n");


        if( (int)me->query_skill("force", 1) < 30 )
		return notify_fail("你的基本内功火候还不够。\n");

	if( (int)me->query_skill("beiming-shengong", 1) > me->query_skill("force", 1) + 10
	&& me->query_skill("beiming-shengong", 1) >= 200 )
		return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");

	return valid_public(me);
}

int practice_skill(object me)
{
if( (int)me->query_skill("beiming-shengong", 1) >= 210 ) {
		if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200) {
			me->improve_skill("beiming-shengong", (int)me->query_int());
			me->add("neili", -100); 
			me->add("potential", -1*(1+random(3)));
			return 1;
		}
		else return notify_fail("你现在的修为不足以提高北冥神功了。\n");
	}
	else return notify_fail("你现在的北冥神功修为只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"beiming-shengong/" + func;
}

mapping exercise_msg(object me)
{
	return ([
		"status_msg" : HIB + me->name()+"头顶笼罩着北冥真气，神色威严" NOR,
		"start_my_msg" : "你盘膝而坐，双目紧闭，深深吸一口气引入丹田，将北冥真气引入周身大穴流动。\n",
		"start_other_msg" : me->name()+"盘膝坐了下来，双手虚握成拳，不一会，头顶冒出北冥真气。\n",
		"halt_msg" : "$N微一簇眉，将内息压回丹田，长出一口气，站了起来。\n",
		"end_my_msg" : "你将北冥真气在体内运行十二周天，返回丹田，只觉得全身通泰的。\n",
		"end_other_msg" : me->name()+"长出一口气，散去全身北冥真气，一抖衣襟，站了起来。\n"
	]);
}

int ob_hit(object ob, object me, int damage)
{
    int m_bmsg,t_force,i;
    m_bmsg = random((int)me->query_skill("beiming-shengong",1));
    t_force = (int)ob->query_skill("force",1);

    if((int)me->query_skill("beiming-shengong",1)>=300)
    if(me->query_temp("bmsg/bm")
    	&&me->query("quest/天龙八部/北冥神功/pass")){
    	
    	if(m_bmsg > t_force*9/10 && !random(3)){
            i = - damage;
            message_vision(HIC"$N神功陡发，将「北冥真气」聚集于全身，双掌贴将$n胸口过去，将毕生修为贯穿于$n各处经脉之中。\n"NOR,me,ob);
            me->add("neili",-1000);
           ob->receive_damage("qi", damage);
           COMBAT_D->report_status(ob, random(2));
            return i;
        }
    	 else if(m_bmsg > t_force*6/10 && !random(1)){
            i = - damage;
            message_vision(WHT"$N默念「北冥真气」心诀，"HBMAG+HIW"“覆杯水于坳堂之上，则芥为之舟；置杯焉则胶，水浅而舟大也。”"NOR+WHT"，顿时化解$n了攻击。\n"NOR,me,ob);
            me->add("neili",2000);
            ob->add("neili",-2000);
            COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 3);       
            return i;
        }
        else if(m_bmsg > t_force*5/10 && !random(1)){
            i = - damage;
            message_vision(WHT"$N猛然领悟「北冥」之精髓"HBRED+HIW"“且夫水之积也不厚，则其负大舟也无力”"NOR+WHT"，$n招数被「北溟真气」卸掉全部攻击。\n"NOR,me,ob);
            me->add("neili",1000);
            ob->add("neili",-1000);
            COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 3);          
            return i;
        }
        
        else if(m_bmsg > t_force*4/10){
            i = - damage*4/5;
            message_vision(WHT"$N陡然间斜上一步，有若飘风，扣住$n胸口「"CYN"膻中穴"NOR+WHT"」，$n一惊之下，急运内力挣扎，突觉内力自膻中空急泻而出！\n"NOR, me,ob);
            ob->add("neili",-500);
            me->add("qi",500);  
            me->add("neili",500);              
            ob->start_busy(1+random(2)); 
            return i;
        }
        else if(m_bmsg > t_force*3/10){
        	  i = - damage*4/5;
            message_vision(WHT"$N左手又已抓住$n肚脐上的「"BLU"神阙穴"NOR+WHT"」，$n急运内力挣扎，突觉内力自神阙空急泻而出，全身便似脱力一般！\n"NOR, me,ob);
            ob->add("neili",-500);
            me->add("qi",500);
            me->add("neili",500);    
            ob->start_busy(1+random(1));   
            return i;
        }
    }
    return 0;
}
