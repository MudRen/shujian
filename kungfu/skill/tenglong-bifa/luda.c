
// pfm luda
// �ϱ��˱��� & ��ѧЧ��
// create by olives@SJ
// ���� �ټ�һhit������ȡ���Ա�����--by daidai
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include <combat_msg.h>

string perform_name(){ return HIY"³�����"NOR; }

int perform2(object me,object target);
int perform(object me, object target)
{
        int skill,ap,pp,damage,effect,p;
        object weapon = me->query_temp("weapon");
	object vweapon;
        string dodge_skill;
        if( !target ) target = offensive_target(me);

        if(!target
        || !target->is_character()
        || !me->is_fighting(target) )
                return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	vweapon = target->query_temp("weapon");

        if(userp(me) && me->query("family/master_id")!="hong antong")
                return notify_fail("��³�������ֻ�а��˽���������ã�\n");

        if( (int)me->query_skill("tenglong-bifa", 1) < 120 )
                return notify_fail("�������ذ��������죬����ʹ��³�������\n");

    	if( (int)me->query("neili", 1) < 3000 )
       		return notify_fail("�������������㣡\n");
       	if( (int)me->query("jingli", 1) < 500 )
       		return notify_fail("�����ھ������㣡\n");

    	if( (int)me->query("max_neili", 1) < 1500 )
       		return notify_fail("��������Ϊ���㣡\n");
        if( (int)me->query_str() < 30  )
                return notify_fail("�������̫�ͣ�����ʹ��³�������\n");

        if(!weapon
        || me->query_skill_mapped("dagger") != "tenglong-bifa")
                return notify_fail("�������޷�ʹ��³�������\n");


        skill = (int)me->query_skill("tenglong-bifa", 1);
	 ap = me->query("combat_exp")/100*me->query_str();
        pp = target->query("combat_exp")/100*target->query_dex();
        
	
        me->add("neili", -350);
        me->add("jingli", -200);

 if(objectp(vweapon))
     
  {
		 ap *= weapon->query("sharpness");
	        pp *= vweapon->query("rigidity");

 		message_vision(HIY"\n$N˫��һ����������ݣ��ұ�ȴ���Ӷ�����"+weapon->name()+HIY"������$n����"+vweapon->name()+HIY"��"NOR,me,target);
  		if(random(ap+pp)>pp  )
  		{

  			message_vision(WHT"\n���$n����"+vweapon->name()+WHT"Ӧ�ֶ��ϣ�\n"NOR,me,target);
                	vweapon->unequip();
                	vweapon->move(environment(target));
                	vweapon->set("name", "�ϵ���" + vweapon->name());
                	vweapon->set("value", 49);
                	vweapon->set("weapon_prop", 0);
                	target->reset_action();
		}
              else message_vision(CYN"\n���$n���һ���������$N��һ����\n"NOR,me,target);
 	}
 else if((int)me->query_skill("tenglong-bifa", 1)>350)
                    { message_vision(HIY"\n$N˫��һ����������ݣ��ұ�ȴ���Ӷ�����"+weapon->name()+HIY"������$n��"NOR,me,target);
                     me->add_temp("apply/attack", me->query_skill("tenglong-bifa", 1)/2); 
                     COMBAT_D->do_attack(me,target,me->query_temp("weapon"), 3);
                     me->add_temp("apply/attack", -me->query_skill("tenglong-bifa", 1)/2); 
                    }


 	message_vision( HIY"\n$NͻȻһ��ǰ������������$n�����������ֻһ���ƣ�����ץ��$n�ҽ����ף�����"+weapon->name()+HIY"����$nС����\n"NOR, me, target);
	 ap = (int)me->query_skill("dulong-dafa",1) * (int)me->query("neili") * (int)me->query_str();
        pp = (int)target->query_skill("force", 1) * (int)target->query("neili") * (int)target->query_dex();
        ap *= (int)me->query("combat_exp")/200;
        pp *= (int)target->query("combat_exp")/200;
        ap /= 1000;
        pp /= 1000;
	if(!living(target)) pp = 1;


 if(random(ap+pp) > pp/2){
      me->start_perform(4, "��³�������");
        if(!userp(target))   target->start_busy(2);
                damage =  me->query_skill("force")*3;
                damage += me->query("jiali") * 15;
                damage -= target->query_temp("apply/armor") * 2;
                effect = SKILL_D("dulong-dafa")->force_effect(target->query_skill_mapped("force"));
                damage *= (5-effect);
                if (damage < 0) damage = 0;
                damage = damage + random(damage / 2);
                
if(me->query("gender")!="����")
            damage = damage*2/3; 
 // ����������С   
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", random(damage), me);
                target->receive_damage("neili", damage/4);
                me->receive_damage("neili", damage/6);
                if(damage >= 5000)
                        message_vision(HBYEL"��һ������ʹ����ȫ����˿��������أ�$n����������������������֮�䣡\n"NOR, me, target);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
               
message_vision("���ֻ����$nһ���Һ���"+weapon->name()+"����$p��С���Դ���������Ѫ�������أ���\n"NOR, me, target);
                message_vision( "( $n"+eff_status_msg(p)+" )\n", me, target);

 if((int)me->query_skill("tenglong-bifa", 1)>450) { 
   message_vision( HIY"\n$Nһ�����У�"+weapon->name()+HIY"һ�ճ��ƶ�ǰ������$n�������У�"NOR, me, target); 
   perform2(me, target);
   target->add_busy(1);  }
    }

 else {
            me->start_perform(2, "��³�������");
          dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                message_vision( SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);
     message_vision( HIY"\n$Nһ�����У�"+weapon->name()+HIY"һ�չ��ض�ǰ����$n�������У�"NOR, me, target); 
   target->add_busy(1);
    perform2(me, target); 
  }         me->add("neili", -400);
        me->add("jingli", -100);
     
   return 1;
}
 
int perform2(object me, object target)
{int lvl;
object weapon = me->query_temp("weapon");
if( !target
         || !target->is_character()
         || !me->is_fighting(target)
         || !living(target))
            	return notify_fail("ֻ����ս����ʹ�á�\n");
 lvl = (int)me->query_skill("tenglong-bifa", 1)  /3; 

me->add_temp("apply/attack", lvl); 
me->add_temp("apply/damage", lvl); 
me->add_temp("apply/strength", lvl/6); 
      
weapon->unequip();
 
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

 weapon->wield(); 
if ( me->is_fighting(target) && random(me->query_skill("tenglong-bifa", 1)) > 250)
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

me->add_temp("apply/attack", -lvl); 
me->add_temp("apply/damage", -lvl); 
me->add_temp("apply/strength", -lvl/6); 
         me->add("neili", -200);
   me->start_busy(1);
        me->add("jingli", -100);
      }
