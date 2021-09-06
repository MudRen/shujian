// youming.c
// Modified by Lane@SJ 2005/4/14

#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
	int ap, dp;
	int nh = me->query_skill("linji-zhuang", 1)/2;

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target) )
		return notify_fail("����ڤ���־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_skill("linji-zhuang", 1) < 180 )
		return notify_fail("����ټ�ʮ��ׯ��Ϊ��������\n");

	if( me->query("class") != "bonze" && me->query("family/generation") > 3 )
		return notify_fail("�㲻�ǳ����ˣ��޷�����ټ�ʮ��ׯ�ġ���ڤ���־���\n");

	if( (int)me->query("neili") < 1500 )
		return notify_fail("�������������\n");

	if( (int)me->query("max_neili") < 2000 )
		return notify_fail("���������Ϊ������\n");

	if( me->query_temp("ljz/youming") )	// �޸ı�ǣ�ԭΪ��yun_youming��
		return notify_fail("�����������ټ�ʮ��ׯ�ġ���ڤ���־���\n");

	if( me->query_temp("ljz/wuwo") )	// �ĳ� ���ܺ� wuwo ͬʱʹ��
		return notify_fail("�����������ټ�ʮ��ׯ�ġ����ҡ��־���\n");


	tell_object(me,MAG"��Ǳ���ټ�ʮ��ׯ�ġ���ڤ���־�������\n"NOR);

	if( nh > 150 ) nh = 150 + (nh - 150)/10;

	me->set_temp("ljz/youming", nh);  	// ����޸�
	me->add("neili", - 250);
	me->add_temp("apply/armor", nh);

	ap = me->query("combat_exp", 1 ) /1000 * me->query_skill("force");
	dp = target->query("combat_exp", 1)/ 1000 * target->query_skill("force");

	ap += ap/2;

	me->start_perform(2,"����ڤ���־�");
	me->start_exert(2,"����ڤ���־�");
	me->start_busy(random(2));

	if ( random(ap + dp) > dp ) {
		message_vision(HIW"$N��ɫͻȻ�����ɭ�ɲ���$n��Ȼ�亹ֱð��\n"NOR, me, target);
		me->add_condition("no_perform",nh/30);
		me->add_condition("no_exert",nh/30);
		target->add_condition("no_perform",nh/30);
		target->add_condition("no_exert",nh/30);
		me->start_perform(nh/30,"����ڤ���־�");
		target->start_perform(nh/30, me->name()+"�ġ���ڤ���־�");
	}
	call_out("remove_effect", 1, me, target, nh);
	return 1;
}

void remove_effect(object me,object target,int count)
{
	int i;
	if( !me ) return;
	if( !target
	 || !me->is_fighting("target")
	 || count < 1 ) {
		i = me->query_temp("ljz/youming");
		me->add_temp("apply/armor", -i);
		me->delete_temp("ljz/youming");
		message_vision(HIR"$Nɢȥ�ˡ���ڤ���ķ����ָ���������\n"NOR, me);
		return;
	}
	call_out("remove_effect", 1, me, count - 1);
}

string exert_name(){ return HIW"��ڤ�־�"NOR; }

int help(object me)
{
        write(HIW"\n�ټ�ʮ��ׯ����ڤ�־�����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1500 ���ϣ�
                ������� 2000 ���ϣ�
                �ټ�ʮ��ׯ�ȼ� 180 ���ϣ�
                ���һ��׼��������ӣ�
                ���ܺ͡����ҡ��־�ͬʱʹ�á�
HELP
        );
        return 1;
}
