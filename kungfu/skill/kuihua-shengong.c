// kuihua-xinfa.c 葵花心法

inherit FORCE;
#include <ansi.h>


string *xue_name = ({ 
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",
"涌泉穴","大锥穴","风府穴",
}); 


int valid_enable(string usage) { 
if ( this_player()->query("quest/pixie/pass") ) return usage == "force"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("kuihua-shengong", 1);
	if ((int)me->query_skill("force", 1) < 10)
        return notify_fail("你的基本内功火候不足，不能学葵花心法。\n");
        
        if (i > 100 && (int)me->query("shen") > i*i*i/20 )
		return notify_fail("学葵花心法，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
		
	if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) )
		return notify_fail("你练了秃驴牛鼻子们的心法，还学葵花心法做什麽！\n");

	if (
	   me->query_skill("shenzhao-jing",1)
	|| me->query_skill("taixuan-gong",1)
	|| me->query_skill("jiuyin-zhengong",1)
	|| me->query_skill("hamagong",1))

		return notify_fail("你不先散了别派内功，怎能学葵花心法？！\n");
	return 1;
}

int practice_skill(object me)
{
	if((int)me->query_skill("kuihua-shengong", 1) >= 200 ) {
		if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200) {
			me->improve_skill("kuihua-shengong", me->query_int());
			me->add("neili", -100);
			me->add("potential", -1*(1+random(3)));
			return 1;
		}
		else return notify_fail("你现在的修为不足以提高葵花神功了。\n");
	}
	else return notify_fail("葵花神功不可随便练习。\n");
}

string exert_function_file(string func)
{
	return __DIR__"kuihua-shengong/" + func;
}

mapping exercise_msg(object me)
{
	return ([
		"status_msg" : MAG + me->name()+"手捏绣花针，双目低垂内视"NOR ,
		"start_my_msg" : MAG"你手捏绣花针，盘膝坐下，默运葵花神功，只觉冷热两股紫气开始在体内缓缓游动。\n"NOR,
		"start_other_msg" : MAG + me->name()+"手捏绣花针盘膝坐下，周身似乎笼罩在一层紫气之中。\n"NOR,
		"halt_msg" : MAG"$N放下绣花针，两股真气迅速交汇消融。\n"NOR,
		"end_my_msg" : MAG"你将紫气在体内运行了一个周天，冷热紫气收于丹田，慢慢抬起了眼睛。\n"NOR,
		"end_other_msg" : MAG"只见"+me->name()+"慢慢睁开眼睛，周身笼罩的紫气逐渐隐去。\n"NOR,
	]);
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon,weapon1;
        string name,name1,name2,name3;
        int i;
        weapon = me->query_temp("weapon");
        weapon1= victim->query_temp("weapon");
        i = me->query_skill("kuihua-shengong", 1);

        
       name = xue_name[random(sizeof(xue_name))];
          
if(!weapon) return;
    if(me->query_skill_mapped("force")!="kuihua-shengong"
     ||me->query_skill_mapped("sword")!="pixie-jian") return;

   if(i>=350){
       if(random(i)>(int)victim->query_skill("parry",1)/3
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HBMAG"$N出招诡异，指东打西，$n猝不及防，「"RED""+name+""HBMAG"」被"+weapon->name()+HBMAG HIG"刺中，当下半身麻痹，不能动弹！\n"NOR,me,victim);
            victim->set_temp("must_be_hit",1);
            victim->add_busy(1+random(2));
            victim->apply_condition("no_fight",1);
            call_out("dgjj_must_be_hit",2,me,victim,random(i/50));
       }
   }
   if(i>=300){
       if(random(i)>(int)victim->query_skill("parry",1)/3
        &&random(3)){
            message_vision(HIC"$N手中"+weapon->name()+HIC"倏往倏来，如同鬼魅，招招不离$n的「"RED""+name+""HIC"」！\n"NOR,me,victim);
            message_vision(RED"结果一招得手，$n的「"HIR""+name+""RED"」被刺了个通透！\n"NOR,me,victim);
            victim->set_temp("must_be_hit",1);
            victim->apply_condition("no_perform",2);
       }
   }


   if(i>=250){
       if(random(i)>(int)victim->query_skill("dodge",1)/3
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(WHT"$N忽然化身为二，手中"+weapon->name()+WHT"幻化不定，招招紧逼，直取$n「"RED""+name+""WHT"」，$n眼前一花，只得连连招架，毫无还手之力！\n"NOR,me,victim);
            victim->set_temp("no_fight",1);
            victim->apply_condition("no_fight",1);
       }
   }

        if( weapon1 && i > 200 && living(victim)
         && me->query_skill_mapped("force") == "kuihua-shengong"
         && me->query_skill_mapped("sword") == "pixie-jian"
         && random(me->query("combat_exp")) > victim->query("combat_exp")/2 ) {
                message_vision( HBMAG HIC "$N招式诡异至极，"+weapon->name()+"看似刺向$n的「"HIR""+name+""HBMAG HIC"」，中途却猛的变招，径直挑向手腕！\n"NOR, 

me,victim);
                if( random(me->query("dex")) > victim->query("dex")/3 ) {
                        me->add("neili", -50);
                   victim->add_busy(1+random(2));
                        message_vision( HBMAG HIG"$N只觉腕上一阵剧痛，手筋已经被连根挑断！"+weapon1->name()+HBMAG HIG"再也把持不住，脱手而出！\n"NOR, victim);
                        weapon1->unequip();
                     victim->apply_condition("broken_arm",5); 
                        weapon1->move(environment(victim));
                }
                else {
                        message_vision(HIC"$n心下大骇，连忙变招，堪堪避过！\n"NOR, me,victim);
                    me->start_perform(1,"「挑腕」");
                    victim->add_busy(1+random(2));
                       }
        }
     
}

