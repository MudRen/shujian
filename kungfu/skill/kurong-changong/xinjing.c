// jingxin.c ��

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = me->query_skill("literate", 1)/2;

	if(me->is_fighting())
	      return notify_fail("������ս���У���ο��Ծ���������\n");

    if((int)me->query_skill("kurong-changong",1) < 100 )
	      return notify_fail("���Ǭ��һ����������죬�����ĳ�ײʹ�㾲����������\n");

	if(me->query("class") != "bonze" )
	      return notify_fail("��û�г��ң������ĳ�ײʹ�㾲����������\n");

	if((int)me->query_skill("buddhism",1) < 50 )
	      return notify_fail("��ķ�ѧ��Ϊ�������޷���������Ǳ�ޣ�\n");

	if (me->query("neili") < 300  ) 
		return notify_fail("�������������\n");

	if (me->query_temp("dali_jing"))
		return notify_fail("�����ھ���Ǳ�ޡ�\n");
       
	me->add("neili", -250);

	message_vision(GRN "\n$N��Ŀ��ϥ���£�ֻ�������徲ƽ�ͣ�������������֮����\n" NOR, me);

	me->set_temp("dali_jing", me->query("int"));  
	me->add_temp("apply/intelligence", me->query("int"));

	call_out("remove_effect", 1, me, skill);
	return 1;
}

void remove_effect(object me, int d)
{
	int i;

	if (!me) return;
    if (me->query_skill_mapped("force") == "kurong-changong"
	 && --d > 0) {
		call_out("remove_effect", 1, me, d);
		return;
	}
	i = me->query_temp("dali_jing");
	me->add_temp("apply/intelligence", -i);
	me->delete_temp("dali_jing");
	tell_object(me, HIY "�����������������޷�����Ǳ���ˡ�\n" NOR);
}

string exert_name(){ return GRN"�ľ�"NOR; }

int help(object me)
{
        write(YEL"\n��������֮��"GRN"�ľ�"YEL"����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 550 ���ϣ�
                ���������ȼ� 100 ���ϣ�
                �����ķ��ȼ� 50 ���ϣ�
                ������ҡ�

HELP
        );
        return 1;
}
