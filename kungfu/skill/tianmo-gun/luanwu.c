//�������
//xjqx 2008/12/30

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

string perform_name(){ return HIW"�������"NOR; }

int perform(object me,object target)
{
    object weapon;
    int i;
    
    if( !target ) target = offensive_target(me);
     
    if( !objectp (target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_skill_mapped("force") != "tianmo-gong" )
          if(me->query_skill_mapped("force") != "xixing-dafa")
                return notify_fail("����ʹ�õ������ڹ����ԡ�\n");  
        if(!me->query_skill("xixing-dafa", 1))
          if(me->query_skill("tianmo-gong", 1) < 100)
                return notify_fail("�������ڵ��ڹ���Ϊ��ʹ������������衹��\n");   
    if( (int)me->query_skill("tianmo-gun", 1) < 100 ) 
                return notify_fail("���������ħ����δ���ɣ�����ʹ��������裡\n");
    if((int)me->query_skill("club", 1) < 100 )
                return notify_fail("��Ļ�������������죬������ʹ��������衣\n");
    if((int)me->query_dex(1) < 35 )
                return notify_fail("�������������������ʹ��������衣\n");
    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "club"
        || me->query_skill_mapped("club") != "tianmo-gun"
        || me->query_skill_mapped("parry") != "tianmo-gun")
                return notify_fail("������ʹ�����������ô��\n");
                
    if((int)me->query("max_neili") < 1200 )
                return notify_fail("���������Ϊ����������ʹ��������裡\n");
    if((int)me->query("neili") < 800 )
                return notify_fail("�������������㣬����ʹ��������裡\n");

        message_vision(HIW"\n$N������"+weapon->name()+HIW+"һ�����裬��$n����$N���ҹ�֮�У����ܶ�����\n"NOR, me, target);

    me->start_perform(3+random(2),"��������衹");
    i = (int)me->query_skill("tianmo-gun",1);
        me->add("neili", -200);
        me->add_temp("apply/attack",  i/2);
        me->add_temp("apply/damage",  i/2);
        me->set_temp("tmg/lw",1);
if(i>450 ) target->add_busy(2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),(i<450)?1:3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),(i<450)?1:3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        me->add_temp("apply/attack",  -i/2);
        me->add_temp("apply/damage",  -i/2);
        me->delete_temp("tmg/lw");

    return 1;
}

int help(object me)
{
   write(WHT"\n������ħ����"HIW"Ⱥħ����"WHT"����"NOR"\n");
   write(@HELP

   Ҫ��  ������� 1200 ���ϣ�
           ��ǰ���� 800 ���ϣ�
           ������ħ���ȼ� 100 ���ϣ�
           ���Ǵ󷨵ȼ� 100 ���ϣ�
           ������ 35 ���ϣ�
           �����м�Ϊ������ħ����

HELP
   );
   return 1;
}
