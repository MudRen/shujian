#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
      object ob;
        if( !target ) target = offensive_target(me);
    if( !objectp(target)
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����𡹹���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
      
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á����𡹣�\n");        
        if(!objectp(ob = present("huo yan", environment(me))))
                return notify_fail("û�л����ô���������𡹽��й�����\n");
        if(me->query_temp("pfm_chousui"))
                return notify_fail("������������ѽ��й�����\n");

       message_vision(YEL"\n$N����һ����һ�ɾ���ֱ����"HIR"����"YEL"֮�С������ֳַ�һ��ϸϸ��"WHT"����"YEL"������һ��"WHT"��ɫ����"YEL"
���Կռʣ�����ڶ�����ɫ�������ޣ����ǹ��죬"RED"��â"YEL"��˸������\n"NOR,me);
       me->set_temp("pfm_chousui", 1);
       if(random(me->query_kar()) > 3)
             check_pfm(me, target, ob);
       else call_out("check_pfm", 2, me, target, ob);
       return 1;
}

int check_pfm(object me, object target, object ob)
{
        string msg, *limbs;
        int i, neili, ap, dp, damage, p;
        object wep;
        if(!me) return 0;        
        i = (int)me->query_skill("chousui-zhang", 1);
        neili = (int)me->query("neili");        

        me->delete_temp("pfm_chousui");
        me->start_busy(1);
        if(!living(me) || me->is_ghost()) return 1;
        
        if(!objectp(present(ob, environment(me)))){
           message_vision(HIY"$N�ۿ����Ϩ�𣬳�̾һ����ɢ����Ϣ��˫���´�������\n"NOR,me);
           return 1;
        }
        
        if( i < 140 ){
                tell_object(me, "�㷢���Լ������޶��ƻ�������죬�޷�ʹ�á����𡹽��й�����\n");
                return 1;
                }
        if( (int)me->query_skill("huagong-dafa",1) < 140 ){
                tell_object(me,"�㷢���Լ��Ļ�������Ϊ�������޷�ʹ�á����𡹽��й�����\n");
                return 1;
                }
        if((int)me->query_skill("poison",1) < 180){
                tell_object(me,"�㷢���Լ����ھ۶��������޷�ʹ�á����𡹽��й�����\n");         
                return 1;
                }
        if (me->query_skill_prepared("strike") != "chousui-zhang"
        || me->query_skill_mapped("strike") != "chousui-zhang"
        || me->query_skill_mapped("parry") != "chousui-zhang"){
                tell_object(me,"������ó����Ʋ���ʹ�á����𡹽��й�����\n"); 
                return 1;
                }                                                                                
        if( me->query_skill_mapped("force") != "huagong-dafa"){
                tell_object(me,"�㷢���Լ����õ��ڹ��޷����С����𡹹�����\n");
                return 1;
                }
        if( (int)me->query("max_neili") < 1200) {
                tell_object(me,"�㷢���Լ�����̫�����޷����������𡹽��й�����\n");
                return 1;
                }
        if(neili < 900){
                tell_object(me,"�㷢���Լ���������̫����ʹ���������𡹽��й�����\n");           
                return 1;
                }
        if(!target || !living(target)
           || !me->is_fighting(target)
           || environment(me)!=environment(target)){
           message_vision(HIY"$N�����ٷ����������"WHT"����"HIY"ѹ�ػ���֮�С�\n"NOR,me);
           return 1;
           }
       

        ap = me->query("combat_exp")/1000 * i * me->query_str();
        dp = target->query("combat_exp")/1000 * target->query_skill("parry",1) * target->query_str();
        if (ap < 1) ap = 1;
        if (dp < 1) dp = 1;
        me->add("neili", -500);
        me->add("jingli", -50);

        msg = YEL"\nͻȻ����������"GRN"��ɫ���"YEL"����ʱ"WHT"����"YEL"ٿ�����أ���������$n$l��ȥ���������ͣ�ȥ����죡\n"NOR;        

       
        if(random(ap+dp) > dp){
        	me->start_busy(2);
		if(objectp(wep = target->query_temp("weapon")) && random(2)==1){     
            		msg += HIY"������������Ѹ���޳������޿ɱܣ�ֻ�ð���������������Ӳ����\n" NOR;
            		if(me->query("neili") < target->query("neili")/2)
                   		msg += HIY"���ֻ��һ�����죬$w"HIY"��$W"HIY"��ײ�������ɻ�����ɢ������\n" NOR;
                   	
            		else if(me->query("neili") > target->query("neili")/2*3){
                   		if(wep->query("rigidity") >= 1){
                      			target->start_busy(4);
                      			wep->unequip();
                      			wep->move(environment(target));
                      			msg += HIW"���ֻ�����ԡ���һ������$w"HIW"������ײ���£�$n�������ѣ�$W"HIW"���ַɳ���\n" NOR;
                      			target->reset_action();
                      		}
                   		else{
                      			target->start_busy(2);
                      			msg += HIW"���ֻ����ž����һ�����죬$n����"+wep->name()+HIW"��$w"HIW"��ϣ���Ƭ��ɢ���䣡\n" NOR;
                      			wep->unequip();
                      			wep->move(environment(target));
                      			wep->set("name", "�ϵ���" + wep->query("name"));
                      			wep->set("value", 49);
                      			wep->set("weapon_prop", 0);
                      			target->reset_action();
                      		}
                  	}
            		else {
                   		if(wep->query("rigidity") >= 1){
                      			target->start_busy(4);
                      			msg += HIY"���ֻ��һ�����죬$w��$W��ײ�������ɻ�����ɢ������\n" NOR;
                      		}
                   		else{
                      			target->start_busy(2);
                      			wep->unequip();
                      			wep->move(environment(target));
                      			msg += HIW"���ֻ�����ԡ���һ������$w"HIW"������ײ���£�$n�������ѣ�$W"HIW"���ַɳ���\n" NOR;
                      		}
                  	}
            	msg = replace_string(msg, "$W", wep->name());
        	}
        
        	else{
                	damage = (i+me->query("jiali"))*4;
                	if(neili > target->query("neili")*2) damage *= 2;
    //                    if( damage > 2000 ) damage = 2000;
                	target->receive_damage("qi", damage, me);    
                	target->receive_wound("qi", damage/2, me);            
                	target->apply_condition("xx_poison", random(3) + (me->query_skill("poison", 1)/10) + target->query_condition("xx_poison"));
			if (userp(me) && userp(target) && me->query_condition("killer") < 15)
				me->apply_condition("killer", 15);
                	p = (int)target->query("qi")*100/(int)target->query("max_qi");
                	msg += damage_msg(damage, "����");
                	msg += "( $n"+eff_status_msg(p)+" )\n";
                	target->start_busy(3);
                }
        }
        
        else{
          	me->start_busy(3);
          	msg += HIY"\n$pȫ������һ������$w"HIY"��������������˵��������ޱȣ�\n" NOR;
        }
        
       limbs = target->query("limbs");
       msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
       msg = replace_string(msg, "$w", WHT"����"NOR);   
       if(!target->is_killing(me->query("id"))) target->kill_ob(me);    
       message_vision(msg, me, target);
       return 1;
}  

string perform_name(){ return YEL"����"NOR; }