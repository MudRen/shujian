// sanhuan.c for tjj
// Created and Modified by snowman@SJ 23/02/2001

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int i, j, lvl = me->query_skill("taiji-jian", 1);

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target)
	 || !living(target) )
		return notify_fail("���������¡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_temp("tjj/lian") )
		return notify_fail("������ʹ������\n");
 
        if( (int)me->query_skill("taiji-jian", 1) < 150 )
		return notify_fail("���̫����������̫ǳ���������ˡ�\n");
 
        if( (int)me->query_skill("sword", 1) < 150 )
		return notify_fail("��Ļ�����������̫ǳ���������ˡ�\n");

	if( (int)me->query_temp("tjj/chan") )
		return notify_fail("����������ʹ�á������־���\n");

        if( (int)me->query_skill("yinyun-ziqi", 1) < 150 )
		return notify_fail("����ڹ�����̫ǳ���������ˡ�\n");

        if( (int)me->query("max_neili") < 2500 )
		return notify_fail("�������̫ǳ���������ˡ�\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("��������������������ˡ�\n");
/*
	if( me->query_skill_mapped("force") != "yinyun-ziqi" )
		return notify_fail("����ʲôΪ�ڹ�������ʹ���������¡�?\n");
*/
	if( !objectp(weapon = me->query_temp("weapon"))
	 || weapon->query("skill_type") != "sword"
	 || me->query_skill_mapped("sword") != "taiji-jian" )
		return notify_fail("��ʹ���ˡ��������¡�ô?\n");

  	j = lvl /2; //ԭ1/3
	if ( lvl > 449 )
		j = to_int(lvl * lvl/825);

if(!userp(me)) j = j/3;
	me->set_temp("tjj/sanhuan", 3);
	me->add_temp("apply/sword", j/3);
        me->add_temp("apply/attack", j*2/3);
        me->add_temp("apply/damage", j*2/3);
	if( wizardp(me) )
           tell_object(me, "��ġ�"HIW"��������"NOR"�����ӣ���Ч���� "+j+"�������� "+j+"���˺� "+j/4+"��\n"NOR);

	if( ( weapon->query("material") == "wood"
	   || weapon->query("material") == "bamboo"
          ||weapon->query("id") == "songwen jian"
           || weapon->query("material") == "paper" )
           || weapon->query("weapon_prop/damage") < 20 
           || weapon->query("weapon_prop/damage") > 220 ) {
                   i =  me->query_skill("taiji-jian", 1)/3;
			me->add_temp("apply/damage", i);
                        me->add_temp("apply/attack", i);
			me->set_temp("tjj/sanhuan_damage", i);
	if( wizardp(me) ) 
                tell_object(me, "�㡸"HIW"��������"NOR"�������ӳɣ� "+i+"��\n"NOR);
if(!userp(target)) target->add_busy(2);
            }

   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	if( me->is_fighting(target) )
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	if( me->is_fighting(target) )
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	me->add_temp("apply/sword", -j/3);
        me->add_temp("apply/attack", -j*2/3);
	me->add_temp("apply/damage", -j*2/3);

	if( me->query_temp("tjj/sanhuan_damage") )
		me->add_temp("apply/damage", -me->query_temp("tjj/sanhuan_damage") );
		me->add_temp("apply/attack", -me->query_temp("tjj/sanhuan_damage") );

	me->delete_temp("tjj/sanhuan");
	me->delete_temp("tjj/sanhuan_damage");

	me->start_busy(random(2));
	me->add("neili", -300);
	me->add("jingli", -150);
	me->start_perform(3, "���������¡�");
	return 1;
}

string perform_name(){ return HIG"��������"NOR; }

int help(object me)
{
        write(HIG"\n̫������֮���������¡���"NOR"\n\n");
        write(@HELP
        �䵱�����������������У����䵱��������߹����Եģ����ʹ��
        �����÷�������������

        Ҫ��  ��ǰ���� 1000 ����;
                ������� 2500 ���ϣ�
                ̫�������ȼ� 150 ���ϣ�
                �������ȼ� 150 ���ϣ�
                ���������ȼ� 150 ���ϣ�
                ��������Ϊ̫��������
                �����м�Ϊ̫��������
                �����ڹ�Ϊ��������

HELP
        );
        return 1;
}
