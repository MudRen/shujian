// puhuo
// 2000.1.19  by emnil

#include <ansi.h>

inherit F_SSERVER;

string perform_name() {return RED"�ɶ��˻�"NOR;}

void canfight(object me);

int perform(object me, object target)
{
	object weapon;
	int busy=0;
	int f,nl,skill;
	string msg;

	if( !target ) target = offensive_target(me);

	weapon = me->query_temp("weapon");

	if (weapon)
		return notify_fail("ֻ�п��ֲ���ʹ�á��ɶ��˻𡹣�\n");

	if( !target 
    || !objectp(target)
	  || !me->is_fighting(target)
	|| !me->is_killing(target->query("id")))
		return notify_fail("���ɶ��˻�ֻ�ܶ��������ಫ�Ķ���ʹ�á�\n");

	if(me->query_temp("sxbb2",1) || me->query_temp("sxbb1",1))
		return notify_fail("���ɶ��˻𡹲��ܺ͡����аٱ䡹���á�\n");

	if(me->query("neili")<1000)
		return notify_fail("����������������û��ʹ�á��ɶ��˻𡹡�\n");
	if(me->query("jingli")<1000)
		return notify_fail("�����ھ���������û��ʹ�á��ɶ��˻𡹡�\n");

	if (target->is_busy()) busy=1;

	if((int)me->query_skill("huagu-mianzhang", 1) < 100 )
		return notify_fail("��Ļ������Ʋ�����죬����ʹ�á��ɶ��˻𡹡�\n");

	if(me->query_skill_mapped("strike") != "huagu-mianzhang")
		return notify_fail("������ʹ�õ��Ʒ����ǻ������ƣ�����ʹ�á��ɶ��˻𡹡�\n");

	f = random(me->query("combat_exp"))*100/(random(target->query("combat_exp"))+1);
	f+= random(me->query_skill("dodge"))*100/(random(target->query_skill("dodge"))+1);
	f+= random(me->query_dex())*100/(random(target->query_dex())+1);
	f+= random(me->query_kar())*100/(random(target->query_kar())+1);
	f+= random(me->query_skill("strike"))*100/(random(target->query_skill("parry"))+1);
	
	skill = me->query_skill("huagu-mianzhang", 1)/20;
	msg = RED+"\n$NͻȻ˫Ŀ��죬�����ſ��������������$n��ȥ��\n"NOR;
	me->receive_damage("jingli",200);
	me->receive_damage("neili",400);
	me->start_perform(5,"���ɶ��˻�");
	if (f*(busy+1) > 250){
		msg +=RED+"$nһ��û���񣬱�$N���ý��ʵʵ���������ã�\n"NOR;

		if (f*(busy+1) < 500 ) {
			msg +=RED+"$n����һ������$N�������ص��ͻ����£����$N�อ��λ��������Ѫ��\n"NOR;
			message_vision(msg,me,target);
			target->add_busy(skill/2);
			nl=f*(busy+1)*3;
			if (target->add("neili",-nl) < 0)
				target->set("neili", 0);
			me->set_temp("last_damage_from","�ɶ��˻��Ծ���");
			me->die();
		} else {
			target->add_busy(skill);
			if (f*(busy+1) < 800) {
				msg +=RED+"$n����һ������$N�������ص��ͻ����£����$N��Ѫ���磡\n"NOR;
				message_vision(msg,me,target);
				me->receive_damage("qi",(800-f*(busy+1))*20,target);
				me->receive_wound("qi",(800-f*(busy+1))*10, target);
				nl= f*(busy+1)*2;
				if (target->add("neili",-nl) < 0)
					target->set("neili", 0);
				me->start_busy(skill*2);
				me->set_temp("no_fight", 1);
				call_out("canfight", skill*2, me);
			}
		}
	} else {
		msg += CYN+"����$n"+CYN+"������$N"+CYN+"����ͼ�����˹�ȥ��\n"NOR;
		me->set_temp("last_damage_from","�ɶ��˻��Ծ���");
		message_vision(msg,me,target);
		me->die();
	}
	return 1;
}

void canfight(object me)
{
	if(me)
		me->delete_temp("no_fight");
}
