// ɳ�����󽣷� ԽŮ�״�
// by Jpei@NT 2009/05

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

string perform_name() {return HIY"��������"NOR;}

int perform(object me,object target)
{
    object weapon;
    
    if( !target ) target = offensive_target(me);
     
    if(!objectp(target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if( (int)me->query_skill("yuenu-jian", 1) < 220 )
                return notify_fail("��Ľ�����δ���ɣ�����ʹ����������������\n");
    if((int)me->query_skill("sword", 1) < 160 )
                return notify_fail("��Ļ�������������죬����ʹ������������\n");
    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "yuenu-jian")
                return notify_fail("�������޽������ʹ������������\n");
                
    if((int)me->query("max_neili") < 1500 )
                return notify_fail("���������Ϊ����������ʹ������������\n");
    if((int)me->query("neili") < 1000 )
                return notify_fail("�������������㣬����ʹ������������\n");
        message_vision(HIY"\n$N���к������ұ�׳֮�⣬�������������ã����н��ǽ������ţ�����ȴ�Ǽ��󣬽�������$n����֮��������ԽŮ����֮������������"HIY"��\n"NOR, me,target);
    me->start_perform(3,"������������");
    me->set_temp("ynj/6j",1);
     me->add("neili", -500);
 me->add_temp("apply/strength",  me->query_skill("yuenu-jian", 1)*2/5);
 me->add_temp("apply/attack",  me->query_skill("yuenu-jian", 1)*1/5);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
 //   if (me->is_fighting(target))
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
//    if (me->is_fighting(target))
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
//    if (me->is_fighting(target))
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
//    if (me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
//    if (me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    me->delete_temp("ynj/6j");
 me->add_temp("apply/strength", - me->query_skill("yuenu-jian", 1)*2/5);
 me->add_temp("apply/attack", - me->query_skill("yuenu-jian", 1)*1/5);
    target->start_busy(1);
    return 1;
}

int help(object me)
{
   write(WHT"\nԽŮ����"HIY"��������"WHT"����"NOR"\n");
   write(@HELP
    ԽŮ���������������������������ã����н��ǽ������ţ�ȴ����ָ������֮�����������ҡ�
HELP
   );
   return 1;
}
