// xixing-dafa.c ���Ǵ�
// modified by action@SJ
//updated by Zmud@Sjmud 10/3/2009
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { if (this_player()->query("quest/xxdf/pass")) return usage == "force"; }

#include "/kungfu/skill/force.h"

int valid_learn(object me)
{
	if ( me->query("gender") == "����")
		return notify_fail("���޸����ԣ�������������������������Ǵ󷨡�\n");

        if ((int)me->query_skill("xixing-dafa", 1) > me->query_skill("force", 1) + 10
          && me->query_skill("xixing-dafa", 1) >= 200 )
               return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

        return valid_public(me);
}

int practice_skill(object me)
{
       if((int)me->query_skill("xixing-dafa", 1) >= 200 )
       {
           if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200)
           {
                   me->improve_skill("xixing-dafa", (int)me->query_int());
                   me->add("neili", -100); 
                   me->add("potential", -1*(1+random(3)));
                   return 1;
           }
           else return notify_fail("�����ڵ���Ϊ������������Ǵ��ˡ�\n");       }
        else return notify_fail("�����ڵ����Ǵ���Ϊֻ����ѧ(learn)�������������ȡ�\n");

}
void skill_improved(object me)
{
        int skill, lit;
        skill = me->query_skill("xixing-dafa", 1);
        lit = me->query_skill("literate", 1);
        if(skill >= 300 && !me->query("xxdf/300") && me->query("age")>55){
                tell_object(me, HIR"\n��������о�һ�����ˣ��ӵ���ӿ�������������������������ߣ�\n"NOR);
                me->add("max_neili", random(lit + skill));
                me->set("xxdf/300", 1);
        }
}

string exert_function_file(string func)
{
        return SKILL_D("xixing-dafa/") + func;
}
mapping exercise_msg(object me)
{
	return ([
		"status_msg" : HIB + me->name()+"����̫�飬��������" NOR,
		"start_my_msg" : "���������£�˫��ƽ����˫ϥ��Ĭ��ھ�����ʼ�������Ǵ󷨡�\n",
		"start_other_msg" : me->name()+"�������������£�˫��ƽ����˫ϥ��ȫ����ɫ��Ϣ���֡�\n",
		"halt_msg" : "$N��ɫһ����Ѹ��������վ��������\n",
		"end_my_msg" : "�㽫�����������ڣ���ȫ��ۼ�����ɫ��Ϣɢȥ��վ��������\n",
		"end_other_msg" : "ֻ��"+me->name()+"˫��̧��վ����������ɫ��Ϣ����ɢȥ��\n"
	]);
}

int ob_hit(object ob, object me, int damage)
{
mapping myfam;
    int m_xxdf,t_force,i,j;
myfam= me->query("family");
    t_force = (int)ob->query_skill("force",1);
if(!myfam || myfam["family_name"] != "�������")
j=0;
else j = 1;
    if((int)me->query_skill("xixing-dafa",1)>=300)
    if(me->query_temp("xxdf/xixing")){
        if(m_xxdf > t_force ){
            i = - damage;
            message_vision(WHT"$n����ʽ����̫������С�������Ǵ�˲�仯�⣬���û�ж�$N����κ��˺���\n"NOR,me,ob);
            me->add("neili",300);
            ob->add("neili",-300);           
            return i;
        }
        else if(m_xxdf > t_force*2/5){
            i = - damage/2 - random(damage/2);
            message_vision(HIB"$NͻȻ�������Ǵ󷨣�$nͻȻ���þ���ԴԴ����������ʧ���о���ƣ����,ֻ�ó��У�\n"NOR, me,ob);
            me->add("jingli",50);
            ob->add("jingli",-300);   
if(j>0)  {ob->start_busy(1);
ob->apply_condition("no_exert",1);
}
            return i;
        }
        else if(m_xxdf > t_force/2){
            i = - damage/2;
            message_vision(HIC"$NͻȻ�������Ǵ󷨣�$nͻȻ��������ԴԴ���������˳�ȥ,$n���һ��,�������У�\n"NOR, me,ob);
            me->add("neili",-200);
            ob->add("neili",-300);   
if(j>0) {ob->start_busy(1);
 ob->apply_condition("no_fight",1);
}
            return i;
        }
        else if(m_xxdf > t_force/3){
            i = - damage/3;
            message_vision(HIR"$NͻȻ�������Ǵ󷨣�$nͻȻ������ѪԴԴ����������ʧ������������$N�Ŀ��ƣ�\n"NOR, me,ob);
            me->add("neili",-100);
            ob->add("qi",-500);               
if(j>0) ob->start_busy(1);
            return i;
        }
        else{
            i = - damage/4 - random(damage/5);
            message_vision(HIM"$NͻȻ�������Ǵ󷨣�$nͻȻ���þ�ѪԴԴ����������ʧ������������$N�Ŀ��ƣ�\n"NOR, me,ob);
            me->add("neili",-50);
            ob->add("jing",-300);   
if(j>0) ob->start_busy(1);
            return i;
        }
    }
    return 0;
}
