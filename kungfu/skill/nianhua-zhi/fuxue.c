// fuxue.c �黨ָ ���黨��Ѩ
// by hunthu //99.01.03
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);

        if( !target
         ||!target->is_character()
         ||!me->is_fighting(target))
           return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if((int)me->query_con() < 25)
           return notify_fail("����ǲ���,����ʹ����һ����!\n");

        if((int)me->query_skill("yijin-jing",1) < 120)
           return notify_fail("���׽�Ĺ�����������ʹ���黨��Ѩ!\n");

        if((int)me->query_skill("nianhua-zhi",1) < 120)
           return notify_fail("���ָ����Ϊ����,Ŀǰ������ʹ���黨��Ѩ����!\n");
        if (me->query_skill_prepared("finger") != "nianhua-zhi"
        || me->query_skill_mapped("finger") != "nianhua-zhi" )
                return notify_fail("��������黨ָ���ܳ����湦�� \n");

        if( me->query_skill_mapped("force") != "yijin-jing" )
                return notify_fail("����ڹ����ԡ�\n");

        if((int)me->query("max_neili")<1000)
           return notify_fail("���������Ϊ��Ƿ���\n");  

        if((int)me->query("neili") < 300)
           return notify_fail("���������ڲ���, ����ʹ���黨��Ѩ! \n");

        if( target->is_busy() )
           return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
        
        msg = HIY "$N��¶����΢Ц����ָ���ᵯ�����ƺ��ڵ��仨���ϵĳ�¶�����µ��𻨰�һ�㣬\n"+
                  "ָ����������,����֮����һ�������������ס��$n��ȫ��ҪѨ, ʹ$n�������á�\n";
        me->start_perform(6,"��Ѩ");    
        if(random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2 ){
           msg +=  HIG"���$p��$P����ҪѨ! \n" NOR;
           target->start_busy( random((int)me->query_skill("nianhua-zhi",1) / 30 + 2));
           if (random(me->query_skill("nianhua-zhi",1))>=150)
           target->apply_condition("fx_busy", random(me->query_skill("finger")/20) + 1 + target->query_condition("fx_busy"));
           me->add("neili",-300);
           me->add("jingli",-100);
        }
        else {
           msg += HIM"����$p���о��������˿�ȥ��$Pһָ����Ǳ����м��š�\n" NOR;
           me->add("neili",-100);
           me->add("jingli",-50);
        me->start_busy(random(2)+2);
        }
        message_vision(msg, me, target);
        return 1;
}
