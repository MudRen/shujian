// lihun.c ���ն

#include <ansi.h>

inherit F_SSERVER;

string perform_name(){ return RED"���ն"NOR; }

int perform(object me, object target)
{
      int lvl;
      object weapon;
      weapon = me->query_temp("weapon");
      lvl = (int)me->query_skill("lietian-fu", 1);
  
      if( !target ) target = offensive_target(me);
     
         if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
        return notify_fail("�����ն��ֻ����ս���жԶ���ʹ�á�\n");

      if (!weapon || weapon->query("skill_type") != "axe"
       || me->query_skill_mapped("axe") != "lietian-fu")
        return notify_fail("��ʹ�õı��в���ȷ���޷�ʹ�á����ն����\n");             

      if( (int)me->query_skill("lietian-fu",1) < 120 )
        return notify_fail("������츫��������죬����ʹ�á����ն����\n");
      
      if( (int)me->query_skill("axe",1) < 100 )
        return notify_fail("��Ļ��������ȼ�����������ʹ�á����ն����\n");  
     
      if( (int)me->query_skill("guiyuan-tunafa", 1) < 100 )
        return notify_fail("��Ĺ�Ԫ���ɷ��ȼ�����������ʹ�á����ն����\n");

      if( (int)me->query("max_neili") < 1000 )
        return notify_fail("�������̫��������ʹ�á����ն����\n");
      
      if( (int)me->query("neili") < ( me->query_skill("force")+ lvl ))
        return notify_fail("�������̫���ˣ��޷�ʹ�ó������ն����\n");   
                                                                                 
      message_vision(RED"\n$Nʹ�������ն����ÿһʽ�ж�������������ɣ��ƺ�ʱ�䶼�������������ᣬ��Ȼ�丫Ӱ�������ƾ��磬�纣�˰������\n"NOR, me,target);
      me->add("neili", - 300);
      me->add("jingli", -50);      
  lvl = lvl /5;
      me->add_temp("apply/strength", lvl /10);
      me->add_temp("apply/attack", lvl );
      me->add_temp("apply/damage", lvl  );
      me->add_temp("apply/axe", lvl );
      me->set_temp("lihun", 1);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
 if (present(target,environment(me)) && me->is_fighting(target)) COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
      if (present(target,environment(me)) && me->is_fighting(target))
 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);  
      if (present(target,environment(me))
       && me->is_fighting(target)
       && me->query_skill("lietian-fu", 1) > 150)
 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      me->add_temp("apply/strength", -lvl /10);
      me->add_temp("apply/attack", -lvl );
      me->add_temp("apply/axe", -lvl );
      me->add_temp("apply/damage", -lvl );
      me->delete_temp("lihun");
 me->start_busy(2);
      me->start_perform(4,"�����ն��");
      return 1;
}
