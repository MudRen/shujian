// lifeforce.c 
#include <ansi.h>

string exert_name() {return MAG"�ڹ�����"NOR;}

int exert(object me, object target)
{
	object where;
        int i;
        if( target == me )
                return notify_fail("�㲻�ܸ��Լ����ˡ�\n");

        if( !target )
                return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");
        where = environment(me);
	if ( !present(target,where) )
		return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");
        if( !living(target) || !target->query("can_speak"))
                return notify_fail("�����ǻ���������˸�ʲô��\n");

        if( me->is_fighting() || target->is_fighting())
                return notify_fail("ս�����޷��˹����ˣ�\n");

        if( me->is_busy() || target->is_busy())
                return notify_fail("æ���в����˹����ˣ�\n");
        if( (int)me->query("max_neili") < 200 )
                return notify_fail("���������Ϊ������\n");

        if ((int)me->query_skill("zixia-gong", 1) < 45)
                return notify_fail("�����ϼ����Ϊ��������\n");

        if( (int)me->query("neili") < 200 )
                return notify_fail("�������������\n");

        if( (int)target->query_condition("hunyuan_hurt") == 0 )
                return notify_fail( target->name() + "��û���ܵ���Ԫ�޼��ھ����˺���\n");

        if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
                return notify_fail( target->name() +
                        "�Ѿ����˹��أ����ܲ�����������𵴣�\n");

        message_vision(
                MAG "$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n\n"
                "���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
                me, target );

        target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
        target->add("qi", 10 + (int)me->query_skill("force")/3 );
        if( (int)target->query("qi") > (int)target->query("eff_qi") ) {
        target->set("qi", (int)target->query("eff_qi")); }
        me->add("neili", -50);
        me->set("jiali", 0);
        me->start_busy(2+random(4));
        i = (target->query_condition("hunyuan_hurt") - 20);
        if( i >= 0 ) {
        target->apply_condition("hunyuan_hurt", i); }
        if( i < 0 ) {
        target->clear_condition("hunyuan_hurt"); }
        return 1;
}
