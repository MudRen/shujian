#include <ansi.h>
int update_condition(object me, int duration)
{                                        
        if (duration < 1) {
            tell_object(me, HIR"��ͻȻ����������Ӫ�ų��źŻ��棡\n"NOR);
            tell_object(me, HIR"�����ƺ���Ҫ��Ԯ�����źš�\n"NOR);
            me->delete_temp("xy");
            return 0;        
        }
        me->apply_condition("guo_job", duration - 1);
        return 1;
}

