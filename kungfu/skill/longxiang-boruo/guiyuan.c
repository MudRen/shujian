
#include <ansi.h>

int exert(object me, object target)
{
	object tar;

	if( !target)
		return notify_fail("��Ҫ��˭ʹ�����ǹ�Ԫ�󷨣�\n");

	if ((int)me->query_skill("longxiang-boruo", 1) < 140)
		return notify_fail("ֻ��������������������߲�֮�󣬲���ʩչ���ǹ�Ԫ��\n");

	if((int)me->query("max_neili") < 2000)
		return notify_fail("���������Ϊ̫��������ɡ�\n");

	if( (int)me->query("neili") < 1000 ) 
		return notify_fail("�������������\n"); 

	if( me->query("jingli") < 500 )
		return notify_fail("��ľ���������\n");

	if ( me->is_fighting())
		return notify_fail("ս����ʹ�����ǹ�Ԫ�󷨣���������\n");

	if( !objectp(target) || target == me || ! objectp(tar=present(target, environment(me))) )
		return notify_fail("����Ҫ��˭���ǹ�Ԫ��\n");

	if( tar->is_corpse() )
		return notify_fail("�������ˣ�ֻ�л��˲��ܾ��ѡ�\n");

	if ( living(tar))
		return notify_fail(tar->name(1)+"�úõģ������ʹ��ʲô���ǹ�Ԫ�󷨰���\n");

	me->add("jingli", -50);
	me->add("neili", -500);
	message_vision( HIY "$Nһ�ַ���$n��������ϣ�һ������$n�����ģ������۾��������� ...\n" NOR, me, target );

	if( random(me->query("max_jingli")) > 500 ) {
		tar->revive();
		me->add("eff_jing", -100);
		me->receive_damage("qi", 300);
		me->add_busy(3);
	}
        else
		me->unconcious();

	me->start_exert(3, "���ǹ�Ԫ");
	return 1;
}

string exert_name(){ return HIY"���ǹ�Ԫ"NOR; }

int help(object me)
{
        write(HIY"\n���������֮�����ǹ�Ԫ����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1000 ���ϣ�
                ������� 2000 ���ϣ�
                ��ǰ���� 500 ���ϣ�
                ����������ȼ� 140 ���ϡ�

HELP
        );
        return 1;
}
