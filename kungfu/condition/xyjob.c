#include <ansi.h>
int update_condition(object me, int duration)
{                                        
        if (duration < 1) {
            tell_object(me, HIW"��ͻȻ�������������ɸ���Ӫ�ų��źŻ��棡\n"NOR);
            tell_object(me, HIW"�����ƺ���Ҫ��Ԯ�����źš�\n"NOR);
            return 0;        
        }
        me->apply_condition("xyjob", duration - 1);
        return 1;
}

