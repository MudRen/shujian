// xunlei-jian perform
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int lvl ;
        object weapon;
        lvl = me->query_skill("xunlei-jian", 1) /2 + me->query_skill("kunlun-zhang",1) /2 ;

 if(!userp(me)) lvl = lvl /2;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
                return notify_fail("��Ѹ���Ƶء�ֻ����ս���жԶ���ʹ�á�\n");
                
        if (!weapon || weapon->query("skill_type") != "sword"
                         || me->query_skill_mapped("sword") != "xunlei-jian"
                         || me->query_skill_mapped("parry") != "xunlei-jian")
                return notify_fail("�������ʹ�ý�ʱ����ʹ����Ѹ���Ƶء�\n");
                         
      if( (int)me->query_skill("kunlun-zhang", 1) < 100 )
      return notify_fail("��������Ʒ��ȼ�����������ʹ��Ѹ���Ƶأ�\n"); 
      
      if (me->query_skill_prepared("strike") != "kunlun-zhang"
                        || me->query_skill_mapped("strike") != "kunlun-zhang")
      return notify_fail("�������޷�ʹ��Ѹ���Ƶؽ��й�����\n");             
      
        if(me->query_skill("xunlei-jian", 1) < 100 )
                return notify_fail("���Ѹ�׽���������죬ʹ������Ѹ���Ƶء���\n");
        if( (int)me->query("max_neili") < 1000 )
                return notify_fail("����������̫����ʹ������Ѹ���Ƶء���\n");
        if( (int)me->query("neili") < 400 )
                return notify_fail("����������̫����ʹ������Ѹ���Ƶء���\n");



        msg = HIB"\n$N��Ȼ���أ�ʹ��Ѹ��ʮ����֮��Ѹ���Ƶء�����ʱһƬ�׹�ֱ��ǰ��ȥ��\n\n"NOR;
        message_vision(msg, me, target);

      me->set_temp("kl/podi",1);
      me->add("neili", -550); 
      me->add("jingli", -200);      
      me->add_temp("apply/strength", lvl /10 );
      me->add_temp("apply/sword", lvl/3);
      me->add_temp("apply/parry", lvl/3);
      me->add_temp("apply/damage", lvl /3 );
      me->add_temp("apply/attack", lvl /3);
      
if( random(lvl*3) > (int)target->query_skill("parry",1) /3 || !userp(target))
target->start_busy(2) ;

      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?3:1);  
  if (me->is_fighting(target))
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);  
  if (me->is_fighting(target))
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?3:1);  


      weapon->unequip(); 
  if (me->is_fighting(target))
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3); 
      weapon->wield();

if(lvl>=350){
   if (me->is_fighting(target)) 
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);  
   if (me->is_fighting(target)) 
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);  
   }
      
      me->add_temp("apply/strength", -lvl /10 );
      me->add_temp("apply/attack", -lvl /3);
      me->add_temp("apply/parry", -lvl/3);
      me->add_temp("apply/sword", -lvl/3 );
      me->add_temp("apply/damage", -lvl /3 );

      me->start_busy(2);
       me->delete_temp("kl/podi");
       me->start_perform(3+random(2),"��Ѹ���Ƶء�");
       return 1;
}
string perform_name(){ return MAG"Ѹ���Ƶ�"NOR; }
int help(object me)
{
write(MAG"\nѸ�׽���֮��Ѹ���Ƶء���"NOR"\n\n");
write(@HELP
          Ҫ��  ��ǰ���� 400 ���ϣ�
          ������� 1000 ���ϣ�
          Ѹ�׽����ȼ� 100 ���ϣ�
          ��������ΪѸ�׽�����
          �����м�ΪѸ�׽�����
          �����б��������Ʒ�
          ��������������

HELP
);
return 1;
}
