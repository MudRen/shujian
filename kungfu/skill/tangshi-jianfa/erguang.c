//erguang.c ����ʽ
// By Spiderii

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int j, lvl = me->query_skill("tangshi-jianfa", 1);

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target)
	 || !living(target) )
		return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	
   if( (int)me->query_skill("tangshi-jianfa", 1) < 80 )
		return notify_fail("�����ʬ��������̫ǳ���������ˡ�\n");

   if( (int)me->query_skill("sword", 1) < 80 )
		return notify_fail("��Ļ�����������̫ǳ���������ˡ�\n");


   if( (int)me->query("max_neili") < 500 )
		return notify_fail("�������̫ǳ���������ˡ�\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("��������������������ˡ�\n");

	
	if( !objectp(weapon = me->query_temp("weapon"))
	 || weapon->query("skill_type") != "sword"
	 || me->query_skill_mapped("sword") != "tangshi-jianfa" )
		return notify_fail("��ʹ���ˡ�����ʽ��ô?\n");

	j = lvl/3;

	if ( lvl > 275 )
		j = to_int(lvl/3.0 * lvl/275.0);

	me->set_temp("tangshi/erguang",1);

	me->add_temp("apply/sword", j);
       me->add_temp("apply/attack", j);
       me->add_temp("apply/damage", j/2);
	
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);

	me->add_temp("apply/sword", -j);
       me->add_temp("apply/attack", -j);
	me->add_temp("apply/damage", -j/2);

	me->delete_temp("tangshi/erguang");

	me->start_busy(random(2));
	me->add("neili", -300);
	me->add("jingli", -100);
	me->start_perform(4, "������ʽ��");
	return 1;
}

string perform_name(){ return HIW"����ʽ"NOR; }

int help(object me)
{
        write(HIW"\n��ʬ����֮������ʽ����"NOR"\n\n");
        write(@HELP
       ��ʬ�������侫���һ�С�
��������
��������Ҫ�󣺡���ǰ���� 100 ���ϣ�
������������������� 500 ���ϣ�
������������������ʬ�����ȼ� 80 ���ϣ�
�������������������������ȼ� 80 ���ϣ�
���������������������м�Ϊ��ʬ������

HELP
        );
        return 1;
}
