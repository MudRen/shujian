#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string perform_name(){ return HIC"˭������"NOR; }

int perform(object me, object target)
{
      string msg; 
      int i;                                  
      object weapon = me->query_temp("weapon");

      if (!weapon || weapon->query("skill_type") != "sword")
         return notify_fail("�������޽������ʹ�ó�˭�����棡\n");

      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
         return notify_fail("˭������ֻ����ս���жԶ���ʹ�á�\n");
             
      if((int)me->query_skill("yitian-tulong",1) < 180 )
         return notify_fail("���������������������죬��ʹ����˭�����棡\n");
      
      if((int)me->query_skill("literate",1) < 180 )
         return notify_fail("��Ķ���д�ֵȼ�����������д��˭�����棡\n");

      if((int)me->query_skill("sword",1) < 180)
         return notify_fail("��Ļ��������ȼ�����������д��˭�����棡\n");  
      
      if((int)me->query("max_neili") < 1500 )
         return notify_fail("���������Ϊ�ƺ�����! \n");
      
      if((int)me->query("neili") < 500 )
         return notify_fail("��ĵ�ǰ�����ƺ�������\n"); 

      if( target->is_busy() )
         return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

      if (me->query_skill_mapped("sword") != "yitian-tulong"
       || me->query_skill_mapped("parry") != "yitian-tulong")
         return notify_fail("�������޷�д����˭�����桹��\n");

      i = random((int)(me->query_skill("yitian-tulong",1)/100));
      if(i < 2) i=2;
      if(i > 4) i=4;                                                                                 
      msg = HIC"$N��Хһ��������"+weapon->query("name")+HIC"ֱ���������������ǽ���â����ʸӦ����\n"+
               "����Ͼ�����粻���ɣ���һֱ���ǡ��桱�ֵ����һ�ʣ�\n" NOR;
      me->add("neili", - 200);
      if((random(me->query_skill("literate", 1)) > target->query_skill("literate", 1)/5)
        &&  random(me->query("combat_exp")) > target->query("combat_exp")/2) {
            target->start_busy(i+1);
            msg += HIR"$n⧲�����������"+weapon->query("name")+HIC"����ѩ����ֻ�������мܣ����޻���֮����\n"NOR;
      }
      else {
            me->start_busy(2);
           target->start_busy(1);
            msg += HIY"$n��$N��ʽϬ�����������ǰ������裬���³����ˣ��������һ�С�\n"NOR;
      }
      message_vision(msg, me, target);
      me->start_perform(3,"��˭�����桹");
      return 1;
}




int help(object me)
{
   write(HIG"\n��"HIW"˭������"HIG"����"NOR"\n");
	write(@HELP
      ������ӿ���죬��(������)��Хһ��������ֱ���������������ǽ���â; 
      ��ʸӦ��������Ͼ�����粻���ɣ���һֱ���ǡ��桱�ֵ����һ�ʡ�

  
    ָ�perform sword(parry).zhengfeng

    Ҫ�󣺻�������180��
          ����д��180��
          ����������180��
          �������1500���ϣ���ǰ����500���ϡ�
          �����������м�Ϊ�����������������г�������          

    ˵������������һ��Ϭ����ƥ������⧲�����֮�£�����ֻ��ƣ���м�
          ���޻���֮����
HELP
	);
	return 1;
}
