#include <ansi.h>
inherit F_SSERVER;

int perform1(object me, object target, object weapon, int ap, int dp, int skill, int i);
int perform2(object me, object target, object weapon, int ap, int dp, int skill, int i);

int perform(object me, object target)
{
	string msg, dodge_skill;
	object weapon = me->query_temp("weapon");
	int ap, dp, damage, p, skill, i = 0;

	if( !target ) target = offensive_target(me);

	if( !objectp(target) || !me->is_fighting(target) )
		return notify_fail("�������־�ֻ����ս���жԶ���ʹ�á�\n");

	if( !living(target) )
		return notify_fail("�������־�ֻ����ս���жԶ���ʹ�á�\n");

	if( !weapon || weapon->query("skill_type") != "sword" )
		return notify_fail("�������޽������ʹ�á������־���\n");

	if( me->query_skill_mapped("sword") != "taiji-jian" )
		return notify_fail("����������̫���������޷�ʹ�á������־���\n");

	if( me->query_skill_mapped("parry") != "taiji-jian" )
		return notify_fail("�������̫������Ϊ�мܲ���ʹ�á������־���\n");  

	if( me->query_temp("tjj/chan") )
		return notify_fail("������ʹ�á������־���\n");

	if( (int)me->query_temp("tjj/lian") )
		return notify_fail("����������ʹ�á������־���\n");

	if( (int)me->query_skill("taiji-jian", 1) <120 )
		return notify_fail("���̫��������Ϊ�в�����,�޷�ʹ�á������־���\n");             

	if( (int)me->query_skill("yinyun-ziqi",1) < 120 )
		return notify_fail("�����������Ϊ��ǳ������ʹ�á������־���\n");

	if( (int)me->query_skill("sword",1) < 120 )
		return notify_fail("�����������Ϊ�в�����,����ʹ�á������־���\n");  

	if( (int)me->query("max_neili") < 1500 )
		return notify_fail("���������Ϊ̫��������ʹ�á������־���\n");

	if( (int)me->query("neili") < 800 )
		return notify_fail("�������̫���ˣ�����ʹ�á������־���\n");  

	message_vision(CYN"\n$N΢΢һЦ��ʹ��̫������"+RED+"������"+CYN+"�־����������ӻ�����ת,���ֳֽ��������𣬽��������ǰ��\n"
			"����������ԣ��籧Բ������"+weapon->name()+CYN"δ������Ȼ�������\n"NOR,me,target);

	me->set_temp("tjj/lian",1);

	ap = me->query("combat_exp", 1) / 1000 * me->query_int(1);
	dp = target->query("combat_exp", 1) / 1000 * target->query_int(1);

	skill = me->query_skill("taiji-jian", 1);
	
  if(skill>=450) ap += ap/2 + random(ap);
  if(skill>=551) ap += random(ap);

	msg = CYN"\n$N����"+weapon->name()+CYN"������ǰ��������һ���Σ�һ��ɭɭ������ֱ����$n��ͻȻ֮�䣬$N�������֣�����һ������$n��ȥ��\n"NOR;

	if ( random( ap + dp) > dp/2 ) {
		damage = me->query_skill("sword") * 3;
		damage = to_int( damage * skill/100.0);
		damage += random(damage);
		
		
            if( damage > target->query("qi") ) 
  { damage= target->query("qi")-1;
    target->start_busy(5);
   }


	
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/3, me);
		
		me->add("neili", -200);
		me->add("jingli", -150);
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
		msg = replace_string( msg, "$w", weapon->name());
		msg = replace_string( msg, "$l", target->query("limbs")[random(sizeof(target->query("limbs")))]);
		i = 1;
	}
	else {
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		me->add("neili", -100);
		me->add("jingli", -50);
	}
	message_vision( msg, me, target);
	me->start_perform(2, "�������־�");
	me->start_busy(random(2));
	me->delete_temp("tjj/lian");
	if ( skill > 150 ) {
		me->set_temp("tjj/lian", 1);
		perform1(me, target, weapon, ap, dp, skill, i);
	}
	return 1;
}

