// 2005.7.4 by Lane@SJ

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg, dodge_skill;
	object weapon;
        int ap, dp,i,skill;

	if( !target ) target = offensive_target(me);

	if( !me->query("raozhi") )
		return notify_fail("��δ�ô��ڡ���ָ�ὣ����\n");

	if( !objectp(target)
	|| !target->is_character()
	|| !me->is_fighting(target)
	|| !living(target) )
		return notify_fail("����ָ�ὣ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_temp("tjj/lian") )
		return notify_fail("������ʹ�á������־���\n");

	if( me->query_temp("tjj/chan") )
		return notify_fail("������ʹ�á������־���\n");

	if( (int)me->query_skill("taiji-jian", 1) < 200 )
		return notify_fail("���̫����������̫ǳ�ˡ�\n");

	if( (int)me->query_skill("sword", 1) < 200 )
		return notify_fail("��Ļ�����������̫ǳ�ˡ�\n");

	if( (int)me->query_skill("yinyun-ziqi", 1) < 200 )
		return notify_fail("����ڹ�����̫ǳ�ˡ�\n");

	if( (int)me->query("max_neili") < 3000 )
		return notify_fail("�������̫ǳ�ˡ�\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("�������������\n");

	if( me->query_skill_mapped("force") != "yinyun-ziqi" )
		return notify_fail("����ʲôΪ�ڹ�������ʹ����ָ�ὣ����\n");

	if( !objectp(weapon = me->query_temp("weapon"))
	 || weapon->query("skill_type") != "sword"
	 || me->query_skill_mapped("sword") != "taiji-jian"
	 || me->query_skill_mapped("parry") != "taiji-jian" )
		return notify_fail("��ʹ���ˡ���ָ�ὣ��ô?\n");
	
	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");
	//For npc Chan+Raozhi ��å����

	ap = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK) + me->query("combat_exp")/2;
	dp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE) + target->query("combat_exp")/2;

	ap += me->query_int(1) * me->query_dex(1) * 1000;
	dp += target->query_int(1) * target->query_con(1) * 1000;
skill = me->query_skill("taiji-jian",1);
        if( skill > 550 )
                ap +=ap/2 + random(ap);

	msg = HIW"\n$Nʩչ��̫�������е���ָ�ὣ������"+weapon->name()+HIW"������һ�����ߣ��������磬������\n"NOR;

        if ( random( ap + dp ) > dp || ( skill> 450 && !userp(target))) {
		msg += HIY"$n���ɸе����£�ֻ�о�ǰ�����Ҷ�����$N������һ���Ӳ�֪������Ǻã�\n"NOR;
		i = me->query_skill("taiji-jian", 1) /100;
		target->add_busy(4+i+random(2));
		target->apply_condition("no_perform",1+ i);
		if( !userp(target) ) target->add_busy(random(2));
		if( target->query_temp("lost_attack") < 1 )
			target->add_temp("lost_attack", i+ random(3));
		me->add("neili", -300);
		me->add("jingli", -100);
if(skill<450 )
                me->start_perform(1 + i/2 , "����ָ�ὣ��");
	}
	else {
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		me->add("neili", -100);
		me->add("jingli", -50);
                me->start_perform(1+random(2), "����ָ�ὣ��");
	}
if(skill<450 )
        me->start_busy(1);
	message_vision(msg, me, target);
	return 1;
}

string perform_name(){ return HIR"��ָ�ὣ"NOR; }

int help(object me)
{
        write(HIR"\n̫������֮����ָ�ὣ����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1000 ����;
                ������� 3000 ���ϣ�
                ̫�������ȼ� 200 ���ϣ�
                �������ȼ� 200 ���ϣ�
                ���������ȼ� 200 ���ϣ�
                ��������Ϊ̫��������
                �����м�Ϊ̫��������
                �����ڹ�Ϊ��������
                450�Ժ��Ծ��
                ��õ����ڡ���ָ�ὣ����

HELP
        );
        return 1;
}
