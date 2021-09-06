// qianshou ǧ������
// bren

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
void remove_effect(object target, int skill);
void check_fight(object me,object target,int improve);
int perform(object me, object target)
{
        string msg;
        int skill;
        skill = (int)me->query_skill("qianye-shou", 1);                

       if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("��ǧ��������ֻ����ս���жԶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("ʹ�á�ǧ��������ʱ˫�ֱ�����ţ�\n");

        if( (int)me->query_skill("qianye-shou", 1) < 100 )
                return notify_fail("�������ǧҶ�ֲ�����죬����ʹ�á�ǧ����������\n");

        if( (int)me->query_skill("yijin-jing", 1) < 100 )
                return notify_fail("����׽�ڹ��ȼ�����������ʹ�á�ǧ����������\n");

        if( (int)me->query_dex() < 27 )
                return notify_fail("���������ǿ������ʹ�á�ǧ����������\n");

        if (me->query_skill_prepared("hand") != "qianye-shou"
        || me->query_skill_mapped("hand") != "qianye-shou")
                return notify_fail("�������޷�ʹ�á�ǧ�����������й�����\n");
     
        if( (int)me->query("neili") < 1000 )
                return notify_fail("����������̫��������ʹ�á�ǧ����������\n");

        if( target->query_temp("qianshou")   )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ���\n");

// 42          me->start_perform(2,"����ǧҶ��")
        msg = HIY "$N˫�ֺ�ʮ��������Ȼ����һ�֣�˫�ƶ�ʱ�������Ʈ�ݣ��鶯�쳣����ʱ�����������Ӱ��\n" NOR;
        message_vision(msg, me, target);
        if (random(me->query("combat_exp")) > target->query("combat_exp")/2){
          msg = HIR "$nֻ�������ܶ���$N����Ӱ�����ɵû���������\n" NOR;
          message_vision(msg, me, target);
          target->add_temp("apply/attack", -skill/3);
          target->add_temp("apply/dodge", -skill/3);
          target->add_temp("apply/parry", -skill/3); 
          target->set_temp("qianshou",1);   
          me->add("neili", -400);
          me->add("jingli",-150);
          me->start_call_out( (: call_other, this_object(), "check_fight",  me, target, skill :), 1);                             
          return 1;
        }
        message_vision(HIC"$N��������������ϸ������$n����Ӱ��\n"NOR,target,me);
        me->start_busy(2);
        me->add("neili", -100);
        me->add("jingli", -100);
        return 1;
}

void check_fight(object me, object target, int improve) 
{ 
       object weapon;     

       if (!target) return;
       if( !me) {
          remove_effect(target,improve);
       }
       else 
       if(target->query_temp("qianshou") && !me->is_fighting(target)){
          remove_effect(target, improve);
       }
       else if( (target->query_temp("qianshou")) 
        && (!target->is_fighting() 
        || !me->is_fighting() 
        || !living(me) 
        || target->is_ghost() 
        || me->is_ghost() )){
               remove_effect(target, improve);
        }
        else if((target->query_temp("qianshou"))
         && objectp(weapon = me->query_temp("weapon"))){
                remove_effect(target, improve);
        }
        else{
//            target->apply_condition("no_perform",1);
            call_out("check_fight", 1, me, target, improve); 
            return;
        }
}

void remove_effect(object target, int skill)
{
        target->add_temp("apply/attack", skill/3);
        target->add_temp("apply/dodge", skill/3);
        target->add_temp("apply/parry", skill/3);
        target->delete_temp("qianshou");
        tell_object(target, HIB"�㽥����Ӧ�����ֱ仯��״̬�ָֻ��糣��\n"NOR);
}

string perform_name(){ return HIY"ǧ������"NOR; }