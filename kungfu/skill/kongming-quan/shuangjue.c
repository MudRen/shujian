// ����˫��


#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
   int lvl;
   lvl = (int)me->query_skill("kongming-quan", 1);
if (me->query("max_pot") >= 400 ) lvl = lvl /4;
  if( !target ) target = offensive_target(me);
  if( !objectp(target)
	 || !me->is_fighting(target)
	 || !living(target)
	 || environment(target)!=environment(me))
		return notify_fail("������˫����ֻ����ս���жԶ���ʹ�á�\n");

  if( objectp(me->query_temp("weapon")))
		return notify_fail("�������ֲ���ʹ�á�����˫������\n");

   if( (int)me->query_skill("kongming-quan", 1) < 200 )
		return notify_fail("��Ŀ���ȭ��������죬ʹ����������˫����������\n");

   if(!me->query_skill("force", 1) || (int)me->query_skill("cuff",1)<200)
   if( (int)me->query_skill("parry", 1) < 200 )
           return notify_fail("��Ļ������ܵȼ���������ʹ����������˫����������\n");

   if( (int)me->query_skill("dodge",1) < 200 )
		return notify_fail("����Ṧ�ȼ�����������ʹ�á�����˫������\n");
		
  if( (int)me->query_skill("xiantian-gong",1) < 200 )
		return notify_fail("������칦�ȼ�����������ʹ�á�����˫������\n");
/*
	if( !me->query("quest/jiebai/pass") )
		return notify_fail("�㲢δ����ܲ�ͨ���ڣ�����ʹ�á�����˫������\n");
*/
   if( me->query_skill_prepared("cuff") != "kongming-quan"
	 || me->query_skill_mapped("cuff") != "kongming-quan")
		return notify_fail("�������޷�ʹ�á�����˫������\n");

   if( me->query_skill_mapped("parry") != "kongming-quan")
		return notify_fail("����Ҫ�����м�Ϊ����ȭ������ʹ�á�����˫������\n");
if(userp(me)) 
            return notify_fail("��ʹ����������С�\n");

   if( (int)me->query("max_neili") < 3000)
		return notify_fail("�������̫����ʹ����������˫������\n");

   if( (int)me->query("neili") < 1500 )
		return notify_fail("����������̫����ʹ����������˫������\n");

   if( (int)me->query("jingli") < 1500 )
           return notify_fail("������̫���ˣ�ʹ����������˫������\n");


message_vision(HIB"\n$N����������Ĭ��ھ������������ɡ���ͨ���Ρ�������Ū��ͯӹ���档��ʹ������ȭ������"NOR+HBWHT+WHT"����˫��"NOR+HIB"����\n"NOR,me);

  

	me->add_temp("apply/attack", lvl);
	me->add_temp("apply/damage", lvl);
	me->add_temp("apply/cuff", lvl);
	me->add_temp("apply/strength", lvl / 3);
	if (me->query_temp("xtg/wuqi"))
		me->add_temp("apply/damage", lvl/2);
     
   COMBAT_D->do_attack(me, target, 0, 3);

	if ( me->is_fighting(target))
   COMBAT_D->do_attack(me, target, 0, 3);

	if ( me->is_fighting(target))
   COMBAT_D->do_attack(me, target, 0, 3);


	if ( me->is_fighting(target))
   COMBAT_D->do_attack(me, target, 0, 3);

	
	me->add_temp("apply/attack",- lvl);
	me->add_temp("apply/damage", -lvl);
	me->add_temp("apply/cuff", -lvl);
	me->add_temp("apply/strength",- lvl / 3);
		if (me->query_temp("xtg/wuqi"))
		me->add_temp("apply/damage", -lvl/2);
   me->add("jingli", -100);
   me->add("neili", -200);
   me->start_busy(random(2));

   me->start_perform(3+ random(3),"������˫����");

	return 1;
}


string perform_name(){ return WHT"����˫��"NOR; }

int help(object me)
{
	write(WHT"\n����ȭ֮������˫������"NOR"\n\n");
	write(@HELP
           ������� 3000 ���ϣ�
           ��ǰ���� 1500  ���ϣ�
           ��ǰ���� 1500  ���ϣ�
           ����ȭ�ȼ� 200 ���ϣ�
           ����ȭ���м�Ϊ����ȭ��
                       ��ȭ��Ϊ����ȭ�ҿ��֡�
            (NPCר��)��

HELP
	);
	return 1;
}
