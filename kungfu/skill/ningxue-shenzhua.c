// ningxue-shenzhua.c 凝血神抓

#include <ansi.h>
inherit SKILL;  

string *xue_name = ({ 
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",
"涌泉穴","大锥穴","风府穴",
}); 


mapping *action = ({
([
"action": "$N双掌平平提到胸前，神色沉重的缓缓施出「"HIG"苍龙探爪"NOR"」抓向$n的$l",
"lvl" : 0,
"damage_type": "瘀伤"
]),
([
"action": "$N突然身形飞起，双手居高临下一招「"HIC"飞鹰拨兔"NOR"」抓向$n的$l",
"lvl" : 30,
"damage_type": "瘀伤"
]),
([
"action": "$N右手一招「"HIB"黑虎掏心"NOR"」，迅捷无比地抓向$n的$l",
"lvl" : 80,
"damage_type": "瘀伤"
]),
([
"action": "$N双手施出一招「"HIY"泰山压顶"NOR"」，隐隐带着风声抓向$n的$l",
"lvl" : 130,
"damage_type": "瘀伤"
]),
([
"action": "$N左手聚成虎爪状，右手一招「"HIR"凝血神抓"NOR"」缓缓抓向$n的$l",
"lvl" : 200,
"damage_type": "瘀伤"
]),
});

int valid_enable(string usage)
{
return usage=="claw" ||  usage=="parry"; 
}

int valid_learn(object me)
{
if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
return notify_fail("练凝血神抓必须空手。\n");
if ((int)me->query("max_neili") < 100)
return notify_fail("你的内力太弱，无法练凝血神抓。\n");
if ( me->query_skill("ningxue-shenzhua", 1) < 150 )
return notify_fail("你现在的凝血神抓还只能通过读书才能提高。\n");
return 1;
}

string query_skill_name(int level)
{
int i = sizeof(action);

while (i--)
if(level > action[i]["lvl"])
return action[i]["skill_name"];
}

mapping query_action(object me,object weapon)
{
int i, j, level;
level = me->query_skill("ningxue-shenzhua",1);

for(i = sizeof(action); i > 0; i--){
if(level > action[i-1]["lvl"]){
j = NewRandom(i, 20, level/5);
if( me->query_temp("nxsz_pfm")) {
return ([
"action":HIR + replace_string(action[j]["action"], NOR, HIR)+NOR,
//"action" :HIR+action[j]["action"]+NOR,
"damage_type":"内伤",
"dodge":random(35),
"parry":random(35),
"force":350 + random(350),
"damage":50 + random(50),
]);
}
return ([
"action":action[j]["action"],
"damage_type":action[j]["damage_type"],
"lvl":action[j]["lvl"],
"force":300 + random(350),
"dodge":random(30),
"parry":random(30),
]);
}
}
}


int practice_skill(object me)
{
if ( me->query("jingli") < 60)
return notify_fail("你的精力不够练此武功。\n");
if ( me->query("neili") < 30)
return notify_fail("你的内力不够练此武功。\n");
me->receive_damage("jingli", 50);
me->add("neili", -20);
return 1;
}

string perform_action_file(string action)
{
return __DIR__"ningxue-shenzhua/" + action;
}





mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon1;
        string name,name1,name2,name3;
        int i;
        weapon1= victim->query_temp("weapon");
        i = me->query_skill("ningxue-shenzhua", 1);
        
       name = xue_name[random(sizeof(xue_name))];
          
