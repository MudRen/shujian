#include <ansi.h>

int update_condition(object me, int duration)
{

	if (duration < 2){
       tell_object(me, HIY "һ����������ֱ͸��Ķ��ǣ����ֵ��ʱ���Ѿ����ˡ�\n" NOR);
       me->delete_temp("lh_teacher");  
        return 0;
       }
        me->apply_condition("lh_job", duration - 1);
        return 1;
}

string query_type(object me)
{
	return "job";
}
