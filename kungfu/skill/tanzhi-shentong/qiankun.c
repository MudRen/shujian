// ��ָ��֮ͨǬ��һָ, pfm qiankun

inherit F_SSERVER;
#include <ansi.h>

string perform_name(){ return HIG"Ǭ��һָ"NOR; }

int perform(object me, object target)
{
        object weapon;
        string msg;
        int neili, qi, ap, dp;

        if( !target ) 
                target = offensive_target(me);

        if( !objectp(target)
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("��Ǭ��һָ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("bihai-chaosheng", 1) < 150 )
                return notify_fail("��ı̺���������Ϊδ�����޷�ʹ��Ǭ��һָ��\n");

//���书��ֹ����npcʹ��
//Ŀǰ��ҪӦ���ڵ���¥npc��
        if( me->query("quest_cancel"))
            return notify_fail("�㱻��ֹʹ�����ž�����\n");
        if( (int)me->query_skill("suibo-zhuliu", 1) < 150 )
                return notify_fail("����沨������Ϊδ�����޷�ʹ��Ǭ��һָ��\n");

        if( (int)me->query_skill("tanzhi-shentong", 1) < 150 )
                return notify_fail("��ĵ�ָ��ͨ��Ϊδ�����޷�ʹ��Ǭ��һָ��\n");

        if ( me->query_skill_mapped("parry") != "tanzhi-shentong"
        || me->query_skill_mapped("throwing") != "tanzhi-shentong"
        || me->query_skill_mapped("finger") != "tanzhi-shentong"
        || me->query_skill_prepared("finger") != "tanzhi-shentong" )
                return notify_fail("�����ڵ�������޷�ʹ��Ǭ��һָ��\n");

        weapon = me->query_temp("weapon");

        if ( weapon && weapon->query("skill_type") != "throwing")
                return notify_fail("��װ�����������ԡ�\n");

        if( (int)me->query_skill("finger",1) < 120 )
                return notify_fail("���ָ����Ϊ���㣬ʹ����Ǭ��һָ��\n");

        if( (int)me->query("neili") < 3000 )
                return notify_fail("����������̫�������ܳ�Ǭ��һָ��\n");

        if (target->query_temp("thd/qiankun"))
                return notify_fail("���Ѿ���Ǭ��һָ�����ˣ����Ĺ����ɡ�\n");

        neili = target->query("max_neili");
        qi = target->query("max_qi");
        msg = HIG"\n$N��ָһ�죬һ�ɾ�����֮��$nϮȥ��\n"NOR;

        ap = me->query_dex(1) * me->query("combat_exp")/1000;
        dp = target->query_dex(1) * target->query("combat_exp")/1000;

        if ( !userp(target))
                ap += random(ap);

        if ( random(ap) > dp){
                msg += HIR"$n����һָ���ص�������Ѩ�����̴�С�����Ѩ��Ϣ��Ҳ�޷�˳��ͨ�С�\n"NOR;
                me->start_busy(random(2));
                target->add_busy(random(4)+1);
                target->set_temp("thd/qiankun",1);
                target->set("max_qi",qi/2);
                target->set("eff_qi",qi/2);
// set for condition
                target->set("qiankun/qi", qi);
                target->set("qiankun/neili", neili);
                if (target->query("qi")>target->query("eff_qi"))
                        target->set("qi",target->query("eff_qi"));
                target->set("max_neili",neili/2);
                if (target->query("neili") > target->query("max_neili"))
                        target->set("neili",target->query("max_neili"));
                target->apply_condition("qiankun_wound",(int)me->query_skill("finger")/50);
                me->add("neili",-300);
                me->start_perform(3, "Ǭ��һָ");
        }
        else {
                me->start_busy(random(2));
                msg += HIY"$n���ΰ�����$N��ͷһ�㣬����������һ�С�\n"NOR;
                me->add("neili",-150);
                me->start_perform(2, "Ǭ��һָ");
        }
        me->add("jingli", -100);
        message_vision(msg, me, target);
        return 1;
}

int help(object me)
{
        write(HIG"\n��ָ��֮ͨ��Ǭ��һָ����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 3000 ���ϣ�
                �̺������� 150 �����ϣ�
                �沨���� 150 �����ϣ�
                ��ָ��ͨ 150 �����ϣ�
                ����ָ�� 120 �����ϡ�
                ��������Ϊ��ָ��ͨ��
                �����м�Ϊ��ָ��ͨ��
                ����ָ��Ϊ��ָ��ͨ��
                ����ָ��ͨ��
                ���ֻ��ð�����

HELP
        );
        return 1;
}

