//By lsxk@hsbbs 2007/10/19
//Ⱥħ����

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

string perform_name(){ return HIB"Ⱥħ"HIR"����"NOR; }

int perform(object me,object target)
{
    object weapon;
    int i;
    
    if( !target ) target = offensive_target(me);
     
    if( !objectp (target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("Ⱥħ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if(me->query_skill_mapped("force") != "huagong-dafa")
                return notify_fail("����ڹ����ǻ����󷢣��޷�ʹ��Ⱥħ���裡\n");
    if( (int)me->query_skill("huagong-dafa", 1) < 250 )
                return notify_fail("����ڹ���δ���ɣ�����ʹ��Ⱥħ���裡\n");
    if( (int)me->query_skill("tianshan-zhang", 1) < 250 ) 
                return notify_fail("�����ɽ�ȷ���δ���ɣ�����ʹ��Ⱥħ���裡\n");
    if((int)me->query_skill("staff", 1) < 250 )
                return notify_fail("��Ļ����ȷ�������죬������ʹ�������޹���\n");
    if((int)me->query_skill("poison", 1) < 180 )
                return notify_fail("��Ķ���������죬������ʹ��Ⱥħ���衣\n");
    if((int)me->query_dex(1) < 41 )
                return notify_fail("��������������ɣ�����ʹ��Ⱥħ���衣\n");
    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "staff"
        || me->query_skill_mapped("staff") != "tianshan-zhang"
        || me->query_skill_mapped("parry") != "tianshan-zhang")
                return notify_fail("������ʹ����Ⱥħ����ô��\n");
                
    if((int)me->query("max_neili") < 4500 )
                return notify_fail("���������Ϊ����������ʹ��Ⱥħ���裡\n");
    if((int)me->query("neili") < 2000 )
                return notify_fail("�������������㣬����ʹ��Ⱥħ���裡\n");

        message_vision(HIB"\n$NͻȻһ���ֽУ��Ų�Ʈ��������˲����Ȼ��$n�ӳ����У���������֮����\n"NOR,me,target);

    me->start_perform(3+random(2),"��Ⱥħ���衹");
    i = (int)me->query_skill("tianshan-zhang",1);
        me->add("neili", -300);
        me->add_temp("apply/attack",  i);
        me->add_temp("apply/damage",  i/2);
        me->set_temp("tsz/lw",1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),(i<450)?1:3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),(i<450)?1:3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        me->add_temp("apply/attack",  -i);
        me->add_temp("apply/damage",  -i/2);
        me->delete_temp("tsz/lw");

    me->start_busy(1);
    target->start_busy(1);
    return 1;
}

int help(object me)
{
   write(WHT"\n��ɽ�ȷ���"HIB"Ⱥħ"HIR"����"WHT"����"NOR"\n");
   write(@HELP

   Ҫ��  ������� 4500 ���ϣ�
           ���� 2000 ���ϣ�
           ��ɽ�ȷ��ȼ� 250 ���ϣ�
           �����󷨵ȼ� 250 ���ϣ�
           ������ 41 ���ϣ�
           �����ȼ� 180 ���ϣ�
           �����м�Ϊ��ɽ�ȷ���

HELP
   );
   return 1;
}
