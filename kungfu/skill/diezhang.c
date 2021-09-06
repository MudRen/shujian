// diezhang.c (�����Ʒ�)  perform ���ص���
// cck 21/8/97
// cool 981010
// augx@sj 8/28/2001
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg, *limbs;
	int p,count, damage = 0, damage1;
	int arg,ap,dp, i=0;

	if( !target )
		target = offensive_target(me);

	if( !objectp(target) || !me->is_fighting(target) )
		return notify_fail("�����ص��ơ�ֻ����ս���жԶ���ʹ�á�\n");

	if( objectp( me->query_temp("weapon")) )
		return notify_fail("ֻ�п��ֲ���ʩչ�����ص��ơ���\n");

	if( me->query_skill("strike") < 180 )
		return notify_fail("����Ʒ�������죬����ʹ�á����ص��ơ���\n");

	if( me->query_skill("xuantian-wuji", 1) < 150 )
		return notify_fail("��������޼����ȼ�����������ʹ�á����ص��ơ���\n");

	if( me->query_str() < 30 )
		return notify_fail("�����������ǿ������ʹ�á����ص��ơ���\n");

	if( me->query("max_neili") < 2000 )
		return notify_fail("��������Ϊ����������ʹ�á����ص��ơ���\n");

	if( me->query("neili") < 800 )
		return notify_fail("����������̫��������ʹ�á����ص��ơ���\n");

	if( me->query("jingli") < 100 )
		return notify_fail("�����ھ����������Լ�С�İ���\n");

	if (me->query_skill_prepared("strike") != "kunlun-zhang"
	 || me->query_skill_mapped("force") != "xuantian-wuji" 
	 || me->query_skill_mapped("strike") != "kunlun-zhang" 
	 || me->query_skill_mapped("parry") != "kunlun-zhang" )
		return notify_fail("�������޷�ʹ�á����ص��ơ����й�����\n");

        if( me->query("env/���ص���") == "���Ƶ���" ) {
		message_vision(HIG"\n$N����һ������������֮��һ�ƻ�����ʹ�����ǡ����ص��ơ��Ʒ���"NOR, me, target);

		i = me->query_skill("kunlun-zhang", 1)/100;
		if( i < 1 ) i = 1;
		if( i > 2 ) i = 2 + random(2);

		me->add_temp("apply/attack", me->query_skill("xuantian-wuji", 1)/2);
		me->add_temp("apply/strike", me->query_skill("kunlun-zhang", 1)/3);
		me->add_temp("apply/dodge", me->query_skill("kunlun-zhang", 1)/3);
		me->add("jiali", i*50);

		me->set_temp("diezhang1", 1);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SUPER);
		me->delete_temp("diezhang1");

		me->set_temp("diezhang2", i+1);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);
		me->delete_temp("diezhang2");

		me->add_temp("apply/attack", -me->query_skill("xuantian-wuji", 1)/2);
		me->add_temp("apply/strike", -me->query_skill("kunlun-zhang", 1)/3);
		me->add_temp("apply/dodge", -me->query_skill("kunlun-zhang", 1)/3);
		me->add("jiali", -i*50);

		me->receive_damage("neili", 400);
		me->receive_damage("jingli", 50);

		me->start_perform(3, "�����Ƶ��ϡ�");
		me->add_busy(1+random(2));
		return 1;
	}

// �����ص� �Ļ�ѧ pfm

	arg = (me->query_skill("kunlun-zhang", 1)-1) / 50;

	if( me->query("neili") < 50*arg + me->query("jiali")*arg/4 )
		return notify_fail("�����ڵ�����ʩչ������ô���С�\n");

	message_vision(HIG"$N����һ���������һ������������"+chinese_number(arg)+"�ƣ���������ǰ�У�����������һ������$n��\n\n"NOR, me, target);

	ap = COMBAT_D->skill_power(me, "strike", SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

	if (target->is_busy())
		dp -= dp / 2;

	if (!userp(target)) {
		i = me->query_temp("kl/dzfail/"+target->query("id"));
		if (dp / 2 > ap)
			i = 0;
	}

	if (!living(target))
		i = 2;

	if (random(ap+dp) > dp || i >= 2) {
		limbs = target->query("limbs");
		damage = 0;
		for (count=0; count<arg; count++) {
			message_vision(
				replace_string(SKILL_D("kunlun-zhang")->query_action(me, 0)["action"],
					"$l", limbs[random(sizeof(limbs))]
				) + "��\n", me, target);
			damage1 = 200 + random(100);
			if (count > 6 && arg >= 8)
				damage1 += random(480);
			damage1 += me->query("jiali")/2 + random(me->query("jiali")/4);
			if ( count > 5 && random(2)) damage1 /= 2;
			damage -= target->query_temp("apply/armor_vs_force");
			damage += damage1;
		}

		damage = damage * me->query_str(1) / 32;

		if(wizardp(me) && me->query("env/test"))
			tell_object(me,sprintf("damage:%d \n",damage));

		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/2 + random(damage/2), me);
		msg = "\n";
		msg += COMBAT_D->damage_msg(damage, random(2)?"����":"����");
		if (random(2) && target->query("qi") >=0 || target->query("eff_qi")+target->query_temp("apply/qi") < 0) {
			p = (target->query("eff_qi")+target->query_temp("apply/qi"))*100
				/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		}
		else {
			p = target->query("qi")*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg += "( $n"+COMBAT_D->status_msg(p)+" )\n";
		}
		me->add("neili", -450);
		me->delete_temp("kl/dzfail");
	}
	else {
		me->add("neili", -200);
		if (!userp(target))
			me->add_temp("kl/dzfail/"+target->query("id"), 1);
		msg = HIY"$n"HIY"���μ��ٺ��ˣ�˳���Ʒ����һ�����㿪���⹥����\n" NOR;
	}
	me->add("jingli", -100);
	me->start_perform(3, "�������ص���");
	me->add_busy(random(2));
	message_vision(msg, me, target);

	return 1;
}

string perform_name(){ return HIG"���ص���"NOR; }
int help(object me)
{
	write(HIG"\n�����Ʒ�֮�����ص��ơ���"NOR"\n\n");
	write(@HELP
	�����������ƣ��������ӹ������ˣ�����������ѧ����˸յ���ɫ��
	Ҫ��150�������޼�����120�������Ʒ���120��������Ʒ�
	      800������2000�������
	      ����30������

	ע����ͬ����£�����ͨ�� set ������ͬ��Ч��
		set ���ص��� ���Ƶ���
		set ���ص��� �����ص�

HELP
	);
	return 1;
}
