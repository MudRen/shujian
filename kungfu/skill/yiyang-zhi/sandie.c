// /kungfu/skill/yiyang-zhi/sandie.c
// COOL@SJ
// Modified by snowman@SJ 05/12/2000

#include <ansi.h>
inherit F_SSERVER;
#include <combat_msg.h>
#include <combat.h>
 
string perform_name() {return YEL"��������"NOR;}

int perform(object me, object target)
{       
        string msg;
        int damage;
        
        if( !target ) target = offensive_target(me);
 
        if( !objectp(target)
         || !target->is_character()
         || !me->is_fighting(target))
                return notify_fail("������������ֻ����ս����ʹ�á�\n");
        if( !living(target) )
        	return notify_fail("�Է��Ѿ��ι�ȥ�ˡ�\n");
        	
        if( objectp( me->query_temp("weapon")) )
                return notify_fail("ֻ�п��ֲ���ʩչ��������������\n");

        if((int)me->query_skill("yiyang-zhi", 1) < 100 
         ||(int)me->query_skill("finger", 1) < 100 
         ||(int)me->query_str() < 25)
                return notify_fail("���еĹ��򻹲�����죬����ʹ�á�������������\n");

        if(!me->query_skill("kurong-changong", 1))
          if(me->query_skill("qiantian-yiyang", 1) <100)
                return notify_fail("�������ڵ��ڹ���Ϊ��ʹ������������������\n");        
         
        if (me->query_skill_mapped("force") != "kurong-changong" )
        if (me->query_skill_mapped("force") != "qiantian-yiyang")
                return notify_fail("����ʹ�õ��ڹ����ԡ�\n");

        if (me->query_skill_prepared("finger") != "yiyang-zhi" 
         || me->query_skill_mapped("finger") != "yiyang-zhi" )
                return notify_fail("�������޷�ʹ�á��������������й�����\n");
 
        if(me->query_temp("start_6mai"))
                return notify_fail("���Ѿ������������񽣵����ν����ˣ�\n");

        if (me->query_skill_mapped("parry") != "kurong-changong" )
           if (me->query_skill_mapped("parry") != "yiyang-zhi")
                return notify_fail("����ʹ�õ��мܲ��ԡ�\n");

        if((int)me->query("max_neili") < 1500 )
                return notify_fail("���������Ϊ̫��������ʹ�á�������������\n");

        if((int)me->query("neili") < 800 )
                return notify_fail("�������������\n");
               
    
                if((string)me->query("class")=="bonze")
           	msg = YEL "\n$N˫�ƺ�ʲ�����е��з�ţ�������ָ��һʽ����ɷ��������������͵�һ�����죬һ�ɴ���������ֱϮ$n�ؿڣ�\n" NOR;
        else if ((string)me->query("class")=="officer")
           	msg = YEL "\n$Nʹ�����������������У��뷢����, ����֮�������һ������ɷ��,һָ���������������������һ�ɴ���������ֱϮ$n�ؿڣ�\n" NOR; 

        else msg = YEL "\n$Nʹ�����������������У����һ������ɷ��,һָ���������������������һ�ɴ���������ֱϮ$n�ؿڣ�\n" NOR; 

        
 if( random( me->query("combat_exp") ) > target->query("combat_exp")/2  
        || target->is_busy() 
        || me->query("env/һ��ָ") == "��ɷ" 
     )
         {
             	damage =(int)me->query_skill("kurong-changong", 1) * 3 + (int)me->query_skill("finger",1) * 3 + (int)me->query_skill("qiantian-yiyang", 1) * 3;
             	damage += (int)me->query_skill("kurong-changong", 1);

             	if( random(me->query("neili")) > target->query("neili")/2 )
                     	damage += random(me->query("jiali"))*2;
                if (me->query("max_neili") > target->query("max_neili")*2 ) 
                       	damage *= 2;
                       	
        	damage = random(damage)+damage;

               if(!userp(me)) damage = damage / 3;
               
            	target->receive_damage("qi", damage, me);
            	target->receive_wound("qi", damage/3, me);               
            	me->add("neili", -(damage/5));
            	msg += damage_msg(damage, "����")+
        	"( $n"+eff_status_msg((int)target->query("qi")*100/(int)target->query("max_qi"))+" )\n"; 

              if(me->query_skill("yiyang-zhi", 1) >=140)
            	{      	me->start_perform(5, "����");
                   	call_out("perform2",1,me, target);       
                }
                else me->start_perform(4, "��ɷ");
	}
else
        {
                me->start_busy(2);
                me->add("neili", -70);                
                msg += HIY"$p����ָ��Ϯ����֪���޷�Ӳ����һ�����Ʒ���ԶԶ�Ķ��˿�ȥ��\n"NOR;
              if(me->query_skill("yiyang-zhi", 1) >= 140)
                        { 
                    	me->start_perform(5, "����");
                    		call_out("perform2", 1, me, target);
        	        }
                else me->start_perform(4, "��ɷ");
	}        
        message_vision(msg, me, target);
            	
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"HIR+ damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"HIR+ damage+ WHT"���˺���\n"NOR);
 
       return 1;
}

