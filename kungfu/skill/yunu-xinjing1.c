// yunu-xinjing.c 玉女心经
// Modify By River 10/98

#include <ansi.h>
inherit FORCE;
#include "/kungfu/skill/eff_msg.h";


int valid_enable(string usage) { 
	  if (this_player()->query("family/family_name")=="古墓派" || this_player()->query("cw_mp/古墓派") )return usage == "force"; }

#include "force.h"

int valid_learn(object me)
{
		mapping fam  = me->query("family");
        int lvl = (int)me->query_skill("yunu-xinjing", 1);


	if ((!fam || fam["family_name"] != "古墓派" )&& !me->query("cw_mp/古墓派") )
			 	return notify_fail("你并非古墓弟子，如何习得了玉女心经。\n");
	if ( me->query("gender") == "无性") 
		return notify_fail("你无根无性，阴阳不调，难以领会高深的玉女心经神功。\n");

        if ( lvl < 120)
                return notify_fail("你现在还只能通过合修来领会高深的玉女心经神功。\n");

        if ((int)me->query_skill("yunu-xinjing", 1) > me->query_skill("force", 1) + 10
          && me->query_skill("yunu-xinjing", 1) >= 200 )
               return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");

        return valid_public(me);
}

int practice_skill(object me)
{
	if((int)me->query_skill("yunu-xinjing", 1) >= 200 ){
		if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200){
			me->improve_skill("yunu-xinjing", (int)me->query_int());
			me->add("neili", -100); 
			me->add("potential", -1*(1+random(3)));
			return 1;
		}
		else return notify_fail("你现在的修为不足以提高玉女心经了。\n");
	}
	else return notify_fail("你现在的玉女心经修为只能用学(learn)的来增加熟练度。\n");

}

string exert_function_file(string func)
{
	return __DIR__"yunu-xinjing/" + func;
}

mapping exercise_msg(object me)
{
	return ([
		"status_msg" : HIB + me->name()+"姿态悠雅，神态清冷"NOR,
		"start_my_msg" : "你轻轻的吸一口气，闭上眼睛，运起玉女心经，内息在脉络中开始运转。\n",
		"start_other_msg" : me->name()+"神态突然开始变的清冷无比，可是姿势又变的悠雅异常。\n",
		"halt_msg" : "$N内息一转，迅速收气，停止了内息的运转。\n",
		"end_my_msg" : "你慢慢收气，归入丹田，睁开眼睛，轻轻的吐了一口气。\n",
		"end_other_msg" : "只见"+me->name()+"睁开眼睛，轻轻的吐出了一口气，神态恢复自然。\n"
	]);
}

int hit_ob(object me, object ob, int damage)
{
	object weapon;	
	if( me->query_int(1) > 40
	 && me->query_dex(1) > 40
	 && me->query_skill_mapped("hand") == "tianluo-diwang"
	 && me->query_skill_mapped("cuff") == "meinu-quanfa"
	 && me->query_skill("hand") > 300
	 && me->query_skill("cuff") > 300
	 && me->query("neili") > 500
	 && me->query("jingli") > 500
	 && me->query("family/family_name") == "古墓派"
	 && me->query("env/玉女心经") == "融合"
	 && !me->query_temp("anran")
//	 &&!ob->is_busy()
//	 &&!ob->is_lost()
	 &&!random(2)
                     ){
		if (weapon=me->query_temp("weapon"))
			message_vision(HIC"$N将手中的"+weapon->query("name")+HIC"一收，",me);
		else
			message_vision(HIC"$N招式一变，",me);

		if(ob->query("class") != "bonze"
		 && ob->query("class") != "huanxi" 
		 && me->query("gender") != ob->query("gender")){
			message_vision(HIC"施展出古墓派嫡传美女拳法！\n", me);
			if (random(me->query_per()) > ob->query_per()/2){
				message_vision(HIR"$n心神一乱，险些被$N击中要害，一阵手忙脚乱！\n"NOR, me, ob);
				ob->add_busy(2+random(3));
				me->add("jingli",-50);
				me->add("neili",-100);
			}
			else
				message_vision(HIC"$n心神一乱，连忙自行镇慑心神！\n"NOR, me, ob);
		}
		else {
			message_vision(HIC"施展出古墓派嫡传天罗地网势！\n", me);
			if (random(me->query_dex()) > ob->query_dex()/2){
				message_vision(HIR"$n连连受挫，自顾不暇，无法准确的向$N攻击！\n"NOR, me, ob);
				ob->start_lost(2+random(3));
				me->add("neili",-50);
				me->add("jingli",-100);
			}
		else
			message_vision(HIC"$n以快打快，破解了$N的奇袭！\n"NOR, me, ob);
		}
	}
}

