#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

        me->apply_condition("fofa_axl", duration - 1);
        
        if(random(10)==1)
	{
		tell_room(environment(me), me->name() + "��Ŀ������������ŭĿ��\n", ({ me }));		
	}

        if( ! me->query_temp("fofa_xiuluo") ) 
        {
		tell_object(me, HIW"�����һ����ţ���Ŀ�ָֻ�ԭ���Ĵ���̬֮��\n"NOR);		
		me->clear_condition("fofa_axl");
		return 0;
        }
        
        return CND_CONTINUE;
}

string query_type(object me)
{
	return "fofa";
}
