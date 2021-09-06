#include <ansi.h>
inherit F_SSERVER;
void attack_1();
void attack_2();
void attack_3();
void finish();
void finish_2();

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( ! objectp(target)
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("������˫�ƣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (me->query_skill("jiuyin-shenzhang",1) < 160 )
	|| (me->query_skill("jiuyin-zhengong",1) < 160 )) 
		return  notify_fail("��Ĺ��򻹲�����죬����ʹ������˫�ơ�\n");

	if( me->query_temp("weapon"))
		return notify_fail("������������\n");   

	if (me->query_skill_prepared("strike") != "jiuyin-shenzhang"
	|| me->query_skill_mapped("parry") != "jiuyin-shenzhang")
		return notify_fail("�������޷�ʹ������˫�ƣ�\n");

	if( me->query("neili") < 5000 )
		return notify_fail("�������������\n");

	if( me->query("jingli") < 1500 )
		return notify_fail("��ľ���������\n");

	me->start_perform(20,"����˫��");
	msg = HIG "$Nʹ������˫�ƣ����Ƶ�ʱ��$n�����ס��\n"NOR;

	me->start_busy(10);
	target->start_busy(10);
	message_vision(msg, me, target);
	call_out("attack_1", 5);
	return 1;
}

void attack_1()
{
	object me = this_player();
	object target = offensive_target(me);
	if (!me || !target) return;
	message_vision(HIY"$N��$n���ɼ���������������ƴ��\n"NOR, me, target);
	me->add("neili",-(target->query_skill("force")));
	target->add("neili",-(me->query_skill("force")));
	if (me->query("neili")<=0||target->query("neili")<=0) {
		if (me->query("neili")<=0) {
			message_vision(HIR"$N�����Ľߣ��ƺ�һ����\n"NOR,me);
			me->set("neili",0);
			me->receive_wound("qi",target->query_skill("force"), target); 
		}
		if (target->query("neili")<=0) {
			message_vision(HIR"$N�����Ľߣ��ƺ�һ����\n"NOR,target);
			target->set("neili",0);
			target->receive_wound("qi",me->query_skill("force"), me); 
		}
		call_out("finish",1); 
	}
	else
		call_out("attack_2",5);
}

void attack_2()
{
	object me = this_player();
	object target = offensive_target(me);
	if (!me || !target) return;
	message_vision(HIY"$N��$n����ı�������Լ�ǿ��������ʩΪ��\n"NOR, me, target);
	me->add("neili",-(target->query_skill("force")*3));
	target->add("neili",-(me->query_skill("force")*3));
	if (me->query("neili")<=0||target->query("neili")<=0) {
		if (me->query("neili")<=0) {
			message_vision(HIR"$N�����Ľߣ��ƺ�һ����\n"NOR,me);
			me->set("neili",0);
			me->receive_wound("qi",target->query_skill("force"), target);
		}
		if (target->query("neili")<=0) {
			message_vision(HIR"$N�����Ľߣ��ƺ�һ����\n"NOR,target);
			target->set("neili",0);
			target->receive_wound("qi",me->query_skill("force"), me);
		}
		call_out("finish",1); 
	}
	else
		call_out("attack_3",5);
}

void attack_3()
{
	object me = this_player();
	object target = offensive_target(me);
	if (!me || !target) return;
	if (!target) return;
	message_vision(HIY"$N��$n����ͷ����ð����ˮ��������������ȫ���Թ���\n"NOR, me, target);
	me->add("neili",-(target->query_skill("force")*5));
	target->add("neili",-(me->query_skill("force")*5));
	if (me->query("neili")<=0||target->query("neili")<=0) {
		if (me->query("neili")<=0) {
			message_vision(HIR"$N�����Ľߣ��ƺ�һ����\n"NOR,me);
			me->set("neili",0);
			me->receive_wound("qi",target->query_skill("force"), target);
		}
		if (target->query("neili")<=0) {
			message_vision(HIR"$N�����Ľߣ��ƺ�һ����\n"NOR,target);
			target->set("neili",0);
			target->receive_wound("qi",me->query_skill("force"));
		}
		call_out("finish",1); 
	}
	else
		call_out("finish_2",5);
}

void finish()
{
	object me = this_player();
	object target = offensive_target(me);
	if (!me || !target) return;
		message_vision(HIY"$N��$n�������ã�ֹͣ�˶��ƣ�������ֹ��\n"NOR, me,target);
}

void finish_2()
{
	object me = this_player();
	object target = offensive_target(me);
	message_vision(HIY"$N��$n���Դ��һ����ֹͣ�˶��ƣ��˿����ߡ�\n"NOR, me,target);
}

string perform_name(){ return HIG"����˫��"NOR; }

int help(object me)
{
        write(HIG"\n��������֮������˫�ơ���"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 5000 ���ϣ�
                ������� 5000 ���ϣ�
                ��ǰ���� 1500 ���ϣ�
                �������Ƶȼ� 160 ���ϣ�
                �����湦�ȼ� 160 ���ϣ�
                �����Ʒ�Ϊ�������ƣ�
                �����м�Ϊ�������ƣ�
                ���Ʒ�Ϊ�������ƣ�
                �����ޱ�����

HELP
        );
        return 1;
}
