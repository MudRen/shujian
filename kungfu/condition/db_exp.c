#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

        me->apply_condition("db_exp", duration - 1);
        
        if(random(10)==1)
	{
       tell_room(environment(me), me->name() + "��������ɷ��ﾫ����档\n", ({ me }));
		tell_object(me, HIG"�ھ�Ӣ״̬�ڼ䣬��о����κ��¶����°빦����\n"NOR);
	}

        if( duration < 1 ) 
        {
        	tell_object(me, HIR"��Ӣ״̬�������Ѿ���������ĳɳ��ٶ�������������\n"NOR);
        	return 0;
        }
        return CND_CONTINUE;
}

string query_type(object me)
{
	return "db_exp";
}
