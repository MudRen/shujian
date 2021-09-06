// retire.c ����ϴ��
// by augx@sj 3/15/2002

#include <ansi.h>
inherit F_CLEAN_UP;

void abandon(object me)
{
	if( !me->query("prepare_retire") ) {
		tell_object(me,"�㲢û��׼������ϴ�ְ���\n");
		return;
	}
	me->delete("prepare_retire");
	tell_object(me,"������˽���ϴ�֡�\n");
}

int main(object me, string arg)
{
	if( arg && arg=="abandon" ) {
		abandon(me);
		return 1;
	}
	//return notify_fail("����ϴ���������������У���ʱ�رա�\n");
	
	if (me->query("no_pk") || me->query("no_pk_disable"))
		return notify_fail("�㲻���Ѿ�����ϴ������\n");
				
	if ( me->query("registered") < 3 )
		return notify_fail("ֻ�й���û����ܽ���ϴ�֡�\n");
		
	//if (me->query_temp("user_type") == "worker")
		//return notify_fail("���ֲ���������ʿ����ν���ϴ�֣�\n");

	if (me->query("prepare_retire")) {
                if( time()- me->query("pk_time") < 86400 )
		{
			me->delete("prepare_retire");
			me->delete("prepare_retire_time");
			return notify_fail("�������ֲ����˽������Ƿǣ����������ȡ����Ľ���ϴ�֡�\n");
		}
                if( (time()-me->query("prepare_retire_time")) < 86400 )
                        return notify_fail("�����ϴ�ֵ�ʱ�仹δ�����������"+CHINESE_D->chinese_time(86400-time()+me->query("prepare_retire_time"))+"����ʽ����ϴ�֡�\n");
		CHANNEL_D->do_channel(me,"chat",HIY"�ҽ�����ʽ����ϴ�֣��Ӵ��˳����������ٹ��ʽ���������"NOR);
		me->delete("prepare_retire");
		me->delete("prepare_retire_time");
		me->set("no_pk",me->query("combat_exp"));
		me->save();
		log_file("static/RETIRE",sprintf("����ϴ�֣�%8s(%-8s) ��exp��%d",me->name(1),me->query("id"),me->query("combat_exp")),me);
	} else {
                if( (time()-me->query("prepare_retire_time")) < 604800 )
			return notify_fail("�㲻�Ǹողŷ�������ϴ����\n");
                if( time()- me->query("pk_time") < 86400)
		{
			return notify_fail("�����ڽ��������п��������԰Ρ�\n");
		}				
		CHANNEL_D->do_channel(me,"chat",HIY"��������޾��Ľ���������׼������ϴ�֣��Ӵ˲��ٹ��ʽ���������"NOR);
		me->set("prepare_retire",1);
		me->set("prepare_retire_time",time());
	}
	
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : retire

����ϴ�֣��˳��������Ӵ˲��ٲ��뽭��������

������������ϴ�֣��ڵ�һ��������������һ���ʱ���˽�
������Թ���ڴ��ڼ䣬�����������PK������Ϊ���������ϴ�֡�
һ��֮���ٴ����뱾�������ʽ�˳�������

�����һ�����������������ϴ�֣������롰retire abandon�����
������������֮���7����㽫�����ٴν���ϴ�֡�

������������һ�����ڲ����˽��������ǽ����ܽ���ϴ�֣�ͬ��
����׼������ϴ�ֵ�һ���ڲ����˽����������ǽ���ϴ�־ͻᱻ
ȡ����

ע�⣡������������
������ʽ����ϴ�ֺ��������κ���ʽ��������������������Լ���
�����10%-30%�ľ���ֵ��

�������ָ��: rejoin(�س�����)

HELP);
	return 1;
}
