// Modified by Darken@SJ
#include <ansi.h>

string exert_name() { return HIG"�һ����ž�"NOR; }

#include <ansi.h>
int exert(object me)
{       
        int level=me->query_skill("qimen-bagua", 1);
        if ((int)me->query_skill("qimen-bagua", 1) < 80)
                return notify_fail("������Ű�����Ϊ��������\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("�������������\n");
        if( me->query_temp("thd/is_smart")   )
                return notify_fail("���������������ķ���\n");

        message_vision(HIW"$N��ϸ��˼�����Ű���֮ѧ�����ж�ʱ��Ȼ���ʣ�\n"NOR, me);
        me->set_temp("thd/is_smart", 1);
        me->add_temp("apply/intelligence",(int)me->query("int"));
        me->add("neili", - (200+random(200)));
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), level );
        return 1;
}

void remove_effect(object me)
{
        if( !me || !me->query_temp("thd/is_smart")) return;
        me->add_temp("apply/intelligence",-(int)me->query("int"));
        me->delete_temp("thd/is_smart");
        tell_object(me, HIY"���˼·���ǣ�ֻ��ɢȥ�ˡ����š��ķ���\n"NOR);
}

int help(object me)
{
        write(HIG"\n���һ����ž�����"NOR"\n");
        write(@HELP

        ˼�����Ű���֮�����ﵽ��ʱ����ѧϰЧ�ʵ��ķ����ϡ��������ڼ䣬ս
        ����Ҳ�������⼼�ɵĻ�����ϣ�����Ǳ�ܣ��������һ�����ѧ�����Ӹ�
        ��һ�㣬���������һ��书��

        Ҫ��  ���Ű��Եȼ� 80 ���ϣ�
                ������� 500 ���ϡ�
HELP
        );
        return 1;
}

