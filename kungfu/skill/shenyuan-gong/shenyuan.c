// shenyuan.c yun shenyuan ������ս���������൱�ķ���

#include <ansi.h>
#include <skill.h>
#include <combat.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int skill);

string exert_name(){ return HIY"��Ԫ��"NOR; }

int exert(object me, object target)
{
	int skill;

	if (!me->is_fighting())
		return notify_fail("��ֻ����ս����ʹ����Ԫ����\n");

	skill = me->query_skill("force") + random(50);
	
	if( (int)me->query_skill("shenyuan-gong",1) < 60 )
		return notify_fail("��Ŀǰ�в���ʹ����Ԫ����\n");

	if( (int)me->query("neili") < skill  )
		return notify_fail("�������������\n");
 
	if( (int)me->query_temp("shenyuan") ) 
		return notify_fail("���Ѿ���������Ԫ���ˡ�\n");

	me->add("neili", -1 * skill);
	me->add_temp("apply/parry", skill/3);
	me->add_temp("apply/dexerity", skill/20);

	message_vision(HIY "$N����Ľ�ݾ�ѧ��Ԫ�����ƺ���֪�书·�������������ɶ��ˡ�\n" NOR, me);

	me->set_temp("shenyuan", skill);
	call_out("remove_effect", 1, me, skill);

	me->start_exert(1, "��Ԫ��");
if( skill <300 )	me->start_busy(1);

	return 1;
}

void remove_effect(object me, int skill)
{
	if (objectp(me)) {
	  if (me->is_fighting()){
	      call_out("remove_effect", 1, me, skill);
//	    me->start_exert(1, "��Ԫ��"); 
	      return;
	  }
	  me->delete_temp("shenyuan");
	  me->add_temp("apply/parry", -1 * skill/3);
	  me->add_temp("apply/dexerity", -1 * skill/20);
//	tell_object(me, "��������Ӧ����ķ�����ʽ��������ǿ�˹��ơ�\n");
	}
	return;
}
