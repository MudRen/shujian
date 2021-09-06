// xiantian-gong.c 先天功
//updated by action@SJ 2008/9/15

inherit FORCE;
#include <ansi.h>

int get_bouns(int damage,int t,int level,int flag);
int valid_enable(string usage) { 
 if (this_player()->query("family/family_name")=="全真教" || this_player()->query("cw_mp/全真教")  )
return usage == "force"; }

int valid_learn(object me)
{
mapping fam;
      int lvl, i;
        lvl = (int)me->query_skill("xiantian-gong", 1);
        i = (int)me->query("shen", 1);
 fam  = me->query("family");
if(!fam || fam["family_name"]!="全真教" && !me->query("cw_mp/全真教"))
             return notify_fail("你不是全真教弟子，难以修炼天罡正气。\n");
        if ( me->query("gender") == "无性" )
	return notify_fail("先天功练的是天罡正气，公公阴人之身修练无益！\n");

	if ( me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你阴气太盛，难以再练天罡正气。\n");
	
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");
		
		    if ((lvl > 10 && lvl < 100 && i < lvl*lvl*lvl / 20 )
            || ( lvl >=100 && i < 10000))
                return notify_fail("你的侠义正气太低了，无法学习先天功。\n");


	return 1;
}
int practice_skill(object me)
{
	if((int)me->query_skill("xiantian-gong", 1) >= 200 ){
		if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200){
			me->improve_skill("xiantian-gong", (int)me->query_int());
			me->add("neili", -100); 
			me->add("potential", -1*(1+random(3)));
			return 1;
		}
		else return notify_fail("你现在的修为不足以提高先天功了。\n");
	}
	else return notify_fail("你现在的先天功修为只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"xiantian-gong/" + func;
}

mapping exercise_msg(object me)
{
	return ([
		"status_msg" : me->name()+"运起纯阳神通功，身手分外矫健。",
		"start_my_msg" : "你运起纯阳神通功，片刻之间，白气笼罩全身，双眼精光四射，身手分外矫健，进退神速，与平时判若两人。\n",
		"end_my_msg" : "你将纯阳神通功运行完毕，除却白气笼罩，双眼精光四射，缓缓站了起来。\n",
		"end_other_msg" : ""+me->name()+"将纯阳神通功退去，站了起来。\n"
	]);
}


string* msgs =
({
	WHT"$N运起先天罡气护体，初若有若无,绵如云霞,然而蓄劲极韧，到后来铺天盖地，牢不可破，\n",
        HIG"$N轻声念到："HIG"养气忘言守，降心为不为"GRN"，先天功真气外放，气就神交，任督自转，\n",
	RED"$N已得真常应物，应物不迷之道家修行绝诣，不迷性住，性住气回！\n",
});


int ob_hit(object ob, object me, int damage)
{
	object she;
	
	if(!environment(me)) return 0;
	if(me->query_temp("xtg/wuqi") && me->query_skill("xiantian-gong",1)>450 || me->query("quanzhen/force")=="pass" )
	{
		int t = me->query_temp("combat_time");

                if( random(10)>6 || (me->query("quanzhen/force")=="pass" && random(5)>=2 ))
		{
			message_vision(msgs[random(sizeof(msgs))]+"$n只觉得好像击打在了棉花团里。\n"NOR,me,ob);
			return -get_bouns(damage,t,me->query_skill("xiantian-gong",1),0);
		}
	}


}

int get_bouns(int damage,int t,int level,int flag)
{
	int dm;
        dm= (damage*100*(t+level/20))/(t+level/20+10);
        return dm/100;
}
