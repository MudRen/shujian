// dragonmedicine ����ҩ��ѧ

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }
int valid_learn(object me)
{
    if ((int)me->query_skill("literate", 1) < 50)
               return notify_fail("��Ķ���ʶ��������������\n");   
        if( me->query_skill("shenlong-yaoli", 1 ) >= 200 ) 
              return notify_fail("�㲻�����������ҩ��ĵȼ��ˡ�\n");
    return 1;
}

int practice_skill(object me)
{
	return notify_fail("����ҩ��ѧֻ����ѧ(learn)�����������������ȡ�\n");
}

/*string perform_action_file(string action)
{
       return __DIR__"lingshe-bianfa/" + action;
}*/
