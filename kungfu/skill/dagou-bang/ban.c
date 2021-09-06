// ban.c �򹷰���--���־�
// Creat by Looklove@SJ 3/16/2001
// modified by Looklove 2001.5.10
// Modified by Lane@SJ 2005.7.29

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return HBBLU"���־�"NOR; }
int perform(object me, object target)
{
	string msg;
	object tweapon, weapon;
	int ap ,dp ,p, n;

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target) )
		return notify_fail("�����־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	weapon = me->query_temp("weapon");

	if( !weapon
	 || weapon->query("skill_type") != "stick"
	 || me->query_skill_mapped("stick") != "dagou-bang" 
	 || me->query_skill_mapped("parry") != "dagou-bang" )
		return notify_fail("�������޷�ʹ�á����־�����\n");

	ap = me->query("combat_exp");
	dp = target->query("combat_exp");

	tweapon = target->query_temp("weapon");

	if( me->query_skill("dagou-bang", 1) < 140 )
		return notify_fail("��Ĵ򹷰�����������죬����ʹ�á����־�����\n");

	if( me->query_skill("bangjue",1) < 140 )
		return notify_fail("��Ĵ򹷰���������죬�޷�ʹ�������־�����\n");

	if( (int)me->query_skill("huntian-qigong",1) < 140 )
		return notify_fail("��Ļ��������������㣬�޷�ʹ�������־�����\n");

	if( (int)me->query("neili") < 600 )
		return notify_fail("��������������޷�ʹ�������־�����\n");

	if( (int)me->query("jingli") < 400 )
		return notify_fail("��ľ�������������ʹ�������־�����\n");

	if( (int)me->query("max_neili") < 2000 )
		return notify_fail("��������Ϊ���ڲ����������á����־�����\n");

	if( target->query_temp("dgb/ban") )
		return notify_fail("�Է��Ѿ��������ˣ����ֹ����ɡ�\n");

	n = me->query_skill("bangjue", 1);

	if( me->query_skill("dagou-bang", 1) > 350 )
		n += random(me->query_skill("bangjue", 1)/2);

	ap = COMBAT_D->skill_power(me, "stick", SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

	ap += ap /100000 * me->query_skill("stick") * me->query_int(1)/3;
	dp += dp /100000 * target->query_skill("dodge") * target->query_int(1)/3;

	msg = HBBLU"$N"+weapon->name()+HBBLU"�ӳ����ԡ����־����ŵ�ɨȥ��һ���У������������������̣������������\n"NOR;

	if( ( ap = random(ap+dp) ) > dp*3/2 ) {
		msg += HBBLU"$n������������"+weapon->name()+HBBLU"��������һ����������һ�����˵ص��ˡ�\n"NOR;
		target->add_busy(2+random(3));
		target->recieve_damage("qi", n*3, me);
		target->recieve_wound("qi", n*3, me);
		if (random(2)) {
			p = (target->query("eff_qi")+target->query_temp("apply/qi"))*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		}
		else {
			p = target->query("qi")*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg += "( $n"+COMBAT_D->status_msg(p)+" )\n";
		}
		target->set_temp("dgb/ban", n);
		target->add_temp("apply/dodge",-n);
		target->apply_condition("dgb_ban_wound", n/30);
		me->add("neili", -400);
		me->add("jingli", -200);
		me->start_busy(random(2));
		call_out("check_perform", 1, target, n);
	}
	else if( ap > dp ) {
		msg += HBBLU"$n���»��ң�̧����ȥ̤ס"+weapon->name()+HBBLU"��ȴ��"+weapon->name()+HBBLU"�ڽ�����һ����ͨ���ء�\n"NOR;
		target->add_busy(1+random(2));
		target->recieve_damage("qi", n*2, me);
		target->recieve_wound("qi", n*2, me);
		if( random(2) ) {
			p = (target->query("eff_qi")+target->query_temp("apply/qi"))*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		}
		else {
			p = target->query("qi")*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg += "( $n"+COMBAT_D->status_msg(p)+" )\n";
		}
		target->set_temp("dgb/ban", n/2);
		target->add_temp("apply/dodge",-n/2);
		target->apply_condition("dgb_ban_wound",n/40);
		me->add("neili", -300);
		me->add("jingli", -100);
		me->start_busy(random(2));
		call_out("check_perform", 1, target, n/2);
	}
	else {
		msg += HIG"$n���̹���ʮ����ʵ����չ��Ų��㿪"+weapon->name()+HIG"�İ��ƣ�˳��һ������$N��ƨ�ɡ�\n"NOR;
		me->start_busy(1);
		me->add("neili", -150);
		me->add("jingli", -50);
	}
	if( wizardp(me) ) tell_object(me, HIY"�򹷰��������־��������ʶԱ� "+ap+" ��"+dp+"��\n"NOR);
	me->start_perform(3, "���־�");
	message_vision(msg, me, target);
	return 1;
}

void check_perform(object target, int bonus)
{
	if ( !target || !target->query_temp("dgb/ban")) return;
	if ( target->query_temp("dgb/ban")
	&& ! target->query_condition("dgb_ban_wound")) {
		target->add_temp("apply/dodge", bonus);
		target->delete_temp("dgb/ban");
		return;
	}
	call_out("check_perform", 1, target, bonus);
}

int help(object me)
{
        write(HBBLU"\n�򹷰������־�����"NOR"\n");
        write(@HELP
        �򹷰����ᡢ�ɡ�����ƣ��轫�������Ĵ�ֻ����Ӱ������Ӱ��
        �⡸���־�����ȴ��ר���������̵��������������̲��ȵĶ���
        ������Ч��һ�����У��������α������ش������ơ�

        Ҫ��  ������� 2000 ���ϣ�
                ��ǰ���� 600 ���ϣ�
                �򹷰��ȼ� 140 ���ϣ�
                ���������ȼ� 140 ���ϣ�
                �򹷰����ȼ� 140 ���ϣ�
                �����м�Ϊ�򹷰���
HELP
        );
        return 1;
}
