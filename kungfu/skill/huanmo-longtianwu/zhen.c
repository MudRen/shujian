#include <ansi.h>
#include <combat.h>

#define ZHEN "��" HIW "��豹���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
string msg;
    int extra,i;
    extra = me->query_skill("huanmo-longtianwu",1);
    if( !target ) target = offensive_target(me);

        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
        return notify_fail("����豹��桹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if( objectp(me->query_temp("weapon")) )
        return notify_fail("��������ʹ�á���豹��桹��\n");

    if( (int)me->query_skill("huanmo-longtianwu", 1) < 100 )
        return notify_fail("��Ļ�ħ�����費����죬�޷�ʩչ������豹��桹��\n");

    if( (int)me->query_skill("force", 1) < 100 )
        return notify_fail("��Ļ����ڹ�������죬�޷�ʩչ������豹��桹��\n");
   
    if ( (int)me->query("max_neili") < 3000)
        return notify_fail("���������Ϊ�������޷�ʩչ������豹��桹��\n");

    if ( (int)me->query("neili") < 1000)
        return notify_fail("��������������޷�ʩչ������豹��桹��\n");
   
    if (me->query_skill_prepared("strike") != "huanmo-longtianwu"
        || me->query_skill_mapped("strike") != "huanmo-longtianwu")
        return notify_fail("�������޷�ʹ�á���豹��桹��\n");  
        
    me->add_temp("apply/attack", extra);
    me->add_temp("apply/strike", extra/2);
    me->add_temp("apply/damage", extra);
    me->add("neili", -350);
    target->add_busy(1);

        message_vision(HIR "��Ȼ��$N" HIR "ʩ����" HIY "��" HIR "���־���˫����$n"
              HIR "ƽƽ��ȥ��������ʵ�޻������ް�㻨�ɿ��ԡ�\n" NOR, me,target);
i = 1;
if(userp(me)) i = 3;              
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
    
    message_vision(HIB "\n������$N" HIB "���С�" HIC "�" HIB "���־�����"
               "ʱֻ��$N" HIR "˫�Ʒ׷ɣ�����������Ӱ����$n" HIW "����"
               "�˷���\n" NOR, me,target); 
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),i,msg);
    
    message_vision(HIM "\n������$N" HIM "���С�" HIY "��" HIM "���־�����"
               "ʱֻ��$N" HIR "˫�Ʒ׷ɣ�����������Ӱ����$n" HIW "����"
               "�˷���\n" NOR, me,target); 
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),i,msg);
    
    message_vision(HIC "\n�����$N" HIC "���С�" HIG "��" HIC "���־�����"
               "ʱֻ��$N" HIR "˫�Ʒ׷ɣ�����������Ӱ����$n" HIW "����"
               "�˷���\n" NOR, me,target); 
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),i,msg);
    
    me->add_temp("apply/attack", -extra);
    me->add_temp("apply/strike", -extra/2);
    me->add_temp("apply/damage", -extra);
    target->start_busy(random(2));
    me->start_perform(3+random(2),"����豹��桹");
    return 1;
}

string perform_name(){ return HIR"��豹���"NOR; }
