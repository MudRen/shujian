// zuijiu.c ���

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{                                  
      int i, lvl, addlvl;
      object weapon;
      
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) || !living(target))
                return notify_fail("���������ֻ����ս���жԶ���ʹ�á�\n");

      if (!objectp(weapon = me->query_temp("weapon")) 
        || weapon->query("skill_type") != "club"
        || me->query_skill_mapped("club") != "zui-gun")
                return notify_fail("�������޷�ʹ�á�������򡹡�\n");
  
      if( (int)me->query_skill("zui-gun",1) < 100 )
                return notify_fail("������������죬����ʹ�á�������򡹣�\n");
      
      if( me->query_skill_mapped("force") != "yijin-jing" )
                return notify_fail("��������ʹ���ڹ��޷�ʹ����������򡹡�\n");

      if( (int)me->query_skill("yijin-jing",1) < 100 )
                return notify_fail("����׽�ȼ�����������ʹ�á�������򡹣�\n");  
       
      if( (int)me->query_str() < 25 )
                return notify_fail("��ı�������ǿ������ʹ�á�������򡹣�\n");
      
      if( (int)me->query("max_neili") < 1000 )
                return notify_fail("�������̫��������ʹ�á�������򡹣�\n");
            
        lvl = (int)me->query_skill("zui-gun", 1);
        addlvl = (int)me->query_skill("zui-gun", 1)/2 +  me->query_skill("yijin-jing",1)/3;

        if(lvl < 120) return notify_fail("��ĵȼ�̫�ͣ��޷�ʹ�ó���������򡹣�\n");

      	if( (int)me->query("neili") < 1500 )
                return notify_fail("�������̫���ˣ��޷�ʹ�ó���������򡹣�\n");
      	lvl /= 20;
      	lvl--;
      	if(lvl > 8) lvl = 8; 
      	if(lvl < 1) return notify_fail("��ĵȼ�̫�ͣ��޷�ʹ�ó���������򡹣�\n");
 message_vision(HIY"\n$N��Ȼ���������ⲻ�������Ĳ�����������У��������ģ��������ʹ����������򡹣��������������\n"NOR,me);
if(!userp(target))  target->add_busy(1+random(2));
       me->add_temp("apply/attack", addlvl/2);
        me->add_temp("apply/parry", addlvl/2);
        me->add_temp("apply/dodge", addlvl/2);
        me->add_temp("apply/damage", addlvl/2);
      	me->set_temp("zuijiu", 1);
      	for(i=0; i < lvl; i++){
      	   	if(!me->is_killing(target->query("id")) 
      	   	&& !target->is_killing(me->query("id"))
      	   	&& !target->is_fighting(me))
      	   	break;
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),random(2)?3:1);
           	me->add_temp("zuijiu", 1);
                me->receive_damage("neili", 50);
                me->receive_damage("jingli", 10);
      	}
      	me->delete_temp("zuijiu");
        me->add_temp("apply/attack", -addlvl/2);
        me->add_temp("apply/parry", -addlvl/2);
        me->add_temp("apply/dodge", -addlvl/2);
        me->add_temp("apply/damage", -addlvl/2);
    me->start_perform(4, "���������");
        tell_object(me, HIG"\n������һ�ң���Ҳ�޷�ά�����������⾳�ˡ�\n"NOR); 
        return 1;
}
