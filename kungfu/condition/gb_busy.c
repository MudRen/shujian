// gb_busy.c 

#include <login.h>
#include <ansi.h>
int update_condition(object me, int duration)
{
        if (duration < 2) return 0;
        me->apply_condition("gb_busy", duration - 1);
        return 1;
}

