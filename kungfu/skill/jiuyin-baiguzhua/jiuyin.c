// jiuyin ��������צ
// By Spiderii �ʵ����
#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;

int perform(object me, object target)
{
	int skill, i;
	skill = (int)me->query_skill("jiuyin-baiguzhua", 1);

	if( !target ) target = offensive_target(me);

        if( !objectp(target) || !me->is_fighting(target) || !necessary(target) )
		return notify_fail("����������צ��ֻ����ս����ʹ�á�\n");

	if( me->query_temp("weapon"))
		return notify_fail("������������ô��ʹ�á���������צ����\n");   

	if( skill < 150 || me->query_skill("claw", 1) < 150)
		return notify_fail("��ľ����׹�צ��������죬ʹ��������������צ��������\n");

	if ( me->query_skill_mapped("claw") != "jiuyin-baiguzhua"
	|| me->query_skill_prepared("claw") != "jiuyin-baiguzhua")
		return notify_fail("�������޷�ʹ�á���������צ����\n");

	if( (int)me->query("max_neili") < 1500  )
		return notify_fail("����������̫����ʹ��������������צ����\n");      

	if( (int)me->query("neili") < 1100 )
		return notify_fail("����������̫����ʹ��������������צ����\n");

    if( me->query("shen") > -1000000 && me->query("PKS") < 10 )
                if( me->query("GKS") < me->query("BKS") && !me->query("no_pk") )
			return notify_fail("�㲻���ݶ����޷�ʹ������������צ���ľ�����\n");

	message_vision(RED"\n$NͻȻ�ֽ�һ����ȫ������籬������ž���죬�ֱ�ͻȻ�������ߣ�\n"NOR,me);

     i = skill/3;
		
	if ( skill > 250 )
		i = to_int(skill/3.0 * skill/250.0);			
	
	if(wizardp(me)) tell_object(me,sprintf("Jiuyin Debug:i=%d \n",i));					
	me->add_temp("apply/attack", i);
	me->add_temp("apply/damage", i);
       me->add_temp("apply/dodge", i);
       me->add_temp("apply/parry", i);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);

        if(me->is_fighting(target)) 
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(3)?1:3);

        if(me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);

	me->add_temp("apply/dodge", - i);
	me->add_temp("apply/parry", - i);
	me->add_temp("apply/attack", -i);
       me->add_temp("apply/damage", -i);
	me->start_perform(3, "��������צ");
	me->add("neili", -400);
	me->add("jingli", -150);
	me->start_busy(random(2));
	return 1;
}

string perform_name(){ return RED"��������צ"NOR; }

int help(object me)
{
        write(RED"\n�����׹�צ֮����������צ����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1100 ���ϣ�
                ������� 1500 ���ϣ�
                ��ǰ���� 1000 ���ϣ�
                �����׹�צ�ȼ� 150 ���ϣ�
                ����ץ���ȼ� 150 ���ϣ�
                ���� 1000000 ������ɱ�������� 10��
                ����ץ��Ϊ�����׹�צ��                
                ��ץ��Ϊ�����׹�צ��
                �����ޱ�����

HELP
        );
        return 1;
}
