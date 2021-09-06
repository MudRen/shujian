// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
	string msg, force;

	if( !target )
		return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

	if( ! present(target,environment(me)))
		return notify_fail("�������������\n");

	if( target == me)
		return notify_fail("����Լ����ˣ�������exert healָ�\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");

	if( target->is_busy())
		return notify_fail( target->name()+ "��æ���أ�\n");

	if( target->query("env/no_lifeheal"))
		return notify_fail( target->name()+"�ܾ���������ˡ�\n");

	if( !living(target) || !target->query("can_speak"))
		return notify_fail("�����ǻ���������˸�ʲô��\n");

	if(!(force = me->query_skill_mapped("force")))
		return notify_fail("�㻹û��ѡ����Ҫʹ�õ��ڹ���\n");

	if(me->query("max_neili") < 300 )
		return notify_fail("���������Ϊ������\n");

	if(me->query("neili") < 100 )
		return notify_fail("�������������\n");

	if( me->query_skill("force") < 150 ) 
		return notify_fail("����ڹ��ȼ���̫�ͣ������˹����ˡ�\n");

	if( me->query_skill("medicine", 1) < 120 )
		return notify_fail("�㱾������ĵȼ��������޷�Ϊ�������ˡ�\n");

	if(target->query_temp("reverse_healing"))
		return notify_fail("���ܵ�����תǬ���Ĺ�������Ҫ�����ϼ��ˣ�\n");
	if( target->query("eff_qi")+target->query_temp("apply/qi")
	< (target->query("max_qi")+target->query_temp("apply/qi")) / 4 )
		return notify_fail( target->name()+ "�Ѿ����˹��أ����ܲ�����������𵴣�\n");

	if (target->query("eff_qi") >= target->query("max_qi"))
		return notify_fail( target->name()+"��û�����ˣ�����Ҫ������ˡ�\n");

	msg = HIW"$N������������"+to_chinese(force)+"������������$n���ģ������ؽ���������$n���ڡ���\n\n"NOR;
	msg +=HIW"$nֻ��һ��������������ԴԴ�������������ڣ�ֻ��$Nͷ����˿˿����ð����\n\n"NOR;
	msg +=HIW"$n�³�һ����Ѫ����ɫ������������ˣ��������˺ܴ�ĺ�ת��ȫ�������ޱȳ��档\n\n"NOR;

	message_vision(msg ,me ,target);			     

	target->receive_curing("qi", 10 + me->query_skill("force")/3 );
	target->receive_heal("qi", 10 + me->query_skill("force")/3 );

	me->add("neili", -150);
	me->set("jiali", 0);
	me->start_busy(4);
	target->start_busy(4);
	return 1;
}
