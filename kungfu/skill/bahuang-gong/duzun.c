// duzun.c
// action@SJ 2009/1/17
#include <ansi.h>
inherit F_CLEAN_UP;

string exert_name(){ return HIR"�˻�����Ψ�Ҷ���"NOR; }

int exert(object me, object target)
{
	int skill;

	if( me->query("neili") < 1000 )
		return notify_fail("�������������\n");

	if( me->query_skill("bahuang-gong", 1) < 150 )
		return notify_fail("��İ˻�����Ψ�Ҷ��𹦵ȼ�������\n");

	if( me->query_skill_mapped("force") != "bahuang-gong" )
		return notify_fail("����ڹ����ԡ�\n");

	if( me->query_temp("bhg/duzun") )
		return notify_fail("���Ѿ����ˡ��˻�����Ψ�Ҷ����ˡ�\n");

	skill = me->query_skill("force")/3;
	if( skill > 150 ) skill = 150;

	me->receive_damage("neili", -300);
	message_vision(HIR "$N����Ϣ��������˻�����Ψ�Ҷ��𹦣�ֻ��һ��������������\n" NOR, me);

  me->set_temp("bhg/duzun", me->query_skill("bahuang-gong", 1)); 
  me->add_temp("apply/armor", me->query_skill("bahuang-gong", 1)/5); 
  me->add_temp("apply/hand", me->query_skill("bahuang-gong", 1)/10);
  me->add_temp("apply/attack", me->query_skill("bahuang-gong", 1)*5/10);

	call_out("remove_effect", 1, me, skill);
	me->start_exert(1, "�˻�����Ψ�Ҷ���");
	if( me->is_fighting() )
		me->start_busy(random(2));
	return 1;
}

void remove_effect(object me, int count)
{
	int amount;
	if( objectp(me) && me->query_temp("bhg/duzun") ) {
		if( count-- > 0 ) {
			call_out("remove_effect", 1, me, count);
			return;
		}
		amount = me->query_temp("bhg/duzun");
    me->add_temp("apply/attack",-me->query_skill("bahuang-gong", 1)*5/10);
    me->add_temp("apply/hand",-me->query_skill("bahuang-gong", 1)/10);
    me->add_temp("apply/armor", -me->query_skill("bahuang-gong", 1)/5);
    me->delete_temp("bhg/duzun");
		tell_object(me, HIR"��ġ��˻�����Ψ�Ҷ��𹦡�������ϣ��������ջص������\n"NOR);
	}
}

int help(object me)
{
	write(HIW"\n�˻�����Ψ�Ҷ���֮��Ψ�Ҷ��𡹣�"NOR"\n\n");
        write(@HELP
	Ҫ��  �������  2000 ���ϣ�
          ��ǰ����  1000  ���ϣ�
          �˻�����Ψ�Ҷ���  150  �����ϣ�
HELP
        );
        return 1;
}