if(!me->query("env/反清复明")) return;
   if(i>=350){
       if(random(i)>(int)victim->query_skill("parry",1)*2/3
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HIG"$N连出数爪，犹如风卷残云，$n猝不及防，「"RED""+name+""HIG"」被一爪抓住，当下半身麻痹，不能动弹！\n"NOR,me,victim);
            victim->set_temp("must_be_hit",1);
            call_out("dgjj_must_be_hit",2,me,victim,random(i/50));
       }
   }
   if(i>=300){
       if(random(i)>(int)victim->query_skill("parry",1)*2/3
        &&random(3)){
            message_vision(HIY"$N趁$n跃起避让之际，抓住$n脚踝从半空拉回来用力一摔，直摔得$n七荤八素眼冒金星！\n"NOR,me,victim);
            victim->set_temp("must_be_hit",1);
            victim->apply_condition("no_perform",2);
       }
   }


   if(i>=250){
       if(random(i)>(int)victim->query_skill("dodge",1)/2
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(WHT"$n只觉$N漫天爪影招招径取自己「"RED""+name+""WHT"」，只得连连招架，毫无还手之力！\n"NOR,me,victim);
            victim->set_temp("no_fight",1);
            victim->apply_condition("no_fight",1);
       }
   }

        if( weapon1 && i > 200 && living(victim)
         && me->query_skill_mapped("parry") == "ningxue-shenzhua"
         && random(me->query("combat_exp")) > victim->query("combat_exp")/2 ) {
                message_vision(MAG"$N作势欲抓$n的「"RED""+name+""MAG"」，中途却猛的变招，径直抓向$n的手腕，用力一扭！\n"NOR, 

me,victim);
                if( random(me->query("str")) > victim->query("str")/3 ) {
                        me->add("neili", -50);
                   victim->add_busy(1+random(2));
                        message_vision(HIR"$N只觉腕上一阵剧痛，只听得咔嚓一声，腕骨已经被扭断！"+weapon1->name()+HIR"再也把持不住，脱手而出！\n"NOR, victim);
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
    if(wizardp(me) && me->query("env/dgjj_test")) write("i is "+i+"\n"NOR);
    if(me->query_skill_mapped("sword")!="ningxue-shenzhua"
     ||me->query_skill_mapped("parry")!="ningxue-shenzhua"
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
        skill = me->query_skill("ningxue-shenzhua", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
        exp = me->query("combat_exp");
        exp1 = ob->query("combat_exp");


       name = xue_name[random(sizeof(xue_name))];

          

        if( me->query("jiali") 
        && skill+50 > random(ob->query_skill("parry", 1)/3)
        && skill > 100
        && me->query_skill_mapped("parry") == "ningxue-shenzhua"
        && living(ob)
        && !me->is_busy()){
                if(wp1){
                        msg = WHT"$N卷起漫天爪影，招招径取$n周身大穴！\n"NOR;
                        msg = replace_string(msg, "$w", wp1->name());
                        if(neili >= random(neili1+damage)){
                                if(random(me->query_dex(1)) > ob->query_str(1)/3 && skill > 120){
                                        msg += WHT"结果$n一不留神被抓到了「"RED""+name+""WHT"」，招式顿时无法连贯！\n"NOR;
                                        ob->add_busy(1+random(2));
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
                                j = -(damage/2+skill/2);
                        }
                        else{
                                j = damage/2+random(damage/2);
                                if(j<damage/2) msg += CYN"$n措不及防之下，「"RED""+name+""CYN"」上微微一麻，登时感到全身酸麻，出招软绵绵的，再无威力。\n"NOR;
                                else msg += CYN"$n措不及防之下，「"RED""+name+""CYN"」上微微一麻，登时感到全身酸麻，出招软绵绵的，再无威力。。\n"NOR;
                                j = -j;
                        }
                        message_vision(msg, me, ob);
                        return j;
                }
                else{
                        msg = HIY"$N看准$n的破绽，急攻数招，招招不离$n周身大穴！\n"NOR;
                        if(neili >= neili1+random(neili1)+damage){
                                ob->receive_damage("qi", damage/10, me);
                                ob->receive_wound("qi", damage/10, me);
                                p = ob->query("qi")*100/ob->query("max_qi");
                                msg += COMBAT_D->damage_msg(damage, "刺伤");
                                msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
                                j = -(damage*2+skill);
                        }
                        else if(neili >= random(neili1)+damage){
                                msg += HIW"$n只见漫天爪影，招招指向自己的「"RED""+name+""HIY"」，只得中途变招，威力大减。\n"NOR;              
                                j = -(damage+skill);
                        }
                        else{
                                j = damage/2+random(damage/2); 
                                if(j<damage/2) msg += HIY"$n但觉「"RED""+name+""HIY"」上微微一麻，只得中途变招，威力竟是发挥不出一半。\n"NOR;
                                else msg += HIW"$n只见漫天爪影，招招指向自己的「"RED""+name+""HIW"」，只得收招防守，无功而返。\n"NOR;
                                j = -j;
                        }
                        message_vision(msg, me, ob);
                        return j;
                }
        }

}
