//COOL@SJ 200001009 add yyz liao yyz_hurt
#include <ansi.h>

string exert_name() {return HIY"��������"NOR;}

int exert(object me, object target)
{
	if( !objectp(target) )
		return notify_fail("��Ҫ��һ��ָΪ˭���ˣ�\n");

	if (target->is_corpse() || !target->is_character())
		return notify_fail("�ǲ��ǻ���Ү��\n");

	if (target->is_busy())
		return notify_fail("�Է�����û�пս���������ˡ�\n");

	if((int)me->query_skill("force") < 270 )
	      return notify_fail("���Ǭ��һ����������죬�޷��������ˣ�\n");

	if((int)me->query_skill("yiyang-zhi",1) < 180 )
	      return notify_fail("���һ��ָ�񹦲�����죬�޷��������ˣ�\n");

	if (me->query_skill_prepared("finger") != "yiyang-zhi"
	|| me->query_skill_mapped("finger") != "yiyang-zhi")
		return notify_fail("�������޷�ʹ��һ��ָ�������ˣ�\n");

	if( me->is_fighting() && target != me)
		return notify_fail("ս�����޷���������ˣ�\n");

        if( target->is_fighting()&&target != me)
                return notify_fail("�Է�����ս�����޷��������ˣ�\n");

	if( (int)me->query("max_neili") < 2000 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 400 )
		return notify_fail("�������������\n");

	if((int)me->query_skill("medicine", 1) < 120 )
	       return notify_fail("���������ҽ��֪ʶ��֪���٣���֪�������? \n");

	if (!target->query_condition("yyz_hurt")
	&& target->query("eff_qi") >= target->query("max_qi"))
		return notify_fail( target->name() + "��û�����ˣ�\n");

	if (me->is_fighting()) {
		message_vision(
			HIY"\n$N�ֱ۲������������ѵ�ˮ��һ����������Լ��ؿڵ�ʮ������Ѩ��������������͸�롭��\n\n"
			HIM"ֻ��Ƭ��֮�䣬$N��ɫ�����˺��Σ����ƺö��ˡ�\n" NOR, me);
		if (target->query_condition("yyz_hurt")) target->clear_condition("yyz_hurt");
		if ((int)target->query("eff_qi") < (int)target->query("max_qi"))
		{
			me->add("neili",-me->query_skill("force")/3);
			me->receive_curing("qi", 10 + me->query_skill("force") );
			me->receive_heal("qi", 10 + me->query_skill("force"));
		}
		me->start_exert(5, "����");
	} else {
		target->start_busy(2);
	  	if (target != me){
			me->start_busy(2);
	    		message_vision(HIY"\n$N�������ʳָ��΢һ������������������, ʳָ���Ρ���������Ѩ���˵���������$n�ؿڵ����д�Ѩ�ϣ���������ԴԴ͸�롣����\n\n"
			   	HIM"\n$Nͷ��ð��˿˿������$n�о�һ������ƽ�͵�����������ѭ������������һյ��ʱ�֣�$N�ŷſ���ָ��ֻ��Ƭ��֮�䣬$n˫��\n"
			   	HIM"�����˺��Σ���ɫ������Ҳ�ö��ˡ�\n" NOR,me,target);
		}
		else
	   		message_vision(HIY"\n$N�������£�΢һ������ʳָ���Ρ���������Ѩ���˵����ʳָһ�գ����ư����ؿ����д�Ѩ����������ԴԴ͸�롣����\n\n"
				HIM"$Nͷ��ð��˿˿����������һյ��ʱ�֣��ŷſ���ָ,$N����ɫ������Ҳ�ö��ˡ�\n" NOR,me);
	   	if( (target != me)
	    	&& userp(target)
	    	&& target->query("eff_qi") < target->query("max_qi")/5) {
	     		if (!random(4)) me->add("max_neili",-1);
	     		me->add("yyz_cure",1);
		}
		if (target->query_condition("yyz_hurt")) target->clear_condition("yyz_hurt");
		if (target->query("eff_qi") < target->query("max_qi"))
		{
		   	me->add("neili", -me->query_skill("force")/4);
	   		target->receive_curing("qi", 10 + me->query_skill("force"));
	   		target->receive_heal("qi", 10 + me->query_skill("force"));
	   		me->start_busy(3);
	   		target->start_busy(3);
	 	}
	}
	return 1;
}
