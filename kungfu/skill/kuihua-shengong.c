// kuihua-xinfa.c �����ķ�

inherit FORCE;
#include <ansi.h>


string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",
"ӿȪѨ","��׶Ѩ","�縮Ѩ",
}); 


int valid_enable(string usage) { 
if ( this_player()->query("quest/pixie/pass") ) return usage == "force"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("kuihua-shengong", 1);
	if ((int)me->query_skill("force", 1) < 10)
        return notify_fail("��Ļ����ڹ�����㣬����ѧ�����ķ���\n");
        
        if (i > 100 && (int)me->query("shen") > i*i*i/20 )
		return notify_fail("ѧ�����ķ���Ҫ�ĺ���������������������ò���ѽ��\n");
		
	if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) )
		return notify_fail("������ͺ¿ţ�����ǵ��ķ�����ѧ�����ķ���ʲ�ᣡ\n");

	if (
	   me->query_skill("shenzhao-jing",1)
	|| me->query_skill("taixuan-gong",1)
	|| me->query_skill("jiuyin-zhengong",1)
	|| me->query_skill("hamagong",1))

		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����ķ�����\n");
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
		else return notify_fail("�����ڵ���Ϊ��������߿������ˡ�\n");
	}
	else return notify_fail("�����񹦲��������ϰ��\n");
}

string exert_function_file(string func)
{
	return __DIR__"kuihua-shengong/" + func;
}

