// fentian.c �ٻ����
// by hunthu

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;
void remove_effect(object me);
void check_fight(object me, object target, int j); 

int perform(object me, int amount)
{
        string msg;
        object weapon, target;
        int skill, damage,p;
        weapon = me->query_temp("weapon");  
        skill= me->query_skill("ranmu-daofa",1);

        if( !target ) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("���ٻ���졹ֻ�ܶ�ս���еĶ���ʹ�á�\n");        

        if (!weapon || weapon->query("skill_type") != "blade"
                        || me->query_skill_mapped("blade") != "ranmu-daofa")
                return notify_fail("�������޷�ʹ�����ٻ���졹֮����\n");

        if (weapon->query("unique"))
                return notify_fail("������֮�����ڷ�����Ӱ�����˹�����\n");

        if((int)me->query_skill("ranmu-daofa", 1) < 160 )
                return notify_fail("���ȼľ������򲻹����޷����ٻ���졹��\n");

        if((int)me->query_skill("blade", 1) < 150 )
                return notify_fail("��Ļ���������������죬ʹ�������ٻ���졹������\n");

        if( (int)me->query_skill("yijin-jing", 1) < 150 )
                return notify_fail("����׽��Ϊ������ʹ�������ٻ���졹������\n");

        if ((int)me->query_skill("strike",1) < 120)
                return notify_fail("����Ʒ���Ϊ̫��޷�ʹ�����ٻ���졹������\n");

        if (me->query_skill_mapped("force") != "yijin-jing")
                return notify_fail("û���׽��Ϊ���������޷�ʹ�����ٻ���졹�����ģ�\n"); 

        if (me->query_temp("fumo"))
                return notify_fail("����������ʹ�á���շ�ħ���񹦡�\n"); 

        if (me->query_temp("ranmu"))
                return notify_fail("����������ʹ�á������ġ�������\n"); 

        if (me->query_temp("fentian"))
                return notify_fail("������ʹ�á��ٻ���졹������");

        if (me->query("max_neili") < 1500)
                return notify_fail("���������Ϊ������\n");

        if (me->query("neili") < 500)
                return notify_fail("�������������\n");

        if (me->query("jingli") < 200)
                return notify_fail("��ľ���������\n");

        me->set_temp("fentian",1);
        me->start_busy(2);
        me->add("neili", -800);
        me->add("jingli", -200);        
        msg =HIR"\n$N��Ȼһ����ȣ����е�"+weapon->name()+HIR"��һ�������ڿն���һ���ٲ�֮��������������棬\n"+
                "��ͷָ����һ���������ܶ�����$N������˫�ƣ��ڼ䲻�ݷ�֮�ʣ����������žŰ�ʮһ�ơ�\n"NOR;

        if(random(me->query("combat_exp",1)) > target->query("combat_exp",1)/3
         &&((me->query_skill("blade",1))+ me->query_skill("strike",1))/2 > random(target->query_skill("dodge",1))){
          skill= me->query_skill("ranmu-daofa",1)+me->query_skill("blade",1)+me->query_skill("buddhism",1);
          damage= skill*2;
          msg += HIR"\n$n��������������������ʧɫ���������޼��������ܴ��Χ�ڵ��С�\n"NOR;
          damage = damage+random(damage/2);
  //        if (damage > 3000) damage = 3000;
          target->receive_damage("qi", damage*4,me);
          target->receive_wound("qi", damage*2,me);
          p = (int)target->query("qi")*100/(int)target->query("max_qi");
          msg += "( $n"+eff_status_msg(p)+" )\n";
          me->start_call_out((: call_other, __FILE__, "remove_effect", me :), random(5));
          me->start_perform((1+random(4)), "�ٻ����");
          me->start_busy(2+random(2));
          me->start_call_out((: call_other, __FILE__, "check_fight", me, target :), 1);
          message_vision(msg, me, target);
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+damage+ WHT"���˺���\n"NOR); ;
          return 1;
        }
        if(random(me->query("combat_exp",1)) > (target->query("combat_exp",1)/3)){
          message_vision(HIR"\n$n�����з�������է�����ҫ��Ҳ�������һ������æԾ����ܣ�Ҳ�Ѵ����Ǳ���\n"NOR,me,target);
          target->start_busy(3+random(2));
          me->start_call_out((: call_other, __FILE__, "remove_effect", me :), random(5));
          me->start_perform(2, "�ٻ����");
          me->start_call_out((: call_other, __FILE__, "check_fight", me, target :), 1);
          return 1;
        }
        msg += HIR"\n$n�������أ����������һ�ɼ����˳����������ʱ���۳�һ��������������$N��\n"NOR;
        damage = skill*5;
        me->receive_damage("qi", damage*3);
        me->receive_wound("qi", damage*2);
        p = (int)me->query("qi")*100/(int)me->query("max_qi");
        msg += "( $N"+eff_status_msg(p)+" )\n";
        message_vision(msg, me, target);
        me->delete_temp("fentian");
        return 1;
}

void remove_effect(object me)
{
        if ( (int)me->query_temp("fentian") ) {
                me->delete_temp("fentian");
                tell_object(me, HIC"��⽥������������ʧ�����ˡ�\n"NOR);}
}

void check_fight(object me, object target, int j)
{
        object weapon;      
        if (!target) {remove_effect(me); return;}
        if( !present(target->query("id"), environment(me)) 
           || me->query_skill_mapped("blade") != "ranmu-daofa"
           || !weapon
           || weapon->query("skill_type") != "blade"
           || !me->is_fighting() 
           || !living(target) 
           || !target->is_fighting()
           || target->is_ghost() 
           || me->is_ghost() 
           || !living(me))
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, j :), 0);
        else call_out("check_fight", 1, me, target, j);
}

string perform_name(){ return HIR"�ٻ����"NOR; }
