//  huima.c ����̫�� 
//Created by Redhat@Sjmud 2009/4/7

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

string perform_name() {return WHT"����̫��"NOR;}

int perform(object me,object target)
{
    object weapon;
    int i;
    i = me->query_skill("taixuan-gong", 1) /3;
    if( !target ) target = offensive_target(me);
     
    if(!objectp(target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("������̫����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if((int)me->query_skill("force", 1) < 250 )
                return notify_fail("��Ļ����ڹ�������죬�޷�֧�֡�����̫������\n");

    if( (int)me->query_skill("taixuan-gong", 1) < 250 ) 
 return notify_fail("��Ĺ���δ���ɣ�����ʹ�á�����̫������\n");

   
    if((int)me->query_skill("dodge", 1) < 250 )
                return notify_fail("��Ļ����Ṧ������죬����ʹ�á�����̫������\n");

                    
    if((int)me->query("max_neili") < 8000 )
                return notify_fail("���������Ϊ����������ʹ�á�����̫������\n");

    if((int)me->query("neili") < 3000 )
                return notify_fail("�������������㣬����ʹ�á�����̫������\n");

    if((int)me->query("jingli") < 1000 )
                return notify_fail("������̫���ˣ�����ʹ�á�����̫������\n");
      
message_vision(HIW"\n��ʱ��$N˼����ӿ���������$n����мܣ�ֻ��ʹ�����͵�ʯ���ϵ�ǧ������ʽ������$nϮȥ��\n"NOR, me,target);

    me->start_perform(3,"������̫����");
    me->add("neili", -800);
    me->add("jingli",-500);
me->set_temp("txg_tx",5);

    me->add_temp("apply/attack", i);
    me->add_temp("apply/damage",i);
target->start_busy(random(4));
        target->set_temp("must_be_hit",1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
   target->delete_temp("must_be_hit");
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
   
   me->add_temp("apply/damage", -i);
   me->add_temp("apply/attack", -i);
me->delete_temp("txg_tx");
    me->start_busy(1);
    target->start_busy(1);
    return 1;
}

int help(object me)
{
   write(HIR"\n̫������"HIW"����̫��"HIR"����"NOR"\n");
   write(@HELP
   ָ�perform xuan

   Ҫ��̫����250����
         ������� 8000 ���ϣ�
         ��ǰ���� 3000 ���ϣ�
         ��ǰ���� 1000 ���ϣ�
         ˭������£�
         ����̫������
HELP
   );
   return 1;
}

