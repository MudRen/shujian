// ���� by lane 2004.12.13 
#include <ansi.h>
#include <combat.h> 

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,skill,at,df,i,lmt,damage,p;
	object weapon;
	extra = me->query_skill("cihang-bian", 1);

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target) )
		return notify_fail("���ȱ��־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( extra < 160 )
		return notify_fail("��Ĵ��б޷���Ϊ̫��,������ʹ�á��ȱ��־�����\n");

	skill = me->query_skill("buddhism", 1); 

	if( skill < 180 )
		return notify_fail("��������ķ��ȼ�����������֧�֡��ȱ��־����� \n");

	if( userp(me) && me->query("class") != "bonze" )
		return notify_fail("���ȱ��־���ֻ�г����˲���ʹ�á�\n");

	if( me->query_temp("chb") )
		return notify_fail("��������⣬�����޷�ʹ�á��ȱ��־�����\n");

	if( me->query("shen") < 100000 )
		return notify_fail("���ȱ��־��������ޱ�����Ϊ������ʦ���Ƕ������°�! \n");

	if( me->query_skill("kurong-changong", 1) < 160 )
		return notify_fail("��Ŀ���������Ϊ̫�������ʹ�á��ȱ��־�����\n");

	if( me->query("max_neili") < 2000 )
		return notify_fail("���������Ϊ���������ȱ��־���\n");

	if( me->query("neili") < 2000 )
		return notify_fail("�������������㣬���������ȱ��־���\n");

	if( me->query("jingli") < 1200 )
		return notify_fail("��ľ�����Ϊ���������ȱ��־���\n");

	weapon = me->query_temp("weapon"); 

	if( me->query_skill_mapped("whip") != "cihang-bian" && userp(me) )
		return notify_fail("�������޷�ʹ�á��ȱ��־�����\n");

	if( me->query_skill_mapped("parry") != "cihang-bian" && userp(me) )
		return notify_fail("�������޷�ʹ�á��ȱ��־�����\n");

	if( !weapon || weapon->query("skill_type") != "whip" )
		return notify_fail("������û�б������ʹ�á��ȱ��־�����\n");

        msg=HIC"$N���и�����ţ�ʹ���Ⱥ����С��ȱ������������г����������裬\n";
        msg+="���������Ҳ������϶�������$n,����$N����һ��������������ħ\n";
        msg+="�ƣ��������ϣ�����$n�˵���\n"NOR;


	message_vision(msg, me, target);

	at = me->query("combat_exp",1)/1000 * me->query_skill("cihang-bian", 1);
	df = target->query("combat_exp", 1)/1000 * target->query_skill("dodge", 1);

	me->set_temp("chb", 3);

//	����������ʧ���� buddhism �ҹ� 
	me->add("neili", -(800-skill) );
	me->add("jingli", -150);
	lmt = extra/4;
	if( extra > 250 )
		lmt = to_int( extra / 4.0 * extra / 250.0); 

	me->add_temp("apply/attack", lmt);
	me->add_temp("apply/whip", lmt);
	me->add_temp("apply/damage", lmt);
	me->add_temp("apply/dodge", lmt);


	for(i=1;i <= 3; i++)
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"), random(2)?1:3);

	me->add_temp("apply/attack",-lmt);
	me->add_temp("apply/whip",-lmt);
	me->add_temp("apply/damage", -lmt);
	me->add_temp("apply/dodge", -lmt);

	me->delete_temp("chb");
	me->start_perform(4,"���ȱ��־���");

	if( me->query_skill("cihang-bian", 1) >= 200 ) {
		if( random(at + df) > df ) {
			damage = me->query("shen")/1000;

//			�����жϣ��𷨶���������˺�����
			if( target->query("shen") > 0 )
				damage = damage + skill - target->query("shen")/5000;
			if( damage < 100 ) damage = 50 + random(50);

			if( damage > 2000 ) damage = 2000;
			msg = CYN"\n$n������$N���ޱ߷𷨴򶯣��͵ĺ��ˣ�����û��һ˿Ѫɫ...\n"NOR;
			target->add("neili", -damage/2 );
			target->receive_damage("qi", damage, me);
			target->receive_wound("qi", damage/3, me); 
			p = (int)target->query("qi")*100/(int)target->query("max_qi");
			msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n"; 
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+ damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+ damage+ WHT"���˺���\n"NOR); ;
			weapon = me->query_temp("weapon");        
			message_vision(msg, me, target);
			me->add("neili", -300);
			me->add("jingli", -100);

//			���ǵ��� job 1 pfm �������ĳ� 1k ���
			me->add("shen", -1000);
			me->start_perform(4,"���ȱ��־���");
		}
		else {
			me->add("neili",-200);
			me->add("jingli",-50);
		}
	}
	me->start_busy(random(2));
	return 1;
}

string perform_name(){ return HIY"�ȱ��־�"NOR; } 

int help(object me)
{
	write(HIY"\n�Ⱥ���֮���ȱ��־�����"NOR"\n\n");
	write(@HELP
   Ҫ��  ��ǰ���� 1500 ���ϣ�
           ��ǰ���� 1200 ���ϣ�
           �Ⱥ��޵ȼ� 160 ���ϣ�
           ���������ȼ� 160 ���ϣ�
           �����ķ��ȼ� 180 ���ϣ�
           ���� 500000 ���ϣ�
           �����޷�Ϊ�Ⱥ��ޣ�
           �����м�Ϊ�Ⱥ��ޣ�
           ����������ֱֳ�����

HELP
        );
	return 1;
}
