//��������
//����new systemҪ��������ΪA+
#include <ansi.h>
#include <combat.h> 

inherit F_SSERVER;

string perform_name() {return HIY"��������"NOR;}

int perform(object me, object target)
{
          int lvl;

              lvl = me->query_skill("anran-zhang", 1)/8 ;
	 if (me->query("gender")=="Ů��") lvl/=2;

        if( !target ) target = offensive_target(me);

        if( !target 
         || !me->is_fighting(target) )
                return notify_fail("���������ס�ֻ����ս����ʹ�á�\n");

        if( me->query_temp("weapon"))
                return notify_fail("������������ô��ʹ�á��������ס���\n");   

        if( (int)me->query_skill("anran-zhang", 1) < 150 )
                return notify_fail("�����Ȼ�����ƻ�������죬ʹ�������������ס�������\n");

        if( (int)me->query_skill("yunu-xinjing", 1) < 150 )
                return notify_fail("�����Ů�ľ��ȼ���������ʹ�������������ס�������\n");

        if ( me->query_skill_mapped("strike") != "anran-zhang"
         || me->query_skill_mapped("parry") != "anran-zhang"
          || me->query_skill_mapped("parry") != "anran-zhang"
          || me->query_skill_mapped("force") != "yunu-xinjing")
                return notify_fail("�������޷�ʹ�á��������ס�������\n");

        if((int)me->query_temp("xinjing")) 
                return notify_fail("������ʹ�á��ľ����־���\n");

        if((int)me->query("max_neili") < (me->query_skill("force")+lvl+100) )
                return notify_fail("����������̫����ʹ�������������ס���\n");      

        if((int)me->query("neili") < (me->query_skill("force")+lvl) )
                return notify_fail("����������̫����ʹ�������������ס�������\n");

/*
        if((int)me->query_temp("xiaohun")) 
                return notify_fail("����������ʹ�á����꡹������\n"); 
*/

        if((int)me->query("eff_qi") == 0 )
                return notify_fail("�������޷�ʹ�á��������ס�������\n");

        me->set_temp("jishi", 2); //������1����Ȼ��ʱ��Ϊ2�ɲ�Ȼ�ڶ���û��ɫ---daidai


           message_vision(HIY"\n$NͻȻһ�����ӿ����ͷ���������������Ȼ����������\n"NOR,me,target);
        me->add_temp("apply/damage", lvl/2);
        me->add_temp("apply/attack", lvl);

          COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        if (present(target,environment(me)) && me->is_fighting(target))
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

        me->add_temp("apply/damage", -lvl/2);
        me->add_temp("apply/attack", -lvl);

        me->add("neili", -(me->query_skill("force") + random(lvl)));
        me->add("jingli", -50);
        me->delete_temp("jishi");
          me->start_perform(4,"��������");
        target->start_busy(1);
       me->start_busy(1+random(2));
        return 1;
}

