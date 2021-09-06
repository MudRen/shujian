// zhixin.c
// Modified by Lane@SJ 2005/4/14

#include <ansi.h>

int exert(object me)
{
	int improve;

	if( (int)me->query_skill("linji-zhuang", 1) < 60 )
		return notify_fail("����ټ�ʮ��ׯ��Ϊ��������\n");
/*
	if( me->query("class") != "bonze" && me->query("family/generation") > 3)
		return notify_fail("�㲻�ǳ����ˣ��޷�����ټ�ʮ��ׯ�ġ�֮�ġ��־���\n");
*/
	if( (int)me->query("neili") < 300 )
		return notify_fail("�������������\n");

	if( me->query_temp("ljz/zhixin") )		// ͳһ ���
		return notify_fail("�����������ټ�ʮ��ׯ�ġ�֮�ġ��־���\n");

	write(MAG"��΢һ�����˶�֮����ׯ��ȥ���������⣬�����������У�ֻ����̨�������������������ӡ�\n"NOR, me);
	message_vision(MAG"ֻ��$N΢һ�������¼��ڳ�����һ�������鶯������������ġ�\n"NOR, me);

	improve = me->query("int");

	me->add_temp("apply/intelligence", improve);
	me->set_temp("ljz/zhixin", improve);	// �޸ı��
	me->start_exert(1, "֮��");
	me->add("neili", - 250);
	me->start_call_out((: call_other, __FILE__, "remove_effect", me, improve :), me->query_skill("literate", 1)/2);
	return 1;
}

void remove_effect(object me, int improve)
{
	if( !me || !me->query_temp("ljz/zhixin") ) return;	// �޸ı��
	me->add_temp("apply/intelligence", -improve);    
	me->delete_temp("ljz/zhixin");	// �޸ı��
	tell_object(me, HIR"�������ѻ������������ƺ��������ֹ���Ѱ����\n"NOR);
}

string exert_name(){ return MAG"֮���־�"NOR; }

int help(object me)
{
        write(MAG"\n�ټ�ʮ��ׯ��֮���־�����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 300 ���ϣ�
                �ټ�ʮ��ׯ�ȼ� 60 ���ϣ�
                ���һ��׼��������ӡ�
HELP
        );
        return 1;
}
