#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
int skill,tg_skill,time;
string msg;
if( !target ) target = offensive_target(me);

        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

if( (int)me->query_skill("wudu-yanluobu", 1) < 250 )
return notify_fail("����嶾���ܲ���򲻹�������ʹ��������������\n");
if( (int)me->query("neili", 1) < 500 )
return notify_fail("����������̫��������ʹ�á�����������\n");
if( target->is_busy() )
return notify_fail(target->name() + "Ŀǰ����æ���ң��㻹��תʲô���Ͽ�����ɣ�\n");
msg = HIC "$N���к���һ�䣬ʹ�������������ľ�������Խ��Խ�졣ֻ��$N�ɿ���Ƴ����ߣ�հ֮��ǰ����֮�ں�һʱ�䵽������$N����Ӱ��\n"NOR;
message_vision(msg, me, target);
time = (int)me->query_skill("wudu-yanluobu",1)/100;
skill = (int)me->query_skill("wudu-yanluobu",1);
 tg_skill = (int)target->query_skill("dodge",1);
me->add("neili", -100);
 if (random(skill) > random(tg_skill) || !userp(target))
{
target->start_busy(random(time)+1);
msg = HIR"$n���ɵ�һ�������޴룬��$N�������У�\n"NOR;
message_vision(msg, me, target);
return 1;
}
else
{
me->start_busy(3);
msg = HIR"����$n�Ծ��ƶ��������Ż���˿������$N��Ӱ��,$N�Լ����۵���ͷ�󺹣�\n"NOR;
message_vision(msg, me, target);
     me->start_perform(5,"����������");

}


return 1;
}
string perform_name(){ return HIC"��������"NOR; }
int help(object me)
{
        write(HIY"\n�嶾����֮����������:"NOR"\n\n");
        write(@HELP
        �嶾�̳��ϼ�����ſ���ϰ���ؼ�����������ɾ���ѩ��
        �Ժκ�ҩ��ϰ�ã����Ϊ��������ֵľ���֮һ����˵��
        ��Ҫ��ܸߡ�

HELP
);
return 1;
}
