//wuji.c

#include <ansi.h>
void remove_effect(object me,int skill);


string exert_name() {return HIG"�����޼�"NOR;}

int exert(object me)
{      
       int skill;
       skill = me->query_skill("xuantia-wuji", 1);
       
	if ( !me->is_fighting())
		return notify_fail("��ֻ����ս����ʹ�á��޼�����\n");

	if( (int)me->query_skill("xuantian-wuji", 1) < 200 )
		return notify_fail("��������޼�����Ϊ�������޷�ʹ�á��޼�����\n");

	if (me->query_skill_mapped("force") != "xuantian-wuji")
		return notify_fail("�����ڹ��С��޼�����\n");

	if( (int)me->query("neili") < 5000 )
		return notify_fail("��Ŀǰ������̫���ˣ��޷�ʹ�á������޼�����\n");

	if( (int)me->query("max_neili") < 3500 )
		return notify_fail("���������Ϊ��ô�����ʹ�á������޼�����\n");

       if( (int)me->query_int() < 40 )
                 return notify_fail("������Ի�������ʹ�����������޼�������\n");

       if( (int)me->query_con() < 48 )
                 return notify_fail("��ĸ��ǻ�������ʹ�����������޼�������\n");

if(me->query_temp("kl/riyue"))
		return notify_fail("���������á������޼����ķ���\n");
		
		if( me->query_temp("xtwj") )
		return notify_fail("���������á������޼����ķ���\n");
     
     
	if( me->query_temp("kl/taxue"))
		return notify_fail("���������á�̤ѩ���ķ���\n");

	message_vision(HIW "$N΢һ�������������޼��ķ���ֻ��$Nȫ��һ������Χ�ơ�\n" NOR, me);
       me->start_busy(1);
       me->add_temp("apply/parry", me->query_skill("xuantian-wuji", 1)/2);
       me->add_temp("apply/armor", me->query_skill("xuantian-wuji", 1)/2);
	me->add("neili", -400);
me->set_temp("kl/riyue", skill );
me->set_temp("xtwj",1);
	call_out("remove_effect", 1, me, skill);

    if( me->query_skill("xuantian-wuji",1)<=350 )
	me->start_exert(2, "���޼���");
	return 1;
}
void remove_effect(object me, int skill)
{
	
	 if (objectp(me)) {
                if (me->is_fighting()) {
                        call_out("remove_effect", 1, me, skill);
                        return;
                }

           me->delete_temp("kl/riyue");
	    me->delete_temp("xtwj");
           me->add_temp("apply/parry", -me->query_skill("xuantian-wuji", 1)/2);
           me->add_temp("apply/armor", -me->query_skill("xuantian-wuji", 1)/2);
           message_vision(WHT"\n$N�������޼���������ϣ��������ջص��\n"NOR, me);
	    return;

	}
}


int help(object me)
{
        write(WHT"\n�����޼����������޼�����"NOR"\n");
        write(@HELP
        �ˡ��޼���һʽ���������������ڹ��ķ������޼�����Ϊ������
        ���������������¾���Ϊ�޼����ܣ�������������ͬʱ����
        ����ʹ�Է�������Ч��

        Ҫ��:  �����޼��� 200 �����ϣ�
               ������� 3500 �㣻
               ��ǰ���� 5000 �㣻
               ������ ̤ѩ ͬʱʹ�á�
              
HELP
        );
        return 1;
}


