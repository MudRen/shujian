// ningxue-shenzhua.c ��Ѫ��ץ

#include <ansi.h>
inherit SKILL;  

string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",
"ӿȪѨ","��׶Ѩ","�縮Ѩ",
}); 


mapping *action = ({
([
"action": "$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ����"HIG"����̽צ"NOR"��ץ��$n��$l",
"lvl" : 0,
"damage_type": "����"
]),
([
"action": "$NͻȻ���η���˫�־Ӹ�����һ�С�"HIC"��ӥ����"NOR"��ץ��$n��$l",
"lvl" : 30,
"damage_type": "����"
]),
([
"action": "$N����һ�С�"HIB"�ڻ�����"NOR"����Ѹ���ޱȵ�ץ��$n��$l",
"lvl" : 80,
"damage_type": "����"
]),
([
"action": "$N˫��ʩ��һ�С�"HIY"̩ɽѹ��"NOR"�����������ŷ���ץ��$n��$l",
"lvl" : 130,
"damage_type": "����"
]),
([
"action": "$N���־۳ɻ�צ״������һ�С�"HIR"��Ѫ��ץ"NOR"������ץ��$n��$l",
"lvl" : 200,
"damage_type": "����"
]),
});

int valid_enable(string usage)
{
return usage=="claw" ||  usage=="parry"; 
}

int valid_learn(object me)
{
if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
return notify_fail("����Ѫ��ץ������֡�\n");
if ((int)me->query("max_neili") < 100)
return notify_fail("�������̫�����޷�����Ѫ��ץ��\n");
if ( me->query_skill("ningxue-shenzhua", 1) < 150 )
return notify_fail("�����ڵ���Ѫ��ץ��ֻ��ͨ�����������ߡ�\n");
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
"damage_type":"����",
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
return notify_fail("��ľ������������书��\n");
if ( me->query("neili") < 30)
return notify_fail("����������������书��\n");
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
          
if(!me->query("env/���帴��")) return;
   if(i>=350){
       if(random(i)>(int)victim->query_skill("parry",1)*2/3
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HIG"$N������צ����������ƣ�$n⧲���������"RED""+name+""HIG"����һצץס�����°�����ԣ����ܶ�����\n"NOR,me,victim);
            victim->set_temp("must_be_hit",1);
            call_out("dgjj_must_be_hit",2,me,victim,random(i/50));
       }
   }
   if(i>=300){
       if(random(i)>(int)victim->query_skill("parry",1)*2/3
        &&random(3)){
            message_vision(HIY"$N��$nԾ�����֮�ʣ�ץס$n���״Ӱ������������һˤ��ֱˤ��$n�߻������ð���ǣ�\n"NOR,me,victim);
            victim->set_temp("must_be_hit",1);
            victim->apply_condition("no_perform",2);
       }
   }


   if(i>=250){
       if(random(i)>(int)victim->query_skill("dodge",1)/2
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(WHT"$nֻ��$N����צӰ���о�ȡ�Լ���"RED""+name+""WHT"����ֻ�������мܣ����޻���֮����\n"NOR,me,victim);
            victim->set_temp("no_fight",1);
            victim->apply_condition("no_fight",1);
       }
   }

        if( weapon1 && i > 200 && living(victim)
         && me->query_skill_mapped("parry") == "ningxue-shenzhua"
         && random(me->query("combat_exp")) > victim->query("combat_exp")/2 ) {
                message_vision(MAG"$N������ץ$n�ġ�"RED""+name+""MAG"������;ȴ�͵ı��У���ֱץ��$n����������һŤ��\n"NOR, 

me,victim);
                if( random(me->query("str")) > victim->query("str")/3 ) {
                        me->add("neili", -50);
                   victim->add_busy(1+random(2));
                        message_vision(HIR"$Nֻ������һ���ʹ��ֻ��������һ��������Ѿ���Ť�ϣ�"+weapon1->name()+HIR"��Ҳ�ѳֲ�ס�����ֶ�����\n"NOR, victim);
                        weapon1->unequip();
                     victim->apply_condition("broken_arm",5); 
                        weapon1->move(environment(victim));
                }
                else {
                        message_vision(HIC"$n���´󺧣���æ���У������ܹ���\n"NOR, me,victim);
                    me->start_perform(1,"������");
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
                        msg = WHT"$N��������צӰ�����о�ȡ$n�����Ѩ��\n"NOR;
                        msg = replace_string(msg, "$w", wp1->name());
                        if(neili >= random(neili1+damage)){
                                if(random(me->query_dex(1)) > ob->query_str(1)/3 && skill > 120){
                                        msg += WHT"���$nһ������ץ���ˡ�"RED""+name+""WHT"������ʽ��ʱ�޷����ᣡ\n"NOR;
                                        ob->add_busy(1+random(2));
                                        j = -(damage);
                                }
                                else{
                                        ob->receive_damage("qi", damage/10, me);
                                        ob->receive_wound("qi", damage/10, me);
                                        p = ob->query("qi")*100/ob->query("max_qi");
                                        msg += COMBAT_D->damage_msg(damage/20, "�˺�");
                                        msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
                                        j = -(damage/2+skill/2);
                                }
                        }
                        else if(neili >= random(neili1)+damage){
                                msg += CYN"$n�벻����֮�£���"RED""+name+""CYN"����΢΢һ�飬��ʱ�е�ȫ�����飬����������ģ�����������\n"NOR;              
                                j = -(damage/2+skill/2);
                        }
                        else{
                                j = damage/2+random(damage/2);
                                if(j<damage/2) msg += CYN"$n�벻����֮�£���"RED""+name+""CYN"����΢΢һ�飬��ʱ�е�ȫ�����飬����������ģ�����������\n"NOR;
                                else msg += CYN"$n�벻����֮�£���"RED""+name+""CYN"����΢΢һ�飬��ʱ�е�ȫ�����飬����������ģ�������������\n"NOR;
                                j = -j;
                        }
                        message_vision(msg, me, ob);
                        return j;
                }
                else{
                        msg = HIY"$N��׼$n���������������У����в���$n�����Ѩ��\n"NOR;
                        if(neili >= neili1+random(neili1)+damage){
                                ob->receive_damage("qi", damage/10, me);
                                ob->receive_wound("qi", damage/10, me);
                                p = ob->query("qi")*100/ob->query("max_qi");
                                msg += COMBAT_D->damage_msg(damage, "����");
                                msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
                                j = -(damage*2+skill);
                        }
                        else if(neili >= random(neili1)+damage){
                                msg += HIW"$nֻ������צӰ������ָ���Լ��ġ�"RED""+name+""HIY"����ֻ����;���У����������\n"NOR;              
                                j = -(damage+skill);
                        }
                        else{
                                j = damage/2+random(damage/2); 
                                if(j<damage/2) msg += HIY"$n������"RED""+name+""HIY"����΢΢һ�飬ֻ����;���У��������Ƿ��Ӳ���һ�롣\n"NOR;
                                else msg += HIW"$nֻ������צӰ������ָ���Լ��ġ�"RED""+name+""HIW"����ֻ�����з��أ��޹�������\n"NOR;
                                j = -j;
                        }
                        message_vision(msg, me, ob);
                        return j;
                }
        }

}
