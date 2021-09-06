// wujian.c
// tiantian@sj
// modified by olives@SJ 4/31/2001
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name() {return HIB"�޽�ʤ�н�"NOR;}

void remove_effect(object me, object weapon);
int perform(object me, object target)
{
	int skill;
	int i;
	object weapon;

	skill = (int)me->query_skill("xuantie-jianfa", 1);                

	if( !target ) target = offensive_target(me);

	if( !target || !me->is_fighting(target) )
		return notify_fail("���޽�ʤ�н���ֻ����ս����ʹ�á�\n");

	if(me->query_temp("wujian"))
		return notify_fail("������ʹ�á��޽�ʤ�н�����\n");

	if(!objectp(weapon = me->query_temp("weapon")) 
	|| weapon->query("skill_type")!="sword")
		return notify_fail("�������޽������ʹ�ĳ����������ľ�����\n");

 if(me->query_skill("sword",1) <=550) 
	if(weapon->query("unique")|| !userp(me) )
		return notify_fail("����������������������ᡸ�޽�ʤ�н������⾳?\n");

	if( (int)me->query_skill("xuantie-jianfa", 1) < 200 ) 
		return notify_fail("�����������������죬����ʹ�á��޽�ʤ�н�����\n");
		
	if( (int)me->query_skill("force", 1) < 200 )
		return notify_fail("��Ļ����ڹ��ȼ�����������ʹ�á��޽�ʤ�н�����\n");

if( me->query_skill("sword",1) <=550 )
    	if (me->query_skill_mapped("sword") != "xuantie-jianfa" )
		return notify_fail("�������޷�ʹ�á��޽�ʤ�н�����\n");

        if( me->query_skill_mapped("force") != "yunu-xinjing" && userp(me))
                return notify_fail("�������޷�ʹ�á��޽�ʤ�н�����\n");
	if( me->query("max_neili")<3000)
		return notify_fail("���������Ϊ̫�����ʹ�á��޽�ʤ�н�����\n");
	if( (int)me->query("neili") < 3000 )
		return notify_fail("����������̫��������ʹ�á��޽�ʤ�н�����\n");

 if(me->query_skill("sword",1) <=550) 	me->start_perform(1,"���޽�ʤ�н���");

	message_vision(HIB "\n$N��������ע���ϣ����������˽���������ؼ���һ����Ϊ�������롸�޽�ʤ�н����ľ��硣\n" NOR, me, target);
        i=(me->query_skill("xuantie-jianfa",1)+me->query_skill("force",1))/6;
	i=i+random(i);
	if(i>160) i=160+(i-160)/10;
	me->add("neili",-i*2);
	me->add_temp("apply/damage",i);
	me->set_temp("wujian",i);
	call_out("check_fight",1,me,weapon);
	return 1;
}

void check_fight(object me, object weapon) 
{ 
	if(!me
	|| !living(me)
	||  me->is_ghost()
	|| !me->is_fighting()
	|| !me->query_temp("weapon")
	||  me->query_temp("weapon") != weapon) 
	{
		remove_effect(me,weapon);
		return;
	}
            call_out("check_fight", 1, me, weapon); 
} 

void remove_effect(object me, object weapon)
{
	int lvl;

	if (!me)
		return;
	lvl = me->query_temp("wujian");
	me->add_temp("apply/damage",-lvl);
	me->delete_temp("wujian");
	if (!weapon) {
		me->set_temp("last_damage_from", "����ʧ�ܱ��ͷ�");
    	me->unconcious();
		return;
	}

}

int help(object me)
{
        write(HIB"\n�����������޽�ʤ�н�����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 3000 ���ϣ�
                ������� 3000 ���ϣ�
                ���������ȼ� 200 ���ϣ�
                ��Ů�ľ��ȼ� 200 ���ϣ�
                ��Ч�ڹ��ȼ� 200 ���ϣ�
                ��������Ϊ����������
                �����м�Ϊ����������

                ���ȼ�����550��ʱװ����������޷�ʹ�á�

HELP
        );
        return 1;
}
