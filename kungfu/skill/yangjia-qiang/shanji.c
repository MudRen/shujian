// pi.c ��ǹ��--����
//Created by Redhat@Sjmud 2009/4/7

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return RED"����"NOR; }
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
        if( (int)me->query_skill("yangjia-qiang",1) < 50)
        return notify_fail("��Ŀǰ������ʹ��������������\n");
    	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "spear")
			return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("neili") < 500 )
    return notify_fail("�������������\n");
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("yangjia-qiang",1) *2 ;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = RED  "$N���е�"+ weapon->name() +"�ó�һ��ǹӰ��"+weapon->name() +"���Ƴ��գ���$n���ȥ��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
 me->start_perform(3+random(2), "��������");

	me->start_busy(2);
	return 1;
}

int help(object me)
{
   write(YEL"\n���ǹ��"HIG"����"YEL"����"NOR"\n");
   write(@HELP
   ָ�perform shanji

   Ҫ�����ǹ50����
         ����ǹ��50����
         ��ǰ���� 500 ���ϣ�
         ��ǰ���� 100 ���ϣ�
HELP
   );
   return 1;
}
