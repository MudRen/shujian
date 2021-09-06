// riyun.c
// by snowman@SJ 27/01/2000
// Modified by Lane@SJ 2005/4/14


#include <ansi.h>
int check_fight(object me);

int exert(object me)
{       
	int nh, neili;
       
	if( !me->is_fighting() )
		return notify_fail("�����¡��־�������ս����ʹ�á�\n");

	if( (int)me->query_skill("linji-zhuang", 1) < 150 )
		return notify_fail("����ټ�ʮ��ׯ��Ϊ��������\n");

	if( me->query("class") != "bonze" && me->query("family/generation") > 3)
		return notify_fail("�㲻�ǳ����ˣ��޷�����ټ�ʮ��ׯ�ġ����¡��־���\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("�������������\n");

	if( me->query_temp("ljz/riyue") )
		return notify_fail("�����������ټ�ʮ��ׯ�ġ����¡��־���\n");

	if( me->query_temp("ljz/wuwo") )	// �ĳ� ���ܺ� wuwo ͬʱʹ��
		return notify_fail("�����������ټ�ʮ��ׯ�ġ����ҡ��־���\n");


	tell_object(me,MAG"\n���������죬Ǳ�����¶�ׯ����������������Ǳ����������������ض�����̩�����پ��Լ�����ԴԴ��ֹ�ˡ�\n"NOR);
	message_vision(HIW"\nֻ��$N���Ϻ��ʱ��ʱ�֣�һ�±��������ġ�\n\n"NOR, me);

	if( me->query_temp("weapon") )
		me->set_temp("ljz/weapon", 1);
	else me->set_temp("ljz/weapon", 0);

	nh = (int)me->query_skill("linji-zhuang", 1)/10;
	neili = (int)me->query("neili");
	me->set_temp("ljz/riyue", neili);
	me->add("neili", -nh*20);
	me->start_busy(random(2));
	check_fight(me);
	me->start_exert(1, "�����¡�");	// ��Ϊ�޷��� wuwo ��ͬʹ�ã��ʼ��� yun busy
	return 1;

}

int check_fight(object me)
{
	int i;
	if( !me || !(int)me->query_temp("ljz/riyue") ) return 0;

	if( me->is_ghost() || !living(me) )
		me->delete_temp("ljz/riyue");

	if( me->query_temp("weapon") )
		i = 1;
	else
		i = 0;

	if( !me->is_fighting()
	|| me->query("neili") <= 10
	|| me->query_temp("ljz/weapon") != i
	|| (userp(me)
	&& me->query_skill_mapped("force") != "linji-zhuang") )
		call_out("remove_effect", 1, me);
	else {
		if( me->query("neili") < (int)me->query_temp("ljz/riyue") ) {
			tell_object(me, "����������֮����ת��Ϣ��ʹ��о������κ����������ģ�\n");
			me->set("neili", me->query_temp("ljz/riyue"));
		}
		call_out("check_fight", 1, me);
	}       
	return 1;
}       

void remove_effect(object me)
{
	if( !me || !me->query_temp("ljz/riyue") ) return;
	me->start_exert(1, "����");
	me->delete_temp("ljz/weapon");
	me->delete_temp("ljz/riyue");
	message_vision(HIR"$N�������֮������ɢ������֮�䣬$N�ָֻ���ԭ�е��������ġ�\n\n"NOR, me);
}

string exert_name(){ return MAG"�����־�"NOR; }

int help(object me)
{
        write(MAG"\n�ټ�ʮ��ׯ�������־�����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 1000 ���ϣ�
                �ټ�ʮ��ׯ�ȼ� 150 ���ϣ�
                ���һ��׼��������ӣ�
                ���ܺ͡����ҡ��־�ͬʱʹ�á�
HELP
        );
        return 1;
}
