// /kungfu/condition/pfm_bishen.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if ( duration < 1 ) 
        {
                tell_object(me, WHT "�㽫��������������ٸе�һ������������Ҳ���ƸղŰ�������Ż����\n" NOR);
                return 0;
        }
//      tell_object(me, "Condition apply spare only " + duration + " times...\n");
        me->apply_condition("pfm_dzxy", duration - 1);
        return 1;
}
