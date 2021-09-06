// bingdi.c ��������

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int lvl, j;

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("���������١�ֻ�ܿ���ʹ�á�\n");

	lvl = (int)me->query_skill("zhenshan-mianzhang", 1);

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !me->is_fighting(target) )
		return notify_fail("���������١�ֻ����ս���жԶ���ʹ�á�\n");

	if( lvl < 100 )
		return notify_fail("����ɽ������Ϊ�в�����,�޷�ʹ�á��������١���\n");

	if( (int)me->query_skill("yinyun-ziqi",1) < 100 )
		return notify_fail("�����������Ϊ��ǳ���޷�ʹ�á��������١���\n");

	if( (int)me->query_skill("strike",1) < 100 )
		return notify_fail("��Ļ����Ʒ��ȼ�����������ʹ�á��������١���\n");

	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("���������Ϊ̫��������ʹ�á��������١���\n");

	if( (int)me->query("neili") < 700 )
		return notify_fail("�������̫���ˣ��޷�ʹ�ó����������١���\n");

	if( (int)me->query("jingli") < 500 )
		return notify_fail("��ľ���̫���ˣ��޷�ʹ�ó����������١���\n");

	if( me->query_skill_prepared("strike") != "zhenshan-mianzhang"
	 || me->query_skill_mapped("strike") != "zhenshan-mianzhang"
	 || me->query_skill_mapped("parry") != "zhenshan-mianzhang"
	 || me->query_skill_mapped("force") != "yinyun-ziqi")
		return notify_fail("�������޷�ʹ�á��������١����й�����\n");

	if( me->query_temp("wd_hkbd"))
		return notify_fail("���ʹ�꡸�������١���Ŀǰ��Ѫ��ӿ���޷��ٴ����ã�\n");

	message_vision(HIC"\n$N������һ���������ֻ����ͻ�$n�Ҽգ����ֳ�ָ����$n��硰ȱ��Ѩ����\n"
		+"�������ƻ�$n��գ�����ʳָ��$n�Ҽ��ȱ��Ѩ����������ʽ�����籩��\n"
		+"�����ʹ������һ�н������������١������ƺ���������ȴʮ��������\n"NOR,me,target);

        j = lvl/2;

	if( lvl > 300 )
		j = to_int( lvl/4.0 * lvl/300.0);

	me->add_temp("apply/strike", j);
	me->add_temp("apply/attack", j);
 me->add_temp("apply/damage", j);
	me->set_temp("wd_hkbd",1);
        COMBAT_D->do_attack(me, target, 0, 3);
        COMBAT_D->do_attack(me, target, 0, 3);

	if( me->is_fighting(target) )
		COMBAT_D->do_attack(me, target, 0, random(3)?1:3);

	if( lvl > 150 && me->is_fighting(target) )
		COMBAT_D->do_attack(me, target, 0,  random(2)?1:3);


	me->add_temp("apply/strike", -j);
	me->add_temp("apply/attack", -j);
 me->add_temp("apply/damage",- j);
	me->delete_temp("wd_hkbd");
	me->add("neili", -300);
	me->add("jingli", -100);
	me->start_busy(random(2));
	me->start_perform(2+random(2), "��������");
	return 1;
}

string perform_name(){ return HIC"��������"NOR; }

int help(object me)
{
        write(HIC"\n��ɽ����֮���������١���"NOR"\n\n");
        write(@HELP
        �����������ڹ����������޼���ʹ�õ����⹥������˲���������С�

        Ҫ��  ��ǰ���� 700 ���ϣ�
                ������� 1000 ���ϣ�
                ��ǰ���� 500 ���ϣ�
                ��ɽ���Ƶȼ� 100 ���ϣ�
                �������ȼ� 100 ���ϣ�
                �����Ʒ��ȼ� 100 ���ϣ�
                �����Ʒ�Ϊ��ɽ���ƣ�
                �����м�Ϊ��ɽ���ƣ�
                �����ڹ�Ϊ��������

HELP
        );
        return 1;
}
