//shigu.c ʯ����
#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;

string perform_name(){ return HIY"ʯ����"NOR; }

int perform(object me, object target)
{
      string msg; 
      int i, damage,p;                                  
      object weapon = me->query_temp("weapon");

      if (!weapon || weapon->query("skill_type") != "brush")
         return notify_fail("������û�бʣ��޷�д��ʯ���ģ�\n");

      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
         return notify_fail("ʯ����ֻ����ս���жԶ���ʹ�á�\n");
             
      if((int)me->query_skill("yingou-bifa",1) < 150 )
         return notify_fail("��������ʷ���������죬����дʯ���ģ�\n");
      
      if((int)me->query_skill("literate",1) < 140 )
         return notify_fail("��Ķ���д�ֵȼ�����������д��ʯ���ģ�\n");  

      if((int)me->query_skill("guiyuan-tunafa",1) < 160 )
         return notify_fail("��Ĺ�Ԫ���ɷ��ȼ�����������д��ʯ���ģ�\n");
      
      if((int)me->query("max_neili") < 2000 )
         return notify_fail("�������̫�����޷�д��ǿ��������ʯ����! \n");
      
      if((int)me->query("neili") < 800 )
         return notify_fail("�������̫���ˣ�д����ʯ�����޸���֮����\n");       

      if((int)me->query("jingli") < 500 )
         return notify_fail("��ľ���̫���ˣ�д����ʯ�����޸���֮����\n");       
         
      if(me->query_skill_mapped("brush") != "yingou-bifa"
       || me->query_skill_mapped("parry") != "yingou-bifa")
         return notify_fail("�������޷�д����ʯ���ġ���\n");

      i = random((int)(me->query_skill("yingou-bifa",1)/15));
      if(i < 1) i=1;
      if(i > 15) i=15;                                                                                 

      msg = HIY"$N��Ȼ��ʷ��ֱ䣬�˱ʲ���д�֣�ȴ�����˸�ͷ��ʯͷ�����һ�㡣��һ·�ʷ���ʯ���ģ�\n"+
               "���Ǵ���֮���ø������ʯ���ϵ����֣�������ŵĴ�׭�֡�$n����һ·��׭��Ȼֻʶ��һ��\n"+
               "���֣��Ȳ�֪�Է���д���֣���Ȼ�²����鷨��ܺͱʻ����ƣ���ʱ�����мܡ�\n" NOR;

      me->add("neili", - 450);
      me->add("jingli", -100);

      if((random(me->query_skill("literate")) > target->query_skill("literate")/6)
       &&(random(me->query_skill("force")) > target->query_skill("force")/5)){
           me->start_busy(1);
           target->start_busy(3);
           damage = (int)me->query_skill("yingou-bifa", 1);
           damage = damage/2 + random(damage);
           damage = damage * i * 2 / 3;
           if (damage > 2400 ) damage = 2400;
           target->receive_damage("qi", damage);
           target->receive_wound("qi", damage/2);
           msg += MAG"$Nһ����һ����׭�����������ֹ�Ȼ�Ű£�����Ϊ�鷨֮���������ʷ�Ҳ��Ӧ��ǿ������\n"+
                     "$N��ʻ��裬�ڿ��������������֣�$n����õ�ȥ�������֣�ϥ��Ѩ��һ�飬ǿ��һ����\n"+
                     "��ϥ��Ѩ����ȥ��$N������磬��������һ���������У�$n����������̱���ڵ��ϡ�\n"NOR;
           p = (int)target->query("qi")*100/(int)target->query("max_qi");
           msg += "( $n"+eff_status_msg(p)+" )\n";
       }
       else{
           msg += CYN"$Pһ�ֿ��һ�֣��ʷ��ӹ�$p����ߣ�ֻ�������쬵ģ�$p������ȥ��$P��\n"+
                     "д���֣�ֻ�û�ס���ź����ϸ���ҪѨ��ͻȻ����һ�飬ǿ��һ����ȥ��Ѩ����\n"+
                     "����������Ѩ�ɹ��������ֱ���������������ǿ���мܡ�\n"NOR;
           if( random(me->query("combat_exp", 1)) > target->query("combat_exp", 1)/ 2
            && me->is_fighting(target)
            && present(target,environment(me))){
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
              if (present(target,environment(me)) && me->is_fighting(target))
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
           }
           me->start_busy(2);
           if ( target->query("neili") > 400 ) target->add("neili",- random(200));
       }
       message_vision(msg, me, target);
       me->start_perform(6,"��ʯ���ġ�");
       return 1;
}
