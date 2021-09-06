// chuanliu.c
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int skill;
	weapon = me->query_temp("weapon");

	if( !target ) target = offensive_target(me);
	
	if( !objectp(target)
	 || !me->is_fighting(target) )
		return notify_fail("��ֻ����ս����ʹ�����д�������\n");

	if (!objectp(weapon) || (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if((int)me->query_skill("linji-zhuang", 1) < 180 )
		return notify_fail("����ټ�ʮ��ׯ�ȼ�����������ʹ�����д�������\n");

	if (me->query_skill_mapped("force") != "linji-zhuang")
		return notify_fail("����ʹ�õ��ڹ����ԡ�\n");

	if ((int)me->query_skill("yanxing-daofa", 1) < 180 )
		return notify_fail("������е����ȼ�����������ʹ�����д�������\n");

	if ((int)me->query_skill("blade", 1) < 180 )
		return notify_fail("��Ļ���������������죬����ʹ�����д�������\n");

	if ( me->query_skill_mapped("blade") != "yanxing-daofa"
	 || me->query_skill_mapped("parry") != "yanxing-daofa" )
		return notify_fail("�������޷�ʹ�����д�������\n");

	if ((int)me->query("neili") < 1000 )
		return notify_fail("����������̫��������ʹ�����д�������\n");

	if ((int)me->query("max_neili") < 2000 )
		return notify_fail("����������̫��������ʹ�����д�������\n");

	if (me->query_temp("yanxing/pfm") ) 
		return notify_fail("���Ѿ���ʹ�����д������ˣ�\n");

	message_vision(HIY"\n$N�����ټ�ʮ��ׯ������" + weapon->name() +HIY"��Ȼһ����\n"NOR, me);
	skill = me->query_skill("yanxing-daofa",1)/6;
	skill += random(skill);
	if ( skill > 100) skill = 100 + random(skill-100)/10;
	me->add_temp("apply/damage", skill);
	me->set_temp("yanxing/pfm", skill);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	if ( me->query_skill("yanxing-daofa", 1) > 200)
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);

	me->start_perform(2, "���д�����");
	me->add("neili", -300);
	me->start_busy(random(2));
	call_out("remove_effect", 1, me, target, weapon, skill);
	return 1;
}

void remove_effect(object me, object target,object weapon, int skill)
{
	if( !me) return;
	if(!me->is_fighting(target)
	|| ! weapon
	|| me->query_temp("weapon") != weapon
	|| me->query_skill_mapped("blade") != "yanxing-daofa"
	|| me->query_skill_mapped("parry") != "yanxing-daofa"){
		if( weapon)
			message_vision(HIW"$N���ϵĵ��⽥������ʧ�ˣ�\n"NOR, me);
		me->add_temp("apply/damage", -skill);
		me->delete_temp("yanxing/pfm");
		return;
	}
	call_out("remove_effect", 1, me, target, weapon, skill);
}

string perform_name(){ return HIY"���д�����"NOR; }

int help(object me)
{
        write(HIY"\n���е���֮�����д���������"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1000 ���ϣ�
                ������� 2000 ���ϣ�
                ���е����ȼ� 180 ���ϣ�
                �ټ�ʮ��ׯ�ȼ� 180 ���ϣ�
                ���������ȼ� 180 ���ϣ�
                ��������Ϊ���е�����
                �����м�Ϊ���е�����
                �����ڹ�Ϊ�ټ�ʮ��ׯ��
                ���ֱֳ�����

HELP
        );
        return 1;
}
