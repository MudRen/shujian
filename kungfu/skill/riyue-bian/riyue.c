// riyue ���±�-����
// campsun

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{

        int i = me->query_skill("riyue-bian", 1) /2;
     
        int j = me->query("jiali") + 20;//ԭ����10
   
        string msg,dodge_skill;

     object weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !me->is_fighting(target) )
                return notify_fail("��������ת��ֻ����ս���жԶ���ʹ�á�\n");

        if (!weapon || weapon->query("skill_type") != "whip")
                return notify_fail("����û������,���ʹ�á�������ת����\n");

        if( (int)me->query_skill("riyue-bian", 1) < 180 )
                return notify_fail("������±޷�������죬����ʹ�á�������ת����\n");

        if( (int)me->query_skill("yijin-jing", 1) < 180 )
                return notify_fail("����׽�ȼ�����������ʹ�á�������ת����\n");

        if( (int)me->query_skill("buddhism", 1) < 180 )
                return notify_fail("��������ķ��ȼ�����������ʹ�á�������ת����\n");
          
        if( (int)me->query("max_neili") < 2500 )
          return notify_fail("������������Ϊ̫��������ʹ�á����¡���\n");
      
        if( (int)me->query("jingli") < 500 )
          return notify_fail("����������̫�٣�����ʹ�á����¡���\n");
       
        if ( me->query_skill_mapped("parry") != "riyue-bian")
          return notify_fail("���мܲ��ԣ�����ʹ�á����¡���\n");
    
        if ( me->query_skill_mapped("force") != "yijin-jing")
          return notify_fail("�����ʹ�������ķ����ܴ߶���������ת����\n");
               
        if( (int)me->query("neili") < 1000 )
                return notify_fail("����������̫��������ʹ�á����¡���\n");

        msg = HIC "$N���и�����ţ�ʹ�����±��С�������ת�����������г����������裬���������Ҳ������϶�������$n,\n" NOR;
        msg += HIC "����$N����һ��������������צ��ī�����ƣ��������ϣ�����$n�˵���\n"NOR;
        message_vision(msg, me, target);
   
         me->set_temp("ryb_riyue", 1);
         me->add_temp("apply/attack", i);
         me->add_temp("apply/damage", j);
  
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3); 
    
    if( me->is_fighting(target) ) 
    	   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
    
    if( me->is_fighting(target) && (int)me->query_skill("riyue-bian", 1) > 220)  
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

        me->add_temp("apply/damage", -j);
        me->add_temp("apply/attack", -i);
 if(me->is_fighting(target) ){
 	
 if(random(10)<5) {          
        msg = HIY"\n������$N�����������ӷ𣡡���ʹ������ �� ���־������г���һ���$n���ʺ��ȥ����ͷδ����������Ю\n"
                 + "����������յ��գ���Է�һ�����ϣ�ֻ������žž���������죬��ͷ���𣬱���һ�������Ķ��ߺ��ط�\n"
                 + "�ɻӶ�������������ɳ����Х������\n"NOR; 
        message_vision(msg, me, target);
              
             COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      if( me->is_fighting(target) ) 
  	         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        me->delete_temp("ryb_riyue");      
        me->add("neili", -400);
        me->start_busy(2+random(2));

        }
        
        
   else { 
          msg = HIC "\n������$N�������ҷ�ȱ�������ʹ������ ת���־����������տ�����������������¶��ǣ����г����趯ʱ\n"
                     +"�Ʋ������Ӱ��������Ϣ���ƻ�ʵ����ȴ���ް�������������ȣ�˵�����Ĺ���Ī����\n"NOR;
        message_vision(msg,me,target);
      
        if (random(10)>6) 
                {
                         msg=HIR"���$Nһ��С�ģ���ʱ��û�������Ӱ֮�С�\n"NOR;
                   message_vision(msg,target);        
                   me->delete_temp("riyue");      
                   target->start_busy(2+random(2));
                   me->add("neili",-400);
                 }
        else {
                dodge_skill = target->query_skill_mapped("dodge");
               if( !dodge_skill ) dodge_skill = "dodge";
                     msg=HIR"$N���Ʋ��ã������ˣ�����������Ӱ��\n"NOR;
                   message_vision(msg,target);        
         me->delete_temp("ryb_riyue");      
        me->start_perform(5, "��������ת��");
                me->add("neili",-200);
                }
        }
       
  }      
        me->delete_temp("ryb_riyue");      
return 1;

}

string perform_name(){ return HIC"������ת"NOR; }
int help(object me)
{
	write(HIC"\n���±ޡ�������ת����"NOR"\n");
	write(@HELP
	
	Ҫ��	������� 2500 ���ϣ�      
		��ǰ���� 1000 ���ϣ� 
		��ǰ���� 500 ���ϣ� 
		�׽�ȼ� 180 ���ϣ�
		���±޷��ȼ� 180 ���ϣ�
		�����ķ��ȼ� 180 ���ϣ�
		�������±޷�Ϊ�мܣ�
		�����׽Ϊ�ڹ���
		װ�������������     
HELP
	);
	return 1;
}

