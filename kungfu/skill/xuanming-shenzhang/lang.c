// jijin����
// by reikou
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)

{
    string msg;
    int extra;
    extra = me->query_skill("xuanming-shenzhang",1);
    if( !target ) target = offensive_target(me);
    if( !target
      ||        !target->is_character()
      ||        !me->is_fighting(target) )
        return notify_fail("�����κ��ˡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if( objectp(me->query_temp("weapon")) )
        return notify_fail("��������ʹ�á����κ��ˡ���\n");

    if( (int)me->query_skill("xuanming-shenzhang", 1) < 350 )
        return notify_fail("�����ڤ���Ʋ�����죬�޷�ʩչ�������κ��ˡ���\n");

    if( (int)me->query_skill("force", 1) < 350 )
        return notify_fail("��Ļ����ڹ�������죬�޷�ʩչ�������κ��ˡ���\n");
   
    if ( (int)me->query("max_neili") < 3000)
        return notify_fail("���������Ϊ�������޷�ʩչ������ָ��������\n");

    if ( (int)me->query("neili") < 1000)
        return notify_fail("��������������޷�ʩչ�������κ��ˡ���\n");
   
    if (me->query_skill_prepared("strike") != "xuanming-shenzhang"
        || me->query_skill_mapped("strike") != "xuanming-shenzhang")
        return notify_fail("�������޷�ʹ�á����κ��ˡ���\n");  
    
    me->add_temp("apply/attack", extra);
    me->add_temp("apply/strike", extra);
    me->add_temp("apply/damage", extra);
    me->add("neili", -350);
    target->start_busy(1);
        message_vision(BLU"$N������������ǰ����˫���Ƴ���ʹ����ڤ������Ϊ����ľ��У�����δ��������֮�����羪�κ��˰���$nӭ��������"NOR"\n" NOR, me,target);
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);  
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    
    me->add_temp("apply/attack", -extra);
    me->add_temp("apply/strike", -extra);
    me->add_temp("apply/damage", -extra);
    me->start_busy(1);
    target->start_busy(random(2));
    me->start_perform(4,"�����κ��ˡ�");
    return 1;
}


