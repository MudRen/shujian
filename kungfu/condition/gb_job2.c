#include <ansi.h>

int update_condition(object me, int duration)
{
	me->apply_condition("gb_job2", duration-1);

	if( duration < 2 ){
		if( me->query_temp("gb_job2"))	{
			write( HIY "��ʱ���ѹ�������ʧ�ܡ�\n" NOR );
			me->delete_temp("gb_job2");
			if(file_name(environment(me))[0..14]=="/d/gb/liangcang"){
				message_vision(HIC"\n$N������Խ��Խ�࣬��֪�������Գɹ������ⰵ������ս���ߣ��������˰�Χ��\n" NOR, me );
				me->move("/d/xiangyang/xuanwumen.c");
				me->unconcious();
				me->set("qi",500);
				me->set("eff_qi",500);
				me->add_condition("job_busy",10);
			}
		}
		return 0;
	}
	return 1;
}
