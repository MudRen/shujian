// chan.c ���±޷���������ơ���

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	object weapon = me->query_temp("weapon");
	int busy;

	if( !target ) target = offensive_target(me);

        if( !objectp(target)
	  ||!target->is_character()
	  ||!me->is_fighting(target) )
		return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_skill("yijin-jing", 1) < 100 )
		return notify_fail("����׽�ڹ��ȼ�����������ʹ�á�������ơ�����\n");

	if( (int)me->query_skill("riyue-bian", 1) < 120 )
		return notify_fail("������±޷�������죬����ʹ�á�������ơ�����\n");

	if (!weapon
	 || weapon->query("skill_type") != "whip"
	 || me->query_skill_mapped("whip") != "riyue-bian"
	 || me->query_skill_mapped("parry") != "riyue-bian")
		return notify_fail("�������޷�ʹ��ǣ�ƹ�����\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("����������̫��������ʹ�á�������ơ�����\n");

	if( target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

 me->start_perform(4, "��������ơ�"); 
//���Ǽ���busy�ĺ���Ϊ��������
	msg = HIY "$Nʹ�����±޷���������ơ������������ޣ�ɢ�������������ͼ��$n��ȫ�����������\n";

	me->add("neili", -200);
	me->add("jingli", -140);
	busy = (int)me->query_skill("riyue-bian", 1)/30;
	if(random(me->query("combat_exp")) >  target->query("combat_exp")*2/5){
		msg += "���$n��$N���˸����ֲ�����\n" NOR;
		target->start_busy(4+random(4));
		me->set_temp("sl/chanrao",1);
		call_out("check_fight", 1, me, target, weapon, 7); 
	} else {
		msg += "����$n������$N����ͼ����û���ϵ���\n" NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);
	return 1;
}

void check_fight(object me,object target,object weapon,int count)
{
	if (!target) return;
       if( !me
	|| !me->is_fighting(target)
	|| weapon != me->query_temp("weapon")
	|| me->query_skill_mapped("whip") != "riyue-bian"
	|| count < 1){
		if (me) {
			me->delete_temp("sl/chanrao");
//			me->start_perform(3, "��������ơ�");
		}
		return;
       }
       call_out("check_fight", 1, me,target,weapon,count -1);
}
string perform_name(){ return HIY"������ƾ�"NOR; }
