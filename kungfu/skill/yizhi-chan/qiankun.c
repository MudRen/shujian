// qiankun.c
// by snowman@SJ 22/06/99

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

void remove_effect(object me);
int perform(object me, object target)
{
      string msg, dodge_skill;                                   
      int ap, dp;
      
      if( !target ) target = offensive_target(me);
     
      if( !objectp(target) || !me->is_fighting(target) || !living(target)
      || environment(target)!=environment(me))
                return notify_fail("��һָǬ����ֻ����ս���жԶ���ʹ�á�\n");
             
      if( target->query("combat_exp") < 80000 )
                return notify_fail("ɱ������ţ������"+target->name()+"��û��Ҫʹ��һָǬ���ɡ�\n");
      if( me->query_temp("weapon") )
                return notify_fail("��������ʹ�á�һָǬ������\n");
      
      if( (int)me->query_skill("yizhi-chan",1) < 180 )
                return notify_fail("���һָ��������죬����ʹ�á�һָǬ������\n");
      
      if( (int)me->query_skill("yijin-jing",1) < 180 )
                return notify_fail("��һָǬ������Ҫ�ۺ���׽�ڹ�Ϊ������\n");
                  
      if (me->query_skill_mapped("force") != "yijin-jing")
                return notify_fail("����ʹ�õ��ڹ����ԡ�\n");
                
      if( target->query_condition("yzc_qiankun"))
                return notify_fail("�Է��Ѿ����С�һָǬ�������㲻���ٷ������ˡ�\n");
      
      if( (int)me->query("max_neili") < 3000 )
                return notify_fail("���������Ϊ̫�Σ�����ʹ�á�һָǬ������\n");
      
      if( (int)me->query("neili") < 700 )
                return notify_fail("�������̫���ˣ��޷�ʹ�ó���һָǬ������\n");   
            
      if( (int)me->query("jingli") < 500 )
                return notify_fail("��ľ���̫���ˣ��޷�ʹ�ó���һָǬ������\n");   
                  
      if( (int)me->query_temp("yzc/qiankun"))
                return notify_fail("��ո�����һ�Ρ�һָǬ�������ȵ�Ϣ��Ϣһ�°ɣ�\n");   
                                                               
      if (me->query_skill_prepared("finger") != "yizhi-chan"
          || me->query_skill_mapped("finger") != "yizhi-chan")
                return notify_fail("�������޷�ʹ�á�һָǬ�������й�����\n");                                                                                 
       
      msg = HIC"\n$N��¶΢Ц����ָ����$n����һ����ֻ���͵�һ��һ�ɾ�����$P��ָ�������������$p���\n" NOR;
                                           
      ap = me->query_skill("force") + me->query_skill("finger") + me->query_kar();
      dp = me->query_skill("force") + me->query_skill("dodge") + target->query_kar();   
      ap *= me->query("combat_exp")/1000;
      dp *= target->query("combat_exp")/1000;       
                      
      me->receive_damage("neili", me->query_skill("force") + me->query_skill("finger"));
//     me->start_perform(5,"һָǬ��");
      
      if( random(ap) > dp/3) {
                msg += HIW"���$nһ����С�ģ���ָ�����ڵ���֮�ϣ���ʱ�������ң���ɫ���ף�\n"NOR;
                tell_object(target, "��о���ָ���ڵ������Ҵܣ��ŵ�����������ɼ���\n");
                target->receive_damage("qi", me->query_skill("finger"), me);
                ap = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(me->query_skill("finger"), "����");
                msg += "( $n"+eff_status_msg(ap)+" )\n";
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"HIR+me->query_skill("finger")+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"HIR+me->query_skill("finger")+ WHT"���˺���\n"NOR);
                
                target->apply_condition("yzc_qiankun", 2+me->query_kar()/5);                                                    
                }
      else {
   me->start_busy(2);
                dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                }                    
            
      message_vision(msg, me, target);   
      me->set_temp("yzc/qiankun", 1);
      me->start_call_out( (: call_other, __FILE__, "remove_effect", me:), 15);
      return 1;
}

void remove_effect(object me)
{
        if(!me) return;
        me->delete_temp("yzc/qiankun"); 
}

string perform_name(){ return HIC"һָǬ��"NOR; }
