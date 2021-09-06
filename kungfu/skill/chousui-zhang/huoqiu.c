// write by snowman@SJ

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
        || !target->is_character()
        || !me->is_fighting(target)
        || !necessary(target) )
                return notify_fail("�����򡹹���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
      
      	if( (int)me->query("max_neili") < 2500 ) 
                return notify_fail("�㷢���Լ�����̫�����޷����������򡹽��й�����\n");
        if( (int)me->query_skill("huagong-dafa",1) < 180 )
                return notify_fail("�㷢���Լ��Ļ�������Ϊ�������޷�ʹ�á����򡹽��й�����\n");
        if( (int)me->query_skill("poison",1) < 180 )
                return notify_fail("�㷢���Լ����ھ۶��������޷�ʹ�á����򡹽��й�����\n");
        if( (int)me->query_skill("chousui-zhang", 1) < 180 )
                return notify_fail("�㷢���Լ������޶��ƻ�������죬�޷�ʹ�á����򡹽��й�����\n");
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á����򡹣�\n");        
        if( !objectp(ob = present("huo yan", environment(me))) )
                return notify_fail("û�л����ô���������򡹽��й�����\n");
        if( me->query_temp("pfm_chousui") )
                return notify_fail("������������ѽ��й�����\n");

       message_vision(HIR"\n$N������ȣ�������ʢ��������ͻȻ����һ�������"RED"����"HIR"���ڿ��й�µµ��Ѹ��ת����\n\n"NOR,me);

       me->set_temp("pfm_chousui", 1);
       if(random(me->query_kar()) > 3)
             check_pfm(me, target, ob);
       else call_out("check_pfm", 4, me, target, ob);
       return 1;
}

int check_pfm(object me, object target, object ob)
{
        string msg, *limbs;
        int i, neili, ap, dp, damage, p;
        object *inv;
        
        if( !me ) return 0;
        me->delete_temp("pfm_chousui");
        
        if( !living(me) || me->is_ghost() ) return 0;
        
        if(!target 
        || !living(target) 
        || !me->is_fighting(target)
        || environment(me)!=environment(target)){
           	message_vision(HIY"$N�����ٷ����������"RED"����"HIY"ѹ�ػ���֮�С�\n"NOR,me);
           	return 1;
        }  
        
        i = (int)me->query_skill("chousui-zhang", 1);
        neili = (int)me->query("neili");
        me->start_busy(2+random(2));
        
        if(!objectp(present(ob, environment(me)))){
           	message_vision(HIY"$N�ۿ����Ϩ��ɢ����Ϣ�����¾����˫�֡�\n"NOR,me);
           	return 1;
        }
        if (me->query_skill_prepared("strike") != "chousui-zhang"
        || me->query_skill_mapped("strike") != "chousui-zhang"
        || me->query_skill_mapped("parry") != "chousui-zhang"){
                tell_object(me,"������ó����Ʋ���ʹ�á����򡹽��й�����\n"); 
                return 1;
        }                                                                                
        if( me->query_skill_mapped("force") != "huagong-dafa"){
                tell_object(me,"�㷢���Լ����õ��ڹ��޷����С����򡹹�����\n");
                return 1;
        }
        if(neili < 1000){
                tell_object(me,"�㷢���Լ���������̫����ʹ���������򡹽��й�����\n");           
                return 1;
        }           
              

	ap = COMBAT_D->skill_power(me,"strike",SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target,"parry",SKILL_USAGE_DEFENSE);
        if(objectp(target)&&!userp(target))
        	dp /= 2;
        if (ap < 1) ap = 1;
        if (dp < 1) dp = 1;
        me->add("neili", -600);
        me->add("jingli", -100);
   damage = ( i + me->query("jiali") ) * 15;
    if(userp(target)) damage = damage*2/3;
	if( ap < dp ) damage -= random(damage/3);
	if( ap > dp ) damage += random(damage/3);
	
        msg = WHT"\n��ʱ$N�������ް��Ѫɫ��һ�ڿ���Ѫ��ס��"RED"����"WHT"����ȥ!\n"HIR"ɲ�Ǽ�,����һʢ�������������죬"
"��������𻨣�"RED"����"HIR"��Ȼ�����$n���������\n"NOR;

       
           if(random(ap+dp) > dp*4/5){
       		target->add_condition("xx_poison", 30);
		if (userp(me) && userp(target) && me->query_condition("killer") < 15)
			me->apply_condition("killer", 15);
		if(!target->is_busy())
                	target->start_busy(2);
          	//inv = check_armor(all_inventory(target));
          	inv = filter_array(all_inventory(target),(:$1->query("equipped")=="worn":));
		inv -= ({0});
          	if( sizeof(inv) >= 1 ){     
            		if( neili > random(target->query("neili"))*2){
               			if( me->query_str()/3*2 > random(target->query_str()) ){
                  			msg += HIY"���Ҽ�����¶�������𻨱��䣬ը����$p�Ļ��ߣ�\n" NOR;
                  			damage += random(damage)*2;
                  			damage -= target->query_temp("apply/armor");
                  			for(i=0; i<sizeof(inv); i++){
                     				inv[i]->unequip();
                         			inv[i]->move(environment(target));
                         			inv[i]->set("name", "�����" + inv[i]->query("name"));
                         			inv[i]->delete("value");
                         			inv[i]->set("armor_prop", 0);
                         		}     
                  		}                   
            			else {
                  			msg += HIY"ֻ��������Ȼ���£����Ľ�������ֱ͸$p�Ļ��ߣ�\n" NOR;
                  			damage += random(damage);
                  			damage -= target->query_temp("apply/armor");
                  			for(i=0; i<sizeof(inv); i++){
                     				inv[i]->set("name", "���ѵ�" + inv[i]->query("name"));
                        			inv[i]->set("value", 49);
                         			if(inv[i]->query("armor_prop/armor"))
                             				inv[i]->set("armor_prop/armor", inv[i]->query("armor_prop/armor")/2);
                        		}
                  		}
                  		target->reset_action();     
               		}
          		else {
                  		msg += HIY"�����ٹ���������Ľ��������������ײ��$p���\n" NOR;
                  	}
                  	target->receive_damage("qi", damage, me);   
                  	target->receive_wound("qi", damage/2, me);  
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+damage+ WHT"���˺���\n"NOR); ;
            	}
            	
        	else{
                //target has no armor, so, hehe...
                	if( neili > target->query("neili")/2*3 )
                		damage += random(damage);
                	else if( neili < target->query("neili")/3*2 )
                		damage -= random(damage/2);
                	else if( neili > target->query("neili")*2 ) 
                		damage *= 3;
                	damage += random(damage);
                	target->receive_damage("qi", damage, me);   
                	target->receive_wound("qi", damage/2, me);
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+damage+ WHT"���˺���\n"NOR); ;
                }
                p = (int)target->query("qi")*100 / (int)target->query("max_qi");
                msg += damage_msg(damage, "����");
               	msg += "( $n"+eff_status_msg(p)+" )\n";
               	limbs = target->query("limbs");
       		msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
       		msg = replace_string(msg, "$w", RED"����"NOR);   
        }
        
    	else{
    		if(!target->is_busy())
        		target->start_busy(2);
        	msg += HIY"\n$p�ۿ���Ҫ�����У�ð��һ���������š���ȫ����ϥ�Ǵ����ȥ�������ܹ�����"HIY"��\n" NOR;
        }
            
       	message_vision(msg, me, target);
       	if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
       	return 1;
} 

string perform_name(){ return HIR"����"NOR; }
