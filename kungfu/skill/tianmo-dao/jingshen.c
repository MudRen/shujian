    // by xjqx 2008/12/30

#include <ansi.h>
inherit F_SSERVER;
int perform(object me,object target)
{
        int j = me->query_skill("tianmo-dao", 1)/2 +me->query_skill("tianmo-zhang",1)/2;
        object weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);

        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
                return notify_fail("�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");                

        if(!me->query_skill("xixing-dafa", 1))
          if(me->query_skill("tianmo-gong", 1) < 100)
                return notify_fail("�������ڵ��ڹ���Ϊ��ʹ���������������\n");  

        if( (int)me->query_skill("tianmo-dao", 1) < 100 )
                return notify_fail("��ĵ�����δ���ɣ�����ʹ�þ������\n");        

        if (!weapon
         || weapon->query("skill_type") != "blade"
         || me->query_skill_mapped("blade") != "tianmo-dao")
                return notify_fail("������û�е����޷�ʹ�þ������\n");

        if((int)me->query_skill("tianmo-zhang", 1) < 100 )
                return notify_fail("�����ħ�Ʒ���δ���ɣ�����ʹ�þ������\n");  

        if (me->query_skill_mapped("force") != "tianmo-gong" )
          if(me->query_skill_mapped("force") != "xixing-dafa")
                return notify_fail("����ʹ�õ������ڹ����ԡ�\n");   

        if(me->query_skill_mapped("strike") != "tianmo-zhang" 
         || me->query_skill_prepared("strike") != "tianmo-zhang")
                return notify_fail("��û������ħ�ƣ��޷�ʹ�þ������\n");

        if(me->query_skill_mapped("parry") != "tianmo-zhang")
         if(me->query_skill_mapped("parry") != "tianmo-dao")
                return notify_fail("����мܹ��򲻶ԣ��޷�ʹ�þ������\n");

        if((int)me->query("max_neili") < 2000 )
                return notify_fail("������������Ϊ����������ʹ�þ������\n");      

        if((int)me->query("neili") < 1000 )
                return notify_fail("�������������㣬����ʹ�þ������\n");      

        if((int)me->query_skill("blade", 1) < 100 )
                return notify_fail("��Ļ�������������죬�����ڵ����м���ʹ�þ������\n");

        if((int)me->query_skill("strike", 1) < 100 )
                return notify_fail("��Ļ����Ʒ�������죬�����ڵ����м���ʹ�þ������\n");     

        message_vision(HIR"\nһ��ŭ��$Nʹ��������̾���֮�����������ֻ�����쵶Ӱ��Ӱ����ǵ�ͻϮ$n��ȥ��\n"NOR, me,target);
        me->set_temp("tmd/jingshen",1);
        me->add("neili", -200); 
        me->add("jingli", -50);
        me->add_temp("apply/attack", j*4/3);
        me->add_temp("apply/damage", j*5/7);
        me->add_temp("apply/dodge",j);
if(j>450 ) target->add_busy(1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        if(objectp(target) && me->is_fighting(target))
        {
                weapon->unequip(); 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
                weapon->wield(); 
        }
        if(objectp(target) && me->is_fighting(target))
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        if(objectp(target) && me->is_fighting(target))
        {
                weapon->unequip(); 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
                weapon->wield();
        }
        if(objectp(target) && me->is_fighting(target) && random((int)me->query_str()) > 30)
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        me->add_temp("apply/dodge",-j);
        me->add_temp("apply/attack", -j*4/3);
        me->add_temp("apply/damage", -j*5/7);
        me->delete_temp("tmd/jingshen");
        me->start_perform(2+random(2),"�����");
        return 1;
}
string perform_name(){ return HIR"�����"NOR; }
