//rebuild by jpei 2010
//ԭ����˼·��д����Щ��
 
#include <ansi.h>
#include <combat.h>
 
 inherit F_SSERVER;
 
 int perform(object me, object target)
 {
         string msg;
         object weapon;
         int jf,zf,sf,lvl;
         weapon = me->query_temp("weapon");

         if( !target ) target = offensive_target(me);

        if( !target 
          || !me->is_fighting(target)
          || !objectp(target)
          || environment(target)!= environment(me))
                return notify_fail("�����߿��衹ֻ����ս���жԶ���ʹ�á�\n");

 
        if (!weapon || weapon->query("skill_type") != "sword"
                         || me->query_skill_mapped("sword") != "jinshe-jianfa")
                 return notify_fail("�������ʹ�ý�ʱ����ʹ�������߿��衹��\n");
//�ٺ٣�����ò��û�ж�parry������9j,dkdny,dzxy...
 
         if(me->query_skill("jinshe-jianfa", 1) < 120 )
                 return notify_fail("��Ľ��߽�����������죬ʹ���������߿��衹������\n");

         if( (int)me->query_skill("force") < 170 )
                 return notify_fail("����ڹ��ȼ�������ʹ���������߿��衹������\n");
 
         if( (int)me->query_str() < 27)
                 return notify_fail("�������������ǿ����ʹ���������߿��衹������\n");
 
         if( (int)me->query_dex() < 27)
                 return notify_fail("�����������Ѹ�ͣ�ʹ���������߿��衹������\n");
/*
         if( (int)me->query("dex") < 20 ||( (int)me->query("str") > 20&&  (int)me->query("str") <31) || (int)me->query("int") < 20)
                 return notify_fail(HIG"��ɵͷɵ��,���ֱ��ŵ�,�����ʲô��.\n"NOR);
*/
         if( (int)me->query("max_neili") < 800 )
                 return notify_fail("����������̫����ʹ���������߿��衹��\n");      
 
         if( (int)me->query("neili") < 500 )
                 return notify_fail("�������������㣬ʹ���������߿��衹��\n");

     
         jf = me->query_skill("jinshe-jianfa", 1);
         zf = me->query_skill("jinshe-zhang", 1);
         sf = me->query_skill("wudu-yanluobu", 1);
         lvl=( jf + zf +sf ) /2;        



if(weapon->query("id") == "jinshe sword"|| weapon->query("id") == "yinshe sword" || weapon->query("imbued")>=4 || !userp(me))     me->set_temp("jsj", 1); //�ж������ǲ��ǽ��߽���������
   
if( me->query_skill("wudu-yanluobu", 1) > 120 && me->query_skill_mapped("dodge") == "wudu-yanluobu")
           {     me->add_temp("apply/dexerity",sf /10);
                 me->add_temp("apply/attack",sf /4); 
                 me->set_temp("sfup",1); 
     }

if( me->query_skill("jinshe-zhangfa", 1) > 120&& me->query_skill_mapped("strike") == "jinshe-zhangfa" && me->query_skill_prepared("strike") == "jinshe-zhangfa")
          {           me->add_temp("apply/strength", zf/10);
                      me->add_temp("apply/damage", zf/6);
                      me->set_temp("zfup",1);
           }       
                                                                
if( me->query_skill("jinshe-jianfa",  1) > 120 && me->query_skill_mapped("sword") == "jinshe-jianfa")
         {      me->add_temp("apply/sword", lvl /4);
                me->add_temp("apply/parry", lvl  /4);
                me->add_temp("apply/damage", lvl/6);
                me->set_temp("jfup",1);
          }        


message_vision(HIC"\n$Nһ������"+weapon->name()+HIC"ʹ�����߽�������֮�أ���"HIW"һ"HIC"�ؽ��߿���֮"HIY"������о"HIC"����Ȼ�ӿ����ٱ���\n"NOR,me);
            me->add_temp("apply/damage", lvl /6);
            me->add_temp("apply/attack", lvl /4);
            me->add_temp("apply/dexerity",sf /10);
 if (me->is_fighting(target))
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

 if(  me->query_temp("jsj") &&  me->query_temp("zfup")  )
 {      
                     message_vision(HIY"\n\n$N����"+weapon->name()+HIY"�����������Ƴ�������⣬������$N����Ϊ�������������ֱָ$n����\n"NOR,me,target);
                     message_vision(HIR"$Nһ������"+weapon->name()+HIR",���ų�������,$n��ʱ�����ۻ�����,��$N���˸����ֲ�������\n"NOR,me,target);
if(!userp(target))
                  {
                   target->start_busy(2);
                                  target->set_temp("must_be_hit",1);
                     }
if( userp(target))  target->add_busy(1);
  

    me->start_perform(3,"�����߿��衹");
              me->add("neili", -300);
              me->add("jingli", -200);

              
        if (me->is_fighting(target)) 
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
                          message_vision(HIY"                                                                     ��������������\n"NOR,me);       
                          message_vision(HIY"                                                                     ����  ��  ����\n"NOR,me);
                          message_vision(HIY"                                                                     ��������������\n"NOR,me);       
   
        if (me->is_fighting(target)){
      weapon->unequip(); 
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
                          message_vision(HIY"                                                                     ��������������\n"NOR,me);       
                          message_vision(HIY"                                                                     ����  ��  ����\n"NOR,me);       
                          message_vision(HIY"                                                                     ��������������\n"NOR,me);       
      weapon->wield();
                                    }

        if (me->is_fighting(target))
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
                          message_vision(HIY"                                                                     ��������������\n"NOR,me);       
                          message_vision(HIY"                                                                     ����  ��  ����\n"NOR,me);       
                          message_vision(HIY"                                                                     ��������������\n"NOR,me);       
        if (me->is_fighting(target)){
              weapon->unequip(); 
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
                          message_vision(HIY"                                                                     ��������������\n"NOR,me);       
                          message_vision(HIY"                                                                     ����  ��  ����\n"NOR,me);       
                          message_vision(HIY"                                                                     ��������������\n"NOR,me);       
              weapon->wield();

target->delete_temp("must_be_hit");
                                    } 
}  

else if( me->query_temp("zfup")) {
       message_vision(HIC"\nͻȻ$N����$n���ٱ��ߣ���Ȼ��������һ�ƣ�\n"NOR,me,target);
       me->start_perform(4,"�����߿��衹");
              if (me->is_fighting(target))  COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
              if (me->is_fighting(target)) COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
              if (me->is_fighting(target)) {
                 weapon->unequip(); 
                COMBAT_D->do_attack(me, target, 0, 3);
                 weapon->wield();     }
}       

if (me->query_temp("sfup")){
                me->add_temp("apply/dexerity",-sf /10);      
                me->add_temp("apply/attack",   -sf /4); 
                   }
if (me->query_temp("zfup")){  
                me->add_temp("apply/strength", -zf/10);
                me->add_temp("apply/damage", -zf/ 6);
                   }
if( me->query_temp("jfup")){
                me->add_temp("apply/sword",     - lvl/4);
                me->add_temp("apply/parry",      - lvl/4);
                me->add_temp("apply/damage",  - lvl/6);
                   }

       me->delete_temp("sfup");
       me->delete_temp("jfup");
       me->delete_temp("zfup");
       me->delete_temp("jsj");
            me->add_temp("apply/damage", -lvl /6);
            me->add_temp("apply/attack", -lvl /4);
            me->add_temp("apply/dexerity",-sf /10);  
            me->start_busy(1+random(2));
            target->start_busy(1);

           return 1;
 }


int help(object me)
{
        write(HIY"\n�����ؼ�֮�����߿��衹��"NOR"\n\n");
        write(@HELP
        �����ɾ���ѩ�������������ĵľ����书. ��ϧ�������н����ؼ���
        �ָ�ɺü�����, ���߿��������Ҳ����ǰ. �ഫ�ڴ�������ؼ�
        �еĽ���, ��, �Ʒ�����ܷ��ӽ��߿�������������. ������ҿ�
        �Ի�ý��߽�, ��ʹ���������ϲ�¥.

        Ҫ��  ��ǰ���� 1500 ���ϣ���������� 2800 ���ϣ�
                ��������������27
                ��һ�׶Σ����߽����ȼ� 120 ���ϣ������ڹ��ȼ� 170 ���ϣ�
                ������������������Ϊ���߽�����
                �ڶ��׶Σ������Ʒ��ȼ� 120 ���ϣ�����׼���Ʒ�Ϊ�����Ʒ���
                �����׶Σ��嶾���޲��ȼ� 120 ���ϣ������ṦΪ�嶾���޲���
                
                ���⣬���װ���˽��߽��������߽��������ɸ���һ��¥��

HELP
        );
        return 1;
}

string perform_name(){ return HIC"���߿���"NOR; }
