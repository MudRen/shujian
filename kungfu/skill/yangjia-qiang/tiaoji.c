// tiao.c ����
//Created by Redhat@Sjmud 2009/4/7

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return HIY"����"NOR; }
int perform(object me, object target)
{
	string msg;
	object tweapon, weapon;
	int ap, dp;

	me->clean_up_enemy();
	target = me->select_opponent();

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target) )
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	weapon = me->query_temp("weapon");
	tweapon = target->query_temp("weapon");

	if( !weapon
	 || weapon->query("skill_type") != "spear"
	 || me->query_skill_mapped("spear") != "yangjia-qiang" )
		return notify_fail("�������޷�ʹ�á���������\n");

	if( !tweapon )
		return notify_fail("�Է�û��ʹ���κα��������޷�ʹ�á���������\n");

	if((int)me->query_skill("yangjia-qiang", 1) < 120 )
		return notify_fail("������ǹ��������죬����ʹ�á���������\n");

	if((int)me->query("neili") < 2000 )
		return notify_fail("�������������\n");

	if( (int)me->query_str() < 25 )
		return notify_fail("�������������㣬�޷�ʹ�á���������\n");

	if( me->query_skill_mapped("parry") != "yangjia-qiang"
	&& me->query_skill_mapped("parry") != "yangjia-qiang" )
                return notify_fail("����Ҫ�����м�Ϊ���ǹ������ʹ�á���������\n");

	if ( weapon )
		msg = HIR"$N���ִ�ǹ��������"+weapon->name()+NOR+HIR"������ס$n��������ͼ�Լ�֮ǿ��������$n������\n"NOR;

	me->start_perform(3, "����");

	ap = me->query("combat_exp")/1000 * me->query_str(1);
	dp = target->query("combat_exp")/1000 * target->query_str(1);

	if( random(ap + dp) > dp ) {
		int move_flag = 0;
		if(tweapon->is_owner(target)) move_flag=1;
		msg += HIY"$nֻ��"+tweapon->name()+HIY"ѹ��ȴԽ��Խ�أ���Ҳ�޷����ƣ�һ�����ղ�ס�����б��������˳�ȥ��\n"NOR;
		target->add_busy(1+random(2));
		me->add("neili",-300);

		if (move_flag==0 && random(2)!=1 && tweapon->query("imbued") < 3 && tweapon->move(environment(me))){
			msg += HIY"$n�ı�����$N��ǹ��������ɲ�Ǽ�"+tweapon->name()+HIY"�ѱ�$N�ѱ�����$n���ơ�\n"NOR;
		}
		else {
			msg += HIY"$n��$N����"+weapon->name()+HIY"��$Nǹ��ѹ�ƣ��޷����ƣ�ֻ�ܽ�"+tweapon->name()+HIY"���¡�\n"NOR;
			tweapon->unequip();
			tweapon->move(environment(me));
		}
	}
	else {
		me->add("neili",-200);
              msg += MAG"$n�����˹���"+tweapon->name()+CYN"��"+weapon->name()+CYN"����һ���⻷����$N�����������Σ�\n"NOR;

	}
	me->start_busy(random(2));
	message_vision(msg, me, target);
	return 1;
}

int help(object me)
{
	write(HBMAG"\n���ǹ֮����������"NOR"\n");
	write(@HELP
	���ǹ���������أ��������䳤ǹԶ���빥��֮���ƣ�
	�������Է�������ʹ���޷�ʹ����������
	perform tiaoji

	Ҫ��	��ǰ���� 2000 ���ϣ�
		���ǹ�ȼ� 100 ���ϣ�
		�����м�Ϊ���ǹ��
		���������ޱ���������Ч����
HELP
	);
	return 1;
}