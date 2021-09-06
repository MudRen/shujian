#include <ansi.h>
#include <skill.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg;
	int i;

	if( me->query_skill("jiuyin-zhengong",1) < 130 )
		return notify_fail("��ľ����湦���������ʹ������������\n");  

	if( me->query_skill("jiuyin-shenfa",1) < 130 )
		return notify_fail("��ľ��������������ʹ������������\n");  

	if (me->query_skill_mapped("dodge") != "jiuyin-shenfa")
		return notify_fail("�������޷�ʹ�û�������\n");

	if( me->query("jingli", 1) < 200 )
		return notify_fail("�����ھ���������\n");

	if( me->query("neili", 1) < 200 )
		return notify_fail("����������������\n");

	if (me->query_temp("jiuyin/fast"))
		return notify_fail("������ʹ�û�������\n");

	if ( me->query_skill_mapped("dodge") != "jiuyin-shenfa")
		return notify_fail("�������޷�ʹ�û�������\n");

	msg = HIW"\n$Nʩչ���������������Ʈ���쳣��\n"NOR; 

	me->add("neili", -100);
	me->add("jingli", -100);
	message_vision(msg, me);
        i = me->query_skill("jiuyin-shenfa", 1)/8;
	me->add_temp("apply/dexerity", i);
// ���� auto perform
	me->set_temp("jiuyin/fast", i);
	me->start_perform(2, "������");
	if ( me->is_fighting())
		me->start_busy(random(2));
	call_out("remove_effect", 1, me, me->query_skill("jiuyin-zhengong", 1)/3);
	return 1;
}

void remove_effect(object me, int count)
{
	int i;
	if (!me) return;
	if ( me->query_skill_mapped("dodge") != "jiuyin-shenfa"
	|| count-- < 1 ){
		i = me->query_temp("jiuyin/fast");
		me->add_temp("apply/dexerity", - i);
		me->delete_temp("jiuyin/fast");
		message_vision(HIW"$Nֹͣ�˻����������ָ���������\n"NOR, me);
		return;
	}
	call_out("remove_effect", 1, me, count);
}

string perform_name(){ return HIW"������"NOR; }

int help(object me)
{
        write(HIW"\n������֮������������"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 200 ���ϣ�
                ��ǰ���� 200 ���ϣ�
                �����湦�ȼ� 130 ���ϣ�
                �������ȼ� 130 ���ϣ�
                ������Ϊ��������

HELP
        );
        return 1;
}
