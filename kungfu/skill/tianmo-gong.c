#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

#include "/kungfu/skill/force.h"

int valid_learn(object me)
{
	if ( me->query("gender") == "����")
		return notify_fail("���޸����ԣ������������������������ħ����\n");

        if ((int)me->query_skill("tianmo-gong", 1) > me->query_skill("force", 1) + 10
          && me->query_skill("tianmo-gong", 1) >= 200 )
               return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

        return valid_public(me);
}

int practice_skill(object me)
{
       if((int)me->query_skill("tianmo-gong", 1) >= 200 )
       {
           if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200)
           {
                   me->improve_skill("tianmo-gong", (int)me->query_int());
                   me->add("neili", -100); 
                   me->add("potential", -1*(1+random(3)));
                   return 1;
           }
           else return notify_fail("�����ڵ���Ϊ�����������ħ���ˡ�\n");       }
        else return notify_fail("�����ڵ���ħ����Ϊֻ����ѧ(learn)�������������ȡ�\n");

}
void skill_improved(object me)
{
        int skill, lit;
        skill = me->query_skill("tianmo-gong", 1);
        lit = me->query_skill("literate", 1);
        if(skill >= 300 && !me->query("tmg/300") && me->query("age")>55){
                tell_object(me, HIR"\n��������о�һ�����ˣ��ӵ���ӿ�������������������������ߣ�\n"NOR);
                me->add("max_neili", random(lit + skill));
                me->set("tmg/300", 1);
        }
}


string exert_function_file(string func)
{
        return SKILL_D("tianmo-gong/") + func;
}
mapping exercise_msg(object me)
{
	return ([
                "status_msg" : HIR + me->name()+"���ϳ����˺�ɫ��â����������" NOR,
                "start_my_msg" : HIR"����ϥ���£�Ĭ����ħ�󷨣���ʱ���Ϻ��ʱ��ʱ�֣���Ϣ˳��������������\n"NOR,
                "start_other_msg" : HIM + me->name() +"��ϥ������Ĭ����ħ�󷨣���ʱ���Ϻ��ʱ��ʱ�֡�\n"NOR,
                "halt_msg" : "$N����һ����������Ϣ�������˻�ȥ��վ��������\n",
                "end_my_msg" : HIR"�㽫��Ϣ���˸�һ�����죬�����������ȥ���չ�վ��������\n"NOR,
                "end_other_msg" : HIR"��һ���"+me->name()+"��������ĵ�վ��������\n"NOR
	]);
}
