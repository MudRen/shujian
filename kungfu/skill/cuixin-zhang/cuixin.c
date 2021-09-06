inherit F_SSERVER;
#include <ansi.h>
#include <combat_msg.h>

int perform(object me, object target)
{
	int damage, p;
	string msg;
        
	if( !target ) target = offensive_target(me);

	if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���Ķϳ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( !target->is_busy())
		return notify_fail("���Ķϳ�ֻ�ܶ�æ���еĶ���ʹ�á�\n");

	if( me->query_temp("weapon"))
		return notify_fail("������������\n");   

	if( (int)me->query_skill("cuixin-zhang",1) < 180 )
		return notify_fail("����Ʒ���Ϊ���㣬ʹ�������Ķϳ���\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("����������̫�������ܴ�����Ķϳ���\n");

	if( (int)me->query("jiali") < 100 )
		return notify_fail("�����ڼ���̫�������ܴ�����Ķϳ���\n");

	if (me->query_skill_prepared("strike") != "cuixin-zhang"
	|| me->query_skill_mapped("parry") != "cuixin-zhang")
		return notify_fail("�������޷�ʹ�ô��Ķϳ���\n");
                
	msg = HIR"\n$N����$n��æ����֮ʱ��ʹ�������Ķϳ�����\n"NOR;
	damage = me->query_skill("strike");
	damage += random(me->query("jiali") * 3);
	damage *= 2;

	if(target->query("neili") < me->query("neili")) damage *= 2;

	if (damage > 2000) damage = 2000+random(500);  

	target->receive_damage("qi", damage, me);
	target->receive_wound("qi", damage/2, me);
	p = (int)target->query("qi")*100/(int)target->query("max_qi");
	msg += "������صĴ���$n���ؿڣ�$n��ʱ��Ѫ���硣\n";
	msg += "( $n"+eff_status_msg(p)+" )\n"; 
        message_vision(msg, me, target);
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+ damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+ damage+ WHT"���˺���\n"NOR); ;
	me->add("neili", -350);
	me->add("jingli", -150);
	me->start_busy(random(2));
	me->start_perform(3,"���Ķϳ�");
	return 1;
}

string perform_name(){ return HIR"���Ķϳ�"NOR; }

int help(object me)
{
        write(HIR"\n������֮�����Ķϳ�����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1000 ���ϣ�
                ������� 1500 ���ϣ�
                ��ǰ���� 1000 ���ϣ�
                �����Ƶȼ� 180 ���ϣ�
                �����Ʒ�Ϊ�����ƣ�
                �����м�Ϊ�����ƣ�
                ���Ʒ�Ϊ�����ƣ�
                �����ޱ�����

HELP
        );
        return 1;
}
