//kong for stop liumai-shenjian
//COOL@SJ

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me)
{
        if(!me->query_temp("start_6mai")) 
                return notify_fail("������û�����������񽣡�\n");     
        message_vision(HIG"$N��ָһ�գ���ָ���£����ڹĵ������������������뵤�\n\n"NOR,  
                      me);
        me->delete_temp("start_6mai");
        
        me->start_busy(1);
        
        return 1;
}

string exert_name(){ return HIG"��"NOR; }

int help(object me)
{
        write(HIG"\nǬ��һ����֮���ա���"NOR"\n\n");
        write(@HELP
        Ҫ��  �������������񽣺�
        
HELP
        );
        return 1;
}
