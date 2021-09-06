// jd.c 
// by emnil   98.10.4

#include <ansi.h>
inherit F_CLEAN_UP;

string exert_name() {return HIW"�ⶾ"NOR;}

int exert(object me, object target)
{
        int skill;

        if(target != me && !present(target,environment(me)))
                return notify_fail("�������û������ˣ�\n");

        if((int)target->query("huagu") < 200 && target != me)
                return notify_fail(target->name()+"û���л������ƶ���\n");

        if((int)target->query("huagu") < 200)
                return notify_fail("��û���л������ƶ���\n");

        if((int)me->query_skill("dulong-dafa",1) < 150  )
                return notify_fail("��Ķ����󷨹����������޷��⻯�����ƶ���\n");

        if((int)me->query_skill("shenlong-yaoli",1) < 150  )
                return notify_fail("�������ҩ��ѧ��������ȱ���޷��⻯�����ƶ���\n");

        if((int)me->query("neili") < 500
         || (int)me->query("max_neili")< 100  )
                return notify_fail("�������������\n");

        skill= (me->query_skill("dulong-dafa",1)/2 + me->query_skill("shenlong-yaoli",1))*14;
        if((int)target->query("huagu") > skill)
            target->add("huagu",-skill);
        else
            target->delete("huagu");
        if( target != me)
          message_vision(HIW"\n$N���ֵ�ס$n��˫�ƣ�������$n���ϵĶ��رƳ����⡣\n\n"NOR,me,target);
        else 
          message_vision(HIW"\n$N��ͷ�󺹣��þ��������ڵĶ��رƳ����⡣\n\n"NOR, me);
        target->clear_condition("huagu_poison");
        me->add("max_neili",-10);
        me->start_busy(5);
        if( target != me) target->start_busy(5);
        me->add("neili",-400);
        return 1;
}
