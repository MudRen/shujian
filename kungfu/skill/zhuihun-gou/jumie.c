//�ı���snowman��sanhuan
//�ı���:caiji
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int i = me->query_skill("zhuihun-gou", 1)/3;
        int j = me->query("jiali")/4 + 10;
        
        if( !target ) target = offensive_target(me);

        if( !target
 || !objectp(target)
        ||  !me->is_fighting(target) 
   || environment(target)!= environment(me))
                return notify_fail("�����ξ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
/*     
   if(me->query_temp("zhuihun/lpf"))
        return notify_fail("������ʹ�á������硹��\n");
*/
        if( (int)me->query_skill("zhuihun-gou", 1) < 100 )
                return notify_fail("���׷�깳����̫ǳ���������ˡ�\n");

        if( (int)me->query_skill("hook", 1) < 100 )
                return notify_fail("��Ļ�����������̫ǳ���������ˡ�\n");

        if( (int)me->query_skill("huagong-dafa", 1) < 100 )
                return notify_fail("����ڹ�����̫ǳ���������ˡ�\n");
                
        if( (int)me->query("max_neili") < 1000 )
                return notify_fail("�������̫ǳ���������ˡ�\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("��������������������ˡ�\n");
        if (me->query_skill_mapped("force") != "huagong-dafa")
                return notify_fail("����ʲôΪ�ڹ�������ʹ�����ξ���?\n");
        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "hook"
            || me->query_skill_mapped("hook") != "zhuihun-gou")
                return notify_fail("��ʹ���ˡ����ξ���ô?\n");
                 
        me->add("neili", -150);
        me->add("jingli", -100);
        me->set_temp("zhuihun/jumie", 4); 
        me->add_temp("apply/attack", i+j);
        me->add_temp("apply/damage", i+j);

if(!userp(target)&& i>=150 ) target->add_busy(2);
        message_vision(GRN "\n$N���һ��������������һ��ʹ��.....\n"NOR,me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        if(me->is_fighting(target)){
        message_vision(YEL "\n$N����һ���������ŷ����ڶ��С����ǡ���\n"NOR,me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        }
        if(me->is_fighting(target)&&(int)me->query_skill("zhuihun-gou", 1) >= 140){
        message_vision(RED "\n$N���һ��������ʽ����꡹����������$n"RED"���ֲ�����\n"NOR,me,target);
        me->add("neili", -50);        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);        
        }
        if(me->is_fighting(target)&&random(me->query("combat_exp"))>target->query("combat_exp")/3
        &&(int)me->query_skill("zhuihun-gou", 1) >= 180){
target->set_temp("must_be_hit",1);
        message_vision(MAG "\n$N���лζ������һʽ�����项���������ǳ���\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);   
target->delete_temp("must_be_hit");
        me->add("neili", -80);
        }
        me->add_temp("apply/attack", -i-j);
        me->add_temp("apply/damage", -i-j);   
        me->start_busy(1);
        me->delete_temp("zhuihun/jumie"); 
        me->start_perform(4, "�����ξ���");
        return 1;
}
