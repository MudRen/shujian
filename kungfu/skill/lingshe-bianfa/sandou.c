 // sandou ��������

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int lv;
      object weapon;

      weapon = me->query_temp("weapon");
	lv = me->query_skill("lingshe-bianfa",1);
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
      return notify_fail("������������ֻ����ս���жԶ���ʹ�á�\n");

      if (!weapon || weapon->query("skill_type") != "whip"
       || me->query_skill_mapped("whip") != "lingshe-bianfa")
      return notify_fail("������û�бޣ��޷�ʹ�á�������������\n");             

      if( (int)me->query_skill("lingshe-bianfa",1) < 120 )
      return notify_fail("������߱޷�������죬����ʹ�á�������������\n");
      
      if( (int)me->query_skill("dulong-dafa", 1) < 120 )
      return notify_fail("��Ķ����󷨵ȼ�����������ʹ�á�������������\n");

      if( (int)me->query("neili") < 200 )
      return notify_fail("�������̫�٣�����ʹ�á�������������\n");
      
	if(me->query_skill_mapped("force") != "dulong-dafa")
       	return notify_fail("������ʹ�õ��ڹ��붾������ִ�������ʹ�á����߲�˿����\n");

      message_vision(HIY"\n$N�����������б��ӣ�"+weapon->query("name")+HIY+"ѭ�Ź����;����$nϮȥ��\n"NOR, me,target);
      me->add("neili", -200); 
      me->add("jingli", -50);

      target->start_busy(1);
me->start_busy(2);

      me->set_temp("sandou",1);
      me->add_temp("apply/attack", lv/4);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
      me->add_temp("apply/attack", -lv/4);
      me->delete_temp("sandou");	
             me->start_perform(3,"������������");
      return 1;
}
