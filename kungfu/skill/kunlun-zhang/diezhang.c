// kunlun-zhang.pfm ���߰���
// By jpei

#include <ansi.h>
inherit F_SSERVER;

string perform_name() { return HIW"���ص���"NOR; }


int perform(object me, object target)
{
        int i,damage;

        if( !target ) target = offensive_target(me);

        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
                return notify_fail("���ص��ƾ���ֻ����ս����ʹ�á�\n");       
        if( objectp(me->query_temp("weapon")) )
               return notify_fail("�ȷ������е�������˵�ɣ�\n");
        if((int)me->query_skill("strike", 1) < 120 )
                return notify_fail("��Ļ����Ʒ�̫�ͣ��޷�ʹ�����ص���֮������\n");  
        if((int)me->query_skill("kunlun-zhang", 1) < 120 )
                return notify_fail("������ص��ƻ�������죬����ʹ�����ص���֮������\n");
        if (me->query_skill_prepared("strike") != "kunlun-zhang"
           || me->query_skill_mapped("strike") != "kunlun-zhang")
                return notify_fail("�㲻ʹ�����ص��ƣ�������ʹ�����ص���֮��������\n");   
        if( (int)me->query("max_neili", 1) < 1500 )
                return notify_fail("��������Ϊ̫ǳ���޷��˾��˵У�\n");                
        if( (int)me->query("neili", 1) < 1000 )
                return notify_fail("�������������������ܷ������ص���֮������\n");
        if(userp(me) && (int)me->query_skill("xuantian-wuji", 1) < 120 )
                return notify_fail("��������ڹ��ȼ�����������Ӧ�����ص���֮������\n");
        if(userp(me) && me->query_skill_mapped("force") != "xuantian-wuji")
                return notify_fail("����ڹ��ķ����ԣ����Ӳ������ص��ƾ���֮����\n");                                                                                     
        if (userp(me) && me->query_skill_mapped("parry") != "kunlun-zhang")
                return notify_fail("��Ŀǰ�޷�ʹ�����ص���������\n");


  i=me->query_skill("strike",1)/3  + me->query_skill("kunlun-zhang",1)/3 + me->query_skill("force",1)/3 ;

  if(!userp(me))  i = i/6;               //npc�ͷ���������Ϊ1/6
              me->add_temp("apply/strength", i /10);
              me->add_temp("apply/strike", i/2);
              me->add_temp("apply/damage", i/2);
              me->add_temp("apply/attack",i);


 message_vision(HIY"$N�������������ַ���һ�ƣ���Ӳ����Ӳ����ֻ���á��顱��һ����Ӳ��Ӳ�������������������ˣ��м�ʵ��˿��������أ�\n"NOR,me, target);
          me->add("neili", -300);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

        if ( me->is_fighting(target) ){
 message_vision(MAG"$N����˫����������������ƺ�$n������ӣ�������֮��ȴ�ֳ���һ��һ��֮����\n"NOR,me, target);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
       }

	
        if ( me->is_fighting(target)){
	 message_vision(HIG"$nֻ������Է�С����һ������ڿմ�����$N���ŵ�һ��ȴ��������ͭǽ���ڡ�\n"NOR,me, target);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	        }

       if ( me->is_fighting(target) && me->query_skill("kunlun-zhang", 1) > 180 )
           {
 message_vision(WHT"�͵���һ�ɾ���ײ����$n�Լ��ľ��������������ټ���$N��������ֱ�ȵ�$n������Ѫ\n"NOR,me, target);        
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
               damage = i * 2 ;               
               damage = damage  + random(damage);
      if (damage > 2500 ) damage = 2500;
      if( random(me->query("max_neili") ) > target->query("max_neili")/2 && userp(me) )
             {          
              target->receive_damage("qi", damage);
              target->receive_wound("qi", damage/3);
     if(userp(me) && me->query("env/damage"))      tell_object(me,WHT"���"+ target->query("name") +"�����"RED+ damage+ WHT"�㹥���˺���\n"NOR);    
     if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+ damage+ WHT"���˺���\n"NOR);    
                }
             }

me->add_temp("apply/strength",- i /10);
 me->add_temp("apply/strike", -i/2);
 me->add_temp("apply/damage",- i/2);
 me->add_temp("apply/attack",-i);


             me->add("neili", -(200+random(100)));
             me->start_perform(4, "���ص��ƾ���");

             return 1;
}



int help(object me)
{
	write(WHT"\n�����Ʒ�֮��"HIG"���ص���"WHT"����"NOR"\n");
	write(@HELP
    ���������ǵ�һ�� �����ս������

    Ҫ�������Ʒ��������޼��������Ʒ�120��
     
          ��ǰ����1000���ϣ�
          �������1500���ϡ�
HELP
	);
	return 1;
}
