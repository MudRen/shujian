// tiezhang-xinfa.c� �����ķ�
inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        if( (int)me->query_skill("tiezhang-xinfa", 1) >= 200 )
             return notify_fail("�㲻����ѧϰ�����ķ��ˡ�\n");
        return 1;
}
int practice_skill(object me)
{
        return notify_fail("�����ķ�ֻ�ܿ�ѧ(learn)����ߡ�\n");
}


