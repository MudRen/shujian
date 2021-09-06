// fuxue.c ������Ѩ
// Created by Numa 19990927

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h"

inherit F_SSERVER;

string *xue_name = ({
        "����Ѩ",
        "����Ѩ",
        "����Ѩ",
        "�׺�Ѩ",
        "��̨Ѩ",
        "�縮Ѩ",
        "���Ѩ",
        "����Ѩ",
}); 

void remove_effect(object me);

int perform(object me, object target)
{
      string msg,name;
      int cp,ap, dp;
      
      if( !target ) target = offensive_target(me);
     
      if( !target
       || !me->is_fighting(target)
       || !living(target)
       || environment(target)!=environment(me))
                return notify_fail("��������Ѩ��ֻ����ս���жԶ���ʹ�á�\n");
             
      if( me->query_temp("weapon") )
                return notify_fail("��������ʹ�á�������Ѩ����\n");
      
      if( (int)me->query_skill("lanhua-shou",1) < 180 )
                return notify_fail("���������Ѩ�ֻ�������죬������������������Ѩ���ġ�׼���֡�\n");
      
      if( (int)me->query_skill("suibo-zhuliu",1) < 180 )
                return notify_fail("����沨������������죬������������������Ѩ���ġ��졹�֡�\n");

        if( (int)me->query_skill("qimen-bagua",1) < 180 )
                return notify_fail("������Ű��Ի�������죬������������������Ѩ���ġ��桹�֡�\n");
                  
        if (me->query_skill_mapped("force") != "bihai-chaosheng")
                return notify_fail("����ʹ�õ��ڹ����ԡ�\n");
                
        if( target->query_condition("lanhua-fuxue"))
                return notify_fail("�Է��Ѿ����С�������Ѩ�����㲻���ٷ������ˡ�\n");

        if( (int)me->query("neili") < 700 )
                return notify_fail("�������̫���ˣ��޷�ʹ����������Ѩ����\n");
            
        if( (int)me->query("jingli") < 500 )
                return notify_fail("��ľ���̫���ˣ��޷�ʹ����������Ѩ����\n");
                  
        if( (int)me->query_temp("lanhua-fuxue"))
                return notify_fail("��ո�ʹ�ù���������Ѩ��������Ϣһ�°ɣ�\n");   
                                                               
        if (me->query_skill_prepared("hand") != "lanhua-shou"
         || me->query_skill_mapped("hand") != "lanhua-shou")
                return notify_fail("�������޷�ʹ�á�������Ѩ�����й�����\n");                                         

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
                
        me->start_perform(5, "������Ѩ");
        name = xue_name[random(sizeof(xue_name))];
// ���� ��              
        if (me->query("eff_qi")>=me->query("max_qi") / 2)
        {
                msg = HIC"\n$N���ֻӳ���Ĵָ��ʳָ����������ָ���ţ���ָ��һ֦���������������$n�����������Ѽ���\n" NOR;
                                           
                ap = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("hand") + me->query_skill("qimen-bagua");
                cp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("hand") + me->query_skill("qimen-bagua");
                dp = target->query_skill("force") + target->query_skill("dodge") +me->query_skill("parry")+target->query_skill("literate");
                ap *= me->query("combat_exp")/1000;
                dp *= target->query("combat_exp")/1000;       
                if (cp>1000) cp=1000;            
                if( random(ap) > dp / 2 )
                {
                        msg += CYN"$nֻ�С�"RED + name + CYN"����һ�飬��$N����Ѩ����\n"NOR;
                        target->receive_damage("qi", random(cp), me);
                        ap = (int)target->query("qi")*100/(int)target->query("max_qi");
                        msg += damage_msg(me->query_skill("hand"), "����");
                        msg += "( $n"+eff_status_msg(ap)+" )\n";
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+random(cp)+ WHT"�㹥���˺���\n"NOR); 

if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+random(cp)+ WHT"���˺���\n"NOR); ;

                        me->add("neili",-cp/3);
                        me->add("jingli",-100);
                        target->start_busy(random(2));
                }
                else
                {
                        msg += CYN"$nֻ�С�"RED + name + CYN"����һ�飬�ֱۼ������������Ѹ�٣�û��$N����Ѩ����\n"NOR;
                        me->add("neili",-100);
                        me->add("jingli",-40);
                        me->start_busy(1);
                }                    
                message_vision(msg, me, target);   
                me->set_temp("lanhua-fuxue", 1);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me:), 10);
                return 1;
        }
// ������ ��
        else
        {
                msg = HIC"\n$N���ֻӳ���Ĵָ��ʳָ����������ָ���ţ���ָ����бб�ط���$n��\n" NOR;
                                           
                ap = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("hand") + me->query_skill("qimen-bagua");
                cp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("hand") + me->query_skill("qimen-bagua");
                dp = target->query_skill("force") + target->query_skill("dodge") +target->query_skill("parry")+target->query_skill("literate",1);
                ap *= me->query("combat_exp")/1000;
                dp *= target->query("combat_exp")/1000;       
                if (cp>1000) cp=1000;      
                if( random(ap) > dp/2 )
                {
                        msg += CYN"$nֻ�С�"RED + name + CYN"����һ�飬��$N����Ѩ����\n"NOR;
                        target->receive_damage("qi", random(cp), me);
                        ap = (int)target->query("qi")*100/(int)target->query("max_qi");
                        msg += damage_msg(me->query_skill("hand"), "����");
                        msg += "( $n"+eff_status_msg(ap)+" )\n";

                        me->add("neili",-300);
                        me->add("jingli",-100);
                        target->start_busy(2);
                }
                else
                {
                        msg += CYN"$nֻ�С�"RED + name + CYN"����һ�飬�ֱۼ������������Ѹ�٣�û��$N����Ѩ����\n"NOR;
                        me->add("neili",-100);
                        me->add("jingli",-40);
                        me->start_busy(1);
                }                    
                message_vision(msg, me, target);   
                me->set_temp("lanhua-fuxue", 1);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me:), 10);
                return 1;
        }
}

void remove_effect(object me)
{
        if(!me) return;
        me->delete_temp("lanhua-fuxue");
}

string perform_name(){ return HIC"������Ѩ"NOR; }
