// baibian.c ���߰ٱ�
// by fengyue
#include <ansi.h>

inherit F_SSERVER;

string perform_name() {return HIC"���߰ٱ�"NOR;}

int perform(object me, object target)
{
        int lvl;
        object weapon = me->query_temp("weapon");
        lvl = ( (int)me->query_skill("lingshe-zhangfa", 1)  + (int)me->query_skill("lingshe-quanfa", 1)+ (int)me->query_skill("hamagong",1) ) /3;

        if( !target ) target = offensive_target(me);
     
          if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
                return notify_fail("�����߰ٱ䡹ֻ����ս���жԶ���ʹ�á�\n");

        if (!weapon || weapon->query("skill_type") != "staff"
        || me->query_skill_mapped("staff") != "lingshe-zhangfa")
                return notify_fail("��û��ʹ�������ȷ����޷����ӳ������߰ٱ䡹��������\n");             

        if( (int)me->query_skill("lingshe-zhangfa",1) < 100 )
                return notify_fail("��������ȷ�������죬����ʹ�á����߰ٱ䡹��\n");
      
        if( (int)me->query_skill("staff",1) < 100 )
                return notify_fail("��Ļ���ȭ���ȼ�����������ʹ�á����߰ٱ䡹��\n");  

        if( (int)me->query_skill("lingshe-quanfa", 1) < 100 )
                return notify_fail("�������ȭ���ȼ�����������ʹ�á����߰ٱ䡹��\n");
      
        if( (int)me->query_skill("hamagong", 1) < 80 )
                return notify_fail("��ĸ�󡹦�ȼ�����������ʹ�á����߰ٱ䡹��\n");

        if( (int)me->query("max_neili") < 800 )
                return notify_fail("�������̫��������ʹ�á����߰ٱ䡹��\n");
      
        if( (int)me->query("neili") < 400 )
                return notify_fail("�������̫���ˣ��޷�ʹ�ó������߰ٱ䡹��\n");   
                                                                                 
        if (me->query_skill_prepared("cuff") != "lingshe-quanfa"
          || me->query_skill_mapped("cuff") != "lingshe-quanfa"
          || me->query_skill_mapped("force") != "hamagong")
                return notify_fail("�������޷�ʹ�á����߰ٱ䡹���й�����\n");


 message_vision(HIC"\n$N�������Ⱥ���,�������ֱ����ƶ���,��ȭ�ķ�λ������˼����Ȼ�鶯���ߣ�����һ�С����߰ٱ䡱��\n"NOR, me);
if(!userp(target)) target->add_busy(3);
else target->add_busy(1);

if( userp(target) &&  target->query("family/family_name") == "ؤ��"  && me->query("oyf/hamagong") == 2
     && random( me->query("combat_exp")/ 100 * me->query_int(1)) < target->query("combat_exp")/100 * target->query_int(1) / 2
  )
{
message_vision(HIC"\n˭֪��$nƽ��ץ��������������צ��������������$Nȭͷ����һ��ǡ���ô����ֿ���׼�����ǿ��ơ�����ȭ�����������\n"NOR, me,target);
me->start_busy(5);
return 1;
}
else{

        me->add("neili", -(300+random(100))); 
        me->add("jingli", -100);      
        me->add_temp("apply/cuff", lvl);
        me->add_temp("apply/attack", lvl);
        me->add_temp("apply/damage", lvl / 2);
        me->set_temp("lszf/bb",1);
        weapon->unequip(); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        weapon->wield();
        
if(me->is_fighting(target))
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

if(me->is_fighting(target)){ 
              weapon->unequip();
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
              weapon->wield();
                          }
if(me->is_fighting(target))
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

if(me->is_fighting(target)){ 
              weapon->unequip();
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
              weapon->wield();
                           }

 message_vision(HIC"\n$N����δ�ˣ�ͻȻ������ǰ���ˣ�����������죬�ѽ�$n������������ġ�����Ѩ���������������ߴ�ġ��ж�Ѩ���Ⱥ���У�\n"NOR, me,target);
       target->start_busy( random(3) + 2);
 
 if( me->query("oyf/hamagong")>2 && me->is_fighting(target) ) {
                       if(random(2)) target->apply_condition("no_exert",2);
                       if(random(2)) target->apply_condition("no_fight",2);
                       target->apply_condition("no_perform",4);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
    if(me->is_fighting(target))
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
                                                    }
        me->start_busy(1);
        me->add_temp("apply/cuff", -lvl);
        me->add_temp("apply/attack", -lvl);
        me->add_temp("apply/damage", - lvl /2 );
        me->delete_temp("lszf/bb");
    	me->start_perform(4 , "�����߰ٱ䡹");
        return 1;
}

}
