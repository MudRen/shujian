// pi.c �򹷰���--���־�
// Creat by looklove@SJ 3/21/2001
// Mofify by looklove 2001.4.8
// Update by lsxk@hsbbs 2007/7/2

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return HBRED"���־�"NOR; }
int perform(object me, object target)
{
	string msg;
	int mlvl, tlvl, damage, i, j, b, mexp, texp, p, ap, dp, m;
	object weapon, tweapon;

	weapon = me->query_temp("weapon");
	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target) )
		return notify_fail("�����־���ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon)
	 || weapon->query("skill_type") != "stick"
	 || me->query_skill_mapped("stick") != "dagou-bang"
	 || me->query_skill_mapped("parry") != "dagou-bang" )
		return notify_fail("�������ް����޷�ʹ�á����־�����\n");

	mexp=me->query("combat_exp");
	texp=target->query("combat_exp");

	mlvl=me->query_skill("dagou-bang",1);
	tlvl=target->query_skill("dodge", 1);

	i = me->query_int(1);
	j = target->query_int(1);
	b = me->query_skill("bangjue",1);

	tweapon = target->query_temp("weapon");

	if( (int)me->query_con(1) < 40 )
		return notify_fail("������̫��,�������ڲ���ʹ�á����־�����\n");

   if( (int)me->query_skill("huntian-qigong", 1) < 200 )
		return notify_fail("��Ļ���������Ϊ������ʹ���������־���������\n");

	if( me->query_skill_mapped("force") != "huntian-qigong" )
		return notify_fail("û�л���������Ϊ���������޷�ʹ�������־��������ģ�\n");

   if( (int)me->query_skill("dagou-bang",1) < 200 )
		return notify_fail("��Ĵ򹷰�����Ϊ����,Ŀǰ������ʹ�á����־�����\n");

   if( (int)me->query_skill("bangjue",1) < 180 )
		return notify_fail("�����־������Դ򹷰���Ϊ�����ģ�������������ʹ�ã�\n");

   if( (int)me->query("max_neili") < 2500 )
		return notify_fail("��������Ϊ���ڲ���, �����á����־�����\n");

	if( (int)me->query("neili") < 800 )
		return notify_fail("�������þ�, �����á����־�����\n");

	if( (int)me->query("jingli") < 600 )
		return notify_fail("������û���㹻�ľ���ʹ�á����־�����\n");


      	msg = HBRED"\n$Nʹ�������־���������������"+weapon->name()+HBRED"���籩����$n��ͷ�����ô�ȥ��\n"NOR;

	ap = mexp/10000 * (i + me->query_skill("stick"));
	dp = texp/10000 * (j + target->query_skill("dodge"));
	ap += COMBAT_D->skill_power(me, "stick", SKILL_USAGE_ATTACK);
	dp += COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

	if( dp < 1 ) dp = 1;

	if( random(ap + dp ) > dp){
		msg += HBRED"$nֻ�����ۻ����ң�һ�������񣬱�"+weapon->name()+HBRED"�������У�\n"NOR;
		damage = mlvl*2 + b*(2+random(i));

		if( me->query_skill("dagou-bang", 1) > 300 ) 
			m = 4000 + ( me->query_skill("dagou-bang", 1) - 300 ) * 10 + random(500);
		else m = 4000;

		if( damage > m )
			damage = m + random(damage-m)/5;
		if( damage > 8000 )
			damage = 8000 + random(damage-8000)/15;

		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/3, me);
		target->receive_damage("jingli",damage/10,me);
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"HIR+damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+damage+ WHT"���˺���\n"NOR); ;
		if( random(2) ) {
			p = (target->query("eff_qi")+target->query_temp("apply/qi"))*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg += COMBAT_D->damage_msg(damage, "����");
			msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		}
		else {
			p = target->query("qi")*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg += COMBAT_D->damage_msg(damage, "����");
			msg += "( $n"+COMBAT_D->status_msg(p)+" )\n";
		}
		me->add("neili", -400);
	}
	else if( random(mlvl) > tlvl/2 ) {
		msg += HBRED"$nֻ�о�������ת���Ĵ�����"+weapon->name()+HBRED"�����޿ɱܣ��������У�\n"NOR;
		damage = mlvl*3+b*(2+random(i));

		if( me->query_skill("dagou-bang", 1) > 300 ) 
			m = 3000 + ( me->query_skill("dagou-bang", 1) - 300 ) * 10 + random(500);
		else m = 3000;

		if( damage > m )
			damage = m + random(damage-m)/5;
		if( damage > 8000 )
			damage = 8000 + random(damage-8000)/15;

		target->receive_damage("qi",damage, me);
		target->receive_wound("qi", random(damage),me);
		target->receive_damage("jingli",damage/10, me);
		if (random(2)) {
			p = (target->query("eff_qi")+target->query_temp("apply/qi"))*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg += COMBAT_D->damage_msg(damage, "����");
			msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		}
		else {
			p = target->query("qi")*100/(target->query("max_qi")+target->query_temp("apply/qi"));
			msg += COMBAT_D->damage_msg(damage, "����");
			msg += "( $n"+COMBAT_D->status_msg(p)+" )\n";
		}
		me->add("neili", -300);
	}
       	else {
          	msg+=HIC"$n��ʧɫ��������һ���͵�ʮ�˹��������ܹ�$N��"+weapon->name()+HIC"��\n"NOR;
          	me->add("neili", -200);
	}
	me->start_busy(random(2));
	me->add("jingli", -150);
	me->start_perform(3, "�����־���");
	message_vision(msg, me, target);
	return 1;
}

int help(object me)
{
	write(HBRED"\n�򹷰������־�����"NOR"\n");
	write(@HELP
	�򹷰��а���ʮ�������������Ī�������г��֣������Լ�
	Ҳ�޷�������������ɱһ�����������ҡ�

	Ҫ��	������Ǵ���40��
           ������� 2500 ���ϣ�
		��ǰ���� 800 ���ϣ�
		��ǰ���� 600 ���ϣ�
           �򹷰��ȼ� 200 ���ϣ�
           ���������ȼ� 200 ���ϣ�
           �򹷰����ȼ� 180 ���ϣ�
		�����м�Ϊ�򹷰���
HELP
	);
	return 1;
}
