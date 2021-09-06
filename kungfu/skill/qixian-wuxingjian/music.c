// music.c
// modified by action@SJ 2009/1/10
// updated BY Zmud@Sjmud 10/3/2009
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg, dodge_skill;
	object weapon;
	int ap, dp,i;

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	|| !target->is_character()
	|| !me->is_fighting(target)
	|| !living(target) )
		return notify_fail("���������ɡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_skill("qixian-wuxingjian", 1) < 300 )
		return notify_fail("����������ν��ȼ����㣬�޷�ʹ�á��������ɡ���\n");

	if( (int)me->query_skill("sword", 1) < 300 )
		return notify_fail("��Ļ��������ȼ����㣬�޷�ʹ�á��������ɡ���\n");

	if( (int)me->query_skill("xixing-dafa", 1) < 300 )
		return notify_fail("��Ļ����ڹ��ȼ����㣬�޷�ʹ�á��������ɡ���\n");

	if( (int)me->query("max_neili") < 8000 )
		return notify_fail("����������㣬�޷�ʹ�á��������ɡ���\n");

	if( (int)me->query("neili") < 5000 )
		return notify_fail("�������������\n");		

	if( me->query_skill_mapped("force") != "xixing-dafa" )
		return notify_fail("������ʹ�õ������ڹ����ԣ��޷�ʹ�á��������ɡ���\n");

	if( !objectp(weapon = me->query_temp("weapon"))
	 || weapon->query("skill_type") != "sword"
	 || me->query_skill_mapped("sword") != "qixian-wuxingjian"
	 || me->query_skill_mapped("parry") != "qixian-wuxingjian" )
		return notify_fail("�����޽��������ʹ���ˡ��������ɡ���\n");
	
	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");
		
	ap = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK) + me->query("combat_exp")/2;
	dp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE) + target->query("combat_exp")/2;

	ap += me->query_int(1) * me->query_dex(1) * 1000;
	dp += target->query_int(1) * target->query_con(1) * 1000;

	if( me->query_skill("qixian-wuxingjian", 1) > 300 )
		ap += random(ap/2);
msg = "\n  "HIB"$N�������У���ָ��" + weapon->name() +HIB"����һ����" + weapon->name() +HIB"��������һ����������ĸ�Ƶ���ɣ�������֮�˸о������ذ���\n"NOR;
message_vision(msg, me, target);  
                   
msg = HIR"\n��" + weapon->name() +HIR"�ϲ��ҷ��������ǹ�ʾ��Ͼ��ȴ��������֮�й�ע�ϳ���������������"+
"\n��������$n����������һ���������㲻֪�����Լ���ʽ��Ϊ�������ơ�\n"NOR;


	if ( random( ap + dp ) > dp ) {
		msg += HIM "\n$nֻ����$N����������" + weapon->name() +HIM"�����ġ�"HIB"��������"HIM"������һ��������͸$n�Ĺ�Ĥ��\n";
		i=random(2);
		target->add_busy(4+i+random(2));
		if( !userp(target) ) target->add_busy(random(2));
		if( target->query_temp("lost_attack") < 1 )
			target->add_temp("lost_attack", random(3));
		me->add("neili", -300);
		me->add("jingli", -100);
		me->start_perform(3 + i, "���������ɡ�");
	}
	else {
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
                msg += HIM "\n����$n����$N��ͼ����æ���������Ŭ��ʹ�Լ����ܡ�"HIB"��������"NOR+HIM"���ĸ��ţ���$n��������������֮�С�\n" NOR;
		me->add("neili", -100);
		me->add("jingli", -50);
		me->start_perform(2+random(2), "���������ɡ�");
	}
	me->start_busy(1);
	message_vision(msg, me, target);
	return 1;
}

string perform_name(){ return HIB"��������"NOR; }
