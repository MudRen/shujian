// huixuan.c ����ʮ��ʽ

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return HIY"����ʮ��ʽ"NOR; }

int perform(object me, object target)
{
	string msg;
	object weapon;
	int times, ap, dp;

	if( !target ) target = offensive_target(me);

	weapon = me->query_temp("weapon");

	if( !objectp(target) || !target->is_character() || !me->is_fighting(target) || !living(target) )
		return notify_fail("������ʮ��ʽ��ֻ����ս����ʹ�á�\n");

	if( !weapon || weapon->query("skill_type") != "whip"
	 || me->query_skill_mapped("whip") != "huifeng-bian"
	 || me->query_skill_mapped("parry") != "huifeng-bian")
		return notify_fail("�������޷�ʹ�á�����ʮ��ʽ����\n");

//	if( target->is_busy() )
//		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	if( (int)me->query_skill("huifeng-bian", 1) < 100 )
		return notify_fail("��Ļط�޷�������죬����ʹ�á�����ʮ��ʽ��������\n");

	if( (int)me->query_skill("huntian-qigong", 1) < 100 )
		return notify_fail("��Ļ�������������񣬲���ʹ�á�����ʮ��ʽ����\n");

	if( (int)me->query("max_neili", 1) < 800 )
		return notify_fail("���������Ϊ����������ʹ�á�����ʮ��ʽ����\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("����������̫��������ʹ�á�����ʮ��ʽ����\n");

	if( me->query_skill_mapped("force") != "huntian-qigong" )
		return notify_fail("������ʹ�õ��ڹ���ط�޷���ִ�������ʹ�á�����ʮ��ʽ����\n");

	if( (int)me->query_temp("huixuan") )
		return notify_fail("����������ʹ�á�����ʮ��ʽ����\n");

	msg = HIY+"\n$N""ͻȻ���������ݰ㼱ת��Ȧ�����е�"+weapon->name()+HIY+"����ʮ����"HIW"�û�Ī��"HIY"����ʽ������$n�����ܣ�\n"NOR;

	ap = me->query("combat_exp", 1)/ 1000 * me->query_skill("whip");
	dp = target->query("combat_exp", 1)/ 1000 * target->query_skill("parry");

	if( random( ap + dp)  > dp ) {
		msg += HIR+"$nһ��û���񣬱�$N���Ī�����ʽ�������ڻ����ı�Ӱ�\n"NOR;
		me->start_perform(10 , "����ʮ��ʽ");
		times = random(me->query_skill("whip")/20) + 4;
		if( times <  6 ) times = 6;
		if( times > 13 ) times = 13;
		me->set_temp("huixuan", times);
		if( wizardp(me) ) tell_object(me, HIY"����ʮ��ʽ�� "+times+" �Ρ�\n"NOR);
		message_vision(msg, me, target);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
		me->start_busy(random(2));
		if( !userp(target) ) target->add_busy(random(2));
		call_out("huixuan", 1, me, target);
	}
	else {
		msg += CYN + "����$n�������أ����й�ֱ�������ݲ��ȵİ����˲��ơ�\n"NOR;
		me->start_perform(2 , "����ʮ��ʽ");
		me->start_busy(random(2));
		message_vision(msg, me, target);
	}
	me->add("neili", -200);
	return 1;
}

int huixuan(object me, object target)
{
	int lvl, ap, dp, times;
	object weapon;

	if( !me ) return 0;

	weapon = me->query_temp("weapon");

	if( !target ) {
		message_vision(HIY+"\n$N"+HIY+"�����Ѿ���"+weapon->query("name")+HIY+"������Ĵ���������\n"NOR,me);
		me->start_perform(1 , "����ʮ��ʽ");
		me->delete_temp("huixuan");
		return 1;
	}

	if( !me->is_fighting(target) ) {
		message_vision(HIY+"\n$N"+HIY+"�����Ѿ���"+weapon->query("name")+HIY+"������Ĵ���������\n"NOR,me);
		me->start_perform(1 , "����ʮ��ʽ");
		me->delete_temp("huixuan");
		return 1;
	}

	if( !living(me) || me->is_ghost() ) {
		me->start_perform(1 , "����ʮ��ʽ");
		me->delete_temp("huixuan");
		return 1;
	}

	if( !weapon || weapon->query("skill_type") != "whip"
	 || me->query_skill_mapped("whip") != "huifeng-bian"
	 || me->query_skill_mapped("parry") != "huifeng-bian" ) {
		me->start_perform(1 , "����ʮ��ʽ");
		me->delete_temp("huixuan");
		return 1;
	}

	if( me->query_temp("huixuan") < 1 ) {
		message_vision(HIY+"\n$N"+HIY+"�����Ѿ���"+weapon->query("name")+HIY+"������Ĵ���������\n"NOR,me);
		me->start_perform(1 , "����ʮ��ʽ");
		me->delete_temp("huixuan");
		return 1;
	}

	if( me->is_busy() ) {
		call_out("huixuan", 1, me, target);
		return 1;
	}

	lvl = me->query_skill("huifeng-bian", 1);

	ap = me->query("combat_exp", 1)/ 1000 * me->query_skill("whip");
	dp = target->query("combat_exp", 1)/ 1000 * target->query_skill("dodge");

	me->start_perform(10 , "����ʮ��ʽ");

	if( random(ap + dp)  > dp/2 ) {
		if( weapon->query("id") == "po budai" ) {
			message_vision( HIR+me->query("name")+"�����е�"+weapon->query("name")+HIR"��$nͷ��һ�֡�\n"NOR, me, target);
			tell_object(target,BLU"���������һ���ʹ�����������㱻Ы��ҧ�ˡ�\n"NOR);
			target->receive_wound("qi", me->query_skill("whip")/3, me);
			target->receive_wound("jing", me->query_skill("whip")/3, me);
			target->add_condition("scorpion_poison", 5);
		}
		message_vision(HIR"\n$n����ǰ��"HIW"��Ӱ"HIR"��ȫ�Ի�ס�ˣ�$N�˴������������У�"NOR, me, target);
		if( !userp(target) ) target->add_busy(random(2));
		me->add_temp("apply/whip", lvl/3);
		me->add_temp("apply/attack", lvl/3);
		me->add_temp("apply/damage", lvl/6);
		target->add_temp("apply/dodge", - me->query_skill("whip", 1)/4);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(3)?1:3);
		me->add_temp("huixuan", -1);

		if( me->is_fighting(target) ) {
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:2);
			me->add_temp("huixuan", -1);
		}
		me->add_temp("apply/whip", -lvl/3);
		me->add_temp("apply/attack", -lvl/3);
		me->add_temp("apply/damage", -lvl/6);
		target->add_temp("apply/dodge", me->query_skill("whip", 1)/4);
		times = me->query_temp("huixuan");
		call_out("huixuan", 2+random(3), me, target);
		if( wizardp(me) ) tell_object(me, HIY"����ʮ��ʽ���� "+times+" �Ρ�\n"NOR);
		return 1;
	}

	times = me->query_temp("huixuan");
	call_out("huixuan", 1+random(3), me, target);
	if( wizardp(me) ) tell_object(me, HIY"����ʮ��ʽ���ƽ⣬���� "+times+" �Ρ�\n"NOR);
	return 1;
}

int help(object me)
{
	write(HIY"\n�ط�޷�������ʮ��ʽ����"NOR"\n");
        write(@HELP
	Ҫ��  �������  800 ���ϣ�
                ��ǰ����  500 ���ϣ�
                �ط�޷��ȼ� 100 ���ϣ�
                ���������ȼ� 100 ���ϣ�
                �����ڹ�Ϊ����������
HELP
        );
        return 1;
}