int ob_hit(object ob, object me, int damage)
{

string *pictures=({
"心惊肉跳","杞人忧天","无中生有","拖泥带水","徘徊空谷","力不从心","行尸走肉", "庸人自扰"
});


string *pictures2=({
HIM"一招" HIR "「勾魂夺魄」" HIM "直插向$n的$l"NOR,
HIM"爪爪钩向$n，一招" HIR "「九子连环」" HIM "已向$n的$l抓出"NOR,
HIM"使出" HIR "「天罗地网」" HIM "，$n的$l已完全笼罩在爪影之下"NOR, 
HIM"使一招" HIR "「风卷残云」" HIM "，右爪幻出满天爪影抓向$n全身"NOR,
HIM"吐气扬声，一招" HIR "「唯我独尊」" HIM "右爪奋力向$n天灵戳下"NOR
   });


 string picture,picture2,msg;
 int p;
 picture = pictures[random(sizeof(pictures))];
 picture2 = pictures2[random(sizeof(pictures2))]; 

if(!environment(me)) return 0;
if(!me->query("quest/jiuyingm/pass")) return 0;

if(me->query_skill("jiuyin-shenfa",1)<=181 ) return 0;

if(!random(3) && me->query("env/九阴")
	&& (me->query("qi")-damage) <=  me->query("max_qi")*2/3 )
	   {  message_vision(HIY"$N身如游鱼，突然使出了"HIW"九阴真经"HIY"上的功夫，躲过了这致命的一击！\n" NOR, me);
      	return -damage;
     	}


if(me->query_skill("anran-zhang",1)<=450 ) return 0;
    
if(random(3) 
	&& me->query("quest/gmsuper/pass") 
	&& (me->query("qi")-damage) <=  me->query("max_qi")*2/3){  
  
        message_vision(HIW"$N心想今日身陷绝境，不由万念俱灰，凄然之意自心而升，没精打采的拍出一掌「"+picture+"」，\n"+
                          "但见掌风激荡，恍恍惚惚，隐隐约约！刹时黯然销魂掌威力顿增，势不可挡。\n"NOR,me);
                        
        message_vision("只听见$N一声惨叫，整个身体象断了线的风筝一样飞了出去！！\n"NOR,ob);
       ob->receive_damage("qi", damage/2);
       ob->receive_wound("qi", damage/4);
   
    p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
    
       msg = "( $n"+eff_status_msg(p)+" )\n";
       message_vision(msg, me, ob); 


       if(damage/2 >= ob->query("qi")) ob->unconcious();
                        
       return -damage;

}


if(me->query_skill("jiuyin-shenzhua",1)<=451 ) return 0;
	
  if(random(4) && me->query("quest/gmsuper/pass")){  
  
        message_vision(HIM"$N运起玉女心经，一心二用，右手虚张成爪，「"+picture2+"」！\n"NOR,me,ob);
                        
        message_vision(HIM"正是源自古墓石刻的绝妙招式，$n招式用老，新力未生，被攻了个措手不及。\n"NOR,me,ob);
       ob->receive_damage("qi", damage/3);
       ob->receive_wound("qi", damage/6);
   
    p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
    
       msg = "( $n"+eff_status_msg(p)+" )\n";
       message_vision(msg, me, ob); 


       if(damage/3 >= ob->query("qi")) ob->unconcious();
                        
       return -damage;

}	
     return 0;

        
}

