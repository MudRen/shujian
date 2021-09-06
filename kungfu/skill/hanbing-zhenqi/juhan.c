// by darken@SJ
// Lklv add help at 2001.10.06

#include <ansi.h>
inherit F_SSERVER;
string exert_name(){ return HIW"�ۺ���"NOR; }

int exert(object me)
{
	string msg;
	int lv = me->query_skill("hanbing-zhenqi",1);

	if (!me->is_fighting())
		return notify_fail("��ֻ����ս����ʹ�á��ۺ�������\n");

	if (lv < 60)
		return notify_fail("����Ŀǰ���ڹ���Ϊ���޷�ʹ�á��ۺ�������\n");

	if (me->query("qi") < me->query("max_qi")/3)
		return notify_fail("�����Ѫ���㡣\n");
		
	if ( me->query_temp("ss/focus") >= 15 )	
		return notify_fail("���Ѿ������ۺ��������ӵ����쾡�¡�\n");

	msg = HIW"$N��Ϣ�����������¶ȶ�Ȼ���ͣ���Ȼ���˱���һ�㺮˪��\n"NOR;

	if (!me->query_temp("ss/focus")) {
		call_out("remove_effect", lv/5 + random(10), me);
	}
    //���û�б�Ҫ�ɣ�һ��������ô�죿
	//me->receive_damage("qi", 200+random(50));
	me->add_temp("ss/focus", random(lv/200)+1);

	if ( me->query_temp("ss/focus") > 15 )
		me->set_temp("ss/focus", 15);

	message_vision(msg, me);
	me->start_exert(1, "���ۺ�����");
	return 1;
}

void remove_effect(object me)
{
	if (!me || !me->query_temp("ss/focus") ) return;
	message_vision(HIW"$N����ĺ���������ɢȥ�ˡ�\n"NOR,me);
	me->delete_temp("ss/focus");
}

int help(object me)
{
	write(HIW"\n��������֮���ۺ�������"NOR"\n\n");
        write(@HELP
	ս����ʹ�ã�������������
	Ҫ��  ��������  60  �����ϣ�
                ��ǰ������������� 1/3 ���ϡ�

HELP
        );
        return 1;
}
