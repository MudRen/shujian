#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg,dodge_skill;
	int p, ap, dp;
       
	if( !target ) target = offensive_target(me);

	if(!objectp(weapon = me->query_temp("weapon"))
	 ||(string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( !objectp(target) || !me->is_fighting(target) )
		return notify_fail("����������С�ֻ����ս���жԶ���ʹ�á�\n");

	if((int)me->query_skill("linji-zhuang", 1) < 150 )
		return notify_fail("����ټ�ʮ��ׯ�ȼ�����������ʹ�÷�������С�\n");       

	if(me->query_skill_prepared("strike") != "sixiang-zhang"
	 || me->query_skill_mapped("strike") != "sixiang-zhang")
		return notify_fail("�㲻�������ƣ������޷�ʹ�÷�������С�\n");

	if (me->query_skill_mapped("force") != "linji-zhuang")
		return notify_fail("����ʹ�õ��ڹ����ԡ�\n");

	if ((int)me->query_skill("yanxing-daofa", 1) < 150 )
		return notify_fail("������е����ȼ�����������ʹ�÷�������У�\n");    

	if( me->query_skill_mapped("blade") != "yanxing-daofa"
	 || me->query_skill_mapped("parry") != "yanxing-daofa")
		return notify_fail("�����ڲ���ʹ�÷�������У�\n"); 

	if ((int)me->query_skill("blade", 1) < 150 )
		return notify_fail("��Ļ�������������죬����ʹ�÷�������У�\n");    

	if ((int)me->query_skill("sixiang-zhang", 1) < 150 )
		return notify_fail("��������Ʋ�����죬����ʹ�÷�������У�\n");    

	if ((int)me->query_skill("strike", 1) < 150 )
		return notify_fail("��������Ʋ�����죬����ʹ�÷�������У�\n");    

	if ((int)me->query("neili") < 1200 )
		return notify_fail("����������̫��������ʹ�÷�������У�\n");

	if ((int)me->query("jingli") < 800 )
		return notify_fail("�����ھ�������������ʹ�÷�������У�\n");

	if ((int)me->query("max_neili") < 2000 )
		return notify_fail("����������̫��������ʹ�÷�������У�\n");

	message_vision(HIY"$NͻȻ������"+weapon->query("name")+HIY"����һ�ӣ�\n"NOR, me, target);
	message_vision(HIR"$N��$nһ��������ʹ��һ�������Ƶľ�ѧ��Ʈѩ�����ơ���\n"NOR, me, target);
	me->add_temp("apply/dexerity", me->query_skill("dodge")/20);
	
	ap = me->query("combat_exp")/1000 * me->query_skill("dodge");
	dp = target->query("combat_exp")/1000* target->query_skill("dodge");

	if (random( ap + dp) > dp ){
		target->receive_damage("qi", me->query_skill("sixiang-zhang", 1) * 3, me);
		target->receive_wound("qi", me->query_skill("sixiang-zhang", 1) * 3, me);
		message_vision(HIY"$nһ�������$N���صĻ��У�\n"NOR, me, target); 
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+ me->query_skill("sixiang-zhang", 1) * 3+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+me->query_skill("sixiang-zhang", 1) * 3+ WHT"���˺���\n"NOR); ;
		p = (int)target->query("eff_qi")*100/(int)target->query("max_qi");
		msg = "( $n"+COMBAT_D->eff_status_msg(p)+" )\n"; 
		message( msg, me, target);
	}
	else{
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg = SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		message( msg, me, target);
	}
	message_vision(HIR"\n$N���˿����������ĵ���������������\n"NOR, me, target);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);
	me->add_temp("apply/dexerity",-me->query_skill("dodge")/20);
	me->start_busy(random(2));
	me->add("neili", -300);
	me->add("jinli", -100);
	me->start_perform(2+random(2), "����������С�");       
	return 1;
}

string perform_name(){ return HIY"���������"NOR; }

int help(object me)
{
        write(HIY"\n���е���֮����������С���"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1200 ���ϣ�
                ������� 2000 ���ϣ�
                ��ǰ���� 800 ���ϣ�
                ���е����ȼ� 150 ���ϣ�
                �����Ƶȼ� 150 ���ϣ�
                �ټ�ʮ��ׯ�ȼ� 150 ���ϣ�
                ���������ȼ� 150 ���ϣ�
                �����Ʒ��ȼ� 150 ���ϣ�
                ��������Ϊ���е�����
                �����м�Ϊ���е�����
                �����Ʒ�Ϊ�����ƣ�
                ���Ʒ�Ϊ�����ƣ�
                �����ڹ�Ϊ�ټ�ʮ��ׯ��
                ���ֱֳ�����

HELP
        );
        return 1;
}
