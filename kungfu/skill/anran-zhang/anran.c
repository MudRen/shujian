// ��Ȼ����
// By River 
#include <ansi.h>
#include <combat.h> 

inherit F_SSERVER;
int perform(object me, object target)
{
        int lvl, i;

        lvl = me->query_skill("anran-zhang", 1) *2;

        if( !target ) target = offensive_target(me);

        if( !target 
         || !me->is_fighting(target) )
                return notify_fail("����Ȼ���꡹ֻ����ս����ʹ�á�\n");

        if( me->query_temp("weapon"))
                return notify_fail("������������ô��ʹ�á���Ȼ���꡹��\n");   

        if( (int)me->query_skill("anran-zhang", 1) < 150 )
                return notify_fail("�����Ȼ�����ƻ�������죬ʹ��������Ȼ���꡹������\n");

        if( (int)me->query_skill("yunu-xinjing", 1) < 150 )
                return notify_fail("�����Ů�ľ��ȼ���������ʹ��������Ȼ���꡹������\n");

        if ( me->query_skill_mapped("strike") != "anran-zhang"
         || me->query_skill_mapped("parry") != "anran-zhang"
          || me->query_skill_prepared("strike") != "anran-zhang"
          || me->query_skill_mapped("force") != "yunu-xinjing")
                return notify_fail("�������޷�ʹ�á���Ȼ���꡹������!!!!!!!!!!!!\n");

        if((int)me->query_temp("xinjing")) 
                return notify_fail("������ʹ�á��ľ����־���\n");

        if((int)me->query("max_neili") < (me->query_skill("force")+lvl+100) )
                return notify_fail("����������̫����ʹ��������Ȼ���꡹��\n");      

        if((int)me->query("neili") < (me->query_skill("force")+lvl) )
                return notify_fail("����������̫����ʹ��������Ȼ���꡹������\n");

        if((int)me->query("eff_qi") >= (int)me->query("max_qi"))
                return notify_fail("����������ܺã���ôʹ�ó�����Ȼ���꡹������\n");

        if((int)me->query_temp("xiaohun")) 
                return notify_fail("����������ʹ�á����꡹������\n"); 

        if((int)me->query("qi") == 0 )
                return notify_fail("�������޷�ʹ�á���Ȼ���꡹������\n");

        me->add_temp("anran", 2);
        i = (int)me->query("max_qi") / (int)me->query("eff_qi");

        if( i > 3 ) i = 3;
        if( i < 1 ) i = 1;

        if( i > 1 ){
           me->add_temp("apply/strength",lvl/3);
           me->set_temp("hurt", 1);
        } 
        
        me->add_temp("apply/damage", lvl/2);
        me->add_temp("apply/strike", lvl);
        target->set_temp("must_be_hit",1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), i);
        if (present(target,environment(me)) && me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), i);

        me->add_temp("apply/damage", -lvl/2);
        me->add_temp("apply/strike", -lvl);

        if(me->query_temp("hurt")){
           me->add_temp("apply/strength",-lvl/3);
            me->delete_temp("hurt");
        }
        me->add("neili", -(me->query_skill("force") + random(lvl)));
        me->add("jingli", -50);
        me->delete_temp("anran");
        me->start_perform(5,"��Ȼ����");
         target->delete_temp("must_be_hit");
        me->start_busy(1+random(2));
        return 1;
}
string perform_name(){ return HIB"��Ȼ"NOR; }
int help(object me)
{
         write(HIB"\n��Ȼ�����ơ���Ȼ����"NOR"\n");
        write(@HELP
����Ժ�С��Ů�ھ���ȶϳ���ǰ���֣�������ҹ˼������С��Ů��
��������������������Ȥ�����ں���֮�п��������������һʮ����
�Ʒ������������Ʒ�����Ϊ��Ȼ�����ƣ�ȡ���ǽ��͡��𸳡����Ǿ�
��Ȼ�����ߣ�Ψ�������֮�⡣���Ʒ�������������������壬��һ
������ۺ�������Խ������Խ��,ʵ�������ض��ú���!

Ҫ��
        ��Ů�ľ���150
        ��Ȼ�����ƣ�150
HELP
        );
        return 1;
}