int perform2(object me, object target)
{
        int f,i;
        string msg;
        
	if (!me ) return 0;        
        
        if( !living(me) ) return 0;
        
        if(!target
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target) )
               return notify_fail("����Ҫ��һ�У�ȴ�������Ѿ����ô��ˡ�\n");;

        if((int)me->query("neili", 1) < 400 )
               return notify_fail("���Ҫ����һָ��ȴ�����Լ������������ˣ�\n");;    

        if( (int)me->query_skill("yiyang-zhi", 1) < 140)               
               return notify_fail("���һ��ָ��Ϊ�������޷�ʹ������������ ֮ ���񡹡�\n");;
     
   
 
        f = (int)me->query_skill("yiyang-zhi",1);
          
        
        if( target->is_busy() ){
          	msg = YEL "\n������$Nһ��ָ�ڶ��ε��������һָ��һʽ�����񡹵�����������͵�һ�����죬һ�ɴ�����ָ��͸��$n���������Ϲ�Ѩ��\n" NOR;
          	i = 2+random(2);
        }
        else {
   	msg = YEL "\n������$Nһ��ָ�ڶ��ε�����Դ���������ͬʱ͸��$n���������Ϲ�Ѩ����ά�����Ѩ����������Ѩ����������Ѩ������������Ѩ��\n"NOR;        
          	i = 2;
        }


 if( random(me->query_skill("force")) > target->query_skill("force")/i
   || me->query("env/һ��ָ") =="����" 
)
         {
        	
                me->add("neili", -f/2);
                msg += HIR "$nֻ��һ������֮�����������澭����,ȫ������ů����ģ���Ȼ�᲻��һ˿������\n" NOR;
                target->add_temp("apply/attack", -f/6);
                target->add_temp("apply/dodge", -f/6);
                target->add_temp("apply/parry", -f/6); 
                target->add_temp("apply/strength", -f/6); 
                if( random(2) ) 

                 	target->apply_condition("no_exert", 2);
                else  
                 	target->apply_condition("no_perform", 2);
                 target->add_busy(random(2)+1);
                 	
                target->set_temp("sandie/jingshen",f/6);

     call_out("sandie_back", 5+random(20), target, f/6);

                if((int)me->query_skill("yiyang-zhi", 1) >= 180 )
                {
                 	remove_call_out("perform3");
                 	call_out("perform3", 1, me, target);
                 }
        }



 else{
   
               me->add("neili", - 100);
                msg += HIY"\n��������һ��˲��ֿ�,ȴ��$p��������ڹ�����ȥ�˹������ڵ�һ��ָ����\n" NOR;
                if((int)me->query_skill("yiyang-zhi", 1) >= 180)
                {
                  	call_out("perform3", 1, me, target);
                 }
        }
        me->start_perform(4, "����");     
        message_vision(msg, me, target);


        return 1;
}



