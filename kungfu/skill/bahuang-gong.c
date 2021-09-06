// bahuang-gong.c �˻�����Ψ�Ҷ���
// bahuang-gong.c
#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { 
	  if (this_player()->query("family/family_name")=="���չ�" || this_player()->query("cw_mp/���չ�") )
return usage == "force"; }

#include "force.h"

int valid_learn(object me)
{
		mapping fam  = me->query("family");
	if ((!fam || fam["family_name"] != "���չ�" )&& !me->query("cw_mp/���չ�") )
			 	return notify_fail("�㲢����ɽ���չ����ӣ����ϰ���˰˻�����Ψ�Ҷ��𹦡�\n");
		
	if ( me->query("gender") == "����")
		return notify_fail("���޸����ԣ���������������������İ˻�����Ψ�Ҷ��𹦡�\n");

	if ((int)me->query_skill("bahuang-gong", 1) > me->query_skill("force", 1) + 10
	 && me->query_skill("bahuang-gong", 1) >= 200 )
		return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	if((int)me->query_skill("bahuang-gong", 1) >= 200 ){
		if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200){
			me->improve_skill("bahuang-gong", (int)me->query_int());
			me->add("neili", -100); 
			me->add("potential", -1*(1+random(3)));
			return 1;
		}
		else return notify_fail("�����ڵ���Ϊ��������߰˻�����Ψ�Ҷ����ˡ�\n");
	}
	else return notify_fail("�����ڵİ˻�����Ψ�Ҷ�����Ϊֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return SKILL_D("bahuang-gong/") + func;
}

mapping exercise_msg(object me)
{
	return ([
		"status_msg" : me->name() +"��ϥ�������ǿ���������ɫ�������ƣ���ɫ��ױ�á�" ,
                "start_my_msg" : "����ϥ����������˻�����Ψ�Ҷ��𹦣������������ڶ��𣬿�ʼ������\n",
		"start_other_msg" : "ֻ��"+ me->name() +"�ǿ�����������ѭ�����ƣ�ͷ���������ڡ�\n",
		"end_my_msg" : "��ֻ��������ת˳���������������棬�������վ��������\n",
		"end_other_msg" : me->name() +"����ǿ׼�İ����������ӣ�վ��������\n",
	]);
}
