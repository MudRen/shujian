// wofo.c yizhi-chan perform ����ҷ�
// By Spiderii Ч���޸�
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me);

int perform(object me, object target)
{
	string msg;
	int busy ;
      if( !target ) target = offensive_target(me);
     
      if( !objectp(target) || !me->is_fighting(target) )
	  return notify_fail("������ҷ�ֻ����ս���жԶ���ʹ�á�\n");
	     
      if( objectp(me->query_temp("weapon")) )
	  return notify_fail("��������ʹ�á�����ҷ𡹣�\n");
      
      if( (int)me->query_skill("yizhi-chan",1) < 100 )
	  return notify_fail("���һָ��������죬����ʹ�á�����ҷ𡹣�\n");

      if( (int)me->query_skill("yijin-jing",1) < 100 )
	  return notify_fail("����׽�ڹ��ȼ�����������ʹ�á�����ҷ𡹣�\n");  
      
      if( (int)me->query_str() < 25 )
	  return notify_fail("��ı�������ǿ������ʹ�á�����ҷ𡹣�\n");
      
      if( (int)me->query("max_neili") < 1000 )
	  return notify_fail("�������̫��������ʹ�á�����ҷ𡹣�\n");
      
      if( (int)me->query("neili") < 350 )
	  return notify_fail("�������̫���ˣ��޷�ʹ�ó�������ҷ𡹣�\n");   
										 
      if (me->query_skill_prepared("finger") != "yizhi-chan"
       || me->query_skill_mapped("finger") != "yizhi-chan")
	  return notify_fail("�������޷�ʹ�á�����ҷ𡹽��й�����\n");										 
      if( me->query_temp("wofo"))
	  return notify_fail("������ʹ��һָ�������⹥��������ҷ𡹣�\n");

	if (target->is_busy()) return notify_fail("�Է����Թ˲�Ͼ���ŵ������ɣ�\n");
       
      msg = HIY"$NͻȻ���������գ�������ָ�������͵�һ����һ�ɾ����������������$n�����Ѩ��\n" NOR;
      message_vision(msg, me, target);   
      busy=3+random(me->query_skill("yizhi-chan",1))/100;
      if(busy>8)
      busy=8;
      if( wizardp(me)) tell_object(me,sprintf("busy=%d\n",busy));
      if((random(me->query("combat_exp")) > target->query("combat_exp")/5*3)) {
  	
             msg = HIW"$nֻ�е�Ѩ��һ�飬��������ɢ���������á�\n"NOR;
		message_vision(msg, me, target); 
		me->set_temp("wofo",1);  
		me->add("neili", -350);    
		target->start_busy(busy);
     		me->start_busy(random(2));
		call_out("remove_effect", me->query_skill("yizhi-chan") / 20 + 2, me);
      }
      else {
		msg = HIY"$n����$N����ͼ��һ�������ݵض����$N����һ�У�\n"NOR;	  
		message_vision(msg, me, target);					
		me->start_busy(1+random(3));
		me->add("neili", - 100);
      }
      return 1;
}


void remove_effect(object me)
{
	if (!me) return;
	me->delete_temp("wofo");
       
	message_vision(HIR"$N�ġ�����ҷ��˹���ϣ���ɫ�ÿ����ˡ�\n"NOR, me);
}
string perform_name(){ return HIY"����ҷ�"NOR; }