// duo.c ʥ������᡹�־�
// By Spiderii@ty ����

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return BCYN"���־�"NOR; }
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
		return notify_fail("�����־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	weapon = me->query_temp("weapon");
	tweapon = target->query_temp("weapon");

	if( !weapon
	 || weapon->query("skill_type") != "dagger"
	 || me->query_skill_mapped("dagger") != "shenghuo-lingfa" )
		return notify_fail("�������޷�ʹ�ö��־���\n");

	if( !tweapon )
		return notify_fail("�Է�û��ʹ���κα��������޷�ʹ�á����־�����\n");

	if((int)me->query_skill("shenghuo-lingfa", 1) < 120 )
		return notify_fail("���ʥ�����������죬����ʹ�á��᡹�־���\n");

	if( me->query_temp("qkdny/yin") )
		return notify_fail("������ʩչǬ����Ų�ơ������־��أ�\n");

	if( me->query_temp("qkdny/hua") )
		return notify_fail("������ʩչǬ����Ų�ơ������־��أ�\n");

	if((int)me->query("neili") < 1000 )
		return notify_fail("�������������\n");

	if( (int)me->query_con(1) < 30 )
		return notify_fail("���᡹�־���Ҫ�ܸߵ��ڹ������ܳ��治��İѶԷ��ı���������������������󻹲�����\n");

	if( me->query_skill_mapped("parry") != "shenghuo-lingfa"
	&& me->query_skill_mapped("parry") != "qiankun-danuoyi" )
                return notify_fail("����Ҫ�����м�Ϊʥ���������ʹ�á��᡹�־���\n");

	if ( weapon )
		msg = BCYN"$N�������ƣ�˫��һ�������Ѵ���$n�ı����ϣ���ͼ��ʥ������᡹�־���$n�ı������¡�\n"NOR;

	me->start_perform(3, "���־�");

	ap = me->query("combat_exp")/1000 * me->query_str(1);
	dp = target->query("combat_exp")/1000 * target->query_dex(1);

	if( random(ap + dp) > dp ) {
		int move_flag = 0;
		if(tweapon->is_owner(target)) move_flag=1;
		msg += HIY"$nֻ��"+tweapon->name()+HIY"�������ַɳ���һ�����ղ�ס�����б���������˳�ȥ��\n"NOR;
		target->add_busy(1+random(2));
		me->add("neili",-300);

		if (move_flag==0 && random(2)!=1 && tweapon->query("imbued") < 3 && tweapon->move(me)){
			msg += HIY"$n�ı�����$N������һѹһ����ɲ�Ǽ�"+tweapon->name()+HIY"�ѱ�$N���¡�\n"NOR;
                    tweapon->move(environment(me));
}
		else {
			msg += HIY"$n��$N����"+weapon->name()+HIY"һ�����������ɵ�������,ֻ����"+tweapon->name()+HIY"����һ�ߡ�\n"NOR;
			tweapon->move(environment(me));
		}
	}
	else {
		me->add("neili",-200);
              msg += CYN"$n���Ʋ������"+weapon->name()+CYN"�������ѣ�����������������$N�Ĺ�����\n"NOR;

	}
	me->start_busy(random(2));
	message_vision(msg, me, target);
	return 1;
}

int help(object me)
{
	write(BCYN"\nʥ���֮�����־�����"NOR"\n\n");
	write(@HELP
	Ҫ��	��ǰ���� 1000 ���ϣ�
		ʥ����ȼ� 120 ���ϣ�
		������� 30��
		�����м�Ϊʥ�����Ǭ����Ų�ƣ�
		���ֱֳ�����

HELP
        );
        return 1;
}