mapping exercise_msg(object me)
{
	return ([
		"status_msg" : MAG + me->name()+"�����廨�룬˫Ŀ�ʹ�����"NOR ,
		"start_my_msg" : MAG"�������廨�룬��ϥ���£�Ĭ�˿����񹦣�ֻ����������������ʼ�����ڻ����ζ���\n"NOR,
		"start_other_msg" : MAG + me->name()+"�����廨����ϥ���£������ƺ�������һ������֮�С�\n"NOR,
		"halt_msg" : MAG"$N�����廨�룬��������Ѹ�ٽ������ڡ�\n"NOR,
		"end_my_msg" : MAG"�㽫����������������һ�����죬�����������ڵ������̧�����۾���\n"NOR,
		"end_other_msg" : MAG"ֻ��"+me->name()+"���������۾����������ֵ���������ȥ��\n"NOR,
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
            message_vision(HBMAG"$N���й��죬ָ��������$n⧲���������"RED""+name+""HBMAG"����"+weapon->name()+HBMAG HIG"���У����°�����ԣ����ܶ�����\n"NOR,me,victim);
            victim->set_temp("must_be_hit",1);
            victim->add_busy(1+random(2));
            victim->apply_condition("no_fight",1);
            call_out("dgjj_must_be_hit",2,me,victim,random(i/50));
       }
   }
   if(i>=300){
       if(random(i)>(int)victim->query_skill("parry",1)/3
        &&random(3)){
            message_vision(HIC"$N����"+weapon->name()+HIC"ٿ��ٿ������ͬ���ȣ����в���$n�ġ�"RED""+name+""HIC"����\n"NOR,me,victim);
            message_vision(RED"���һ�е��֣�$n�ġ�"HIR""+name+""RED"�������˸�ͨ͸��\n"NOR,me,victim);
            victim->set_temp("must_be_hit",1);
            victim->apply_condition("no_perform",2);
       }
   }


   if(i>=250){
       if(random(i)>(int)victim->query_skill("dodge",1)/3
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(WHT"$N��Ȼ����Ϊ��������"+weapon->name()+WHT"�û����������н��ƣ�ֱȡ$n��"RED""+name+""WHT"����$n��ǰһ����ֻ�������мܣ����޻���֮����\n"NOR,me,victim);
            victim->set_temp("no_fight",1);
            victim->apply_condition("no_fight",1);
       }
   }

        if( weapon1 && i > 200 && living(victim)
         && me->query_skill_mapped("force") == "kuihua-shengong"
         && me->query_skill_mapped("sword") == "pixie-jian"
         && random(me->query("combat_exp")) > victim->query("combat_exp")/2 ) {
                message_vision( HBMAG HIC "$N��ʽ����������"+weapon->name()+"���ƴ���$n�ġ�"HIR""+name+""HBMAG HIC"������;ȴ�͵ı��У���ֱ��������\n"NOR, 

me,victim);
                if( random(me->query("dex")) > victim->query("dex")/3 ) {
                        me->add("neili", -50);
                   victim->add_busy(1+random(2));
                        message_vision( HBMAG HIG"$Nֻ������һ���ʹ���ֽ��Ѿ����������ϣ�"+weapon1->name()+HBMAG HIG"��Ҳ�ѳֲ�ס�����ֶ�����\n"NOR, victim);
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
                      if(wp)  msg = RED"$Nһ����Ц������Ｒ����ǰ�������Ƕ������ã�һ˲֮�䣬"+wp->name()+RED"��$n�ġ�"HIR""+name+""RED"������Ѳ���һ�磡\n"NOR;
                     else msg = RED"$Nһ����Ц������Ｒ����ǰ�������Ƕ������ã�һ˲֮�䣬��$n�ġ�"HIR""+name+""RED"������Ѳ���һ�磡\n"NOR;
                       
                        if(neili >= random(neili1+damage)){
                                if(random(me->query_dex(1)) > ob->query_dex(1)/3 && skill > 120){
                                        msg += WHT"���$nһ�����񣬡�"RED""+name+""WHT"���Ѿ����������ˣ���ʽ��ʱ�޷����ᣡ\n"NOR;
                                        ob->add_busy(2+random(2));
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
                                j = -(damage/3+skill/3);
                        }
                        else{
                                j = damage/4+random(damage/4);
                                if(j<damage/2) msg += CYN"$n�벻����֮�£���"RED""+name+""CYN"����΢΢һʹ����ʱ�е�ȫ�����飬����������ģ����������\n"NOR;
                                else msg += CYN"$n�벻����֮�£���"RED""+name+""CYN"����΢΢һʹ����ʱ�е�ȫ�����飬����������ģ�����������\n"NOR;
                                j = -j;
                        }
                        message_vision(msg, me, ob);
                        return j;
                }
                else{
                     if(wp) {   msg = HBYEL MAG"$Nһ����У����������ڰ����һת������ޱȵķ�������������"+wp->name()+HBYEL MAG"�ƿ�ֱ��������\n"NOR;
                        msg += HBMAG HIC "$N��һ������һ������һ������һ������$n��������������������"+wp->name()+HBYEL MAG"һת������$n�ġ�"RED""+name+""CYN"����\n"NOR;}
                     else  
                        msg = HBMAG HIC "$N��һ������һ������һ������һ������$n������������������ָ�罣������$n�ġ�"RED""+name+""CYN"����\n"NOR;
                        if(neili >= neili1+random(neili1)+damage){
                                ob->receive_damage("qi", damage/10, me);
                                ob->receive_wound("qi", damage/10, me);
                                p = ob->query("qi")*100/ob->query("max_qi");
                                msg += COMBAT_D->damage_msg(damage, "����");
                                msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
                                j = -(damage+skill);
                        }
                        else if(neili >= random(neili1)+damage){
                                msg += HBMAG HIC "$n����������ֻ����"RED""+name+"" HBMAG HIC"��΢΢һ�飬��æ���з��أ��޹�������\n"NOR;     
                                j = -(damage/2+skill);
                        }
                        else{
                                j = damage/3+random(damage/3); 
 
                                 msg += HBMAG HIC "$n����������ֻ����"RED""+name+"" HBMAG HIC"��΢΢һ�飬��æ���з��أ��޹�������\n"NOR;
                                j = -j;
                        }
                        message_vision(msg, me, ob);
                        return j;
                }
        }

}
