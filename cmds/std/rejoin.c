// rejoin.c	�س�����
// by augx@sj 3/15/2002

#include <ansi.h>
inherit F_CLEAN_UP;

void abandon(object me)
{
	if( !me->query("prepare_rejoin") ) {
		tell_object(me,"�㲢û���س���������\n");
		return;
	}
	me->delete("prepare_rejoin");
	tell_object(me,"��������س�������\n");
}
/*
if( me->query("no_pk") > 3000000 )
		exp = me->query("combat_exp") / 3;
	else
		exp = me->query("combat_exp") / 2;
*/

private void reward_player(object me)
{
	int cuted,exp;
	if(!me) return;
	
        cuted = me->query("rejoin_times") *20;
        if(cuted >=100) cuted = 95;
       if(cuted == 0) cuted = 10;
	exp = me->query("combat_exp") * cuted / 100;
	me->add("combat_exp",-exp);
	
	log_file("static/RETIRE",sprintf("�س�������%8s(%-8s) ��cut lit��%d",me->name(1),me->query("id"),cuted),me);
	log_file("static/RETIRE",sprintf("�س�������%8s(%-8s) ��cut exp��%d",me->name(1),me->query("id"),exp),me);
	
	if(me->query_skill("literate",1) <= cuted) me->delete_skill("literate");
	else me->set_skill("literate",me->query_skill("literate",1) - cuted );
	
	me->add("rejoin_times",1);
}

int main(object me, string arg)
{
	int exp;

	if( arg && arg=="abandon" ) {
		abandon(me);
		return 1;
	}
        if ( me->query("combat_exp") < 5000000 )
			return notify_fail("���ϣ����ǵ㾭�鲻�����ģ�������������˵�ɡ�\n");

	if( !me->query("no_pk") )
		return notify_fail("�㲢û�н���ϴ�ְ���\n");

	if( me->query("prepare_rejoin") ) {
		if( (time()-me->query("prepare_rejoin_time")) < 604800 )
			return notify_fail("���س�������ʱ�仹δ����\n");
		CHANNEL_D->do_channel(me,"chat",HIY"��λͬ�����ҽ�����ʽ�س��������Ӵ��ݺ����֣��������"NOR);
		me->delete("prepare_rejoin");
		me->delete("prepare_rejoin_time");
		
		exp = me->query("combat_exp");
		
		reward_player(me);
		
		me->delete("no_pk");		
		me->setup();
		me->save();
		log_file("static/RETIRE",sprintf("�س�������%8s(%-8s) ��exp��%d(%d)",me->name(1),me->query("id"),me->query("combat_exp"),exp),me);
	}
	else {
		if( (time()-me->query("prepare_rejoin_time")) < 604800 )
			return notify_fail("�㲻�Ǹողŷ����س�������\n");
		CHANNEL_D->do_channel(me,"chat",HIY"��λͬ�����Ҳ��ٸ��ڼ�į������������֮���س��������ٴ����ܿ����������ӣ�"NOR);
		me->set("prepare_rejoin",1);
		me->set("prepare_rejoin_time",time());
	}

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : rejoin

���³�ɽ�����뽭��������

�����Ҫ�س��������ڵ�һ�����������󣬽�������Ļ����ڣ�
������֮�������ʹ�����rejoin abandon���������س�������
����֮�����ڴ����뱾���������ʽ�س�������
ע�⣺�س���������һ���ľ���Ͷ���д�ֵȼ� ��ʧ��
      ��һ���س�������ʧ10%����Ͷ���д�֡��Ժ�ÿ�ε���20%

��ʧ������س������Ĵ����йء�

�������ָ��: retire(����ϴ��)

HELP);
	return 1;
}

