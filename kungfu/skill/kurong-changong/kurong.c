// By Spiderii �ϲ�ͬ���� kurong.c
// By Spiderii ���ڿ������ɣ���߷���

#include <ansi.h>
void remove_effect(object me,int skill);


string exert_name() {return HIG"�������"NOR;}

int exert(object me)
{      
       int skill;
       skill = me->query_skill("kurong-changong");
	if ( !me->is_fighting())
		return notify_fail("��ֻ����ս����ʹ�á����١���\n");

	if( (int)me->query_skill("kurong-changong", 1) < 150 )
		return notify_fail("��Ŀ���������Ϊ�������޷�ʹ�á����١���\n");

	if (me->query_skill_mapped("force") != "kurong-changong")
		return notify_fail("�����ڹ��С����١���\n");

	if( (int)me->query("neili") < 1500 )
		return notify_fail("��Ŀǰ������̫���ˣ��޷�ʹ�á����١���\n");

	if( (int)me->query("max_neili") < 2000 )
		return notify_fail("���������Ϊ��ô�����ʹ�á����١���\n");

	if( me->query_temp("krcg_kurong"))
		return notify_fail("���������á����١���\n");

        // �������
        if ((int)me->query_skill("kurong-changong", 1) > 450)
	        message_vision(HIG "$N" HIG "�������������ȫ��Ƥ�������һ����"
                                "��Ӥ������һ��ȴ�Ƹ������Ƥ��\n" NOR, me);
        // ȫ��
        else if ((int)me->query_skill("kurong-changong", 1) > 350)
	        message_vision(HIC "$N" HIC "���������������������ȫ��Ƥ����"
                                "�������Ӥ����⻬����\n" NOR, me);
        // ȫ��
        else if ((int)me->query_skill("kurong-changong", 1) > 250)
	       message_vision(YEL "$N" YEL "���������������������ȫ��Ƥ����"
                                "���������Ƥ�������ϡ�\n" NOR, me);
        // ��ݰ���
        else
	        message_vision(HIY "$N" HIY "���������������������������ʱ��"
                                "��ȫ��\n" NOR, me);

       me->start_busy(1);
       me->add_temp("apply/parry", me->query_skill("kurong-changong", 1)/2);
       me->add_temp("apply/armor", me->query_skill("kurong-changong", 1)/2);
	me->add("neili", -400);
	me->set_temp("krcg_kurong",skill /2);
	call_out("remove_effect", 1, me, skill);
	me->start_exert(2, "�����١�");
	return 1;
}
void remove_effect(object me, int skill)
{
	
	 if (objectp(me)) {
                if (me->is_fighting()) {
                        call_out("remove_effect", 1, me, skill);
                        return;
                }

           me->delete_temp("krcg_kurong");
	    
           me->add_temp("apply/parry", -me->query_skill("kurong-changong", 1)/2);
           me->add_temp("apply/armor", -me->query_skill("kurong-changong", 1)/2);
           message_vision(WHT"\n$N�Ŀ�������������ϣ��������ջص��\n"NOR, me);
	    return;

	}
}


int help(object me)
{
        write(WHT"\n�������������١���"NOR"\n");
        write(@HELP
        �����������Ǵ����������Ժ--���������ֿ��ٳ��ϵ��ڹ��ķ�
        �ഫ�����������ڰ˿���֮�䡣��˿����ֶ����ϱ��������÷�
        �У����Ƿֱ���һ��һ�٣������ϱ��ֱ��ǣ������޳���������
        �֣��������ң������޾��� ���������޿����ٷ��Ǵ�ɡ�����
        �������������������һ����ֻ�εð�ݰ��١�
        �˿���һ����ʹ��Ҵ�����������ķ������мܣ�������һ��
        ����ʹ�Է�������Ч��

        Ҫ��:   �������� 150 �����ϣ�
                ������� 2000 �㣻
                ��ǰ���� 1500 �㣻
                �輤���ڹ�Ϊ����������
              
HELP
        );
        return 1;
}


