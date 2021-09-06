// zixia-gong.c ��ϼ��
// Update by lsxk@hsbbs �����ɻ�ɽ�� Quest �ڹ�  2007/7/26

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) {
 if (this_player()->query("quest/zixia/pass") ) return usage == "force";
}

#include "force.h"

int valid_learn(object me)
{
        
        int lvl, i;
        lvl = (int)me->query_skill("zixia-gong", 1);
        i = (int)me->query("shen", 1);

        if ( me->query("gender") == "����" && lvl > 49)
                return notify_fail("���޸����ԣ������������������������ϼ���񹦡�\n");

        if ( me->query("class") == "bonze" )
                return notify_fail("��ϼ�񹦽����������ϣ���Υ��������徻֮�⣬"
                        +RANK_D->query_respect(me)+"���޴˹������������\n");

        if ((int)me->query_skill("force", 1) < 15)
                return notify_fail("��Ļ����ڹ���򻹲�����\n");

        if ( !me->query("quest/zixia/pass") )
                return notify_fail("��ϼ���˻�ɽ��ɽ֮������������ܹ�����ѧϰ��\n");

        if ((lvl > 10 && lvl < 100 && i < lvl*lvl*lvl / 20 )
            || ( lvl >=100 && i < 10000))
                return notify_fail("�����������̫���ˣ��޷�ѧϰ�������ϼ�񹦡�\n");

        return valid_public(me);
}

int practice_skill(object me)
{
       if((int)me->query_skill("zixia-gong", 1) >= 200 )
       {
           if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200)
           {
                   me->improve_skill("zixia-gong", (int)me->query("int"));
                   me->add("potential", -1*(1+random(3)));
                   me->add("neili", -150); 
                   return 1;
           }
           else return notify_fail("�����ڵ���Ϊ�����������ϼ���ˡ�\n");
       }
        else return notify_fail("��ϼ��ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"zixia-gong/" + func;
}

mapping exercise_msg(object me)
{
	return ([
		"status_msg" : MAG + me->name()+"˫�����������������������"NOR,
		"start_my_msg" : MAG"����Ϣ�������������������ִ�������֮�ϣ�����ǰ���˸�������������Ϣ���߸���������\n"NOR,
		"start_other_msg" : MAG + me->name() +"����������������������������һ��������\n"NOR,
		"halt_msg" : MAG"$N����һ��������Ϣѹ�ص��˫��һ��վ��������\n"NOR,
		"end_my_msg" : MAG"�㽫��Ϣ����һ�����죬ֻ�е�ȫ��̩ͨ��������ů���ģ�˫��һ�֣�����վ��������\n"NOR,
		"end_other_msg" : MAG""+me->name()+"��������������ȥ��վ��������\n"NOR
	]);
}

int ob_hit(object ob, object me, int damage)
{
    int m_zxg,t_force,i;
    m_zxg = random((int)me->query_skill("zixia-gong",1));
if(me->query("quest/zixia/pass")) m_zxg *=2;

    t_force = (int)ob->query_skill("force",1);

    if((int)me->query_skill("zixia-gong",1)>=300)
    if(me->query("env/��ϼ��")=="����" && me->query_temp("zxg/zixia")){
        if(m_zxg > t_force*4/5 && !random(3)){
            i = - damage;
            message_vision(MAG"$N����ϼ����Ȼ�뻯����$n��һ����$N,$N���ϱ�������ʢ����ϼ���������������"+
                "$n���и�����û��$N����κ��˺���\n"NOR,me,ob);
            me->add("neili",-800);
            return i;
        }
        else if(m_zxg > t_force*4/5){
            i = - damage/2 - random(damage/2);
            message_vision(MAG"$N΢΢һЦ����ϼ�����Ķ�����$n������Ȼ��$N�����˾����Ĺ�����\n"NOR,me,ob);
            me->add("neili",-600);
            return i;
        }
        else if(m_zxg > t_force/2){
            i = - damage/2;
            message_vision(MAG"$N���´���������ϼ�ھ�����ʱ��$n�Ĺ��ƻ�ȥ��һ��!\n"NOR,me,ob);
            me->add("neili",-400);
            return i;
        }
        else if(m_zxg > t_force/3){
            i = - damage/3;
            message_vision(MAG"$N��$n���������쳣�����´󾪣�����������ϼ�����У�������$n�Ĳ��ֹ���!\n"NOR,me,ob);
            me->add("neili",-300);
            return i;
        }
        else{
            i = - damage/4 - random(damage/5);
            message_vision(MAG"$N�����߶���ϼ�񹦣����ڻ���$n��һ�㹥�������²�����Ȼ!\n"NOR,me,ob);
            me->add("neili",-150);
            return i;
        }
    }
    return 0;
}
