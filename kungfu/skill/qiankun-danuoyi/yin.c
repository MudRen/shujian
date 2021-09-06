#include <ansi.h>
inherit F_SSERVER;
int check_fight(object me);
string perform_name(){ return HIG"���־�"NOR; }

int perform(object me,object target,string arg)
{
	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target) )
		return notify_fail("�������־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if(!me->is_fighting())
		return notify_fail("��û��ս�����أ�\n");

	if(me->query_skill("qiankun-danuoyi", 1) < 210 )
		return notify_fail("���Ǭ����Ų�ƻ�δ�������߲㡣\n");

	if (!me->query_skill("jiuyang-shengong", 1))
	if( me->query_skill("shenghuo-shengong", 1) < 210 )
		return notify_fail("���ʥ���񹦵ȼ�������\n");

	if(me->query_skill_mapped("parry") != "qiankun-danuoyi")
		return notify_fail("��û��ʹ��Ǭ����Ų����Ϊ�мܣ�\n");

	if((int)me->query("neili") < 500)
		return notify_fail("��Ŀǰ������������\n");

	if((int)me->query_temp("qkdny/yi") )
		return notify_fail("������ʩչ���ơ��־��أ�\n");

	if((int)me->query_temp("qkdny/yin") )
		return notify_fail("������ʩչ�������־��أ�\n");

	if((int)me->query_temp("qkdny/xu") )
		return notify_fail("������ʩչ����־��أ�\n");

	if((int)me->query_temp("qkdny/hua") )
		return notify_fail("������ʩչ�������־��أ�\n");

	if(target->query_temp("qkdny/yin"))
		return notify_fail( target->query("name") +"����ʹ�á������־��ء�\n");

	me->add("neili", -400);
	tell_object(me,HIG"\n������Ǭ����Ų���ķ���ͣ���˹�����ʹ�á������־�������רעǣ����\n"NOR);
	me->set_temp("qkdny/yin", 1);
	me->set_temp("lost_attack", 1);
	me->start_perform(2, "���־�");
	me->add_temp("apply/dodge", -150);
	me->add_temp("apply/parry", -150);
	check_fight(me);
	return 1;
}

int check_fight(object me)
{
	if (!me || !me->query_temp("qkdny/yin")) return 0;

	else if(me->is_ghost() || !living(me)
	 || !me->is_fighting()
	 || me->query("jingli") < 500
	 || me->query("neili") < 500
	 || me->query("jing") < 500) {
		tell_object(me, HIG"\n��������ָ���ƽ����\n"NOR);
		me->delete_temp("qkdny/yin");
		me->add_temp("apply/dodge", 150);
		me->add_temp("apply/parry", 150);
	}
	else {
		me->set_temp("lost_attack", 1);
		call_out("check_fight", 1, me);
	}
	return 1;
}

int help(object me)
{
        write(HIG"\nǬ����Ų�ơ����־�����"NOR"\n");
        write(@HELP
        Ҫ��  ��ǰ���� 500 ���ϣ�
                Ǭ����Ų�Ƶȼ� 210 ���ϣ�
                �����м�ΪǬ����Ų�ơ�
HELP
        );
        return 1;
}
