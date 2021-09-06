// richu.c �ճ��⻪
// action@SJ 2009/1/17

#include <ansi.h>
inherit F_CLEAN_UP;
string exert_name(){ return HIR"�ճ��⻪"NOR; }

int exert(object me, object target)
{
	int skill;

	if( me->query("neili") < 1000 )
		return notify_fail("�������������\n");

	if( me->query_skill("tianmo-gong", 1) < 150 )
		return notify_fail("�����ħ���ȼ�������\n");

	if( me->query_skill_mapped("force") != "tianmo-gong" )
		return notify_fail("����ڹ����ԡ�\n");

	if( me->query_temp("tmg/richu") )
		return notify_fail("���Ѿ����ˡ��ճ��⻪���ˡ�\n");

	skill = me->query_skill("force")/3;
	if( skill > 150 ) skill = 150;

	me->receive_damage("neili", -300);
	message_vision(
HIR"$Nһ����Х��˫Ŀ��ó�죬˫��һ�㣬�����ڿն������ܶ�ʱ���˷�ӿ�������ѵ�����\n" NOR, me);

  me->set_temp("tmg/richu", me->query_skill("tianmo-gong", 1)/10); 
  me->add_temp("apply/armor", me->query_skill("tianmo-gong", 1)/3); 
  me->add_temp("apply/attack", me->query_skill("tianmo-gong", 1)*6/10);
   me->add_temp("apply/parry", me->query_skill("tianmo-gong", 1)/10);
	call_out("remove_effect", 1, me, skill);
	me->start_exert(1, "�ճ��⻪");
	if( me->is_fighting() )
		me->start_busy(random(2));
	return 1;
}

void remove_effect(object me, int count)
{
	int amount;
	if( objectp(me) && me->query_temp("tmg/richu") ) {
		if( count-- > 0 ) {
			call_out("remove_effect", 1, me, count);
			return;
		}
		amount = me->query_temp("tmg/richu");
		me->add_temp("apply/parry", -me->query_skill("tianmo-gong", 1)/10);
    me->add_temp("apply/attack",-me->query_skill("tianmo-gong", 1)*6/10);
    me->add_temp("apply/armor", -me->query_skill("tianmo-gong", 1)/3);
    me->delete_temp("tmg/richu");
                tell_object(me, HIW"���["+HIR+"�ճ�����"+HIW+"]������ϣ��������ջص��\n"NOR);
	}
}

int help(object me)
{
	write(HIW"\n��ħ��֮���ճ��⻪����"NOR"\n\n");
        write(@HELP
	Ҫ��  �������  2000 ���ϣ�
          ��ǰ����  1000  ���ϣ�
          ��ħ��  150  �����ϣ�
HELP
        );
        return 1;
}
