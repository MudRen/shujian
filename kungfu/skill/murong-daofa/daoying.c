//    /kungfu/skill/xingyi-zhang/daoying.c pfm daoying
// by leontt /22/6/2000

#include <ansi.h>
inherit F_SSERVER;
int perform(object me,object target)
{
        int j;
        object weapon = me->query_temp("weapon");
       j = me->query_skill("murong-daofa",1)/2 + me->query_skill("xingyi-zhang",1)/2;
       j =j /3;
       if(!userp(me)) j = j*2/ 3;
     
        if( !target ) target = offensive_target(me);

  if( !target  
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
                return notify_fail("��Ӱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");                

        if( (int)me->query_skill("shenyuan-gong", 1) < 100 )
                return notify_fail("����ڹ���δ���ɣ�����ʹ�õ�Ӱ�ƣ�\n");    

        if( (int)me->query_skill("murong-daofa", 1) < 100 )
                return notify_fail("��ĵ�����δ���ɣ�����ʹ�õ�Ӱ�ƣ�\n");        

        if (!weapon
         || weapon->query("skill_type") != "blade"
         || me->query_skill_mapped("blade") != "murong-daofa")
                return notify_fail("������û�е����޷�ʹ�õ�Ӱ�ƣ�\n");

        if((int)me->query_skill("xingyi-zhang", 1) < 100 )
                return notify_fail("����Ʒ���δ���ɣ�����ʹ�õ�Ӱ�ƣ�\n");  
/*
        if(me->query_skill_mapped("force") != "shenyuan-gong")
                return notify_fail("����ڹ�������Ԫ�����޷�ʹ�õ�Ӱ�ƣ�\n");      
*/
        if(me->query_skill_mapped("strike") != "xingyi-zhang" 
         || me->query_skill_prepared("strike") != "xingyi-zhang")
                return notify_fail("��û�����ƣ��޷�ʹ�õ�Ӱ�ƣ�\n");

        if(me->query_skill_mapped("parry") != "xingyi-zhang")
        if(me->query_skill_mapped("parry") != "douzhuan-xingyi")
         if(me->query_skill_mapped("parry") != "murong-daofa")
                return notify_fail("����мܹ��򲻶ԣ��޷�ʹ�õ�Ӱ�ƣ�\n");

        if((int)me->query("max_neili") < 1200 )
                return notify_fail("������������Ϊ����������ʹ�õ�Ӱ�ƣ�\n");      

        if((int)me->query("neili") < 600 )
                return notify_fail("�������������㣬����ʹ�õ�Ӱ�ƣ�\n");      

        if((int)me->query_skill("blade", 1) < 100 )
                return notify_fail("��Ļ�������������죬�����ڵ����м���ʹ�õ�Ӱ�ơ�\n");

        if((int)me->query_skill("strike", 1) < 100 )
                return notify_fail("��Ļ����Ʒ�������죬�����ڵ����м���ʹ�õ�Ӱ�ơ�\n");     

        message_vision(HIR"\n$N���һ��ʹ��Ľ�ݾ�������Ӱ�ơ���ֻ��$P���浶�ߣ�ƬƬ�����м����������Ʒ�һ����$n��\n"NOR, me,target);
if(j<= 300 && !userp(target))
 { j = j * 2;
  target->add_busy(2);
}


        me->set_temp("mr_daoying",1);
        me->add("neili", -200); 
        me->add("jingli", -50);
        me->start_perform(4,"��Ӱ��");  
        me->add_temp("apply/attack", j); 
        me->add_temp("apply/strength",j /10);
        me->add_temp("apply/blade",j);
        me->add_temp("apply/strike",j);
        me->add_temp("apply/damage",j);
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        
        if( me->is_fighting(target))
        {
                weapon->unequip(); 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
                weapon->wield(); 
        }
        
        if(me->is_fighting(target))
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        
        if(me->is_fighting(target))
        {
                weapon->unequip(); 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
                weapon->wield();
        }
        
        if( me->is_fighting(target) && random((int)me->query_str()) > 30)
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        
        
        me->add_temp("apply/damage",-j);
        me->add_temp("apply/strike",-j);
        me->add_temp("apply/strength",-j /10);
        me->add_temp("apply/blade",-j);
        me->add_temp("apply/attack", -j);

if(me->query_skill("shenyuan-gong",1)<=450 )
        me->start_busy(1+random(2));
        me->delete_temp("mr_daoying");
        return 1;
}
string perform_name(){ return HIR"��Ӱ��"NOR; }
