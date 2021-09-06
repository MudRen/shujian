// shenhuo-shengong.c
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { 

if (this_player()->query("family/family_name")=="����" || this_player()->query("cw_mp/����")  )
return usage == "force"; }

#include "/kungfu/skill/force.h"

int valid_learn(object me)
{
mapping fam;

if(!fam || fam["family_name"]!="����")
      return notify_fail("�㲻�����̵��ӣ�����ѧϰʥ���񹦡�\n");
        if (me->query_skill("force", 1) < 10)
      	    return notify_fail("��Ļ����ڹ�����Ҫ��һ����ߡ�\n");

	if ( me->query("gender") == "����")
		return notify_fail("���޸����ԣ����������������������ʥ���񹦡�\n");

        if ((int)me->query_skill("shenghuo-shengong", 1) > me->query_skill("force", 1) + 10
          && me->query_skill("shenghuo-shengong", 1) >= 200 )
               return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

	return valid_public(me);
}

int practice_skill(object me)
{
       if((int)me->query_skill("shenghuo-shengong", 1) >= 200 )
       {
           if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200)
           {
                   me->improve_skill("shenghuo-shengong", (int)me->query_int());
                   me->add("neili", -100); 
                   me->add("potential", -1*(1+random(3)));
                   return 1;
           }
           else return notify_fail("�����ڵ���Ϊ���������ʥ�����ˡ�\n");       }
        else return notify_fail("�����ڵ�ʥ������Ϊֻ����ѧ(learn)�������������ȡ�\n");

}

string exert_function_file(string func)
{
	return SKILL_D("shenghuo-shengong/") + func;
}
mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIR + me->name()+"�������࣬��������һ�Ż���" NOR,
    "start_my_msg" : "����ϥ������˫�ִ�����ǰ�ɻ���״�������������þ����е���������һ����������ӿ�뵤�\n",
    "start_other_msg" : me->name()+"��ϥ������˫����ǰ�ش�ס���������࣬�������һ�Ż������¡�\n",
    "halt_msg" : "$N����΢΢����������������վ��������\n",
    "end_my_msg" : "�㽫������Ϣ��ͨ���������������۾���վ��������\n",
    "end_other_msg" : "ֻ��"+me->name()+"�����۾���վ��������ͷ�����۵İ�������Ʈɢ����\n",
    "heal_msg" : HIW"$N��ϥ������˫��ʮָ�ſ���������ǰ�����������֮״������"RED"ʥ����"HIW"��ʼ���ˡ�\n"NOR,
    "heal_finish_msg" : HIW"$N�������⸡�֣�һ���������Ҳ���������ʥ������λ�������οࣿ��������վ��\n"NOR,
    "heal_unfinish_msg" : "$N��̬ׯ�ϣ�����վ��������������Ѫ�죬�������ƻ�û����ȫ�ָ���\n",
    "heal_halt_msg" : "$N�����ͺ죬ͷ�����������������͵���һ����������������������\n",
    ]);
}
