// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

#define YAN "��" HIR "�������" NOR "��"

inherit F_SSERVER; 
string perform_name(){ return HIR"�������"NOR; }
int perform(object me, object target)
{
        object weapon;
        string msg;
        int lvl,damage;
        
        if (! target) target = offensive_target(me); 
        
        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
		return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
         
        if (me->query_temp("weapon") )
                return notify_fail("�������ֲ���ʩչ" YAN "��\n");
         
        if (me->query_skill("force") < 200) 
                return notify_fail("����ڹ�����Ϊ�������޷�ʩչ" YAN "��\n");
        
        if (me->query_skill("huoyan-dao", 1) < 150) 
                return notify_fail("��Ļ��浶��Ϊ�������޷�ʩչ" YAN "��\n");
         
        if (me->query("neili") < 600 || me->query("max_neili") < 2000) 
                return notify_fail("��������������޷�ʩչ" YAN "��\n");

        if (me->query_skill_mapped("strike") != "huoyan-dao") 
                return notify_fail("��û�м������浶���޷�ʩչ" YAN "��\n");

        if (me->query_skill_prepared("strike") != "huoyan-dao")
                return notify_fail("��û��׼�����浶���޷�ʩչ" YAN "��\n");

       
        if (me->query_skill("xuedao-jing", 1) > 1) 
               return notify_fail("������Ѫ������" YAN "������㣣�����ʩչ��\n");
     
        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "\n\n$N" HIR "����������ŭ״�� Ŀ�����壬ŭ���ϳ壬�������ע�뵥�ƣ���Ե��ʱ����һ���������ף�\n" NOR;
       

        me->add("neili", -500);

       lvl = me->query_skill("huoyan-dao",1);
       
      damage = lvl*3;
      damage = damage+random(damage);
       
        
  if( damage > target->query("qi") ) {
  	      damage= target->query("qi")-1;
          target->start_busy(5);
                                     }

          	target->receive_damage("qi", damage, me);
          	target->receive_wound("qi", random(damage), me);     
               
        message_vision(msg, me, target);

COMBAT_D->report_status(target, 2);

me->set_temp("yan",1);
         
        
        
if(random(10)>6 || (!userp(target)&& lvl > 350)) {
    //         target->set_temp("must_be_hit",1);
             target->start_busy(1+ random(4));
                              }

me->add_temp("apply/parry", lvl/3);
me->add_temp("apply/dodge", lvl/3);
me->add_temp("apply/attack", lvl/5);
me->add_temp("apply/damage", lvl/5);
 
        COMBAT_D->do_attack(me, target, weapon, 3);

       if( me->is_fighting(target) )  
        COMBAT_D->do_attack(me, target, weapon, 3);

       if( me->is_fighting(target) ) 
        COMBAT_D->do_attack(me, target, weapon, 3);

  //      target->delete_temp("must_be_hit");
  
        me->start_busy(1 + random(2));
        me->start_perform(3,"��������ס�");
       
me->add_temp("apply/parry", -lvl/3);
me->add_temp("apply/dodge", -lvl/3);
me->add_temp("apply/attack", -lvl/5);
me->add_temp("apply/damage", -lvl/5);
me->delete_temp("yan");
        return 1;

}


