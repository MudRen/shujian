//    /kungfu/skill/wenjia-quan/daoying.c pfm daoying
// by leontt /22/6/2000

#include <ansi.h>
inherit F_SSERVER;
int perform(object me,object target)
{
        int j = me->query_skill("wenjia-daofa", 1)/3+me->query_skill("wenjia-quan",1)/4;
        object weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("ȭ����һֻ�ܶ�ս���еĶ���ʹ�á�\n");                

        if( (int)me->query_skill("yijin-jing", 1) < 100 )
                return notify_fail("����ڹ���δ���ɣ�����ʹ��ȭ����һ��\n");    

        if( (int)me->query_skill("wenjia-daofa", 1) < 100 )
                return notify_fail("��ĵ�����δ���ɣ�����ʹ��ȭ����һ��\n");        

        if (!weapon
         || weapon->query("skill_type") != "blade"
         || me->query_skill_mapped("blade") != "wenjia-daofa")
                return notify_fail("������û�е����޷�ʹ��ȭ����һ��\n");

        if((int)me->query_skill("wenjia-quan", 1) < 100 )
                return notify_fail("���ȭ����δ���ɣ�����ʹ��ȭ����һ��\n");  

        if(me->query_skill_mapped("force") != "yijin-jing")
                return notify_fail("����ڹ����ԣ��޷�ʹ��ȭ����һ��\n");      

        if(me->query_skill_mapped("cuff") != "wenjia-quan" 
         || me->query_skill_prepared("cuff") != "wenjia-quan")
                return notify_fail("��û�����ƣ��޷�ʹ��ȭ����һ��\n");

        if(me->query_skill_mapped("parry") != "wenjia-quan")
         if(me->query_skill_mapped("parry") != "wenjia-daofa")
                return notify_fail("����мܹ��򲻶ԣ��޷�ʹ��ȭ����һ��\n");

        if((int)me->query("max_neili") < 1200 )
                return notify_fail("������������Ϊ����������ʹ��ȭ����һ��\n");      

        if((int)me->query("neili") < 600 )
                return notify_fail("�������������㣬����ʹ��ȭ����һ��\n");      

        if((int)me->query_skill("blade", 1) < 100 )
                return notify_fail("��Ļ�������������죬�����ڵ����м���ʹ��ȭ����һ��\n");

        if((int)me->query_skill("cuff", 1) < 100 )
                return notify_fail("��Ļ����Ʒ�������죬�����ڵ����м���ʹ��ȭ����һ��\n");     

        message_vision(HIC"\n$N���һ��ʹ���¼Ҿ�����ȭ����һ����ֻ��$P���д�Ȧ,��籩��㹥��$n��\n"NOR, me,target);
        me->add("neili", -200); 
        me->add("jingli", -50);
        me->start_perform(4,"ȭ����һ");  
        me->add_temp("apply/attack", j); 
        me->add_temp("apply/dodge",j);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
        if(objectp(target) && me->is_fighting(target))
        {
                weapon->unequip(); 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
                weapon->wield(); 
        }
        if(objectp(target) && me->is_fighting(target))
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
        if(objectp(target) && me->is_fighting(target))
        {
                weapon->unequip(); 
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
                weapon->wield();
        }
        if(objectp(target) && me->is_fighting(target) && random((int)me->query_str()) > 30)
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
        me->add_temp("apply/dodge",-j);
        me->add_temp("apply/attack", -j);
        me->start_busy(2+random(2));
        me->start_perform(2+random(2),"ȭ����һ");
        return 1;
}


