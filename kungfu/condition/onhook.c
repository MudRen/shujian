#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
string arg;

        me->apply_condition("onhook", duration );
        me->start_busy(999);
        if(random(10)==1)
	{
    tell_room(environment(me), HIG + me->name() + "�������⣬������죬���ڱչ�Ǳ�ޡ�\n", ({ me }));
	    	}

        if( me->query("on_hook/time")-time()<=0 ) 
        {
        me->delete("block_msg");
        	tell_object(me, HIR"�㱾�αչ�Ǳ��ʱ���ѵ���\n"NOR);
       arg = "over";
      "/cmds/usr/onhook"->main(me,arg);
      me->start_busy(-1);
	
        	return 0;
        }
        return CND_CONTINUE;
}

string query_type(object me)
{
	return "onhook";
}
