// feizhang.c  ��������

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return CYN"��������"NOR; }

int perform(object me, object target)
{
	object weapon;
	int ap, dp, damage, p;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( !objectp(weapon = me->query_temp("weapon"))
	 || (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( me->query_skill("fengmo-zhang", 1) < 100 )
		return notify_fail("��ķ�ħ�ȷ�������죬����ʹ�á��������ȡ���\n");

	if( me->query_skill_mapped("parry") != "fengmo-zhang"
	 || me->query_skill_mapped("staff") != "fengmo-zhang")
		return notify_fail("�����ڲ���ʹ�÷����˵С�\n");

	if( me->query_skill("huntian-qigong", 1) < 80 )
		return notify_fail("��Ļ������������ߣ�����ʹ�÷����˵С�\n");

	if( me->query("max_neili", 1) < 800 )
		return notify_fail("���������Ϊ����������ʹ�á��������ȡ���\n");

	if( me->query("neili",1) < 500 )
		return notify_fail("��������������޷�ʹ�÷��ȡ�\n");

	msg = CYN"\n$Nһ����Х������һ����,������"+weapon->query("name")+CYN"�������$n��\n"NOR;

	ap = COMBAT_D->skill_power(me, "staff", SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
	ap += me->query("combat_exp", 1) / 1000 * me->query_str(1);
	dp += target->query("combat_exp", 1) /1000 * target->query_con(1);

	if ( random(ap + dp ) > dp ) {
		damage = me->query_skill("staff") * 4;
		damage += me->query_skill("force") * 2;
		damage = damage/2 + random(damage);
		if (damage > 3500) damage = 3500 + random(damage-3500)/10;
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/3, me);
		me->add("neili", -250);
		me->add("jingli", -80);
		msg += HIR"ֻ��$N����"+ weapon->name()+HIR"�����ɳ���ٿ������$n��\n"+
			"$nֻ��һ�ɴ�������ǵذ�ѹ������ʱ��ǰһ���������������۵����һ����Ѫ��\n"NOR;
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+ damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+damage+ WHT"���˺���\n"NOR); ;
		if( random(2) ) {
			p = (target->query("eff_qi")+target->query_temp("apply/qi"))*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		}
		else {
			p = target->query("qi")*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg += "( $n"+COMBAT_D->status_msg(p)+" )\n";
		}
		msg +=	HIW"\nֻ��"+weapon->name()+HIW"ײ��$n�󣬷��������ֻص���$N���С�\n"NOR;
	}
	else{
		msg += CYN"����$p���²���͵���ǰһԾ��������$P�Ĺ�����Χ��$P����ǰ��ס���е�"+weapon->query("name")+CYN"��\n"NOR;
		me->add("neili", -100);
	}
	me->start_busy(random(2));
	me->start_perform(3, "����");
	message_vision(msg, me, target);
	return 1;
}

int help(object me)
{
	write(CYN"\n��ħ��֮���������ȡ���"NOR"\n");
        write(@HELP
	Ҫ��  �������  800 ���ϣ�
                ��ǰ����  500 ���ϣ�
                ��ħ�ȵȼ� 100 ���ϣ�
                ���������ȼ� 80 ���ϣ�
HELP
        );
        return 1;
}
