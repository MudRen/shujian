#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

        me->apply_condition("fofa_gdp", duration - 1);
        me->set("no_pk",1);
        
        if(random(10)==1)
	{
		tell_room(environment(me), me->name() + "����ɢ����һ����Ʈ���������\n", ({ me }));
		tell_object(me, HIG"��������Ʈ��������У�������������ƺ�������û��ϵ��\n"NOR);
	}

        if( duration < 1 ) 
        {
        	tell_object(me, HIW"�����ϵ�����������ȥ��\n"NOR);
        	me->delete("no_pk");
        	return 0;
        }
        return CND_CONTINUE;
}

string query_type(object me)
{
	return "fofa";
}