int perform1(object me, object target, object weapon, int ap, int dp, int skill,int i)
{
	string msg, dodge_skill;
	int damage, p;

	if ( !me) return 1;
	if( !weapon || !objectp(target)) {
		me->delete_temp("tjj/lian");
		return 1;
	}

	msg =CYN"\n$N�ֽ��������֣�����ǰ��������ԲȦ���������໤סȫ�����ް�ֿ�϶���������Ž�����\n"+
		"����"+weapon->name()+CYN"��ס�Ķ���������$n�����ߴ�ҪѨ�����⼱��������������δ���\n"NOR;     

	if ( random( ap + dp) > dp/2 ) {
		damage = me->query_skill("sword") * 3;
		damage = to_int( damage * skill/150.0);
		damage += random(damage);
	
		if ( i ) damage -= random(damage/2);


                 if( damage > target->query("qi") ) 
  { damage= target->query("qi")-1;
    target->start_busy(5);
   }


		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/3+random(damage/3), me);
		me->add("neili", -250);
		me->add("jingli", -150);
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
		msg = replace_string( msg, "$w", weapon->name());
		msg = replace_string( msg, "$l", target->query("limbs")[random(sizeof(target->query("limbs")))]);
	}
	else {
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		i = 0;
		me->add("neili", -100);
		me->add("jingli", -50);
	}
	message_vision( msg, me, target);
	me->start_perform(3, "�������־�");
	me->delete_temp("tjj/lian");
	if ( skill > 200 ) {
		me->set_temp("tjj/lian", 1);
		perform2(me, target, weapon, ap, dp, skill, i);
	}
	return 1;
}

int perform2(object me, object target,object weapon, int ap, int dp, int skill, int i)
{
	string msg, dodge_skill;
	int damage, p;

	if ( !me) return 1;
	if( !weapon || !objectp(target)) {
		me->delete_temp("tjj/lian");
		return 1;
	}

	msg = CYN"\n$N�������õ�"+RED+"��Ȧ"+CYN+"Խ��Խ�࣬������ʱ��ȫ������������"+RED+"��Ȧ"+CYN+"֮�У�"+RED+"��Ȧ"+CYN+"��Ȧһ��δ������һ��������\n"
		"����"+weapon->name()+CYN"��ʹ�ü��죬ȴ˿����������������֮�����������֮�����Ѵ��ڻ�����\n"
		CYN"$n���ӽ�����������"+RED+"��Ȧ"+CYN+"�����Լ������޿��˱ܣ�ֻ��ð��һ���������ֱ�һ�죬��"+RED+"��Ȧ"+CYN+"�����Ļ���ֱ�롣\n"NOR;

	if ( random( ap + dp) > dp/2 ) {
		damage = me->query_skill("sword") * 4;
		damage = to_int( damage * skill/200.0);
		damage = damage*2 + random(damage);
	


                 if( damage > target->query("qi") ) 
  { damage= target->query("qi")-1;
    target->start_busy(5);
   }



		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/2+random(damage/2), me);
		me->add("neili", -300);
		me->add("jingli", -150);
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
		msg = replace_string( msg, "$w", weapon->name());
		msg = replace_string( msg, "$l", "�ֱ�");
		me->start_perform(3+random(2), "�������־�");
	}
	else {
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		me->add("neili", -100);
		me->add("jingli", -50);
		me->start_perform(3, "�������־�");
	}

	msg += HIY"\n$N�������־�������ϣ��������֣��ս�������������ȫ�����µĴ�С��Ȧ�漴������Ӱ��\n\n"NOR;
	me->delete_temp("tjj/lian");
	message_vision( msg, me, target);
	return 1;
}

string perform_name(){ return CYN"������"NOR; }

int help(object me)
{
        write(CYN"\n̫������֮������������"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 800 ����;
                ������� 1500 ���ϣ�
                ̫�������ȼ� 120 ���ϣ�
                �������ȼ� 120 ���ϣ�
                ���������ȼ� 120 ���ϣ�
                ��������Ϊ̫��������
                �����м�Ϊ̫��������
                �����ڹ�Ϊ��������

HELP
        );
        return 1;
}
