// yinyun-ziqi.c 氤氲紫气

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) {          if (this_player()->query("family/family_name")=="武当派"|| this_player()->query("cw_mp/武当派")|| this_player()->query("expell/family_name")=="武当派" )
return usage == "force"; }

#include "force.h"

int valid_learn(object me)
{

		mapping fam  = me->query("family");


	int lvl = (int)me->query_skill("yinyun-ziqi", 1);
	int t = 1, j;

	for( j = 1; j < lvl / 10; j++) t *= 2;
	if( t > 5000 ) t = 5000;
	if( me->query("gender") == "无性" && lvl > 49 )
		return notify_fail("你无根无性，阴阳不调，难以领会高深的氤氲紫气神功。\n");
	if ((!fam || fam["family_name"] != "武当派" )&& !me->query("cw_mp/武当派") )
			 	return notify_fail("你并非武当派弟子，如何习得了武当神功。\n");

	if( me->query("class") == "bonze" )
		return notify_fail("氤氲紫气讲究阴阳调合，有违佛家六根清净之意，" +RANK_D->query_respect(me)+"欲修此功，已是罪过。\n");

	if( (int)me->query_skill("force", 1) < 15 )
		return notify_fail("你的基本内功火候还不够。\n");

	if( (int)me->query_skill("yinyun-ziqi", 1) > me->query_skill("force", 1) + 10
	&& me->query_skill("yinyun-ziqi", 1) >= 200 )
		return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");

	if( (lvl > 10 && lvl < 100 && (int)me->query("shen") < t * 200)
	|| ( lvl >=100 && (int)me->query("shen") < 10000) )
		return notify_fail("你的侠义正气太低了。\n");

	if( me->query("menggu") )
		return notify_fail("你已投降蒙古，无法再进一步提高氤氲紫气。\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	if( (int)me->query_skill("yinyun-ziqi", 1) >= 200 ) {
		if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200) {
			me->improve_skill("yinyun-ziqi", (int)me->query_int());
			me->add("neili", -100); 
			me->add("potential", -1*(1+random(3)));
			return 1;
		}
		else return notify_fail("你现在的修为不足以提高氤氲紫气了。\n");
	}
	else return notify_fail("你现在的氤氲紫气修为只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"yinyun-ziqi/" + func;
}

mapping exercise_msg(object me)
{
	return ([
		"status_msg" : MAG + me->name()+"头顶氤气蒸蒸，神色威严" NOR,
		"start_my_msg" : "你盘膝而坐，双目紧闭，深深吸一口气引入丹田，慢慢让一股内息在周身大穴流动，渐入忘我之境。\n",
		"start_other_msg" : me->name()+"盘膝坐了下来，双手虚握成拳，不一会，头顶冒出氤氤紫气。\n",
		"halt_msg" : "$N微一簇眉，将内息压回丹田，长出一口气，站了起来。\n",
		"end_my_msg" : "你将内息在体内运行十二周天，返回丹田，只觉得全身暖洋洋的。\n",
		"end_other_msg" : me->name()+"长出一口气，一抖衣襟，站了起来，眼中精光一闪。\n"
	]);
}

mixed ob_hit(object ob, object me, int damage)
{
	 int ap, dp;
        int  lvl,i;
        lvl = me->query_skill("yinyun-ziqi", 1);
        if ( lvl < 350
          || me->query("neili") < 2000
          || me->query_skill_mapped("force") != "yinyun-ziqi")
         	return 0;
if(!me->query("quest/wdjiuyang/pass") && !me->query_temp("quest/wdjiuyang/pass") ) return 0;
         	
        ap = ob->query_skill("force");
        dp = me->query_skill("force");

 if (random(dp)> ap*2 /3 && random(me->query("neili")) > ob->query("neili")/3 && lvl >550 )
        {

	              i = -damage* 3/2;
              
                ob->receive_damage("qi", damage,me);
                ob->receive_wound("qi", damage/3, me);
                ob->add_busy(2);
            

              message_vision(HIC"$N已经澈晓道家"HIG"冲虚圆通"HIC"之道，又将生平所学与"HIR"九阳真经"HIC"相对照，武当武功几臻登峰造极之境，"
                                  "\n当下$N用意不用劲，前后左右，全无定向，反守为攻，竟是后发制人，先发者制于人。\n"NOR,me,ob);
              COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), userp(ob)?1:3); //这个不支持?

               return 0;                              
           }      


  else if (random(dp)> ap /2 && random(me->query("neili")) > ob->query("neili")/2 )
        {
	          i = -damage;        //削减并反弹所有攻击。
           ob->receive_damage("qi", damage,me);
           ob->receive_wound("qi", damage/3,me);

              message_vision(HIC"$N以四两拨千斤之法，我劲接彼劲，曲中求直，借力打人，体内真气流转，敌弱便弱，敌强愈强。"
                                   "\n那掌力击在$N身上，尽数反弹了出来，竟是丝毫没有受到伤害。\n"NOR,me,ob);
              return i;                               
           }      
 
  else if (random(dp+ap)> ap || (lvl>450&&random(2)))
        {
	        i = - damage/3 - random(damage*2/3);  //削减一小半至全部的攻击
                                
              message_vision(HIC"$N将"HIM"氤氲紫气"HIC"运遍全身，顷刻间使遍于四肢百骸，几至全身无缺陷处，无凹凸处，无断续处。"
                                   "\n$N随人所动，随屈就伸，以心使劲，中招之处竟不觉如何疼痛。\n"NOR,me,ob);
         return i;
         }                          
 
               return 0;  

} 

