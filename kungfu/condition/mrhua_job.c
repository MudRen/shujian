// mrhua_job.c 

#include <login.h>
#include <ansi.h>

int update_condition(object me, int duration)
{
        if (duration < 1) {
            //  me->delete_temp("mrhua");
              me->delete_temp("yanpopo");
              me->delete_temp("mark/ok");
              me->delete_temp("mark/����");
              me->delete_temp("mark/��");
              tell_object(me,HIY"ͻȻһ���Ҷ����˳����������ȵ�������ô������������ȡ���ˡ�\n"NOR);
              me->clear_condition("mrhua_job");
                  }
        if (!duration) return 0;
        me->apply_condition("mrhua_job", duration - 1);
        return 1;
}

string query_type(object me)
{
	return "job";
}
