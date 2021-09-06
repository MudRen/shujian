// chousui.c ��������
// Created and Modified by spiderii

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        
        int j, i, lvl = me->query_skill("chousui-zhang", 1);

        if( !target ) target = offensive_target(me);

        if( !objectp(target)
         || !target->is_character()
         || !me->is_fighting(target)
         || !living(target) )
                return notify_fail("���������衹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        
        if( (int)me->query_skill("chousui-zhang", 1) < 200 )
                return notify_fail("��ĳ����ƹ���̫ǳ���������ˡ�\n");

        if( (int)me->query_skill("strike", 1) < 200 )
                return notify_fail("��Ļ����Ʒ�����̫ǳ���������ˡ�\n");

        
        if( (int)me->query_skill("force", 1) < 200 )
                return notify_fail("����ڹ�����̫ǳ���������ˡ�\n");

       if( (int)me->query_skill("huagong-dafa", 1) < 200 )
                return notify_fail("��Ļ�����̫ǳ���������ˡ�\n");

        if( (int)me->query("max_neili") < 2500 )
                return notify_fail("�������̫ǳ���������ˡ�\n");

        if( (int)me->query("neili") < 1000 )
                return notify_fail("��������������������ˡ�\n");
        if (me->query_skill_prepared("strike") != "chousui-zhang"
        || me->query_skill_mapped("strike") != "chousui-zhang"
        || me->query_skill_mapped("parry") != "chousui-zhang")
                tell_object(me,"������ó����Ʋ���ʹ�á��������衹���й�����\n"); 
                                                                                         
        if(me->query_skill_mapped("force") != "huagong-dafa")
                tell_object(me,"�㷢���Լ����õ��ڹ��޷����С��������衹������\n");
                
        
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á��������衹��\n");           
        j = lvl/3;

        if ( lvl > 300 )
                j = to_int(lvl/3.0 * lvl/275.0);
        message_vision(BLU"\n$N"BLU"����$n���ٵ�ת�˼�Ȧ������һ������צ���棬���������ƶ������Ϯ��$n�� "BLU"��\n"NOR, me,target);

        me->set_temp("xx_chousui", 3);

        me->add_temp("apply/strike", j);
        me->add_temp("apply/attack", j);
        me->add_temp("apply/damage", j);
if(target->query_condition("xx_poison") > 180 || me->query_skill("poison",1)>180) 
{ target->add_busy(2);
 me->add_temp("apply/damage", j);
i=1;
}

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(3)?1:3);

        if( me->is_fighting(target) )
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

        if( me->is_fighting(target) )
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

if(i==1 && me->is_fighting(target) ) 
                 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        me->add_temp("apply/strike", -j);
        me->add_temp("apply/attack", -j);
        me->add_temp("apply/damage", -j);

if(i==1) me->add_temp("apply/damage", -j);

        me->delete_temp("xx_chousui");

        me->start_busy(random(2));
        me->add("neili", -300);
        me->add("jingli", -150);
        me->start_perform(3, "���������衹");
        return 1;
}

string perform_name(){ return HIW"��������"NOR; }

int help(object me)
{
        write(HIW"\n������֮���������衹��"NOR"\n\n");
        write(@HELP
        �����ɵĹ�����Ҫ����<��>�����¹������������������ζ
        ������������ս���У�ƾ������ڹ������ڴ涾�Ƴ������˵е�
        һ�Ź��򡣡��������衹һʽ�����Կ������һ���־���������
        ʽ����Է��������а�����ѷ�����

        Ҫ��  ��ǰ���� 1000 ����;
                ������� 2500 ���ϣ�
                �����Ƶȼ� 220 ���ϣ�
                �����󷨵ȼ� 220 ���ϣ�
                �����Ʒ��ȼ� 220 ���ϣ�
                �����ڹ��ȼ� 220 ����;
                �������ޱ�����

        
HELP
        );
        return 1;
}

