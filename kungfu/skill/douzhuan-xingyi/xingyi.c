// xingyi.c ��ת����perform����
//COOL@SJ,20000909

#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

string perform_name(){ return HIY"���ƶ�ת"NOR; }

int perform(object me, object target)
{
        int damage,p;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("���ƶ�ת֮����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("douzhuan-xingyi", 1) < 120 )
                return notify_fail("������ƶ�ת��δ���ɣ�����ʹ�ã�\n");

        if( (int)me->query("max_neili") < 1800 )
                return notify_fail("������������Ϊ����������ʹ�����ƶ�ת֮���ƣ�\n");     
/*
if((int)me->query_temp("lianhuan"))
		return notify_fail("������ʹ���߽�����ָ��\n");
*/
        if( (int)me->query("neili") < 800 )
                return notify_fail("�������������㣬����ʹ�����ƶ�ת֮���ƣ�\n");

        if( (int)me->query_skill("parry", 1) < 120 )
                return notify_fail("��Ļ����м�֮��������죬����ʹ�����ƶ�ת֮���ơ�\n");

        if (me->query_skill_mapped("parry") != "douzhuan-xingyi")
                return notify_fail("�������޷�ʹ�����ƶ�ת��\n");                                                                                 
        msg = HIY "\n��Ȼ���ذ���$N�߶��ھ���ʹ��$n�ľ��У������������ڼ�������$n��ȥ��\n"NOR;
        if(me->query("neili") < random(target->query("neili")*2/3)){
           me->start_busy(1);
           target->start_busy(1); 
           me->add("neili", -me->query_skill("force"));
           me->add("jingli", -50);
           target->add("jingli", -50);
           target->add("neili", -me->query_skill("force"));
           msg += HIY"���$p��$P��������һƴ��˫����ûռ��˿���ô���\n"NOR;
           message_vision(msg, me, target);
                me->start_perform(4,"����");                 
           call_out("xingyi_hit", 3, me, target);   
           return 1;
        }
        if ((random(me->query_skill("parry"))+me->query_skill("literate",1)/4) 
           > target->query_skill("parry")/2){
           me->start_busy(1);
           target->start_busy(1);

           me->add("jingli", -100);
           damage = (int)me->query_skill("shenyuan-gong", 1);
           damage = (int)me->query_skill("douzhuan-xingyi", 1) +damage;
           damage += me->query("max_neili")/20;
           damage += damage;
           if( damage > 1500 ) damage = 1500;
        me->start_perform(5,"����");                 
           target->receive_damage("qi", damage);
           target->receive_wound("qi", damage/3);   
           me->add("neili", -(damage/3));             
           p = (int)target->query("qi")*100/(int)target->query("max_qi");
           msg += damage_msg(damage, "����");
           msg += "( $n"+eff_status_msg(p)+" )\n";
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"HIR+damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+damage+ WHT"���˺���\n"NOR); ;
           if (me->query("neili",1)>300)
           call_out("xingyi_hit", 2, me, target);                      
        }
        else{
           me->start_busy(3);
        me->start_perform(2+random(2),"����");                 
           me->add("jingli", -50);
           me->add("neili", -200);
           msg += CYN"\n$p��ôҲ�벻��$N�ܹ�ʹ���Լ��ĳ���������Σ��֮��˫�Űϵض��𣬼��ѵĶ����һ�У���ɫ��Ĳ԰ס�\n" NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

int xingyi_hit(object me, object target)
{
        int skill,i,j;
     string msg;   
        mapping apply;
if(!me) return 0;
        skill = (int)me->query_skill("douzhuan-xingyi", 1);                
        j = skill/80;   
        skill = skill/6;
        if(skill>100) skill=100;
        
        
        if (j>3) j=3;     
        target = offensive_target(me);
        if( !target
        || !target->is_character()
        || !me->is_fighting(target)
        || !living(target)
        || environment(target) != environment(me) ){
                write("���ƶ�תֻ�ܶ�ս���еĶ���ʹ�á�\n");
                return 0;
        }
       
        if(!living(target)) 
              return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if((int)me->query("neili", 1) < 200 )
              return notify_fail("����Ҫ�����ٻ���һگ��ȴ�����Լ������������ˣ�\n"); 
                
        if(me->query_skill_mapped("parry") != "douzhuan-xingyi")
             return notify_fail("�������޷�ʹ�����ƶ�ת��\n");         
        
        apply=target->query_temp("apply");
     if(apply) {
        me->set_temp("douzhuan/damage_apply",(apply["damage"]+apply["strength"])/2);
        me->set_temp("douzhuan/attack_apply",apply["attack"]);
    }
      msg = HIR "\n������$N��������������ˮ,����ʹ�����¶Է�������,���Է��Ĺ����������˻�ȥ��\n"NOR;
        message_vision(msg, me, target);
        me->add_temp("apply/damage", skill+me->query_temp("douzhuan/damage_apply"));
        me->add_temp("apply/attack", skill+me->query_temp("douzhuan/attack_apply"));
        for (i=0;i< j;i++) {
            if(me->is_fighting(target))
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), (me->query_skill("douzhuan-xingyi",1)>=300)?3:1);
        }
        me->add_temp("apply/damage", -(skill+me->query_temp("douzhuan/damage_apply")));
        me->add_temp("apply/attack", -(skill+me->query_temp("douzhuan/attack_apply")));
        me->add("neili", -j*50);
if(me->query_skill("douzhuan-xingyi",1)<=450)
        me->start_busy(2);
        return 1;
}


int help(object me)
{
    write(WHT"\n��ת����֮��"HIG"���ƶ�ת"WHT"����"NOR"\n");
         write(@HELP
   ��ת�����еľ��У����Ի��������Ӷ����۾���Է���
   �Է�����֪��һ�е���������ֻ��ʹ���Լ��ĳ�������
   �ԶԿ���ȴƫƫ��ֻ���з��������亦��
      
Ҫ��  ������� 1800 ���ϣ�      
        ��ǰ���� 800  ���ϣ�  
        ��ת���Ƶȼ� 120 ���ϣ�
        �����мܵȼ� 120 ���ϣ�
        �����м�Ϊ��ת���ơ�            
HELP
    );
        return 1;
}


