#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��ڤ˫��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("xuanming-shenzhang", 1) < 200 )
                return notify_fail("�����ڤ���Ʋ�����죬�޷�ʹ����ڤ˫�ơ�\n");
        if( (int)me->query_skill("force") < 350 )
                return notify_fail("����ڹ�������죬�޷�ʹ����ڤ˫�ơ�\n");

        if ( (int)me->query("max_neili") < 4000)
                return notify_fail("��������������޷�ʹ����ڤ˫�ơ�\n");

        if ( (int)me->query("neili") < 7000)
                return notify_fail("��������������޷�ʹ����ڤ˫�ơ�\n");
             if(me->query("jingli")<3000)
                  return notify_fail("��ľ����������޷�ʹ����ڤ˫�ơ�\n");
           if(me->query_skill_mapped("parry")!="xuanming-shenzhang"
         ||me->query_skill_mapped("strike")!="xuanming-shenzhang"
         ||me->query_skill_prepared("strike")!="xuanming-shenzhang")
                 return notify_fail("�㲢û��׼����ʹ�á���ڤ˫�ơ�\n");

        msg = HIY"$Nһ�ƻ���$n����һ��ȴ������Ϣ������$n�ĵ��\n";
        if( random(me->query_dex()) > (int)target->query_dex()/2 ) {
                msg += HIR"$n�������������е��$n�ƺ�һ�����ƺ����˼��ص����ˣ�������ʧ���࣡\n"NOR;
                target->add("max_neili",-(random(me->query_skill("xuanming-shenzhang",1)/50)+1));
                if (random(2)) {
                  target->set_skill("force", target->query_skill("force",1)-1);
                  msg += HBRED"$n���ڹ�Ҳ�ܵ��˼�����˺���\n"NOR;
                }
                target->set("neili",0);
                target->set("jiali",0);
                target->apply_condition("xuanmin_poison", 50+random(30));
                me->add("neili", -1500-random(1000));
                me->add("jingli", -1500-random(1000));
        } 
        else {
                msg += HIG"$n��æ���֣����Ծ����\n" NOR;
        }
        message_vision(msg, me, target);
        me->start_busy(1+random(2));
        me->start_perform((4+random(2)), "��ڤ˫��");
        return 1;
}


