// ������ - ���컨��
// By River@SJ 

inherit F_SSERVER;
#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
        int num,p,damage;
        string msg;
        object weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
              return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if((int)me->query_skill("duoming-jinhua", 1) < 120 )
              return notify_fail("��Ķ����𻨲�����죬������ʹ�����컨�ꡣ\n");
        if((int)me->query_skill("shenghuo-shengong", 1) < 100 )
              return notify_fail("���ʥ���񹦵ȼ�����������ʹ�����컨�ꡣ\n");
        if((int)me->query("neili", 1) < 500 
         ||(int)me->query("jingli", 1) < 200 )
              return notify_fail("�����ڵ���������ʩչ���컨��ľ�����\n");
        if( (int)me->query_dex() < 35 )
              return notify_fail("�����̫�ͣ��޷�ʩչ���컨��ľ�����\n");
        if ( !weapon
         || weapon->query("skill_type") != "throwing"
         || me->query_skill_mapped("throwing") != "duoming-jinhua")
              return notify_fail("�������޷�ʹ�����컨�ꡣ\n");
        num = random(me->query_skill("duoming-jinhua", 1) / 20) + 10;
        if (me->query("gender") =="����")
            num = num/2;
        if ((weapon->query_amount()) < num)
             return notify_fail("�����ϵİ����������޷�ʹ�����컨�ꡣ\n");         
        me->add("neili", -100);
        me->add("jingli", -50);
        me->start_busy(1);
        msg = HIW"\n$N��߳һ��������ƮƮ��ֻ��"+chinese_number(num)+"����������컨��֮�ƣ�������˷���$n�����ȥ��\n"NOR;
        if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2
          && (int)me->query_dex() > random(target->query_dex())){
          weapon->add_amount(-num);
          msg += HIR"ֻ��$n����������ʹ��Ĵ��һ����"+weapon->name()+HIR"��ȫ��������ȫ��ҪѨ��\n"NOR;
          me->add("neili", -200);
          damage = me->query_skill("duoming-jinhua", 1);
          damage +=me->query_skill("throwing", 1);
          damage = damage * num /10;
          damage = damage + random(damage);
          if (damage>1500) damage=1500;
          target->receive_damage("qi", damage);
          target->receive_wound("qi", damage/3);
          target->start_busy(3);
          if(!target->is_killing(me->query("id"))) target->kill_ob(me);
          p = (int)target->query("qi")*100/(int)target->query("max_qi");
          msg += "( $n"+eff_status_msg(p)+" )\n";
         }
         else {
          msg += CYN"$n��ͷ����һ������������Ȼ�㿪��"+weapon->name()+CYN"�Ĺ�����\n"NOR;
          weapon->add_amount(-num);
          me->start_busy(3);
          me->add("neili",-100);
         }
         message_vision(msg, me, target);
         me->start_perform(4,"���컨��");
         return 1;
}
