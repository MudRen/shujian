// chanshen.c ����

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
      int lvl;
      
      
      lvl = ((int)me->query_skill("hamagong", 1)+(int)me->query_skill("shexing-diaoshou", 1))/2;
          if( !target ) target = offensive_target(me);
           if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�����߲���֮��ֻ����ս���жԵ���ʹ�á�\n");

        if( (int)target->query_temp("bt_chanshen") )
                return notify_fail("�Է��Ѿ�����ʹ���߲����ס�ˣ�\n");
      if( (int)me->query_skill("shexing-diaoshou",1) < 100 )
      return notify_fail("������е��ֲ�����죬����ʹ�����߲���\n");
      if( (int)me->query_skill("hamagong", 1) < 150 && (int)me->query_skill("huntian-qigong", 1) < 150  )
      return notify_fail("��������ڹ��ȼ�����������ʹ�����߲���\n");
      if( (int)me->query("max_neili") < 1000 )
      return notify_fail("�������̫��������ʹ�����߲���\n");
      if( (int)me->query("neili") < 200 )
      return notify_fail("�������̫���ˣ�����ʹ�����߲���\n");   
                if( (int)me->query("neili") < 300 )
      return notify_fail("��ľ���̫���ˣ�����ʹ�����߲���\n");   


    message_vision(HIR"\n$N�з�һ�䣬����������߾���ճ����������չ�����в���$n��Ҫ����\n"NOR,me);
      me->add("neili", -300+random(50)); 
      me->add("jingli", -150+random(50));      
                target->add_temp("apply/parry",  -lvl/5);
                target->add_temp("apply/dodge",  -lvl/5);
                target->add_temp("apply/aromr",  -lvl/5);
                if(target->query("combat_exp")<random(me->query("combat_exp"))*2
                        )
                {
                        message_vision(HIW"\n����$N����ʽ���綾�߲���һ�㣬��������$n��Ҫ����"
                        "\n$n�Ķ�����ʱ�������������ν�������������\n"NOR, me,target);
                        
                        target->start_busy(1+random(lvl/100));
                }

                target->set_temp("bt_chanshen",1);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", target, lvl/5 :), lvl/100);
                
                me->start_busy(1+random(2));
      return 1;
}

void remove_effect(object target,int lvl)
{
                        if( !target ) return;
                        target->add_temp("apply/parry",  lvl);
                        target->add_temp("apply/dodge",  lvl);
                        target->add_temp("apply/aromr",  lvl);
                        target->delete_temp("bt_chanshen");
                if(target->is_fighting() )
                        {
                        target->start_busy(1 + random(1));
                        message_vision(HIG"$Nʹ������������������������ε��ֵĹ�����С�\n"NOR, target);
                        }
}

string perform_name() {return HIW"���߲���"NOR;}
