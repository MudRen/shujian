// By Darken@SJ
// Modified by Numa@Sj 99-11-12 2:46
// Modified by Darken@SJ

inherit F_SSERVER;
#include <ansi.h>
#include <combat_msg.h>

string perform_name() { return HIG"��Ӣ������"NOR; }

int perform(object me, object target)
{
        int damage, p;
        string msg;
        
        if (!target) target = offensive_target(me);
        if (!objectp(target)) return notify_fail("������˭��\n");
        if (wiz_level(me) < wiz_level(target))
                return notify_fail("�㲻�ܹ�����ʦ�ȼ�����ߵĶ��֡�\n");
        if (target == me)
                return notify_fail("�� suicide -f ָ���ȽϿ�Щ��\n");
         if( target->is_corpse() ) 
                return notify_fail("�и��ԣ���ʬ�塣\n");
        if (!target || !target->is_character())
                return notify_fail("���빥��˭��\n");
        if (me->query_temp("weapon"))
                return notify_fail("������������ô��ʹ�������ƣ�\n");   
        if (environment(me)->query("no_fight") )
                return notify_fail("���ﲻ��ս����\n");
        if ((int)me->query_dex() < 50)
                return notify_fail("������������޷���������ơ�\n");
        if ((int)me->query_skill("bihai-chaosheng", 1) < 200 )
                return notify_fail("��ı̺���������Ϊδ�����޷���������ơ�\n");
        if ((int)me->query_skill("luoying-zhang",1) < 200 )
                return notify_fail("����Ʒ���Ϊ���㣬ʹ���������ơ�\n");
        if ((int)me->query("max_neili") < 5000)
                return notify_fail("����������̫�������ܴ�������ơ�\n");
        if ((int)me->query("jiali") < 100)
                return notify_fail("�����ڼ���̫�������ܴ�������ơ�\n");
        if (me->query_skill_prepared("strike") != "luoying-zhang" || me->query_skill_mapped("strike") != "luoying-zhang")
                return notify_fail("��׼���ļ��ɲ��ԣ�\n");
        if (me->query_skill_mapped("force") != "bihai-chaosheng")
                return notify_fail("�㼤�����ڹ����ԣ�\n");
     if( me->query("no_pk") && userp(target) && (!me->query_temp("xyjob") || !target->query_temp("xyjob")))
     return notify_fail("���Ѿ��˳���������������ʵʵ�İɡ�\n");

     if( target->query("no_pk") && userp(me) && (!me->query_temp("xyjob") || !target->query_temp("xyjob")))
     return notify_fail( target->name()+"�Ѿ��˳������ˣ������˴������˰ɣ�\n");
if (userp(target) && userp(me) && me->query("combat_exp")<  target->query("combat_exp") * 2 /3 &&  !target->query_condition("killer") && !target->is_killing(me->query("id")) ) 
                 return notify_fail("�˼ұ���ǿ��ô�࣬��Ͳ����˼ұ�����\n");

if (userp(target) && userp(me) && me->query("combat_exp") > target->query("combat_exp") * 3 / 2 &&  !target->query_condition("killer") && !target->is_killing(me->query("id"))) 
                 return notify_fail("����˼�ǿ��ô�࣬����СϺ��Ҳֵ���㶯�֣�\n");

        me->start_perform(3,"������");
        msg = HIB "\n$N��Хһ����һʽ��������$n��������Ӣ���Ʒ�Ю����������ӿ�ı̺���������ӵ�����������ⲻ�ɵ���\n"NOR;
        if (random(me->query_dex()) > target->query_dex()/2)
        {
                me->start_busy(1);
                target->start_busy(1+random(3));
                damage = (int)me->query_skill("force") + (int)me->query_skill("strike") + me->query("jiali")*5;
                if (damage > 1500 + me->query("thd/is_fast")*3) damage = 1500 + me->query("thd/is_fast")*3;
                if (target->query("neili") < me->query("neili")) damage *= 2;
                if (me->is_fighting()) damage *= 3/4;
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/2, me);
                me->add("neili", -damage/2);
                if (me->query("neili") < 0) me->set("neili",0);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += HIG"$n���ؿ���ͬ�ܵ�һ���ش������е�ʱ��Ѫ���硣\n"NOR;
                msg += "( $n"+eff_status_msg(p)+" )\n"; 
                me->kill_ob(target);
        }
        else {
                msg += CYN"$n���������ң���æ����һ�ã�$N��һ�Ʊ㼴��ա�\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

int help(object me)
{
        write(HIG"\n����Ӣ�����ơ���"NOR"\n");
        write(@HELP

        �����������һ������⼼���У�Ψһ����ǿ���ھ���ֱ�Ӵ������춴˾�ȫ
        ������ڹ�֧�����ﵽԶ���빥����Ч��������������ļ���ͬʱ����ʱ
        �ļ������Ҳ��ΪЧ���Ĺؼ���

        Ҫ��  �̺��������ȼ� 200 ���ϣ�
                ��Ӣ���Ƶȼ� 200 ���ϣ�
                ������ 50 ���ϣ�
                ������� 5000 ���ϣ�
                ��ս����ʹ��ʱ�����½���
                ������������ʱ����������
                ���������תʹ��ʱ����������
HELP
        );
        return 1;
}

