// xunlei.c Ѹ�׽�
#include <ansi.h>
//�����б��׿콣---by daidai 2007-06-26
inherit F_SSERVER;
string perform_name(){ return HBMAG"���׿콣"NOR; }
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, attack_time, lvl;
        if( !target ) target = offensive_target(me);
        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) )
                 return notify_fail("�����׿콣��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
         || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if((int)me->query_skill("xunlei-jian",1) < 100 )
            return notify_fail("���Ѹ�׽������������ʹ���������׿콣����\n");
        if((int)me->query_skill("xuantian-wuji",1) < 100 )
                return notify_fail("��������޼������������ʹ���������׿콣����\n");
        if((string)me->query_skill_mapped("sword") != "xunlei-jian" && userp(me))
                return notify_fail("�������޷�ʹ��������У�\n");
        if((string)me->query_skill_mapped("force") != "xuantian-wuji" && userp(me))
                return notify_fail("�㲻�������޼��ڹ�֧�����޷�ʹ��������еģ�\n");
        if((string)me->query_skill_mapped("parry") != "xunlei-jian" && userp(me))
                  return notify_fail("�������޷�ʹ��������У�\n");
        if((int)me->query_temp("xunlei_jian") )
               return notify_fail("�������Ѿ��������ʹ���ˡ�\n");
        if((int)me->query_temp("xunlei") )
        return notify_fail("�������Ѿ��������ʹ�á�Ѹ��ʮ�������ˡ�\n");
        if((int)me->query("max_neili", 1) < 1000 )
               return notify_fail("���������Ϊ����ʹ�á����׿콣����\n");
        if((int)me->query("max_jingli") < 500 )
         return notify_fail("��ľ�����Ϊ����ʹ�á����׿콣����\n");
        if((int)me->query("neili")<500)
                return notify_fail("�������������\n"); 
        attack_time = random((int)me->query_skill("xunlei-jian",1) / 80)+1;
        if(attack_time < 2)
               attack_time = 2;
        if(attack_time > 5)  attack_time = 5;
        msg = HBMAG "$N����"+weapon->name()+HBMAG"�������죬����ָ�죬ͻȻ���ΰθߣ�����$n��Ӧ������������$n��ȥ��\n"NOR;
        message_vision(msg, me, target);
        lvl = ((me->query_skill("xunlei-jian", 1) + me->query_skill("xuantian-wuji", 1)))/ 6;
       me->set_temp("kl/xunlei", 1);
       me->add_temp("apply/sword", lvl);
       me->add_temp("apply/damage", lvl);
       me->add_temp("apply/attack", lvl);
if(!userp(target)) target->start_busy(2);
        for(i = 0; i <= attack_time; i++)
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
       me->delete_temp("kl/xunlei");
if(me->query_skill("xunlei-jian",1) <450)
       me->start_perfrom(attack_time-1,"�����׿콣��");
        me->add("neili", -300);
        me->add("jingli", -80);
        me->set_temp("xunlei_jian", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, target, lvl :),
           random(attack_time)+4);
        return 1;
}
void remove_effect(object me, object target)
{
        int lvl;
        lvl = ((me->query_skill("xunlei-jian", 1) + me->query_skill("xuantian-wuji", 1)))/ 6;
        me->delete_temp("xunlei_jian");
        me->add_temp("apply/sword", -lvl);
        me->add_temp("apply/damage", -lvl);
       me->add_temp("apply/attack", -lvl);
        if (me->is_fighting(target) )
       message_vision(MAG"$N�Ĺ��ƽ�������������$n�����������˿�����\n"NOR,me,target);
}
