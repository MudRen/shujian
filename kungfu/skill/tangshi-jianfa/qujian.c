//qujian.c
//by spiderii@ty����SJ��д

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon, weapon2;
	int j, lvl = me->query_skill("tangshi-jianfa", 1);

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target)
	 || !living(target) )
		return notify_fail("��ȥ��ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	
    if( (int)me->query_skill("tangshi-jianfa", 1) < 150 ) 
                return notify_fail("�����ʬ������δ���ɣ��޷�ʹ�á�ȥ�硹�־���\n");

    if((int)me->query_skill("sword", 1) < 150 )
                return notify_fail("��Ļ�������������죬����ʹ�á�ȥ�硹�־���\n");

    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "tangshi-jianfa")
                return notify_fail("�����ʹ�ý���������ʹ����ȥ�硹�־�!\n");

    if(!objectp(weapon2 = target->query_temp("weapon")))
                return notify_fail("�Է����ڲ�û��ʹ������!\n");

   if(me->query_skill_mapped("parry") != "tangshi-jianfa")
           return notify_fail("��ȥ�硹�־���Ҫʹ����ʬ�����м�һ�ез�������\n"); 

   if((int)me->query("max_neili") < 2500 )
           return notify_fail("��������Ϊ��ǳ��ʹ������ȥ�硹�־���\n");  

   if( (int)me->query("neili") < 500 )
           return notify_fail("����������̫����ʹ������ȥ�硹�־���\n");


	j = lvl/3;
	me->set_temp("tangshi/qujian",1);

	me->add_temp("apply/sword", j);
       me->add_temp("apply/attack", j);
       me->add_temp("apply/damage", j/2);
	
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);

	me->add_temp("apply/sword", -j);
       me->add_temp("apply/attack", -j);
	me->add_temp("apply/damage", -j/2);

	me->delete_temp("tangshi/qujian");

	me->start_busy(random(2));
	me->add("neili", -300);
	me->add("jingli", -100);
	me->start_perform(4, "��ȥ��ʽ��");
	return 1;
}

string perform_name(){ return HIW"ȥ��ʽ"NOR; }

int help(object me)
{
        write(HIW"\n��ʬ����֮��ȥ��ʽ����"NOR"\n\n");
        write(@HELP
       ��ʬ�������侫���һ�С�

��������Ҫ�󣺡���ǰ���� 2500 ���ϣ�
������������    ������� 500 ���ϣ�
������������������ʬ�����ȼ� 150 ���ϣ�
�������������������������ȼ� 150 ���ϣ�
���������������������м�Ϊ��ʬ������

HELP
        );
        return 1;
}
