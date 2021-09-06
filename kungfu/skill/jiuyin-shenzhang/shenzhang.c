inherit F_SSERVER;
#include <ansi.h>
#include <combat_msg.h>

int perform(object me, object target)
{
	int damage, p;
	string msg;
        
	if( !target ) target = offensive_target(me);

	if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���ƶ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( !target->is_busy())
		return notify_fail("���ƶ������ܶ�æ���еĶ���ʹ�á�\n");

	if( me->query_temp("weapon"))
		return notify_fail("������������\n");   

	if( (int)me->query_skill("jiuyin-shenzhang",1) < 180 )
		return notify_fail("����Ʒ���Ϊ���㣬ʹ�������ƶ��ǡ�\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("����������̫�������ܴ�����ƶ��ǡ�\n");

	if( (int)me->query("jiali") < 100 )
		return notify_fail("�����ڼ���̫�������ܴ�����ƶ��ǡ�\n");

	if (me->query_skill_prepared("strike") != "jiuyin-shenzhang"
	|| me->query_skill_mapped("parry") != "jiuyin-shenzhang")
		return notify_fail("�������޷�ʹ�����ƶ��ǣ�\n");
                
	msg = HIR"$N����$n��æ����֮ʱ��ʹ�������ƶ��ǡ���\n"NOR;
	damage = (int)me->query_skill("strike")+(int)me->query_skill("force");
	damage += random(me->query("jiali") * 10);
	damage *= 2;
	if(target->query("neili") > me->query("neili")) damage /= 2;

	if (damage>5000) damage = 5000+ random(damage-5000)/100;

	target->receive_damage("qi", damage, me);
	target->receive_wound("qi", damage/2, me);
	p = (int)target->query("qi")*100/(int)target->query("max_qi");
	msg += HIG"$N͵Ϯ���֣����صĴ���$n���ؿڣ�$n��ʱ��Ѫ���硣\n"NOR;
	msg += "( $n"+eff_status_msg(p)+" )\n"; 
	me->add("neili", -500);
	me->add("jingli", -150);
	me->start_busy(random(2));
	me->start_perform(3, "���ƶ���");
	message_vision(msg, me, target);
	return 1;
}

string perform_name(){ return HIR"���ƶ���"NOR; }

int help(object me)
{
        write(HIR"\n��������֮�����ƶ��ǡ���"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1000 ���ϣ�
                ������� 1500 ���ϣ�
                ��ǰ���� 1000 ���ϣ�
                �������Ƶȼ� 180 ���ϣ�
                �����Ʒ�Ϊ�������ƣ�
                �����м�Ϊ�������ƣ�
                ���Ʒ�Ϊ�������ƣ�
                �����ޱ�����

HELP
        );
        return 1;
}
