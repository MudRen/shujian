// shuangjue.c It's a "pfm" .
// by Looklove@SJ 2001/2/14 ...���˽�
// Modify by looklove 2001.4.4
// Mofify by looklove 2001.4.8
// Modify by looklove 2001.5.2

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return HIM"����˫��"NOR; }
int perform(object me, object target)
{
	int b, j, h;
	object weapon;
	b = me->query_skill("dagou-bang", 1);
	b += me->query_skill("xianglong-zhang", 1);
	weapon = me->query_temp("weapon");

	if (!target ) target = offensive_target(me);

	if (!objectp(target) || !me->is_fighting(target) || !necessary(target) )
		return notify_fail("������˫����ֻ����ս���жԶ���ʹ�á�\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	|| weapon->query("skill_type") != "stick")
		return notify_fail("������û�а����޷�ʹ�ð���˫����\n");

	if( (int)me->query_int(1) < 30)
		return notify_fail("�����Բ��㣬�޷�ʹ�ð���˫����\n");

	if( (int)me->query_skill("dagou-bang", 1) < 300 )
		return notify_fail("��Ĵ򹷰�����������죬ʹ����������˫����������\n");

	if( (int)me->query_skill("xianglong-zhang", 1) < 300 )
		return notify_fail("��Ľ���ʮ���ƻ�δ���ɣ�����ʹ�ð���˫����\n");

	if( me->query_skill_mapped("force") != "huntian-qigong"
	|| (int)me->query_skill("huntian-qigong", 1) < 300 )
		return notify_fail("��Ļ���������û��ѧ�ɣ��޷�ʹ�ð���˫����\n");

	if( me->query_skill_mapped("parry") != "dagou-bang")
		return notify_fail("����мܹ����Ǵ򹷰����޷�ʹ�ð���˫����\n");

	if( me->query_skill_mapped("strike") != "xianglong-zhang"
	|| me->query_skill_prepared("strike") != "xianglong-zhang")
		return notify_fail("��û���ý���ʮ���ƣ��޷�ʹ�ð���˫����\n");

	if( (int)me->query("max_neili") < 5000 )
		return notify_fail("�����������̫����ʹ����������˫������\n");

	if( (int)me->query("neili") < 2500 )
		return notify_fail("����������̫����ʹ����������˫������\n");

	if((int)me->query("jingli") < 1200 )
		return notify_fail("��ľ�������������ʹ���˾�����\n");
		
		
  h = me->query("death_times",1) /150;
  
  if(h>2) h=2;
 
	j = b/2;
	
	
	

	message_vision(HIM"\n$N���һ��������˫����������"+weapon->name()+HIW+"��$n������ֻ�����в��ƣ��Ʋ��ɵ����������ҡ�\n"NOR, me, target);


	me->set_temp("shuangjue/dgb", 3);
	me->set_temp("shuangjue/xlz", 2);
	
	
	me->add_temp("apply/damage", j/3);	
	me->add_temp("apply/attack", j/4);
	me->add_temp("apply/stick",  j/5);
	me->add_temp("apply/strike", j/5);
	me->add_temp("apply/strength", j/10);

if(h>0) target->add_busy(h);	
	
	
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);


	weapon->unequip();

	if( me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);


	weapon->wield();
	if( me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	weapon->unequip();
	if( me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);


	weapon->wield();
	if( me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);

	me->add_temp("apply/damage", -j/3);	
	me->add_temp("apply/attack", -j/4);
	me->add_temp("apply/stick",  -j/5);
	me->add_temp("apply/strike", -j/5);
	me->add_temp("apply/strength", -j/10);
	

	me->add("neili", -500 );
	me->add("jingli", -200);
	me->delete_temp("shuangjue");
        me->start_perform(3+ random(2),"������˫����");
	me->start_busy(random(2));
	return 1;
}

int help(object me)
{
	write(WHT"\n������˫������"NOR"\n");
	write(@HELP
	���򹷰��뽵��ʮ���ƾ�����һ�����в��ƣ��Ʋ��ɵ����������ҡ�

	Ҫ��	��������30���ϣ�
		������� 5000 ���ϣ�
		��ǰ���� 2500 ���ϣ�
		�򹷰��ȼ� 300 ���ϣ�
		���������ȼ� 300 ���ϣ�
		����ʮ���Ƶȼ� 300 ���ϣ�
		�����м�Ϊ�򹷰���
		�����书Ϊ����ʮ���ơ�
HELP
	);
	return 1;
}
