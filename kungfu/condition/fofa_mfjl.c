#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

        me->apply_condition("fofa_mfjl", duration - 1);
        me->set("channels", ({}));
        
        if(random(10)==1)
	{
		tell_room(environment(me), me->name() + "����Χ�����ǲ��в�֪������ȴ��������\n", ({ me }));
	}

        if( duration < 1 ) 
        {
        	tell_object(me, HIW"��˫��һ��¶���������⡣\n"NOR);
        	return 0;
        }
        return CND_CONTINUE;
}

string query_type(object me)
{
	return "fofa";
}
