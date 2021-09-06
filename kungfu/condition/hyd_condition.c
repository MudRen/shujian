// hyd_condition.c

#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int qi;

	if( !living(me) ) {
		tell_object(me, RED "����û�����������������С�����Ҳ壬���ĵ���ʹ��\n" NOR );
		message("vision",HIR+me->name()+HIR"�������������Ҵܣ�һ�ɹɽ���ζð�˳������յ�"
			+me->name()+HIR"�������죬˫�ֺ����˴��š�\n"NOR,environment(me), me);
	}

	if(me->query("eff_qi") < 300) {
		tell_object(me, RED "����û�����������������С�����Ҳ壬���ĵ���ʹ��������ܲ���ȥ�ˡ�\n" NOR );
		message("vision", HIR+me->name()+HIR"���ϻ����𽥼�С�����������ճ��˺�̼��ɫ��"
			+me->name()+HIR"˫���ڿ��������ػ��裬�����첻���ˡ�\n"NOR,environment(me), me);
	}

	qi = me->query("max_qi")/20;
	if (qi > 300) qi = 300;
	if (qi < 50)  qi = 50;
	me->receive_damage("qi",qi, "�����ճɽ�̼��");
	me->receive_wound("qi",qi, "�����ճɽ�̼��");
	me->apply_condition("hyd_condition", duration - 1);

	if( (int)me->query_temp("hyd/dec") != 1 ) {
		me->set_temp("hyd/dec",1);
		me->set_temp("hyd/dodge" , me->query_skill("dodge")/3 );
		me->add_temp("apply/dodge", -me->query_temp("hyd/dodge"));
		call_out("remove_effort",30+random(30),me);
	}

	if( random(10)>5 )
		me->add_busy(5);

	if( duration < 1) return 0;
	return CND_CONTINUE; 
}

void remove_effort(object me)
{
	if ( !objectp(me) || (int)me->query_temp("hyd/dec")!=1 ) 
		return;

	me->delete_temp("hyd/dec");
	me->add_temp("apply/dodge", me->query_temp("hyd/dodge"));
	me->delete_temp("hyd/dodge");
}

string query_type(object me)
{
	return "hurt";
}
