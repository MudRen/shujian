// beiming.c
// modified by action@SJ 2009/2/5
//updated by Zmud@Sjmud 12/3/2009

#include <ansi.h>
inherit F_CLEAN_UP;

string exert_name(){ return HIC"��������"NOR; }

int exert(object me, object target)
{
	int skill;

        if( me->query("neili") < 5000 )
		return notify_fail("�������������\n");

        if( me->query_skill("beiming-shengong", 1) < 300 )
		return notify_fail("��ı�ڤ�񹦵ȼ�������\n");

	if( me->query_skill_mapped("force") != "beiming-shengong" )
		return notify_fail("����ڹ����ԡ�\n");

	if( me->query_temp("bmsg/bm") )
		return notify_fail("���Ѿ����ˡ������������ˡ�\n");

	skill = (int)me->query_skill("beiming-shengong", 1);

	me->receive_damage("neili", -1000);
	message_vision(HIB "\n$N����ڤ�񹦿���Ĭ��"NOR"��"HIB"����������̨���������أ��麣�����ڻ�������["HIG"����"HIB"]���γ�һ�ɺƵ�֮����\n" NOR, me);

  me->set_temp("bmsg/bm", me->query_skill("beiming-shengong", 1)); 
  me->add_temp("apply/armor", me->query_skill("beiming-shengong", 1)); 
  me->add_temp("apply/attack", me->query_skill("beiming-shengong", 1)/6);
  me->add_temp("apply/intelligence", me->query_skill("beiming-shengong", 1)/30);
  me->add_temp("apply/dexerity", me->query_skill("beiming-shengong", 1)/20);

	call_out("remove_effect", 1, me, skill);
	me->start_exert(1, "��������");
	if( me->is_fighting() )
		me->start_busy(random(2));
	return 1;
}

void remove_effect(object me, int count)
{
	int amount;
	if( objectp(me) && me->query_temp("bmsg/bm") ) {
		if( count-- > 0 ) {
			call_out("remove_effect", 1, me, count);
			return;
		}
		amount = me->query_temp("bmsg/bm");
    me->add_temp("apply/armor", -me->query_skill("beiming-shengong", 1));
    me->add_temp("apply/attack",-me->query_skill("beiming-shengong", 1)/6);
    me->add_temp("apply/intelligence", -me->query_skill("beiming-shengong", 1)/30);
    me->add_temp("apply/dexerity", -me->query_skill("beiming-shengong", 1)/20);

    me->delete_temp("bmsg/bm");
		tell_object(me, HIC"�㽥����ɢȥ�˾�������["HIB"����"NOR+HIC"]������\n"NOR);
	}
}

int help(object me)
{
	write(HIW"\n��ڤ��֮��������������"NOR"\n\n");
        write(@HELP
        Ҫ��  
                ��ǰ����  10000  ���ϣ�
                ��ڤ��  300  �����ϣ�
                ���������ɽ���н����ڤ��֮���轫�����칦Ч��
HELP
        );
        return 1;
}
