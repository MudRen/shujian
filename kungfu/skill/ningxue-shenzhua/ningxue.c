// ningxue.c  ��Ѫ��צ֮����Ѫ����
// Create By lsxk@hsbbs 2007/5/13 
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string *xue_name = ({"��׶Ѩ","�ٻ�Ѩ","־��Ѩ","�羮Ѩ","�͹�Ѩ","�ڹ�Ѩ","���Ѩ","����Ѩ",
                     "����Ѩ","����Ѩ","����Ѩ","�׺�Ѩ","��̨Ѩ","�縮Ѩ","���Ѩ","����Ѩ",
                     "����Ѩ","����Ѩ","˿����Ѩ","����Ѩ","����Ѩ","��׵Ѩ","����Ѩ","����Ѩ", });

string perform_name() {return HIR"��Ѫ��"NOR;}

 int perform(object me, object target)
 {
         int j;
         string msg,xuedao;
         j = me->query_skill("ningxue-shenzhua", 1);

         if( !target ) target = offensive_target(me);

         if( !target 
           || !me->is_fighting(target)
          || !objectp(target)
           || environment(target)!= environment(me))
                 return notify_fail("����Ѫ����ֻ����ս���жԶ���ʹ�á�\n");

         if( objectp(me->query_temp("weapon")) )
                 return notify_fail("�������ֲ���ʹ�á���Ѫ������\n");

         if( (int)me->query_skill("ningxue-shenzhua", 1) < 150 )
                 return notify_fail("�����Ѫ��צ������죬ʹ��������Ѫ����������\n");

         if( (int)me->query_skill("force", 1) < 200 )
                 return notify_fail("������ڹ�������ʹ��������Ѫ����������\n");

         if( (int)me->query_dex() < 30 )
                return notify_fail("���������㣬�޷�ʹ�á���Ѫ��������!\n");

         if (me->query_skill_prepared("claw") != "ningxue-shenzhua"
          || me->query_skill_mapped("claw") != "ningxue-shenzhua"
          || me->query_skill_mapped("parry") != "ningxue-shenzhua")
                 return notify_fail("��Ҫȫ��������Ѫ��צ�������ʹ������Ѫ����������\n");

         if( (int)me->query("max_neili") < 2000)
                 return notify_fail("��������Ϊ̫��޷�ʹ�á���Ѫ����������\n");

         if( (int)me->query("neili") < 1500 )
                 return notify_fail("����������̫�����޷�ʹ�á���Ѫ����������\n");
   /*      
         if( (int)me->query("combat_exp",1)*2/3 > (int)target->query("combat_exp",1) && userp(target) && !target->query_condition("killer") )
                 return notify_fail("����������ã���ȴ��˱��꣬�������ã����á�����������\n");
*/
         xuedao = xue_name[random(sizeof(xue_name))];

         msg = HIR "\n$N�����ƻ���̧��������ɫ�ɰױ�죬ð��һ����������������Ϣ֮�ʣ�������$n�ġ�"+HIY+xuedao+HIR+"��ץ��ȥ��\n"NOR;

if(userp(target)) j = j /3;
         me->add_temp("apply/claw", j);
         me->add_temp("apply/attack", j);
         me->add_temp("apply/strength",(int)me->query("str"));
         me->add_temp("apply/damage", j/2);

          if(j>=450)       target->set_temp("must_be_hit",1);          

           if ( random((int)me->query_skill("ningxue-shenzhua",1)) > (int)target->query_skill("dodge",1)/3 &&  random((int)me->query_str()) > (int)target->query_dex() /3  ||  !userp(target)  ){
              msg += HIR"�ۿ�$N��ץ����$n�Ѿ����֮ң��$n�޷���ܣ���"+HIY+xuedao+HIR+"������ץ�����š�\n"NOR;
                 
                  target->receive_wound("qi",j*5);
                  target->receive_damage("qi",j*10);
                  target->apply_condition("nxsz_hurt",j/8);
           if(j>=300)       target->apply_condition("no_perform",3+random(3));
           if(j>=350)       target->apply_condition("no_exert",3+random(3));   
             
                  message_vision(msg, me, target);
                 COMBAT_D->report_status(target);
 if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"HIR"��Ѫ��"WHT"��"+ target->query("name") +"�����"RED+ j*5 + WHT"�㴴���˺���"RED+ j*10 + WHT"�㹥���˺���\n"NOR);    
 if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+ j*6 + WHT"���˺���\n"NOR); 



                 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
                 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

         } else {
             msg += CYN"\n$n���з�����һ�����ӷ��������$N��ץ�磬��$N�������飬��ǰ��֮�ƣ���$n����������\n"NOR;
                 message_vision(msg, me, target);
                 me->set_temp("nxsz_pfm",1);
                 target->apply_condition("no_fight",1);
                 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
                 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

                 me->delete_temp("nxsz_pfm");
         }               

         me->add("neili", -1500);
         me->add_temp("apply/claw", -j);
         me->add_temp("apply/attack", -j);
         me->add_temp("apply/strength",-(int)me->query("str"));
         me->add_temp("apply/damage", -j/2);
       
if(target)  target->delete_temp("must_be_hit");
         me->start_perform(2+random(2),"����Ѫ����");
         return 1;
 }

int help(object me)
{
   write(WHT"\n��Ѫ��צ��"HIR"��Ѫ��"WHT"����"NOR"\n");
   write(@HELP
   ����Ѫ��צ������ػ��ܶ����½��������ĳ������ա������У�
   ���д���צ֮�ˣ������ȫ��ѪҺ�����������ɽ���һ�㣬��ҩ
   ���Ρ�

   Ҫ��  ���� 1500 ���ϣ�
           ������� 2000 ���ϣ� 
           ������ 30 ���ϣ� 
           ��Ѫ��צ�ȼ� 150 ���ϣ�
           ��Ч�ڹ��ȼ� 200 ���ϣ�
           ����צ��Ϊ��Ѫ��צ��
           �����м�Ϊ��Ѫ��צ��
           ��צ�������ޱ�����

HELP
   );
   return 1;
}
