// wuwo.c
// Modified by Lane@SJ 2005/4/14

#include <ansi.h>
int check(object me);
int exert(object me)
{

	int nh = me->query_skill("linji-zhuang", 1);

	if( !me->is_fighting() )
		return notify_fail("��ֻ����ս���У����á����ҡ��־���\n");

	if( me->query_skill("linji-zhuang", 1) < 160 )
		return notify_fail("����ټ�ʮ��ׯ��Ϊ��������\n");

	if( me->query("class") != "bonze" && me->query("family/generation") > 3 )
		return notify_fail("�㲻�ǳ����ˣ��޷�����ټ�ʮ��ׯ�ġ����ҡ��־���\n");

	if( me->query_skill("medicine", 1) < 80 )
		return notify_fail("��ı�������ȼ�������\n");

	if( me->query("neili") < 500 )
		return notify_fail("�������������\n");

	if( me->query("jingli") < 300 )	// ���Ӿ���Ҫ��
		return notify_fail("��ľ���������\n");

	if( me->query_temp("ljz/wuwo") )
		return notify_fail("�����������ټ�ʮ��ׯ�ġ����ҡ��־���\n");

	if( me->query_temp("ljz/riyue") )
		return notify_fail("�����������ټ�ʮ��ׯ�ġ����¡��־���\n");

	if( me->query_temp("ljz/youming") )
		return notify_fail("�����������ټ�ʮ��ׯ�ġ���ڤ���־���\n");

	message_vision(HIW"ֻ��$N��������һ����������¶�������Ц�ݡ�\n"NOR, me);
	me->set_temp("ljz/wuwo", nh);  
	me->add("neili", - 200);
	check(me);
	me->start_exert(1,"�����ҡ��־�");
	me->start_busy(random(2));
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), nh/3);
	return 1;
}

int check(object me)
{
	if( !me || !(int)me->query_temp("ljz/wuwo") ) return 0;

	if( me->is_ghost() || !living(me) )
		me->delete_temp("ljz/wuwo");

	if( me->query("jingli") < 100 
	|| me->query("neili") < 120
	|| me->query("qi") < 1		// ���� BUG������-1�����ָ�
	|| !me->is_fighting()
	|| (userp(me) && me->query_skill_mapped("force") != "linji-zhuang") ) {
		message_vision(HIC"$N�ݻ�������ֹͣ����Ϣ��������\n"NOR, me);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), 1);
	}
	else {
		if( me->query("qi") < (int)me->query("max_qi") && ( !me->is_busy() || random(2) ) ) {
			message_vision(HIY"$N��ɫһ���ֻظ��������������ڵ�����Ϣ��\n"NOR,me);
			me->add("neili", -50 );
			me->add("eff_qi", me->query_skill("medicine", 1));
			me->add("eff_qi", me->query_skill("linji-zhuang", 1)/10); // �������޻ָ�
			if( me->query("eff_qi") > me->query("max_qi") )
				me->set("eff_qi", me->query("max_qi"));
                        me->add("qi", me->query_skill("force")*3/2);
                        if( me->query("qi") > me->query("eff_qi") )
				me->set("qi", me->query("eff_qi") );
		}
		call_out("check", 2+random(2), me);	// ��������ʱ�䣬����Ч��
	}
	return 1;
}       

void remove_effect(object me)
{
        int nh;
        if( !me || !me->query_temp("ljz/wuwo") ) return;
        nh = me->query_temp("ljz/wuwo");
        me->start_exert(0);
        me->delete_temp("ljz/wuwo");
        message_vision(HIR"$Nɢȥ�ˡ����ҡ��ķ����ָֻ���ԭ����$N��\n\n"NOR,me);
}

string exert_name(){ return HIW"�����־�"NOR; }

int help(object me)
{
        write(HIW"\n�ټ�ʮ��ׯ�������־�����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 500 ���ϣ�
                ��ǰ���� 300 ���ϣ�
                �ټ�ʮ��ׯ�ȼ� 160 ���ϣ�
                �������� 80 ���ϣ�
                ���һ��׼��������ӣ�
                ���ܺ͡����¡��־�ͬʱʹ�á�
HELP
        );
        return 1;
}
