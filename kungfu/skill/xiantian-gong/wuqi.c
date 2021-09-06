// wuqi.c
// action@SJ 2009/1/17

#include <ansi.h>
inherit F_CLEAN_UP;
string exert_name(){ return HIR"������Ԫ"NOR; }


 void remove_effect(object me, int count);
int exert(object me, object target)
{
	int skill;

	if( me->query("neili") < 1000 )
		return notify_fail("�������������\n");

	if( me->query_skill("xiantian-gong", 1) < 150 )
		return notify_fail("������칦�ȼ�������\n");

	if( me->query_skill_mapped("force") != "xiantian-gong" )
		return notify_fail("����ڹ����ԡ�\n");

	if( me->query_temp("xtg/wuqi") )
		return notify_fail("���Ѿ����ˡ�������Ԫ���ˡ�\n");

	skill = me->query_skill("force",1);
	
	me->receive_damage("neili", -300);
	
	message_vision(
HIR"$NĬ��Ĳ��񣬸βػ꣬Ƣ���⣬���ؾ����β��ǡ��ķ��������ϵ���[������Ԫ]֮����ʱ��\n"+

"�������ˡ���֮�޵����������й����ϣ������������壬ʼ�ܹ�ԭ�޼����壬����Բͨ�������ķ��š�\n" NOR, me);

  me->set_temp("xtg/wuqi", skill );

	call_out("remove_effect", 1, me, skill);
	me->start_exert(1, "������Ԫ");
	if( me->is_fighting() )
		me->start_busy(random(2));
	return 1;
}

void remove_effect(object me, int count)
{
        int amount;
        if(!me)  return;
  if( objectp(me) && me->query_temp("xtg/wuqi")) {
		if( count-- > 0 ) {
			call_out("remove_effect", 1, me, count);
			return;
		                        }
		
		amount = me->query_temp("xtg/wuqi");
    me->delete_temp("xtg/wuqi");
    
		tell_object(me, HIW"���["+HIR+"������Ԫ"+HIW+"]������ϣ��������ջص��\n"NOR);
      }
}

int help(object me)
{
	write(HIW"\n���칦֮��������Ԫ����"NOR"\n\n");
        write(@HELP
	Ҫ��  �������  2000 ���ϣ�
          ��ǰ����  1000  ���ϣ�
          ���칦  150  �����ϣ�
HELP
        );
        return 1;
}