int perform3(object me, object target)
{
       
        int i,j;
 	string msg;
	if( !me ) return 0;

	if( !living(me) ) return 0;
	
	if(!target
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target) )
               return notify_fail("����Ҫ��һ�У�ȴ�������Ѿ����ô��ˡ�\n");

        if((int)me->query("neili", 1) < 300 )
		return notify_fail("���Ҫ����һָ��ȴ�����Լ������������ˣ�\n");

        if( (int)me->query_skill("yiyang-zhi", 1) < 180)
               return notify_fail("���һ��ָ��Ϊ�������޷�ʹ������������ ֮ ���졹��\n");
        
                j= me->query_skill("yiyang-zhi",1);
        i = j /35;
     
        if(i>5) i=5; 
   
	me->start_perform(5, "����");

       msg = YEL"\n����$N̤ǰһ����������ָ�����졹���յ���$n��ǰ������Ѩ������Ѩ�������֮�\n"NOR;

        if( random(me->query_skill("parry")) > target->query_skill("parry")/3 
             || me->query("env/һ��ָ") =="����" 
          ){
       msg += HIR "���һָ���У�$nֻ��������ͨ���������������ܸ��ӣ�\n"NOR;
                target->start_busy( i );
                target->add("neili", -me->query_skill("force"));
                me->add("neili", -(me->query_skill("force")/3));
             
             if( (i >=5  && userp(me))
                 || ( random(10)> 5 && me->query("env/һ��ָ") =="����") 
                 )
                  {
          	msg += HIM"\n$NǱ����������ɫ����������\n"NOR;
                          me->start_call_out( (: call_other, __DIR__"yizhisanmai", "yzsm_attack", me, 2 :), 1 );
                   }
  }
       
         else {
               	me->start_busy(1+random(2));
                me->add("neili", -200);
                target->add("neili", -random(100));
                msg += HIY"\n$p����ָ��Ϯ����֪���޷�Ӳ������Ҳ����һ������������������$p˳�����˿�ȥ��\n" NOR;
               }


        message_vision(msg, me, target);
        return 1;
}

void sandie_back(object target, int i)
{        
        if( !target ) return;
        target->add_temp("apply/attack", i);
        target->add_temp("apply/dodge", i);
        target->add_temp("apply/parry", i); 
        target->add_temp("apply/strength", i); 
        target->delete_temp("sandie/jingshen");
}



int help(object me)
{
   write(WHT"\nһ��ָ֮��"HIY"��������"WHT"����"NOR"\n\n");
   write(@HELP
��           μ�ǳ��꣬һ�����᳾��
             ������������࣬Ū������ǧ����ɫ�¡� 
             ������������࣬ǧ����ɫ�¡�
             �ݷ��գ�Ȱ������һ���ƣ�
             �������٣��ԹŸ������ж��֣�Īǲ��������
             �ݷ��գ�Ȱ������һ���ƣ�
             ֻ�����������أ��������Σ���ǰ�޹���

       ȡ������������ӽ֮̾��˼��������ָ������ɷ�˵���Ѫ���Ծ���һ��ָָ������
       ��������������˲����б������������˷������мܣ����͵������С�����Խ���ָ
       ����Ѩʹ֮æ�ҡ�������Ȼ����������һ��ָ������˫�������ޱȡ�


  ����Ҫ��һ��ָ������ָ����100�����ϡ�
           Ǭ��һ��100������ ��ʹ�ÿ���������
           �������1500���ϣ���ǰ����800���ϡ�

  �������ݣ� 
       set һ��ָ  ��ɷ   Ч��Ϊ�����ɷ����
                   ����   Ч��Ϊ��߾�������
                   ����   Ч��Ϊ��߽�������
                   ����   Ч��Ϊ��ߺ��еļ���


HELP
   );
   return 1;
}




