// һ������� by hongba
#include <ansi.h>
inherit F_SSERVER;
    
   string perform_name(){ return HIM"һ�������"NOR; }
    
   int perform(object me,object target)
 {
       object weapon;
      int i;
      
       if( !target ) target = offensive_target(me);
       
       if( !objectp (target) || !me->is_fighting(target) || !living(target)
          || environment(target)!=environment(me))
                   return notify_fail("һ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
  
      
       if( (int)me->query_skill("hengshan-jianfa", 1) < 250 ) 
                   return notify_fail("��ĺ�ɽ������δ���ɣ�����ʹ��һ������㣡\n");

                 
       if((int)me->query_skill("sword", 1) < 250 )
                   return notify_fail("��Ļ�������������죬������ʹ��һ������㡣\n");
      
   if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"
           || me->query_skill_mapped("sword") != "hengshan-jianfa"
           || me->query_skill_mapped("parry") != "hengshan-jianfa")
                   return notify_fail("������ʹ����һ�������ô��\n");
                   
       if((int)me->query("max_neili") < 4500 )
                  return notify_fail("���������Ϊ����������ʹ��һ������㣡\n");
       if((int)me->query("neili") < 2000 )
                 return notify_fail("�������������㣬����ʹ��һ������㣡\n");
  
          message_vision(HIW"\n$N����һ����ֹ���Ӱһ��ʹ��ƽ����ѧ��\n",me);
           message_vision(HIM"�����Ǻ�ɽ�����ľ��С�һ������㡹,��˵���������������һ�������ֻ���㡣\n",me);
          
   me->start_perform(2,"��һ������㡹");
       i = (int)me->query_skill("hengshan-jianfa",1);
      me->add("neili", -300);
          me->add_temp("apply/attack",  i);
         me->add_temp("apply/damage",  i/4);

         me->add_temp("apply/damage",  i/4);
      me->add_temp("hsjf_ly",1);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
     me->add_temp("hsjf_ly",1);
      if (me->is_fighting(target))
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
      me->add_temp("hsjf_ly",1);
      if (me->is_fighting(target))
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
      me->add_temp("hsjf_ly",1);
         me->add_temp("apply/attack",  -i);
           me->add_temp("apply/damage",  -i/4);
  
      if(me->query("hsjf_ly")){
   message_vision(HBYEL"$N�ѵá�һ������㡹֮��Ҫ������������ˮ��ɲ�Ǽ�$n�Ѳ�֪��εֵ���"NOR,me,target);
 target->start_busy(3);
          me->add_temp("apply/attack",  i);
  me->add_temp("apply/damage",  i);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
          me->add_temp("hsjf_ly",1);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
         me->add_temp("hsjf_ly",1);

         me->add_temp("hsjf_ly",1);
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
          me->add_temp("apply/attack",  -i);
   me->add_temp("apply/damage",  -i);
       }
if (random(me->query("kar")) > 10 && random(me->query("pur")) > 10 && me->query("hsjf_ly")){
                   if (wizardp(me))
                   
   message_vision(HIM"\n$N����һ�٣�ͻȻʹ��һ�С�"HBRED"�ٱ�ǧ������ʮ��ʽ"NOR""HIM"����
�⡰�ٱ�ǧ������ʮ��ʽ�����Ǻ�ɽ��һλǰ��������
�����ɽ�����ˣ�ݻ��������˿�$Nʹ����ȴ�������ޱȡ�\n"NOR, me, target);
 message_vision(CYN"\n$nһ��֮�£���Ȼ�޷��������ǰ�Դ�һ��ȭ���Ѫ�����ۼ��������ء�\n"NOR, me, target);
          target->die();   // ò�ƺ���å�������ܿ����ٺ٣�Ū�����¡�
            }
      me->delete_temp("hsjf_ly");
      me->start_busy(1);
     return 1;
 }

