#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { 
	  if (this_player()->query("family/family_name")=="ؤ��"|| this_player()->query("cw_mp/ؤ��") )
return usage == "force"; }

#include "/kungfu/skill/force.h"

int valid_learn(object me)
{
		mapping fam  = me->query("family");
	if((!fam || fam["family_name"] != "ؤ��" )&& !me->query("cw_mp/ؤ��") )
			 	return notify_fail("�㲢��ؤ����ӣ����ϰ���˻���������\n");

	if ( me->query("gender") == "����")
		return notify_fail("���޸����ԣ���������������������Ļ���������\n");

        if ((int)me->query_skill("huntian-qigong", 1) > me->query_skill("force", 1) + 10
          && me->query_skill("huntian-qigong", 1) >= 200 )
               return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

        return valid_public(me);
}

int practice_skill(object me)
{
       if((int)me->query_skill("huntian-qigong", 1) >= 200 )
       {
           if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200)
           {
                   me->improve_skill("huntian-qigong", (int)me->query_int());
                   me->add("neili", -100); 
                   me->add("potential", -1*(1+random(3)));
                   return 1;
           }
           else return notify_fail("�����ڵ���Ϊ��������߻��������ˡ�\n");       }
        else return notify_fail("�����ڵĻ���������Ϊֻ����ѧ(learn)�������������ȡ�\n");

}
void skill_improved(object me)
{
        int skill, lit;
        skill = me->query_skill("huntian-qigong", 1);
        lit = me->query_skill("literate", 1);
        if(skill >= 300 && !me->query("htqg/300") && me->query("age")>55){
                tell_object(me, HIR"\n��������о�һ�����ˣ��ӵ���ӿ�������������������������ߣ�\n"NOR);
                me->add("max_neili", random(lit + skill));
                me->set("htqg/300", 1);
        }
}


string exert_function_file(string func)
{
        return SKILL_D("huntian-qigong/") + func;
}
mapping exercise_msg(object me)
{
	return ([
		"status_msg" : HIW + me->name()+"�����⣬���۷���" NOR,
                "start_my_msg" : "���������£�˫��ƽ����˫ϥ��Ĭ��ھ�����ʼ��������ķ���\n",
		"start_other_msg" : me->name()+"�������������£�˫��ƽ����˫ϥ���촽΢΢���������ϵ����ۿ�ʼ�Ķ�������\n",
		"halt_msg" : "$N��ɫһ����Ѹ��������վ��������\n",
		"end_my_msg" : "�������뵤�������ת�����������չ���˫��̧��վ��������\n",
		"end_other_msg" : "ֻ��"+me->name()+"˫��̧��վ��������������������������\n"
	]);
}
