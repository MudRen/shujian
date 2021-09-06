// songyangjue.c by darken@SJ
// Lklv@SJ modified 2001.10.22

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon = me->query_temp("weapon");

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target) )
		return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_skill("hanbing-zhenqi", 1) < 90 )
		return notify_fail("��ĺ��������������޷�ʩչ��������\n");

	if( me->query_skill("songshan-jian", 1) < 90 )
		return notify_fail("��Ľ����̶Ȼ�����ʹ����������\n");

	if( me->query_skill("songyang-shou", 1) < 90 )
		return notify_fail("��Դ���������ʶ��������\n");

	if( me->query("neili") < 500 )
		return notify_fail("�����������ʹ����������\n");

	if( me->query("jingli") < 300 )
		return notify_fail("��ľ�������ʹ����������\n");

	if (!weapon
	 || weapon->query("skill_type") != "sword"
	 || me->query_skill_mapped("sword") != "songshan-jian"
	 || me->query_skill_mapped("parry") != "songshan-jian" )
		return notify_fail("�����ʹ����ɽ������\n");

	message_vision(HIW"\n$N��Хһ��������ͻ�䣬���н����һ������ʯ������Ȼʩչ���������ֵ�������\n" NOR, me);
	me->set_temp("ssj_songyang", 2);
 if( me->query_skill("songyang-shou", 1) < 160 ) target->start_busy(1+random(1));
        me->add_temp("apply/attack", 50);
        me->add_temp("apply/damage", 150);
        me->add_temp("apply/sword", 150);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(3)?1:3);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);
	me->add_temp("apply/attack", -50);
        me->add_temp("apply/damage", -150);
        me->add_temp("apply/sword", -150); 
	me->add("neili", -200);
	me->add("jingli", -100);
	me->delete_temp("ssj_songyang");
	me->start_perform(2+random(2), "������");
	me->start_busy(random(2));
	return 1;
}

string perform_name(){ return HIW"������"NOR; }

int help(object me)
{
        write(HIW"\n��ɽ����֮������������"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 500 ���ϣ�
                ��ǰ���� 300 ���ϣ�
                ��ɽ�����ȼ� 90 ���ϣ�
                ���������ȼ� 90 ���ϣ�
                �������ֵȼ� 90 ���ϣ�
                ��������Ϊ��ɽ������
                �����м�Ϊ��ɽ������
                ���ֱֳ�����

HELP
        );
        return 1;
}
