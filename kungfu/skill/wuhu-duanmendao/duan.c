#include <ansi.h>
inherit F_SSERVER;

string perform_name() {return HIY"���־�"NOR;}

int perform(object me, object target)
{
    int lvl;
    object weapon; 
    lvl = me->query_skill("wuhu-duanmendao", 1);
    
    if( !target ) target = offensive_target(me);
        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
        return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�ö��־���\n");

    if( (int)me->query_skill("wuhu-duanmendao", 1) < 220 )
        return notify_fail("����廢���ŵ�������죬�޷�ʩչ�����־���\n");

    if (!objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "blade") 
                return notify_fail("�������޵������ʹ�������־�����\n");

    if (me->query_skill_mapped("blade") != "wuhu-duanmendao"
         || me->query_skill_mapped("parry") != "wuhu-duanmendao")
         return notify_fail("�������޷�ʹ�á����־�����\n");  

    if ( (int)me->query("max_neili") < 3000)
        return notify_fail("��������������޷�ʩչ�����־���\n");

    if ( (int)me->query("neili") < 1000)
        return notify_fail("��������������޷�ʩչ�����־���\n");

    if ((int)me->query("jingli") < 1000)
        return notify_fail("��ľ����������޷�ʩչ�����־���\n");

    message_vision(HIY"$N��Ȼ���أ�ʹ���廢���ŵ�"NOR+HIR"���ϡ�"NOR+HIY"�־�����ʱһƬ�׹�ֱ��$n��ȥ��\n"NOR,me, target);
    me->start_perform(2,"�����־���");

if(!userp(target)&& me->query("max_pot",1)<=550) target->start_busy(lvl/50); 

    else if(!random(3))  target->add_busy(lvl/100); 
 
 me->add("neili", -(300 +random(100)) );
 me->add("jingli", -150);

   me->add_temp("apply/attack",lvl/3);
   me->add_temp("apply/damage",lvl/4);

    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), random(2)?1:3);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

    me->start_busy(random(2) + 1);
    me->add_temp("apply/attack", -lvl/3);
    me->add_temp("apply/damage", -lvl/4);
   
    return 1;
}


int help(object me)
{
        write(HIG"\n�廢���ŵ�֮�����־�����"NOR"\n\n");
        write(@HELP
        �廢���ŵ������������������У�����Ѹ�ݣ�
        �����ֽ׶�������ɵ�����æ���ң����߹����ԡ�
        451�������Ǳ��551�㣩�Ժ�����˥����

        Ҫ��  ��ǰ���� 1000 ����;
                ������� 3000 ���ϣ�
                �廢���ŵ��ȼ� 220 ���ϣ�
                ��������Ϊ�廢���ŵ���
                �����м�Ϊ�廢���ŵ���
 
HELP
        );
        return 1;
}

