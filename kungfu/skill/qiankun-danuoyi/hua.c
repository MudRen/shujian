//Update By lsxk@hsbbs 2007/6/11

#include <ansi.h>
inherit F_SSERVER;
int check_fight(object me, object target);
string perform_name(){ return HIW"���־�"NOR; }

int perform(object me, object target)
{
	int ap , dp;

	if( !target) target = offensive_target(me);

	if(!objectp(target) || !me->is_fighting(target))
		return notify_fail("��û�ںͶԷ�ս���أ�\n");

	if( me->query_skill("qiankun-danuoyi", 1) < 210 )
		return notify_fail("���Ǭ����Ų�ƻ�δ�������߲㡣\n");

	if (!me->query_skill("jiuyang-shengong", 1))
	if( me->query_skill("shenghuo-shengong", 1) < 210 )
		return notify_fail("���ʥ���񹦵ȼ�������\n");

	if( me->query_skill_mapped("parry") != "qiankun-danuoyi")
		return notify_fail("��û��ʹ��Ǭ����Ų����Ϊ�мܣ�\n");

	//if( me->query("neili") > me->query("max_neili"))
	//	return notify_fail("��Ŀǰ������̫ǿ���޷�ʹ�û��־���\n");

	if( me->query("neili") < 200 )
		return notify_fail("��������������޷�ʹ�û��־���\n");

	if( me->query("jiali") >= 10)
		return notify_fail("��Ŀǰ�ļ���̫���޷�ʹ�û��־���\n");

	if( me->query_temp("qkdny/hua") )
		return notify_fail("������ʩչ�������־��أ�\n");

	if( me->query_temp("qkdny/yi") )
		return notify_fail("������ʩչ���ơ��־��أ�\n");

	if( me->query_temp("qkdny/xu") )
		return notify_fail("������ʩչ����־��أ�\n");

	if( me->query_temp("qkdny/yin") )
		return notify_fail("������ʩչ�������־��أ�\n");

	me->add("neili", -100-random(100));
	me->start_perform(2, "�������־�");
        ap = me->query("combat_exp", 1) * me->query_int(1)/200;//��ֹ�������
        dp = target->query("combat_exp", 1) * target->query_int(1)/200;//��ֹ�������

	tell_object(me,HIW"\n����������˿���������Ĭ������־�������������Ỻ����\n"NOR);

	me->set_temp("qkdny/hua", 1);

	if ( random(ap + dp) > dp ) {
		tell_object(me, "��ͻȻ���Ỻ���ĳ��У���"+target->name(1)+"һ���Ӿ��ú�����Ӧ��\n"NOR);
		tell_object(target, me->name(1)+"ͻȻ���Ỻ���ĳ��У�����һ���Ӿ��ú�����Ӧ��\n"NOR);
		target->add_condition("no_perform",random(3)+1);
	}
	check_fight(me, target); 
        return 1;
}

int check_fight(object me, object target)
{
	if (!me || !me->query_temp("qkdny/hua")) return 0;

	if(me->is_ghost() || !living(me))
		me->delete_temp("qkdny/hua");

	if(!me->is_fighting()
	 || me->query("jiali") > 9
	 || me->query("jingli") < 500
	 || me->query("jing") < 500 
	 || !target ){
		tell_object(me, HIW"\n������������ָֻ���ƽ����\n"NOR);
		me->delete_temp("qkdny/hua");
	}
	else call_out("check_fight", 1, me, target);
	return 1;
}

int help(object me)
{
        write(HIW"\nǬ����Ų�ơ����־�����"NOR"\n");
        write(@HELP
        Ҫ��  ��ǰ���� 200 ���ϣ�
                ���� 10 ���£�
                Ǭ����Ų�Ƶȼ� 210 ���ϣ�
                �����м�ΪǬ����Ų�ơ�
HELP
        );
        return 1;
}
