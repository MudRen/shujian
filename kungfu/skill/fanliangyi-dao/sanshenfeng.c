// shenfeng.c ���������
// by look
#include <ansi.h>

inherit F_SSERVER;

string perform_name() {return HIC"���������"NOR;}

int perform(object me, object target)
{
        int lvl;
        object weapon = me->query_temp("weapon");
        lvl = ( (int)me->query_skill("fanliangyi-dao", 1)/2 + (int)me->query_skill("poyu-quan", 1) ) /2;

        if( !target ) target = offensive_target(me);
     
        if( !target || !me->is_fighting(target) )
                return notify_fail("����������塹ֻ����ս���жԶ���ʹ�á�\n");

        if (!weapon || weapon->query("skill_type") != "blade"
        || me->query_skill_mapped("blade") != "fanliangyi-dao")
                return notify_fail("������û�е����޷�ʹ�á���������塹��\n");             

        if( (int)me->query_skill("fanliangyi-dao",1) < 100 )
                return notify_fail("��ķ����ǵ�������죬����ʹ�á���������塹��\n");
      
        if( (int)me->query_skill("blade",1) < 100 )
                return notify_fail("��Ļ��������ȼ�����������ʹ�á���������塹��\n");  

        if( (int)me->query_skill("poyu-quan", 1) < 100 )
                return notify_fail("�������ȭ���ȼ�����������ʹ�á���������塹��\n");
      
        if( (int)me->query_skill("zixia-gong", 1) < 80 )
                return notify_fail("�����ϼ�񹦵ȼ�����������ʹ�á���������塹��\n");

        if( (int)me->query("max_neili") < 800 )
                return notify_fail("�������̫��������ʹ�á���������塹��\n");
      
        if( (int)me->query("neili") < 400 )
                return notify_fail("�������̫���ˣ��޷�ʹ�ó�����������塹��\n");   
                                                                                 
        if (me->query_skill_prepared("cuff") != "poyu-quan"
          || me->query_skill_mapped("cuff") != "poyu-quan")
                return notify_fail("�������޷�ʹ�á���������塹���й�����\n");


        message_vision(HIC"\n$N����һ����Х����������ʹ������������塹����$n������ػ�����ȭһ����\n"NOR, me,target);
        me->add("neili", -(300+random(100))); 
        me->add("jingli", -100);      
        me->add_temp("apply/attack", lvl);
        weapon->unequip(); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        weapon->wield();
        if(me->is_fighting(target))
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        if(me->is_fighting(target)){ 
              weapon->unequip();
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
              weapon->wield();
        }
        me->start_busy(1);
        me->add_temp("apply/attack", -lvl);
	me->start_perform(4 , "����������塹");
        return 1;
}
