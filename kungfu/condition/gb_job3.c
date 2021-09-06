#include <ansi.h>

int update_condition(object me, int duration)
{
	if( file_name(environment(me)) == "/d/xiangyang/xuanwumen" 
	&& me->query_temp("gb_job3") ) {
		message_vision(CYN"�״�����˹�����$N˵��������������\n"NOR,me);
		write( "\n�״������������ɹŴ���ļ������ڣ������о�Ӫǰ��\n"+
			CYN"�״���������˵�����ҷ��о�ʿ�����޷����ڣ��Ժ�Ϳ�����ˡ�˵��ת���߿��ˡ�\n"NOR);
		log_file("job/zhongjun", sprintf("%8s%-10s��ʼ����ɱ��Ԫ˧�������ڵľ����ǣ�%d��", 
			me->name(), "("+me->query("id")+")", me->query("combat_exp")), me);
		me->move("/d/gb/zhongjun1");
		me->set_temp("gb_job3_enter",1);
	}
	
/*	if( duration / 5 * 5 == duration 
		&& !present("zhongjun shiwei",environment(me) )
		&& me->query_temp("gb_job3_enter") )
	{
		new("/d/gb/npc/yuanbing-shiwei")->move(environment(me));
	}
*/	
	
	me->apply_condition("gb_job3", duration-1);

	if( duration < 2 ){
		if( me->query_temp("gb_job3_enter") ){
			message_vision(HIC"\n$N������Խ��Խ�࣬��֪�������Գɹ�����ս���ߣ��������˰�Χ��\n" NOR, me );
			me->move("/d/xiangyang/xuanwumen.c");
			me->delete_temp("gb_job3");
			me->delete_temp("gb_job3_enter");
			me->unconcious();
			me->set("qi",500);
			me->set("eff_qi",500);
			me->apply_condition("job_busy",10);
		}
		else if(me->query_temp("gb_job3"))
			write(HIY "��ʱ���ѹ�������ʧ�ܡ�\n" );
		return 0;
	}
	return 1;
}
