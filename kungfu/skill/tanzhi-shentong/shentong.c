// By Darken@SJ
#include <ansi.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h"

string perform_name() { return HIG"��ͨ����"NOR; }

int perform(object me, object target)
{
        int damage, p;
        object weapon, weapon1;
        string msg, dodge_skill, *limbs, limb;
        
        if( !target ) target = offensive_target(me);

    if( !objectp(target)  || !target->is_character() || !me->is_fighting(target) 
         || environment(target)!=environment(me))
                return notify_fail("��ָ��ֻͨ�ܶ�ս���еĶ���ʹ�á�\n");
        if( (int)me->query_skill("tanzhi-shentong", 1) < 150 )
                return notify_fail("��ĵ�ָ��ͨ��δ�����ʹ��������ָ��ͨ��\n");
        if( (int)me->query_skill("bihai-chaosheng", 1) < 150)
                return notify_fail("��ı̺���������δ�����\n");     
        if( (int)me->query_skill("throwing", 1) < 150 )
                return notify_fail("��Ļ���������δ�����ʹ��������ָ��ͨ��\n");
        if( (int)me->query("max_neili", 1) < 2000 )
                return notify_fail("����ڹ���Ϊ������ʹ����ָ��ͨ������\n");
        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("�������������ʹ����ָ��ͨ������\n");
        if(target->is_busy())     
                return notify_fail("�Է����Թ˲�Ͼ�أ��ŵ������ɡ�\n");
        if (!objectp(weapon = me->query_temp("weapon")) 
        && (int)me->query_skill("tanzhi-shentong", 1) < 160)
                return notify_fail("�������޷�ʹ�õ�ָ��ͨ��\n");
        if(weapon && (weapon->query("skill_type") != "throwing"
        || me->query_skill_mapped("throwing") != "tanzhi-shentong"))
                return notify_fail("�����ڵ������޷�ʹ�õ�ָ��ͨ��\n");
        if(weapon){
                if(weapon->query("skill_type") != "throwing" || me->query_skill_mapped("throwing") != "tanzhi-shentong")
                         return notify_fail("�����ڵ������޷�ʹ�õ�ָ��ͨ��\n");
                msg = HIW"\nֻ��$N"HIW"˫��΢�Σ�������ָ����"+weapon->name()+HIW+"����һ�������$P���������ֱ��$n"HIW"��ȥ��\n"NOR; 
                }
        else msg = GRN"\n$N"GRN"�����ھ���ָ����׼�������$n"GRN"һ����һ˿�����������������$p��ǰ��Ѩ��\n"NOR; 
        
        me->add("neili", -350);
        me->start_perform(2, "��ͨ����");
        limbs = target->query("limbs");
        limb = limbs[random(sizeof(limbs))];
        
        if( random((int)me->query_dex()) < (int)target->query_dex()/2) {
                dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        } else if (weapon && objectp( weapon1 = target->query_temp("weapon")) && random(2)==1) {
                if( random((int)me->query_dex()) > (int)target->query_dex()/2 ){
                         weapon1->unequip();
                         weapon1->move(environment(target));
                         target->reset_action();
                         if(!target->is_busy()) target->start_busy(2);
                         msg += HIR"$n"HIR"ֻ�����ֱ�һ�飬�ѱ�$N"HIR"��"+weapon->name()+HIR+"������Ѩ�������������ذ����е�"+weapon1->name()+HIR+"׹�أ�\n"NOR;
                         target->start_busy(1);
                } else {
                         dodge_skill = target->query_skill_mapped("dodge");
                         if( !dodge_skill ) dodge_skill = "dodge";
                         msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                }
        } else {
                damage = me->query_skill("finger") + me->query_skill("throwing") + me->query_temp("thd/is_fast");
                if(me->query("neili") > target->query("neili")*2)
                         damage *= 2;
                target->receive_damage("qi", damage, me);
                if(weapon)
                         target->receive_wound("qi", damage/2+random(damage/2), me);
                if(!target->is_busy()) 
                         target->start_busy(2+random(2));
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n" + eff_status_msg(p) + " )\n";
                msg = replace_string(msg, "$l", limb);
                msg = replace_string(msg, "$w", weapon?weapon->name():"���ν���"); 
        }
        message_vision(msg, me, target);
        return 1;
}

int help(object me)
{
        write(HIG"\n����ͨ��������"NOR"\n");
        write(@HELP

        ʩչ��ָ��ͨ��������ϣ����̺����������ھ�������ͬһ��ϸ����������
        ���ǽ��������ӽ�����������˺�����֮���ʹ����Ѫ���ڣ�������������
        ����Ҳ�п����޷�ʹ�������䡣

        Ҫ��  �̺������ȼ� 150 ���ϣ�
                ��ָ��ͨ�ȼ� 150 ���ϣ�
                ����ָ���ȼ� 150 ���ϣ�
                ���������ȼ� 150 ���ϣ�
                ������� 2000 ���ϣ�
                ���������תʹ�ù����˺����ӣ�
                ����ϰ���ʹ�á�
HELP
        );
        return 1;
}

