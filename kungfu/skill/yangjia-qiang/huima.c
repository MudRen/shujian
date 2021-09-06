//  huima.c ����ǹ 
//Created by Redhat@Sjmud 2009/4/7

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

string perform_name() {return WHT"����ǹ"NOR;}

int perform(object me,object target)
{
    object weapon;
    int i;
    i = me->query_skill("yangjia-qiang", 1) /3;
    if( !target ) target = offensive_target(me);
     
    if(!objectp(target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("������ǹ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if((int)me->query_skill("force", 1) < 250 )
                return notify_fail("��Ļ����ڹ�������죬�޷�֧�֡�����ǹ����\n");

    if( (int)me->query_skill("yangjia-qiang", 1) < 250 ) 
                return notify_fail("���ǹ����δ���ɣ�����ʹ�á�����ǹ����\n");

    if((int)me->query_skill("spear", 1) < 250 )
                return notify_fail("��Ļ���ǹ��������죬�����ڽ�����ʹ�á�����ǹ����\n");

    if((int)me->query_skill("dodge", 1) < 250 )
                return notify_fail("��Ļ����Ṧ������죬����ʹ�á�����ǹ����\n");

    if (!objectp(weapon = me->query_temp("weapon")) 
        || weapon->query("skill_type") != "spear"
        || me->query_skill_mapped("spear") != "yangjia-qiang"
        || me->query_skill_mapped("parry") != "yangjia-qiang")
                return notify_fail("��������ǹ�����ʹ�á�����ǹ����\n");
                
    if((int)me->query("max_neili") < 8000 )
                return notify_fail("���������Ϊ����������ʹ�á�����ǹ����\n");

    if((int)me->query("neili") < 3000 )
                return notify_fail("�������������㣬����ʹ�á�����ǹ����\n");

    if((int)me->query("jingli") < 1000 )
                return notify_fail("������̫���ˣ�����ʹ�á�����ǹ����\n");
      
message_vision(HIB"\n$N��Ȼ����Ծ�𣬾�ʹ�����ǹ֮"YEL"������ǹ��"HIB"������ֻ��ǹ�浽���ŷ���һ�����У�������֮�˵����ľ���\n"NOR, me,target);

    me->start_perform(3,"������ǹ��");
    me->add("neili", -800);
    me->add("jingli",-500);
    me->set_temp("yjq/huima",1);

    me->add_temp("apply/attack", i);
    me->add_temp("apply/damage",i);
    
	target->set_temp("must_be_hit",1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
   target->delete_temp("must_be_hit");
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
   
   me->add_temp("apply/damage", -i);
   me->add_temp("apply/attack", -i);
    me->delete_temp("yjq/huima");
    me->start_busy(1);
    target->start_busy(1);
    return 1;
}

int help(object me)
{
   write(YEL"\n���ǹ��"HIG"����ǹ"YEL"����"NOR"\n");
   write(@HELP
   ָ�perform huima

   Ҫ�����ǹ250����
         ����ǹ��250����
         ������� 8000 ���ϣ�
         ��ǰ���� 3000 ���ϣ�
         ��ǰ���� 1000 ���ϣ�
         �������ǹΪ�мܡ�
HELP
   );
   return 1;
}
