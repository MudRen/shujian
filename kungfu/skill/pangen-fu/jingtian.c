//  jingtian.c ������Ƹ� 
//  by Leontt 2000.6.11

#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
      int lvl;
      object weapon;
      weapon = me->query_temp("weapon");
      lvl = (int)me->query_skill("pangen-fu", 1)/2;
      if( !target ) target = offensive_target(me);
     
     if(!objectp(target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("�̸���ڸ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    
      if (!weapon || weapon->query("skill_type") != "axe"
       || me->query_skill_mapped("axe") != "pangen-fu")
        return notify_fail("��ʹ�õı��в��ԣ��޷�ʹ�á�������Ƹ�����\n");             

      if( (int)me->query_skill("pangen-fu",1) < 120 )
        return notify_fail("����̸�����������죬����ʹ�á�������Ƹ�����\n"); 
      
      if( (int)me->query_skill("axe",1) < 100 )
        return notify_fail("��Ļ��������ȼ�����������ʹ�á�������Ƹ�����\n");  
     
      if( (int)me->query_skill("qiantian-yiyang", 1) < 100 )
        return notify_fail("���Ǭ��һ�����ȼ�����������ʹ�á�������Ƹ�����\n");

      if( (int)me->query("max_neili") < 1000 )
        return notify_fail("�������̫��������ʹ�á�������Ƹ�����\n");
      
      if( (int)me->query("neili") < ( me->query_skill("force")+ lvl ))
        return notify_fail("�������̫���ˣ��޷�ʹ�ó���������Ƹ�����\n");   
      
      message_vision(HIY"\n$NͻȻ���һ��,��������������"+weapon->query("name") +HIY"��Բ�������������޸�������Ϊ"+
                          "���أ�����$Nȫ��ʩչ��������ֹǧ�ֱ�о������֮����\n"NOR, me,target);
      me->add("neili", - (300+random(200)));
      me->add("jingli", -80);      
      lvl= lvl/5 + me->query("con") + me->query("str");
      me->add_temp("apply/axe", lvl);
      me->add_temp("apply/strength", lvl /5 );
      me->add_temp("apply/attack", lvl);
      me->add_temp("apply/damage", lvl);
      me->set_temp("jingtian", 1);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
      if (present(target,environment(me)) && me->is_fighting(target))
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);  
      if (present(target,environment(me))
       && me->is_fighting(target)
       && me->query_skill("pangen-fu", 1) > 150){
       if(random(me->query("combat_exp")) > target->query("combat_exp")/3)     
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
       else 
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
      }
      me->add_temp("apply/axe",- lvl);
      me->add_temp("apply/strength", -lvl /5 );
      me->add_temp("apply/attack",- lvl);
      me->add_temp("apply/damage",- lvl);
      me->delete_temp("jingtian");
      me->start_busy(random(2));
      me->start_perform(5,"��������Ƹ���");
      return 1;
}