void dgjj_must_be_hit(object me,object target,int i)
{
    if(!target) return;
    if(!me) {
        target->delete_temp("must_be_hit");
        return;
    }
 
    if(me->query_skill_mapped("force")!="kuihua-shengong"
     ||me->query_skill_mapped("sword")!="pixie-jian"
     ||i<=0){
        if(living(target))
        target->delete_temp("must_be_hit");
        return;
    }
    call_out("dgjj_must_be_hit",1,me,target,--i);
}

int ob_hit(object ob, object me, int damage)
{
        object wp,wp1;
        string msg;
        string name,name1,name2,name3;
        int p,j,skill, neili, neili1, exp, exp1;
        wp = me->query_temp("weapon");
        wp1 = ob->query_temp("weapon");
        skill = me->query_skill("kuihua-shengong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
        exp = me->query("combat_exp");
        exp1 = ob->query("combat_exp");



       name = xue_name[random(sizeof(xue_name))];

          

        if( me->query("jiali") 
        && skill+50 > random(ob->query_skill("parry", 1)/3)
        && skill > 100
        && me->query_skill_mapped("parry") == "pixie-jian"
        && me->query_skill_mapped("dodge") == "pixie-jian"
        && me->query_skill_mapped("sword") == "pixie-jian"
        && living(ob)
        && !me->is_busy()){
                if(wp1){
                      if(wp)  msg = RED"$N一声冷笑，蓦地里疾冲上前，当真是动如脱兔，一瞬之间，"+wp->name()+RED"与$n的「"HIR""+name+""RED"」相距已不到一寸！\n"NOR;
                     else msg = RED"$N一声冷笑，蓦地里疾冲上前，当真是动如脱兔，一瞬之间，与$n的「"HIR""+name+""RED"」相距已不到一寸！\n"NOR;
                       
                        if(neili >= random(neili1+damage)){
                                if(random(me->query_dex(1)) > ob->query_dex(1)/3 && skill > 120){
                                        msg += WHT"结果$n一不留神，「"RED""+name+""WHT"」已经被剑气所伤，招式顿时无法连贯！\n"NOR;
                                        ob->add_busy(2+random(2));
                                        j = -(damage);
                                }
                                else{
                                        ob->receive_damage("qi", damage/10, me);
                                        ob->receive_wound("qi", damage/10, me);
                                        p = ob->query("qi")*100/ob->query("max_qi");
                                        msg += COMBAT_D->damage_msg(damage/20, "伤害");
                                        msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
                                        j = -(damage/2+skill/2);
                                }
                        }
                        else if(neili >= random(neili1)+damage){
                                msg += CYN"$n措不及防之下，「"RED""+name+""CYN"」上微微一麻，登时感到全身酸麻，出招软绵绵的，再无威力。\n"NOR;              
                                j = -(damage/3+skill/3);
                        }
                        else{
                                j = damage/4+random(damage/4);
                                if(j<damage/2) msg += CYN"$n措不及防之下，「"RED""+name+""CYN"」上微微一痛，登时感到全身酸麻，出招软绵绵的，威力大减！\n"NOR;
                                else msg += CYN"$n措不及防之下，「"RED""+name+""CYN"」上微微一痛，登时感到全身酸麻，出招软绵绵的，毫无威力！\n"NOR;
                                j = -j;
                        }
                        message_vision(msg, me, ob);
                        return j;
                }
                else{
                     if(wp) {   msg = HBYEL MAG"$N一声尖叫，飞身纵起，在半空中一转，快绝无比的飞落下来，手中"+wp->name()+HBYEL MAG"破空直刺下来，\n"NOR;
                        msg += HBMAG HIC "$N左一拨，右一拨，上一拨，下一拨，将$n的招数尽数拨开，右手"+wp->name()+HBYEL MAG"一转，急刺$n的「"RED""+name+""CYN"」。\n"NOR;}
                     else  
                        msg = HBMAG HIC "$N左一拨，右一拨，上一拨，下一拨，将$n的招数尽数拨开，骈指如剑，急刺$n的「"RED""+name+""CYN"」。\n"NOR;
                        if(neili >= neili1+random(neili1)+damage){
                                ob->receive_damage("qi", damage/10, me);
                                ob->receive_wound("qi", damage/10, me);
                                p = ob->query("qi")*100/ob->query("max_qi");
                                msg += COMBAT_D->damage_msg(damage, "刺伤");
                                msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
                                j = -(damage+skill);
                        }
                        else if(neili >= random(neili1)+damage){
                                msg += HBMAG HIC "$n还欲进攻，只觉「"RED""+name+"" HBMAG HIC"」微微一麻，连忙收招防守，无功而返。\n"NOR;     
                                j = -(damage/2+skill);
                        }
                        else{
                                j = damage/3+random(damage/3); 
 
                                 msg += HBMAG HIC "$n还欲进攻，只觉「"RED""+name+"" HBMAG HIC"」微微一麻，连忙收招防守，无功而返。\n"NOR;
                                j = -j;
                        }
                        message_vision(msg, me, ob);
                        return j;
                }
        }

}
