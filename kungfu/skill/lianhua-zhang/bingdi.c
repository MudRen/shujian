// bingdi.c ������������

#include <ansi.h>
inherit F_SSERVER;

string perform_name(){ return HIG"��������"NOR; }

int perform(object me, object target)
{
	int lvl,jiali;

	lvl = (int)me->query_skill("lianhua-zhang", 1);

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 ||!target->is_character()
	 ||!me->is_fighting(target))
		return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_skill_prepared("strike") != "lianhua-zhang"
	 || me->query_skill_mapped("strike") != "lianhua-zhang"
	 || me->query_skill_mapped("parry") != "lianhua-zhang" )
		return notify_fail("������������Ʋ��ܷ����˾��С� \n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("������������ֻ�ܿ���ʹ�á�\n");

	if( me->query_skill("huntian-qigong", 1) < 120 )
		return notify_fail("��Ļ�������������������ʹ�á�����������!\n");

	if( me->query_skill("lianhua-zhang",1) < 120 )
		return notify_fail("�����������Ϊ������������ʹ������������������!\n");

	if( me->query_skill_mapped("force") != "huntian-qigong" )
		return notify_fail("����ڹ����ԡ�\n");

	if( me->query("max_neili") < 1500 )
		return notify_fail("���������Ϊ��Ƿ���\n");

	if( me->query("neili") < 700 )
		return notify_fail("��������������, ����ʹ�á�����������! \n");

	if( me->query("jingli") < 500 )
		return notify_fail("�����ھ�������, ����ʹ�á�����������! \n");

	if( me->query_temp("lhz/bdlh") )
		return notify_fail("��Ŀǰ��Ѫ��ӿ���޷����á�������������\n");

	if( me->query_temp("lhz/cailian") )
		return notify_fail("��е���Ѫ��ӿ���޷����á�������������\n");

	message_vision(HIG"\n$N���²������ˣ������������£������������ϣ�����������������ԲȦ��\n"
                       +"˫������ǰһ����Ȼ��˫���ⷭ���ֻ�������ԲȦ��ͻȻ��Ϯ��$n��\n"
                       +"�����ƻ�����������������ʹ����ʱ˫���紩����������裬�ǳ��ÿ���\n"NOR,me,target);

	jiali = (int)me->query("jiali");
	me->add("neili",- 300);
	me->add("jingli", -80);

	lvl /= 4;

	if( me->query_skill("lianhua-zhang", 1) > 280 )
		lvl = to_int(me->query_skill("lianhua-zhang", 1)/4.0 * me->query_skill("lianhua-zhang", 1)/280.0);

	me->add_temp("apply/strike", lvl);
	me->add_temp("apply/attack", lvl);
	COMBAT_D->do_attack(me, target, 0, 1);

	me->set_temp("lhz/bdlh",2);
	if( present(target,environment(me)) && me->is_fighting(target) )
		COMBAT_D->do_attack(me, target, 0, 1);

	if( present(target,environment(me)) && me->is_fighting(target) )
		COMBAT_D->do_attack(me, target, 0, random(3)?1:3);

	me->add_temp("apply/strike", -lvl);
	me->add_temp("apply/attack", -lvl);
	me->delete_temp("lhz/bdlh");
	me->start_perform(3, "��������");
	me->start_busy(random(2));
	return 1;
}

int help(object me)
{
        write(HIG"\n�����ơ�������������"NOR"\n");
        write(@HELP
        ��������Ϊ�����Ƽ���֮һ�������ﵽ�߿������������ơ�
        Ҫ��  �������  1500 ���ϣ�
                ��ǰ����  700 ���ϣ�
                ��ǰ����  500 ���ϣ�
                �����Ƶȼ� 120 ���ϣ�
                ���������ȼ� 120 ���ϣ�
                �����м�Ϊ�����ơ�
HELP
        );
        return 1;
}
