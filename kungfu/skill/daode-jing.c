// daode-jing.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        int lvl;
        
        lvl = (int)me->query_skill("daode-jing", 1);
               
        if(!me->query("jiuyin/passed"))
                return notify_fail("���޷������¾��ĸ�����ѧ��Ҳ���á�\n");

        if(me->query("gender") == "����" && lvl > 39)
                return notify_fail("�����һ�������������Ժ���ԭ����û������֮�����޷��������������仯֮����\n");

        return 1;
}

int practice_skill(object me)
{       
        return notify_fail("���¾�ֻ�ܿ�ѧϰ����ߡ�\n");
}

