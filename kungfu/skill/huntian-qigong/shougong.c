// shougong.c �չ�

#include <ansi.h>
inherit F_CLEAN_UP;

string exert_name(){ return HIW"�չ�"NOR; }

void remove_effect(object me);

int exert(object me)
{
//	int amount;

//	if( !wizardp(me) || !me->query("env/huntian_test") )    return notify_fail("��ʱ�رա�\n"); 

	if( !me->query_temp("htqg/powerup") )
		return notify_fail("�㲢û��ʹ�á����졹�񹦡�\n");

	if( me->query_temp("htqg/shougong") )
		return notify_fail("�����ڽ������ջص��\n");

	if( me->query_temp("htqg/powerup") > 0 ) {
		message_vision(HIW"$N��Ŀ����ȫ��ǽڡ���ž�����죬��Ҫɢȥ���ھ�����\n" NOR, me);
		me->set_temp("htqg/shougong", 1);
		if( me->is_fighting() )
			me->start_busy(random(2));
	} else return notify_fail("�������޷��չ���\n");
	return 1;
}

int help(object me)
{
        write("\n�����������չ�����\n");
        write(@HELP
        ���������˹�����Ҫ��ǰȡ���˹�����Ҫ�ˡ��չ������ﵽ��
        Ҫ��
                ���������˹��С�
HELP
        );
        return 1;
}
