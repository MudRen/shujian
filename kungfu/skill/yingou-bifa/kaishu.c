//kaishu.c ����
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string perform_name(){ return HIC"����"NOR; }

int perform(object me, object target)
{
      string msg; 
      int i;                                  
      object weapon = me->query_temp("weapon");

      if (!weapon || weapon->query("skill_type") != "brush")
         return notify_fail("������û�бʣ��޷�д�����飡\n");

      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
         return notify_fail("����ֻ����ս���жԶ���ʹ�á�\n");
             
      if((int)me->query_skill("yingou-bifa",1) < 80 )
         return notify_fail("��������ʷ���������죬����д�����飡\n");
      
      if((int)me->query_skill("literate",1) < 80 )
         return notify_fail("��Ķ���д�ֵȼ�����������д�������䱮�ģ�\n");

      if((int)me->query_skill("guiyuan-tunafa",1) < 100)
         return notify_fail("��Ĺ�Ԫ���ɷ��ȼ�����������д�������䱮�ģ�\n");  
      
      if((int)me->query("max_neili") < 1000 )
         return notify_fail("�������̫����д�����վ������Ŀ���! \n");
      
      if((int)me->query("neili") < 300 )
         return notify_fail("�������̫���ˣ�д���Ŀ�������������\n"); 

      if( target->is_busy() )
         return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

      if (me->query_skill_mapped("brush") != "yingou-bifa"
       || me->query_skill_mapped("parry") != "yingou-bifa")
         return notify_fail("�������޷�д�������项��\n");

      i = random((int)(me->query_skill("yingou-bifa",1)/20));
      if(i < 5) i=5;
      if(i > 10) i=10;                                                                                 
      msg = HIC"$Nһת�����б�ҡ�ϣ����д�𡸷����䱮�����ģ��鷨֮���е�Ѩ����Ѩ֮�����鷨��\n"+
               "������������������������������ΰ��������һ�����ݵ�����������з����Ͻ������翬��\n"+
               "���һ�ʲ�����\n" NOR;
      me->add("neili", - 200);
      if((random(me->query_skill("literate", 1)) > target->query_skill("literate", 1)/5)
       && (random(me->query_skill("force")) > target->query_skill("force")/3)){
            me->start_busy(1);
            target->start_busy(i+2);
            msg += HIR"$n���鷨ֻ�����ţ��Ķ��ñ��ĵ��⾳��ֻ��$N���еı��������Լ����ϸ���ҪѨ����\n"+
                      "���裬ֻ��������ס�����ؿ�Ҫ����ͻ��ϥͷһ�飬ԭ���ѱ�$N��ת�ʿڣ�������Ѩ����\n"NOR;
      }
      else {
       
             msg += HIY"��֪$p����д���������䱮����Ԥ�Ƶõ�$P��һ��֮������д��һֱ����Ҳ�صþ���������\n"+
                      "˿����������\n"NOR;
//          if (!(target->query("neili")<0)) target->add("neili",- 100);
      }
      message_vision(msg, me, target);
      me->start_perform(3,"�����项");
      return 1;
}
