#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
    int skill;
    
    if ((int)me->query_skill("youming-zhao", 1) < 120 )
        return notify_fail("�����ڤ��צ�ȼ����������ܺ�����꣡\n");    
    if ((int)me->query_skill("claw", 1) < 120 )
        return notify_fail("��Ļ���צ����������죬���ܺ�����꣡\n");    
    if( objectp(me->query_temp("weapon")) )
      return notify_fail("��������ʹ�á���շ�ħ����\n");
    if (me->query_skill_prepared("claw") != "youming-zhao"
        || me->query_skill_mapped("claw") != "youming-zhao"
        || me->query_skill_mapped("parry") != "youming-zhao")
                return notify_fail("�������޷������������й�����\n"); 
    if ((int)me->query("neili") < 500 )
        return notify_fail("����������̫�������ܺ�����꣡\n");
    if ((int)me->query("max_neili") < 1000 )
        return notify_fail("����������̫�������ܺ�����꣡\n");
    if ( (int)me->query_temp("��ڤ", 1) ) 
        return notify_fail("���Ѿ����������Լ��Ļ��ǣ�\n");
    
    message_vision(HIR"ͻȻ$Nҧ����⣬�����л���ع�����ͬ����һ�㣡���ŵ���������ˮ����
ֻ��һ��"HIB"��Ӱ"HIR"�ӵص�ð�������ڰ�գ�����Ʈ�첻����ʱ����һ����ʱ����һ��Ӱ��\n"NOR, me);
    me->start_busy(2);
    me->add("neili", -500);    
    skill = me->query_skill("youming-zhao", 1)/5;
    me->set_temp("��ڤ", 1);
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me:), skill+2);
    return 1;
}

void remove_effect(object me)
{
    message_vision(HIR"����Ĳ�����������������"HIB"��Ӱ"HIR"�ڰ���ǻ���һ�󣬾���ʧ�ڵص��ˣ�\n"NOR, me);
    me->delete_temp("��ڤ");
    return;
}
