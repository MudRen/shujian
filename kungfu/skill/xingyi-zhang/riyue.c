// riyue ����ͬ��
// by leontt
// Modify by leontt 1/05/2000
// By Spiderii fix bug

#include <ansi.h>
#include <combat.h>

string perform_name(){ return CYN"����ͬ��"NOR; }

inherit F_SSERVER;
int perform(object me, object target)
{
        int i;

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("������ͬ�ԡ�ֻ����ս����ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("ʹ�á�����ͬ�ԡ�ʱ������֣�\n");
        
        if( (int)me->query_skill("xingyi-zhang", 1) < 140 )
                return notify_fail("��������Ʋ�����죬ʹ����������ͬ�ԡ�������\n");

        if( (int)me->query_skill("shenyuan-gong", 1) < 140 )
                return notify_fail("�����Ԫ���ȼ�����������ʹ�á�����ͬ�ԡ���\n");

        if (me->query_skill_mapped("force") != "shenyuan-gong")
                return notify_fail("��Ŀǰ���ڹ��޷�֧����ʹ�á�����ͬ�ԡ����й�����\n");  
                        
        if( (int)me->query_int() < 30 )
                return notify_fail("������Ի�ʹ����������ͬ�ԡ�������\n");

        if (me->query_skill_prepared("strike") != "xingyi-zhang"
         || me->query_skill_mapped("strike") != "xingyi-zhang")
                return notify_fail("�������޷�ʹ�á�����ͬ�ԡ����й�����\n");  
                                                                                               
        if( (int)me->query("max_neili") < 1200 )
                return notify_fail("������������Ϊ̫��������ʹ�á�����ͬ�ԡ���\n");

        if( (int)me->query("neili") < 800 )
                return notify_fail("��Ŀǰ����̫�٣�����ʹ�á�����ͬ�ԡ���\n");

        if( (int)me->query("jingli") < 200 )
                return notify_fail("�����ھ���̫�٣�����ʹ�á�����ͬ�ԡ���\n");

        if( me->query_temp("mr_riyue") || me->query_temp("mr_riyue_next"))
                return notify_fail("���ʹ�꡸����ͬ�ԡ���������ת�������޷��ٴ�ʹ�ã�\n");
                
        tell_object(me,CYN"\n��˫��һ�꣬��˫��֮���γ�һ��ҫ�۵ġ�"HIW"����"CYN"����\n" NOR,me, target);
        
        i = (int)me->query_skill("xingyi-zhang", 1);

        me->add_temp("apply/attack", i/5);
        me->add_temp("apply/strike", i/5);
        me->add_temp("apply/strength",i/15);
        me->set_temp("mr_riyue", 4);
        
        COMBAT_D->do_attack(me, target, 0, 3);
        me->add("neili", -100);
        if(me->is_fighting(target)){
                COMBAT_D->do_attack(me, target, 0, 3);
                me->add("neili", -100);
        }
        if(me->is_fighting(target) && me->query_skill("xingyi-zhang", 1) >= 150){
                COMBAT_D->do_attack(me, target, 0, 3);
                me->add("neili", -100);
        }
       if(me->is_fighting(target) && me->query_skill("xingyi-zhang", 1) >= 200){
                COMBAT_D->do_attack(me, target, 0, 3);
                me->add("neili", -100);
        }
                  
        message_vision(YEL "\n$Nһʽ������ͬ�ԡ����ӵ����쾡�£�˫��һ�֣��������У����ı�����\n" NOR,me, target);
        me->add_temp("apply/attack", -i/5);
        me->add_temp("apply/strike", -i/5);
        me->add_temp("apply/strength",-i/15);
        me->delete_temp("mr_riyue");
        me->start_busy(1+random(2));
        me->start_perform( 4,"������ͬ�ԡ�");
        me->set_temp("mr_riyue_next", 1); 
        me->add("jingli", -100);
        me->add("neili", -200);
        if(me->query("neili") < 0) me->set("neili", 0);
        i = (int)me->query_skill("strike")/30;
        if( i > 10 ) i = 10;
        if( i < 4 ) i = 4;
        call_out("remove_effect", i, me);   
        return 1;
}

void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("mr_riyue_next"); 
        tell_object(me, HIW"\n���ϢƬ�̣����������ָ��˲��٣��ֿ���ʹ�á�����ͬ�ԡ��ˡ�\n"NOR); 
}

