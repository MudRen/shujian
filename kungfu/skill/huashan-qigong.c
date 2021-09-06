// huashan-qigong.c  ��ɽ����  By lsxk@hsbbs 2007/7/22

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { 
	  if (this_player()->query("family/family_name")=="��ɽ��"|| this_player()->query("cw_mp/��ɽ��")
 )
return usage == "force"; }

#include "force.h"

int valid_learn(object me)
{
        
        int lvl, i;
        lvl = (int)me->query_skill("huashan-qigong", 1);
        i = (int)me->query("shen", 1);

        if ( me->query("gender") == "����" && lvl > 49)
                return notify_fail("���޸����ԣ������������������ڵĻ�ɽ����?\n");

        if ( me->query("class") == "bonze" )
                return notify_fail("��ɽ���������������ϣ���Υ��������徻֮�⣬"
                        +RANK_D->query_respect(me)+"���޴˹������������\n");

        if ((int)me->query_skill("force", 1) < 15)
                return notify_fail("��Ļ����ڹ���򻹲�����\n");

        if ((lvl > 10 && lvl < 100 && i < lvl*lvl*lvl / 20 )
            || ( lvl >=100 && i < 10000))
                return notify_fail("�����������̫���ˣ�������˼ѧϰ�⻪ɽ������\n");

        return valid_public(me);
}

int practice_skill(object me)
{
       if((int)me->query_skill("huashan-qigong", 1) >= 200 )
       {
           if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200)
           {
                   me->improve_skill("huashan-qigong", (int)me->query("int"));
                   me->add("potential", -1*(1+random(3)));
                   me->add("neili", -100); 
                   return 1;
           }
           else return notify_fail("�����ڵ���Ϊ��������߻�ɽ�����ˡ�\n");
       }
        else return notify_fail("��ɽ����ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"huashan-qigong/" + func;
}

mapping exercise_msg(object me)
{
	return ([
            "status_msg" : WHT + me->name()+"��ϥ������������Ϣ��ȫ�����ߡ�"NOR,
            "start_my_msg" : WHT"����������������������һ���ڼ���������ȫ��\n"NOR,
            "start_other_msg" : WHT + me->name() +"����������˫�����˸���������ʼ����������\n"NOR,
            "halt_msg" : WHT"$N��Ȼǿ��һ��������˫��һ��������վ��������\n"NOR,
            "end_my_msg" : WHT"�㽫��Ϣ����ȫ������ȫ���泩�����������ޱȡ�\n"NOR,
            "end_other_msg" : WHT""+me->name()+"������˿�����΢΢һЦ��վ��������\n"NOR
	]);
}
