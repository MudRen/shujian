#include <ansi.h>
int update_condition(object me, int duration)
{
        if (duration < 1) {               
		tell_object(me, HIY "��о����г�����Ȼ����������Ϊ֮һ��\n" NOR);
		return 0;
                }
         me->apply_condition("sljob", duration - 1);
        return 1;
}

string query_type(object me)
{
	return "job";
}
