// shexin.c ����

#include <ansi.h>

inherit F_SSERVER;

void affectob(object ,object ,int ,int ,int);
void dohit(object,object);
string perform_name(){ return HIW"����"NOR; }
int perform(object me, object target)
{
	int affect,skill,hits;
	string msg;
	
	if(!me->is_fighting())
		return notify_fail("��û��ս�����أ�\n");

	if(!target) target = offensive_target(me);

	if( (skill=(int)me->query_skill("meinu-quanfa", 1)) < 150 )
		return notify_fail("�����Ůȭ�����������죬�޷�ʩչ�����ġ�������\n");

	if(me->query_skill_mapped("parry") != "meinu-quanfa")
		return notify_fail("��û��ʹ����Ůȭ����Ϊ�мܣ�\n");
	
	if ( me->query_temp("weapon"))
		return notify_fail("���ֳ����������ʹ�á����ġ�������\n");

	if(me->query("gender")=="����")
		return notify_fail("������Զ��֣������ʩչ�����ġ�������\n");
		
if((target->query("gender")==me->query("gender"))&&((int)me->query_skill("meinu-quanfa",1 ) < 350))
		return notify_fail("���ͬ�Զ��֣������ʩչ�����ġ�������\n");

	if(me->query("max_neili")<1200)
		return notify_fail("�������������޷�ʹ�á����ġ�������\n");

	affect=me->query_per()+random(me->query("per")/2);

	if (me->query("gender")=="����") affect=affect / 2;

	if (   target->query_skill("buddhism") > (skill+random(affect/2))  //�ж�monk
	    || target->query_skill("dacheng-fofa") > (skill+random(affect/2))
	    || target->query_skill("taoism") > (skill+random(affect/2)) )
	{
		msg = HIY"\n$N��$n����һЦ���۹�֮����¶������֮�⣬��ʩչ�����ġ�������\n"+
			HIW"����$n���˶���ͻȻ���һ������ʱ��$N����һ���亹��\n"NOR;
		message_vision(msg,me,target);
		me->start_busy(4);
	}
	else if (target->query_per()>=me->query_per())
	{
		msg = HIY"\n$N��Ȼ��$n����һЦ���۹��Ĵ�������������֮���ƺ����������ġ�\n"NOR; 
		message_vision(msg, me, target);
		message_vision(HIW"����$N��ɥ�ط�����$n���Լ�Ư���������ġ������޷�ʩչ��\n"NOR,me,target);
		me->start_busy(2);
	}
	  else if (random(10)>5)
	{
		msg = HIY"\n$N��Ȼ��$n����һЦ���۹��Ĵ�������������֮���ƺ����������ģ�$n���ɵ�һ����\n"NOR; 
      
		message_vision(msg, me, target);

		if ( random(skill) > target->query_skill("force",1)/2 )
		{
			target->add_temp("apply/dexerity", -affect);
			hits = skill / 10;
			me->start_perform(4,"����");
			target->apply_condition("no_perform", 3);
			target->set_temp("shexin", 1);
                        target->start_busy(3);
			me->add("jingli",-100);
			me->add("neili",-300);
			dohit(me,target);
			dohit(me,target);
			call_out("affectob",random(2)+2, me, target, affect, hits,3);
		}
		else 
		{
			message_vision(CYN"\n����$n���һ���������ۻ����������$N���������ĵ����գ�\n"+
					"���$nֻ�����������У����޷�����$N���ĵ��۹��ˡ�\n"NOR, me, target);

                        target->start_busy(2);
			me->add("neili",-100);
			target->add_temp("apply/dexerity", -affect);
			dohit(me,target);
			dohit(me,target);
			if (skill >= 200) dohit(me,target);
			target->add_temp("apply/dexerity", affect);
			me->start_perform(4,"����");
		}
	}
	else
	{
		msg = HIY"\n$N��Ȼ��$n����һЦ����ʩչ�����ġ�������\n"+
			HIM"˭֪$n������û���ϵ���\n"NOR; 
		message_vision(msg, me, target);
		me->start_perform(5,"����");
	}       
	return 1;
}

void affectob(object me,object target,int affect,int hits,int now)
{
	if( !me 
		|| !target 
		|| ( now > hits) 
		|| objectp(me->query_temp("weapon")) 
		|| target->is_ghost() 
		|| me->is_ghost()  
		|| !me->is_fighting(target) 
		|| me->query("neili") < 800 
		|| me->query_skill_prepared("cuff")!="meinu-quanfa"
		|| me->query_skill_prepared("parry")!="meinu-quanfa")
	{
		if( me ) message_vision(HIC"\n$N����ͻȻһ�٣��۹��ָֻ�ƽ����\n"NOR, me);
		if( target && target->query_temp("shexin"))
			target->delete_temp("shexin");
		if ( target )  target->add_temp("apply/dexerity", affect);
			return;
	}

	if( now > (hits/2) && target->query_temp("shexin"))
		target->delete_temp("bujue_busy");

	dohit(me,target);
	dohit(me,target);
	me->start_perform(3,"����");
	call_out("affectob",random(2)+2,me,target,affect,hits,now+1);
}

void dohit(object me,object target) 
{
	int neili,jiali;
	neili = me->query("neili");
	jiali = me->query("jiali");
	COMBAT_D->do_attack(me, target,0, 1);
	if (me->query("neili")<neili && jiali>0) me->set("neili",neili-jiali/3);
}
