#include <ansi.h>

int exert(object me)
{
	int i;

	if(me->query_temp("jiuyin/powerup"))
		return notify_fail("��������ʹ�����ܾ���\n");

	if ((int)me->query_skill("jiuyin-zhengong", 1) < 200)
		return notify_fail("��ľ����湦��Ϊ��������\n");

	if ((int)me->query_skill("daode-jing", 1) < 200)
		return notify_fail("��ĵ��¾���Ϊ��������\n");

	if( (int)me->query("neili") < 1500 )
		return notify_fail("�������������\n");

        i = me->query_skill("force")/5;
	me->add("neili", -500);
	me->start_exert(3, "�����ܾ�");
	me->add_temp("apply/dodge", i);
        me->add_temp("apply/parry", i);
	me->add_temp("apply/force", i);
	me->add_temp("apply/sword", i);
	me->add_temp("apply/whip", i);
	me->add_temp("apply/strike", i);
	me->add_temp("apply/cuff", i);
	me->add_temp("apply/claw", i);
	me->set_temp("jiuyin/powerup", 1);
	message_vision(HIY"$N��������ܾ�������������Ȼ������\n"NOR, me);

	if ( me->is_fighting())
		me->start_busy(random(2));
	call_out("remove_effect", (int)me->query_skill("force")/4, me, i);
	return 1;
}

void remove_effect(object me, int i)
{
	if (!me) return;
	me->delete_temp("jiuyin/powerup");
	me->add_temp("apply/dodge", - i);
	me->add_temp("apply/force", - i);
        me->add_temp("apply/parry", - i);
	me->add_temp("apply/sword", - i);
	me->add_temp("apply/whip", - i);
	me->add_temp("apply/strike", - i);
	me->add_temp("apply/cuff", - i);
	me->add_temp("apply/claw", - i);
	message_vision(HIY"$N�ľ����ܾ���ʹ��ϣ�����һ������\n"NOR, me);
}

string exert_name(){ return HIY"�����ܾ�"NOR; }

int help(object me)
{
        write(HIY"\n�����湦֮�������ܾ�����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1500 ���ϣ�
        	���¾��ȼ� 200 ���ϣ�
                �����湦�ȼ� 200 ���ϡ�

HELP
        );
        return 1;
}
