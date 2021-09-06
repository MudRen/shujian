// sancheng-gong �������˹���
// Created by snowman@SJ 02/03/2001
// By Spiderii����
#include <ansi.h>
inherit FORCE;
#include "force.h"

string force_name(){ return "���˹���"; }

int valid_enable(string usage)
{ 
 	return usage == "force"; 
}

int valid_learn(object me)
{
        int nb, lvl = (int)me->query_skill("sancheng-gong", 1);

        if ( me->query("gender") == "����" && lvl > 49 )
                return notify_fail("���޸����ԣ��޷�������˹����İ��\n");

        if ( (int)me->query_skill("force", 1) < 15 )
                return notify_fail("��Ļ����ڹ���򻹲�����\n");

	nb = (int)me->query_skill("buddhism", 1);
	if ( nb < 200 && nb <= lvl )
                return notify_fail("��������ķ���Ϊ�������޷�����������������\n");

        if ((int)me->query_skill("sancheng-gong", 1) > me->query_skill("force", 1) + 10
        && me->query_skill("sancheng-gong", 1) >= 200 )
               	return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

        return valid_public(me);
}

int practice_skill(object me)
{
       	if((int)me->query_skill("sancheng-gong", 1) >= 200 ){
           	if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200){
                   	me->improve_skill("sancheng-gong", (int)me->query_int());
                   	me->add("neili", -100); 
                   	me->add("potential", -1*(1+random(3)));
                   	return 1;
           	}
           	else return notify_fail("�����ڵ���Ϊ������������˹����ˡ�\n");       
       	}
       	else return notify_fail("�����ڵ����˹�����Ϊֻ����ѧ(learn)�������������ȡ�\n");

}

string exert_function_file(string func)
{
        return __DIR__"sancheng-gong/" + func;
}

mapping exercise_msg(object me)
{
  	return ([
		"status_msg" : HIR + me->name()+"���Ϻ�����֣�˫�ִ�����ϥ����" NOR,
		"start_my_msg" : HIR"��ϯ�ض������������죬���Ϻ��ʱ��ʱ�֣���Ϣ˳��������������\n"NOR,
		"start_other_msg" : MAG + me->name() +"ϯ�ض������������죬���Ϻ��ʱ��ʱ�֡�\n"NOR,
		"halt_msg" : HIW"$N����һ����������Ϣ�������˻�ȥ��վ��������\n"NOR,
		"end_my_msg" : HIC"�㽫��Ϣ���˸�С���죬���ص���չ�վ��������\n"NOR,
		"end_other_msg" : HIR"��һ���"+me->name()+"��������ĵ�վ��������\n"NOR
        ]);
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int i=0, j=0, sk;
	object weapon;

	if( ( sk = me->query_skill("sancheng-gong", 1) ) < 300 ) return 1;

	// Ů�����ӽ�������
	if( me->query_skill_mapped("sword") == "qingyin-jian"
	 && me->query("jiali") > 0
	 && me->query("gender") == "Ů��" 
	 && me->query_skill("qingyin-jian", 1) >= 100
	 && objectp(weapon = me->query_temp("weapon"))
	 && weapon->query("skill_type") == "sword" ) {
		i += ( me->query_skill("qingyin-jian", 1)/100 ) * sk/10;	// 100 level Ϊһ����Ծ
		if( me->query_temp("apply/damage") < 100 ) i = i + random(i/3);
		else i += random(i/5);
		if( wizardp(me) ) tell_object(me, "��Ľ�������������"+i+"��\n"NOR);
	}

	// ����������ͬ��grin
	if( me->query_skill_mapped("sword") == "qingyin-jian"
	 && me->query("jiali") > 0
	 && me->query("gender") == "����" 
	 && me->query_skill("qingyin-jian", 1) >= 120
	 && objectp(weapon = me->query_temp("weapon"))
	 && weapon->query("skill_type") == "sword" ) {
		i += ( me->query_skill("qingyin-jian", 1)/120 ) * sk/10;	// 120 level Ϊһ����Ծ
		if( me->query_temp("apply/damage") < 100 ) i = i + random(i/3);
		else i += random(i/5);
		if( wizardp(me) ) tell_object(me, "��Ľ�������������"+i+"��\n"NOR);
	}

	// ���ӱ�������Ч��
	if( victim->is_perform() || victim->is_exert() ) {
		j = me->query_str() * me->query_con() / 20;
		j = j + random(j/4);
		if( wizardp(me) ) tell_object(me, "�����ڱ�������״̬���������� "+j+"��\n"NOR);
	}

	i = i + j;

	if( !userp(me) ) i = i/3;

	return i;
}


int help(object me)
{
	write(HIG"\n���ҡ�" + force_name() + "����"NOR"\n");
	write(@HELP
	�������˹���Դ�Է����������̫��������ˮ�������ͼϵ��������ֲ�ͬ��
	��������ɡ����ڹ�������ء����桢���顢����������Ƕ���ȡ������
	���ƶ����������������ղ��ᡣ�Ǽ�������ҹ�����䵱�ڼҹ������һ��
	����ѧ���˹��������������ķ��������ڹ���
	
	Ҫ��	�����ڹ��ȼ� 15 ���ϡ�
HELP
	);
	return 1;
}




