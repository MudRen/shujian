// qixing. ���Ǿ�����
// Modify By River 99.5.26
// Modified by darken@SJ
#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;

string perform_name() {return HIW"���Ǿ�����"NOR;}

int perform(object me, object target)
{
        string msg,dodge_skill;
        object weapon = me->query_temp("weapon");
        int damage, p;
        if( !target ) target = offensive_target(me);

         if( !objectp(target)
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á����Ǿ���������������\n");

        if( (int)me->query_skill("quanzhen-jianfa", 1) < 101 )
                return notify_fail("���ȫ�潣������������ʹ���������Ǿ�������������\n");

        if ( !weapon
         || weapon->query("skill_type") != "sword"
         || me->query_skill_mapped("sword") != "quanzhen-jianfa"
         || me->query_skill_mapped("parry") != "quanzhen-jianfa")
               return notify_fail("�������޷�ʹ�����Ǿ�������\n");

        if((int)me->query_skill("sword", 1) < 100 )
               return notify_fail("��Ļ�������������죬ʹ���������Ǿ�������������\n");

        if((int)me->query_dex() < 25)
               return notify_fail("�����������Ѹ��ʹ���������Ǿ�������������\n");

        if((int)me->query_skill("force", 1) < 100)
               return notify_fail("����ڹ���Ϊ�������޷�ʹ�á����Ǿ�������������\n");  

        if((int)me->query_temp("hebi"))
               return notify_fail("������ʩչ˫���ϱڣ��޷�ʹ�á����Ǿ�������������\n"); 

        if((int)me->query("neili") < 400)
               return notify_fail("��������������޷�ʹ�á����Ǿ�������������\n");

        if((int)me->query("jingli")< 300)
               return notify_fail("��ľ����������޷�ʹ�á����Ǿ�������������\n");

        msg = HIW"\n$Nһ����Х��һ�����н�����Ļ�зɳ��߶亮�ǣ������籩���������ǰ���$n���˹�ȥ��\n"NOR;
        if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
        {
           damage =  8 * (int)me->query_skill("quanzhen-jianfa", 1);
           damage = damage / 2 + random(damage / 2);
           if (damage>1500) damage=1500;
           if (me->query_skill("xiantian-gong")>100) damage *= 2;
               else message_vision(HIG"ֻ��$N�����칦��û���ң�����΢����\n"NOR, me);
           me->add("neili", -damage/3);
           me->add("jingli",-100);

  if( damage > target->query("qi") ) 
 { damage= target->query("qi")-1;
   target->start_busy(10);
  }
           target->receive_damage("qi", damage);
           target->receive_wound("qi", damage/3);

           msg += HIR"$n���������������߽������ۡ��Ŀ��һ������Ѫ���������\n"NOR;
           p = (int)target->query("qi")*100/(int)target->query("max_qi");
           msg += "( $n"+eff_status_msg(p)+" )\n";


           target->set_temp("last_damage_from", "��"+me->name()+"ɱ");
if(target->query("qi")==1) target->die();
           me->start_perform(2+random(1),"�����Ǿ�������");
        } 
        else {
              dodge_skill = target->query_skill_mapped("dodge");
              if( !dodge_skill ) dodge_skill = "dodge";
              msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
              me->add("neili", -100);
              me->start_busy(2); 
              me->start_perform(3,"�����Ǿ�������");
        }
        message_vision(msg, me, target);
        return 1;
}
