// liaodu.c, �ƶ�
// by snowman
// Modified by darken@SJ

#include <ansi.h>

string exert_name(){ return HBRED"�ƶ�"NOR; }
int exert(object me)
{
        if( me->is_fighting() )
                return notify_fail("ս�����˹���������\n");

        if ((int)me->query_skill("huagong-dafa", 1) < 200)
                return notify_fail("��Ļ�������Ϊ��������\n");

        if ((int)me->query_skill("poison", 1) < 200)
                return notify_fail("��Ļ���������Ϊ��������\n");

        if ((int)me->query_skill("medicine", 1) < 120)
                return notify_fail("��ı���������Ϊ��������\n");

        if ((int)me->query_skill("jingmai-xue", 1) < 120)
                return notify_fail("��ľ���ѧ��Ϊ��������\n");

        if( (int)me->query("neili") < 5000 )
                return notify_fail("�������������\n");
      
        message_vision(HIB"$N���ڵ��ϣ�������һ���һ�󣬿�ʼ�˹��ƶ���\n" NOR, me);
        me->clear_conditions_by_type("poison");
        me->add("neili", -3000);
        me->add("max_neili",-random(2));
        me->start_busy(45-random(me->query("con")));
                
        return 1;
}

