 // zhuiming.c    ����׷����
 // 98.9.18  by Aug    99.9.11 changed by aug
 // modified by olives@SJ
//update by lsxk@hsbbs 2007/6/6

#include <ansi.h>
#include <combat.h>
 inherit F_SSERVER;

string perform_name() {return HIY"����׷����"NOR;}

#define TICKTIME 5

 void exam1(object me , object tartget );

 int perform(object me, object target)
 {
         if( !target ) target = offensive_target(me);

      if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
                 return notify_fail("������׷���ȡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

         if((int)me->query_skill("shenlong-tuifa", 1) < 150 )
                 return notify_fail("��������ȷ�������죬����ʹ�á�����׷���ȡ���\n");

         if((int)me->query_skill("dulong-dafa", 1) < 150 )
                 return notify_fail("��Ķ����󷨲�����񣬲���ʹ�á�����׷���ȡ���\n");

         if((int)me->query("neili") < 1000)
                 return notify_fail("����������̫��������ʹ������׷���ȡ�\n");

         if((int)me->query("jingli") < 500)
                 return notify_fail("�����ھ���̫��������ʹ������׷���ȡ�\n");

         if( me->query_temp("weapon")) 
                 return notify_fail("�����ű����޷�ʹ������׷���ȡ�\n");

         if((int)me->query_temp("zhuiming/time")>0)
                 return notify_fail("������ʹ������׷�����ء�\n");

         if(me->query_skill_mapped("force") != "dulong-dafa")
                 return notify_fail("��������ʹ�õ��ڹ�ͬ��������ִ�������ʹ�á�����׷���ȡ���\n");

         me->add("neili" , -200);
         me->add("jingli" , -80);
         me->set_temp("zhuiming/target",target);
         me->set_temp("zhuiming/time",time());
         me->set_temp("no_fight", 1);
         me->apply_condition("no_perform", 100);
         message_vision(HIY+"\n$N"+HIY+"��Ȼ��Хһ����˫�ȷɿ�����л�λ��ȴ����һ�ȣ��ƺ��ڻ���������ʹ��������������׷���ȣ�\n\n"NOR,me);
                 
         call_out("exam1",TICKTIME,me,target);

         return 1;
 }

 void exam1(object me , object target )
 {
         string str;     
         int  times,dis,i;

         if(!target
         || !me
         || !me->is_fighting(target)
         ||  environment(target) != environment(me)
         || !living(target)
         || target->is_ghost()
         || me->is_ghost()
         || !(dis = (int)me->query("env/zhuiming")))
         {
                 message_vision(HIY+"\n$N"+HIY+"�����ջؾۼ���������\n"NOR,me);
                 if (userp(me))
                 me->clear_condition("no_perform");
                 if (userp(me))
                 me->delete_temp("zhuiming");
                 if (userp(me))
                 me->delete_temp("no_fight");
                 me->start_perform(6,"������׷���ȡ�");
                 return;
         }
         dis = (dis>60?60:(dis<5?5:dis));
         times = time()-me->query_temp("zhuiming/time",1);
         if( me->query_skill_mapped("leg") != "shenlong-tuifa"
          || me->query_skill_prepared("leg") != "shenlong-tuifa"
          || me->query_temp("weapon")){
                 me->clear_condition("no_perform");
                 me->delete_temp("zhuiming");
                 me->delete_temp("no_fight");
                 me->start_perform(6,"������׷���ȡ�");
                 tell_object(me,"��������������ȷ�������������׷���ȡ�Ҳ�Զ������\n");
                 return;
         }
         if( target 
          && me->is_fighting(target)
          && (times < dis)
          && me->query_temp("zhuiming")){
                 str = HIY+"\n$N"+HIY+"�Ѿ�����"+CHINESE_D->chinese_number(times)+"���ӣ�$N˫�ȿ��ٵ��ƶ�����һ���Ż������ƺ��ڽ��¾ۼ���һ��";
                 if( times < 20)  str +="СС�����š�"NOR;
                   else if( times < 40) str +="�������������š�"NOR;
                       else if( times <= 50) str +="���ڲ��ϱ��Ĵ����ţ�"NOR;
                          else str +="��ʾ�ű��˷�â�ľ޴����ţ�"NOR;
                 message_vision(str+"\n",me);
                 call_out("exam1",TICKTIME,me,target);
         }
         else if(times>=dis)
         {
                 message_vision(HIY"\n$N������ϣ�˲���߳���"+chinese_number(times/5)+"�ȣ���ļ��������޷�����\n"NOR,me);
                 for(i=0;i<times/5-1;i++){
                   if(!random(3)) target->set_temp("must_be_hit",1);
                         COMBAT_D->do_attack(me,target,0,TYPE_SUPER);
                 target->delete_temp("must_be_hit");
             }
                 me->set_temp("sld/pfm/zhuiming",1);
                 target->set_temp("must_be_hit",1);
                 if(dis>30)
                         COMBAT_D->do_attack(me,target,0,TYPE_SUPER);
                 else
                         COMBAT_D->do_attack(me,target,0,TYPE_REGULAR);
                 target->delete_temp("must_be_hit");
                 me->delete_temp("sld/pfm/zhuiming");
                 me->clear_condition("no_perform");
                 me->delete_temp("zhuiming");
                 me->delete_temp("no_fight");
                 me->start_perform(6,"������׷���ȡ�");
                 return;
         }
         
 }

int help(object me)
{
   write(WHT"\n���������ȡ�"HIY"����׷����"WHT"����"NOR"\n");
   write(@HELP

    Ҫ�󣺵�ǰ���� 1000 ���ϣ�
          ��ǰ���� 500 ���ϣ�
          ���������ȵȼ� 150 ���ϣ�
          �����󷨵ȼ� 150 ���ϣ�
          set zhuiming xxx ���趨����ʱ�䣬���60�롣
HELP
   );
   return 1;
}
