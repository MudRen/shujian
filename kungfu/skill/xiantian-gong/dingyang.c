//dingyang.c ������;
//Modify By jpei
//��һ�ƴ�ѧ�ö��������Ҫ������ϰ���ܻ�Ȼ��ͨ
//������Ϊtry,��������
 
#include <ansi.h>
inherit F_SSERVER;
 
string exert_name() {return HIB"������"NOR;}

int exert(object me)
{
        string msg;
        object target;
        int skill, ap, dp, p, force, neili_wound, qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("xiantian-gong",1);

        if( !(me->is_fighting() ))
                return notify_fail("�������롹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if((string)me->query_skill_mapped("force") != "xiantian-gong" )
		  return notify_fail("���������롹���ǵ������칦�ľ�ѧ��\n");

        if( skill < 220)
                return notify_fail("������칦��������, ����ʹ�á������롹��\n");

        if( me->query("neili") < 2000 )
                return notify_fail("��������������޷����á������롹��\n");

       if( !me->query("quanzhen/force")  )
                return notify_fail("����Ȼ��˵���������롹�����ǲ�֪��������á�\n");     

        if( me->query("max_neili") < 2500 )
                return notify_fail("��������������޷����á������롹��\n");
 
         msg = HIY"\n$NĬ�����칦����������������һ��ָָ����ӭ��һָ����ֱ����$nü�ģ����ǵ���һָ���Ƹ�󡹦������������"HIR"������"HIY"������\n"NOR;

        ap = me->query_skill("force",1) + skill;
        dp = target->query_skill("force",1)+ target->query_skill("parry",1);
        if( dp < 1 ) dp = 1;
  	
if( me->query("quanzhen/force")=="try" )
 {        ap = ap/4;
    	msg += HIY"ֻ��$N��ѧէ��֮�£������ܺܺõķ��Ӷ������������\n"NOR;

   if( me->query("kar")<31 && random(me->query("kar"))>27 && random(50)==5 && me->query_skill("xiantian-gong",1)>=350 ){

		      	msg += HBBLU"$N��Ȼ�������飬���칦���������У���ȱ�裬��������أ���������������֮���������������Ȼ��ͨ��\n"NOR;	     
	           me->set("quanzhen/force","pass");
  me->set("title",HIR"ȫ����ƽ�"HIR" "HIC"���칦����"NOR);
}
 }   
         message_vision(msg, me, target);


   if( random(ap+dp ) > dp ||   ( me->query("str")>30 && random( me->query_str(1)) > target->query_dex(1)/3 ) ||(!userp(target) &&me->query("str") >41) ){
                if(userp(me))   me->add("neili",-(1500+random(500)));
           msg = HIW"\n$n������������$Nһָ���У�ֻ������������͸����룬��Ȼ��嫣�Ī��֮�С����º��Ļ����ɢ��\n" NOR;   
           message_vision(msg, me, target);
      
           p = (int)me->query_skill("force",1) + random(me->query_skill("force",1)*3);

        if( target->query_skill("hamagong",1) >=1 && target->query("oyf/hamagong",1)<3 ){
				target->start_busy(p/10);
				target->add_temp("apply/force", -p);
				target->add_temp("apply/damage", -p);
								target->add_temp("apply/attack", -p);
								target->add_temp("apply/dodge", -p);
								target->add_temp("apply/parry", -p);
							   target->add("neili", -p*200);
				   if( target->query_skill_mapped("force") )         target->map_skill(force); 
				tell_object(target, HIR"��������޸�󡹦��������һָ���ƣ����ɵ��������ң�\n" NOR);
				return 1;
		       	}
      if( target->query_temp("hmg_nizhuan") && target->query("oyf/hamagong",1)==3 ){

         message_vision(HIW "\n$n������ת����������$Nһָ��ȥ��ֻ�������аܸ������������ţ�뺣��˿���������á�\n" NOR, me,target);
                target->add_busy(2);
                me->start_exert(1+random(2),"������");
				return 1;
		       	}


                        qi_wound = ap * 2 +random(ap*2) ;
                     neili_wound = ap * 3 +random(ap*3);
                
                if(neili_wound > target->query("neili"))
                   neili_wound = target->query("neili");

                if(qi_wound > target->query("qi"))
                   qi_wound = target->query("qi");


      if( target->query("relife/gifts/total")>=150 ){

         message_vision(HIW "\n����$n������ѧ���£������������಻����ת���ݣ�$Nһָ��ȥ��ֻ�������аܸ���������\n" NOR, me,target);
                target->add("neili", -neili_wound);
                target->add("qi", -qi_wound);
                target->add("eff_qi", -qi_wound*2/3);
                target->add_busy(2);
                me->start_exert(1+random(2),"������");
				return 1;
		       	}

   
  
         if(random(3)== 1)            target->apply_condition("no_perform", 1+ random(2));
         if(random(3)== 1)            target->apply_condition("no_exert", 1+ random(2)); 
         if(random(3)== 1)            target->apply_condition("no_fight", 1+ random(2)); 
                target->add("neili", -neili_wound);
                target->add("qi", -qi_wound);
                target->add("eff_qi", -qi_wound*2/3);
                target->add_busy(2);
                if(target->query_skill_mapped("force") ) target->map_skill("force");

            me->start_exert(2+random(2),"������");
if( me->query_skill("xiantian-gong",1)<=550 )
            me->start_perform(1,"������");
       }

 else
              { 

         msg = YEL"\n$nֻ����$Nָ��͸����룬����������Ȼ��嫣�Ī��֮�С�����ֻ�÷�����ˣ�\n" NOR;
         message_vision(msg, me, target);
//     if (me->query("quanzhen/force") =="pass" )     target->add_busy(1);
                 me->add_busy(1+random(2));
                me->start_exert(1+random(2),"������");
         }

        return 1;

}
int help(object me)
{
	write(HIC"\n���칦�������롹��"NOR"\n");
	write(@HELP
 
��������֮�������롹
 
          ����һָ���Ƹ�󡹦��������������������������һ��ָָ�������Ƶ��˻���������
          
	
 Ҫ��	��ǰ���� 2000 ���ϣ�
              ������� 2500 ���ϣ�
              ���칦 220 �����ϣ�
              �õ����������칦�洫�ĵ��ӿ���ʹ�á�
              �ߵı������ڹ��ȼ��ж����Ч���� 

HELP
	);
	return 1;
}

